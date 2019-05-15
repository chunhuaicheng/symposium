<?php
function symposium_abstract_fields($id, $year, $title) {
  $field_bases = array();
  $settings = symposium_get_settings();
  
  // Working_group'.
  $field_bases['taxonomy_symposium_working_group'] = array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'taxonomy_symposium_working_group',
      'indexes' => array(
          'tid' => array(
              0 => 'tid',
          ),
      ),
      'locked' => 0,
      'module' => 'taxonomy',
      'settings' => array(
          'allowed_values' => array(
              0 => array(
                  'vocabulary' => 'symposium_working_group',
                  'parent' => 0,
              ),
          ),
          'required' => TRUE,
      ),
      'translatable' => 0,
      'type' => 'taxonomy_term_reference',
  );
  
  // Presentation type
  $field_bases['field_symposium_presentation'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_symposium_presentation',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        '15 minute Oral' => '15 minute Oral',
        '5 minute Oral and Poster' => '5 minute Oral and Poster',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'legacy_values' => array(),
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
    'type_name' => $id . '_' . $year . '_abstract',
  );
  
  // Payment
  $field_bases['field_symposium_payment'] = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_symposium_payment',
      'indexes' => array(
          'value' => array(
              0 => 'value',
          ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
          'allowed_values' => array(
              'Paid' => 'The payment has been made.',
              'Unpaid' => 'I\'ve not submitted the payment. As a reminder, please go to <a href="https://'. $settings[$id]->payment_url .'" target="_blank">' . $settings[$id]->payment_site . '</a> to pay and complete the registration.',              
          ),
          'allowed_values_function' => '',
          'allowed_values_php' => '',
          'legacy_values' => array(),
          'text_processing' => 0,
      ),
      'translatable' => 0,
      'type' => 'list_text',
      'type_name' => $id . '_' . $year . '_abstract',
  );

  // Authors
  $field_bases['field_symposium_authors'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_symposium_authors',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '255',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => $id . '_' . $year . '_authors',
  );
  
  // Emails
  $field_bases['field_symposium_emails'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_symposium_emails',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '255',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => $id . '_' . $year . '_emails',
  );
  
  // Affliation
  $field_bases['field_symposium_affiliation'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_symposium_affiliation',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '510',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => $id . '_' . $year . '_affiliation',
  );
  
  // Abstract
  $field_bases['field_symposium_abstract'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_symposium_abstract',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => $id . '_' . $year . '_abstract',
  );
  
  return $field_bases;
}

function symposium_abstract_instances($id, $year, $title) {
  $field_instances = array();
  
  // Working group
  $field_instances['node-' . $id . '_' . $year . '_abstract-taxonomy_symposium_working_group'] = array(
      'bundle' => $id . '_' . $year . '_abstract',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'Please select the type of abstract submitted.',
      'display' => array(
          'default' => array(
              'label' => 'hidden',
              'module' => 'taxonomy',
              'settings' => array(),
              'type' => 'taxonomy_term_reference_link',
              'weight' => 0,
          ),
          'teaser' => array(
              'label' => 'hidden',
              'module' => 'taxonomy',
              'settings' => array(),
              'type' => 'taxonomy_term_reference_link',
              'weight' => 0,
          ),
      ),
      'entity_type' => 'node',
      'field_name' => 'taxonomy_symposium_working_group',
      'label' => 'Working group session',
      'required' => 1,
      'settings' => array(
          'user_register_form' => FALSE,
      ),
      'widget' => array(
          'module' => 'options',
          'settings' => array(),
          'type' => 'options_select',
          'weight' => 0,
      ),
  );
  
  // Presentation type
  $field_instances['node-' . $id . '_' . $year . '_abstract-field_symposium_presentation'] = array(
    'bundle' => $id . '_' . $year . '_abstract',
    'default_value' => array(
      0 => array(
        'value' => '',
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
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'rss' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'token' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_symposium_presentation',
    'label' => 'Presentation type',
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
  
  // Payment
  $field_instances['node-' . $id . '_' . $year . '_abstract-field_symposium_payment'] = array(
      'bundle' => $id . '_' . $year . '_abstract',
      'default_value' => array(
          0 => array(
              'value' => '',
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
              'weight' => 5,
          ),
          'full' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 5,
          ),
          'rss' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 5,
          ),
          'search_index' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 5,
          ),
          'search_result' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 5,
          ),
          'teaser' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 5,
          ),
          'token' => array(
              'label' => 'inline',
              'module' => 'text',
              'settings' => array(),
              'type' => 'text_default',
              'weight' => 5,
          ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_symposium_payment',
      'label' => 'Registration Fee',
      'required' => 5,
      'settings' => array(
          'text_processing' => 0,
          'user_register_form' => FALSE,
      ),
      'weight' => 5,
      'widget' => array(
          'active' => 0,
          'module' => 'options',
          'settings' => array(
              'default_value_php' => NULL,
          ),
          'type' => 'options_buttons',
          'weight' => 5,
      ),
      'widget_type' => 'optionwidgets_buttons',
  );

  // Authors
  $field_instances['node-' . $id . '_' . $year . '_abstract-field_symposium_authors'] = array(
    'bundle' => $id . '_' . $year . '_abstract',
    'default_value' => array(
      0 => array(
        'value' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'List all authors in the \'Last name, First name\' format (e.g Eikenberry, Tomas). Drag the cross icon or change the row weights to re-order.',
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
    'field_name' => 'field_symposium_authors',
    'label' => 'Authors',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
    'widget_type' => 'text_textfield',
  );
  
  // Emails
  $field_instances['node-' . $id . '_' . $year . '_abstract-field_symposium_emails'] = array(
    'bundle' => $id . '_' . $year . '_abstract',
    'default_value' => array(
      0 => array(
        'value' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'List authors\' email in the same order as the authors listed above. Drag the cross icon or change the row weights to re-order.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'rss' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'search_index' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'token' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_symposium_emails',
    'label' => 'Author Email',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 20,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 20,
    ),
    'widget_type' => 'text_textfield',
  );
  
  // Affliation
  $field_instances['node-' . $id . '_' . $year . '_abstract-field_symposium_affiliation'] = array(
    'bundle' => $id . '_' . $year . '_abstract',
    'default_value' => array(
      0 => array(
        'value' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'List authors\' affliation in the same order as the authors listed above. Drag the cross icon or change the row weights to re-order.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'rss' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'search_index' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'token' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_symposium_affiliation',
    'label' => 'Author Affliation',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 20,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 20,
    ),
    'widget_type' => 'text_textfield',
  );
  
  // Abstract
  $field_instances['node-' . $id . '_' . $year . '_abstract-field_symposium_abstract'] = array(
    'bundle' => $id . '_' . $year . '_abstract',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_symposium_abstract][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Please limit your abstract length to 500 words',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 80,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 80,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 80,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 80,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 80,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 80,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 80,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_symposium_abstract',
    'label' => 'Abstract',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 80,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 20,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 80,
    ),
    'widget_type' => 'text_textarea',
  );
  
  return $field_instances;
}
