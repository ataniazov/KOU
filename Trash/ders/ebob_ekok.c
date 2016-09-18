#include <stdio.h>
int ebob(int x, int y);
int sayi_oku();
int main() {
	int N, i;
	int ebob_s; // ebob isleminin sonucu
	printf("kac sayi gireceksiniz: ");
	scanf("%d", &N);
	ebob_s = sayi_oku();
	printf("yeni ebob: %d\n", ebob_s);
	for (i = 2 ; i <= N ; i++) {
		int sayi = sayi_oku();
		ebob_s = ebob(ebob_s, sayi);
		printf("yeni ebob: %d\n", ebob_s);
	}
	printf("sonuc: %d\n", ebob_s);
	return 0;
}
int sayi_oku() {
	int x;
	printf("sayi girin: ");
	scanf("%d", &x);
	return x;
}
int ebob(int x, int y) {
	int i;
	int sonuc = 1;
	for (i = 2 ; i <= x && i <= y ; i++) {
		if (x % i == 0 && y % i == 0)
			sonuc = i;
	}
	return sonuc;
}
// ornek
// int ekok(int x, int y) {
// return x*y/ebob(x,y);
// }
