/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

public class SatisPersonel extends Personel {
	private int bonus;

	public int aylikSatis(int satisMiktari, int birimFiyat) {
		setBonus(satisMiktari * birimFiyat);
		return (super.maas + bonus);
	}
	
	public int getBonus() {
		return bonus;
	}

	public void setBonus(int bonus) {
		this.bonus = bonus;
	}
	
	public void bilgiYaz(){
		System.out.println("\nSatis Personel Bilgileri:");
		super.bilgiYaz();
		System.out.println("Bonus Miktari: " + getBonus());
		System.out.println("Aylik Satis Toplam Maasi: " + (super.maas + getBonus()));
	}
}
