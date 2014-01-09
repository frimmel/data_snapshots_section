<?php
/**
 * @file
 * data_snapshots_data_source.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function data_snapshots_data_source_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function data_snapshots_data_source_node_info() {
  $items = array(
    'data_snapshot_data_source' => array(
      'name' => t('Data Snapshot Data Source'),
      'base' => 'node_content',
      'description' => t('Content type for Data Snapshot Data Sources'),
      'has_title' => '1',
      'title_label' => t('Public Name for Dataset'),
      'help' => '',
    ),
  );
  return $items;
}
