<?php

function symposium_create_abstract_content ($id) {
  
  module_load_include('inc', 'symposium', 'includes/abstract.fields');
  
  $settings = symposium_get_settings();
  $setting = $settings[$id];
  $title = $setting->title;
  $years = $setting->years;
  $roles = $setting->roles;
  
  // create abstract node type if it does not already exists
  foreach ($years AS $year) {
    $type = node_type_load($id . '_'. $year . '_abstract');
    if (!$type) {
      $type = array(
        'type' => $id . '_' . $year . '_abstract',
        'name' => t($title . ' ' . $year . ' Abstract'),
        'base' => 'node_content',
        'description' => t('Abstract for the ' . $title . ' ' . $year),
        'has_title' => '1',
        'title_label' => t('Title'),
      );
      $type = node_type_set_defaults($type);
      $fields = symposium_abstract_fields($id, $year, $title);
      $field = array();
      foreach ($fields AS $field) {
        $fname = $field['field_name'];
        if (!field_info_field($fname)) {
          $field = field_create_field($field);
        }
      }
      $instances = symposium_abstract_instances($id, $year, $title);
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
      variable_set('node_options_' . $id . '_' . $year . '_abstract', array('moderate'));
      variable_set('node_preview_' . $id . '_' . $year . '_abstract', '1');
      variable_set('comment_' . $id . '_' . $year . '_abstract', '0');
    }
    
    // make sure the member roles can submit abstracts
    symposium_grant_permissions($id . '_'. $year . '_abstract', $roles);
    
  }
}