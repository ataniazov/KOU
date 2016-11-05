/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

public class BilgiIslemPersonel extends Personel {
	private int bonus;
	private String gorevTanimi;

	public BilgiIslemPersonel(String ad, String soyad, long kimlikNo, String gorevTanimi) {
		super(ad, soyad, kimlikNo, 1499);
		setGorevTanimi(gorevTanimi);

		// Karsilastirmak icin kucuk harfe cevir
		gorevTanimi = gorevTanimi.toLowerCase();

		if (gorevTanimi.equals("dba")) {
			setMaas(3000);
		} else if (gorevTanimi.equals("network")) {
			setMaas(2750);
		} else if (gorevTanimi.equals("software")) {
			setMaas(2500);
		}
	}

	public void bonusHesapla(int aylikMesaiSaat, int saatlikMesaiUcreti) {
		setBonus(aylikMesaiSaat * saatlikMesaiUcreti);
	}
	
	@Override
	public void setMaas(int maas) {
		super.maas = maas;
	}
	
	public int getBonus() {
		return bonus;
	}

	public void setBonus(int bonus) {
		this.bonus = bonus;
	}

	public String getGorevTanimi() {
		return gorevTanimi;
	}

	public void setGorevTanimi(String gorevTanimi) {
		this.gorevTanimi = gorevTanimi;
	}
	
	public void bilgiYaz(){
		System.out.println("\nBilgi Islem Personel Bilgileri:");
		super.bilgiYaz();
		System.out.println("Gorevi : " + getGorevTanimi());
		System.out.println("Bonus Miktari: " + getBonus());
	}
}