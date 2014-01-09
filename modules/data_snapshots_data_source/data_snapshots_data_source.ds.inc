<?php
/**
 * @file
 * data_snapshots_data_source.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function data_snapshots_data_source_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_snapshot_data_source|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_snapshot_data_source';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|data_snapshot_data_source|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function data_snapshots_data_source_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_snapshot_data_source|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_snapshot_data_source';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_dssds_framing_question',
        3 => 'field_dssds_english_descript',
        5 => 'field_dssds_secondary_questi',
        6 => 'field_dssds_plain_english_an',
        7 => 'field_dssds_colors',
        9 => 'field_dssds_data_matters',
        11 => 'field_dssds_editorial_commen',
        14 => 'field_dssds_processing_steps',
        15 => 'field_dssds_processing_envir',
        16 => 'field_dssds_technical_commen',
        17 => 'field_dssds_data_format',
        18 => 'field_dssds_references',
      ),
      'right' => array(
        2 => 'field_dssds_official_name',
        4 => 'field_dssds_data_provider',
        8 => 'field_dssds_data_access_url',
        10 => 'field_dssds_catalog_url',
        12 => 'field_dssds_reviewer',
        13 => 'field_dssds_reviewer_affilia',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_dssds_framing_question' => 'left',
      'field_dssds_official_name' => 'right',
      'field_dssds_english_descript' => 'left',
      'field_dssds_data_provider' => 'right',
      'field_dssds_secondary_questi' => 'left',
      'field_dssds_plain_english_an' => 'left',
      'field_dssds_colors' => 'left',
      'field_dssds_data_access_url' => 'right',
      'field_dssds_data_matters' => 'left',
      'field_dssds_catalog_url' => 'right',
      'field_dssds_editorial_commen' => 'left',
      'field_dssds_reviewer' => 'right',
      'field_dssds_reviewer_affilia' => 'right',
      'field_dssds_processing_steps' => 'left',
      'field_dssds_processing_envir' => 'left',
      'field_dssds_technical_commen' => 'left',
      'field_dssds_data_format' => 'left',
      'field_dssds_references' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'article-body' => 'article-body',
      ),
      'right' => array(
        'article-info' => 'article-info',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|data_snapshot_data_source|full'] = $ds_layout;

  return $export;
}
