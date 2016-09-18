#include <stdio.h>
#include <stdlib.h>

struct Takvim {
	int yil;
	int ay;
	int hafta;
	int gun;
};

struct Zaman {
	int saat;
	int dakika;
	int saniye;
};

/**
 * Kullanilacak Fonksiyonlar
 */
int ana_menu();
void dev_mode();


int main() {

	return ana_menu();

}

int ana_menu() {


	char ana_menu_secim = '\0';

	while(ana_menu_secim != 'Q') {

		system("clear");

		printf("ANA MENU\n--------\n");

		printf("[A] Hatirlatmalar\n");
		printf("\n[Q] EXIT\n");

		ana_menu_secim = '\0';

		printf("\n");

		printf("Seciminiz: ");
		scanf(" %c",&ana_menu_secim);

		switch(ana_menu_secim) {
			case 'A' : ; break;
			case 'Q' :{
					  printf("DUYURU: Cikis yapiyorum");
					  fflush(stdout);
					  system("sleep 1");
					  return 0;
				  } break;
			case '.' : dev_mode(); break;

			default :{
					 printf("DUYURU: HATALI SECIM!!!\n");
					 fflush(stdout);
					 system("sleep 2");
				 }
		}
	}
}


/**
 *Gelistirme moduna girmek icin ANA MENUDAN "." seciniz.
 */
void dev_mode() {

	char dev_mode_secim = '\0';

	while(dev_mode_secim != 'B') {

		system("clear");

		printf("DEVELOPER MODE\n--------------\n");

		printf("[A] TEST 1\n");
		printf("\n[B] ANA MENU'YA GERI DON\n");

		dev_mode_secim = '\0';

		printf("\n");

		printf("Seciminiz: ");
		scanf(" %c",&dev_mode_secim);

		switch(dev_mode_secim) {
			case 'A' :{
					  printf("Test 1\n");
				  } break;

			case 'B' :{
					  printf("DUYURU: Ana menu'ya geri donuyorum\n");
					  fflush(stdout);
					  system("sleep 2");
				  } break;

			default :{
					 printf("DUYURU: HATALI SECIM!!!\n");
					 fflush(stdout);
					 system("sleep 2");
				 }
		}
	}
}
