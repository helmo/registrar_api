<?php
// $Id$

/**
 * @file
 * Hooks to implement the custom content types
 */

/**
 * Implementation of hook_node_info().
 */
function registrar_api_node_info() {
	return array(
		'registrar_contact' => array(
			'name'		=> t('Contact Handle'),
			'module'	=> 'registrar_contact',
			'description'	=> 'A contact handle representing a contact',
			'has_body'	=> FALSE,
		),
	);
}

/**
 * Implementation of hook_form() for the contact content type.
 */
function registrar_contact_form(&$node, $form_state) {
	$type = node_get_types('type', $node);

	$form['title'] = array(
		'#type'		=> 'textfield',
		'#title'	=> check_plain($type->title_label),
		'#required'	=> TRUE,
		'#size'		=> 20,
	);

	/* DB schema fields */
	$form['uid'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Users table uid'),
		'#required'		=> TRUE,
		'#default_value'	=> $node->uid,
	);
	$form['company_name'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Company Name'),
		'#required'		=> TRUE,
		'#size'			=> 60,
		'#maxlength'		=> 60,
		'#default_value'	=> $node->company_name,
	);
	$form['initials'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Initials'),
		'#required'		=> TRUE,
		'#size'			=> 60,
		'#maxlength'		=> 60,
		'#default_value'	=> $node->initials,
	);
	$form['firstname'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Firstname'),
		'#required'		=> TRUE,
		'#size'			=> 60,
		'#maxlength'		=> 60,
		'#default_value'	=> $node->firstname,
	);
	$form['nameprefix'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Name Prefix'),
		'#required'		=> FALSE,
		'#size'			=> 10,
		'#maxlength'		=> 10,
		'#default_value'	=> $node->nameprefix,
	);
	$form['lastname'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Lastname'),
		'#required'		=> TRUE,
		'#size'			=> 60,
		'#maxlength'		=> 60,
		'#default_value'	=> $node->lastname,
	);
	$form['gender'] = array(
		'#type'			=> 'select',
		'#title'		=> t('Gender'),
		'#required'		=> TRUE,
		'#maxlength'		=> 8,
		'#default_value'	=> $node->gender,
		'#options'		=> array(
						'M' => t("Male"),
						'F' => t("Female"),
					),
	);
	$form['street'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Street'),
		'#required'		=> TRUE,
		'#size'			=> 60,
		'#maxlength'		=> 60,
		'#default_value'	=> $node->street,
	);
	$form['housenumber'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Housenumber'),
		'#required'		=> TRUE,
		'#default_value'	=> $node->housenumber,
	);
	$form['housesuffix'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Housesuffix'),
		'#required'		=> FALSE,
		'#size'			=> 30,
		'#maxlength'		=> 30,
		'#default_value'	=> $node->housesuffix,
	);
	$form['zipcode'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Zipcode'),
		'#required'		=> TRUE,
		'#size'			=> 15,
		'#maxlength'		=> 15,
		'#default_value'	=> $node->zipcode,
	);
	$form['city'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('City'),
		'#required'		=> TRUE,
		'#size'			=> 60,
		'#maxlength'		=> 200,
		'#default_value'	=> $node->city,
	);
	$form['state'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('State'),
		'#required'		=> TRUE,
		'#size'			=> 60,
		'#maxlength'		=> 200,
		'#default_value'	=> $node->state,
	);
	$form['country'] = array(
		'#type'			=> 'select',
		'#title'		=> t('Country'),
		'#required'		=> TRUE,
		'#maxlength'		=> 2,
		'#default_value'	=> $node->country,
		'#options'		=> _registrar_api_country_codes(),
	);
	$form['phone_countrycode'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Telephone Country code'),
		'#required'		=> TRUE,
		'#default_value'	=> $node->phone_countrycode,
	);
	$form['phone_areacode'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Telephone Area code'),
		'#required'		=> TRUE,
		'#size'			=> 10,
		'#maxlength'		=> 10,
		'#default_value'	=> $node->phone_areacode,
	);
	$form['phone_subscribernumber'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Telephone Subscriber code'),
		'#required'		=> TRUE,
		'#size'			=> 20,
		'#maxlength'		=> 20,
		'#default_value'	=> $node->phone_subscribernumber,
	);
	$form['fax_countrycode'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Fax Country code'),
		'#required'		=> FALSE,
		'#default_value'	=> $node->fax_countrycode,
	);
	$form['fax_areacode'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Fax Area code'),
		'#required'		=> FALSE,
		'#size'			=> 10,
		'#maxlength'		=> 10,
		'#default_value'	=> $node->fax_areacode,
	);
	$form['fax_subscribernumber'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Fax Subscriber code'),
		'#required'		=> FALSE,
		'#size'			=> 20,
		'#maxlength'		=> 20,
		'#default_value'	=> $node->fax_subscribernumber,
	);
	$form['email'] = array(
		'#type'			=> 'textfield',
		'#title'		=> t('Email address'),
		'#required'		=> TRUE,
		'#size'			=> 60,
		'#maxlength'		=> 255,
		'#default_value'	=> $node->email,
	);
	return $form;
}

/**
 * Implementation of hook_insert().
 */
function registrar_contact_insert($node) {
	//stub	
	$set_str = _registrar_api_get_set_str($node);
	db_query("INSERT INTO {registrar_api_contact} SET $set_str",
		$node->nid);
} 

/**
 * Implementation of hook_update().
 */
function registrar_api_update($node) {
	print_r($node);
	//stub
}

/**
 * Implementation of hook_load().
 */
function registrar_api_load($node) {
	print_r($node);
	$contact_data = db_fetch_object(db_query("SELECT * FROM {registrar_api_contact} WHERE nid=%d", $node->nid));
	return $contact_data; 
}

/**
 * There is no implementation of hook_delete()
 * Handles may not be deleted, because the can be used by domains
 * If there are domains active, and the handle is deleted, we may have a problem with renewing the domain
 */

/**
 * Implementation of hook_form_alter().
 */
function registrar_api_form_alter(&$form, $form_state, $form_id) {
	if ($form_id == 'registrar_contact_node_form') {
		// Move menu to the bottom
		$form['menu']['#weight'] = 5;
		
		// We need to do something hacky if CCK is being used.
		if (module_exists('content')) {
			$extra = variable_get('content_extra_weights_registrar_contact', array());
			$extra['menu'] = 5;
			variable_set('content_extra_weights_registrar_contact', $extra);
		}

		// Preview doesn't make sense in this context
		unset($form['buttons']['preview']);
		unset($form['buttons']['delete']);
	}
}
