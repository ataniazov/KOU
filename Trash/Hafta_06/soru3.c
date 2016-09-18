#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

	system("clear");

	char yazi[100];
	int i;
	int rakam_toplam = 0;
	char s[2];

	printf("icerisinde rakam bulunan bir yazi girin: \n");
	fgets(yazi,100,stdin);
	yazi[strlen(yazi)-1] = '\0';

	for(i=0; yazi[i] != '\0'; i++) {
		if(isdigit(yazi[i])) {
			s[0] = yazi[i];
			s[1] = '\0';
			rakam_toplam += atoi(s);
		}
	}

	printf("rakamlarin toplami: %d\n",rakam_toplam);

	return 0;
}
