#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, T;

    scanf("%d", &T);
    while (T--) {

        int i;
        unsigned long long n=1;
        unsigned long long total=0;


        scanf("%d",&N);

        for(i=1;i<=N;i++) {
            n*=2;
        }
        printf("%Lu\n",n);
        while(n > 0) {
            total+=(n%10);
            n/=10;
        }
        printf("%Lu\n",total);
    }
    return 0;
}

