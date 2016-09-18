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

	int eleman_sayi = strlen(cumle)/strlen(old_str);
	int search_index[eleman_sayi];
	// index dizisini -1 ile dolduryorum.
	memset(search_index,-1,eleman_sayi*sizeof(int));

	int i;
	char * adres = strstr(cumle,old_str);

	// bulunduk index'leri kayit ediyorum
	if(adres == NULL) {
		printf("Hata!!! Degistirilecek: %s bulunmamaktadir.\n",old_str);
		printf("\nDIKKATLI OL!!!\n");

		return 0;
	} else {
		for(i = 0; adres != NULL && i <= eleman_sayi; i++) {
			search_index[i] = adres - cumle;
			adres = strstr(adres+strlen(old_str),old_str);
		}
	}

	printf("yeni stringi girin: ");
	fgets(new_str,100,stdin);
	new_str[strlen(new_str)-1] = '\0';

	char cumle_new[100];
	int j=0, eleman = 0, ara_kelime_boyutu;
	i=0;

	while(i <= strlen(cumle) && cumle[i] != '\0') {
		if(i == search_index[eleman] && search_index[eleman] != -1) {
			strcat(cumle_new,new_str);
			i+=strlen(old_str);
			j+=strlen(new_str);
			eleman++;
		} else {
			if(search_index[eleman] != -1) {
				ara_kelime_boyutu = search_index[eleman]-i;
				strncat(cumle_new+j,cumle+i,ara_kelime_boyutu);
				i+=ara_kelime_boyutu;
				j+=ara_kelime_boyutu;
			} else {
				strcat(cumle_new+j,cumle+i);
				i+=strlen(cumle+i);
				break;
			}
		}
	}

	printf("\ndegistirildikten sonra:\n%s\n",cumle_new);

	return 0;
}
