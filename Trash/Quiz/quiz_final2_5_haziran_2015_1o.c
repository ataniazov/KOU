#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOSYA_YOLU "/home/delta/my_sandbox/sayilar.txt"

int main()
{
        system("clear");

        srand(time(NULL));

        FILE * dosya;

        if((dosya = fopen(DOSYA_YOLU, "w")) == NULL) {
                printf("dosya acilamadi!\n");
                exit(1);
        }

        fprintf(dosya,"%d %d\n",(10 + (rand()%10)), (10 + (rand()%10)));

        fclose(dosya);

        printf("Rastgele iki sayi dosyaya yazildi\n");

        printf("...\n");

        if((dosya = fopen(DOSYA_YOLU, "r")) == NULL) {
                printf("dosya acilamadi!\n");
                exit(1);
        }

        int sayi1;
        int sayi2;

        fscanf(dosya,"%d %d",&sayi1, &sayi2);

        if(sayi2 >= sayi1) {
                printf("Ikinci sayi birinci sayidan daha buyuk oldugu icin:\n");
                printf(" %2d + %2d = %d\n", sayi1, sayi2, sayi1+sayi2);
        }

        if(sayi2 < sayi1) {
                printf("Ikinci sayi birinci sayidan daha kucuk oldugu icin:\n");
                printf(" %2d - %2d = %d\n", sayi1, sayi2, sayi1-sayi2);
        }

        fclose(dosya);
}
