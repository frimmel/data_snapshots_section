<?php
/**
 * @file
 * data_snapshots.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function data_snapshots_field_default_fields() {
  $fields = array();

  // Exported field: 'node-data_snapshot_data_source-field_dssds_additional_info'.
  $fields['node-data_snapshot_data_source-field_dssds_additional_info'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_additional_info',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 8,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 10,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 14,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 8,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 25,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 14,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 25,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 14,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_additional_info',
      'label' => 'Additional information',
      'required' => 0,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 34,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_colors'.
  $fields['node-data_snapshot_data_source-field_dssds_colors'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_colors',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 7,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 11,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 22,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 11,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 23,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 11,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_colors',
      'label' => 'What do the colors mean?',
      'required' => 0,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 3,
        ),
        'type' => 'text_textarea',
        'weight' => 31,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_data_access_url'.
  $fields['node-data_snapshot_data_source-field_dssds_data_access_url'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_data_access_url',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 16,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 7,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 22,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 16,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 23,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 22,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 22,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 22,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_data_access_url',
      'label' => 'Access to Source Data',
      'required' => 1,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'rel_remove' => 'default',
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => 21,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_data_format'.
  $fields['node-data_snapshot_data_source-field_dssds_data_format'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_data_format',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 17,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 11,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 23,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 17,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 21,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 23,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 21,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 23,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_data_format',
      'label' => 'Data Format Description',
      'required' => 0,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 22,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_data_matter'.
  $fields['node-data_snapshot_data_source-field_dssds_data_matter'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_data_matter',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 8,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 12,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 12,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 19,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 12,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_data_matter',
      'label' => 'Why do these data matter?',
      'required' => 0,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 32,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_data_product'.
  $fields['node-data_snapshot_data_source-field_dssds_data_product'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_data_product',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Formal name for data product source.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 13,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 5,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 19,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 13,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 31,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 19,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 30,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 19,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_data_product',
      'label' => 'Source Data Product',
      'required' => 1,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'rel_remove' => 'default',
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => 2,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_data_provider'.
  $fields['node-data_snapshot_data_source-field_dssds_data_provider'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_data_provider',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Name of and URL to Data Provider\'s main site.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 21,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 6,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 27,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'link_default',
          'weight' => 21,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 18,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 27,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 27,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_data_provider',
      'label' => 'Data Provider',
      'required' => 1,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'rel_remove' => 'default',
        'title' => 'required',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => 20,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_description_auth'.
  $fields['node-data_snapshot_data_source-field_dssds_description_auth'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_description_auth',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 19,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 18,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 25,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 19,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 19,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 25,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 24,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 25,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_description_auth',
      'label' => 'Description Author',
      'required' => 1,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 24,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_feed_url'.
  $fields['node-data_snapshot_data_source-field_dssds_feed_url'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_feed_url',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => 150,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The URL of the master feed file for this data source (must be a complete URL of the feed.csv file, complete with "http://" prefix)',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 14,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 17,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 14,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 3,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 10,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_feed_url',
      'label' => 'Master Feed URL',
      'required' => 1,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 2,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_framing_q_answer'.
  $fields['node-data_snapshot_data_source-field_dssds_framing_q_answer'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_framing_q_answer',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 25,
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 4,
        ),
        'nf_category_listing' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 25,
        ),
        'search_result' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
            'trim_length' => 600,
          ),
          'type' => 'text_trimmed',
          'weight' => 2,
        ),
        'short_teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
            'trim_length' => 200,
          ),
          'type' => 'text_trimmed',
          'weight' => 3,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
            'trim_length' => 100,
          ),
          'type' => 'text_trimmed',
          'weight' => 3,
        ),
        'tiny_teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
            'trim_length' => 200,
          ),
          'type' => 'text_trimmed',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_framing_q_answer',
      'label' => 'Answer to Framing Question',
      'required' => 1,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 28,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_framing_question'.
  $fields['node-data_snapshot_data_source-field_dssds_framing_question'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_framing_question',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 24,
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'nf_category_listing' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
            'trim_length' => 200,
          ),
          'type' => 'text_trimmed',
          'weight' => 2,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 24,
        ),
        'search_result' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'short_teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'tiny_teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_framing_question',
      'label' => 'Framing Question',
      'required' => 1,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 2,
        ),
        'type' => 'text_textarea',
        'weight' => 27,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_image_frequency'.
  $fields['node-data_snapshot_data_source-field_dssds_image_frequency'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_image_frequency',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'data_snapshot_data_source_frequency',
            'parent' => 0,
            'depth' => '',
          ),
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 23,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 19,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 29,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 23,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 28,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 29,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 31,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 29,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_image_frequency',
      'label' => 'Image Frequency',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => 1,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_machine_name'.
  $fields['node-data_snapshot_data_source-field_dssds_machine_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_machine_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => 150,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'A unique string used to identify this data source internally',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 13,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 15,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 18,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 13,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 18,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 6,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 18,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_machine_name',
      'label' => 'Machine Name',
      'required' => 1,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 2,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_map_scope'.
  $fields['node-data_snapshot_data_source-field_dssds_map_scope'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_map_scope',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'data_source_scope',
            'parent' => 0,
            'depth' => '',
          ),
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 30,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 14,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_map_scope',
      'label' => 'Map scope',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => -3,
      ),
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_processing_steps'.
  $fields['node-data_snapshot_data_source-field_dssds_processing_steps'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_processing_steps',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 9,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 9,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 15,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 9,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 26,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 15,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 27,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 15,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_processing_steps',
      'label' => 'How did you produce these snapshots?',
      'required' => 1,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 9,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_references'.
  $fields['node-data_snapshot_data_source-field_dssds_references'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_references',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'References used in writing the description.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 22,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 12,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 28,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 22,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 27,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 28,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 18,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 28,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_references',
      'label' => 'References',
      'required' => 1,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 35,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_representative_image'.
  $fields['node-data_snapshot_data_source-field_dssds_representative_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_representative_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 32,
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 2,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_representative_image',
      'label' => 'Representative Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => -4,
      ),
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_reviewer'.
  $fields['node-data_snapshot_data_source-field_dssds_reviewer'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_reviewer',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'First and last name of subject matter expert reviewer.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 20,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 9,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 26,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 20,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 17,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 26,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 17,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 26,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_reviewer',
      'label' => 'Reviewer',
      'required' => 1,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 25,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_secondary_q_answ'.
  $fields['node-data_snapshot_data_source-field_dssds_secondary_q_answ'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_secondary_q_answ',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 28,
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 6,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 30,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 28,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 30,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 30,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 29,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 30,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_secondary_q_answ',
      'label' => 'Answer to Secondary Question',
      'required' => 1,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 30,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_secondary_questi'.
  $fields['node-data_snapshot_data_source-field_dssds_secondary_questi'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_secondary_questi',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 29,
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 5,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 31,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 29,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 7,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 31,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 8,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 31,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_secondary_questi',
      'label' => 'Secondary Question',
      'required' => 1,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 29,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_themes'.
  $fields['node-data_snapshot_data_source-field_dssds_themes'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_themes',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'data_snapshots_themes',
            'parent' => 0,
            'depth' => '',
          ),
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 14,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 21,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 14,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 6,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 21,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 21,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_themes',
      'label' => 'Theme(s)',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => 0,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_dssds_url_pattern'.
  $fields['node-data_snapshot_data_source-field_dssds_url_pattern'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dssds_url_pattern',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => 150,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The url pattern where the Data Sanpshot image is hosted. Use {dsmn} for the machine name, {ptk} for the primary key & {stk} for the secondary key.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 14,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 16,
        ),
        'nf_category_listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
        'nf_related_content_teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
          ),
          'type' => 'text_default',
          'weight' => 14,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 3,
        ),
        'short_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 10,
        ),
        'tiny_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dssds_url_pattern',
      'label' => 'URL pattern',
      'required' => 1,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => -1,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-data_snapshot_data_source-field_weight'.
  $fields['node-data_snapshot_data_source-field_weight'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_weight',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'data_snapshot_data_source',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Sets the display order of data sources in the theme dropdown. This value is used across all themes for the data source.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'empty_fields_emptyfieldtext_empty_text' => '',
            'empty_fields_handler' => '',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => 31,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 13,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_weight',
      'label' => 'Weight',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 3,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A unique string used to identify this data source internally');
  t('Access to Source Data');
  t('Additional information');
  t('Answer to Framing Question');
  t('Answer to Secondary Question');
  t('Data Format Description');
  t('Data Provider');
  t('Description Author');
  t('First and last name of subject matter expert reviewer.');
  t('Formal name for data product source.');
  t('Framing Question');
  t('How did you produce these snapshots?');
  t('Image Frequency');
  t('Machine Name');
  t('Map scope');
  t('Master Feed URL');
  t('Name of and URL to Data Provider\'s main site.');
  t('References');
  t('References used in writing the description.');
  t('Representative Image');
  t('Reviewer');
  t('Secondary Question');
  t('Sets the display order of data sources in the theme dropdown. This value is used across all themes for the data source.');
  t('Source Data Product');
  t('The URL of the master feed file for this data source (must be a complete URL of the feed.csv file, complete with "http://" prefix)');
  t('The url pattern where the Data Sanpshot image is hosted. Use {dsmn} for the machine name, {ptk} for the primary key & {stk} for the secondary key.');
  t('Theme(s)');
  t('URL pattern');
  t('Weight');
  t('What do the colors mean?');
  t('Why do these data matter?');

  return $fields;
}
