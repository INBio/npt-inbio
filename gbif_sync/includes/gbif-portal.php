<?php

error_reporting(E_ALL);
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);

/**
 * Uses the GBIF data portal web services to retrieve occurrence data of a 
 * specified country
 *
 * @autor asanabria (20130109)
 */

define('DATA_PORTAL_URL', 'http://data.gbif.org/ws/rest/occurrence');

/**
 * Return occurrence count of certain country  using the GBIF web services
 *
 * @param $country_code
 *  ISO (two letter) country code  
 *
 * @return 
 *  String format of the xml response.
 */
function get_occurrence_count( $country_code = 'cr'){

    $url = DATA_PORTAL_URL.'/count?'."&originisocountrycode=$country_code";
    // FIXME: in this fucntion the process have to wait for the download of the data.
    $info = file_get_contents($url);

    $xml_string = clean_gbif_xml($info);
    $simplexml = load_gbif_xml($xml_string);

    $summary = $simplexml->xpath('//summary');
    $count = (String) $summary[0]->attributes()->totalMatched;

    return $count;
  }

/**
 * Return occurrence records for a certain country  using the GBIF web services
 *
 * @param $country_code
 *  ISO (two letter) country code  
 * @param $start_index
 *  Start index for pagination porpuses
 * @param $max_results
 *  Size of the resultset
 * @param $format
 *  GBIF specific parameter
 *    brief: presents a small amount of record specific info.
 *    darwin: presents all the dwc fields availables
 *    kml: return the info in kml format.
 * @param $mode
 *  GBIF specific parameter
 *    raw: data as provided
 *    processed: data as presented after gbif processing
 *
 * @return 
 *  String format of the xml response.
 */
function get_occurrence_list( $country_code = 'cr', $start_index = 0,
  $max_results = 1000, $format = 'darwin', $mode = 'processed'){

    $url = DATA_PORTAL_URL.'/list?'.
      "startindex=$start_index".
      "&maxresults=$max_results".
      "&originisocountrycode=$country_code".
      "&format=$format".
      "&mode=$mode";

    $info = file_get_contents($url);

    return $info;
  }

/**
 * Deletes the namespaces of the xml elements
 *
 * @param $xml_string
 *  String representation of a full xml response
 *
 * @return 
 *  Xml string representation whiout namespaces
 */ 
function clean_gbif_xml($xml_string){

    $xml_string = preg_replace('/<[a-zA-z]+:/', "<", $xml_string);
    $xml_string = preg_replace('/<\/[a-zA-z]+:/', "</", $xml_string);

    return $xml_string;
}

/**
 * Transform into SimpleXMLElement representation string representation of the 
 * xml response
 *
 * @para $xml_string
 *  string representation of the xml response
 *
 * @return 
 *  SimpleXML representation of the input string
 */
function load_gbif_xml($xml_string){

    libxml_use_internal_errors(true);

    // Read the xml by using simplexml library.
    $xml = simplexml_load_string($xml_string);

    #print_r($sxe);

    if ($xml === false) {
        echo "Failed loading XML\n";
        foreach(libxml_get_errors() as $error) {
            echo "\t", $error->message;
        }
    }

    return $xml;
}

/**
 * Review an gbif xml response object and extract the data resource names
 *
 * @param $gbif_xml
 *  $SimpleXML representation of a GBIF Response xml.
 *
 * @return 
 *  Array containing the names of the data resources in the xml response
 */
function extract_data_resource_names($gbif_xml, $data_provider_name_list = Array()){

    #$data_provider_name_list = Array();

    foreach ( $gbif_xml->xpath('//dataResource') as $data_resource){
      $data_provider_name_list[ (String)$data_resource['gbifKey'] ] = (String)$data_resource->name;
    }

    return $data_provider_name_list;
}


/**
 * Review an gbif xml response object and extract the occurrence records.
 *
 */
function get_occurrence_data($gbif_xml, $occurrence_records = Array()){

  foreach ( $gbif_xml->xpath('//dataProvider') as $data_provider){
    #    print "==========>  ".$data_provider->name;
    #    print "\n";
    $data_resources = $data_provider->xpath('dataResources');
    foreach( $data_resources[0] as $data_resource){
      #      print $data_resource->name;
      #      print "\n";
      #
      if( ! isset($occurrence_records[(String)$data_provider->name]) ){
        $occurrence_records[(String)$data_provider->name] = Array();
      }

      if( ! isset($occurrence_records[(String)$data_provider->name][(String)$data_resource->name] ) ){
        $occurrence_records[(String)$data_provider->name][(String)$data_resource->name] = Array();
      }

      foreach ( $data_resource->occurrenceRecords->TaxonOccurrence as $current_item){

          $array_format = Array(
              'gbif_key' => (String) $current_item['gbifKey'],
              'basis_of_record' => (String) $current_item->basisOfRecordString,
              'catalog_number' => (String)$current_item->catalogNumber,
              'collection_code' => (String) $current_item->collectionCode,
              'collector' => (String) $current_item->collector,
              'continent' => (String) $current_item->continent,
              'coordinate_uncertainty_in_meters' => (String) $current_item->coordinateUncertaintyInMeters,
              'country'=> (String)$current_item->country,
              'decimal_latitude' => (String)$current_item->decimalLatitude,
              'decimal_longitude' => (String)$current_item->decimalLongitude,
              'institution_code' => (String) $current_item->institutionCode,
              'maximum_elevation_in_meters' => (String) $current_item->maximumElevationInMeters,
              'maximum_elevation_in_meters' => (String) $current_item->maximumElevationInMeters,
              'state_province' => (String) $current_item->stateProvince,
              'county' => (String) $current_item->county,
              'earliest_date_collected' => (String)$current_item->earliestDateCollected,
              'latest_date_collected' => (String)$current_item->latestDateCollected,
              'scientific_name' => (String)$current_item->identifiedTo->Identification->taxon->TaxonConcept->hasName->TaxonName->nameComplete,
              'locality' => (String) $current_item->locality
              );

              array_push(
                      $occurrence_records[(String)$data_provider->name][(String)$data_resource->name],
                      $array_format);
      }

      # var_dump($data_resource->occurrenceRecords->TaxonOccurrence);
      # var_dump($current_item->identifiedTo->Identification->taxon);

    }
  }
  return $occurrence_records;
}


function get_csvformated_occurrence_data($gbif_xml, $occurrence_records = Array()){

  $headers = Array(
    'gbif_key' ,
    'data_provider' ,
    'data_resource' ,
    'basis_of_record' ,
    'catalog_number' ,
    'collection_code' ,
    'collector' ,
    'continent' ,
    'coordinate_uncertainty_in_meters' ,
    'country',
    'decimal_latitude' ,
    'decimal_longitude' ,
    'institution_code' ,
    'maximum_elevation_in_meters' ,
    'maximum_elevation_in_meters' ,
    'state_province' ,
    'county' ,
    'earliest_date_collected' ,
    'latest_date_collected' ,
    'scientific_name' ,
    'locality' ,
  );

  array_push( $occurrence_records, implode(',', $headers));

  foreach ( $gbif_xml->xpath('//dataProvider') as $data_provider){

    $data_resources = $data_provider->xpath('dataResources');

    foreach( $data_resources[0] as $data_resource){

      foreach ( $data_resource->occurrenceRecords->TaxonOccurrence as $current_item){

        $records = Array(
          (String) $current_item['gbifKey'],
          (String) $data_provider->name,
          (String) $data_resource->name,
          (String) $current_item->basisOfRecordString,
          (String) $current_item->catalogNumber,
          (String) $current_item->collectionCode,
          (String) $current_item->collector,
          (String) $current_item->continent,
          (String) $current_item->coordinateUncertaintyInMeters,
          (String) $current_item->country,
          (String) $current_item->decimalLatitude,
          (String) $current_item->decimalLongitude,
          (String) $current_item->institutionCode,
          (String) $current_item->maximumElevationInMeters,
          (String) $current_item->maximumElevationInMeters,
          (String) $current_item->stateProvince,
          (String) $current_item->county,
          (String) $current_item->earliestDateCollected,
          (String) $current_item->latestDateCollected,
          (String) $current_item->identifiedTo->Identification->taxon->TaxonConcept->hasName->TaxonName->nameComplete,
          (String) $current_item->locality
        );

        array_push( $occurrence_records, implode("\t", $records));
      }
    }
  }
  return $occurrence_records;
}

