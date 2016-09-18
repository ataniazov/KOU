#include <stdio.h>
int main() {
	int i;
	float kareler[6];
	// i-> [0, 6) = [0, 5]
	for (i = 0 ; i < 6 ; i++) {
		kareler[i] = i*i;
	}
	for (i = 0 ; i < 6 ; i++) {
		printf("%f\n", kareler[i]);
	}
	float toplam = 0;
	for (i = 0 ; i < 6 ; i++)
		toplam += kareler[i];
	float ortalama = toplam / 6.0;
	printf("toplam: %f\n", toplam);
	printf("ortalama: %f\n", ortalama);
	return 0;
}
