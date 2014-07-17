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
				<?php /* print $header; */ ?>
    <h2 style="display:inline-block; margin-bottom: .25em;">Data Snapshots</h2>
    <div id="dss-tabs-wrapper">
      <div id="dss-tabs-maps" class="dss-tab active">Maps</div><div id="dss-tabs-description" class="dss-tab">Description</div>
    </div>
  </<?php print $header_wrapper ?>>

  <<?php print $left_wrapper ?> class="group-left<?php print $left_classes; ?>">
    <?php print $left; ?>
  </<?php print $left_wrapper ?>>

  <<?php print $right_wrapper ?> class="group-right<?php print $right_classes; ?>">
    <div class="dss-selector-wrapper active">  
      <div class="dss-menu-wrapper">
        <div class="dss-spacer"></div>
        <div class="dss-accordion"></div>
      </div>
      <div class="dss-short-summary-wrapper">
        <div class="dss-short-summary-title">About This Snapshot:</div>
        <div class="dss-short-summary-text"></div>
      </div>
    </div>
    <div class="dss-text-wrapper">
      <?php print $right; ?>
    </div>
  </<?php print $right_wrapper ?>>

  <<?php print $footer_wrapper ?> class="group-footer<?php print $footer_classes; ?>">
    <?php print $footer; ?>
  </<?php print $footer_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
