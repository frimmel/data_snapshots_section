<?php

function delete_nodes($node_type) {
  // Select the nodes that we want to delete.
  $result = db_select('node', 'n')
            ->fields('n', array('nid'))
            ->condition('type', $node_type, '=')
            ->execute();

  $deleted_count = 0;
  foreach ($result as $record) {
    node_delete($record->nid);
    $deleted_count++;
  }
  return $deleted_count;
}

function empty_table($table_name) {
  db_query("delete from $table_name");
}

$count = delete_nodes('data_snapshot');
drush_print("Deleted $count Data Snapshot nodes");

empty_table('data_snapshots_import_urls');
empty_table('data_snapshots_imports');
empty_table('data_snapshots');
