#include <stdio.h>

unsigned long long asal_toplam(

int main()
{
    unsigned long long sayi1,sayi2;

    printf("1. sayi giriniz: ");
    scanf("%Lu",&sayi1);

    printf("2. sayi giriniz: ");
    scanf("%Lu",&sayi2);

    printf("%Lu ve %Lu sayi araliginda toplam %Lu asal sayi var",asal_toplam(sayi1,sayi2));

    return 0;
}
