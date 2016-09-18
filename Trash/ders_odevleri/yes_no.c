#include<stdio.h>
#include<stdlib.h>

int main() {
    char cevap;
    do{
        printf("Hello World!\n");
        printf("Tekrar istermisiniz (E/H): ");
        scanf("%c",&cevap);
    } while(cevap=='E' || cevap=='e');

    return 0;
}
