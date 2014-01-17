This is the combined project for the data snapshots section.

The end goal of this project is to be able to enable one module and have the section ready.

For development purposes you will need to go into the modules/data_snapshots directory and run the redo script.

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

1. Make Data Snapshots Page feature complete
  - Write remaining data source switchers 
  - Add URL aliases to Data Source
  - Determine Theme from URL
  - Implement Downloads section
  - Load Metadata fields
2. Import remaining dependencies
  - Annotation admin view
  - Context settings
  - Switch display of Data Snapshots to display suite
  - Add image to Data Source
  - Social media buttons
  - Breadcrumbs
3. Generally clean up code
  - Rename anything refering to 'Data Set' to 'Data Source'
  - Update primary tab links on interaction
  - Rewrite queries to be more efficient
  - Cut out deprecated/development code
  - Properly bundle css & js
  - Minify Javascript
4. Implementation
  - Test on live mirror
  - Ensure datasets with odd date combinations work
  - Fix remaining bugs
