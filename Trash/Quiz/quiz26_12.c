#include<stdio.h>
#include<stdlib.h>


int main(){

	int sayi_sayisi,i,j;
	int sayilar[100];
	int tmp=0;
	float ortalama;

	printf("Kac sayi:");
	scanf("%d",&sayi_sayisi);

	for(i=1;i<=sayi_sayisi;i++){
		printf("Sayi girin: ");
		scanf("%d",&sayilar[i]);
	}

	printf("Girilen sayilar:\n");

	for(i=1;i<=sayi_sayisi;i++){
		printf("%d\n",sayilar[i]);
		tmp+=sayilar[i];
	}

	ortalama=(float)tmp/sayi_sayisi;

	printf("Ortalama:%f\n",ortalama);
	printf("Bar graph:\n");

	for(i=1;i<=sayi_sayisi;i++){
		for(j=1;j<=sayilar[i];j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
