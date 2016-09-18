#include <stdio.h>

int main() {
    unsigned long long N, T;

    scanf("%Lu", &T);
    while (T--) {

        unsigned long long i;
        unsigned long long n=2,s=0;
        int status=0,flag=0;

        scanf("%Lu",&N);

        while(status==0) {
            flag=0;
            for(i=2;i<=n/2;++i) {
                if(n%i==0) {
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                s++;
                if(s == N) {
                    status=1;
                }
            }
            if(status==0) n++;
        }
        printf("%Lu\n",n);
    }
    return 0;
}

