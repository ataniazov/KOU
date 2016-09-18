#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long i,j;
        unsigned long long total=2;
        int flag=0;

        scanf("%Lu",&N);

        for(i=3;i<=N;i++) {
            flag=0;
            for(j=2;j<=i/2;j++) {
                if(i%j==0) {
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                total+=i;
            }
        }
        if(N!=0 || N!=1) {
            printf("%Lu\n",total);
        }
    }
    return 0;
}

