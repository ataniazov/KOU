#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long i,n1,n2,n3;
        unsigned long long sum=0;


        scanf("%Lu",&N);
        for(n1=1;n1<=N;n1++) {
            n2=0;
            n3=0;
            for(i=1;i<n1;i++) {
                if(n1%i==0) {
                    n2+=i;
                }
            }
            for(i=1;i<n2;i++) {
                if(total%i==0) {
                    n3+=i;
                }
            }
            if(n1==n3) {
                sum+=(n1+n2);
            }
        }
        printf("%Lu\n",sum);
    }

    return 0;
}
