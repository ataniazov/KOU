/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

public class Stajyer extends Personel {
	Stajyer() {
		super();
		setMaas(300);
	}
	
	Stajyer(String ad, String soyad, long kimlikNo){
		super(ad, soyad, kimlikNo, 1000);
		setMaas(300);
	}

	@Override
	public void setMaas(int maas) {
		super.maas = maas;
	}
	
	public void bilgiYaz(){
		System.out.println("\nStajyer Bilgileri:");
		super.bilgiYaz();
	}
}
