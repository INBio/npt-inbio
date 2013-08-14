<?php
/**
 * @file
 * plinian_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function plinian_core_field_group_info() {
  $export = array();

  // #~ field groups for default  
  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_main|node|pliniancore|default';
  $field_group->group_name = 'group_plic_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Principal',
    'weight' => '0',
    'children' => array(
      0 => 'title',
      1 => 'field_taxonomic_name',
      2 => 'field_plic_abstract',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 0,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_main|node|pliniancore|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_demography|node|pliniancore|default';
  $field_group->group_name = 'group_plic_demography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Demography and conservation',
    'weight' => '4',
    'children' => array(
      0 => 'field_plic_legislation',
      1 => 'field_plic_population_biology',
      2 => 'field_plic_territory',
      3 => 'field_plic_threat_status',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_demography|node|pliniancore|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_description|node|pliniancore|default';
  $field_group->group_name = 'group_plic_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '5',
    'children' => array(
      0 => 'field_plic_brief_description',
      1 => 'field_plic_full_description',
      2 => 'field_plic_keys',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_description|node|pliniancore|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_documentation|node|pliniancore|default';
  $field_group->group_name = 'group_plic_documentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documentation',
    'weight' => '7',
    'children' => array(
      0 => 'field_references',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_documentation|node|pliniancore|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_habitat_distribution|node|pliniancore|default';
  $field_group->group_name = 'group_plic_habitat_distribution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Habitat and distribution',
    'weight' => '2',
    'children' => array(
      0 => 'field_plic_distribution',
      1 => 'field_plic_endemism',
      2 => 'field_plic_habitat',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_habitat_distribution|node|pliniancore|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_meta|node|pliniancore|default';
  $field_group->group_name = 'group_plic_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '9',
    'children' => array(
      0 => 'field_plic_guid',
      1 => 'field_plic_language',
      2 => 'field_plic_publication_date',
      3 => 'field_plic_version',
      4 => 'field_plic_author',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_meta|node|pliniancore|default'] = $field_group;


  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_misc|node|pliniancore|default';
  $field_group->group_name = 'group_plic_misc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Misc',
    'weight' => '8',
    'children' => array(
      0 => 'field_plic_detail',
      1 => 'field_plic_life_form',
      2 => 'field_plic_direct_threats',
      3 => 'field_plic_dispersal',
      4 => 'field_plic_environmental',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_misc|node|pliniancore|default'] = $field_group;


  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_natural_history|node|pliniancore|default';
  $field_group->group_name = 'group_plic_natural_history';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Natural History',
    'weight' => '1',
    'children' => array(
      0 => 'field_plic_anual_cycle',
      1 => 'field_plic_behavior',
      2 => 'field_plic_ecological',
      3 => 'field_plic_feeding',
      4 => 'field_plic_interactions',
      5 => 'field_plic_life_cycle',
      6 => 'field_plic_migratory',
      7 => 'field_plic_molecular_data',
      8 => 'field_plic_reproduction',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_natural_history|node|pliniancore|default'] = $field_group;


  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_taxonomy|node|pliniancore|default';
  $field_group->group_name = 'group_plic_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomic information',
    'weight' => '6',
    'children' => array(
      0 => 'field_plic_synonims',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_taxonomy|node|pliniancore|default'] = $field_group;


  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_uses_management|node|pliniancore|default';
  $field_group->group_name = 'group_plic_uses_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Uses and management',
    'weight' => '3',
    'children' => array(
      0 => 'field_plic_folklore',
      1 => 'field_plic_management',
      2 => 'field_plic_uses',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_uses_management|node|pliniancore|default'] = $field_group;


  // #~ field groups for form
  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a form field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_main|node|pliniancore|form';
  $field_group->group_name = 'group_plic_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Principal',
    'weight' => '0',
    'children' => array(
      0 => 'title',
      1 => 'field_taxonomic_name',
      2 => 'field_plic_abstract',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_main|node|pliniancore|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_demography|node|pliniancore|form';
  $field_group->group_name = 'group_plic_demography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Demography and conservation',
    'weight' => '4',
    'children' => array(
      0 => 'field_plic_legislation',
      1 => 'field_plic_population_biology',
      2 => 'field_plic_territory',
      3 => 'field_plic_threat_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_demography|node|pliniancore|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_description|node|pliniancore|form';
  $field_group->group_name = 'group_plic_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '5',
    'children' => array(
      0 => 'field_plic_brief_description',
      1 => 'field_plic_full_description',
      2 => 'field_plic_keys',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_description|node|pliniancore|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_documentation|node|pliniancore|form';
  $field_group->group_name = 'group_plic_documentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documentation',
    'weight' => '7',
    'children' => array(
      0 => 'field_references',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_documentation|node|pliniancore|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_habitat_distribution|node|pliniancore|form';
  $field_group->group_name = 'group_plic_habitat_distribution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Habitat and distribution',
    'weight' => '2',
    'children' => array(
      0 => 'field_plic_distribution',
      1 => 'field_plic_endemism',
      2 => 'field_plic_habitat',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_habitat_distribution|node|pliniancore|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_meta|node|pliniancore|form';
  $field_group->group_name = 'group_plic_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '9',
    'children' => array(
      0 => 'field_plic_guid',
      1 => 'field_plic_language',
      2 => 'field_plic_publication_date',
      3 => 'field_plic_version',
      4 => 'field_plic_author',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_meta|node|pliniancore|form'] = $field_group;


  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_misc|node|pliniancore|form';
  $field_group->group_name = 'group_plic_misc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Misc',
    'weight' => '8',
    'children' => array(
      0 => 'field_plic_detail',
      1 => 'field_plic_life_form',
      2 => 'field_plic_direct_threats',
      3 => 'field_plic_dispersal',
      4 => 'field_plic_environmental',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_misc|node|pliniancore|form'] = $field_group;


  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_natural_history|node|pliniancore|form';
  $field_group->group_name = 'group_plic_natural_history';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Natural History',
    'weight' => '1',
    'children' => array(
      0 => 'field_plic_anual_cycle',
      1 => 'field_plic_behavior',
      2 => 'field_plic_ecological',
      3 => 'field_plic_feeding',
      4 => 'field_plic_interactions',
      5 => 'field_plic_life_cycle',
      6 => 'field_plic_migratory',
      7 => 'field_plic_molecular_data',
      8 => 'field_plic_reproduction',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_natural_history|node|pliniancore|form'] = $field_group;


  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_taxonomy|node|pliniancore|form';
  $field_group->group_name = 'group_plic_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomic information',
    'weight' => '6',
    'children' => array(
      0 => 'field_plic_synonims',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_taxonomy|node|pliniancore|form'] = $field_group;


  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_uses_management|node|pliniancore|form';
  $field_group->group_name = 'group_plic_uses_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Uses and management',
    'weight' => '3',
    'children' => array(
      0 => 'field_plic_uses',
      1 => 'field_plic_management',
      2 => 'field_plic_folklore',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_plic_uses_management|node|pliniancore|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plic_tabs|node|pliniancore|form';
  $field_group->identifier = 'group_plic_tabs|node|pliniancore|form';
  $field_group->group_name = 'group_plic_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pliniancore';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Field group',
    'weight' => '-1',
    'children' => array(
      0 => 'group_plic_main',
      1 => 'group_plic_demography',
      2 => 'group_plic_description',
      3 => 'group_plic_habitat_distribution',
      4 => 'group_plic_meta',
      5 => 'group_plic_misc',
      6 => 'group_plic_natural_history',
      7 => 'group_plic_taxonomy',
      8 => 'group_plic_documentation',
      9 => 'group_plic_uses_management',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_plic_tabs|node|pliniancore|form'] = $field_group;

  return $export;
}
