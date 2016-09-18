#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long N, T;

    unsigned long long s1=5,s2=3,i=5;
    unsigned long long tmp,step=0,n;

    scanf("%Lu", &T);
    while (T--) {

        step=0;

        scanf("%Lu",&N);
        if(N==1) printf("1\n");
        else {
            if(n>N) {
                s1=5;s2=3;i=5;
            }
            n=N;
            while(step<N) {
                s1 ^= s2; 
                s2 ^= s1; 
                s1 ^= s2; 
                s2 += s1; 

                i++;

                tmp=s2;
                step=0;
                while(tmp>0) {
                    tmp/=10;
                    step++;
                }
            }   

            printf("%Lu\n",i);
        }   
    }
    return 0;
}
