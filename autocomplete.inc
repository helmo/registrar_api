<?php

function registrar_api_company_autocomplete($string = "") {
	$matches = array();
	global $user;
	$result = db_query("
		SELECT company_name FROM {registrar_api_contact} contact
			LEFT JOIN {registrar_api_user_handles} handles
			ON (contact.cid = handles.cid)
		WHERE handles.uid = %d
			AND LOWER(contact.company_name) LIKE LOWER('%s%%')", $user->uid, $string);
	while ($data = db_fetch_object($result)) {
		$matches[$data->company_name] = check_plain($data->company_name);
	}
	drupal_json($matches);
}
