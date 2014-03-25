<?php
/**
 * @file
 * data_snapshots.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function data_snapshots_taxonomy_default_vocabularies() {
  return array(
    'data_snapshot_data_source_frequency' => array(
      'name' => 'Data Snapshot Data Source Frequency',
      'machine_name' => 'data_snapshot_data_source_frequency',
      'description' => 'Image frequency for a Data Snapshot Data source.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'data_snapshots_themes' => array(
      'name' => 'Data Snapshots Themes',
      'machine_name' => 'data_snapshots_themes',
      'description' => 'The available Themes for Data Snapshots',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
