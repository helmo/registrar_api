<?php

echo "Started example script\n\n";

require_once('API.php');

$username = "";
$password = "";

// Create a new API connection
$api = new OP_API ('https://api.openprovider.eu');

$request = new OP_Request;
$request->setCommand('createCustomerRequest')
	->setAuth(array('username' => $username, 'password' => $password))
	->setArgs(array(
		'companyName' => 'Company Ltd',
		'name' => array(
			'initials' => 'J.A.',
			'firstName' => 'John',
			'prefix' => "",
			'lastName' => 'Jones',
		),
		'vat' => null,
		'gender' => 'M', 
		'phone' => array(
			'countryCode'  => '+31',
			'areaCode' => '383',
			'subscriberNumber' => '1231212'
		),

		'fax' => array(
			'countryCode' => '+31',
			'areaCode' => '383',
			'subscriberNumber' => '1231213'
		),

		'address' => array(
			'street' => 'Main Avenue',
			'number' => '2',
			'suffix' => 'a',
			'zipcode' => '8817 AB',
			'city' => 'Rotterdam',
			'state' => null,
			'country' => 'NL',
		),

		'email' => 'not@existing.com',

		'additionalData' => array(
			'birthDate' => '1958-12-03',
			'companyRegistrationCity' => 'London',
			'companyRegistrationNumber' => '7723601',
			'companyRegistrationSubscriptionDate' => '2003-09-12',
		)
	));
$reply = $api->setDebug(1)->process($request);
$response = $reply->getValue();
$handle = $response['handle'];
echo "Code: " . $reply->getFaultCode() . "\n";
echo "Error: " . $reply->getFaultString() . "\n";
echo "Handle: " . $handle."\n";
echo "\n---------------------------------------\n";

$request = new OP_Request;
$request->setCommand('deleteCustomerRequest')
	->setAuth(array('username' => $username, 'password' => $password))
	->setArgs(array(
		'handle' => $handle,
	));
$reply = $api->setDebug(1)->process($request);
echo "\n---------------------------------------\n";


$request = new OP_Request;
$request->setCommand('retrieveDomainRequest')
	->setAuth(array('username' => $username, 'password' => $password))
	->setArgs(array(
		'domain' => array(
			'name' => 'openprovider',
			'extension' => 'nl'
		),
		'withAdditionalData' => 0
	));
$reply = $api->setDebug(1)->process($request);
echo "Code: " . $reply->getFaultCode() . "\n";
echo "Error: " . $reply->getFaultString() . "\n";
echo "Value: " . print_r($reply->getValue(), true) . "\n";
echo "\n---------------------------------------\n";

$request = new OP_Request;
$request->setCommand('checkDomainRequest')
	->setAuth(array('username' => $username, 'password' => $password))
	->setArgs(array(
		'domains' => array(
			array('name' => 'openprovider', 'extension' => 'nl'),
			array('name' => 'non-existing-domain', 'extension' => 'co.uk')
		)
	)
);
$reply = $api->setDebug(1)->process($request);
print_r($reply->getValue());
echo "\n---------------------------------------\n";

echo "Finished example script\n\n";


