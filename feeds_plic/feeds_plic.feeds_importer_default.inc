<?php
/**
 * @file
 * feeds_plic.feeds_importer_default.inc
 *
 * Add the configuration of the 
 *     - 'Plinian Core Importer'
 *         (pliniancore_importer)
 */

/**
 * Implements hook_feeds_importer_default().
 *
 * To add the default configuration of the pliniancore_importer
 *
 */
function feeds_plic_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'pliniancore_importer';
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
            'target' => 'taxon_record_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'InstitutionCode',
            'target' => 'institution_code',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'DateLastModified',
            'target' => 'date_last_modified',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Language',
            'target' => 'language',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Creators',
            'target' => 'creators',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'ScientificName',
            'target' => 'field_taxonomic_name',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'GlobalUniqueIdentifier',
            'target' => 'global_unique_identifier',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Contributors',
            'target' => 'contributors',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'TargetAudiences',
            'target' => 'target_audiences',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'DateCreated',
            'target' => 'date_created',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Kingdom',
            'target' => 'kingdom',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Phylum',
            'target' => 'phylum',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Class',
            'target' => 'class',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Order',
            'target' => 'order',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Family',
            'target' => 'family',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Genus',
            'target' => 'genus',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'CommonNames',
            'target' => 'common_names',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'SpeciesPublicationReference',
            'target' => 'species_publication_reference',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Synonyms',
            'target' => 'synonyms',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'AuthorYearOfScientificName',
            'target' => 'author_year_of_scientific_name',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'Typification',
            'target' => 'typification',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'MolecularData',
            'target' => 'molecular_data',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'ScientificDescription',
            'target' => 'scientific_description',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'Abstract',
            'target' => 'abstract',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'Habit',
            'target' => 'habit',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'LifeCycle',
            'target' => 'life_cycle',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'Reproduction',
            'target' => 'reproduction',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'AnnualCycle',
            'target' => 'annual_cycle',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'Feeding',
            'target' => 'feeding',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'Behavior',
            'target' => 'behavior',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'Interactions',
            'target' => 'interactions',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'Habitat',
            'target' => 'habitat',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'Territory',
            'target' => 'territory',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'Endemicity',
            'target' => 'endemicity',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'Uses',
            'target' => 'uses',
            'unique' => FALSE,
          ),
          35 => array(
            'source' => 'PopulationBiology',
            'target' => 'population_biology',
            'unique' => FALSE,
          ),
          36 => array(
            'source' => 'Management',
            'target' => 'management',
            'unique' => FALSE,
          ),
          37 => array(
            'source' => 'MigratoryData',
            'target' => 'migratory_data',
            'unique' => FALSE,
          ),
          38 => array(
            'source' => 'InvasivenessData',
            'target' => 'invasiveness_data',
            'unique' => FALSE,
          ),
          39 => array(
            'source' => 'ThreatStatus',
            'target' => 'threat_status',
            'unique' => FALSE,
          ),
          40 => array(
            'source' => 'Legislation',
            'target' => 'legislation',
            'unique' => FALSE,
          ),
          41 => array(
            'source' => 'Distribution',
            'target' => 'distribution',
            'unique' => FALSE,
          ),
          42 => array(
            'source' => 'References',
            'target' => 'references',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
      ),
    ),
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['pliniancore_importer'] = $feeds_importer;

  return $export;
}
