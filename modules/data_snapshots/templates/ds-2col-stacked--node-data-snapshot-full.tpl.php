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
    <table>
      <tr>
        <td>
          Theme:&nbsp;
          <select id="dss-theme-dropdown">
          </select>
  	      <br/>
          Data Source:&nbsp;
          <select id="dss-data-source-dropdown">
          </select>
        </td>
        <td>
          <table>
            <tr><td align="right">Year:</td><td><div id="dss-yearslider"></div></td></tr>
            <tr id="dss-timeslider-row"><td align="right">Week:</td><td><div id="dss-timeslider"></div></td></tr>
          </table>
        </td>
      </tr>
    </table>
    <?php /*print $header; */?>
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
