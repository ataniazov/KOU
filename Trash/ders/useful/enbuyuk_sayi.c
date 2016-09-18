#include <stdio.h>
// fonksiyon prototipleri
int sayi_oku() ;
int max(int s1, int s2);
int main() {
	int N; // sayilarin sayisi
	int i, en_buyuk, sayi;
	printf("kac sayi gireceksiniz?");
	scanf("%d", &N);
	en_buyuk = sayi_oku();
	for (i = 2 ; i <= N ; i++) {
		sayi = sayi_oku();
		en_buyuk = max(sayi, en_buyuk);
		//printf("yeni enbuyuk sayi: %d\n", en_buyuk);
	}
	printf("en buyuk sayi: %d", en_buyuk);
	return 0;
}
int sayi_oku() {
	int sayi;
	printf("sayi girin:");
	scanf("%d", &sayi);
	return sayi;
}
int max(int s1, int s2) {
	if (s1 > s2)
		return s1;
	else
		return s2;
}
