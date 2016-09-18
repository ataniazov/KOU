#include <stdio.h>
#include <conio.h>

int main()
{
	char kr1,kr2,kr3;
	int x=0,y=0,z=0;
	
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
	
	
	//ASCII karsiliklarin buyukten kucuge siralamasi yapiliyor.
	if (x>y && x>z)
	{
 		if (y>z)
 			printf("%d>%d>%d",x,y,z);
 		else if (z>y)
 			printf("%d>%d>%d",x,z,y);
 		else
 			printf("%d > %d",x,y);
	}
    else if (y>x && y>z)
    {
    	if (x>z)
 			printf("%d > %d > %d",y,x,z);
 		else if (z>x)
 			printf("%d>%d>%d",y,z,x);
 		else
			printf("%d > %d",y,z);
	}
 	else if (z>y && z>x)
	{
 		if (y>x)
 			printf("%d>%d>%d",z,y,x);
 		else if(x<y)
 			printf("%d > %d",z,y); 
 		else 
 			printf("%d>%d",z,x);
	}
 	if (x==y && x<z)
 		printf(" ve %d = %d",x,y);
 	if (z==x && z<y)
 		printf(" ve %d = %d",x,z);
 	if (y==z && y<x)
 		printf(" ve %d = %d",y,z);
 	if (x>y && x==z)
 		printf("%d > %d ve %d = %d",x,y,x,z);
 	if (y>x && y==z)
 		printf("%d > %d ve %d = %d",y,x,y,z);
 	if (x>z && x==y)
 		printf("%d > %d ve %d = %d",x,z,y,x);
 	if (x==y && y==z )
 		printf("%d = %d = %d",x,y,z); 

	
	
	getch();
	
	return 0;
}
