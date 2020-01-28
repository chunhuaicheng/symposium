<?php
function symposium_create_registration_content ($id) {
  
  module_load_include('inc', 'symposium', 'includes/registration.fields');
  
  $settings = symposium_get_settings();
  $setting = $settings[$id];
  $title = $setting->title;
  $years = $setting->years;
  $roles = $setting->roles;
  
  // create registration node type if it does not already exists
  foreach ($years AS $year) {
    $type = node_type_load($id . '_' . $year . '_registration');
    if (!$type) {
      $type = array(
        'type' => $id . '_' . $year . '_registration',
        'name' => t($title . ' ' . $year . ' Registration'),
        'base' => 'node_content',
        'description' => t('A form for the ' . $title . ' ' . $year . ' registration'),
        'has_title' => '0'
      );
      $type = node_type_set_defaults($type);
      $fields = symposium_registration_fields($id, $year, $title);
      $field = array();
      foreach ($fields AS $field) {
        $fname = $field['field_name'];
        if (!field_info_field($fname)) {
          $field = field_create_field($field);
        }
      }
      $instances = symposium_registration_instances($id, $year, $title);
      $instance = array();
      foreach ($instances AS $instance) {
        $entity_type = $instance['entity_type'];
        $fname = $instance['field_name'];
        $bundle = $instance['bundle'];
        if (!field_info_instance($entity_type, $fname, $bundle)) {
          field_create_instance($instance);
        }
      }
      // Save
      node_type_save($type);
      
      // set variables for the content type default (published, with preview, no comment)
      $moderate = variable_get('symposium_moderate_registration', 0);
      if ($moderate) {
        variable_set('node_options_' . $id . '_' . $year . '_registration', array('moderate'));
      }
      else {
        variable_set('node_options_' . $id . '_' . $year . '_registration', array());
      }
      variable_set('node_preview_' . $id . '_' . $year . '_registration', '0');
      variable_set('comment_' . $id . '_' . $year . '_registration', '0');
    }
    
    // make sure the member roles can register
    symposium_grant_permissions($id . '_'. $year . '_registration', $roles);
  } 
}