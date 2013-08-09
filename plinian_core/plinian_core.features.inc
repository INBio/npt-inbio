<?php
/**
 * @file
 * plinian_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function plinian_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function plinian_core_node_info() {
  trigger_error("plinian_core_node_info");
  $items = array(
    'pliniancore' => array(
      'name' => t('Plinian Core'),
      'base' => 'node_content',
      'description' => t('Plinian core'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
