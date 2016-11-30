<?php
session_start();

	require_once('session.php');
	require_once('kullanici.php');
	$kullanici_cikis = new kullaniciBilgisi();
	
	if($kullanici_cikis->girisYapildi()!="")
	{
		$kullanici_cikis->sesYer('giris.php');
	}
	if(isset($_GET['logout']) && $_GET['logout']=="true")
	{
		$kullanici_cikis->cikis();
		$kullanici_cikis->sesYer('index.php');
	}
