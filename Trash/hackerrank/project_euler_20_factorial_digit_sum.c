#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long i;
        unsigned long long total=0,factor=1;

        scanf("%Lu",&N);
        if(N>0) {
            factor=1;
            total=0;

            for(i=1;i<=N;i++) {
                factor*=i;
            }
            while(factor>0) {
                total+=(factor%10);
                factor/=10;
            }
            printf("%Lu\n",total);
        }
        else printf("1\n");
    }
    return 0;
}
