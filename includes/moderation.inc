<?php
function  symposium_form_modr8_response_form_alter (&$form, &$form_state) {
  $node = node_load(arg(1));
  $form['title']['#value'] = 'Response regarding '.$node->title;
  
}

// Alter abstract moderation form
function  symposium_form_modr8_form_alter (&$form, &$form_state) {
  // Add css to the form
  drupal_add_css (drupal_get_path ( 'module', 'symposium' ) . '/theme/symposium.css' );
  
  // change 'No action' to 'E-mail author'
  foreach ($form as $id =>$value) {
    if (preg_match('/^\d+$/', $id)) {
      $form[$id]['ops'][ '#options']['nada'] = t ('E-mail author');
    }
  }
  
  //change 'Save' to 'Submit'
  $form['submit'] = array(
    '#prefix' => '<div class=icgi_moderation_form_submit_buttons>',
    '#suffix' => '</div>',
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
}