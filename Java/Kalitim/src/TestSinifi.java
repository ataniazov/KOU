/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

public class TestSinifi {

	public static void main(String[] args) {
		
		System.out.println("=====================\n| Test Sinifi Giris |\n=====================\n");

		Personel personelObject1 = new Personel();
		personelObject1.bilgiYaz();
		System.out.println();

		Personel personelObject2 = new Personel("Ali", "Yıldırım", 12345678901L, 1000);
		personelObject2.bilgiYaz();

		Stajyer stajyerObject1 = new Stajyer();
		stajyerObject1.bilgiYaz();
		
		Stajyer stajyerObject2 = new Stajyer();
		stajyerObject2.bilgiYaz();
		
		SatisPersonel satisPersonelObject1 = new SatisPersonel();
		satisPersonelObject1.aylikSatis(100, 4);
		satisPersonelObject1.bilgiYaz();
		
		BilgiIslemPersonel bilIslemPerObject1 = new BilgiIslemPersonel("Mehmet", "Koç", 12345678902L, "DBA");
		bilIslemPerObject1.bonusHesapla(8, 17);
		bilIslemPerObject1.bilgiYaz();

		BilgiIslemPersonel bilIslemPerObject2 = new BilgiIslemPersonel("Mustafa", "Öztürk", 12345678903L, "Network");
		bilIslemPerObject2.bonusHesapla(14, 15);
		bilIslemPerObject2.bilgiYaz();

		BilgiIslemPersonel bilIslemPerObject3 = new BilgiIslemPersonel("Zehra", "Yıldız", 12345678904L, "Software");
		bilIslemPerObject3.bilgiYaz();

		BilgiIslemPersonel bilIslemPerObject4 = new BilgiIslemPersonel("Hatice", "Aydın", 12345678905L, "Personel");
		bilIslemPerObject4.bilgiYaz();

		
		System.out.println("\n=====================\n| Test Sinifi Cikis |\n=====================");
	}

}
