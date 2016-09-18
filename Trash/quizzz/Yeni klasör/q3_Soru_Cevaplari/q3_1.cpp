#include<stdio.h>
#include<conio.h>

int main()
{
	char kr1,kr2,kr3;
	int x,y,z;
	
	printf("Birinci karakteri giriniz!\n");
	scanf("%c",&kr1);
    fflush(stdin);  //Arka arkaya scanf kullaniminda bellegi temizlemeyi saðlayan fonksiyondur.

	
	printf("Ikinci karakteri giriniz!\n");
	scanf("%c",&kr2);
	fflush(stdin);

	
	printf("Ucuncu karakteri giriniz!\n");
	scanf("%c",&kr3);
	fflush(stdin);

	
	//Karakterlerin ASCII karsiliklari aliniyor.
	x=kr1;
	y=kr2;
	z=kr3;
	
	if((x>96 && x<125) && (y>96 && y<125) && (z>96 && z<125)) //kucuk harf kontrolu yapiliyor.
	{
		
		int toplam=x+y+z;
		printf("Basamaklarina ayirilacak sayi: %d\n",toplam);
		printf("-------------------------------------\n");
		
		//elde edilen ASCII karakter toplami basamaklarina ayiriliyor.
		printf("birler basamagi: %d\n",toplam%10);
		toplam=toplam/10;
		
		printf("onlar basamagi: %d\n",toplam%10);
		toplam=toplam/10;
		
		printf("yuzler basamagi: %d\n",toplam%10);
		toplam=toplam/10;
		
	}
	else //Butun karakterler kucuk harf degilse uyari veriliyor.
	{
		printf("girilen butun karakterler kucuk harf olmalidir!");
	}
	
	getch();
	
	return 0;
}
