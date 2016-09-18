#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long i,n,chain;
        unsigned long long long_chain=0;
        unsigned long long answer=0;


        scanf("%Lu",&N);

        for(i=1;i<=N;i++) {
            n=i;
            chain=1;
            while(n>1) {
                    if(n%2==0) {
                        n/=2;
                        chain++;
                    }
                    else {
                        n=(3*n)+1;
                        chain++;
                    }
            }
            if(chain>=long_chain) {
                answer=i;
                long_chain=chain;
            }
        }
        printf("%Lu\n",answer);
    }
    return 0;
}

