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
$evergreen_answer_length = 500;
$evergreen_answer_length_ellipsis = $evergreen_answer_length + 3;

$framing_question = strip_tags($element['#object']->{'datasource_node'}->{'field_dssds_framing_question'}['und'][0]['value']);
$framing_question_answer = strip_tags($element['#object']->{'datasource_node'}->{'field_dssds_framing_q_answer'}['und'][0]['safe_value']);
$secondary_question = strip_tags($element['#object']->{'datasource_node'}->{'field_dssds_secondary_questi'}['und'][0]['value']);
$secondary_question_answer = strip_tags($element['#object']->{'datasource_node'}->{'field_dssds_secondary_q_answ'}['und'][0]['safe_value']);

if (strlen($framing_question_answer) > $evergreen_answer_length_ellipsis) {
  $framing_question_answer = trim(substr($framing_question_answer, 0, $evergreen_answer_length)) . '...';
}

if (strlen($secondary_question_answer) > $evergreen_answer_length_ellipsis) {
  $secondary_question_answer = trim(substr($secondary_question_answer, 0, $evergreen_answer_length)) . '...';
}

?>
<div class="field-name-field-ds-dsds-evergreen <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="field-label field_dssds_framing_question"<?php print $title_attributes; ?>><?php print $framing_question; ?>&nbsp;</div>
  <div class="field-items"<?php print $content_attributes; ?>>
    <div class="field-item field_dssds_framing_q_answer"><p><?php print $framing_question_answer; ?></p></div>
  </div>
  <div class="field-label field_dssds_secondary_questi"<?php print $title_attributes; ?>><?php print $secondary_question; ?>&nbsp;</div>
  <div class="field-items"<?php print $content_attributes; ?>>
    <div class="field-item field_dssds_secondary_q_answ"><p><?php print $secondary_question_answer; ?></p></div>
    <span class="dss-question-read-more"><a href="/node/<?php print $element['#object']->{'datasource_node'}->nid; ?>">read more</a></span>
  </div>
</div>
