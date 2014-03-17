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
				     'add_this' => array(
                                                         'weight' => '4',
                                                         'label' => 'above',
                                                         'format' => 'default',
                                                         ),
				     'data_snapshot_permalink' => array(
                                                                        'weight' => '5',
									'label' => 'above',
									'format' => 'default',
									),
				     'title' => array(
						      'weight' => '1',
						      'label' => 'hidden',
						      'format' => 'default',
						      ),
				     );
  $export['node|data_snapshot|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_snapshot|nf_category_listing';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_snapshot';
  $ds_fieldsetting->view_mode = 'nf_category_listing';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|data_snapshot|nf_category_listing'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_snapshot|nf_related_content_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_snapshot';
  $ds_fieldsetting->view_mode = 'nf_related_content_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'post_date' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|data_snapshot|nf_related_content_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_snapshot|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_snapshot';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|data_snapshot|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_snapshot|short_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_snapshot';
  $ds_fieldsetting->view_mode = 'short_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|data_snapshot|short_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_snapshot|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_snapshot';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|data_snapshot|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_snapshot|tiny_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_snapshot';
  $ds_fieldsetting->view_mode = 'tiny_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|data_snapshot|tiny_teaser'] = $ds_fieldsetting;

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
								   4 => 'add_this',
								   5 => 'data_snapshot_permalink',
								   6 => 'field_ds_dtgen',
								   ),
						  'footer' => array(
								    7 => 'body',
								    ),
						  ),
			       'fields' => array(
						 'field_ds_disimg' => 'left',
						 'title' => 'right',
						 'field_ds_dsds_mn' => 'right',
						 'field_ds_dloads' => 'right',
						 'add_this' => 'right',
						 'data_snapshot_permalink' => 'right',
						 'field_ds_dtgen' => 'right',
						 'body' => 'footer',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_snapshot|nf_category_listing';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_snapshot';
  $ds_layout->view_mode = 'nf_category_listing';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_ds_disimg',
      ),
      'right' => array(
        1 => 'title',
        2 => 'post_date',
        3 => 'body',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_ds_disimg' => 'left',
      'title' => 'right',
      'post_date' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|data_snapshot|nf_category_listing'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_snapshot|nf_related_content_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_snapshot';
  $ds_layout->view_mode = 'nf_related_content_teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_ds_disimg',
      ),
      'right' => array(
        1 => 'title',
        2 => 'post_date',
      ),
    ),
    'fields' => array(
      'field_ds_disimg' => 'left',
      'title' => 'right',
      'post_date' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|data_snapshot|nf_related_content_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_snapshot|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_snapshot';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|data_snapshot|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_snapshot|short_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_snapshot';
  $ds_layout->view_mode = 'short_teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_ds_disimg',
      ),
      'right' => array(
        1 => 'title',
        2 => 'post_date',
        3 => 'body',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_ds_disimg' => 'left',
      'title' => 'right',
      'post_date' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|data_snapshot|short_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_snapshot|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_snapshot';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_ds_disimg',
      ),
      'right' => array(
        1 => 'title',
        2 => 'post_date',
        3 => 'body',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_ds_disimg' => 'left',
      'title' => 'right',
      'post_date' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|data_snapshot|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_snapshot|tiny_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_snapshot';
  $ds_layout->view_mode = 'tiny_teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_ds_disimg',
      ),
      'right' => array(
        1 => 'title',
        2 => 'post_date',
        3 => 'body',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_ds_disimg' => 'left',
      'title' => 'right',
      'post_date' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|data_snapshot|tiny_teaser'] = $ds_layout;

  return $export;
}