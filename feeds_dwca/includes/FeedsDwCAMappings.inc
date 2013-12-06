<?php

/**
 * @file
 * Class definition of FeedsDwCAMappings
 *
 * Sets the default of the mappings to use in this the 
 * feeds_dwca module for both importers (for location and specimen/observation
 * content types)
 */


class FeedsDwCAMappings {


  public static function get_provider_config(){
    return   array(
        'content_type' => 'data_provider',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
            0 => array(
                'source' => 'data_provider_title',
                'target' => 'title',
                'unique' => TRUE,
            ),
            1 => array(
                'source' => 'data_provider_description',
                'target' => 'field_data_provider_description',
                'unique' => FALSE,
            ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
    );
  }

  public static function get_resource_config(){

    return   array(
        'content_type' => 'data_resource',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
            0 => array(
                'source' => 'data_resource_title',
                'target' => 'title',
                'unique' => TRUE,
            ),
            1 => array(
                'source' => 'data_resource_description',
                'target' => 'field_data_resource_description',
                'unique' => FALSE,
            ),
            1 => array(
                'source' => 'data_provider_title',
                'target' => 'field_data_provider:title',
                'unique' => FALSE,
            ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
    );
  }

  public static function get_location_config(){

    return   array(
        'content_type' => 'location',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
            0 => array(
                'source' => 'map',
                'target' => 'field_map',
                'unique' => FALSE,
            ),
            1 => array(
                'source' => 'location_title',
                'target' => 'title',
                'unique' => TRUE,
            ),
            2 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/continent',
                'target' => 'field_continent_or_ocean',
                'unique' => FALSE,
            ),
            3 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/coordinateUncertaintyInMeters',
                'target' => 'field_coordinate_uncertainty',
                'unique' => FALSE,
            ),
            4 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/country',
                'target' => 'node:location:field_country:name',
                'unique' => FALSE,
            ),
            5 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/county',
                'target' => 'field_county',
                'unique' => FALSE,
            ),
            6 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/geodeticDatum',
                'target' => 'field_geodetic_datum',
                'unique' => FALSE,
            ),
            7 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/georeferenceProtocol',
                'target' => 'field_georeference_protocol',
                'unique' => FALSE,
            ),
            8 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/georeferenceRemarks',
                'target' => 'field_georeference_remarks',
                'unique' => FALSE,
            ),
            9 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/island',
                'target' => 'field_island',
                'unique' => FALSE,
            ),
            10 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/islandGroup',
                'target' => 'field_island_group',
                'unique' => FALSE,
            ),
            11 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/locality',
                'target' => 'field_locality',
                'unique' => FALSE,
            ),
            12 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/maximumDepthInMeters',
                'target' => 'field_max_depth',
                'unique' => FALSE,
            ),
            13 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/maximumElevationInMeters',
                'target' => 'field_max_elevation',
                'unique' => FALSE,
            ),
            14 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/stateProvince',
                'target' => 'field_state_province',
                'unique' => FALSE,
            ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
    );
  }

  public static function get_specimen_config(){

    return array(
        'content_type' => 'specimen_observation',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
            0 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/basisOfRecord',
                'target' => 'field_basis_of_record',
                'unique' => FALSE,
            ),
            1 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/catalogNumber',
                'target' => 'field_catalogue_number',
                'unique' => FALSE,
            ),
            2 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/collectionCode',
                'target' => 'field_collection_code',
                'unique' => FALSE,
            ),
            3 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/dateIdentified',
                'target' => 'field_date_identified:end',
                'unique' => FALSE,
            ),
            4 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/fieldNotes',
                'target' => 'field_notes',
                'unique' => FALSE,
            ),
            5 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/fieldNumber',
                'target' => 'field_number',
                'unique' => FALSE,
            ),
            6 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/identificationQualifier',
                'target' => 'field_identification_qualifier',
                'unique' => FALSE,
            ),
            7 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/institutionCode',
                'target' => 'field_institution_code',
                'unique' => FALSE,
            ),
            8 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/lifeStage',
                'target' => 'field_lifestage',
                'unique' => FALSE,
            ),
            9 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/otherCatalogNumbers',
                'target' => 'field_other_catalogue_numbers',
                'unique' => FALSE,
            ),
            10 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/occurrenceRemarks',
                'target' => 'field_remarks',
                'unique' => FALSE,
            ),
            11 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/sex',
                'target' => 'field_sex',
                'unique' => FALSE,
            ),
            12 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/scientificName',
                'target' => 'field_taxonomic_name',
                'unique' => FALSE,
            ),
            13 => array(
                'source' => 'http://rs.tdwg.org/dwc/terms/typeStatus',
                'target' => 'field_type_status',
                'unique' => FALSE,
            ),
            14 => array(
                'source' => 'specimen_observation_title',
                'target' => 'title',
                'unique' => TRUE,
            ),
            15 => array(
                'source' => 'location_title',
                'target' => 'field_location:title',
                'unique' => FALSE,
            ),
            16 => array(
                'unique' => FALSE,
            ),
            16 => array(
              'source' => 'id',
              'target' => 'nid',
              'unique' => TRUE,
            ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
    );
  }
}
