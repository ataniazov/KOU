#include <stdio.h>
// fonksiyona boyutu degisken olan bir dizi gonderilmek istenilirse asagidaki
// gibi yazilir.
// elaman_say -> fonksiyon cagrilirken dizideki eleman_sayisi da belirtiliyor
float dizi_toplam(float d[], int eleman_say) {
	int i;
	float toplam = 0;
	for (i = 0 ; i < eleman_say ; i++) {
		toplam += d[i];
	}
	return toplam;
}
int main() {
	float sicakliklar[7];
	int i;
	for (i = 0 ; i < 7 ; i++) {
		printf("%d. gun: ", i+1);
		float x;
		scanf("%f", &x);
		sicakliklar[i] = x;
	}
	float toplam = dizi_toplam(sicakliklar, 7);
	printf("toplam: %f\n", toplam);
	float ortalama = toplam / 7.0;
	printf("ortalama: %f\n", ortalama);
	for (i = 0 ; i < 7 ; i++) {
		if (sicakliklar[i] < ortalama) {
			printf("%d. gun = %f\n", i+1, sicakliklar[i]);
		}
	}
	return 0;
}
