<?php
 require_once("kullanici.php");
 require_once("veritabani.php");

$slider_nesne = new kullaniciBilgisi();



if (isset($_POST["sliderAdi"]) && isset($_POST["sliderMetni"])) {
  $sliderAdi = $_POST["sliderAdi"];
  $sliderMetni = $_POST["sliderMetni"];
  $sliderResmi = basename($_FILES["sliderResmi"]["name"]);
  $hedef_dizin = "slicebox/slider/";
  $hedef_dosya = $hedef_dizin.$sliderResmi;
  $yuklemeTamam = 1;
  $resimDosyaTipi = pathinfo($hedef_dosya,PATHINFO_EXTENSION);

  if (file_exists($hedef_dosya)) {
    $yuklemeTamam = 0;
  }

  if($resimDosyaTipi != "jpg" && $resimDosyaTipi != "png" && $resimDosyaTipi != "jpeg" && $resimDosyaTipi != "gif" && 
     $resimDosyaTipi != "JPG" && $resimDosyaTipi != "PNG" && $resimDosyaTipi != "JPEG") {
        $yuklemeTamam = 0;
 }
 if ($yuklemeTamam == 0) {
      echo "<script language='javascript'>alert('İzin verilmeyen bir dosya formatı.');</script>";
  } else {
      if (move_uploaded_file($_FILES["sliderResmi"]["tmp_name"], $hedef_dosya)) {
        $slider_nesne->sliderKaydet($sliderAdi,$sliderMetni,$sliderResmi);
        header("Location: slider.php");
      } else {
          echo "<script language='javascript'>alert('Yükleme sırasında bir hata meydana geldi.');</script>";
      }
  }
}


   $sld=$slider_nesne->sliderGoruntule();
        

       
        


if (isset($_POST["silinecekSlider"])) {
  $ID = $_POST["silinecekSlider"];
  
  $rs = $slider_nesne->sliderId($ID);

  $rsm = $rs["resim"];
  if(unlink("slicebox/slider/".$rsm."")) {
    $slider_nesne->sliderSil($ID);
    header("Location: slider.php");  
  }
}

?>
<!DOCTYPE html>
<html lang="tr">
  <head>
<link href="bootstrap/css/bootstrap.min.css" rel="stylesheet" media="screen">
<link href="bootstrap/css/bootstrap-theme.min.css" rel="stylesheet" media="screen">
<script type="text/javascript" src="js/jquery-1.11.3-jquery.min.js"></script>
<link rel="stylesheet" href="css/style.css" type="text/css"  />
<script type="text/javascript" src="bootstrap/js/bootstrap-filestyle.js"> </script>
<script src="bootstrap/js/bootstrap.min.js"></script>
  </head>

  <body>

 

    <div class="container-fluid">
      <div class="row">


        <div class="col-sm-12 main"><br/><br/>
        <div class="alert alert-info"><i class="fa fa-superpowers" aria-hidden="true"></i> Slider İşlemleri</div>
        <form action="slider.php" method="post" enctype="multipart/form-data">
          <label class="label label-primary"></label>
           <table class="table table-bordered tablo">
          <tr>
            <td class="col-md-2"><i class="fa fa-pencil-square" aria-hidden="true"></i> Slider Adı</td>
            <td class="col-md-7"><input type="text" name="sliderAdi" class="form-control" required=""></td>
          </tr>
            <tr>
            <td class="col-md-2"><i class="fa fa-newspaper-o" aria-hidden="true"></i> Slider Metni</td>
            <td class="col-md-7"><input type="text" name="sliderMetni" class="form-control" required=""></td>
          </tr>
            <tr>
            <td class="col-md-2"><i class="fa fa-picture-o" aria-hidden="true"></i> Resim</td>
            <td class="col-md-7"><input type="file" name="sliderResmi" class="form-control" required=""></td>
          </tr>
            <tr>
            <td class="col-md-2"><input type="reset" value="Temizle" class="btn btn-warning btn-sm"></td>
            <td class="col-md-7"><input type="submit" value="Gönder" class="btn btn-success btn-sm"></td>
          </tr>
        </table>
        </form>

           <form action="slider.php" method="post">
          <label class="label label-primary"></label>
           <table class="table table-bordered tablo">
          <tr>
            <td class="col-md-2"><i class="fa fa-pencil-square" aria-hidden="true"></i> Slider Adı</td>
            <td class="col-md-7">
              <select name="silinecekSlider" class="form-control">
                <?php
                  $slider_nesne->sliderListesi();
                ?>
              </select>
            </td>
          </tr>
         
            <tr>
            <td class="col-md-2"><input type="submit" value="Sil" class="btn btn-danger btn-sm" onclick="if(!confirm('Bunu yapmak istediğinize emin misiniz?')){return false;}"></td>
          </tr>

        </table>
        </form>
             <a href="giris.php" class="btn btn-info" role="button" style="float: right;"><i class="glyphicon glyphicon-backward"></i> &nbsp; Geri</a>


        </div>
      </div>
    </div>


  </body>
</html>
