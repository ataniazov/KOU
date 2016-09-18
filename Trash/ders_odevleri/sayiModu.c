#include <stdio.h>

int main()
{
	int sayi=0;

	printf("Sayi giriniz: ");
	scanf("%d",&sayi);

	if(sayi%2==0)
		printf("Sayi cifttir");
	else
		printf("Sayi tektir");

	return 0;
}
