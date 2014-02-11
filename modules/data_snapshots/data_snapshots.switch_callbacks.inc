<?php

  /*
callback functions to switch between different datasets
  */

function getDataSourceDates($datasource) {
  $rows = db_select('data_snapshots', 'ds')
    ->fields('ds', array('nid','ptk','stk'))
    ->condition('dsmn', $datasource)
    ->orderBy('ds.ptk', 'ASC')
    ->orderBy('ds.stk', 'ASC')
    ->execute()
    ->fetchAll();
  $snapshots = array();
  if (!empty($rows)) {
    $ptk = null;
    $ptks = array();
    foreach ($rows as $row) {
      if ($row->{'ptk'} != $ptk) {
	$snapshots[$row->{'ptk'}] = array();
	$ptk = $row->{'ptk'};
	$ptks[] = $ptk;
      }
      $snapshots[$ptk][] = $row->{'stk'};
    }
  }

  return array(
	       'p' => $ptks,
	       's' => $snapshots
	       );
}

function getNewPrimaryKey($ptk, $dates) {
  if (array_key_exists($ptk, $dates['s'])) {
    $new_ptk = $ptk;
  } else {
    if ($ptk < $dates['p'][0]) {
      $new_ptk = $dates['p'][0];
    } else {
      $new_ptk = $dates['p'][count($dates['p']) - 1];
    }
  }

  return $new_ptk;
}

function AnnualToAnnual($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  
  $new_ptk = getNewPrimaryKey($ptk, $dates);
  return array(
	       'ptk' => $new_ptk,
	       'stk' => NULL,
	       'dates' => $dates,
  );
}

function AnnualToMonthly($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  
  $new_ptk = getNewPrimaryKey($ptk, $dates);
  $new_stk = $dates['s'][$new_ptk][count($dates['s'][$new_ptk]) - 1];

  return array(
	       'ptk' => $new_ptk,
	       'stk' => $new_stk,
	       'dates' => $dates,
  );
}

function AnnualToWeekly($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  
  $new_ptk = getNewPrimaryKey($ptk, $dates);
  $new_stk = $dates['s'][$new_ptk][count($dates['s'][$new_ptk]) - 1];

  return array(
	       'ptk' => $new_ptk,
	       'stk' => $new_stk,
	       'dates' => $dates,
  );
}

function MonthlyToAnnual($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  
  $new_ptk = getNewPrimaryKey($ptk, $dates);
  return array(
	       'ptk' => $new_ptk,
	       'stk' => NULL,
	       'dates' => $dates,
  );
}

function MonthlyToMonthly($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  

  $new_ptk = getNewPrimaryKey($ptk, $dates);

  $potential_stks = $dates['s'][$new_ptk];

  if ($stk <= $potential_stks[0]) {
    $new_stk = $potential_stks[0];
  }

  for ($i = 1; $i < count($potential_stks); $i++) {
    if ($stk == $potential_stks[$i]) {
      $new_stk = $potential_stks[$i];
      break;
    } elseif ($stk < $potential_stks[$i]) {
      $new_stk = $potential_stks[$i];
      break;
    }
  }

  if (!isset($new_stk)) {
    $new_stk = $potential_stks[count($potential_stks) - 1];
  }

  return array(
	       'ptk' => $new_ptk,
	       'stk' => $new_stk,
	       'dates' => $dates,
  );
}

function MonthlyToWeekly($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  

  $new_ptk = getNewPrimaryKey($ptk, $dates);

  $potential_stks = $dates['s'][$new_ptk];

  for ($i = 0; $i < count($potential_stks); $i++) {
    if ($stk < $potential_stks[$i]) {
      $new_stk = $potential_stks[$i];
      break;
    }
  }

  if (!isset($new_stk)) {
    $new_stk = $potential_stks[count($potential_stks) - 1];
  }

  return array(
	       'ptk' => $new_ptk,
	       'stk' => $new_stk,
	       'dates' => $dates,
  );
}

function WeeklyToAnnual($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  
  $new_ptk = getNewPrimaryKey($ptk, $dates);
  return array(
	       'ptk' => $new_ptk,
	       'stk' => NULL,
	       'dates' => $dates,
  );
}

function WeeklyToMonthly($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  

  $new_ptk = getNewPrimaryKey($ptk, $dates);

  $potential_stks = $dates['s'][$new_ptk];

  if ($stk < $potential_stks[0]) {
    $new_stk = $potential_stks[0];
  } else {
    for ($i = 1; $i < count($potential_stks); $i++) {
      if ($stk < $potential_stks[$i]) {
	$new_stk = $potential_stks[$i - 1];
	break;
      }
    }
  }

  if (!isset($new_stk)) {
    $new_stk = $potential_stks[count($potential_stks) - 1];
  }

  return array(
	       'ptk' => $new_ptk,
	       'stk' => $new_stk,
	       'dates' => $dates,
  );
}

function WeeklyToWeekly($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  

  $new_ptk = getNewPrimaryKey($ptk, $dates);

  $potential_stks = $dates['s'][$new_ptk];

  if ($stk <= $potential_stks[0]) {
    $new_stk = $potential_stks[0];
  } else {
    for ($i = 1; $i < count($potential_stks); $i++) {
      if ($stk == $potential_stks[$i]) {
	$new_stk = $potential_stks[$i];
	break;
      } elseif ($stk < $potential_stks[$i]) {
	$new_stk = $potential_stks[$i - 1];
	break;
      }
    }
  }

  if (!isset($new_stk)) {
    $new_stk = $potential_stks[count($potential_stks) - 1];
  }

  return array(
	       'ptk' => $new_ptk,
	       'stk' => $new_stk,
	       'dates' => $dates,
  );
}

function DefaultConversion($dest, $ptk, $stk) {
  $dates = getDataSourceDates($dest);  

  $new_ptk = $dates['p'][count($dates['p']) - 1];
  $new_stk = $dates['s'][$new_ptk][count($dates['s'][$new_ptk]) - 1];

  return array(
	       'ptk' => $new_ptk,
	       'stk' => $new_stk,
	       'dates' => $dates,
  );
}
