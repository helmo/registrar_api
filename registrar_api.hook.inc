<?php

/**
 * @file
 * List of hooks to be implemented for each registrar.
 * This file should not contain any implementation.
 */


/**
 * Provide a form structure for registrar specific configuration.
 *
 * @return Form API array 
 */
function hook_admin_form() {
}

/**
 *  Return an array containing some details about this registrar.
 */
function hook_get_registrar_info() {}

/**
 * @see registrar_api_check_domains() 
 */
function hook_check_domains($domain_list) {}

function hook_create_domain($domain_name, $years, $registrant, $tech, $admin, $auxbilling, $nameservers = NULL) {}
function hook_get_contacts($domain_name) {}
function hook_set_contacts($domain_name, $registrant, $tech, $admin, $auxbilling) {}

/**
 * Returns an array of domains with the following structure:
 *
 * Array (
 *   [domaintest.com] => Array (
 *     [ID] => 1836
 *     [Name] => domain-name.com
 *     [User] => owner
 *     [Created] => 03/24/2009
 *     [Expires] => 03/24/2010
 *     [IsExpired] => false
 *   )
 * )
 *
 */
function hook_domains_getlist() {
}
