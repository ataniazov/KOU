#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int karsilikliEsit(int matris[5][5], int transpoz[5][5]);

int main() {

	system("clear");

	int i,j;
	int matris[5][5],transpoz[5][5];
	int esit_eleman;

	printf("\nLutfen 5x5 matris tam sayi elemanlarini giriniz!\n\n");

	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			printf("%d. satir, %d. sutun elemani giriniz: ",i+1,j+1);
			scanf(" %d",&matris[i][j]);
			transpoz[j][i]=matris[i][j];
		}
		printf("\n");
	}

	system("clear");

	printf("---Matris---\n\n");

	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			printf("%d\t",matris[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	printf("---Transpoz---\n\n");

	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			printf("%d\t",transpoz[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	esit_eleman=karsilikliEsit(matris, transpoz);

	printf("Esit eleman sayisi = %d\n",esit_eleman);

	return 0;
}


int karsilikliEsit(int matris[5][5], int transpoz[5][5]) {

	int i,j;
	int matris_satir[5],transpoz_satir[5];
	int esit_eleman=0;

	for(i=0;i<5;i++) {
		matris_satir[i]=0;
		transpoz_satir[i]=0;
	}

	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			matris_satir[i]+=matris[i][j];
			transpoz_satir[i]+=transpoz[i][j];
		}
	}

	printf("---Matris satir toplami---\n");

	for(i=0;i<5;i++) {
		printf("%d\t",matris_satir[i]);
	}

	printf("\n\n");

	printf("---Transpoz satir toplami---\n");

	for(i=0;i<5;i++) {
		printf("%d\t",transpoz_satir[i]);
	}

	printf("\n\n");

	for(i=0;i<5;i++) {
		if(matris_satir[i]==transpoz_satir[i]) {
			esit_eleman++;
		}
	}

	return esit_eleman;
}
