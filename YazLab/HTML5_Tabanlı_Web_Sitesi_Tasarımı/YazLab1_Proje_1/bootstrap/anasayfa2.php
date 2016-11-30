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
    <title>Kocaeli Üniversitesi Bilgisayar Mühendisliği</title>
    <!-- Bootstrap -->
    <link href="bootstrap/css/bootstrap.min.css" rel="stylesheet">
	    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
      <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="bootstrap/js/bootstrap.min.js"></script>
    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
  </head>
  <body>
  
  <!-- Navbar başlangıc -->
  <div class="navbar-wrapper">
  <div class="container">
    <div class="navbar navbar-inverse navbar-static-top">
      
        <div class="navbar-header">
	    <a class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
	      <span class="icon-bar"></span>
	      <span class="icon-bar"></span>
	      <span class="icon-bar"></span>
	    </a>
        </div>
        <div class="navbar-collapse collapse">
          <ul class="nav navbar-nav">
            <li class="active"><a href="#">Ana Sayfa</a></li>
            <li><a href="#">Hakkımızda</a></li>
                <li class="dropdown">
                  <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">Yönetim <span class="caret"></span></a>
                  <ul class="dropdown-menu">
                    <li><a href="index.php">Yönetici Girişi</a></li>
                  </ul>
                </li>
            <li><a href="#">Araştırma</a></li>
            <li><a href="#">Personel</a></li>
            <li><a href="#">Lisans</a></li>
			      <li><a href="#">Y.Lisan/Doktora</a></li>
            <li><a href="#">Mezunlar</a></li>
            <li><a href="#">İletişim</a></li>
            <li><a href="#">3DNavi</a></li>
			      <li><a href="#">English</a></li>
              </ul>
            </li>
          </ul>
        </div>

    </div>
  </div>
</div>
    <!-- Navbar bitiş -->
  
  


	  <!-- slide başlangıc -->
  <div class="container">       


  <?php $anasayfaDuyurulariGoster->sliderOlustur(); ?>
   
   
  </div>
  <!-- Controls -->
  <a class="left carousel-control" href="#carousel-example-generic" role="button" data-slide="prev">
    <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
    <span class="sr-only">Önceki</span>
  </a>
  <a class="right carousel-control" href="#carousel-example-generic" role="button" data-slide="next">
    <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    <span class="sr-only">Sonraki</span>
  </a>
</div>
</div>
  <!-- slide bitiş -->	
	
       <div class="container">
    	<br/><br/>
    	<div class="row">
        <div class="col-md-6">
			<div class="panel-group" id="accordion" role="tablist" aria-multiselectable="true">
			<!-- baslangıç -->
			<div class="alert alert-info">Bölüm Duyuruları</div>
			 <?php $anasayfaDuyurulariGoster->duyurulariGetir(); ?>
			<!-- bitiş -->
			</div>
		</div>
		<div class="col-md-6">
			<div class="panel-group" id="accordion" role="tablist" aria-multiselectable="true">
			<div class="alert alert-info">Genel Duyurular</div>
			 <?php $anasayfaDuyurulariGoster->duyurulariGetir2(); ?>
			</div>
		</div>


</div>
    <!-- jQuery -->
    <script src="bootstrap/js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="bootstrap/js/bootstrap.min.js"></script>

    <!-- Script to Activate the Carousel -->
    <script>
    $('.carousel').carousel({
        interval: 5000 //changes the speed
    })
    </script>
<div class="panel-footer">
				  <p>Adres: KOÜ Mühendislik Fakültesi (B Blok) Bilgisayar Mühendisliği Umuttepe Yerleşkesi 41380 Kocaeli<br>
					Tel: +90 (262) 303 35 60<br>
					E-Posta: bilgisayar@kocaeli.edu.tr<br> 
					Web: http://bilgisayar.kocaeli.edu.tr 
                    <br>
                  Web  istek görüş ve önerileriniz için : <a href="http://akademikpersonel.kocaeli.edu.tr/binner/">A. Burak İNNER</a> / <a href="http://akademikpersonel.kocaeli.edu.tr/hikmetcan.ozcan/">Hikmetcan ÖZCAN </a></p>
			  </div>
</div>
  <!-- panel bitiş -->
  


  </body>
</html>