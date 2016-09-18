#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

	system("clear");

	char yazi[100];
	int ascii_array[128];
	int i;

	memset(ascii_array,0,128*sizeof(int));

	printf("yazi girin: ");
	fgets(yazi,100,stdin);
	yazi[strlen(yazi)-1] = '\0';

	printf("\n");

	for(i=0; yazi[i] != '\0'; i++) {
		if(yazi[i] >= 0 && yazi[i] <= 127) {
			ascii_array[yazi[i]]++;
		} else {
			printf("HATA!!! Sizin yaziniz ASCII 128 disi karakter iceriyor.\n");
			return 0;
		}
	}

	for(i=0; i<128; i++) {
		if(ascii_array[i] != 0) {
			printf("%c: %d tane\n",i,ascii_array[i]);
		}
	}

	return 0;
}
