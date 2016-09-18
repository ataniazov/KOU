#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

	system("clear");

	char cumle[100];
	char old_str[100];
	char new_str[100];
	int i;


	printf("bir cumle girin: \n");
	fgets(cumle,100,stdin);
	cumle[strlen(cumle)-1] = '\0';

	printf("\n");

	printf("degistirilecek stringi girin: ");
	fgets(old_str,100,stdin);
	old_str[strlen(old_str)-1] = '\0';

	printf("\n");

	printf("yeni stringi girin: ");
	fgets(new_str,100,stdin);
	new_str[strlen(new_str)-1] = '\0';


	char * adres = strstr(cumle,old_str);
	int index = adres - cumle;

	while (adres != NULL) {
		memcpy(cumle+index,new_str,strlen(new_str)*sizeof(char));
		adres = strstr(adres+1,old_str);
		index = adres - cumle;
	}


	printf("\ndegistirildikten sonra:\n%s\n",cumle);

	return 0;
}
