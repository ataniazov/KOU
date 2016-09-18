#include <stdio.h>
#include<math.h>

int main()
{
    int sayi=0;
    int toplam=0;
    int sayac=0;
    float ortalama=0;

    printf("sayi giriniz (sonlandirmak icin -1): ");
    scanf("%d",&sayi);

    while(sayi != EOF)
    {
        sayac++;
        toplam=toplam+sayi;
        printf("sayi giriniz (sonlandirmak icin -1): ");
        scanf("%d",&sayi);
    }

    ortalama=toplam/sayac;
    
    printf("Ortalama: %f, Toplam: %d, Sayac: %d",ortalama,toplam,sayac);

    return 0;
}
