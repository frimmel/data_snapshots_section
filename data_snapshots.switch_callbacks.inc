<?php

  /*
callback functions to switch between different data sources
  */

function _data_snapshots_get_ptk($ptk, $dates) {
  if (in_array($ptk, $dates['p'])) {
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

function _data_snapshots_generate_switch_results($ptk, $stk, $dates) {
  return array(
	       'ptk' => $ptk,
	       'stk' => $stk,
	       'dates' => $dates,
	       );
}

function _data_snapshots_Annual_to_Annual($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);

  return _data_snapshots_generate_switch_results($new_ptk, NULL, $dates);
}

function _data_snapshots_Annual_to_Monthly($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);
  $new_stk = $dates['s'][$new_ptk][count($dates['s'][$new_ptk]) - 1];

  return _data_snapshots_generate_switch_results($new_ptk, $new_stk, $dates);
}

function _data_snapshots_Annual_to_Weekly($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);
  $new_stk = $dates['s'][$new_ptk][count($dates['s'][$new_ptk]) - 1];

  return _data_snapshots_generate_switch_results($new_ptk, $new_stk, $dates);
}

function _data_snapshots_Monthly_to_Annual($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);

  return _data_snapshots_generate_switch_results($new_ptk, NULL, $dates);
}

function _data_snapshots_Monthly_to_Monthly($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);
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

  return _data_snapshots_generate_switch_results($new_ptk, $new_stk, $dates);
}

function _data_snapshots_Monthly_to_Weekly($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);
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

  return _data_snapshots_generate_switch_results($new_ptk, $new_stk, $dates);
}

function _data_snapshots_Weekly_to_Annual($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);

  return _data_snapshots_generate_switch_results($new_ptk, NULL, $dates);
}

function _data_snapshots_Weekly_to_Monthly($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);
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

  return _data_snapshots_generate_switch_results($new_ptk, $new_stk, $dates);
}

function _data_snapshots_Weekly_to_Weekly($dest, $ptk, $stk, $dates) {
  $new_ptk = _data_snapshots_get_ptk($ptk, $dates);
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

  return _data_snapshots_generate_switch_results($new_ptk, $new_stk, $dates);
}

function _data_snapshots_default_conversion($dest, $ptk, $stk, $dates) {
  $new_ptk = $dates['p'][count($dates['p']) - 1];
  $new_stk = $dates['s'][$new_ptk][count($dates['s'][$new_ptk]) - 1];

  return _data_snapshots_generate_switch_results($new_ptk, $new_stk, $dates);
}
