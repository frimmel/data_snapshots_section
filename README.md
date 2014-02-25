This is the combined project for the data snapshots section.

The end goal of this project is to be able to enable one module and have the section ready.

For development purposes you will need to go into the modules/data_snapshots directory and run the redo script.

---

**PRODUCTION DEPENDENCIES**
- Breadcrumbs can't easily be put into code so they must be added by hand.
- Feeds can't import multi-value fields very well, so in the eventual csv feeds the downloads fields must each be single columns with commas separating the values. For example:
```csv
...,download_title,download_url,...
...,"title 1,title 2,title 3,...,title n","url 1,url 2,url 3,...,url n",...
```
- There are multiple field template files, these will work but Drupal is faster if theme functions are created in the theme's template.php file instead with the pattern:
```php
/**
 * Overrides theme_field
 *
 * Customizes display of the field 'FIELDNAME' for the content type 'Data Snapshot'
 */
function THEMENAME_field__FIELD_MACHINE_NAME__data_snapshot($variables) {
  /* CONTENTS OF TEMPLATE FILE TWEAKED FOR THEME_FIELD */
}
```

---

**DEVELOPMENT DEPENDENCIES**
- The left and right regions for the Data Source content type require custom classes which exist in the final site, but are not included in the module. These classes are enabled by default when the module is enabled due to the way which they were bundled up in features, but will be taken out of the rendered html if any changes to the display of the Data Source content type are saved.

To enable changes to the display of Data Source nodes follow these steps:

1. Enable the `Display Suite UI` module.
2. Click on the `Custom classes` tab at the bottom of the `Manage Display` page for the Data Source content type.
3. Click on the link `Manage region and field CSS classes`.
4. Add these classes to the `CSS classes for regions` textarea on seperate lines.
```
article-body
article-info
```
5. Back on the `Custom classes` tab, ensure the `Class for left` is `article-body` and the `Class for right` is `article-info`.

---

**TODO**

1. Generally clean up code
  - Rewrite queries to be more efficient
  - Cut out deprecated/development code
  - Properly bundle css & js
2. Implementation
  - Write instructions for adding data snapshots to Maps & Data submenu
  - Annotation view exposed filters
  - Test in climate.gov
  - Social media buttons
  - Add example image to Data Source
  - Ensure datasets with odd date combinations work
  - Minify Javascript
  - Fix remaining bugs
