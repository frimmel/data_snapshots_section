<?php
  /**
   * @file
   * data_snapshots.views_default.inc
   */

  /**
   * Implements hook_views_default_views().
   */
function data_snapshots_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'data_snapshot_annotation_admin_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Data Snapshot Annotation Admin View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Snapshot Annotation Admin View';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
							       2 => '2',
							       );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Annotation';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Data Set Machine Name */
  $handler->display->display_options['fields']['field_ds_dsds_mn']['id'] = 'field_ds_dsds_mn';
  $handler->display->display_options['fields']['field_ds_dsds_mn']['table'] = 'field_data_field_ds_dsds_mn';
  $handler->display->display_options['fields']['field_ds_dsds_mn']['field'] = 'field_ds_dsds_mn';
  $handler->display->display_options['fields']['field_ds_dsds_mn']['label'] = 'Machine Name';
  $handler->display->display_options['fields']['field_ds_dsds_mn']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'data_snapshot' => 'data_snapshot',
									 );
  /* Filter criterion: Content: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['body_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['body_value']['expose']['operator_id'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['label'] = 'Body (body)';
  $handler->display->display_options['filters']['body_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['body_value']['expose']['operator'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['identifier'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['expose']['remember_roles'] = array(
												  2 => '2',
												  1 => 0,
												  3 => 0,
												  );
  $handler->display->display_options['filters']['body_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['body_value']['group_info']['label'] = 'Annotation';
  $handler->display->display_options['filters']['body_value']['group_info']['identifier'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['body_value']['group_info']['group_items'] = array(
												   1 => array(
													      'title' => 'No Annotation',
													      'operator' => 'empty',
													      'value' => '1',
													      ),
												   2 => array(
													      'title' => 'Has Annotation',
													      'operator' => 'not empty',
													      'value' => '2',
													      ),
												   );
  /* Filter criterion: Content: Data Set Machine Name (field_ds_dsds_mn) */
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['id'] = 'field_ds_dsds_mn_value';
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['table'] = 'field_data_field_ds_dsds_mn';
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['field'] = 'field_ds_dsds_mn_value';
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['expose']['operator_id'] = 'field_ds_dsds_mn_value_op';
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['expose']['label'] = 'Operational Name';
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['expose']['operator'] = 'field_ds_dsds_mn_value_op';
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['expose']['identifier'] = 'field_ds_dsds_mn_value';
  $handler->display->display_options['filters']['field_ds_dsds_mn_value']['expose']['remember_roles'] = array(
													      2 => '2',
													      1 => 0,
													      3 => 0,
													      );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'data-snapshot/annotation-admin-view';
  $export['data_snapshot_annotation_admin_view'] = $view;

  return $export;
}