<?php
 require_once("kullanici.php");
 require_once("veritabani.php");
 $anasayfaDuyurulariGoster = new kullaniciBilgisi();
 ?>
<!DOCTYPE html>
<html lang="tr">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="../../favicon.ico">

    <title>Kocaeli Üniversitesi Bilgisayar Mühendisliği</title>

    <!-- Bootstrap core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">


    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->

    <!-- Custom styles for this template -->
    <link href="css/carousel.css" rel="stylesheet">
  </head>
<!-- NAVBAR
================================================== -->
  <body>
    <div class="navbar-wrapper">
      <div class="container">

       <nav class="navbar navbar-default navbar-fixed-top">
        <div class="container-fluid">
        <!-- Brand and toggle get grouped for better mobile display -->
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          </button>
        </div>

        <!-- Collect the nav links, forms, and other content for toggling -->
        <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
          <ul class="nav navbar-nav">
          <li><a href="anasayfa.php">Anasayfa</a></li>
          <li class="dropdown">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown">Hakkımızda <span class="caret"></span></a>
            <ul class="dropdown-menu" role="menu">
            <li><a href="#">Tarihçe</a></li>
            <li><a href="#">Hakkımızda</a></li>
            <li><a href="#">Misyon</a></li>
            <li><a href="#">Vizyon</a></li>
            <li><a href="#">Ana Bilim Dalları</a></li>
            <li><a href="#">Program Çıktıları</a></li>
<!--          <li><a href="galeri.php">Fotoğraf Galerisi</a></li>  -->
            </ul>
          </li>
          <li><a href="#">Yönetim</a></li>
          <li class="dropdown">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown">Araştırma <span class="caret"></span></a>
            <ul class="dropdown-menu" role="menu">
            <li><a href="http://bilgisayar.kocaeli.edu.tr/akilli_sistemler_lab/"  target="_blank">Akıllı Sistemler Araştırma Laboratuvarı</a></li>
            <li><a href="http://bilgisayar.kocaeli.edu.tr/comnet" target="_blank">Bilgisayar Ağları ve Haberleşme Araştırma Laboratuvarı</a></li>
            <li><a href="http://embedded.kocaeli.edu.tr/" target="_blank">Gömülü ve Algılayıcı Sistemler Araştırma Laboratuvarı</a></li>
            <li><a href="http://ipcv.kocaeli.edu.tr/" target="_blank">Görüntü İşleme Araştırma Laboratuvarı</a></li>
            <li><a href="http://ibel.kocaeli.edu.tr/" target="_blank">İnsan Bilgisayar Etkileşimi Araştırma Laboratuvarı</a></li>
            <li><a href="http://yapbenzet.kocaeli.edu.tr/" target="_blank">Yapay Zeka ve Benzetim Sistemleri Araştırma Laboratuvarı</a></li>
            <li><a href="#">Projeler</a></li>
            </ul>
          </li>
          <li class="dropdown">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown">Personel <span class="caret"></span></a>
            <ul class="dropdown-menu" role="menu">
            <li><a href="#">Öğretim Üyeleri</a></li>
            <li><a href="#">Öğretim Elemanları</a></li>
            <li><a href="#">İdari Personel</a></li>
            <li><a href="index.php">Sisteme Giriş</a></li>


            

            </ul>
          </li>
          <li class="dropdown">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown">Lisans <span class="caret"></span></a>
            <ul class="dropdown-menu" role="menu">
            <li><a href="#" target="_blank">Öğrenci Dilekçe ve Formları</a></li>
            <li><a href="#" target="_blank">Ders Planı</a></li>
            <li><a href="#">Ders İçerikleri</a></li>
                <li><a href="#">Ders Programı</a></li>
                <li><a href="#">Akademik Danışmanlar</a></li>
            <li><a href="#">İntibak Öğrencileri</a></li>
            <li><a href="#">Aday Öğrenciler</a></li>
            <li><a href="#">Araştırma Problemleri ve Bitirme</a></li>
            <li><a href="#">Akademik Takvim</a></li>
            <li><a href="#">MÜDEK</a></li>
            <li><a href="#">Diploma Sorgulama</a></li>            
            <li><a href="#">Staj</a></li>  
                
            </ul>
          </li>
          <li class="dropdown" >
            <a href="#" class="dropdown-toggle" data-toggle="dropdown">Y.Lisans / Doktora <span class="caret"></span></a>
            <ul class="dropdown-menu" role="menu">
            <li><a href="#">Çalışma Alanları</a></li>
            <li><a href="#" target="_blank">Ders Listesi</a></li>
            <li><a href="#" target="_blank">Ders Programı</a></li>
            <li><a href="#">Tezler</a></li>

            </ul>
          </li>
          <li><a href="#" target="_blank">Mezunlar</a></li>
          <li><a href="#">İletişim/Ulaşım</a></li>
          <li><a href="#">3DNavi</a></li>         
          </ul>

        </div><!-- /.navbar-collapse -->
        </div><!-- /.container-fluid -->
      </nav>

      </div>
    </div>

    <div id="myCarousel" class="carousel slide" data-ride="carousel">
      <div class="carousel-inner" role="listbox">
       
       <?php $anasayfaDuyurulariGoster->sliderOlustur(); ?>
      
      </div>
      <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
        <span class="sr-only">Previous</span>
      </a>
      <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
        <span class="sr-only">Next</span>
      </a>
    </div>

    <div class="container">

    
     
      <div class="row well">
        <div class="col-md-6">
      <div class="panel-group" id="accordion" role="tablist" aria-multiselectable="true">
      <div class="alert alert-info">Bölüm Duyuruları</div>
       <?php $anasayfaDuyurulariGoster->duyurulariGetir(); ?>
      </div>
    </div>
    <div class="col-md-6">
      <div class="panel-group" id="accordion" role="tablist" aria-multiselectable="true">
      <div class="alert alert-info">Genel Duyurular</div>
       <?php $anasayfaDuyurulariGoster->duyurulariGetir2(); ?>
      </div>
    </div>
</div>
<script src="bootstrap/js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="bootstrap/js/bootstrap.min.js"></script>

    <!-- Script to Activate the Carousel -->
    <script>
    $('.carousel').carousel({
        interval: 5000 //changes the speed
    })
    </script>

      <!-- FOOTER -->
      <footer>
          <p>Adres: KOÜ Mühendislik Fakültesi (B Blok) Bilgisayar Mühendisliği Umuttepe Yerleşkesi 41380 Kocaeli<br>
          Tel: +90 (262) 303 35 60<br>
          E-Posta: bilgisayar@kocaeli.edu.tr<br> 
          Web: http://bilgisayar.kocaeli.edu.tr 
                    <br>
                  Web  istek görüş ve önerileriniz için : <a href="http://akademikpersonel.kocaeli.edu.tr/binner/">A. Burak İNNER</a> / <a href="http://akademikpersonel.kocaeli.edu.tr/hikmetcan.ozcan/">Hikmetcan ÖZCAN </a></p>
        </footer>

    </div><!-- /.container -->


  </body>
</html>
