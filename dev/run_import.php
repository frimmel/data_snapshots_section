<?php

### Running this script with "drush scr run_import.php" does the same thing
### as clicking the "Run Import Now" button in the Data Snapshots Module
### admin settings screen; i.e. it causes the Data Snapshots module to run
### an import batch.  This involves just calling the
### function data_snapshots_run_import(); everything else in this file
### just has to do with printing out status information about what
### got imported.
###
### First, some terminology:
### 
### `data_snapshot` nodes are imported in batches.  Each batch corresponds
### to one or more CSV files on the image server that contain data that
### gets loaded into `data_snapshot` nodes.  When
### data_snapshots_run_import() runs, it checks to see if there are any new
### CSV files on the server, and if there are, it does an import batch to
### import their contents.
###
### Each run of this script results in a single import batch, unless
### there are no new CSV files present on the server, in which case
### there is nothing new to import and nothing is done.
### 
### The `data_snapshots_imports` table records the batches; it contains
### one row for each import batch, giving a unique id called `dsi_id`
### (which stands for "data snapshots import id") for the batch, and a
### timestamp telling when the batch was run.
### 
### The `data_snapshots_import_urls` table records the URLs of the CSV
### files that have been imported, along with the `dsi_id` of the batch
### that imported each one.
### 

###
### This function return the total number of data snapshots currently
### in the database:
###
function get_snapshot_count() {
    # This should return the same number as
    #     select count(*) from node where type='data_snapshot'
    # but we use the following query instead, because the data_snapshots
    # table is smaller and faster to query.  Note that all the info in
    # the data_snapshots table is also available in the `node` table
    # and the various field tables associated with nodes of type
    # `data_snapshot`; the `data_snapshots` table exists simply to have
    # a fast way to query basic information about data_snapshot nodes.
    $rows = db_query("select count(*) as count from data_snapshots")
      ->fetchAll();
    $count = 0;
    if (!empty($rows)) {
      $count = $rows[0]->{'count'};
    }
    return $count;
}

###
### This function returns the dsi_id of the most recent import batch:
###
function get_most_recent_dsi_id() {
    $rows = db_select('data_snapshots_imports', 'dsi')
      ->fields('dsi', array('dsi_id'))
      ->orderBy('dsi.dsi_id', 'DSC')
      ->range(0,1)
      ->execute()
      ->fetchAll();
    $last_dsi_id = '';
    if (!empty($rows)) {
      $last_dsi_id = $rows[0]->{'dsi_id'};
    }
    return $last_dsi_id;
}

### 
### This function return an array of all the CSV files (urls)
### that were imported in a given import batch:
###
function get_import_urls($dsi_id) {
    $rows = db_select('data_snapshots_import_urls', 'dsiu')
      ->fields('dsiu', array('url'))
      ->condition('dsi_id', $dsi_id)
      ->execute()
      ->fetchAll();
    $urls = [];
    foreach ($rows as $row) {
        $urls[] = $row->{'url'};
    }
    return $urls;
}

###
### get the dsi_id of the last import batch
###
$previous_dsi_id = get_most_recent_dsi_id();
$previous_snapshot_count = get_snapshot_count();

###
### run the import function
###
data_snapshots_run_import();

###
### Now get the dsi_id of the most recent import batch, to see if the
### call just done above resulted in a new batch.  (If
### data_snapshots_run_import() does not find any new CSV files, it does
### not import anything and doesn't do a new batch.)
###
$dsi_id = get_most_recent_dsi_id();

###
### report what happened:
###
if ($dsi_id == $previous_dsi_id) {
  print "No new snapshots found to import.\n";
} else {
  $urls = get_import_urls($dsi_id);
  $snapshot_count = get_snapshot_count();
  printf("%1d data_snapshot nodes imported from the following %1d CSV files:\n",
         $snapshot_count - $previous_snapshot_count,
         count($urls));
  foreach ($urls as $url) {
    printf("    %s\n", $url);
  }
}
