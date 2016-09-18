#include <stdio.h>
#include <stdlib.h>

int karakter_sayisi(const char *s);
int rakam_sil(char *s);

int main() {

	char cumle[100];
	int rakam_sayisi;

	system("clear");

	printf("Cumle girin: ");
	gets(cumle);

	printf("\nGirilen karakter sayisi: %d\n\n", karakter_sayisi(cumle));

	rakam_sayisi = rakam_sil(cumle);

	printf("Rakam sayisi: %d\n", rakam_sayisi);

	printf("Rakam olmayan karakter sayisi: %d\n\n", karakter_sayisi(cumle));

	return 0;
}

int karakter_sayisi(const char *s) {

	int i;

	for(i=0; s[i] != '\0'; i++) {
		/* bos dongu */
	}

	return i;
}

int rakam_sil(char *s) {

	int i,j;
	int karakter_say = karakter_sayisi(s);
	int rakam_sayisi = 0;

	printf("Rakamlarin silinmis hali:\n");

	for(i=0; s[i] != '\0'; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			for(j=i; j <= karakter_say; j++) {
				s[j] = s[j+1];
			}
			rakam_sayisi++;
			i--;
			karakter_say--;
		} else {
			printf("%c",s[i]);
		}
	}
	printf("\n\n");

	return rakam_sayisi;
}
