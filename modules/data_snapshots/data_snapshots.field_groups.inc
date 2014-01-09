<?php

/**
 * Implements hook_field_group_info().
 */
  //REMOVE all groups associcated with the data source
function data_snapshots_field_group_info() {

  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_climategov_metadata|node|data_snapshot|form';
  $field_group->group_name = 'group_climategov_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dss_tabs';
  $field_group->data = array(
    'label' => 'Climate.gov Metadata',
    'weight' => '3',
    'children' => array(
      0 => 'field_ds_tclean',
      1 => 'path',
      2 => 'redirect',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_climategov_metadata|node|data_snapshot|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_datasnapshot_edit_info|node|data_snapshot|form';
  $field_group->group_name = 'group_datasnapshot_edit_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dss_tabs';
  $field_group->data = array(
    'label' => 'Editable Information',
    'weight' => '1',
    'children' => array(
      0 => 'title',
      1 => 'body',
      2 => 'field_ds_relnds',
      3 => 'field_ds_dloads',
      4 => 'field_ds_disimg',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_datasnapshot_edit_info|node|data_snapshot|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_datasnapshot_image_meta|node|data_snapshot|form';
  $field_group->group_name = 'group_datasnapshot_image_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dss_tabs';
  $field_group->data = array(
    'label' => 'Image Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'field_ds_ptk',
      1 => 'field_ds_stk',
      2 => 'field_ds_dtgen',
      3 => 'field_ds_dtacc',
      4 => 'field_ds_dsds_mn',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_datasnapshot_image_meta|node|data_snapshot|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dss_tabs|node|data_snapshot|form';
  $field_group->group_name = 'group_dss_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data Snapshot Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_climategov_metadata',
      1 => 'group_datasnapshot_image_meta',
      2 => 'group_datasnapshot_edit_info',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dss_tabs|node|data_snapshot|form'] = $field_group;

  return $export;
}
