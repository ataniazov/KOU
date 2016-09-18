#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOSYA_YOLU "D:\\SINAV\\lab71\\dizinin_elemanlari.txt"

int main()
{
    int boyut;
    int sayi,i;

    FILE * dosya;

    if ((dosya = fopen(DOSYA_YOLU, "w")) == NULL)
    {
        printf("dosya acilamadi!\n");
        exit(1);
    }

    srand(time(NULL));

    printf("Dizinin boyutunu giriniz\n");
    scanf("%d",&boyut);

    for(i=0; i<boyut; i++)
    {
        sayi = (rand()%10);
        fprintf(dosya,"%d\n",sayi);

    }
    fclose(dosya);

    if ((dosya = fopen(DOSYA_YOLU, "r")) == NULL)
    {
        printf("dosya acilamadi!\n");
        exit(1);
    }

    int sayi2;
    int tane;
    int bolunen = 0;
    printf("Dizinin 2'ye bolunen elemanlari:\n");
    while (1)
    {
        tane = fscanf(dosya, "%d", &sayi2);

        if(tane<1)
        {
            break;
        }
        if((sayi2 % 2) == NULL)
        {
            printf("%d\n",sayi2);
            bolunen++;
        }
    }
    printf("\n%d elemanli dizinin elemanlarindan %d tanesi 2'ye tam bolunur.\n",boyut,bolunen);


    return 0;
}
