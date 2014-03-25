<?php
/**
 * @file
 * data_snapshots.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function data_snapshots_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:node/add/data-snapshot-data-source
  $menu_links['navigation:node/add/data-snapshot-data-source'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/data-snapshot-data-source',
    'router_path' => 'node/add/data-snapshot-data-source',
    'link_title' => 'Data Snapshot Data Source',
    'options' => array(
      'attributes' => array(
        'title' => 'Content type for Data Snapshot Data Sources',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Data Snapshot Data Source');


  return $menu_links;
}
