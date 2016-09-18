#include <stdio.h>
#include <stdlib.h>

void sagdankirp(int * sayi, int krp_sayi);

int main()
{
        system("clear");

        int sayi,krp_sayi;

        printf("Sayiyi giriniz: ");
        scanf("%d",&sayi);

        printf("Sagdan kirpilacak basamak sayisini giriniz: ");
        scanf("%d",&krp_sayi);

        sagdankirp(&sayi,krp_sayi);

        printf("Sayinin kirpilmis hali = %d\n",sayi);

        return 0;
}


void sagdankirp(int * sayi, int krp_sayi)
{
        while(krp_sayi > 0) {
                *sayi /= 10;
                krp_sayi--;
        }
}

