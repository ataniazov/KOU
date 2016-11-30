<?php

require_once('veritabani.php');

class kullaniciBilgisi
{	

	private $conn;
	
	public function __construct()
	{

		$Vtb = new Veritabani();
		$veri = $Vtb->VeriBaglanti();
		$this->conn = $veri;

    }
	
	public function sorguCalistir($sorgu)
	{
		$hazirla = $this->conn->prepare($sorgu);
		return $hazirla;
	}
	
	public function kayit($kullaniciAdi,$kullaniciEmail,$kullaniciSifre,$unvan)
	{
		try
		{
			$yeniSifre = password_hash($kullaniciSifre, PASSWORD_DEFAULT);
			
			$hazirla = $this->conn->prepare("INSERT INTO tablo(kullanici_adi_veri,kullanici_email_veri,kullanici_sifre_veri,kullanici_unvan_veri) 
		                                               VALUES(:kullaniciAdi, :kullaniciEmail, :kullaniciSifre,:kullanici_unvan_veri)");
												  
			$hazirla->bindparam(":kullaniciAdi", $kullaniciAdi);
			$hazirla->bindparam(":kullaniciEmail", $kullaniciEmail);
			$hazirla->bindparam(":kullaniciSifre", $yeniSifre);	
			$hazirla->bindparam(":kullanici_unvan_veri", $unvan);											  
				
			$hazirla->execute();	
			
			return $hazirla;	
		}
		catch(PDOException $e)
		{
			echo $e->getMessage();
		}				
	}

		public function guncelle($duyuru_id,$duyuruBasligi,$duyuruIcerigi)
	{
		try
		{
			$hazirla = $this->conn->prepare("UPDATE duyuru_tablo SET duyuru_basligi_veri=:duyuruBasligi, 
		                                               duyuru_icerigi_veri=:duyuruIcerigi 
													   WHERE duyuru_id_veri=:duyuru_id ");
			$hazirla->bindparam(":duyuruBasligi",$duyuruBasligi);
			$hazirla->bindparam(":duyuruIcerigi",$duyuruIcerigi);
			$hazirla->bindparam(":duyuru_id",$duyuru_id);
			$hazirla->execute();

		return true;	
		}
		catch(PDOException $e)
		{
			echo $e->getMessage();	
			return false;
		}
	}
	
		public function guncelleGenel($duyuru_id,$duyuruBasligi,$duyuruIcerigi)
	{
		try
		{
			$hazirla = $this->conn->prepare("UPDATE duyuru_tablo_genel SET duyuru_basligi_veri=:duyuruBasligi, 
		                                               duyuru_icerigi_veri=:duyuruIcerigi 
													   WHERE duyuru_id_veri=:duyuru_id ");
			$hazirla->bindparam(":duyuruBasligi",$duyuruBasligi);
			$hazirla->bindparam(":duyuruIcerigi",$duyuruIcerigi);
			$hazirla->bindparam(":duyuru_id",$duyuru_id);
			$hazirla->execute();

		return true;	
		}
		catch(PDOException $e)
		{
			echo $e->getMessage();	
			return false;
		}
	}
	public function profilGuncelle($kullaniciAdi,$kullaniciEmail,$kullaniciSifre)
	{
		try
		{
			$yeniSifre = password_hash($kullaniciSifre, PASSWORD_DEFAULT);
			
			$hazirla = $this->conn->prepare("UPDATE tablo SET kullanici_email_veri=:kullaniciEmail,
				kullanici_sifre_veri=:kullaniciSifre WHERE kullanici_adi_veri=:kullaniciAdi");
		                                              
											  
			$hazirla->bindparam(":kullaniciAdi", $kullaniciAdi);
			$hazirla->bindparam(":kullaniciEmail", $kullaniciEmail);
			$hazirla->bindparam(":kullaniciSifre", $yeniSifre);										  
			$hazirla->execute();	
			
			return $hazirla;	
		}
		catch(PDOException $e)
		{
			echo $e->getMessage();
		}				
	}

   public function duyuru_kayit($kullaniciIsim,$duyuruBasligi,$duyuruIcerigi)
  {
    try
    {
      
      $hazirla = $this->conn->prepare("INSERT INTO duyuru_tablo(kullanici_adi_veri,duyuru_basligi_veri,duyuru_icerigi_veri) 
                                                   VALUES( :kullaniciIsim, :duyuruBasligi, :duyuruIcerigi)");
      $hazirla->bindparam(":kullaniciIsim", $kullaniciIsim);                    
      $hazirla->bindparam(":duyuruBasligi", $duyuruBasligi);
      $hazirla->bindparam(":duyuruIcerigi", $duyuruIcerigi);
      $hazirla->execute();  
      
      return $hazirla;  
    }
    catch(PDOException $e)
    {
      echo $e->getMessage();
    }       
  }

   public function duyuru_kayit_genel($kullaniciIsim,$duyuruBasligi,$duyuruIcerigi)
  {
    try
    {
      
      $hazirla = $this->conn->prepare("INSERT INTO duyuru_tablo_genel(kullanici_adi_veri,duyuru_basligi_veri,duyuru_icerigi_veri) 
                                                   VALUES( :kullaniciIsim, :duyuruBasligi, :duyuruIcerigi)");
      $hazirla->bindparam(":kullaniciIsim", $kullaniciIsim);                    
      $hazirla->bindparam(":duyuruBasligi", $duyuruBasligi);
      $hazirla->bindparam(":duyuruIcerigi", $duyuruIcerigi);
      $hazirla->execute();  
      
      return $hazirla;  
    }
    catch(PDOException $e)
    {
      echo $e->getMessage();
    }       
  }

  	public function duyuruGoruntule($sorgu)
	{
		$hazirla = $this->conn->prepare($sorgu);
		$hazirla->execute();
	
		if($hazirla->rowCount()>0)
		{
			while($row=$hazirla->fetch(PDO::FETCH_ASSOC))
			{
				?>
                <tr class="alert-warning">
                <td ><?php print($row['duyuru_basligi_veri']); ?></td>
                <td ><?php print($row['duyuru_icerigi_veri']); ?></td>
                <td  align="center">
                <a href="duyuru_duzenle.php?edit_id=<?php print($row['duyuru_id_veri']); ?>"><i class="glyphicon glyphicon-edit"></i></a>&nbsp;Düzenle
                </td>
                <td align="center">
                <a href="duyuru_sil.php?delete_id=<?php print($row['duyuru_id_veri']); ?>"><i class="glyphicon glyphicon-remove-circle"></i></a>&nbsp;Sil
                </td>
                </tr>
                <?php
			}
		}

		
	}

	

	public function duyurulariGetir() {
		$hazirla = $this->conn->prepare("SELECT * FROM duyuru_tablo");
		$hazirla->execute();
	
		if($hazirla->rowCount()>0)
		{
			while($row=$hazirla->fetch(PDO::FETCH_ASSOC))
			{
				$id = $row['kullanici_adi_veri'];
				$kullaniciBilgileri = $this->conn->query("SELECT * FROM tablo WHERE kullanici_adi_veri = '$id'")->fetch(PDO::FETCH_ASSOC);
		        $unvan = $kullaniciBilgileri["kullanici_unvan_veri"];
				?>
					 <div class="panel panel-default">
    <div class="panel-heading" role="tab">
      <h4 class="panel-title">
        <a class="collapsed" role="button" data-toggle="collapse" data-parent="#accordion" href="#collapse<?php print($row['duyuru_id_veri']); ?>" aria-expanded="false" aria-controls="collapse">
          <?php print($row['duyuru_basligi_veri']); ?>
        </a>
		<br/><br/><strong>Yazar:</strong> <?php print($unvan); ?> <br>
		<strong>Tarih:</strong> <?php print(substr($row['duyuru_kayit_tarihi'], 0,10)); ?>
      </h4>
    </div>
    <div id="collapse<?php print($row['duyuru_id_veri']); ?>" class="panel-collapse collapse" role="tabpanel" aria-labelledby="heading">
      <div class="panel-body">
      <?php print($row['duyuru_icerigi_veri']); ?>
      </div>
    </div>
  </div>
				<?php
			}
		}

	}

	public function duyurulariGetir2() {
		$hazirla = $this->conn->prepare("SELECT * FROM duyuru_tablo_genel");
		$hazirla->execute();
	
		if($hazirla->rowCount()>0)
		{
			while($row=$hazirla->fetch(PDO::FETCH_ASSOC))
			{			$id = $row['kullanici_adi_veri'];
				$kullaniciBilgileri = $this->conn->query("SELECT * FROM tablo WHERE kullanici_adi_veri = '$id'")->fetch(PDO::FETCH_ASSOC);
		        $unvan = $kullaniciBilgileri["kullanici_unvan_veri"];
				?>
					 <div class="panel panel-default">
    <div class="panel-heading" role="tab">
      <h4 class="panel-title">
        <a class="collapsed" role="button" data-toggle="collapse" data-parent="#accordion" href="#duyurular<?php print($row['duyuru_id_veri']); ?>" aria-expanded="false" aria-controls="collapse">
          <?php print($row['duyuru_basligi_veri']); ?>
        </a>
		<br/><br/><strong>Yazar:</strong> <?php print($unvan); ?> <br>
		<strong>Tarih:</strong> <?php print(substr($row['duyuru_kayit_tarihi'], 0,10)); ?>
      </h4>
    </div>
    <div id="duyurular<?php print($row['duyuru_id_veri']); ?>" class="panel-collapse collapse" role="tabpanel" aria-labelledby="heading">
      <div class="panel-body">
      <?php print($row['duyuru_icerigi_veri']); ?>
      </div>
    </div>
  </div>
				<?php
			}
		}

	}



		public function IdAl($id)
	{
		$hazirla = $this->conn->prepare("SELECT * FROM duyuru_tablo WHERE duyuru_id_veri=:id");
		$hazirla->execute(array(":id"=>$id));
		$editRow=$hazirla->fetch(PDO::FETCH_ASSOC);
		return $editRow;
	}

		public function IdAl_genel($id)
	{
		$hazirla = $this->conn->prepare("SELECT * FROM duyuru_tablo_genel WHERE duyuru_id_veri=:id");
		$hazirla->execute(array(":id"=>$id));
		$editRow=$hazirla->fetch(PDO::FETCH_ASSOC);
		return $editRow;
	}
	
	public function sil($id)
	{
		$hazirla = $this->conn->prepare("DELETE FROM duyuru_tablo WHERE duyuru_id_veri=:id");
		$hazirla->bindparam(":id",$id);
		$hazirla->execute();
		return true;
	}

	public function sil_genel($id)
	{
		$hazirla = $this->conn->prepare("DELETE FROM duyuru_tablo_genel WHERE duyuru_id_veri=:id");
		$hazirla->bindparam(":id",$id);
		$hazirla->execute();
		return true;
	}

	public function giris($kullaniciAdi,$kullaniciEmail,$kullaniciSifre)
	{
		try
		{
			$hazirla = $this->conn->prepare("SELECT kullanici_id_veri, kullanici_adi_veri, kullanici_email_veri, kullanici_sifre_veri 
				FROM tablo WHERE 
				kullanici_adi_veri=:kullaniciAdi OR kullanici_email_veri=:kullaniciEmail ");
			$hazirla->execute(array(':kullaniciAdi'=>$kullaniciAdi, ':kullaniciEmail'=>$kullaniciEmail));
			$kullaniciData=$hazirla->fetch(PDO::FETCH_ASSOC);
			if($hazirla->rowCount() == 1)
			{
				if(password_verify($kullaniciSifre, $kullaniciData['kullanici_sifre_veri']))
				{
					$_SESSION['kullanici_session'] = $kullaniciData['kullanici_id_veri'];
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		catch(PDOException $e)
		{
			echo $e->getMessage();
		}
	}
	
	public function girisYapildi()
	{
		if(isset($_SESSION['kullanici_session']))
		{
			return true;
		}
	}
	
	public function sesYer($url)
	{
		header("Location: $url");
	}
	
	public function cikis()
	{
		session_destroy();
		unset($_SESSION['kullanici_session']);
		return true;
	}



	public function sliderGoruntule() {
		$sliderListe = $this->conn->prepare("SELECT * FROM slider");
		$sliderListe->execute();
		$sliderListe->fetch(PDO::FETCH_ASSOC);

	}

	public function sliderOlustur() {
			$hazirla = $this->conn->prepare("SELECT * FROM slider");
		$hazirla->execute();
		$sayac =0;
		if($hazirla->rowCount()>0)
		{
			while($row=$hazirla->fetch(PDO::FETCH_ASSOC))
			{
				if($sayac == 0)
				{
					?>
					<div class="item active">
					      <img src="slicebox/slider/<?php print($row['resim']); ?>" alt="">
					      <div class="carousel-caption">
					       <?php print($row['sliderMetni']); ?>
					      </div>
					    </div>
					<?php
					$sayac++;
				}
				else {
					?>
					 <div class="item">
					      <img src="slicebox/slider/<?php print($row['resim']); ?>" alt="">
					      <div class="carousel-caption">
					       <?php print($row['sliderMetni']); ?>
					      </div>
					    </div>
					<?php
				}
			}
		}
	}
	public function sliderListesi() {
			$hazirla = $this->conn->prepare("SELECT * FROM slider");
		$hazirla->execute();
	
		if($hazirla->rowCount()>0)
		{
			while($row=$hazirla->fetch(PDO::FETCH_ASSOC))
			{
				?>
					<option value="<?php print($row['ID']); ?>"><?php print($row['sliderAdi']); ?></option>
				<?php
			}
		}
	}
		
	public function sliderKaydet($sliderAdi,$sliderMetni,$sliderResmi) {
		    $hazirla=$this->conn->prepare("INSERT INTO slider(sliderAdi,sliderMetni,resim) VALUES(:sliderAdi , :sliderMetni , :sliderResmi )");

			$hazirla->bindparam(":sliderAdi", $sliderAdi);
			$hazirla->bindparam(":sliderMetni", $sliderMetni);
			$hazirla->bindparam(":sliderResmi", $sliderResmi);										  
			$hazirla->execute();	
	}

		public function sliderSil($id) {
		$hazirla = $this->conn->prepare("DELETE FROM slider WHERE ID=:id");
		$hazirla->bindparam(":id",$id);
		$hazirla->execute();
		return true;	
	}


			public function sliderId($id)
	{
		$hazirla = $this->conn->prepare("SELECT * FROM slider WHERE ID=:id");
		$hazirla->execute(array(":id"=>$id));
		$editRow=$hazirla->fetch(PDO::FETCH_ASSOC);
		return $editRow;
	}



			public function kontrol_bolum()
	{
        return true;

		}

			public function kontrol_genel()
	{
          return true;

		}

	public function slider() {
		

		$sliderListe = $this->conn->prepare("SELECT * FROM slider");
		$sliderListe->execute();

		$sayac = 0;
		while ($res = $sliderListe->fetch(PDO::FETCH_ASSOC)) {
			if($sayac == 0) {
				echo "<div class='item active'>";
				$sayac++;
			}
			else {
				echo "<div class='item'>";
			}
			echo "<img src='slicebox/slider/".$res['resim']."'>
          <div class='container'>
            <div class='carousel-caption'>
              <h1>".$res['sliderAdi']."</h1>
              <p>".$res['sliderMetni']."</p>
            </div>
          </div>
        </div>";
		}
	}



}
?>