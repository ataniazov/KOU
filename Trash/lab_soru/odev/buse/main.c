#include <stdio.h>
#include<math.h>
int main()
{
    int secim;
    float sayi, sonuc;
    printf("Bir sayi giriniz: ");
    scanf("%f", &sayi);
    printf("1: Sayinin karekokunu al\n2: Sayinin karesini al\n3: Sayinin mutlak degerini al\nSecim giriniz: ");
    scanf("%d", &secim);
    switch(secim)
    {
    case 1:
    {
//sayinin karekokunu al
        sonuc=sqrt(sayi);
        printf("sqrt(%f): %f\n",sayi,sonuc);
        break;
    }
    case 2:
    {
//sayinin karesini al
        sonuc=pow(sayi,2);
        printf("pow(%f,2): %f\n",sayi,sonuc);
        break;
    }
    case 3:
    {
//sayýnýn mutlak degerini al
        sonuc=fabs(sayi);
        printf("fabs(%f): %f\n",sayi,sonuc);
        break;
    }
defult:
    {
        printf("yanlis secim yaptiniz!\n");
        break;
    }

    }
    return 0;
}
