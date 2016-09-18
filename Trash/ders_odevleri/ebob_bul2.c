#include <stdio.h>

int ebob_bul(int a,int b)
{
    int kucuk,ebob;
    int i;

    if(a>b) {
        kucuk=b;
    } else kucuk=a;

    for(i=1;i<=kucuk;i++) {
        if(a%i==0 && b%i==0) {
            ebob=i;
        }
    }
    return ebob;
}

int main()
{
    int sayi_sayisi,i;
    int sayi,ebob;

    printf("Kac sayi gireceksiniz: ");
    scanf("%d",&sayi_sayisi);

    printf("sayi girin: ");
    scanf("%d",&ebob);

    for(i=2;i<=sayi_sayisi;i++) {
        printf("sayi girin: ");
        scanf("%d",&sayi);
        ebob=ebob_bul(ebob,sayi);
    }
    printf("obeb: %d\n",ebob);

    return 0;
}

