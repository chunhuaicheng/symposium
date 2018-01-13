<?php

// Login or create account
function symposium_message_create_account($title) {
  $message = t(
    "Please <a href=\"@user\">Log in</a><br>$title is open to registered users only.
      If you don't have an account, please follow the link to <a href=\"@register\">Create 
      New Account</a>.",
      array(
        '@user' => url('user'),
        '@register' => url('user/register')
      )
  );
  return $message;
}

// Registration closed
function symposium_message_registration_closed () {
  $message =
  t("Registration closed. The deadline for registration has passed.");
  return $message;
}

// Already registered
function symposium_message_already_registered ($id, $year, $nid, $title) {
  global $user;
  $uid = $user->uid;
  $message = t(
    "You are already registered to the $title $year</br>
     <ul style=\"padding-left:12px\">
       <li>To make change to your registration, please follow the link: <a href=\"@register\">Update Registration</a></li>
       <li>To submit an abstract, please follow the link: <a href=\"@abstract\">Abstract Submission</a></li>
       <li>To review your submissions, please follow the link: <a href=\"@submission\">My Submissions</a></li>
     </ul>",
      array(
        '@register' => url("node/$nid/edit"),
        '@abstract' => url("node/add/$id-" . $year . "-abstract"),
        '@submission' => url("symposium/mysubmission/$id/$year")
      )
  );
  return $message;
}

// Not yet registered
function symposium_message_not_yet_registered ($id, $year, $title) {
  $message = t(
    "Please register for the $title $year first. <br> Follow the link to
     <a href=\"@register\">Register</a>",
    array(
      '@register' => url("symposium/$id/$year/registration")
    )
  );
  return $message;
}

// Membership required
function symposium_message_membership_required ($id) {
  global $user;
  $uid = $user->uid;
  $message = t(
    "You're not a member. " . ucfirst($id) . " membership is required for the registration.
     Please use this link to acquire the membership:
     <a href=\"@profile\">Become a member</a> or <a href=\"@contact\">Contact us</a>
     if you don't have permission to change your roles.",
      array(
        '@profile' => url("user/$uid/edit"),
        '@contact' => url('contact')
      )
  );
  return $message;
}

// Abstract submission closed
function symposium_message_abstract_submission_closed () {
  $message =
  "Abstract submission closed. The deadline for abstract submission has passed.";
  return $message;
}

// Abstract submission rules
function symposium_message_abstract_submission_rules ($id, $year, $title, $limit) {
  $message = t(
  "<br /><br /><h4>Abstract submission rules:</h4>
    Members may submit their abstract for the $title.
    They must first acquire an account on the website and request membership in the ICGI group.
    After logging in, they need to register for the conference using the
    <a href=\"@register\">Registration</a>.
    Then, submission can be made using the <a href=\"@abstract\">
    Abstract Submission</a>.<br /><br />All abstracts must be submitted online.
    The abstract should not exceed the limit of $limit words in length and will be reviewed by one of the moderators for approval.
    Once accepted, you'll be notified by email and the abstract will be published here:
    <a href=\"@pub\">Current Abstracts</a>",
      array(
        '@register' => url("symposium/$id/$year/registration"),
        '@abstract' => url("symposium/$id/$year/abstract_submission"),
        '@pub' => url("$id/$year/publication")
      )
  );
  return $message;
}