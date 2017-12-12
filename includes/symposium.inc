<?php
/*
 * Validation for 'symposium', 'registration', and 'abstracts'
 */
function symposium_node_validate($node, $form) {
  $type = $node->type;
  /*
   * Content Type: symposium
   */
  if ($type == 'symposium') {
    // make sure the short_name/id is unique
    $nid = $node->nid;
    $id = $node->field_short_name['und'][0]['value'];
    //make sure the id id unique
    $query = NULL;
    if ($nid) { // Node Update
      $query =
      db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'symposium')
      ->condition('nid', $nid, '<>')
      ->execute();
    } else { // Node Insert
      $query =
      db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'symposium')
      ->execute();
    }
    $nids = array();
    while ($symposium = $query->fetchObject()) {
      array_push($nids, $symposium->nid);
    }
    $nodes = entity_load('node', $nids);
    $used_ids = array();
    foreach ($nodes AS $node) {
      array_push($used_ids, $node->field_short_name['und'][0]['value']);
    }
    if (in_array($id, $used_ids)) {
      form_set_error('field_short_name', 'The short name is already used by another symposium.');
    }
    
  /*
   * Content Type: registration
   */
  } else if (preg_match('/.+?_.+?_registration$/', $type)) {
	$registration = preg_match('/(.+?)_(.+?)_registration$/', $type, $matches);
    $id = $matches[1];
    $year = $matches[2];
	$settings = symposium_get_settings();
	if (isset($settings[$id]) && in_array($year, $settings[$id]->years)) {

	}
  
    
  /*
   * Content Type: abstract
   */
  } else if (preg_match('/.+?_.+?_abstract$/', $type)) {
    $abstract = preg_match('/(.+?)_(.+?)_abstract$/', $type, $matches);
    $id = $matches[1];
    $year = $matches[2];
    // make sure the abstract submission is not closed
    $settings = symposium_get_settings();
	if (isset($settings[$id]) && in_array($year, $settings[$id]->years)) {
      // make sure authors are listed as Last name, First name
      $authors_field = $node->field_authors['und'];
	  $num_authors = 0;
	  $num_emails = 0;
	  $num_affiliations = 0;
      foreach ($authors_field AS $author) {
        if (isset($author['value']) && trim($author['value']) != '') {
		  $num_authors ++;
		  if (!preg_match('/.+?\,.+/', $author['value'])) {
            form_set_error('field_authors', 'Please separate author\'s last name and first name with a comma. i.e. (Last name, First name)');
		  }
        }
      }
      // make sure emails are in valid format
      $emails_field = $node->field_emails['und'];
      foreach ($emails_field AS $email) {
        if (isset($email['value']) && trim($email['value']) != '') {
          $num_emails ++;
		  if (!preg_match('/.+?@.+?\..+/', $email['value'])) {
		    form_set_error('field_emails', 'Please provide valid email(s)');
		  }		  
        }
      }
	  $affiliation_field = $node->field_affiliation['und'];
      foreach ($affiliation_field AS $affiliation) {
		  if (isset($affiliation['value']) && trim($affiliation['value']) != '') {
		    $num_affiliations++;
		  }
	  }
	  // make sure emails are filled for all authors
	  if ($num_authors != $num_emails) {
		  form_set_error('field_emails', 'Please provide email for all authors');
	  }
	  // make sure affiliations are filled for all authors
	  if ($num_authors != $num_affiliations) {
		  form_set_error('field_affiliation', 'Please provide affiliation for all authors');
	  }
	}
  }
}

/*
 * Alter forms for 'symposium', 'registration', and 'abstracts'
 */
function symposium_form_node_form_alter(&$form,&$form_state,$form_id) {
  $type = $form['type']['#value'];
  /*
   * Content Type: symposium
   */
  if ($type == 'symposium') {
    //unset($form['revision_information']);  // disable revision 
    // unset($form['comment_settings']);     // disable comment settings
    // $form_state['node']->comment = '0'; // disable comment
    
  /*
   * Content Type: registration
   */ 
  } else if (preg_match('/.+?_.+?_registration$/', $type)) {
    // check if the user has registered. if yes, redirect to update registration
    global $user;
    $roles = $user->roles;
    $registration = preg_match('/(.+?)_(.+?)_registration$/', $type, $matches);
    $id = $matches[1];
    $year = $matches[2];
    // make sure registration is not closed
    $settings = symposium_get_settings();
	if (isset($settings[$id]) && in_array($year, $settings[$id]->years)) {
      $setting = $settings[$id];
      $closed = $setting->closed;
      if (in_array($year, $closed)) {
        if (!in_array($setting->late_role, $roles)) {
          drupal_goto("symposium/$id/$year/registration");
        }
      }
      // make sure the user is not already registered
      $sql = "SELECT nid FROM {node} WHERE type = '" . $id . "_" . $year . "_registration' AND uid = :uid";
      $nid = db_query($sql, array(':uid' => $user->uid))->fetchField();
      if ($nid && !$form['nid']['#value']) {
        drupal_goto("symposium/$id/$year/registration");
      }
    
      // add a default title
      $form_state['node']->title = 'Registerd';
    
      unset($form['actions']['preview']);        // disable preview
      unset($form['revision_information']);   // disable revision
      unset($form['comment_settings']);      // disable comment settings
      $form_state['node']->comment = '0'; // disable comment
      unset($form['menu']);                           // disable menu
      unset($form['additional_settings']);    // disable additional settings
      unset($form['author']);                         // disable authoring
      unset($form['options']);                       // disable publishing options
      unset($form['path']);                            // disable URL path
      $form_state['node']->promote = '0'; // don't promot to the front
      $form_state['node']->status = '0';      // don't publish the registration
	}
    
  /*
   * Content Type: abstract
   */ 
  } else if (preg_match('/.+?_.+?_abstract$/', $type)) {
    // check if the user has registered. if not, redirect to abstract submission checkpoint
    global $user;
    $roles = $user->roles;
    $abstract = preg_match('/(.+?)_(.+?)_abstract$/', $type, $matches);
    $id = $matches[1];
    $year = $matches[2];
    // make sure the abstract submission is not closed
    $settings = symposium_get_settings();
	if (isset($settings[$id]) && in_array($year, $settings[$id]->years)) {
      $setting = $settings[$id];
      $closed = $setting->closed;
      if (in_array($year, $closed)) {
        if (!in_array($setting->late_role, $roles)) {
          drupal_goto("symposium/$id/$year/abstract_submission");
        }
      }
      // make sure the user is already registered
      $sql = "SELECT nid FROM {node} WHERE type = '" . $id . "_" . $year . "_registration' AND uid = :uid";
      $nid = db_query($sql, array(':uid' => $user->uid))->fetchField();
      if (!$nid) {
        drupal_goto("symposium/$id/$year/abstract_submission");
      }
    
      unset($form['revision_information']); // disable revision
      unset($form['comment_settings']);     // disable comment settings
      $form_state['node']->comment = '0'; // disable comment
      unset($form['menu']);                           // disable menu
      unset($form['additional_settings']);    // disable additional settings
      unset($form['author']);                         // disable authoring
      unset($form['options']);                       // disable publishing options
      unset($form['path']);                            // disable URL path
      $form_state['node']->promote = '0'; // don't promot to the front
    }
  }
}

function  symposium_node_insert ($node) {
  $type = $node->type;
  if ($type == 'symposium') {
    //Set up sympoisum AFTER the sympoisum is created
    register_shutdown_function('symposium_setup', $node);
  } else if (preg_match('/.+?_.+?_abstract$/', $type)) {
    // send to moderation queue
    db_update('node')
    ->fields(array('moderate' => '1'))
    ->condition('nid', $node->nid)
    ->execute();
  }
}

function  symposium_node_update($node) {
  $type = $node->type;
  if ($type == 'symposium') {
    //Set up sympoisum AFTER the sympoisum is updated
    register_shutdown_function('symposium_setup', $node);
  }
}

function  symposium_setup($node) {
  // Create menu items to check registration and abstract submission
  menu_rebuild();
  
  // Create registration and abstract submission content types
  $id = $node->field_short_name['und'][0]['value'];
  module_load_include('inc', 'symposium', 'includes/registration');
  symposium_create_registration_content ($id);
  module_load_include('inc', 'symposium', 'includes/abstract');
  symposium_create_abstract_content ($id);

}

function symposium_mysubmission($id, $year) {
  global $user;
  
  $sql = "SELECT nid, title FROM {node} WHERE type = '" . $id . "_" . $year . "_abstract' AND uid = :uid";
  $results = db_query($sql, array(':uid' => $user->uid));
  $list = '<ul>';
  $counter = 0;
  while($node = $results->fetchObject()) {
    $title = $node->title;
    $nid = $node->nid;
    $list .= t("<li><a href=@nid>$title</a></li>", array('@nid' => url("node/$nid")));
    $counter ++;
  }
  $list .= '</ul>';
  $list = "You have $counter submission.<br>" . $list;
  $settings = symposium_get_settings();
  $setting = $settings[$id];
  drupal_set_title("My $setting->title $year submission");
  return $list;
}

/*
 * Maintain permissions for the roles that are allowed to register
 */
function symposium_grant_permissions($type, $roles) {
  $permissions = array(
    "create $type content",
    "edit own $type content",
    "view own unpublished content"
    // "delete own $type content",
  );
  $all_roles = user_roles();
  foreach ($all_roles AS $rid => $role) {
    if ($role == 'administrator') {
      // do not change administrator settings
    }
    else if (in_array($role, $roles)) {
      user_role_grant_permissions($rid, $permissions);
    }
    else {
      user_role_revoke_permissions($rid, $permissions);
    }
  } 
}
