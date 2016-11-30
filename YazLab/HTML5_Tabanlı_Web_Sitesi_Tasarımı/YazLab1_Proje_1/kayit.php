<?php
session_start();

require_once('kullanici.php');

$kayitKullanici = new kullaniciBilgisi();

if($kayitKullanici->girisYapildi()!="")
{
	$kayitKullanici->sesYer('giris.php');
}

if(isset($_POST['button_giris']))
{
	$kullaniciAdi = strip_tags($_POST['kullanici_adi']);
	$kullaniciEmail = strip_tags($_POST['kullanici_email']);
	$kullaniciSifre = strip_tags($_POST['kullanici_sifre']);	
	$kullaniciUnvan = strip_tags($_POST["kullanici_unvan"]);
	
	if($kullaniciAdi=="")	{
		$error[] = "İsim gerekli !";	
	}
	else if($kullaniciEmail=="")	{
		$error[] = "E-Mail gerekli!";	
	}
	else if(!filter_var($kullaniciEmail, FILTER_VALIDATE_EMAIL))	{
	    $error[] = 'Lütfen doğru bir E-Mail giriniz';
	}
	else if($kullaniciSifre=="")	{
		$error[] = "Şifre gerekli";
	}
	else if(strlen($kullaniciSifre) < 1){
		$error[] = "Şifre en az 1 karakterli olmalı";	
	}
	else
	{
		try
		{
			$hazirla = $kayitKullanici->sorguCalistir("SELECT kullanici_adi_veri, kullanici_email_veri FROM tablo WHERE 
				kullanici_adi_veri=:kullaniciAdi OR kullanici_email_veri=:kullaniciEmail");
			$hazirla->execute(array(':kullaniciAdi'=>$kullaniciAdi, ':kullaniciEmail'=>$kullaniciEmail));
			$Data=$hazirla->fetch(PDO::FETCH_ASSOC);
				
			if($Data['kullanici_adi_veri']==$kullaniciAdi) {
				$error[] = "Kayıtlı kullanıcı adı";
			}
			else if($Data['kullanici_email_veri']==$kullaniciEmail) {
				$error[] = "Kayıtlı E-Mail adresi";
			}
			else
			{
				if($kayitKullanici->kayit($kullaniciAdi,$kullaniciEmail,$kullaniciSifre,$kullaniciUnvan)){	
					$kayitKullanici->sesYer('kayit.php?joined');
				}
			}
		}
		catch(PDOException $e)
		{
			echo $e->getMessage();
		}
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

<div class="signin-form">
<div class="container">
        <form method="post" class="form-signin">
        <div align="center" style="margin: 20px;"><img src="logokou.gif" /></div>
        <h3 class="form-signin-heading"><p align="center">Bilgisayar Mühendisliği Kayıt Sistemi</p></h3><hr />
            <?php
			if(isset($error))
			{
			 	foreach($error as $error)
			 	{
					 ?>
                     <div class="alert alert-danger">
                        <i class="glyphicon glyphicon-warning-sign"></i> &nbsp; <?php echo $error; ?>
                     </div>
                     <?php
				}
			}
			else if(isset($_GET['joined']))
			{
				 ?>
                 <div class="alert alert-info">
                      <i class="glyphicon glyphicon-log-in"></i> &nbsp; Kayıt Başarılı
                 </div>
                 <?php
			}
			?>

            <div class="form-group">
            <input type="text" class="form-control" name="kullanici_adi" placeholder="Kullanıcı adi" 
            value="<?php if(isset($error)){echo $kullaniciAdi;}?>" />
            </div>

            <div class="form-group">
            <input type="text" class="form-control" name="kullanici_email" placeholder="E-Mail" 
            value="<?php if(isset($error)){echo $kullaniciEmail;}?>" />
            </div>

            <div class="form-group">
            	<input type="password" class="form-control" name="kullanici_sifre" placeholder="Sifre giriniz" />
            </div>

             <div class="form-group">
            	<input type="text" class="form-control" name="kullanici_unvan" placeholder="Unvan giriniz" />
            </div>

            <div class="clearfix"></div><hr/>
            <div class="form-group">
            	<button type="submit" class="btn btn-primary" name="button_giris">
                	<i class="glyphicon glyphicon-share"></i> &nbsp; Gönder
                </button>
                <a href="anaSay.php" class="btn btn-info" role="button" style="float: right;"><i class="glyphicon glyphicon-backward"></i> &nbsp; Geri</a>
            </div><br/>
        </form>
       </div>
    </div>
  </div>
</body>
</html>