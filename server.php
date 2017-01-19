<?php

$slack_token = 'XXXXXXXXXXXXXXXXXX';
$particle_device_id = 'XXXXXXXXXXX';
$particle_device_function = 'relay';
$particle_access_token = 'XXXXXXXX';

// If the request came from our slack webhook turn on the light
if($_POST['token'] == $slack_token){

	// Initialize curl
	$ch = curl_init();

	// Set some options
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
	curl_setopt($ch, CURLOPT_POST, 1);
	curl_setopt($ch, CURLOPT_POSTFIELDS,
	    "access_token=$particle_access_token&args=r4,HIGH");
	curl_setopt($ch, CURLOPT_URL, 
		"https://api.particle.io/v1/devices/$particle_device_id/relay");
	
	// Server says?!
	$server_output = curl_exec($ch);
	echo $server_output;

	// All done, cleanup
	curl_close ($ch);

}
