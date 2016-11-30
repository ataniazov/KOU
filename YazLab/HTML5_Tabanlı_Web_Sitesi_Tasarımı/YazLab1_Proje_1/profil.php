<?php

	require_once("session.php");
	require_once("kullanici.php");
	$kullanici_dogrulama = new kullaniciBilgisi();
	$profil_guncelle = new kullaniciBilgisi();
	
	$kullanici_id_veri = $_SESSION['kullanici_session'];
	
	$hazirla = $kullanici_dogrulama->sorguCalistir("SELECT * FROM tablo WHERE kullanici_id_veri=:kullanici_id_veri");
	$hazirla->execute(array(":kullanici_id_veri"=>$kullanici_id_veri));
	$kullaniciData=$hazirla->fetch(PDO::FETCH_ASSOC);




if(isset($_POST['btn-guncelle']))
{
	$kullaniciAdi = $kullaniciData['kullanici_adi_veri'];
	$kullaniciEmail = strip_tags($_POST['kullanici_email']);
	$kullaniciSifre1 = strip_tags($_POST['kullanici_sifre1']);
	$kullaniciSifre2 = strip_tags($_POST['kullanici_sifre2']);
	$kullaniciSifreEski = strip_tags($_POST['kullanici_sifre']);


  $sifre_dogrulama = password_verify($kullaniciSifreEski, $kullaniciData['kullanici_sifre_veri']);

	
	if($kullaniciEmail == "" )
	{

		$kullaniciEmail= $kullaniciData['kullanici_email_veri'];
		
	}

		if((password_verify($kullaniciSifreEski, $kullaniciData['kullanici_sifre_veri'])) and ($kullaniciSifre1 == $kullaniciSifre2))
	     {

		$kullaniciSifreYeni = $kullaniciSifre2;

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
				<strong>Şifreler uyuşmuyor</strong> 
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
<link rel="stylesheet" href="css/style.css" type="text/css"  />
<title>Kullanıcı sistemi</title>
<script src="bootstrap/js/bootstrap.min.js"></script>
</head>

<body>

<nav class="navbar progress-bar-info navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" 
          aria-expanded="false" aria-controls="navbar">
            <span class="sr-only"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" </a>
        </div>
        <div id="navbar" class="navbar-collapse collapse">
          <ul class="nav navbar-nav navbar-right">
            
            <li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
			  <span class="glyphicon glyphicon-user"></span>&nbsp;<?php echo $kullaniciData['kullanici_adi_veri']; ?>&nbsp;<span class="caret"></span></a>
              <ul class="dropdown-menu">
                <li><a href="giris.php"><span class="glyphicon glyphicon-user"></span>&nbsp;Giriş</a></li>
                <li><a href="cikis.php?logout=true"><span class="glyphicon glyphicon-log-out"></span>&nbsp;Çıkış</a></li>
              </ul>
            </li>
          </ul>
        </div>
      </div>
    </nav>

	<div class="clearfix"></div>
	
<div class="signin-form">
<div class="container">

        <form method="post" class="form-signin">
        <h3 class="form-signin-heading">Profil Düzenleme</h3><hr />
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
            <input type='text' name='kullanici_email' class='form-control' value="" placeholder="E-mail güncelle" >
            </div>

            <div class="form-group">
            	<input type="password" class="form-control" name="kullanici_sifre" placeholder="Sifreniz" required/>
            </div>

            <div class="form-group">
            	<input type="password" class="form-control" name="kullanici_sifre1" placeholder="Yeni Sifre" required/>
            </div>

            <div class="form-group">
            	<input type="password" class="form-control" name="kullanici_sifre2" placeholder="Yeni Sifre" required/>
            </div>
            <div class="clearfix"></div><hr/>
            <div class="form-group">
            	<button type="submit" class="btn btn-primary" name="btn-guncelle">
                	<span class="glyphicon glyphicon-edit"></span>&nbsp;Güncelle
                </button>
             <a href="giris.php" class="btn btn-info" role="button" style="float: right;"><i class="glyphicon glyphicon-backward"></i> &nbsp; Geri</a>
            </div><br/>
       </form>
       </div>
    </div>

</body>
</html>