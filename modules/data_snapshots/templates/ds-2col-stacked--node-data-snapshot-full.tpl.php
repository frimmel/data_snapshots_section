<?php

/**
 * @file
 * Display Suite 2 column stacked template.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-2col-stacked <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $header_wrapper ?> class="group-header<?php print $header_classes; ?>">
    <div class="dss-interactive-widget">
      <div class="dss-interactive-select-lists">
        <div class="dss-interactive-component">
          <span class="dss-interactive-theme-label">Theme:&nbsp;</span>
          <select id="dss-theme-dropdown"></select>
        </div>
        <div class="dss-interactive-component">
          <span class="dss-interactive-source-label">Data Source:&nbsp;</span>
          <select id="dss-data-source-dropdown"></select>
        </div>
      </div>
      <div class="dss-interactive-sliders">
        <div class="dss-interactive-component">
          <span class="dss-interactive-ptk-label dss-interactive-label"></span>
	  <div class="dss-interactive-slider-wrapper">
	    <span id="dss-interactive-slider-ptk-start-label" class="dss-interactive-slider-label dss-interactive-slider-start-label"></span>
            <div id="dss-interactive-slider-ptk-slider" class="dss-interactive-slider"></div>
	    <span id="dss-interactive-slider-ptk-end-label" class="dss-interactive-slider-label dss-interactive-slider-end-label"></span>
	    <span id="dss-interactive-slider-ptk-popup" class="dss-interactive-slider-popup"></span>
          </div>
        </div>
        <div class="dss-interactive-component">
          <span class="dss-interactive-stk-label dss-interactive-label"></span>
	  <div class="dss-interactive-slider-wrapper">
	    <span id="dss-interactive-slider-stk-start-label" class="dss-interactive-slider-label dss-interactive-slider-start-label"></span>
            <div id="dss-interactive-slider-stk-slider" class="dss-interactive-slider"></div>
	    <span id="dss-interactive-slider-stk-end-label" class="dss-interactive-slider-label dss-interactive-slider-end-label"></span>
	    <span id="dss-interactive-slider-stk-popup" class="dss-interactive-slider-popup"></span>
          </div>
        </div>
      </div>
    </div>
  </<?php print $header_wrapper ?>>

  <<?php print $left_wrapper ?> class="group-left<?php print $left_classes; ?>">
    <?php print $left; ?>
  </<?php print $left_wrapper ?>>

  <<?php print $right_wrapper ?> class="group-right<?php print $right_classes; ?>">
    <?php print $right; ?>
  </<?php print $right_wrapper ?>>

  <<?php print $footer_wrapper ?> class="group-footer<?php print $footer_classes; ?>">
    <?php print $footer; ?>
  </<?php print $footer_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
