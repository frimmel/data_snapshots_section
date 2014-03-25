<?php
  /**
   * @file
   * data_snapshots.context.inc
   */

  /**
   * Implements hook_context_default_contexts().
   */
function data_snapshots_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'data-snapshot';
  $context->description = 'Data Snapshot section context';
  $context->tag = 'data';
  $context->conditions = array(
			       'node' => array(
					       'values' => array(
								 'data_snapshot' => 'data_snapshot',
								 'data_snapshot_data_source' => 'data_snapshot_data_source',
								 ),
					       'options' => array(
								  'node_form' => '1',
								  ),
					       ),
			       'path' => array(
					       'values' => array(
								 '*data-snapshot*' => '*data-snapshot*',
								 ),
					       ),
			       );
  $context->reactions = array(
			      'block' => array(
					       'blocks' => array(
								 'menu-menu-data-submenu' => array(
												   'module' => 'menu',
												   'delta' => 'menu-data-submenu',
												   'region' => 'menu',
												   'weight' => '-10',
												   ),
								 ),
					       ),
			      'menu' => 'node/427',
			      'theme_html' => array(
						    'class' => 'context-data',
						    ),
			      );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Data Snapshot section context');
  t('data');
  $export['data-snapshot'] = $context;

  return $export;
}
