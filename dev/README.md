Installing Data Snapshots in a Drupal Site for the First Time
=============================================================

1. Make sure the following taxonomy vocabularies exist and are
   populated with the following terms:
   
   * *Section* (the exact term names for this vocab do not matter -- just make sure the vocab exists and
     has terms defined for the sections of the site; they should be somewhat like the following)
     * _Climate Conditions_
     * _Maps and Data_
     * _Decision Support_
     * _News and Features_
     * _Teaching Climate_

   * *Data Snapshot Data Source Frequency* (machine name: _data_snapshot_data_source_frequency_; the terms should be **exactly**
     the following):
     * _Daily_
     * _Weekly_
     * _Bimonthly_
     * _Monthly_
     * _Annual_
     * _Custom_
     
   * *Data Snapshots Themes* (machine name: _data_snapshots_themes_; the terms should be **exactly**
     the following):
     * _Drought_
     * _Outlooks_
     * _Temperature_
     * _Precipitation_
     * _Severe Weather_
     * _Snow_
     
   * *Data Source Scope* (machine name: _data_source_scope_; the terms should be **exactly**
     the following):
     * _CONUS_
     * _Global_

2. Edit the _CONFIGURATION SECTION_ at the top of the script `dev/retidify-datasets-json`
   to adjust the settings there to be appropriate for your environment.  See the comments
   at the top of that file for details.  (There are just 3 variables whose values may need
   to be changed.)
   
3. From the *data_snapshots* directory, run the command:

   ```
   drush scr dev/retidify-datasets-json
   ```
   
4. From the *data_snapshots* directory, run the command:

   ```
   drush ne-import < dev/datasets-retids.json
   ```
   
5. From the *data_snapshots* directory, run the command:

   ```
   drush scr dev/run_import.php
   ```
