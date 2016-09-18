#include<stdio.h>
#include<stdlib.h>


int main()
{
	char isim[100];

	char ata[4]= {'A','t','a'};
	printf("Isiminizi yaziniz: ");
	scanf("%s",isim);
	if(isim==ata){

		printf("Eshit");

	}

	printf("Merhaba %s!",isim);

	return 0;

}
