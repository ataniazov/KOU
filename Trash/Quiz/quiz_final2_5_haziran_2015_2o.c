#include <stdio.h>
#include <stdlib.h>

#define USD "/home/delta/my_sandbox/USD.txt"
#define TL "/home/delta/my_sandbox/TL.txt"

int main()
{
        system("clear");

        float kur;

        printf("USD-TL kur giriniz: 1 USD = ");
        scanf("%f",&kur);

        FILE * dosya_usd;
        FILE * dosya_tl;

        if((dosya_usd = fopen(USD,"r")) == NULL) {
                printf("dosya acilamadi!");
                exit(1);
        }


        if((dosya_tl = fopen(TL,"w")) == NULL) {
                printf("dosya acilamadi!");
                exit(1);
        }

        float usd;

        printf("USD.txt > TL.txt\n");
        while(fscanf(dosya_usd,"%f",&usd) != EOF) {
                fprintf(dosya_tl,"%.2f\n",usd*kur);
        }
        printf("cevirme islemi tamamlandi.\n\n");

        fclose(dosya_usd);
        fclose(dosya_tl);


        int i;
        float tl;

        for(i = 0; i < 20; i++) {
                printf("-");
        }
        printf("\n");

        if((dosya_tl = fopen(TL,"r")) == NULL) {
                printf("dosya acilamadi!");
                exit(1);
        }

        while(fscanf(dosya_tl,"%f",&tl) != EOF) {
                printf("%.2f\n",tl);
        }

        fclose(dosya_tl);

        return 0;
}
