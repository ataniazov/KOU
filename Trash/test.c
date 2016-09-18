#include <stdio.h>

int main() {

	/*----------------------------------------------
	 *
	 *  * char tipinde diziler
	 *
	 *   *---------------------------------------------*/

	printf("char tipinde diziler\n");

	printf("====================\n");

	int dizi_a[4] = {'T', 'E', 'S', 'T'};

	printf("sizeof(char) : %d\n", sizeof(char));

	printf("sizeof(dizi_a) : %d\n\n", sizeof(dizi_a));

	printf("ilk elemanin adresi : %u\n", &dizi_a[0]);

	printf("ikinci elemanin adresi : %u\n\n", &dizi_a[1]);

	printf("%c\n", dizi_a[2]);

	printf("%u\n\n", &dizi_a[2]);

	/*----------------------------------------------
	 *
	 *  * Int tipinde diziler
	 *
	 *   *---------------------------------------------*/

	printf("int tipinde diziler\n");

	printf("====================\n");

	int dizi_b[3] = {100, 500, 1500};

	printf("sizeof(int) : %d\n", sizeof(int));

	printf("sizeof(dizi_b) : %d\n\n", sizeof(dizi_b));

	printf("ilk elemanin adresi : %u\n", &dizi_b[0]);

	printf("ikinci elemanin adresi : %u\n\n", &dizi_b[1]);

	printf("%d\n", dizi_b[2]);

	printf("%u\n\n", &dizi_b[2]);

	/*----------------------------------------------
	 *
	 *  * Dizinin pointer olarak kullanilmasi
	 *
	 *   *---------------------------------------------*/

	printf("dizinin pointer olarak kullanilmasi\n");

	printf("===================================\n");

	printf("dizi_b[2] : %d\n", dizi_b[2]);

	printf("*(dizi_b + 2) : %d\n\n", *(dizi_b + 2));

	printf("&dizi_b[2] : %u\n", &dizi_b[2]);

	printf("(dizi_b + 2) : %u\n", (dizi_b + 2));

	return 0;

}
