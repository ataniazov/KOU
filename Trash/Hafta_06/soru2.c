#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

	system("clear");

	char kelime[100];
	char ek[100];
	int i;

	printf("kelime girin: ");
	fgets(kelime,100,stdin);
	kelime[strlen(kelime)-1] = '\0';

	printf("kontrol edilecek eki girin: ");
	fgets(ek,100,stdin);
	ek[strlen(ek)-1] = '\0';

	printf("\n");

	char * adres = strstr(kelime,ek);
	int index = adres-kelime;
	int state = 0;

	if(adres != NULL) {
		while (adres != NULL) {
			if (index == 0) {
				printf("on ektir\n");
				state = 1;
			} else if (index+strlen(ek) == strlen(kelime)) {
				printf("son ektir\n");		
				state = 1;
			} else if (state == 0){
				printf("on ek veya son ek degildir\n");
			}
			adres = strstr(adres+1,ek);
			index = adres-kelime;
		}

	} else {
		printf("kelime eki degildir\n");
	}

	return 0;
}
