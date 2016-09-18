#include <stdio.h>

int main() {
    int x,y,i,j;

    printf("x: ");
    scanf("%d",&x);
    printf("y: ");
    scanf("%d",&y);
    printf("\n");
    for(i=1 ; i<=x ; i++)
        printf(" ");
    printf("a\n");
    for(i=1;i<=x;i++) {
        for(j=1;j<=x-i;j++) {
            printf(" ");
        }
        printf("a");
        for(j=1;j<=i;j++) {
            printf("x");
        }
        for(j=1;j<i;j++) {
            printf("y");
        }
        printf("a");
        printf("\n");
    }
    for(i=1;i<=y;i++) {
        printf("a");
    }
    return 0;
}
