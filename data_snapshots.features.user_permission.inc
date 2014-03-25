<?php
/**
 * @file
 * data_snapshots.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function data_snapshots_user_default_permissions() {
  $permissions = array();

  // Exported permission: create data_snapshot_data_source content.
  $permissions['create data_snapshot_data_source content'] = array(
    'name' => 'create data_snapshot_data_source content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any data_snapshot_data_source content.
  $permissions['delete any data_snapshot_data_source content'] = array(
    'name' => 'delete any data_snapshot_data_source content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own data_snapshot_data_source content.
  $permissions['delete own data_snapshot_data_source content'] = array(
    'name' => 'delete own data_snapshot_data_source content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any data_snapshot_data_source content.
  $permissions['edit any data_snapshot_data_source content'] = array(
    'name' => 'edit any data_snapshot_data_source content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own data_snapshot_data_source content.
  $permissions['edit own data_snapshot_data_source content'] = array(
    'name' => 'edit own data_snapshot_data_source content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
