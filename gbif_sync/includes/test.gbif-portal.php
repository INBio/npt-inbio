<?php 

include_once('gbif-portal.php');

// Testing area

function test(){

  print date("H:i:s")."\n";

  $results = Array();

  for ($i = 0; $i< 60000; $i=$i+1000){

    print $i."\n";
    $wsresponse =  get_occurrence_list('bj', $i, 1000);
    $clean_wsresponse = clean_gbif_xml($wsresponse);
    $xml = load_gbif_xml($clean_wsresponse);
    if (! $xml === false){
      $results = extract_data_resource_names($xml, $results );
    }
  }

  print "";
  print count($results);
  print "";
  /*
  foreach( $results as $gbif_key => $data_provider_name){
    print $gbif_key ." =0= ".$data_provider_name."\n";
  }
   */
  print date("H:i:s");
}

function test2(){

  print date("H:i:s")."\n";

  $results = Array();

  for ($i = 0; $i< 1000; $i=$i+1000){

    print $i."\n";
    $wsresponse =  get_occurrence_list('bj', $i, 1000);
    $clean_wsresponse = clean_gbif_xml($wsresponse) ;
    $xml = load_gbif_xml($clean_wsresponse);
    if (! $xml === false){
      $results = get_occurrence_data($xml, $results);
    }
  }

  var_dump($results);

  /*
  foreach($results as $dp => $dr){
    #    print $dp. "     ";
    foreach( $dr as $name => $records){
      #            print $name."\n";
      foreach ($records as $record){
        print implode(',', array_values($record));
        print "\n";
      }
    }
  }
   */

#   array_push(
#     $occurrence_records[(String)$data_provider->name][(String)$data_resource->name],
#     $array_format);

#  var_dump($results);

  print date("H:i:s");
}

function test3(){

  print date("H:i:s")."\n";

  $results = Array();
  $filename = tempnam(".",  "occurrence_test");

  for ($i = 0; $i <= 2000; $i=$i+1000){

    print $i."\n";
    $wsresponse =  get_occurrence_list('bj', $i, 1000);
    $clean_wsresponse = clean_gbif_xml($wsresponse) ;
    $xml = load_gbif_xml($clean_wsresponse);
    if (! $xml === false){
      $results = get_csvformated_occurrence_data($xml);
    }

    if($i > 0){
      unset($results[0]);
    }

    file_put_contents($filename, implode("\n", $results), FILE_APPEND );

    /*
    #print implode("\n", $results);
    foreach($results as $row){
      print $row;
      print "\n";
    }
     */
  }

#  var_dump($results);
  print date("H:i:s");
}

function test4(){

  print date("H:i:s")."\n";

  get_occurrence_count('bj');

  print date("H:i:s")."\n";
}

#test();
test2();
#test3();
#test4();

