<?php
/**
 * @file
 * feeds_plic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feeds_plic_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
