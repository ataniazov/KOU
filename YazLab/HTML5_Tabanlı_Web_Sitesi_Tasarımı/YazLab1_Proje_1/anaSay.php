<?php
session_start();
require_once("kullanici.php");

$Bilgi = new kullaniciBilgisi();

if($Bilgi->girisYapildi()!="")
{
	$Bilgi->sesYer('giris.php');
}

if(isset($_POST['button_giris']))
{
	$kullaniciAdi = strip_tags($_POST['kullanici_adi']);
	$kullaniciEmail = strip_tags($_POST['kullanici_adi']);
	$kullaniciSifre = strip_tags($_POST['kullanici_sifre']);
		
	if($Bilgi->giris($kullaniciAdi,$kullaniciEmail,$kullaniciSifre))
	{
		$Bilgi->sesYer('giris.php');
	}
	else
	{
		$error = "Geçersiz Giriş";
	}	
}
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Sisteme Giriş</title>
<link href="bootstrap/css/bootstrap.min.css" rel="stylesheet" media="screen">
<link href="bootstrap/css/bootstrap-theme.min.css" rel="stylesheet" media="screen">
<link rel="stylesheet" href="css/style.css" type="text/css"  />
</head>
<body>

<div class="signin-form ">

	<div class="container ">
       <form class="form-signin " method="post" id="login-form ">
       <div align="center" style="margin: 20px;" ><img src="logokou.gif" /></div>
                     
                
        <h3 class="form-signin-heading "><p align="center">Bilgisayar Mühendisliği Sisteme Giriş</p> </h3><hr />
        <div id="error">

        <?php
			if(isset($error))
			{
				?>
                <div class="alert alert-danger">
                    <i class="glyphicon glyphicon-warning-sign"></i> &nbsp; <?php echo $error; ?> !
                </div>
                <?php
			}
		?>

        </div>
        <div class="form-group ">
        <input type="text" class="form-control" name="kullanici_adi" placeholder="Kullanici adi" required />
        <span id="check-e"></span>
        </div>

        <div class="form-group">
        <input type="password" class="form-control" name="kullanici_sifre" placeholder="Sifre" required />
        </div><hr />

        <div class="form-group">
            <button type="submit" name="button_giris" class="btn btn-primary">
                	<i class="glyphicon glyphicon-log-in"></i> &nbsp; Giriş
            </button>
             <a href="kayit.php" class="btn btn-info" role="button" style="margin-left:60px"><i class="glyphicon glyphicon-edit"></i> &nbsp; Üye ol</a>
             <a href="sifre_guncelleme.php" class="btn btn-info" role="button" style="float: right;"><i class="glyphicon glyphicon-edit"></i> &nbsp; Şifre Güncelleme</a>
        </div><br/>
       
      </form>
    </div>
</div>
</body>
</html>