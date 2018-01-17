<?php
function symposium_registration_fields($id, $year, $title) {
  $field_bases = array();
  
  // Register
  $field_bases['field_symposium_register'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_symposium_register',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Registered' => 'I wish to register for the ' . $title,
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'legacy_values' => array(),
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
    'type_name' => $id . '_' . $year . '_registration',
  );
  
  // Invitation
  $field_bases['field_symposium_invitation'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_symposium_invitation',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Invitation Needed' => 'I need an official invitation from the Foreign Affairs Office.',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'legacy_values' => array(),
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
    'type_name' => $id . '_' . $year . '_registration',
  );
  
  // Guests
  $field_bases['field_symposium_guests'] = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_symposium_guests',
      'indexes' => array(
          'value' => array(
              0 => 'value',
          ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
          'allowed_values' => array(
              1 => 1,
              2 => 2,
              3 => 3,
              4 => 4,
              5 => 5,
              6 => 6,
              7 => 7,
              8 => 8,
              9 => 9,
              10 => 10,
          ),
          'allowed_values_function' => '',
          'allowed_values_php' => '',
          'legacy_values' => array(),
          'text_processing' => 0,
      ),
      'translatable' => 0,
      'type' => 'list_integer',
      'type_name' => $id . '_' . $year . '_registration',
  );
  
  return $field_bases;
}

function symposium_registration_instances($id, $year, $title) {
  $field_instances = array();
  
  // Register
  $field_instances['node-' . $id . '_' . $year . '_registration-field_symposium_register'] = array(
    'bundle' => $id . '_' . $year . '_registration',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_symposium_register',
    'label' => 'Registration Status',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );
  
  // Invitation
  $field_instances['node-' . $id . '_' . $year . '_registration-field_symposium_invitation'] = array(
    'bundle' => $id . '_' . $year . '_registration',
    'default_value' => array(
      0 => array(
        'value' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_symposium_invitation',
    'label' => 'Invitation',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_buttons',
      'weight' => 10,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );
  
  // Guests
  $field_instances['node-' . $id . '_' . $year . '_registration-field_symposium_guests'] = array(
      'bundle' => $id . '_' . $year . '_registration',
      'default_value' => array(
          0 => array(
              'value' => NULL,
          ),
      ),
      'deleted' => 0,
      'description' => '',
      'display' => array(
          'default' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 10,
          ),
          'full' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 10,
          ),
          'rss' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 10,
          ),
          'search_index' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 10,
          ),
          'search_result' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 10,
          ),
          'teaser' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 10,
          ),
          'token' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 10,
          ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_symposium_guests',
      'label' => 'I wish to bring guests. The number of guests is',
      'required' => 0,
      'settings' => array(
          'text_processing' => 0,
          'user_register_form' => FALSE,
      ),
      'weight' => 10,
      'widget' => array(
          'active' => 0,
          'module' => 'options',
          'settings' => array(
              'default_value_php' => NULL,
          ),
          'type' => 'options_select',
          'weight' => 10,
      ),
      'widget_type' => 'optionwidgets_select',
  );
  
  return $field_instances;
}