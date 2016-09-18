#include<stdio.h>
#include<stdlib.h>

void sorgulama(int dizi[],int sayi_sayisi,int sayi);

int main()
{
	int sayi_sayisi,i,sorgulanacak;
	int dizi[20];
	int deney=0;

	printf("Kac sayi: ");
	scanf("%d",&sayi_sayisi);

	while(sayi_sayisi>20){

		printf("Hata!! En fazla 20 sayi girebilir\n");

		printf("Kac sayi: ");
		scanf("%d",&sayi_sayisi);

		deney++;

		if(deney>2 && sayi_sayisi<=20) {

			printf("Aferim!\n");

		} else if(deney>10) {
		
			printf("Kullanci aptal!!\n");

			return 0;

		} else;
	}

	for(i=1;i<=sayi_sayisi;i++) {

		printf("%d sayi girin: ",i);
		scanf("%d",&dizi[i-1]);

	}

	printf("Girilen sayilar:\n");

	for(i=1;i<=sayi_sayisi;i++){

		printf("%d\t\n",dizi[i-1]);

	}

	printf("Sorgulanacak sayi: ");
	scanf("%d",&sorgulanacak);

	sorgulama(dizi,sayi_sayisi,sorgulanacak);

	return 0;
}

void sorgulama(int dizi[],int sayi_sayisi,int sayi){

	int i,flag=0;
	for(i=1;i<=sayi_sayisi;i++){
		if(sayi==dizi[i-1]){
			flag=1;
		}
	}
	(flag==1) ? printf("Var\n") : printf("Yok\n");

}
