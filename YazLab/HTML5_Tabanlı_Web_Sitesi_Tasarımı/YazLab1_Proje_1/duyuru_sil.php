<?php

  require_once("session.php");
  require_once("kullanici.php");
  require_once("veritabani.php");


$kullanici_dogrulama = new kullaniciBilgisi();
$duyuru_sorgula = new kullaniciBilgisi();
$duyuru_sil = new kullaniciBilgisi();

    $kullanici_id_veri = $_SESSION['kullanici_session'];
    
    $hazirla = $kullanici_dogrulama->sorguCalistir("SELECT * FROM tablo WHERE kullanici_id_veri=:kullanici_id_veri");
    $hazirla->execute(array(":kullanici_id_veri"=>$kullanici_id_veri));
    $kullaniciData=$hazirla->fetch(PDO::FETCH_ASSOC);


if(isset($_POST['btn-sil']))
{
    $id = $_GET['delete_id'];
    if($duyuru_sil->kontrol_bolum()){
    $duyuru_sil->sil($id);}
    if($duyuru_sil->kontrol_genel()){
    $duyuru_sil->sil_genel($id);}
    header("Location: duyuru_sil.php?deleted"); 
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



<div class="container-fluid" style="margin-top:120px;">
<div class="container">

    <?php
    if(isset($_GET['deleted']))
    {
        ?>
        <div class="alert alert-success">
        <strong>Kayıt silindi</strong>
        </div>
        <?php
    }
    else
    {
        ?>
        <div class="alert alert-danger">
        <strong>Kaydı silmek istiyor musunuz?</strong>
        </div>
        <?php
    }
    ?>  
</div>


<div class="container">

<?php
if(isset($_GET['delete_id']))
{
    ?>
    <form method="post">
    <input type="hidden" name="id" value="<?php echo $row['duyuru_id_veri']; ?>" />
    <button class="btn btn-large btn-primary" type="submit" name="btn-sil"><i class="glyphicon glyphicon-trash"></i> &nbsp; Evet</button>
    <a href="giris.php" class="btn btn-large btn-success"><i class="glyphicon glyphicon-backward"></i> &nbsp; Hayır</a></form>
    </br>    </form>  
    <?php
}
else
{
    ?>
    <a href="anaSay.php" class="btn btn-large btn-success"><i class="glyphicon glyphicon-backward"></i> &nbsp; Duyuru Ekleme Sayfası </a></br> </br>  
    <?php

}
?>
   <table class='table table-bordered table-responsive'>
     <tr>
     <th>Duyuru Başlığı</th>
     <th>Duyuru içeriği</th>
     <th colspan="2" align="center">Düzenle</th>
     </tr>


     <?php
         if($duyuru_sil->kontrol_bolum()){
       $sorgu = "SELECT * FROM duyuru_tablo";       
    $duyuru_sorgula->duyuruGoruntule($sorgu);
}



        if($duyuru_sil->kontrol_genel()){
           $sorgu = "SELECT * FROM duyuru_tablo_genel";       
    $duyuru_sorgula->duyuruGoruntule($sorgu);
}
   ?>
    <tr>
        <td colspan="7" align="center">
      <div class="pagination-wrap">
          </div>
        </td>
    </tr>
 </table>
</div>
</div>  
</div>
<body>
</html>