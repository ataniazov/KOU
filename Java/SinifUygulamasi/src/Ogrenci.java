/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

public class Ogrenci {
	//no, ad,soyad,bolum, dersadi, ortalamaNot ve harfNotu
	
	private static int noSayac = 0;
	private int no = 0;

	private String ad = null;
	private String soyad = null;
	private String bolum = null;
	private String dersadi = null;

	private int ortalamaNot = 0;
	private String harfNotu = null;
		
	Ogrenci(String _ad, String _soyad, String _bolum, String _dersadi){
		ad = _ad;
		soyad = _soyad;
		bolum = _bolum;
		dersadi = _dersadi;
		
		no = ++noSayac;
	}
	
	public void ortalamaHesapla(int vizeNotu, int finalNotu){
		ortalamaNot = (int) ((vizeNotu * 0.4) + (finalNotu * 0.6));		
	}
	
	public String harfCevir(){
		
		if (ortalamaNot >= 65 && ortalamaNot <= 100) {
			if (ortalamaNot >= 90 && ortalamaNot <= 100) {
				harfNotu = "AA";
			} else if (ortalamaNot >= 85 && ortalamaNot <= 89) {
				harfNotu = "BA";
			} else if (ortalamaNot >= 80 && ortalamaNot <= 84) {
				harfNotu = "BB";
			} else if (ortalamaNot >= 75 && ortalamaNot <= 79) {
				harfNotu = "CB";
			} else if (ortalamaNot >= 65 && ortalamaNot <= 74) {
				harfNotu = "CC";
			}
		} else if (ortalamaNot >= 0 && ortalamaNot <= 64) {
			if (ortalamaNot >= 58 && ortalamaNot <= 64) {
				harfNotu = "DC";
			} else if (ortalamaNot >= 50 && ortalamaNot <= 57) {
				harfNotu = "DD";
			} else if (ortalamaNot >= 40 && ortalamaNot <= 49) {
				harfNotu = "FD";
			} else if (ortalamaNot <= 39) {
				harfNotu = "FF";
			}
		}
		return harfNotu;
	}
	
	public int getNo(){
		return no;
	}
	public int getNoSayac(){
		return noSayac;
	}
	public String getAd(){
		return ad;
	}
	public String getSoyad(){
		return soyad;
	}
	public String getBolum(){
		return bolum;
	}
	public String getDersAdi(){
		return dersadi;
	}
	public int getOrtalamaNot(){
		return ortalamaNot;
	}
}