#include <stdio.h>

int karakter_sayisi(const char *s);
int kelime_sayisi(const char *s);

int main() {

	char cumle[100];
	int kelime_say;

	printf("Cumle giriniz: ");

	gets(cumle);

	printf("\nGirilen karakter sayisi: %d\n\n",karakter_sayisi(cumle));

	kelime_say = kelime_sayisi(cumle);
	
	printf("kelime sayisi: %d\n",kelime_say);

	return 0;
}


int karakter_sayisi(const char *s) {

	int i;

	for(i = 0; s[i] != '\0'; i++){
	}

	return i;
}

int kelime_sayisi(const char *s) {

	int i;
	int kelime_say = 1;
	int karakter_say = karakter_sayisi(s);

	printf("Cumledeki kelimeler:\n");

	for(i = 0; s[i] != '\0'; i++) {
		if(s[i] == ' ') {
			printf("\n");
			kelime_say++;
		} else {
			printf("%c",s[i]);
		}
	}

	printf("\n\n");

	return kelime_say;
}
