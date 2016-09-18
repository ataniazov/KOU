#include<stdio.h>

int birbul(int x);
int ikibul(int y);

int main ()
{
	int sayi_sayisi,sayi;
	int birsayisi,ikisayisi;
	int encokbir=0,enaziki=0;
	int birli=0,ikili=0;
	int flag_bir=0,flag_iki=0,i;

	printf("kac sayi gireceksiniz: ");
	scanf("%d",&sayi_sayisi);

	for(i=1;i<=sayi_sayisi;i++) {
		printf("sayi girin:");
		scanf("%d",&sayi);

		birsayisi=birbul(sayi);
		ikisayisi=ikibul(sayi);

		if(flag_bir==0) {
			birli=sayi;
			encokbir=birsayisi;
			flag_bir=1;
		}

		if(flag_iki==0) {
			ikili=sayi;
			enaziki=ikisayisi;
			flag_iki=1;
		}

		if(birsayisi>encokbir) {
			birli=sayi;
			encokbir=birsayisi;
		}

		if(ikisayisi<enaziki) {
			ikili=sayi;
			enaziki=ikisayisi;
		}
	}

	printf("en fazla 1 olan:%d\n",birli);
	printf("en az 2 olan:%d\n",ikili);

	return 0;
}

int birbul(int x)
{
	int basamak,birsayisi=0;

	while(x>0) {
		basamak=x%10;
		x/=10;
		if(basamak==1) {
			birsayisi++;
		}
	}

	return birsayisi;
}


int ikibul(int y)
{
	int basamak,ikisayisi=0;

	while(y>0) {
		basamak=y%10;
		y/=10;
		if(basamak==2) {
			ikisayisi++;
		}
	}

	return ikisayisi;
}
