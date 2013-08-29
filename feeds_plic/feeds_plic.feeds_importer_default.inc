<?php
/**
 * @file
 * feeds_plic.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function feeds_plic_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'plinian_core_importer';
  $feeds_importer->config = array(
    'name' => 'Plinian Core Importer',
    'description' => 'Import species records in Plinian Core format. ',
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
        'no_headers' => 0,
        'all_worksheets' => 0,
        'max_rows' => '65535',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'pliniancore',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'TaxonRecordID',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'InstitutionCode',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'DateLastModified',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Language',
            'target' => 'field_plic_language',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Creators',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'ScientificName',
            'target' => 'field_taxonomic_name',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'GlobalUniqueIdentifier',
            'target' => 'field_plic_guid',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Contributors',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'TargetAudiences',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'DateCreated',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Kingdom',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Phylum',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Class',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Order',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Family',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Genus',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'CommonNames',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'SpeciesPublicationReference',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Synonyms',
            'target' => 'field_plic_synonims',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'AuthorYearOfScientificName',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'Typification',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'MolecularData',
            'target' => 'field_plic_molecular_data',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'ScientificDescription',
            'target' => 'field_plic_full_description',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'Abstract',
            'target' => 'field_plic_abstract',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'Habit',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'LifeCycle',
            'target' => 'field_plic_life_cycle',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'Reproduction',
            'target' => 'field_plic_reproduction',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'AnnualCycle',
            'target' => 'field_plic_anual_cycle',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'Feeding',
            'target' => 'field_plic_feeding',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'Behavior',
            'target' => 'field_plic_behavior',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'Interactions',
            'target' => 'field_plic_interactions',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'Habitat',
            'target' => 'field_plic_habitat',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'Territory',
            'target' => 'field_plic_territory',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'Endemicity',
            'target' => 'field_plic_endemism',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'Uses',
            'target' => 'field_plic_uses',
            'unique' => FALSE,
          ),
          35 => array(
            'source' => 'PopulationBiology',
            'target' => 'field_plic_population_biology',
            'unique' => FALSE,
          ),
          36 => array(
            'source' => 'Management',
            'target' => 'field_plic_management',
            'unique' => FALSE,
          ),
          37 => array(
            'source' => 'MigratoryData',
            'target' => 'field_plic_migratory',
            'unique' => FALSE,
          ),
          38 => array(
            'source' => 'InvasivenessData',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          39 => array(
            'source' => 'ThreatStatus',
            'target' => 'field_plic_threat_status',
            'unique' => FALSE,
          ),
          40 => array(
            'source' => 'Legislation',
            'target' => 'field_plic_legislation',
            'unique' => FALSE,
          ),
          41 => array(
            'source' => 'Distribution',
            'target' => 'field_plic_distribution',
            'unique' => FALSE,
          ),
          42 => array(
            'source' => 'References',
            'target' => 'field_references',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => 'pliniancore',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['plinian_core_importer'] = $feeds_importer;

  return $export;
}
