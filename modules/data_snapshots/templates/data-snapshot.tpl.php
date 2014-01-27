<?php

/**
 * @file
 * Bartik's theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
  //dsm($view_mode);
  //dsm($node);
  //dsm($content['field_ds_year']);
  //dsm('tpl.php');
  //dsm($node);
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


<?php if ($view_mode == "full") { ?>

    <div class="dss-wrapper">
    
      <div class="dss-header dss-controls">
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
      </div>  

      <div class="dss-middle">  
        <div class="dss-left-side">
          <img id="dss-disimg" src="<?php print $node->{'field_ds_disimg'}['und'][0]['url']; ?>">
        </div> <!-- end dss-left-side -->
        <div class="dss-right-side">
          <div class="dss-title"><?php printf("%s / %s",
                                              $node->{'field_ds_ptk'}['und'][0]['value'],
                                              $node->{'field_ds_stk'}['und'][0]['value']);  ?></div>
          <div class="dss-evergreen-question">
            <?php print $node->{'dataset_node'}->{'field_dssds_framing_question'}['und'][0]['value']; ?>
          </div>
          <div class="dss-evergreen-answer">
            <?php print $node->{'dataset_node'}->{'field_dssds_english_descript'}['und'][0]['value']; ?>
            <span class="dss-question-read-more"><a href="/node/<?php print $node->{'dataset_node'}->nid; ?>">read more...<a></span>
          </div>  
          <div class="dss-download-social-container">
            <div class="dss-downloads">
	      <?php print render($content['field_ds_dloads']) ?>
            </div>
            <div class="dss-social">
              <img src="<?php printf('/%s/', drupal_get_path('module', 'data_snapshots')); ?>/socialbuttons.png">
            </div>
          </div>
          <div class="dss-metadata">
	    <?php print render($content['field_ds_dtgen']) ?>
          </div>  
        </div> <!-- end dss-right-side -->
      </div> <!-- end dss-middle -->

      <div class="dss-footer">
        <div class="dss-about-this-date">About This Date</div>
        <div class="field-item even" property="content:encoded"> 
        <p><?php if ($node->{'body'} && $node->{'body'}['und']) { print $node->{'body'}['und'][0]['value']; } ?></p>
        </div>
      </div>  

    </div> <!-- end dss-wrapper -->
<?php } else { ?>
    <div class="dss-title"><a href="<?php global $base_url; printf('%s/node/%1d', $base_url, $node->{'nid'}); ?>"><?php print $title; ?></a></div>
<?php } ?>
</div>
