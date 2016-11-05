/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

import javax.swing.JOptionPane;

public class Personel {
	private String ad;
	private String soyad;
	private long kimlikNo;
	protected int maas;

	Personel() {
		this("RastgeleAd", "RastgeleSoyad", 10000000146L, 1499);
	}

	Personel(String ad, String soyad, long kimlikNo, int maas) {
		setAd(ad);
		setSoyad(soyad);
		setKimlikNo(kimlikNo);
		setMaas(maas);
	}

	public String getAd() {
		return ad;
	}

	public void setAd(String ad) {
		while (ad.equals("")) {
			JOptionPane.showMessageDialog(null, "Ad Hatali Giris " + ad, "Personel Ad Hatali Giris",
					JOptionPane.ERROR_MESSAGE);
			ad = JOptionPane.showInputDialog(null, "Ad Giriniz: ", "Personel Ad Girisi", JOptionPane.QUESTION_MESSAGE);
		}
		this.ad = ad;
	}

	public String getSoyad() {
		return soyad;
	}

	public void setSoyad(String soyad) {
		while (soyad.equals("")) {
			JOptionPane.showMessageDialog(null, "Soyad Hatali Giris " + soyad, "Personel Soyad Hatali Giris",
					JOptionPane.ERROR_MESSAGE);
			soyad = JOptionPane.showInputDialog(null, "Soyad Giriniz: ", "Personel Soyad Girisi",
					JOptionPane.QUESTION_MESSAGE);
		}
		this.soyad = soyad;
	}

	public long getKimlikNo() {
		return kimlikNo;
	}

	public void setKimlikNo(long kimlikNo) {
		while (kimlikNo < 10000000000L || kimlikNo > 99999999999L) {
			JOptionPane.showMessageDialog(null, "Kimlik No Hatali Giris: " + kimlikNo,
					"Personel Kimlik No Hatali Giris", JOptionPane.ERROR_MESSAGE);
			kimlikNo = Long.parseLong(JOptionPane.showInputDialog(null, "Kimlik No Giriniz: ",
					"Personel Kimlik No Girisi", JOptionPane.QUESTION_MESSAGE));
		}
		this.kimlikNo = kimlikNo;
	}

	public int getMaas() {
		return maas;
	}

	public void setMaas(int maas) {
		while (maas < 1000 || maas > 1500) {
			JOptionPane.showMessageDialog(null, ad + " " + soyad + " Maasi Hatali Giris: " + maas, "Personel Maas Hatali Giris",
					JOptionPane.ERROR_MESSAGE);
			maas = Integer.parseInt(
					JOptionPane.showInputDialog(null, ad + " " + soyad + " Maas Giriniz: ", "Maas Girisi", JOptionPane.QUESTION_MESSAGE));
		}
		this.maas = maas;
	}
	
	public void bilgiYaz(){
		System.out.println("Adi: " + getAd());
		System.out.println("Soyadi: " + getSoyad());
		System.out.println("Kimlik No: " + getKimlikNo());
		System.out.println("Maas Miktari: " + getMaas());
	}
}
