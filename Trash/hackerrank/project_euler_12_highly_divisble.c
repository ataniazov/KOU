#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long i,j;
        unsigned long long answer=0,divisor=1,n;
        unsigned long long high_divisor=0;


        scanf("%Lu",&N);

        for(n=3,i=3;high_divisor<N;n+=i,i++) {
            divisor=1;
            for(j=2;j<=n/2;j++) {
                if(n%j==0) {
                    divisor++;
                }
            }
            if(high_divisor<divisor) {
                answer=n;
                high_divisor=divisor;
            }
        }

        printf("%Lu\n",answer);
    }
    return 0;
}

