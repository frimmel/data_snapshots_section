<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>
<div class="dss-downloads-wrapper">
  <div class="dss-downloads-popup">
    <div class="dss-downloads-label">Select a Format:</div>
    <div class="dss-downloads-options">
      <?php foreach ($items as $delta => $item): ?>
        <div>
          <label for="dss-form-element-<?php print $delta; ?>"><?php print $item['#element']['title']; ?></label>
        </div>
      <?php endforeach; ?>
    </div>
    <form method="get" action="" target="_blank" id="exampleform">
      <div class="dss-downloads-radio">
        <?php foreach ($items as $delta => $item): ?>
          <input type="radio" value="<?php print $item['#element']['url']; ?>" id="dss-form-element-<?php print $delta; ?>" class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?> name="dss-download"></input>
        <?php endforeach; ?>
      </div>
      <div class="dss-downloads-license">These public-domain images are freely available for re-use.</div>
      <div class="dss-downloads-buttons">
        <button class="dss-downloads-cancel-button">Cancel</button>
        <button class="dss-downloads-ok-button" type="submit">OK</button>
      </div>
    </form>
  </div>
  <button class="dss-downloads-toggle">Download</button>
</div>
