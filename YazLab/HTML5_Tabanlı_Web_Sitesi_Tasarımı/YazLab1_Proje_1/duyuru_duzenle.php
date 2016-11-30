<?php

require_once("kullanici.php");
require_once("veritabani.php");
require_once("session.php");
$kullanici_dogrulama = new kullaniciBilgisi();
$duyuru_sorgula = new kullaniciBilgisi();
$duyuru_guncelle = new kullaniciBilgisi();


    $kullanici_id_veri = $_SESSION['kullanici_session'];
    
    $hazirla = $kullanici_dogrulama->sorguCalistir("SELECT * FROM tablo WHERE kullanici_id_veri=:kullanici_id_veri");
    $hazirla->execute(array(":kullanici_id_veri"=>$kullanici_id_veri));
    $kullaniciData=$hazirla->fetch(PDO::FETCH_ASSOC);

if(isset($_POST['btn-guncelle']))
{
	$duyuru_id = $_GET['edit_id'];
	$duyuruBasligi = $_POST['duyuru_basligi_veri'];
	$duyuruIcerigi = $_POST['duyuru_icerigi_veri'];

	if($duyuru_guncelle->kontrol_bolum()){
		if($duyuru_guncelle->guncelle($duyuru_id,$duyuruBasligi,$duyuruIcerigi))
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
	
if($duyuru_guncelle->kontrol_genel()) {
		if($duyuru_guncelle->guncelleGenel($duyuru_id,$duyuruBasligi,$duyuruIcerigi))
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

}

if(isset($_GET['edit_id']))
{
	$duyuru_id = $_GET['edit_id'];
		if($duyuru_guncelle->kontrol_bolum()){
	extract($duyuru_guncelle->IdAl($duyuru_id));}

			 if ($duyuru_guncelle->kontrol_genel()){
	extract($duyuru_guncelle->IdAl_genel($duyuru_id));}		
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
<script type="text/javascript" src="bootstrap/js/bootstrap-filestyle.js"> </script>
<script src="bootstrap/js/bootstrap.min.js"></script>
<script type="text/javascript" src="openEditor/ckeditor.js"></script>
<title>Kullanıcı sistemi</title>
</head>

<body>


<nav class="navbar navbar-default navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" 
          aria-expanded="false" aria-controls="navbar">
            <span class="sr-only"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand"</a>
        </div>
        <div id="navbar" class="navbar-collapse collapse">
          <ul class="nav navbar-nav">

          </ul>
          <ul class="nav navbar-nav navbar-right">
            
            <li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
        <span class="glyphicon glyphicon-user"></span>&nbsp;<?php echo $kullaniciData['kullanici_adi_veri']; ?>&nbsp;<span class="caret"></span></a>
              <ul class="dropdown-menu">
                  <li><a href="profil.php"><span class="glyphicon glyphicon-user"></span>&nbsp;Profili düzenle</a></li>
                <li><a href="cikis.php?logout=true"><span class="glyphicon glyphicon-log-out"></span>&nbsp;Çıkış</a></li
              </ul>
            </li>
          </ul>
        </div><!--/.nav-collapse -->
      </div>
    </nav>


<div class="clearfix"></div>

<div class="container-fluid" style="margin-top:120px;">
<div class="container">
<?php
if(isset($msg))
{
	echo $msg;
}
?>

<div class="clearfix"></div><br />

<div class="container">
	     <form method='post'>
     <table class='table table-bordered'>
         <tr>
            <td>Duyuru Başlığı</td>
            <td><input type='text' name='duyuru_basligi_veri' class='form-control' value="<?php echo $duyuru_basligi_veri; ?>" required></td>
        </tr>
         <tr>
            <td>Duyuru içeriği</td>
            <td><textarea type="text" name="duyuru_icerigi_veri" id="duyuru_icerigi_veri" class="form-control" rows="10" name="duyuru_icerigi_veri" required><?php echo $duyuru_icerigi_veri;?></textarea></td>
        </tr>
            <td colspan="2">
                <button type="submit" class="btn btn-primary" name="btn-guncelle">
    			<span class="glyphicon glyphicon-edit"></span>&nbsp;Güncelle</button>
                <a href="giris.php" class="btn btn-large btn-success"><i class="glyphicon glyphicon-backward"></i> &nbsp; Anasayfaya Dön</a>
            </td>
       
     </table>
</form>
</div>

</div>

</div>
<script type="text/javascript">
	CKEDITOR.replace('duyuru_icerigi_veri');
</script>
<body>
</html>
