<?php
  // Q: what is going on in commented out blocks. remove?


/**
 * Implementation of hook_feeds_importer_default().
 */
function data_snapshots_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'data_snapshot_importer';
  $feeds_importer->config = array(
    'name' => 'Data Snapshot Importer',
    'description' => 'Imports Data Snapshot nodes from a CSV file via an HTTP URL',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'dsmn',
            'target' => 'field_ds_dsds_mn',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'ptk',
            'target' => 'field_ds_ptk',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'stk',
            'target' => 'field_ds_stk',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'image_url',
            'target' => 'field_ds_disimg:url',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'about',
            'target' => 'body',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'data_snapshot',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['data_snapshots'] = $feeds_importer;
  
  return $export;
}

// function data_snapshots_module_implements_alter(&$module_list, $context){
//    if (array_key_exists('data_snapshots', $module_list)) {
//        $a_foofoo = $context;
//    }
//    if($context === "node_insert") {
//      $temp = $module_list['data_snapshots'];
//      // Removing the data_snapshots key/value
//      unset($module_list['data_snapshots']);
//      // Adding the data_snapshots key value as the last member in the list
//      $module_list['data_snapshots'] = $temp;
//    }
// }
// 
// function data_snapshots_feeds_processor_targets_alter(&$target, $type, $bundle) {
//   if ($bundle == 'data_snapshots') {
//     $target['data_snapshots_image_480'] = array(
//                         'name' => t('Altered Data Image 480'),
//                         'description' => t('Altered Data Snapshots Image 480!!!'),
//                         'callback' => 'data_snapshots_set_target',
//                         );
//   }
// }
// 
// function data_snapshots_feeds_processor_targets() {
//   dsm('hey ho!');
// }
// 
// function data_snapshots_set_target($source, $entity, $target, $value, $mapping) {
//   $entity->{$target}[$entity->language][0]['value'] = $value;
//   if (isset($source->importer->processor->config['input_format'])) {
//     $entity->{$target}[$entity->language][0]['format'] =
//       $source->importer->processor->config['input_format'];
//   }
// }
// 
// function data_snapshots_foo_callback() {
//   dsm('data_snapshots_foo_callback !!!');
// }
// 
// function data_snapshots_my_setter_callback($source, $entity, $mapping_target, $value, $mapping) {
//   dsm($entity);
//   dsm($value);
//   //'data_snapshots_image_480',
// }

//xxx /**
//xxx  * Implementation of hook_feeds_importer_default().
//xxx  */
//xxx function CSV_data_snapshots_feeds_importer_default() {
//xxx   $export = array();
//xxx 
//xxx   $feeds_importer = new stdClass;
//xxx   $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
//xxx   $feeds_importer->api_version = 1;
//xxx   $feeds_importer->id = 'data_snapshots';
//xxx   $feeds_importer->config = array(
//xxx     'name' => 'Data Snapshots import',
//xxx     'description' => 'Import data snapshots nodes from CSV file.',
//xxx     'fetcher' => array(
//xxx       'plugin_key' => 'FeedsFileFetcher',
//xxx       'config' => array(
//xxx         'direct' => FALSE,
//xxx       ),
//xxx     ),
//xxx     'parser' => array(
//xxx       'plugin_key' => 'FeedsCSVParser',
//xxx       'config' => array(
//xxx         'delimiter' => ',',
//xxx       ),
//xxx     ),
//xxx     'processor' => array(
//xxx       'plugin_key' => 'FeedsNodeProcessor',
//xxx       'config' => array(
//xxx         'bundle' => 'data_snapshots',
//xxx         'update_existing' => 1,
//xxx         'expire' => '-1',
//xxx         'mappings' => array(
//xxx           0 => array(
//xxx             'source' => 'title',
//xxx             'target' => 'title',
//xxx             'unique' => FALSE,
//xxx           ),
//xxx           2 => array(
//xxx             'source' => 'year',
//xxx             'target' => 'data_snapshots_year',
//xxx             'unique' => FALSE,
//xxx           ),
//xxx           3 => array(
//xxx             'source' => 'month',
//xxx             'target' => 'data_snapshots_month',
//xxx             'unique' => FALSE,
//xxx           ),
//xxx           4 => array(
//xxx             'source' => 'day',
//xxx             'target' => 'data_snapshots_day',
//xxx             'unique' => FALSE,
//xxx           ),
//xxx           5 => array(
//xxx             'source' => 'image_480',
//xxx             'target' => 'data_snapshots_image_480',
//xxx             'unique' => FALSE,
//xxx           ),
//xxx           6 => array(
//xxx             'source' => 'image_620',
//xxx             'target' => 'data_snapshots_image_620',
//xxx             'unique' => FALSE,
//xxx           ),
//xxx         ),
//xxx         'input_format' => 'plain_text',
//xxx         'author' => 0,
//xxx       ),
//xxx     ),
//xxx     'content_type' => '',
//xxx     'update' => 0,
//xxx     'import_period' => '-1',
//xxx     'expire_period' => 3600,
//xxx     'import_on_create' => 1,
//xxx   );
//xxx   $export['data_snapshots'] = $feeds_importer;
//xxx 
//xxx   return $export;
//xxx }
//xxx 
