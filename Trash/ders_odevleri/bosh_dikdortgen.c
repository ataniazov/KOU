#include <stdio.h>

int main() {
    int x,y,i,j;

    printf("x: ");
    scanf("%d",&x);
    printf("y: ");
    scanf("%d",&y);
    printf("\n");
    for(i=1;i<=x;i++) {
        printf("x");
    }
    printf("\n");
    for(i=1;i<=x-2;i++) {
        printf("x");
        for(j=1;j<=x-2;j++) {
            printf("*");
        }
        printf("x");
        printf("\n");
    }
    for(i=1;i<=x;i++) {
        printf("x");
    }
    printf("\n");
    return 0;
}
