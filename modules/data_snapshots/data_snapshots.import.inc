<?php

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
	  7 => array(
	    'source' => 'date_generated',
	    'target' => 'field_ds_dtgen:start',
	    'unique' => FALSE,
	  ),
	  8 => array(
		     'source' => 'download_title',
		     'target' => 'field_ds_dloads:title',
		     'unique' => FALSE,
		     ),
	  9 => array(
		     'source' => 'download_url',
		     'target' => 'field_ds_dloads:url',
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
