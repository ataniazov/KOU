/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

public class OgrenciTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Ogrenci ogrenci1 = new Ogrenci("Fatma", "Karaca", "Bilgisayar Muhendisligi", "Programlama");
		System.out.println(ogrenci1.getNoSayac());
		
		Ogrenci ogrenci2 = new Ogrenci("Ayse", "Yilmaz", "Makina Muhendisligi", "Malzeme");
		System.out.println(ogrenci2.getNoSayac());

		Ogrenci ogrenci3 = new Ogrenci("Mustafa", "Ates", "Endüstri Mühendisliği", "Iktisat");
		System.out.println(ogrenci3.getNoSayac());

		Ogrenci ogrenci4 = new Ogrenci("Serdar", "Solak", "Enformatik", "Java Programlama");
		System.out.println(ogrenci4.getNoSayac());
		
		ogrenci1.ortalamaHesapla(55, 43);
		ogrenci2.ortalamaHesapla(65, 53);
		ogrenci3.ortalamaHesapla(60, 70);
		ogrenci4.ortalamaHesapla(100, 100);
		
		System.out.println(ogrenci1.getNo() + ". " + ogrenci1.getAd() + ", " + ogrenci1.getSoyad() + ", " + ogrenci1.getBolum() + ", " + ogrenci1.getDersAdi() + ", " + ogrenci1.getOrtalamaNot() + ", " + ogrenci1.harfCevir());
		System.out.println(ogrenci2.getNo() + ". " + ogrenci2.getAd() + ", " + ogrenci2.getSoyad() + ", " + ogrenci2.getBolum() + ", " + ogrenci2.getDersAdi() + ", " + ogrenci2.getOrtalamaNot() + ", " + ogrenci2.harfCevir());
		System.out.println(ogrenci3.getNo() + ". " + ogrenci3.getAd() + ", " + ogrenci3.getSoyad() + ", " + ogrenci3.getBolum() + ", " + ogrenci3.getDersAdi() + ", " + ogrenci3.getOrtalamaNot() + ", " + ogrenci3.harfCevir());
		System.out.println(ogrenci4.getNo() + ". " + ogrenci4.getAd() + ", " + ogrenci4.getSoyad() + ", " + ogrenci4.getBolum() + ", " + ogrenci4.getDersAdi() + ", " + ogrenci4.getOrtalamaNot() + ", " + ogrenci4.harfCevir());

		System.out.println(ogrenci1.getNoSayac());
	}

}
