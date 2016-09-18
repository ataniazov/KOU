// Ata Niyazov  130201108  20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORNEK_DOSYA "D:\\SINAV\\quiz81\\ornek.txt"
#define SONUC_DOSYA "D:\\SINAV\\quiz81\\sonuc.txt"

int harf_sayisi(char * kelime);

int main()
{
    FILE * dosya_ornek;

    if ((dosya_ornek = fopen(ORNEK_DOSYA, "r")) == NULL)
    {
        printf("ornek.txt dosya acilamadi!\n");
        exit(1);
    }

    FILE * dosya_sonuc;

    if ((dosya_sonuc = fopen(SONUC_DOSYA, "w")) == NULL)
    {
        printf("sonuc.txt dosya acilamadi!\n");
        exit(1);
    }

    char buf[100];
    int sayi = 0;
    int kelime_sayisi = 0;

    fgets(buf, 100, dosya_ornek);

    const char *ayrac = " "; // bosluk, nokta ve virgul, noktali virgul...

    char *kelime = strtok(buf, ayrac);
    while (kelime != NULL)
    {
        printf("%s\n", kelime);

        sayi = harf_sayisi(kelime);
        kelime_sayisi++;

        fprintf(dosya_sonuc,"%s\n%s kelimesindeki harf sayisi=%d\n\n",kelime,kelime,sayi);

        kelime = strtok(NULL, ayrac);
    }
    fprintf(dosya_sonuc,"cumledeki toplam kelime sayisi=%d\n",kelime_sayisi);

    int i;

    printf("\n");

    for(i=0; i < 32; i++)
    {
        printf("-");
    }

    fclose(dosya_ornek);
    fclose(dosya_sonuc);

    return 0;
}

int harf_sayisi(char * kelime)
{
    int sayi = strlen(kelime);
    return sayi;
}

