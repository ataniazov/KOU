#include<stdio.h>
#include<stdlib.h>

int sayi_tersi_bul(int x);

int main ()
{
	int sayi_sayisi,sayi;
	int sayi_tersi;
	int i,enbuyugi;

	printf("kac sayi gireceksiniz: ");
	scanf("%d",&sayi_sayisi);

	printf("sayi girin:");
	scanf("%d",&sayi);
	sayi_tersi=sayi_tersi_bul(sayi);
	enbuyugi=abs(sayi-sayi_tersi);
	for(i=2;i<=sayi_sayisi;i++) {
		printf("sayi girin:");
		scanf("%d",&sayi);
		sayi_tersi=sayi_tersi_bul(sayi);
		if(enbuyugi<abs(sayi-sayi_tersi)){
			enbuyugi=abs(sayi-sayi_tersi);
		}



	}

	printf("enbuyugi %d\n",enbuyugi);

	return 0;
}

int sayi_tersi_bul(int sayi)
{
	int basamak,sayi_tersi=0;
	int x,i=1;

	x=sayi;
	while(x>0) {
		x/=10;
		i*=10;
	}
	while(sayi>0) {
		basamak=sayi%10;
		sayi/=10;
		i/=10;
		sayi_tersi+=(basamak*i);
	}

	return sayi_tersi;
}

