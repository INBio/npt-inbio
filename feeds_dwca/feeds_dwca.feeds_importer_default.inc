<?php
/**
 * @file
 * feeds_dwca_specimen_observation_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function feeds_dwca_feeds_importer_default() {
  $export = array();

  // feeds_dwca_specimen_observation_importer
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feeds_dwca_specimen_observation_importer';
  $feeds_importer->config = array(
    'name' => 'Feeds DwC-A Obsevarion/Specimen Importer',
    'description' => 'Import observations/specimens from a DwC-A file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'zip',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'DwCAParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'DwCAObservationProcessor',
      'config' => array(
        'content_type' => 'dwc_1_4',
        'expire' => -1,
        'author' => 0,
        'mappings' => array(),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['feeds_dwca_specimen_observation_importer'] = $feeds_importer;
  
  unset($feeds_importer);
  
  // feeds_dwca_location_importer
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feeds_dwca_location_importer';
  $feeds_importer->config = array(
    'name' => 'Feeds DwC-A Location Importer',
    'description' => 'Import locations from a DwC-A file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'zip',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'DwCAParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'DwCALocationProcessor',
      'config' => array(
        'content_type' => 'dwc_1_4',
        'expire' => -1,
        'author' => 0,
        'mappings' => array(),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['feeds_dwca_location_importer'] = $feeds_importer;

  return $export;
}
