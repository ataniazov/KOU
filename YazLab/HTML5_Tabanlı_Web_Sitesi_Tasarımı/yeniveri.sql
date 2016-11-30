-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Anamakine: 127.0.0.1
-- Üretim Zamanı: 29 Kas 2016, 12:22:28
-- Sunucu sürümü: 10.1.13-MariaDB
-- PHP Sürümü: 5.6.23

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `yeniveri`
--

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `duyuru_tablo`
--

CREATE TABLE `duyuru_tablo` (
  `duyuru_id_veri` int(11) NOT NULL,
  `kullanici_adi_veri` varchar(50) NOT NULL,
  `duyuru_basligi_veri` text NOT NULL,
  `duyuru_icerigi_veri` text NOT NULL,
  `duyuru_kayit_tarihi` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `duyuru_tablo`
--

INSERT INTO `duyuru_tablo` (`duyuru_id_veri`, `kullanici_adi_veri`, `duyuru_basligi_veri`, `duyuru_icerigi_veri`, `duyuru_kayit_tarihi`) VALUES
(174, 'a', 'Doktora Yeterlik SÄ±navÄ± Hk.', '<p>Doktora Yeterlik Ders ve KonularÄ± ekteki dosyada listelenmiÅŸtir. Muhtemel sÄ±nav tarihi 16 OCak 2017 haftasÄ±dÄ±r.</p>\r\n\r\n<p>Ek :&nbsp;<a href="http://bilgisayar.kocaeli.edu.tr/files/164_Doktora%20Yeterlik%20Ders%20Ve%20Konular.pdf" target="_blank">indir</a></p>\r\n', '2016-11-29 11:18:18'),
(175, 'a', 'DilekÃ§eler Hk.', 'Mazeret sÄ±navlarÄ±nÄ±n da dahil olduÄŸu t&uuml;m dilek&ccedil;elerin B&ouml;l&uuml;m SekreterliÄŸine verilmesi gerekmektedir.\r\n', '2016-11-29 11:18:39'),
(176, 'a', 'DanÄ±ÅŸmanlÄ±klar Ve Ã–ÄŸrenci Temsilcileri', 'SÄ±nÄ±f temsilcileri ve bolum temsilcisi ekte belirtildiÄŸi ÅŸekli ile se&ccedil;ilmiÅŸtir.Ä°lgili &ouml;renciler; eÄŸitim, saÄŸlÄ±k, spor ve k&uuml;lt&uuml;rel ihtiya&ccedil;larÄ±nÄ±n karÅŸÄ±lanmasÄ±nda diÄŸer &ouml;ÄŸrencilerin de g&ouml;r&uuml;ÅŸlerini belirleyerek, kendi sÄ±nÄ±fÄ±na ait akademik veya kayÄ±t danÄ±ÅŸmanÄ±na bildirilmesi ve y&ouml;netim organlarÄ± ile &ouml;ÄŸrenciler arasÄ±ndaki iletiÅŸimi oluÅŸturmaktan sorumludurlar.\r\n\r\n\r\nEk :&nbsp;indir\r\n', '2016-11-29 11:18:56');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `duyuru_tablo_genel`
--

CREATE TABLE `duyuru_tablo_genel` (
  `duyuru_id_veri` int(11) NOT NULL,
  `kullanici_adi_veri` varchar(50) NOT NULL,
  `duyuru_basligi_veri` text NOT NULL,
  `duyuru_icerigi_veri` text NOT NULL,
  `duyuru_kayit_tarihi` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `duyuru_tablo_genel`
--

INSERT INTO `duyuru_tablo_genel` (`duyuru_id_veri`, `kullanici_adi_veri`, `duyuru_basligi_veri`, `duyuru_icerigi_veri`, `duyuru_kayit_tarihi`) VALUES
(192, 'a', 'Bilgisayar AÄŸlarÄ± 30 KasÄ±m Dersi Hk', 'Ders 30 KasÄ±mda aÅŸaÄŸÄ±daki dersliklerde tek grup olarak yapÄ±lacaktÄ±r\r\n\r\nI. Ogretim 10:00--&gt; Mekatronik 201\r\nII. &Ouml;ÄŸretim 17:00--&gt; Jeoloji 105\r\n', '2016-11-29 11:17:56'),
(191, 'a', 'Prolab I Proje 1 NotlarÄ±', 'Notlar ektedir.\r\n\r\n\r\nEk :&nbsp;indir\r\n', '2016-11-29 11:17:34'),
(190, 'a', 'Netas Coop Staj BaÅŸvurularÄ± Ä°Ã§in MÃ¼lakat Tarihi', 'NetaÅŸ Coop staj i&ccedil;in m&uuml;lakat b&ouml;l&uuml;m 3042 nolu b&ouml;l&uuml;m seminer odasÄ±nda yapÄ±lacaktÄ±r. M&uuml;lakata katÄ±lacak kiÅŸiler ve program ektedir.&nbsp;\r\nM&uuml;lakat tarihi 1 AralÄ±k 2016 Saat 10\r\n\r\n\r\nEk :&nbsp;indir\r\n', '2016-11-29 11:17:00');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `slider`
--

CREATE TABLE `slider` (
  `ID` int(11) NOT NULL,
  `sliderAdi` text COLLATE utf8_turkish_ci NOT NULL,
  `sliderMetni` text COLLATE utf8_turkish_ci NOT NULL,
  `resim` text COLLATE utf8_turkish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `slider`
--

INSERT INTO `slider` (`ID`, `sliderAdi`, `sliderMetni`, `resim`) VALUES
(12, 'Ar-ge Proje PazarÄ± TÃ¼bitak Projesinde ÃœÃ§Ã¼ncÃ¼lÃ¼k Ã–dÃ¼lÃ¼', 'Ar-ge Proje PazarÄ± TÃ¼bitak Projesinde ÃœÃ§Ã¼ncÃ¼lÃ¼k Ã–dÃ¼lÃ¼', '30_SantekAna (1).jpg'),
(13, 'GÃ¶rÃ¼ntÃ¼ DÃ¶kÃ¼man Ä°ÅŸleme Semineri', 'GÃ¶rÃ¼ntÃ¼ DÃ¶kÃ¼man Ä°ÅŸleme Semineri Digiform Åžirketinden GÃ¼rkan KaragÃ¶z TarafÄ±ndan GÃ¶rÃ¼ntÃ¼ DÃ¶kÃ¼man Ä°ÅŸleme Ve Mobil TabanlÄ± GÃ¶rÃ¼ntÃ¼ Ä°ÅŸleme Ãœzerine 9 KasÄ±m Ã‡arÅŸamba GÃ¼nÃ¼ Saat 14.00-16.00 ArasÄ±nda Prof. Dr. SavaÅŸ Ayberk Konferans Salonunda Seminer Verilecektir.', '27_Goruntu_Dokumn.jpg'),
(14, 'PMI-TR ve Proje YÃ¶netimine GiriÅŸ TanÄ±tÄ±m EtkinliÄŸi', 'PMI-TR ve Proje YÃ¶netimine GiriÅŸ TanÄ±tÄ±m EtkinliÄŸi PMI (Project Magement Institute) TÃ¼rkiye Ve Kocaeli Ãœniversitesi iÅŸbirliÄŸi ile dÃ¼zenenecek PMI-TR ve Proje YÃ¶netimine GiriÅŸ Ve TanÄ±tÄ±m EtkinliÄŸine tÃ¼m Ã¶ÄŸrencilerimiz davetlidir. Yer: Prof. Dr. SavaÅŸ Ayberk Konferans Salonu Tarih: 10 KasÄ±m 2016 Saat: 14:00-17:00 KonuÅŸmacÄ±: A. BuÄŸu BayazÄ±t YÄ±ldÄ±rÄ±m', '238_PMI.jpg'),
(15, 'Yeni Nesil ', 'Yeni Nesil Giyilebilir Ã–deme Sistemleri ', '241_Bilg_Resim.jpg'),
(16, 'aaaa', 'aaaa', '177_kou_bil_slider_v1.jpg');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `tablo`
--

CREATE TABLE `tablo` (
  `kullanici_id_veri` int(11) NOT NULL,
  `kullanici_adi_veri` varchar(15) NOT NULL,
  `kullanici_email_veri` varchar(40) NOT NULL,
  `kullanici_sifre_veri` varchar(255) NOT NULL,
  `joining_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `kullanici_unvan_veri` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `tablo`
--

INSERT INTO `tablo` (`kullanici_id_veri`, `kullanici_adi_veri`, `kullanici_email_veri`, `kullanici_sifre_veri`, `joining_date`, `kullanici_unvan_veri`) VALUES
(40, 'z', 'a@a.com', '$2y$10$WLc0sX4cQgkVhO2/OODx2eV4i795zCm.dg5K1aUdh9l0bp46IunfK', '2016-11-25 08:14:02', 'a'),
(39, 'a', 'admin@admin.com', '$2y$10$yxET7CZmSptjRw61Xc8htemCfo1RfufWKhgn.U3cB2bBmhuI5F0Qy', '2016-11-13 18:24:52', 'BÃ¶lÃ¼m BaÅŸkanlÄ±ÄŸÄ±');

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `duyuru_tablo`
--
ALTER TABLE `duyuru_tablo`
  ADD PRIMARY KEY (`duyuru_id_veri`);

--
-- Tablo için indeksler `duyuru_tablo_genel`
--
ALTER TABLE `duyuru_tablo_genel`
  ADD PRIMARY KEY (`duyuru_id_veri`);

--
-- Tablo için indeksler `slider`
--
ALTER TABLE `slider`
  ADD PRIMARY KEY (`ID`);

--
-- Tablo için indeksler `tablo`
--
ALTER TABLE `tablo`
  ADD PRIMARY KEY (`kullanici_id_veri`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `duyuru_tablo`
--
ALTER TABLE `duyuru_tablo`
  MODIFY `duyuru_id_veri` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=177;
--
-- Tablo için AUTO_INCREMENT değeri `duyuru_tablo_genel`
--
ALTER TABLE `duyuru_tablo_genel`
  MODIFY `duyuru_id_veri` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=193;
--
-- Tablo için AUTO_INCREMENT değeri `slider`
--
ALTER TABLE `slider`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;
--
-- Tablo için AUTO_INCREMENT değeri `tablo`
--
ALTER TABLE `tablo`
  MODIFY `kullanici_id_veri` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
