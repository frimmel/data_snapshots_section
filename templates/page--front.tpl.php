<?php
   /**
    * @file
    * Default theme implementation to display a single Drupal page.
    *
    * Available variables:
    *
    * General utility variables:
    * - $base_path: The base URL path of the Drupal installation. At the very
    *   least, this will always default to /.
    * - $directory: The directory the template is located in, e.g. modules/system
    *   or themes/bartik.
    * - $is_front: TRUE if the current page is the front page.
    * - $logged_in: TRUE if the user is registered and signed in.
    * - $is_admin: TRUE if the user has permission to access administration pages.
    *
    * Site identity:
    * - $front_page: The URL of the front page. Use this instead of $base_path,
    *   when linking to the front page. This includes the language domain or
    *   prefix.
    * - $logo: The path to the logo image, as defined in theme configuration.
    * - $site_name: The name of the site, empty when display has been disabled
    *   in theme settings.
    * - $site_slogan: The slogan of the site, empty when display has been disabled
    *   in theme settings.
    *
    * Navigation:
    * - $main_menu (array): An array containing the Main menu links for the
    *   site, if they have been configured.
    * - $secondary_menu (array): An array containing the Secondary menu links for
    *   the site, if they have been configured.
    * - $breadcrumb: The breadcrumb trail for the current page.
    *
    * Page content (in order of occurrence in the default page.tpl.php):
    * - $title_prefix (array): An array containing additional output populated by
    *   modules, intended to be displayed in front of the main title tag that
    *   appears in the template.
    * - $title: The page title, for use in the actual HTML content.
    * - $title_suffix (array): An array containing additional output populated by
    *   modules, intended to be displayed after the main title tag that appears in
    *   the template.
    * - $messages: HTML for status and error messages. Should be displayed
    *   prominently.
    * - $tabs (array): Tabs linking to any sub-pages beneath the current page
    *   (e.g., the view and edit tabs when displaying a node).
    * - $action_links (array): Actions local to the page, such as 'Add menu' on the
    *   menu administration interface.
    * - $feed_icons: A string of all feed icons for the current page.
    * - $node: The node object, if there is an automatically-loaded node
    *   associated with the page, and the node ID is the second argument
    *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
    *   comment/reply/12345).
    *
    * Regions:
    * - $page['help']: Dynamic help text, mostly for admin pages.
    * - $page['highlighted']: Items for the highlighted content region.
    * - $page['content']: The main content of the current page.
    * - $page['sidebar_first']: Items for the first sidebar.
    * - $page['sidebar_second']: Items for the second sidebar.
    * - $page['header']: Items for the header region.
    * - $page['footer']: Items for the footer region.
    *
    * @see template_preprocess()
    * @see template_preprocess_page()
    * @see template_process()
    */

    $query = new EntityFieldQuery();

    $entities = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'data_snapshot')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_ds_dsds_mn', 'value', 'averagetemp-monthly-cmb', '=')
      ->fieldOrderBy('field_ds_ptk', 'value', 'DESC')
      ->fieldOrderBy('field_ds_stk', 'value', 'DESC')
      ->range(0, 1)
      ->execute();

    if (!empty($entities['node'])) {
      $node = node_load(current(array_keys($entities['node'])));
    }
    
   ?>
<?php $theme_path = drupal_get_path('theme', variable_get('theme_default', NULL)); ?>
<div id="skip-link">
   <a href="#main-content" class="element-invisible element-focusable">Skip to main content</a>
</div>
<div class="page clearfix node-type-data-snapshot" id="page">
   <?php include($directory . "/inc/header.inc.php");?>
   <!-- CONTENT MARGIN WRAP -->
   <div class="content-margin_wrap">
      <section id="section-content" class="section section-content">
         <div id="zone-content-wrapper" class="zone-wrapper zone-content-wrapper clearfix">
            <div id="zone-content" class="zone zone-content clearfix container-12">
               <!-- SIDEBAR AREA -->                  
               <div class="col-2-left">
                  <div class="leftNavLink">
                     <a id="sidebar-links"></a>
                     <?php print render($page['sidebar_first']); ?>
                  </div>
               </div>
               <!-- END SIDEBAR AREA -->
               <a id="main-content"></a>						
               <!-- REGION (MAIN) CONTENT -->
               <div class="grid-9 region region-content" id="region-content">
                  <div class="region-inner region-content-inner">
                     <a id="main-content"></a>
                     <?php print $messages; ?>
                     <?php
                        $node_type = 'page';
                        if(isset($node)) {
                        	$node_type = substr($node->type,0);
                        }
                        ?>
                     <?php // Special front page with message and filter blocks still appearing  ?>
                     <?php if (request_uri() == $front_page): ?>
                     	<?php print render($page['front_message']); ?>
                     <?php else: ?>
                     	<?php if ($breadcrumb && $node_type=='page'): print $breadcrumb; endif; ?>
                     	<?php print render($title_prefix); ?>
                     	<?php if ($title): ?>
                     	<h1 class="title search-results-header" id="page-title"><?php print $title; ?> <?php print $feed_icons; ?></h1>
                     	<?php endif; ?>
                     	<?php print render($title_suffix); ?>
                 	 <?php endif; // end else clause of special front page handling ?>
                     <?php if ($tabs): ?>
                     <div class="tabs"><?php print render($tabs); ?></div>
                     <?php endif; ?>
                     <?php print render($page['help']); ?>
                     <?php if ($action_links): ?>
                     <ul class="action-links"><?php print render($action_links); ?></ul>
                     <?php endif; ?>
		     <div id="block-system-main" class="block block-system">
                        <?php print drupal_render(node_view($node)); ?>
                     </div>
                  </div>
               </div>
               <!-- END REGION (MAIN) CONTENT -->
            </div>
         </div>
         <!-- ZONE-POSTSCRIPT-WRAPPER -->
         <div id="zone-postscript-wrapper" class="zone-wrapper zone-postscript-wrapper clearfix">
            <div id="zone-postscript" class="zone zone-postscript clearfix container-12">
               <!-- FOOTER BRANDING -->
               <div class="grid-3 region region-postscript-fourth" id="region-postscript-fourth">
                  <div class="region-inner region-postscript-fourth-inner">
                     <div class="block block-block block-7 block-block-7 odd block-without-title" id="block-block-7">
                        <div class="block-inner clearfix">
                           <div class="content clearfix">
                              <p id="footer-logo"><a href="/"><img alt="climate.gov" src="<?php print $base_path . $theme_path; ?>/images/footer-logo.jpg" title="climate.gov" /></a></p>
                           </div>
                        </div>
                     </div>
                  </div>
               </div>
               <!-- END FOOTER BRANDING -->
            </div>
         </div>
         <!-- END ZONE-POSTSCRIPT-WRAPPER -->
      </section>
   </div>
   <!-- END CONTENT MARGIN WRAP -->
   <?php include($directory . "/inc/footer.inc.php");?>
</div>
<!-- end PAGE clear fix -->