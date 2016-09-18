#include <stdio.h>

int exist(const char big[], const char lil[]);
int lenth_cpm(const char array[]);

int main() {

	int x = 0;

	char big_string[101];
	char lil_string[101];

	printf("1. diziyi giriniz: ");
	gets(big_string);

	printf("2. diziyi giriniz: ");
	gets(lil_string);

	x = exist(big_string,lil_string);

	if(x) {
		printf("Var\n");
	} else {
		printf("Yok\n");
	}

	return 0;
}

int exist(const char big[], const char lil[]) {

	int i,j;

	int big_len, lil_len;

	big_len = lenth_cpm(big);
	lil_len = lenth_cpm(lil);

	for(i=0; i <= big_len-lil_len; i++) {
		printf("i = %d\n",i);
		for(j=0; j < lil_len; j++) {
			printf("j = %d\n",j);
			if(big[i] != lil[j]) {
				break;
			}
		}

		if(j == lil_len) {
			return 1;
		}
	}

	return 0;
}

int lenth_cpm(const char s[]) {

	int i;

	for(i=0; s[i] != '\0'; i++) {
	}

	printf("i = %d\n",i);

	return i;
}
