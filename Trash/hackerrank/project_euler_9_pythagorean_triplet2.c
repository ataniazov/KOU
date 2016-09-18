#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long a,b,c;

        scanf("%Lu",&N);

        if(N%3==0 && N%4==0) {
            b=(N/3);
            a=(N/4);
            c=sqrt(pow(a,2)+pow(b,2));
            printf("%Lu\n",a*b*c);
        }
        else printf("%d\n",EOF);
    }
    return 0;
}

