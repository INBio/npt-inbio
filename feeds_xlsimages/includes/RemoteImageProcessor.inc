<?php


/**
 * @file
 * Class definition of RemoteImageProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class RemoteImageProcessor extends FeedsFileProcessor{

  /**
   * Process the result of the parsing stage.
   *
   * @param FeedsSource $source
   *   Source information about this import.
   * @param FeedsParserResult $parser_result
   *   The result of the parsing stage.
   */
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {

    $new_items = Array();
    $items = $parser_result->items;

    foreach($items as $item){
      // download the image with the name in the file
      $filename = $item['Filename'];
      $content = file_get_contents($filename);

      if($content === FALSE){
        $new_filename = '';
      }else{
        // save the image to the public repository
        $new_filename = 'public://' . basename($filename);
        file_put_contents( drupal_realpath($new_filename), $content);
      }

      // save the new location
      $item['Filename'] = $new_filename;
      $new_items[] = $item;
    }

    $parser_result->items = $new_items;

    #parent::process($source, $parser_result);
    $this->post_process($source, $parser_result);

  }

  public function post_process(FeedsSource $source, FeedsParserResult $parser_result){
    $state = $source->state(FEEDS_PROCESS);
    while($item = $parser_result->shiftItem()){
        // Only proceed if item has actually changed.
        $hash = $this->hash($item);
        if(!empty($entity_id) && $hash == $this->getHash($entity_id)){
          continue;
        }
        try{
          // Assemble node, map item to it, save.
          if(empty($entity_id)){
            $entity = $this->newEntity($source);
            $this->newItemInfo($entity, $source->feed_nid, $hash);
          }else{
            $entity = $this->entityLoad($source, $entity_id);
            // The feeds_item table is always updated with the info for the most recently processed entity.
            // The only carryover is the entity_id.
            $this->newItemInfo($entity, $source->feed_nid, $hash);
            $entity->feeds_item->entity_id = $entity_id;
          }

          $this->map($source, $parser_result, $entity);
          $this->entityValidate($entity);

          $entity->uri      = $entity->filename;
          $entity->title    = basename($entity->filename);
          $entity->status   = 1;
          $entity->filename = basename($entity->filename);

          // Allow modules to alter the entity before saving.
          module_invoke_all('feeds_presave', $source, $entity);
          if(module_exists('rules')){
            rules_invoke_event('feeds_import_' . $source->importer()->id, $entity);
          }
          // Enable modules to skip saving at all.
          if(empty($entity->feeds_item->skip)){
            $this->entitySave($entity);
            // Track progress.
            $state->updated++;
          }
        }
        catch(Exception $e){
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
    if($source->progressImporting() != FEEDS_BATCH_COMPLETE){return;}
    $info = $this->entityInfo();
    $tokens = array(
      '@entity' => strtolower($info['label']),
      '@entities' => strtolower($info['label plural'])
    );
    $messages = array();
    if($state->created){
      $messages[] = array(
        'message' => format_plural($state->created, 'Created @number @entity.', 'Created @number @entities.', array(
          '@number' => $state->created
        ) + $tokens)
      );
    }
    if($state->updated){
      $messages[] = array(
        'message' => format_plural($state->updated, 'Updated @number @entity.', 'Updated @number @entities.', array(
          '@number' => $state->updated
        ) + $tokens)
      );
    }
    if($state->failed){
      $messages[] = array(
        'message' => format_plural($state->failed, 'Failed importing @number @entity.', 'Failed importing @number @entities.', array(
          '@number' => $state->failed
        ) + $tokens),
        'level' => WATCHDOG_ERROR
      );
    }
    if(empty($messages)){
      $messages[] = array(
        'message' => t('There are no new @entities.', array(
          '@entities' => strtolower($info['label plural'])
        ))
      );
    }
    foreach($messages as $message){
      drupal_set_message($message['message']);
      $source->log('import', $message['message'], array(), isset($message['level']) ? $message['level'] : WATCHDOG_INFO);
    }
  }
}

