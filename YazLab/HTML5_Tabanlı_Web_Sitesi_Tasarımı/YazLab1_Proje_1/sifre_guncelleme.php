<?php

	require_once("kullanici.php");
	$kullanici_dogrulama = new kullaniciBilgisi();
	$profil_guncelle = new kullaniciBilgisi();
	
	
	
	$hazirla = $kullanici_dogrulama->sorguCalistir("SELECT * FROM tablo");
	$hazirla->execute();
	$kullaniciData=$hazirla->fetch(PDO::FETCH_ASSOC);




if(isset($_POST['btn-guncelle']))
{
	$kullaniciAdi = $kullaniciData['kullanici_adi_veri'];
	$kullaniciAdiGiris = strip_tags($_POST['kullanici_adi']);
	$kullaniciSifre1 = strip_tags($_POST['kullanici_sifre1']);
	$kullaniciSifre2 = strip_tags($_POST['kullanici_sifre2']);
	$kullaniciSifreEski = strip_tags($_POST['kullanici_sifre']);
	$kullaniciEmail = null;


       $sifre_dogrulama = password_verify($kullaniciSifreEski, $kullaniciData['kullanici_sifre_veri']);


	

	if(($sifre_dogrulama) and ($kullaniciSifre1 == $kullaniciSifre2) and 
		($kullaniciAdi == $kullaniciAdiGiris) and $kullaniciEmail == null)
	 {

		$kullaniciSifreYeni = $kullaniciSifre2;
		$kullaniciEmail= $kullaniciData['kullanici_email_veri'];


	    if($profil_guncelle->profilGuncelle($kullaniciAdi,$kullaniciEmail,$kullaniciSifreYeni))
	    {
		$msg = "<div class='alert alert-info'>
				<strong>Güncelleme başarılı bir şekilde yapıldı</strong>
				</div>";
	    }
	    else
	    {
		$msg = "<div class='alert alert-warning'>
				<strong>Güncelleme yapılırken hata oluştu</strong> 
				</div>";
	    }
		
	}


	else
	{
		$msg_sifre = "<div class='alert alert-danger'>
				<strong>Bilgiler uyuşmuyor</strong> 
				</div>";

	}



}

	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link href="bootstrap/css/bootstrap.min.css" rel="stylesheet" media="screen"> 
<link href="bootstrap/css/bootstrap-theme.min.css" rel="stylesheet" media="screen"> 
<script type="text/javascript" src="js/jquery-1.11.3-jquery.min.js"></script>
<script src="bootstrap/js/bootstrap.min.js"></script>
<link rel="stylesheet" href="css/style.css" type="text/css"  />
<title>Kullanıcı sistemi</title>
</head>
<body>
<div class="clearfix"></div>
	
<div class="signin-form">
<div class="container">
        <form method="post" class="form-signin">
        <div align="center" style="margin: 20px;"><img src="logokou.gif" /></div>
        <h3 class="form-signin-heading"><p align="center">Şifre Güncelleme</p> </h3><hr />
<?php
if(isset($msg))
{
	echo $msg;
}

if (isset($msg_sifre) )
{
echo $msg_sifre;
}
?>
           <div class="form-group">
            <input type='text' name='kullanici_adi' class='form-control' value="" placeholder="Kullanıcı Adı" required>
            </div>

            <div class="form-group">
            	<input type="password" class="form-control" name="kullanici_sifre" placeholder="Sifreniz" required/>
            </div>

            <div class="form-group">
            	<input type="password" class="form-control" name="kullanici_sifre1" placeholder="Yeni Sifre" required/>
            </div>

            <div class="form-group">
            	<input type="password" class="form-control" name="kullanici_sifre2" placeholder="Yeni Sifre" required/>
            </div><hr/>

            <div class="form-group">
            	<button type="submit" class="btn btn-primary" name="btn-guncelle">
                	<i class="glyphicon glyphicon-share"></i> &nbsp; Gönder
                 </button>
                <a href="anaSay.php" class="btn btn-info" role="button" style="float: right;"><i class="glyphicon glyphicon-backward"></i> &nbsp; Geri</a>
            </div>
        </form>
       </div>
    </div>

</body>
</html>