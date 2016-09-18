#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int tamKaremi(int d[5][5]);

int main() {

	system("clear");

	int i,j,sonuc;
	int dizi[5][5];

	printf("\nLutfen 5x5 matris elemanlarini giriniz!\n\n");

	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			printf("%d satir, %d sutun elemani giriniz: ",i+1,j+1);
			scanf(" %d",&dizi[i][j]);
		}
		printf("\n");
	}

	system("clear");

	printf("---Matris---\n\n");

	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			printf("%d\t",dizi[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	sonuc=tamKaremi(dizi);

	printf("Sonuc=%d\n",sonuc);

	return 0;
}

int tamKaremi(int d[5][5]) {
	int i,j,tam_parca;
	float karekok;
	int esas=0, koshegen=0, toplam=0;

	for(i=0,j=4;i<5 && j>=0;i++,j--) {
		esas+=d[i][i];
		koshegen+=d[i][j];
		//printf("Esas %d, Koshegen %d, Esas Toplam %d, Koshegen Toplam %d\n\n",d[i][i],d[i][j],esas,koshegen);
	}

	toplam=esas+koshegen;

	printf("Toplam=%d\n\n",toplam);

	karekok=(sqrt(toplam));

	tam_parca=round(karekok);

	printf("Karekok=%d\n\n",tam_parca);

	/*
	if(karekok==tam_parca) {
		return 1;
	} else {
		return 0;
	}
	*/

	return (karekok==tam_parca) ? 1 : 0;

}
