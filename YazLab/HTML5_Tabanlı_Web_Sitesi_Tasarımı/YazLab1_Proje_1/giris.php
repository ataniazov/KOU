<?php
   require_once("session.php");
   require_once("kullanici.php");
   require_once("veritabani.php");
   
   
   $kullanici_dogrulama = new kullaniciBilgisi();
   $duyuru = new kullaniciBilgisi();
    $duyuru_sorgula = new kullaniciBilgisi();
   
   $kullanici_id_veri = $_SESSION['kullanici_session'];
   
   
   $hazirla = $kullanici_dogrulama->sorguCalistir("SELECT * FROM tablo WHERE kullanici_id_veri=:kullanici_id_veri");
   $hazirla->execute(array(":kullanici_id_veri"=>$kullanici_id_veri));
   $kullaniciData=$hazirla->fetch(PDO::FETCH_ASSOC);
   $kullaniciIsim = $kullaniciData["kullanici_adi_veri"];
   
   if(isset($_POST['button_gonder']))
   {
    $duyuruBasligi = strip_tags($_POST['duyuru_basligi']);
    $duyuruIcerigi = strip_tags($_POST['duyuru_icerigi']);
    $kullaniciIsim = $kullaniciData['kullanici_adi_veri'];
   
     $bolum = strip_tags($_POST['bolum']);
     $genel = strip_tags($_POST['genel']);
   
   
     $bolumDuzenle =  ($_POST['bolumDuzenle']);
     $genelDuzenle =  ($_POST['genelDuzenle']);
   
   if($bolumDuzenle)
    $duyuru->kontrol_bolum();
   else if($genelDuzenle)
   $duyuru->kontrol_genel();
   
      try
      {
        
   if($bolum){
   
          $hazirla = $duyuru->sorguCalistir("SELECT duyuru_basligi_veri, duyuru_icerigi_veri FROM duyuru_tablo WHERE 
          duyuru_basligi_veri=:duyuruBasligi OR duyuru_icerigi_veri=:duyuruIcerigi");
        $hazirla->execute(array(':duyuruBasligi'=>$duyuruBasligi, ':duyuruIcerigi'=>$duyuruIcerigi));
        $Data=$hazirla->fetch(PDO::FETCH_ASSOC);
          
          if($duyuru->duyuru_kayit($kullaniciIsim,$duyuruBasligi,$duyuruIcerigi)){  
            $duyuru->sesYer('giris.php?joined');
          }
   
   }
   
   else 
   {
   
            $hazirla = $duyuru->sorguCalistir("SELECT duyuru_basligi_veri, duyuru_icerigi_veri FROM duyuru_tablo_genel WHERE 
          duyuru_basligi_veri=:duyuruBasligi OR duyuru_icerigi_veri=:duyuruIcerigi");
        $hazirla->execute(array(':duyuruBasligi'=>$duyuruBasligi, ':duyuruIcerigi'=>$duyuruIcerigi));
        $Data=$hazirla->fetch(PDO::FETCH_ASSOC);
          
          if($duyuru->duyuru_kayit_genel($kullaniciIsim,$duyuruBasligi,$duyuruIcerigi)){  
            $duyuru->sesYer('giris.php?joined');
          }
   }
   
      }
      catch(PDOException $e)
      {
        echo $e->getMessage();
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
      <script type="text/javascript" src="openEditor/ckeditor.js"></script>
      <script type="text/javascript" src="bootstrap/js/bootstrap-filestyle.js"> </script>
      <script src="bootstrap/js/bootstrap.min.js"></script>
      <title>Kullanıcı sistemi</title>
   </head>
   <body>
      <nav class="navbar progress-bar-info navbar-fixed-top">
         <div class="container col-xs-11 col-md-11">
            <div class="navbar-header ">
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
                  <li class="dropdown ">
                     <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
                     <span class="glyphicon glyphicon-user"></span>&nbsp;<?php echo $kullaniciData['kullanici_adi_veri']; ?>&nbsp;<span class="caret"></span></a>
                     <ul class="dropdown-menu">
                        <li><a href="profil.php"><span class="glyphicon glyphicon-user"></span>&nbsp;Profili düzenle</a></li>
                        <li><a href="slider.php"><span class="glyphicon glyphicon-picture"></span>&nbsp;Slider</a></li>
                        <li><a href="cikis.php?logout=true"><span class="glyphicon glyphicon-log-out"></span>&nbsp;Çıkış</a></li>
                     </ul>
                  </li>
               </ul>
            </div>
         </div>
      </nav>
      <div class="container-fluid " style="margin-top:120px;">
         <div class="container" style="margin-top:20px;">
            <section class="container ">
               <div class="row">
                  <div class="form-group">
                     <div class="col-xs-3">
                        <button type="button" class="btn btn-warning btn-lg" data-toggle="modal" data-target="#signupModal"><i class="glyphicon glyphicon-edit"></i> &nbsp; Duyuru Ekle</button>
                     </div>
                  </div>
            </section>
            </br>
            <?php
               if(isset($error))
               {
                 foreach($error as $error)
                 {
                    ?>
            <div class="alert alert-danger">
            <?php echo $error; ?>
            Kayıt Başarısız
            </div>
            <?php
               }
               }
               
               else if(isset($_GET['joined']))
               {
                ?>
            <div class="alert alert-info">
            Kayıt Başarılı
            </div>
            <?php
               }
               ?>
            </div>
         </div>
         <div class="modal fade " id="signupModal" tabindex="-1" role="dialog" aria-labelledby="mySigninLabel">
            <div class="modal-dialog modal-md ">
               <div class="modal-content ">
                  <div class="modal-header ">
                     <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                     <h4 class="modal-title" id="myModalLabel">Duyuru Ekle</h4>
                  </div>
                  <div class="modal-body " >
                     <form method="POST" class="form " >
                        <div class="form-group">
                           <h5 >Duyuru Başlığı</h5>
                           <input type="text" class="form-control" name="duyuru_basligi" value="" required />
                        </div>
                        <label for="duyuruTuru" class=" control-label">Duyuru Türü</label>
                        <div class="radio">
                           <label><input type="radio"  name="bolum" id="bolum" >Bölüm Duyuruları</label>
                        </div>
                        <div class="radio">
                           <label><input type="radio" name="genel" id="genel" >Genel Duyurular</label>
                        </div>
                        <div class="form-group">
                           <h5 >Duyuru içeriği</h5>
                           <textarea  type="text" class="form-control" id="duyuru_icerigi"  rows="4" name="duyuru_icerigi" value="" required ></textarea>
                        </div>
                        <div class="form-group">
                           <hr/>
                        </div>
                        <div class="form-group">
                           <button type="submit" class="btn btn-primary" name="button_gonder" ><i class="glyphicon glyphicon-share"></i> &nbsp; Gönder</button>
                           <button type="button" class="btn btn-default" style="float: right;" data-dismiss="modal">Kapat</button>
                        </div>
                     </form>
                  </div>
               </div>
            </div>
         </div>
         <div class="container">
            <table class='table table-bordered table-responsive'>
               <tr class="alert-success">
                  <div class="alert alert-info" align="center">Bölüm Duyuruları</div>
                  <th>
                     <p align="center">Duyuru Başlığı</p>
                  </th>
                  <th>
                     <p align="center">Duyuru içeriği</p>
                  </th>
                  <th colspan="2" name="bolumDuzenle" id="bolumDuzenle" align="center">
                     <p align="center">Düzenle</p>
                  </th>
               </tr>
               <?php
                  $sorgu1 = "SELECT * FROM duyuru_tablo WHERE kullanici_adi_veri='$kullaniciIsim'";       
                  $duyuru_sorgula->duyuruGoruntule($sorgu1);
                  
                  ?>
               <tr>
                  <td colspan="7" align="center">
                     <div class="pagination-wrap"> </div>
                  </td>
               </tr>
            </table>
            <table class='table table-bordered table-responsive'>
               <tr class="alert-success">
                  <div class="alert alert-info" align="center">Genel Duyurular</div>
                  <th>
                     <p align="center">Duyuru Başlığı</p>
                  </th>
                  <th>
                     <p align="center">Duyuru içeriği</p>
                  </th>
                  <th colspan="2" name="genelDuzenle" id="genelDuzenle" align="center">
                     <p align="center">Düzenle</p>
                  </th>
               </tr>
               <?php
                  $sorgu2 = "SELECT * FROM duyuru_tablo_genel WHERE kullanici_adi_veri='$kullaniciIsim'";       
                  $duyuru_sorgula->duyuruGoruntule($sorgu2);
                  
                  ?>
               <tr>
                  <td colspan="7" align="center">
                     <div class="pagination-wrap"> </div>
                  </td>
               </tr>
            </table>
         </div>
      </div>
      </div>
      <script type="text/javascript">
         CKEDITOR.replace('duyuru_icerigi');
      </script>
   </body>
</html>