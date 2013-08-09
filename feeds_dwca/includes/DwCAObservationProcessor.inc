<?php

include_once "FeedsDwCAMappings.inc";


/**
 * @file
 * Class definition of FeedsNodeProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class DwCAObservationProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'node';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Nodes');
    return $info;
  }

  /**
   * Creates a new node in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $node = new stdClass();
    $node->type = $this->config['content_type'];
    $node->changed = REQUEST_TIME;
    $node->created = REQUEST_TIME;
    $node->language = LANGUAGE_NONE;
    node_object_prepare($node);
    // Populate properties that are set by node_object_prepare().
    $node->log = 'Created by FeedsNodeProcessor';
    $node->uid = $this->config['author'];
    return $node;
  }

  /**
   * Loads an existing node.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the node
   * table will be loaded, foregoing the node_load API for better performance.
   */
  protected function entityLoad(FeedsSource $source, $nid) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $node = node_load($nid, NULL, TRUE);
    }
    else {
      // We're replacing the existing node. Only save the absolutely necessary.
      $node = db_query("SELECT created, nid, vid, type FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchObject();
      $node->uid = $this->config['author'];
    }
    node_object_prepare($node);
    // Populate properties that are set by node_object_prepare().
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $node->log = 'Updated by FeedsNodeProcessor';
    }
    else {
      $node->log = 'Replaced by FeedsNodeProcessor';
    }
    return $node;
  }

  /**
   * Save a node.
   */
  public function entitySave($entity) {
    // If nid is set and a node with that id doesn't exist, flag as new.
    if (!empty($entity->nid) && !node_load($entity->nid)) {
      $entity->is_new = TRUE;
    }
    node_save($entity);
  }

  /**
   * Delete a series of nodes.
   */
  protected function entityDeleteMultiple($nids) {
    node_delete_multiple($nids);
  }

  /**
   * Implement expire().
   *
   * @todo: move to processor stage?
   */
  public function expire($time = NULL) {
    if ($time === NULL) {
      $time = $this->expiryTime();
    }
    if ($time == FEEDS_EXPIRE_NEVER) {
      return;
    }
    $count = $this->getLimit();
    $nodes = db_query_range("SELECT n.nid FROM {node} n JOIN {feeds_item} fi ON fi.entity_type = 'node' AND n.nid = fi.entity_id WHERE fi.id = :id AND n.created < :created", 0, $count, array(':id' => $this->id, ':created' => REQUEST_TIME - $time));
    $nids = array();
    foreach ($nodes as $node) {
      $nids[$node->nid] = $node->nid;
    }
    $this->entityDeleteMultiple($nids);
    if (db_query_range("SELECT 1 FROM {node} n JOIN {feeds_item} fi ON fi.entity_type = 'node' AND n.nid = fi.entity_id WHERE fi.id = :id AND n.created < :created", 0, 1, array(':id' => $this->id, ':created' => REQUEST_TIME - $time))->fetchField()) {
      return FEEDS_BATCH_ACTIVE;
    }
    return FEEDS_BATCH_COMPLETE;
  }

  /**
   * Return expiry time.
   */
  public function expiryTime() {
    return $this->config['expire'];
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $types = node_type_get_names();
    $type = isset($types['article']) ? 'article' : key($types);
    $type = 'dwc_1_4';
    return array(
        'content_type' => $type,
        'expire' => FEEDS_EXPIRE_NEVER,
        'author' => 0,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $types = node_type_get_names();
    array_walk($types, 'check_plain');
    $form = parent::configForm($form_state);
    $form['content_type'] = array(
        '#type' => 'select',
        '#title' => t('Content type'),
        '#description' => t('Select the content type for the nodes to be created. <strong>Note:</strong> Users with "import !feed_id feeds" permissions will be able to <strong>import</strong> nodes of the content type selected here regardless of the node level permissions. Further, users with "clear !feed_id permissions" will be able to <strong>delete</strong> imported nodes regardless of their node level permissions.', array('!feed_id' => $this->id)),
        '#options' => $types,
        '#default_value' => $this->config['content_type'],
    );
    $author = user_load($this->config['author']);
    $form['author'] = array(
        '#type' => 'textfield',
        '#title' => t('Author'),
        '#description' => t('Select the author of the nodes to be created - leave empty to assign "anonymous".'),
        '#autocomplete_path' => 'user/autocomplete',
        '#default_value' => empty($author->name) ?  'anonymous' : check_plain($author->name),
    );
    $period = drupal_map_assoc(array(FEEDS_EXPIRE_NEVER, 3600, 10800, 21600, 43200, 86400, 259200, 604800, 2592000, 2592000 * 3, 2592000 * 6, 31536000), 'feeds_format_expire');
    $form['expire'] = array(
        '#type' => 'select',
        '#title' => t('Expire nodes'),
        '#options' => $period,
        '#description' => t('Select after how much time nodes should be deleted. The node\'s published date will be used for determining the node\'s age, see Mapping settings.'),
        '#default_value' => $this->config['expire'],
    );
    $form['update_existing']['#options'] = array(
        FEEDS_SKIP_EXISTING => 'Do not update existing nodes',
        FEEDS_REPLACE_EXISTING => 'Replace existing nodes',
        FEEDS_UPDATE_EXISTING => 'Update existing nodes (slower than replacing them)',
    );
    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * Reschedule if expiry time changes.
   */
  public function configFormSubmit(&$values) {
    if ($this->config['expire'] != $values['expire']) {
      feeds_reschedule($this->id);
    }
    parent::configFormSubmit($values);
  }

  /**
   * Override setTargetElement to operate on a target item that is a node.
   */
  public function setTargetElement(FeedsSource $source, $target_node, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_node->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'feeds_source':
        // Get the class of the feed node importer's fetcher and set the source
        // property. See feeds_node_update() how $node->feeds gets stored.
        if ($id = feeds_get_importer_id($this->config['content_type'])) {
          $class = get_class(feeds_importer($id)->fetcher);
          $target_node->feeds[$class]['source'] = $value;
          // This effectively suppresses 'import on submission' feature.
          // See feeds_node_insert().
          $target_node->feeds['suppress_import'] = TRUE;
        }
        break;
      default:
        parent::setTargetElement($source, $target_node, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $type = node_type_get_type($this->config['content_type']);
    $targets = parent::getMappingTargets();
    if ($type->has_title) {
      $targets['title'] = array(
          'name' => t('Title'),
          'description' => t('The title of the node.'),
          'optional_unique' => TRUE,
      );
    }
    $targets['nid'] = array(
        'name' => t('Node ID'),
        'description' => t('The nid of the node. NOTE: use this feature with care, node ids are usually assigned by Drupal.'),
        'optional_unique' => TRUE,
    );
    $targets['uid'] = array(
        'name' => t('User ID'),
        'description' => t('The Drupal user ID of the node author.'),
    );
    $targets['status'] = array(
        'name' => t('Published status'),
        'description' => t('Whether a node is published or not. 1 stands for published, 0 for not published.'),
    );
    $targets['created'] = array(
        'name' => t('Published date'),
        'description' => t('The UNIX time when a node has been published.'),
    );
    $targets['promote'] = array(
        'name' => t('Promoted to front page'),
        'description' => t('Boolean value, whether or not node is promoted to front page. (1 = promoted, 0 = not promoted)'),
    );
    $targets['sticky'] = array(
        'name' => t('Sticky'),
        'description' => t('Boolean value, whether or not node is sticky at top of lists. (1 = sticky, 0 = not sticky)'),
    );

    // Include language field if Locale module is enabled.
    if (module_exists('locale')) {
      $targets['language'] = array(
          'name' => t('Language'),
          'description' => t('The two-character language code of the node.'),
      );
    }

    // Include comment field if Comment module is enabled.
    if (module_exists('comment')) {
      $targets['comment'] = array(
          'name' => t('Comments'),
          'description' => t('Whether comments are allowed on this node: 0 = no, 1 = read only, 2 = read/write.'),
      );
    }


    // If the target content type is a Feed node, expose its source field.
    if ($id = feeds_get_importer_id($this->config['content_type'])) {
      $name = feeds_importer($id)->config['name'];
      $targets['feeds_source'] = array(
          'name' => t('Feed source'),
          'description' => t('The content type created by this processor is a Feed Node, it represents a source itself. Depending on the fetcher selected on the importer "@importer", this field is expected to be for example a URL or a path to a file.', array('@importer' => $name)),
          'optional_unique' => TRUE,
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'node', $this->config['content_type']);

    return $targets;
  }

  /**
   * Get nid of an existing feed item node if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($nid = parent::existingEntityId($source, $result)) {
      return $nid;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'nid':
          $nid = db_query("SELECT nid FROM {node} WHERE nid = :nid", array(':nid' => $value))->fetchField();
          break;
        case 'title':
          $nid = db_query("SELECT nid FROM {node} WHERE title = :title", array(':title' => $value))->fetchField();
          break;
        case 'feeds_source':
          if ($id = feeds_get_importer_id($this->config['content_type'])) {
            $nid = db_query("SELECT fs.feed_nid FROM {node} n JOIN {feeds_source} fs ON n.nid = fs.feed_nid WHERE fs.id = :id AND fs.source = :source", array(':id' => $id, ':source' => $value))->fetchField();
          }
          break;
      }
      if ($nid) {
        // Return with the first nid found.
        return $nid;
      }
    }
    return 0;
  }

  /**
   * Process the result of the parsing stage.
   *
   * @param FeedsSource $source
   *   Source information about this import.
   * @param FeedsParserResult $parser_result
   *   The result of the parsing stage.
   */
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {

    // get the current state (this is to update the progress bar).
    $state = $source->state(FEEDS_PROCESS);

    // Run over all the results
    while ($item = $parser_result->shiftItem()) {

      //Process every item

      try {

        // --------------------
        // Set the configuration to extract locations.
        $this->setConfig(FeedsDwCAMappings::get_specimen_config());

        $parser_result->current_item['specimen_observation_title'] =
        $parser_result->current_item['http://rs.tdwg.org/dwc/terms/institutionCode'].":"
            .$parser_result->current_item['http://rs.tdwg.org/dwc/terms/collectionCode'].":"
                .$parser_result->current_item['http://rs.tdwg.org/dwc/terms/catalogNumber'];

        if (!($entity_id = $this->existingEntityId($source, $parser_result))){
          // Assemble node, map item to it, save.

          #$entity = $this->__create_new_entity($entity_id, $source, $hash);
          $entity = $this->__create_new_entity($entity_id, $source);

                  // Create the location title
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

          // complete the entity data with this.
          $this->map($source, $parser_result, $entity);

          // validate and save
          $state = $this->__validate_and_save($entity, $source, $state);
        }

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

  /**
   * Execute mapping on an item.
   *
   * This method encapsulates the central mapping functionality. When an item is
   * processed, it is passed through map() where the properties of $source_item
   * are mapped onto $target_item following the processor's mapping
   * configuration.
   *
   * For each mapping FeedsParser::getSourceElement() is executed to retrieve
   * the source element, then FeedsProcessor::setTargetElement() is invoked
   * to populate the target item properly. Alternatively a
   * hook_x_targets_alter() may have specified a callback for a mapping target
   * in which case the callback is asked to populate the target item instead of
   * FeedsProcessor::setTargetElement().
   *
   * @ingroup mappingapi
   *
   * @see hook_feeds_parser_sources_alter()
   * @see hook_feeds_data_processor_targets_alter()
   * @see hook_feeds_node_processor_targets_alter()
   * @see hook_feeds_term_processor_targets_alter()
   * @see hook_feeds_user_processor_targets_alter()
   */
  protected function map(FeedsSource $source, FeedsParserResult $result, $target_item = NULL) {

    // Static cache $targets as getMappingTargets() may be an expensive method.
    static $sources;
    if (!isset($sources[$this->id])) {
      $sources[$this->id] = feeds_importer($this->id)->parser->getMappingSources();
    }
    static $targets;
    if (!isset($targets[$this->id])) {
      $targets[$this->id] = $this->getMappingTargets();
    }
    $parser = feeds_importer($this->id)->parser;
    if (empty($target_item)) {
      $target_item = array();
    }

    // Many mappers add to existing fields rather than replacing them. Hence we
    // need to clear target elements of each item before mapping in case we are
    // mapping on a prepopulated item such as an existing node.
    foreach ($this->config['mappings'] as $mapping) {
      if (isset($targets[$this->id][$mapping['target']]['real_target'])) {
        unset($target_item->{$targets[$this->id][$mapping['target']]['real_target']});
      }
      elseif (isset($target_item->{$mapping['target']})) {
        unset($target_item->{$mapping['target']});
      }
    }

    /*
     This is where the actual mapping happens: For every mapping we envoke
    the parser's getSourceElement() method to retrieve the value of the source
    element and pass it to the processor's setTargetElement() to stick it
    on the right place of the target item.

    If the mapping specifies a callback method, use the callback instead of
    setTargetElement().
    */
    self::loadMappers();
    foreach ($this->config['mappings'] as $mapping) {
      // Retrieve source element's value from parser.
      if (isset($sources[$this->id][$mapping['source']]) &&
          is_array($sources[$this->id][$mapping['source']]) &&
          isset($sources[$this->id][$mapping['source']]['callback']) &&
          function_exists($sources[$this->id][$mapping['source']]['callback'])) {
        $callback = $sources[$this->id][$mapping['source']]['callback'];
        $value = $callback($source, $result, $mapping['source']);
      }
      else {
        $value = $parser->getSourceElement($source, $result, $mapping['source']);
      }

      // Map the source element's value to the target.
      if (isset($targets[$this->id][$mapping['target']]) &&
          is_array($targets[$this->id][$mapping['target']]) &&
          isset($targets[$this->id][$mapping['target']]['callback']) &&
          function_exists($targets[$this->id][$mapping['target']]['callback'])) {
        $callback = $targets[$this->id][$mapping['target']]['callback'];
        $callback($source, $target_item, $mapping['target'], $value);
      }
      else {
        $this->setTargetElement($source, $target_item, $mapping['target'], $value);
      }
    }
    return $target_item;
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




