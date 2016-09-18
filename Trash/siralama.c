#include <stdio.h>

int main()

{

	long ogr_no[1000] = { 150004, 150002, 150001, 150005, 150003 };

	int vize[1000] = {77, 65, 99, 89, 77};

	int N = 5; // ogrenci sayisi

	int i, j;

	while (1) {

		printf("0: listele\n");

		printf("1: ogr numarasina gore sirala\n");

		printf("2: vizeye gore sirala\n");

		printf("seciniz:");

		int secim;

		scanf("%d", &secim);

		if (secim == 0)

		{

			printf("liste:\n");

			for (i = 0 ; i < N ; i++)

			{

				printf("%ld - %d\n", ogr_no[i], vize[i]);

			}

		}

		else if (secim == 1)

		{

			for (j = 0 ; j < N-1 ; j++)

			{

				// j'den itibaren en kucuk elemani bul

				int en_kucuk_sira = j;

				for (i = j+1 ; i < N ; i++)

				{

					if (ogr_no[i] < ogr_no[en_kucuk_sira])

					{

						en_kucuk_sira = i;

					}

				}

				// ogrenci numaralari dizinde yer degistir

				int tmp = ogr_no[j];

				ogr_no[j] = ogr_no[en_kucuk_sira];

				ogr_no[en_kucuk_sira] = tmp;

				// vize dizisinde yer degistir

				tmp = vize[j];

				vize[j] = vize[en_kucuk_sira];

				vize[en_kucuk_sira] = tmp;

			}

		}

		else if (secim == 2)

		{

			for (j = 0 ; j < N-1 ; j++)

			{

				// en buyuk buyuk elemani bulur

				int enb_sira = j;

				for (i = j+1 ; i < N ; i++)

				{

					if (vize[i] > vize[enb_sira])

					{

						enb_sira = i;

					}

				}

				// vize dizinde yer degistir

				int tmp = vize[j];

				vize[j] = vize[enb_sira];

				vize[enb_sira] = tmp;

				// ogr_no dizisinde yer degistir

				tmp = ogr_no[j];

				ogr_no[j] = ogr_no[enb_sira];

				ogr_no[enb_sira] = tmp;

			}

		}

	}

	return 0;

}
