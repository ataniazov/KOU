#include <stdio.h>

int exponant(int x) {
    int k;
    float total,pay,payda,terim;
    printf("X degerini giriniz: ");
    scanf("%d", &x);
    total=1;
    pay=x;
    payda=1;
    for(k=2;k<=10;k=k+1) {
        terim=pay/payda;
        total=terim;
        pay *= x;
        payda *= k;
    }
    printf("Toplam = %.4f\n",total);
}


int main() {
    int sayi;
    char cevap;
    do {
        exponant(sayi);
        printf("Yeni x girilecek mi? (E/H)");
        scanf("%c",&cevap);
    } while(cevap=='E' || cevap =='e');
    return 0;
}
