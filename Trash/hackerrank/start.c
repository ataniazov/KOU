#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long i=1;
        unsigned long long s1=0,s2=0;
        unsigned long long total=0;


        scanf("%Lu",&N);

        while(i <= N) {
            s1 += pow(i,2);
            s2 += i;
            i++;
        }
        total = (pow(s2,2))-s1;
        printf("%Lu\n",total);
    }
    return 0;
}

