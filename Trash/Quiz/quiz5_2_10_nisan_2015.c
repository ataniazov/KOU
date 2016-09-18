#include <stdio.h>
#include <stdlib.h>

struct Karmasik {
	float real;
	float imag;
};

struct Karmasik topla(const struct Karmasik * birinci, const struct Karmasik * ikinci);
struct Karmasik cikar(const struct Karmasik * birinci, const struct Karmasik * ikinci);
struct Karmasik carp(const struct Karmasik * birinci, const struct Karmasik * ikinci);

int main() {

	system("clear");

	struct Karmasik birinci;
	struct Karmasik ikinci;
	struct Karmasik sonuc;
	char secim;

	while(secim != 'c') {
		secim = '\0';
		printf("\n\nToplama Icin 1 Giriniz\nCikarma Icin 2 Giriniz\nCarpma Icin 3 Giriniz\nCikis Icin c Giriniz\n");

		printf("Seciminizi Giriniz:\n");
		scanf(" %c",&secim);

		if(secim == '1' || secim == '2' || secim == '3') {
			printf("Birinci Karmasik Sayi Icin\n");
			printf("Sirasiyla real and imag kisimlarini giriniz:\n");
			scanf("%f",&birinci.real);
			scanf("%f",&birinci.imag);

			printf("\nIkinci Karmasik Sayi Icin\n");
			printf("Sirasiyla real and imag kisimlarini giriniz:\n");
			scanf("%f",&ikinci.real);
			scanf("%f",&ikinci.imag);

			printf("Birinci Karmasik Sayi:%7.2f+%.2fi\n", birinci.real, birinci.imag);
			printf("Ikinci Karmasik Sayi:%8.2f+%.2fi\n", ikinci.real, ikinci.imag);
		}

		if(secim == '1' || secim == '2' || secim == '3' || secim == 'c') {
			switch(secim) {
				case 'c' : return 0; break;

				case '1' : {
						   sonuc = topla(&birinci, &ikinci);
						   printf("Toplam=");
					   }
					   break;
				case '2' : {
						   sonuc = cikar(&birinci, &ikinci);
						   printf("Fark=");
					   }
					   break;
				case '3' : {
						   sonuc = carp(&birinci, &ikinci);
						   printf("Carpim=");
					   }
					   break;
			}
			printf("%.1f+%.1fi\n\n", sonuc.real, sonuc.imag);
		}
	}
}


struct Karmasik topla(const struct Karmasik * birinci, const struct Karmasik * ikinci) {
	struct Karmasik sonuc;
	sonuc.real = birinci->real + ikinci->real;
	sonuc.imag = birinci->imag + ikinci->imag;

	return sonuc;
}

struct Karmasik cikar(const struct Karmasik * birinci, const struct Karmasik * ikinci) {
	struct Karmasik sonuc;
	sonuc.real = birinci->real - ikinci->real;
	sonuc.imag = birinci->imag - ikinci->imag;

	return sonuc;
}

struct Karmasik carp(const struct Karmasik * birinci, const struct Karmasik * ikinci) {
	struct Karmasik sonuc;
	sonuc.real = ((birinci->real) * (ikinci->real)) + ((birinci->imag) * (ikinci->imag)*(-1));
	sonuc.imag = ((birinci->real) * (ikinci->imag)) + ((birinci->imag) * (ikinci->real));

	return sonuc;
}
