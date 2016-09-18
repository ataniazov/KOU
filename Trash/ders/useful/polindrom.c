#include <stdio.h>
int tersini_bul(int x);
int main() {
	/*
	 * printf("%d = 1\n", tersini_bul(1));
	 * printf("%d = 21\n", tersini_bul(12));
	 * printf("%d = 321\n", tersini_bul(123));
	 * */
	int sayi;
	printf("sayi girin:");
	scanf("%d", &sayi);
	if (sayi == tersini_bul(sayi))
		printf("sayi palindromik sayidir");
	else
		printf("degildir");
	return 0;
}
int tersini_bul(int x) {
	int S = 0;
	while (x > 0) {
		int b = x % 10;
		S = (S * 10) + b;
		x /= 10;
	}
	return S;
}
