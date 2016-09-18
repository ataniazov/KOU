#include <stdio.h>

int main()
{
	int sayi;
	int sonuc;

	printf("sayi giriniz: ");

	scanf("%d",&sayi);

	sonuc = sayi%5;
	printf("sonuc = %d", sonuc);

	return 0;
}
