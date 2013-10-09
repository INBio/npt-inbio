<?php
/**
 * @file
 * feeds_xlsimages_specimen_observation_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function feeds_xlsimages_feeds_importer_default() {
  $export = array();

  // feeds_xlsimages_specimen_observation_importer
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feeds_xlsimages_specimen_observation_importer';
  $feeds_importer->config = array(
    'name' => 'Feeds Remote Images Importer',
    'description' => 'Import images from a remote location',

    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'xls xlsx',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExcelParser',
      'config' => array(
        'all_worksheets' => 0,
        'max_rows' => 65535,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'RemoteImageProcessor',
      'config' => array(
        'content_type' => 'image',
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => TRUE,
          ),
          1 => array(
            'source' => 'Filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Media galleries (NID)',
            'target' => 'field_smg_galleries:nid:duplicates',
            'unique' => 0,
          ),
          3 => array(
            'source' => 'Media galleries (Title)',
            'target' => 'field_smg_galleries:title:duplicates',
            'unique' => 0,
          ),
          4 => array(
            'source' => 'Taxonomic name (Name)',
            'target' => 'field_taxonomic_name',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'Taxonomic name (TID)',
            'target' => 'field_taxonomic_name:tid',
            'unique' => 0,
          ),
          6 => array(
            'source' => 'Taxonomic name (GUID)',
            'target' => 'field_taxonomic_name:guid',
            'unique' => 0,
          ),
          7 => array(
            'source' => 'Licence',
            'target' => 'field_cc_licence',
            'unique' => 0,
          ),
          8 => array(
            'source' => 'Imaging technique (Name)',
            'target' => 'field_imaging_technique',
            'unique' => 0,
          ),
          9 => array(
            'source' => 'Imaging technique (TID)',
            'target' => 'field_imaging_technique:tid',
            'unique' => 0,
          ),
          10 => array(
            'source' => 'Imaging technique (GUID)',
            'target' => 'field_imaging_technique:guid',
            'unique' => 0,
          ),
          11 => array(
            'source' => 'Keywords (Name)',
            'target' => 'field_keywords',
            'unique' => 0,
          ),
          12 => array(
            'source' => 'Keywords (TID)',
            'target' => 'field_keywords:tid',
            'unique' => 0,
          ),
          13 => array(
            'source' => 'Keywords (GUID)',
            'target' => 'field_keywords:guid',
            'unique' => 0,
          ),
          14 => array(
            'source' => 'Preparation technique (Name)',
            'target' => 'field_preparation_technique',
            'unique' => 0,
          ),
          15 => array(
            'source' => 'Preparation technique (TID)',
            'target' => 'field_preparation_technique:tid',
            'unique' => 0,
          ),
          16 => array(
            'source' => 'Preparation technique (GUID)',
            'target' => 'field_preparation_technique:guid',
            'unique' => 0,
          ),
          17 => array(
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => 0,
          ),
          18 => array(
            'source' => 'Sticky at top of lists',
            'target' => 'field_sticky',
            'unique' => 0,
          ),
          19 => array(
            'source' => 'Creator',
            'target' => 'field_creator',
            'unique' => 0,
          ),
          20 => array(
            'source' => 'Weight',
            'target' => 'field_weight',
            'unique' => 0,
          ),
        ),
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
  $export['feeds_xlsimages_importer'] = $feeds_importer;
  

  return $export;
}
