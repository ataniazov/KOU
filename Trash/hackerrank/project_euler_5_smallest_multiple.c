#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long total;
        unsigned long long i;
        int status=0;


        scanf("%Lu",&N);
        total=N;
        while(status == 0) {
            i=2;
            while(i <= N) {
                if((total % i) == 0)  {
                    i++;
                }
                else {
                    total++;
                    break;
                }

            }
            if(i>N) status=1;
        }
        printf("%Lu\n",total);
    }
    return 0;
}

