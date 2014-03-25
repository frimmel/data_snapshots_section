<?php

/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
$query = db_select('field_data_field_dssds_operational_data_pro', 'ona');
$query->join('field_data_field_dssds_machine_name', 'mna', '(ona.entity_id = mna.entity_id)');
$query->fields('ona', array('field_dssds_operational_data_pro_value'))
  ->fields('mna', array('field_dssds_machine_name_value'))
  ->distinct()
  ->orderBy('field_dssds_operational_data_pro_value', 'DESC');
$rows = $query->execute()
  ->fetchAll();

if (array_key_exists('field_ds_dsds_mn_value', $_REQUEST)) {
  $value = $_REQUEST['field_ds_dsds_mn_value'];
} else {
  $value = NULL;
}

$new_form = '<div class="form-item form-type-textfield form-item-field-ds-dsds-mn-value">';
$new_form .= '<select id="edit-field-ds-dsds-mn-value" name="field_ds_dsds_mn_value" class="form-select">';
$new_form .= '<option value="All">- Any -</option>';
foreach ($rows as $row) {
  $new_form .= '<option value="' . $row->field_dssds_machine_name_value . '"';
  if ($row->field_dssds_machine_name_value == $value) {
    $new_form .= ' selected="selected"';
  }
  $new_form .= '>' . $row->field_dssds_operational_data_pro_value . '</option>';
}
$new_form .= '</select>';
$new_form .= '</div>';

$target_id = 'edit-field-ds-dsds-mn-value';
foreach ($widgets as $id => $widget):
  if ($widget->id == $target_id) {
    $widget->widget = $new_form;
    break;
  }
endforeach;
?>
<?php if (!empty($q)): ?>
  <?php
    // This ensures that, if clean URLs are off, the 'q' is added first so that
    // it shows up first in the URL.
    print $q;
  ?>
<?php endif; ?>
<div class="views-exposed-form">
  <div class="views-exposed-widgets clearfix">
    <?php foreach ($widgets as $id => $widget): ?>
      <div id="<?php print $widget->id; ?>-wrapper" class="views-exposed-widget views-widget-<?php print $id; ?>">
        <?php if (!empty($widget->label)): ?>
          <label for="<?php print $widget->id; ?>">
            <?php print $widget->label; ?>
          </label>
        <?php endif; ?>
        <?php if (!empty($widget->operator)): ?>
          <div class="views-operator">
            <?php print $widget->operator; ?>
          </div>
        <?php endif; ?>
        <div class="views-widget">
          <?php print $widget->widget; ?>
        </div>
        <?php if (!empty($widget->description)): ?>
          <div class="description">
            <?php print $widget->description; ?>
          </div>
        <?php endif; ?>
      </div>
    <?php endforeach; ?>
    <?php if (!empty($sort_by)): ?>
      <div class="views-exposed-widget views-widget-sort-by">
        <?php print $sort_by; ?>
      </div>
      <div class="views-exposed-widget views-widget-sort-order">
        <?php print $sort_order; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($items_per_page)): ?>
      <div class="views-exposed-widget views-widget-per-page">
        <?php print $items_per_page; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($offset)): ?>
      <div class="views-exposed-widget views-widget-offset">
        <?php print $offset; ?>
      </div>
    <?php endif; ?>
    <div class="views-exposed-widget views-submit-button">
      <?php print $button; ?>
    </div>
    <?php if (!empty($reset_button)): ?>
      <div class="views-exposed-widget views-reset-button">
        <?php print $reset_button; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
