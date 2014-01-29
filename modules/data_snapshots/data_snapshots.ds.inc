<?php
  /**
   * @file
   * data_snapshots.ds.inc
   */

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
								   1 => 'field_ds_dsds_mn',
								   2 => 'field_ds_dloads',
								   3 => 'field_ds_dtgen',
								   ),
						  'footer' => array(
								    4 => 'body',
								    5 => 'field_ds_relnds',
								    ),
						  ),
			       'fields' => array(
						 'field_ds_disimg' => 'left',
						 'field_ds_dsds_mn' => 'right',
						 'field_ds_dloads' => 'right',
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