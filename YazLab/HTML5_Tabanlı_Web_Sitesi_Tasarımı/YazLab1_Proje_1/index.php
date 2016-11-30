
<?php
 require_once("kullanici.php");
 require_once("veritabani.php");

 
 $anasayfaDuyurulariGoster = new kullaniciBilgisi();
 ?>

<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="favicon.ico">

    <title>Bilgisayar Mühendisliği</title>

    <!-- Bootstrap Core CSS -->
    <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

    <!-- Theme CSS -->
    <link href="css/freelancer.min.css" rel="stylesheet">
    <!-- YazLab1 CSS -->
    <link href="css/yazlab.css" rel="stylesheet">
    <!-- Custom Fonts -->
    <link href="vendor/font-awesome/css/font-awesome.min.css" rel="stylesheet" type="text/css">
    <link href="https://fonts.googleapis.com/css?family=Montserrat:400,700" rel="stylesheet" type="text/css">
    <link href="https://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic" rel="stylesheet" type="text/css">

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->

</head>

<body id="page-top " class="index">


    <!-- Navigation -->
    <nav id="mainNav" class="navbar navbar-default navbar-fixed-top navbar-custom">
        <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header page-scroll">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span> Menu <i class="fa fa-bars"></i>
                </button>
                <a class="navbar-brand" href="#page-top">Bilgisayar Mühendisliği</a>
            </div>

            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav navbar-right">
                    <li class="hidden">
                        <a href="#page-top"></a>
                    </li>
                    <li class="page-scroll">
                        <a href="#portfolio">Genel</a>
                    </li>
                    <li class="page-scroll">
                        <a href="#bolumduyuru">Bölüm</a>
                    </li>
                    <li class="dropdown">
                      <a href="#" class="dropdown-toggle" data-toggle="dropdown">Araştırma<b class="caret"></b></a>
                      <ul class="dropdown-menu">
                        <li><a href="http://embedded.kocaeli.edu.tr/">EmbedSysLab</a></li>
                        <li><a href="http://yapbenzet.kocaeli.edu.tr/">YapBenzet</a></li>
                        <li><a href="http://ibel.kocaeli.edu.tr/">İBEL</a></li>
                        <li><a href="http://bilgisayar.kocaeli.edu.tr/akilli_sistemler_lab/">ASİST</a></li>
                        <li><a href="http://bilgisayar.kocaeli.edu.tr/comnet/">COMNET</a></li>
                      </ul>
                    </li>
                    <li class="dropdown">
                      <a href="#" class="dropdown-toggle" data-toggle="dropdown">Personel<b class="caret"></b></a>
                      <ul class="dropdown-menu">
                        <li><a href="personel.php#portfolio">Öğretim Üyeleri</a></li>
                        <li><a href="#">Öğretim Elemanları</a></li>
                        <li><a href="#">İdari Personel</a></li>
                        <li><a href="anaSay.php">SİSTEME GİRİŞ</a></li>
                      </ul>
                    </li>
                </ul>
            </div>
            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container-fluid -->
    </nav>


 <div class="container "  style="margin-top:130px" >
<div id="myCarousel col-xs-11 col-md-11" class="carousel slide " data-ride="carousel">
      <div class="carousel-inner" role="listbox" >
       
       <?php $anasayfaDuyurulariGoster->sliderOlustur(); ?>
      
      </div>
      <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
        <span class="sr-only">Geri</span>
      </a>
      <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
        <span class="sr-only">İleri</span>
      </a>
    </div>
      </div>

    <section class="success" id="bolumduyuru">
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
    </section>

    <!-- Contact Section -->
   
    <!-- Footer -->
    <footer class="text-center">
        <div class="footer-above">
            <div class="container">
                <div class="row">
                    <div class="footer-col col-md-4">
                        <h3>Adres</h3>
                        <p>KOÜ Mühendislik Fakültesi (B Blok) Bilgisayar Mühendisliği
                            <br>Umuttepe Yerleşkesi 41380 Kocaeli</p>
                    </div>
                    <div class="footer-col col-md-4">
                        <h3>BİZİ TAKİP EDİN</h3>
                        <ul class="list-inline">
                            <li>
                                <a href="https://www.facebook.com/kocaeliuni1992" class="btn-social btn-outline"><i class="fa fa-fw fa-facebook"></i></a>
                            </li>
                            <li>
                                <a href="https://plus.google.com/+kocaeli%C3%BCniversitesi" class="btn-social btn-outline"><i class="fa fa-fw fa-google-plus"></i></a>
                            </li>
                            <li>
                                <a href="https://twitter.com/kocaeliuni1992" class="btn-social btn-outline"><i class="fa fa-fw fa-twitter"></i></a>
                            </li>
                            <li>
                                <a href="https://instagram.com/kocaeliuni1992" class="btn-social btn-outline"><i class="fa fa-fw fa-instagram"></i></a>
                            </li>
                            <li>
                                <a href="https://www.youtube.com/c/kocaeli%C3%BCniversitesi" class="btn-social btn-outline"><i class="fa fa-fw fa-youtube"></i></a>
                            </li>
                        </ul>
                    </div>
                    <div class="footer-col col-md-4">
                        <h3>İLETİŞİM</h3>
                        <p>Tel: +90 (262) 303 35 60 <br>Web: <a href="http://bilgisayar.kocaeli.edu.tr">http://bilgisayar.kocaeli.edu.tr</a><br>E-Posta: <a href="mailto:bilgisayar@kocaeli.edu.tr">bilgisayar@kocaeli.edu.tr</a></p>
                    </div>
                </div>
            </div>
        </div>
        <div class="footer-below">
            <div class="container">
                <div class="row">
                    <div class="col-lg-12">
                        &copy; 2016 Kocaeli Üniversitesi. Bütün hakları saklıdır
                    </div>
                </div>
            </div>
        </div>
    </footer>

    <!-- Scroll to Top Button (Only visible on small and extra-small screen sizes) -->
    <div class="scroll-top page-scroll hidden-sm hidden-xs hidden-lg hidden-md">
        <a class="btn btn-primary" href="#page-top">
            <i class="fa fa-chevron-up"></i>
        </a>
    </div>


    <!-- jQuery -->
    <script src="vendor/jquery/jquery.min.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="vendor/bootstrap/js/bootstrap.min.js"></script>

    <!-- Plugin JavaScript -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js"></script>

    <!-- Contact Form JavaScript -->
    <script src="js/jqBootstrapValidation.js"></script>
    <script src="js/contact_me.js"></script>

    <!-- Theme JavaScript -->
    <script src="js/freelancer.min.js"></script>

    <!-- SliceBox -->
    <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
    <script type="text/javascript" src="slicebox/js/jquery.slicebox.js"></script>
    <script>
    $('.carousel').carousel({
        interval: 5000 //changes the speed
    })
        </script>

</body>

</html>
