<?php
// Check ICGI membership for conference registration
function  symposium_registration_check ($id, $year) {
  global $user;
  $roles = $user->roles;
  
  $settings = symposium_get_settings();
  $setting = $settings[$id];
  $title = $setting->title;
  $years = $setting->years;
  $closed = $setting->closed;
  
  /* Close the old registration if the year not found in settings */
  if (in_array($year, $closed)) {
    if (!in_array($setting->late_role, $roles)) {
      return symposium_message_registration_closed();
    }
  }
  
  // If user is not logged in
  if (!isset($user->name)) {
    return symposium_message_create_account($title);
    
    // User is logged in
  } else {
    
    // If user is a member in allowed roles
    $allowed = false;
    foreach ($roles AS $user_role) {
      if (in_array($user_role, $setting->roles)) {
        $allowed = true;
      }
    }
    if($allowed) {
      // If the user has already registered
      $sql = "SELECT nid FROM {node} WHERE type = '" . $id . "_" . $year . "_registration' AND uid = :uid";
      $nid = db_query($sql, array(':uid' => $user->uid))->fetchField();
      if ($nid) {
        return symposium_message_already_registered ($id, $year, $nid, $title);
        
        // If the user has not registered, redirect to the registration form
      } else {
        drupal_goto("node/add/icgi-" . $year . "-registration");
      }
      
      // If the user doesn't have a 'icgi member' role, prompt to join icgi group
    } else {
      return symposium_message_membership_required ($id);
    }
  }
}

// Check ICGI membership for abstract submission
function  symposium_abstract_submission_check ($id, $year) {
  global $user;
  $roles = $user->roles;
  
  /* Close the old Abstract submission */
  $settings = symposium_get_settings();
  $setting = $settings[$id];
  $title = $setting->title;
  $years = $setting->years;
  $closed = $setting->closed;
  if (in_array($year, $closed)) {
    if (!in_array($setting->late_role, $roles)) {
      return symposium_message_abstract_submission_closed();
    }
  }
  
  // If user is not logged in
  if (!isset($user->name)) {
    return symposium_message_create_account($title);
    
    // User is logged in
  } else {
    $sql = "SELECT nid FROM {node} WHERE type = '" . $id . "_" . $year . "_registration' AND uid = :uid";
    $nid = db_query($sql, array(':uid' => $user->uid))->fetchField();
    
    // If the user has already registered
    if ($nid) {
      drupal_goto("node/add/" . $id ."-" . $year . "-abstract");
      
      // If the user not yet registered
    } else {
      return symposium_message_not_yet_registered ($id, $year, $title);
    }
  }
}
