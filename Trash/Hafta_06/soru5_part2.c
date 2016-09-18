#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

	system("clear");

	char cumle[100];
	char old_str[100];
	char new_str[100];

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

	if(strlen(old_str) == strlen(new_str)) {

		char * adres = strstr(cumle,old_str);
		int index = adres - cumle;
		while (adres != NULL) {
			memcpy(cumle+index,new_str,strlen(new_str)*sizeof(char));
			adres = strstr(adres+1,old_str);
			index = adres - cumle;
		}

		printf("\ndegistirildikten sonra:\n%s\n",cumle);
	} else { 

		int i,eleman=0;
		char s[2];
		char cumle_updated[100];

		char * adres = strstr(cumle,old_str);

		int eleman_sayi = strlen(cumle)/strlen(old_str);
		int search_index[eleman_sayi];
		memset(search_index,-1,eleman_sayi*sizeof(int));

		for(i=0;adres != NULL;i++) {
			search_index[i] = adres - cumle;
			adres = strstr(adres+1,old_str);
		}


		for(i=0; cumle[i] != '\0' && i<=strlen(cumle); i++) {
			if(i == search_index[eleman] && search_index[eleman] >=0) {
				strcat(cumle_updated,new_str);
				i += strlen(old_str);
				eleman++;
			} else {
				s[0]= cumle[i];
				strcat(cumle_updated,s);
			}

		}
		printf("\ndegistirildikten sonra:\n%s\n",cumle_updated);

	}

	return 0;
}
