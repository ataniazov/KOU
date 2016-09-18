#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

	system("clear");

	char yazi[100];
	int i;

	printf("yazi girin: ");
	fgets(yazi,100,stdin);
	yazi[strlen(yazi)-1] = '\0';

	int kucuk_sayi = 0;
	int buyuk_sayi = 0;
	int rakam_sayi = 0;
	int bosluk_sayi = 0;

	for(i=0; yazi[i] != '\0'; i++) {

		kucuk_sayi += (islower(yazi[i])) ? 1 : 0;
		buyuk_sayi += (isupper(yazi[i])) ? 1 : 0;
		rakam_sayi += (isdigit(yazi[i])) ? 1 : 0;
		bosluk_sayi += (isspace(yazi[i])) ? 1 : 0;

	}

	printf("kucuk harf sayisi: %d\n",kucuk_sayi);
	printf("buyuk harf sayisi: %d\n",buyuk_sayi);
	printf("rakam sayisi: %d\n",rakam_sayi);
	printf("bosluk sayisi: %d\n",bosluk_sayi);

	return 0;
}
