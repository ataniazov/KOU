/*
 * C'de Ogrenci bilgi sistemi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Tarih {
	unsigned short gun;
	unsigned short ay;
	unsigned short yil;
};


typedef struct {
	char ad[21];
	char soyad[21];
	char bolum[41];
	char no[10];

	struct Tarih dogum_yili;
	struct Tarih kayit_tarih;

	char mevcut;
} Ogrenci;

struct Tarih tarih_olustur();

void ogr_olustur(Ogrenci * ogr_dizi, unsigned int * ogr_sayisi);
void ogr_listele(const Ogrenci * ogr_dizi, unsigned int ogr_sayisi);

int ogr_oku(const Ogrenci * ogr_dizi, unsigned int ogr_sayisi, int N);

void ogr_sil(Ogrenci * ogr_dizi, unsigned int * ogr_sayisi);
void ogr_toparla(Ogrenci * ogr_dizi);
void ogr_duzenle(Ogrenci * ogr_dizi, unsigned int * ogr_sayisi);

void dev_mode();

void waiting_progress(unsigned int time_interval);

int main()
{
	unsigned int ogr_sayisi = 3;

	int i;

	Ogrenci ogr_liste[100];

	for(i=0; i<100; i++) {
		ogr_liste[i].mevcut = '0';
	}

	ogr_liste[0] = (Ogrenci) {
		"Ata",
			"Niyazov",
			"Bilgisayar muhendisligi",
			"130201108",
			{9,7,1992},
			{16,9,2013},
			'1'
	};

	ogr_liste[1] = (Ogrenci) {
		"Delta",
			"Linux",
			"X@kep",
			"150201108",
			{9,7,1992},
			{16,9,2013},
			'1'
	};

	ogr_liste[2] = (Ogrenci) {
		"AtAOEUa",
			"NiEOUyazov",
			"BilgiAEUAsayar muhendisligi",
			"144501108",
			{9,7,1982},
			{16,9,2003},
			'1'
	};

	/*for(i=2; i < 100; i++) {
	  ogr_liste[i] = (Ogrenci) {
	  "AtAOEUa",
	  "NiEOUyazov",
	  "BilgiAEUAsayar muhendisligi",
	  "144501108",
	  {9,7,1982},
	  {16,9,2003},
	  '1'
	  };
	  }*/

	short int state = 1;

	while(state) {

		system("clear");

		printf("### ANA MENU ###\n\n");

		char choise;

		printf("Seciminizi yapiniz, lutfen:\n--------------------------\n");
		printf("[1] Ogrencileri Listele\n[2] Ogrenci Ekle\n[3] Ogrenci Sil\n[4] Ogrenci Bilgi Yenile\n\n[0] Cikis\n\n");
		printf("Seciminiz: ");

		scanf("%c",&choise);

		switch(choise) {

			case '0' : printf("Cikis yapiyorum\n"); state = 0; return 0; break;
			case '1' : ogr_listele(ogr_liste,ogr_sayisi); break;
			case '2' : ogr_olustur(ogr_liste, &ogr_sayisi); break;
			case '3' : ogr_sil(ogr_liste, &ogr_sayisi); break;
			case '4' : ogr_duzenle(ogr_liste,&ogr_sayisi); break;
				   /*case '5' : {
				     unsigned int N = 0;
				     scanf(" %u",&N);
				     ogr_oku(ogr_liste,ogr_sayisi, N);
				     } break;
				     */
				   //case '9' : system("clear"); break;
			case 'z' : dev_mode(); break;

			default : {
					  printf("UYARI: Yalnis secim yaptiniz!\n\n");
					  printf("Press ENTER key to continue\n");
					  getchar();
					  getchar();
				  }
		}
	}

	return 0;
}


struct Tarih tarih_olustur()
{
	int gun, ay, yil;
	short int chanse = 3;

	while(chanse--) {

		printf("Lutfen tarihi giriniz (GG AA YYYY): ");
		scanf(" %d %d %d",&gun, &ay, &yil);

		if(gun <= 31 && ay <= 12 && yil >= 1970 && yil <= 2017) {
			struct Tarih tarih = {gun,ay,yil};
			return tarih;
		} else {
			printf("\nUYARI: Sisteme hatali tarih girisi yaptiniz!\n\n");
		}
	}

	struct Tarih tarih = {0,0,0};

	return tarih;
}


void ogr_olustur(Ogrenci * ogr_dizi, unsigned int *ogr_sayisi)
{
	system("clear");

	printf("OGRENCI OLUSTURMA\n-----------------\n\n");
	printf("[0] IPTAL\n\n");

	unsigned int N;
	printf("Kayit edilecek ogrenci sayisini giriniz: ");
	scanf(" %u",&N);

	unsigned int i,j;
	unsigned int dizi_boyutu = sizeof(Ogrenci);
	int state = 0;


	for(i=0,j=0; j < N && i < 100; i++) {
		if(((ogr_dizi+i)->mevcut) == '0') {

			printf("%2d. Ogrenci\n-----------\n",i+1);

			printf("Ad giriniz: ");
			scanf(" %20s",(ogr_dizi+i)->ad);

			printf("Soyadini giriniz: ");
			scanf(" %20s",(ogr_dizi+i)->soyad);

			printf("Bolum giriniz: ");
			scanf(" %40s",(ogr_dizi+i)->bolum);

			printf("Okul Numara giriniz: ");
			scanf(" %9s",(ogr_dizi+i)->no);

			printf("Dogum tarihi ");
			(ogr_dizi+i)->dogum_yili = tarih_olustur();

			printf("Kayit tarihi ");
			(ogr_dizi+i)->kayit_tarih = tarih_olustur();

			(ogr_dizi+i)->mevcut = '1';

			*ogr_sayisi += 1;
			j++;
			state = 1;
		}
	}

	if(state != 0) {
		printf("Ogrenci Olusturuldu\n\n");
	}
	printf("\nPress ENTER key to continue\n");
	getchar();
	getchar();
}

void ogr_listele(const Ogrenci * ogr_dizi, unsigned int ogr_sayisi)
{
	system("clear");

	unsigned int i,j;

	printf("OGRENCI LISTESI\n---------------\n\n");

	for(i=0,j=0; j < ogr_sayisi && i < 100; i++) {

		if(((ogr_dizi+i)->mevcut) != '0') {

			printf("%2d. Ogrenci\n-----------\n",j+1);

			printf("Adi: %s ",(ogr_dizi+i)->ad);

			printf("%s\n",(ogr_dizi+i)->soyad);

			printf("Bolum: %s\n",(ogr_dizi+i)->bolum);

			printf("Okul Numarasi: %s\n",(ogr_dizi+i)->no);

			printf("Dogum tarihi: %02d.%02d.%04d\n",
					(ogr_dizi+i)->dogum_yili.gun,
					(ogr_dizi+i)->dogum_yili.ay,
					(ogr_dizi+i)->dogum_yili.yil);

			printf("Kayit tarihi: %02d.%02d.%04d\n\n",
					(ogr_dizi+i)->kayit_tarih.gun,
					(ogr_dizi+i)->kayit_tarih.ay,
					(ogr_dizi+i)->kayit_tarih.yil);

			j++;
		}
	}
	printf("Press ENTER key to continue\n");
	getchar();
	getchar();
}

int ogr_oku(const Ogrenci * ogr_dizi, unsigned int ogr_sayisi, int N)
{
	if(((ogr_dizi+N)->mevcut) != '0' && N >= 0 && N < 100) {

		printf("\n%2d. Ogrenci\n-----------\n",N+1);

		printf("Adi: %s ",(ogr_dizi+N)->ad);

		printf("%s\n",(ogr_dizi+N)->soyad);

		printf("Bolum: %s\n",(ogr_dizi+N)->bolum);

		printf("Okul Numarasi: %s\n",(ogr_dizi+N)->no);

		printf("Dogum tarihi: %02d.%02d.%04d\n",
				(ogr_dizi+N)->dogum_yili.gun,
				(ogr_dizi+N)->dogum_yili.ay,
				(ogr_dizi+N)->dogum_yili.yil);

		printf("Kayit tarihi: %02d.%02d.%04d\n\n",
				(ogr_dizi+N)->kayit_tarih.gun,
				(ogr_dizi+N)->kayit_tarih.ay,
				(ogr_dizi+N)->kayit_tarih.yil);
		return 0;
	} else {
		return -1;
	}
}

void ogr_sil(Ogrenci * ogr_dizi, unsigned int * ogr_sayisi)
{
	unsigned int N;

	printf("Hangi ogrencini silmek istersiniz: ");
	scanf(" %u",&N);
	N--;

	int sonuc = -1;
	sonuc = ogr_oku(ogr_dizi, *ogr_sayisi, N);

	if(sonuc == 0) {
		printf("Bu ogrencini silmek istedinize eminmisiniz? [n/Y]: ");

		char sure = 'n';
		scanf(" %c",&sure);

		if(sure == 'Y') {
			(ogr_dizi+N)->mevcut = '0';
			*ogr_sayisi -= 1;
			ogr_toparla(ogr_dizi);

			printf("%d. Ogrenci silindi\n",N+1);
		}

	} else {
		printf("UYARI: Girdiginiz ogrenci mevcut degil!!!\n");
	}
	printf("\nPress ENTER key to continue\n");
	getchar();
	getchar();
}

void ogr_toparla(Ogrenci * ogr_dizi)
{
	unsigned int i,j;

	for(i=0; i < 100; i++) {
		if(((ogr_dizi+i)->mevcut) == '0') {
			for(j=i; j < 100; j++) {
				if(((ogr_dizi+j)->mevcut) != '0') {
					ogr_dizi[i] = ogr_dizi[j];
					(ogr_dizi+j)->mevcut = '0';
					break;
					//memcpy(ogr_dizi+i,ogr_dizi+j,sizeof(struct Ogrenci));
				}
			}
		}
		if(j == 99) {
			break;
		}
	}
}

void ogr_duzenle(Ogrenci * ogr_dizi, unsigned int * ogr_sayisi)
{
	system("clear");
	printf("OGRENCI BILGI YENILEME\n----------------------\n\n");

	unsigned int N;
	char sure = 'n';

	printf("Hangi ogrenci bilgilerini duzenlemek istiyorsunuz: ");
	scanf(" %u",&N);
	N--;

	int sonuc = -1;
	sonuc = ogr_oku(ogr_dizi, *ogr_sayisi, N);

	if(sonuc == 0) {

		printf("Bu ogrenci bilgilerini duzenlemek istiyorsunuz mu? [n/Y]: ");

		scanf(" %c",&sure);

		if(sure == 'Y') {

			char choise;

			printf("\nHangi bilgileri duzenlemek istiyorsunuz?\n----------------------------------------\n");

			printf("[1] Ad\n[2] Soyad\n[3] Bolum\n[4] Okul Numara\n[5] Dogum tarihi\n[6] Kayit tarihi\n\n[0] Iptal\n\n");

			while(choise != '0') {

				printf("Seciminiz: ");
				scanf(" %c",&choise);

				printf("\n");

				switch(choise) {
					case '0' :; break;

					case '1' : {
							   printf("Adi: %s ",(ogr_dizi+N)->ad);
							   printf("\nYeni Ad giriniz: ");
							   scanf(" %20s",(ogr_dizi+N)->ad);

							   printf("\n%d. Ogrenci Adi yenilendi.\n",N+1);
						   }
						  break;

					case '2' : {
							   printf("Soyadi: %s ",(ogr_dizi+N)->soyad);
							   printf("\nYeni Soyad giriniz: ");
							   scanf(" %20s",(ogr_dizi+N)->soyad);

							   printf("\n%d. Ogrenci Soyadi yenilendi.\n",N+1);
						   }
						   break;

					case '3' : {
							   printf("Bolum: %s ",(ogr_dizi+N)->bolum);
							   printf("\nYeni Bolum giriniz: ");
							   scanf(" %40s",(ogr_dizi+N)->bolum);

							   printf("\n%d. Ogrenci Bolumu yenilendi.\n",N+1);
						   }
						   break;

					case '4' : {
							   printf("Okul Numarasi: %s ",(ogr_dizi+N)->no);
							   printf("\nYeni Okul Numara giriniz: ");
							   scanf(" %9s",(ogr_dizi+N)->no);

							   printf("\n%d. Ogrenci Okul Numarasi yenilendi.\n",N+1);
						   }
						   break;

					case '5' : {
							   printf("Dogum tarihi: %02d.%02d.%04d\n",
									   (ogr_dizi+N)->dogum_yili.gun,
									   (ogr_dizi+N)->dogum_yili.ay,
									   (ogr_dizi+N)->dogum_yili.yil);

							   printf("\nYeni Dogum tarihi giriniz: ");
							   (ogr_dizi+N)->dogum_yili = tarih_olustur();

							   printf("\n%d. Ogrenci Dogum tarihi yenilendi.\n",N+1);
						   }
						   break;

					case '6' : {
							   printf("Kayit tarihi: %02d.%02d.%04d\n\n",
									   (ogr_dizi+N)->kayit_tarih.gun,
									   (ogr_dizi+N)->kayit_tarih.ay,
									   (ogr_dizi+N)->kayit_tarih.yil);

							   printf("\nYeni Kayit tarihi giriniz: ");
							   (ogr_dizi+N)->kayit_tarih = tarih_olustur();

							   printf("\n%d. Ogrenci Kayit tarihi yenilendi.\n",N+1);
						   }
						   break;

					default : printf("Yalnis secim yaptiniz!\n");
				}
			}

			printf("Ana menu'ya geri donuyorum.\n");
		}

	} else {
		printf("UYARI: Girdiginiz ogrenci mevcut degil!!!\n");
	}
	printf("\nPress ENTER key to continue\n");
	getchar();
	getchar();
}

void dev_mode()
{
	system("clear");
	printf("Wellcome to Developer mode!\n");

	waiting_progress(10);

	getchar();
	getchar();
	system("clear");
}


void waiting_progress(unsigned int time_interval)
{
	int i;

	for(i=0; i<50 ; i++) {
		//	printf("\a\u2588");
		fflush(stdout);
		usleep(time_interval * 10000);
	}
}


void shell_sort(Ogrenci * ogr_dizi, unsigned int * ogr_sayisi)
{
	unsigned int gap,i,j;
	Ogrenci temp;
	for(gap = *ogr_sayisi/2; gap > 0; gap /= 2) {
		for(i = gap; i<*ogr_sayisi; i++) {
			for(j=i-gap; j>=0 && (strcmp(ogr_dizi[j].ad,ogr_dizi[j+gap].ad)) > 0; j-=gap) {
				temp = ogr_dizi[j];
				ogr_dizi[j] = ogr_dizi[j+gap];
				ogr_dizi[j+gap] = temp;
			}
		}
	}
}
