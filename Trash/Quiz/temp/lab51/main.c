// Ata Niyazov  130201108  20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Zaman
{
    int saat;
    int dakika;
    int saniye;
};

struct Zaman fark(struct Zaman bitis, struct Zaman baslama);

int main()
{
    struct Zaman bitis;
    struct Zaman baslama;

    struct Zaman fark_deger;

    int state = 1;
    int sum;


    while(state)
    {

        printf("Bitis Zamanini Giriniz::\nSaat, dakika ve saniyeyi arka arkaya giriniz:\n");

        scanf("%d",&bitis.saat);
        scanf("%d",&bitis.dakika);
        scanf("%d",&bitis.saniye);

        printf("Baslama Zamanini Giriniz::\nSaat, dakika ve saniyeyi arka arkaya giriniz:\n");

        scanf("%d",&baslama.saat);
        scanf("%d",&baslama.dakika);
        scanf("%d",&baslama.saniye);

        sum = memcmp(&bitis,&baslama,sizeof(struct Zaman));

        if(sum < 0)
        {
            printf("Bitis Saati Baslama Saatinden Kucuk Bir Deger Olamaz!\n");
        }
        else
        {
            state = 0;
            break;
        }

    }

    fark_deger = fark(bitis,baslama);

    printf("\nFark: %d:%02d:%02d -%d:%02d:%02d = %d:%02d:%02d\n\n",bitis.saat, bitis.dakika, bitis.saniye, baslama.saat, baslama.dakika, baslama.saniye, fark_deger.saat, fark_deger.dakika, fark_deger.saniye);

    return 0;
}

struct Zaman fark(struct Zaman bitis, struct Zaman baslama)
{
    struct Zaman fark_deger;
    int sum_saniye = 0;

    sum_saniye = ((bitis.saat * 3600) - (baslama.saat * 3600)) + ((bitis.dakika * 60)) - ((baslama.dakika * 60)) + (bitis.saniye - baslama.saniye);


    fark_deger.saat = sum_saniye/3600;
    fark_deger.dakika = ((sum_saniye/60)%60);
    fark_deger.saniye = (sum_saniye%60);

    return fark_deger;
}

