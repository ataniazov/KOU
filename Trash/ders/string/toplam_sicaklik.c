#include <stdio.h>
float dizi_toplam(float d[], int eleman_say);
int main() {
	float sicakliklar[100];
	int N, i;
	printf("gun sayisi:");
	scanf("%d", &N);
	// N > 100 ise hata verilmeli
	for ( i = 0 ; i < N ; i++) {
		printf("%d. gun: ", i+1);
		scanf("%f", &sicakliklar[i]);
	}
	float toplam = dizi_toplam(sicakliklar, N);
	printf("toplam: %f\n", toplam);
	float ortalama = toplam / (float)N;
	printf("ortalama: %f\n", ortalama);
	int sayac = 0;
	for (i = 0 ; i < N ; i++) {
		if (sicakliklar[i] < ortalama)
			sayac++;
	}
	printf("%d gun ortalama altinda\n", sayac);
	for (i = 0 ; i < N ; i++) {
		if (sicakliklar[i] < ortalama)
			printf("%d. gun = %f\n", i+1, sicakliklar[i]);
	}
	return 0;
}
float dizi_toplam(float d[], int eleman_say) {
	int i;
	float toplam = 0;
	for (i = 0 ; i < eleman_say ; i++) {
		toplam += d[i];
	}
	return toplam;
}
