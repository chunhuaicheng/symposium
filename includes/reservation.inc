<?php 
function symposium_event_reservation ($id, $year) {
    $form = drupal_get_form('symposium_event_reservation_form', $id, $year);
    return $form;
}

function symposium_event_reservation_form($form, &$form_state, $id, $year) {
    global $user;
    $uid = $user->uid;
    dpm($uid);
}