#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long s=2;
        unsigned long long i;
        unsigned long long tmp=0;

        scanf("%Lu",&N);

        while(s < N) {
            if(N%s==0) {
                int flag=0;

                for(i=2;i<=(s/2);++i) {
                    if(s%i==0) {
                        flag=1;
                        break;
                    }
                }
                if(flag==0) tmp=s;
            }
            s++;
        }
        if(tmp==0) {
            printf("%Lu\n",N);
        }
        else printf("%Lu\n",tmp);
    }
    return 0;
}

