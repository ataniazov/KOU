#include <stdio.h>

int main() {
    int x,y,i,j,n=0;

    printf("x: ");
    scanf("%d",&x);
    printf("y: ");
    scanf("%d",&y);
    printf("\n");
    for(i=1;i<=x-1;i++) {
        for(j=1;j<=x-i;j++) {
            printf(" ");
        }
        printf("x");
        for(j=1;j<i;j++) {
            printf(" ");
        }
        for(j=1;j<i-1;j++) {
            printf(" ");
        }
        if(n==0) n++;
        else printf("x");
        printf("\n");
    }
    for(i=1;i<=x*2-1;i++) {
        printf("x");
    }
    printf("\n");
    return 0;
}
