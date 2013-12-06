<?php

include_once "FeedsDwCAMappings.inc";


/**
 * @file
 * Class definition of DwCALocationProcessor.
 *
 * Necesary to set the Title of the Location content type one of the following 
 * formats:
 *    - Locality (Latitude, Longitude)
 *    - (Latitude, Longitude)
 */

/**
 *  Extends FeedsProcessor and reimplement the process method
 */
class DwCALocationProcessor extends FeedsProcessor {

  /**
   * Process the result of the parsing stage.
   *
   * @param FeedsSource $source
   *   Source information about this import.
   *
   * @param FeedsParserResult $parser_result
   *   The result of the parsing stage.
   */
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {

    // get the current state (this is to update the progress bar).
    $state = $source->state(FEEDS_PROCESS);


    //make the processor use transaction 
    //TODO: make sure this is working correctly
    $transaction = db_transaction();

    /* FIXME: put the method in a try catch to enable the rollbacks
    try {
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception('DwC-A', $e);
    }
     */


    // Run over all the results
    while ($item = $parser_result->shiftItem()) {

      //Process every item

      try {

        // Set the configuration to extract locations.
        $this->setConfig(FeedsDwCAMappings::get_location_config());

        // config special fields
        if( $parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLatitude']
            && $parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLongitude']
            && $parser_result->current_item['http://rs.tdwg.org/dwc/terms/locality']){

          // Create the location title
          $parser_result->current_item['location_title'] =
          $parser_result->current_item['http://rs.tdwg.org/dwc/terms/locality']." ("
              .$parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLatitude'].","
                  .$parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLongitude'].")";

        }else if( $parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLatitude']
            && $parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLongitude']){

          // Create the location title
          $parser_result->current_item['location_title'] =
          " (".$parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLatitude'].","
              .$parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLongitude'].")";

        }



        if (!($entity_id = $this->existingEntityId($source, $parser_result))){

          // Assemble node, map item to it, save.
          $entity = $this->__create_new_entity($entity_id, $source);

          // config special fields
          if( $parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLatitude']
              && $parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLongitude']){

            $parser_result->current_item['map'] =
              "(".$parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLatitude'].
              ",".
              $parser_result->current_item['http://rs.tdwg.org/dwc/terms/decimalLongitude'].")";
          }

          // complete the entity data with this.
          $this->map($source, $parser_result, $entity);

          // validate and save
          $state = $this->__validate_and_save($entity, $source, $state);

        }
        // --------------------------------------------------------------------------

      }catch (Exception $e) {
        $state->failed++;
        drupal_set_message($e->getMessage(), 'warning');
        $message = $e->getMessage();
        $message .= '<h3>Original item</h3>';
        $message .= '<pre>' . var_export($item, TRUE) . '</pre>';
        $message .= '<h3>Entity</h3>';
        $message .= '<pre>' . var_export($entity, TRUE) . '</pre>';
        $source->log('import', $message, array(), WATCHDOG_ERROR);
      }
    }

    // Set messages if we're done.
    if ($source->progressImporting() != FEEDS_BATCH_COMPLETE) {
      return;
    }

    $info = $this->entityInfo();
    $tokens = array(
        '@entity' => strtolower($info['label']),
        '@entities' => strtolower($info['label plural']),
    );
    $messages = array();

    // Message for create entities.
    if ($state->created) {
      $messages[] = array(
          'message' => format_plural(
              $state->created,
              'Created @number @entity.',
              'Created @number @entities.',
              array('@number' => $state->created) + $tokens
          ),
      );
    }

    // Message for updated entities.
    if ($state->updated) {
      $messages[] = array(
          'message' => format_plural(
              $state->updated,
              'Updated @number @entity.',
              'Updated @number @entities.',
              array('@number' => $state->updated) + $tokens
          ),
      );
    }

    // Message for failed to import entities.
    if ($state->failed) {
      $messages[] = array(
          'message' => format_plural(
              $state->failed,
              'Failed importing @number @entity.',
              'Failed importing @number @entities.',
              array('@number' => $state->failed) + $tokens
          ),
          'level' => WATCHDOG_ERROR,
      );
    }

    // If nothing happens during the importation.
    if (empty($messages)) {
      $messages[] = array(
          'message' => t('There are no new @entities.', array('@entities' => strtolower($info['label plural']))),
      );
    }

    // Log the messages
    foreach ($messages as $message) {
      drupal_set_message($message['message']);
      $source->log('import', $message['message'], array(), isset($message['level']) ? $message['level'] : WATCHDOG_INFO);
    }
  }


  private function __create_new_entity($entity_id, $source, $hash = NULL){

    if (empty($entity_id)) {

      $entity = $this->newEntity($source);
      $this->newItemInfo($entity, $source->feed_nid, $hash);

    }else {
      $entity = $this->entityLoad($source, $entity_id);
      // The feeds_item table is always updated with the info for the most recently processed entity.
      // The only carryover is the entity_id.
      $this->newItemInfo($entity, $source->feed_nid, $hash);
      $entity->feeds_item->entity_id = $entity_id;
    }

    return $entity;
  }

  private function __validate_and_save($entity, $source,  $state){

    // validate the entity.
    $this->entityValidate($entity);

    // Allow modules to alter the entity before saving.
    module_invoke_all('feeds_presave', $source, $entity);

    if (module_exists('rules')) {
      rules_invoke_event('feeds_import_'. $source->importer()->id, $entity);
    }

    // Enable modules to skip saving at all.
    if (empty($entity->feeds_item->skip)) {
      $this->entitySave($entity);
      // Track progress.
      if (empty($entity_id)) {
        $state->created++;
      }
      else {
        $state->updated++;
      }
    }

    return $state;
  }
}

