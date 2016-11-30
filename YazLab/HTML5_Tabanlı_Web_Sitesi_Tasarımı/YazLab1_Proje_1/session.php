<?php

	session_start();
	
	require_once 'kullanici.php';
	$session = new kullaniciBilgisi();
	
	// if user session is not active(not loggedin) this page will help 'giris.php and profil.php' to sesYer to login page
	// put this file within secured pages that users (users can't access without login)
	
	if(!$session->girisYapildi())
	{
		// session no set sesYers to login page
		$session->sesYer('anaSay.php');
	}