#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long i=1;
        unsigned long long s1=1,s2=1;
        unsigned long long total=0;


        scanf("%Lu",&N);

        while(s1 < N) {
            if(s1%2==0) {
                total+=s1;
            }

            s1 ^= s2;
            s2 ^= s1;
            s1 ^= s2;
            s1 += s2;
        }

        printf("%Lu\n",total);
    }

    return 0;
}
