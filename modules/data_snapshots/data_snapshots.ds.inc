<?php
  /**
   * @file
   * data_snapshots.ds.inc
   */

  /**
   * Implements hook_ds_custom_fields_info().
   */
function data_snapshots_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'data_snapshot_permalink';
  $ds_field->label = 'Permalink';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
			      'node' => 'node',
			      );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
				'code' => array(
						'value' => '<?php print(url(\'node/\' . $entity->nid, array(\'absolute\' => TRUE)));?>',
						'format' => 'ds_code',
						),
				'use_token' => 0,
				);
  $export['data_snapshot_permalink'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_field_settings_info().
 */
function data_snapshots_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_snapshot|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_snapshot';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
				     'data_snapshot_permalink' => array(
									'weight' => '4',
									'label' => 'above',
									'format' => 'default',
									),
				     'title' => array(
						      'weight' => '0',
						      'label' => 'hidden',
						      'format' => 'default',
						      ),
				     );
  $export['node|data_snapshot|full'] = $ds_fieldsetting;

  return $export;
}

  /**
   * Implements hook_ds_layout_settings_info().
   */
function data_snapshots_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_snapshot|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_snapshot';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
			       'regions' => array(
						  'left' => array(
								  0 => 'field_ds_disimg',
								  ),
						  'right' => array(
								   1 => 'title',
								   2 => 'field_ds_dsds_mn',
								   3 => 'field_ds_dloads',
								   4 => 'data_snapshot_permalink',
								   5 => 'field_ds_dtgen',
								   ),
						  'footer' => array(
								    6 => 'body',
								    7 => 'field_ds_relnds',
								    ),
						  ),
			       'fields' => array(
						 'field_ds_disimg' => 'left',
						 'title' => 'right',
						 'field_ds_dsds_mn' => 'right',
						 'field_ds_dloads' => 'right',
						 'data_snapshot_permalink' => 'right',
						 'field_ds_dtgen' => 'right',
						 'body' => 'footer',
						 'field_ds_relnds' => 'footer',
						 ),
			       'classes' => array(),
			       'wrappers' => array(
						   'header' => 'div',
						   'left' => 'div',
						   'right' => 'div',
						   'footer' => 'div',
						   ),
			       'layout_wrapper' => 'div',
			       'layout_attributes' => '',
			       'layout_attributes_merge' => 1,
			       );
  $export['node|data_snapshot|full'] = $ds_layout;

  return $export;
}