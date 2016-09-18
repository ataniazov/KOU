#include <stdio.h>
#include <stdlib.h>

int asalbul(int * psayi);

int main()
{
        system("clear");

        int sayi;

        printf("Sayiyi giriniz: ");
        scanf("%d",&sayi);

        if(asalbul(&sayi)) {
                printf("%d sayisi asal sayidir\n",sayi);
        } else {
                printf("%d sayisi asal sayi degildir\n",sayi);
        }

        int sayi2 = sayi + 2;

        if(asalbul(&sayi2)) {
                printf("%d sayisi asal sayidir\n",sayi2);
                printf("%d sayisi Chen asalidir\n",sayi);
                printf("%d Chen asal sayisinin bellekteki adresi:%X\n",sayi,&sayi);
        } else {
                printf("%d sayisi asal sayi degildir\n",sayi2);
                printf("%d sayisi Chen asali degildir\n",sayi);
        }

        return 0;
}

int asalbul(int * psayi)
{
        int i;

        for(i = 2; i < *psayi; i++) {
                if((*psayi % i) == 0) {
                        return 0;
                }
        }
        return 1;
}
