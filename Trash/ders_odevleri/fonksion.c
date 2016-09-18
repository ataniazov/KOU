#include <stdio.h>

void ucgen_ciz(int x) {
    int i,j;
    printf("\n");
    printf("Taban sayisini giriniz: ");
    scanf("%d",&x);
    for(i=1;i<=x;i++) {
        for(j=1;j<=i;j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}


void ters_ucgen_ciz(int x) {
    int i,j;
    printf("\n");
    printf("Taban sayisini giriniz: ");
    scanf("%d",&x);
    for(i=1;i<=x;i++) {
            for(j=1;j<=x-i+1;j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void kare_ciz(int x) {
    int i,j;
    printf("Taban sayisini giriniz: ");
    scanf("%d",&x);
    printf("\n");
    for(i=1;i<=x;i++) {
        for(j=1;j<=x;j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int sayi;
    ucgen_ciz(sayi);
    ters_ucgen_ciz(sayi);
    kare_ciz(sayi);
    return 0;
}
