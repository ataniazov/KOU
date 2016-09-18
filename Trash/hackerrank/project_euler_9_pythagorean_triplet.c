#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, T;

    scanf("%d", &T);
    while (T--) {

        int a,b,c;
        int status=0;

        scanf("%d",&N);
        for (a = 1; a <= N/3; a++) {
            int b;
            for (b = a + 1; b <= N/2; b++) {
                int c = N - a - b;
                if ( a*a + b*b == c*c ) {
                    printf("%d\n",a*b*c);
                    status=1;
                }
            }
        }
        if(status==0) printf("%d\n",EOF);
    }
    return 0;
}

