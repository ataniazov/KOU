#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
        unsigned long long N, T;

        scanf("%Lu", &T);
        while (T--) {

                unsigned long long i;
                unsigned long long s1=5,s2=3;
                unsigned long long tmp,step=0;


                scanf("%Lu",&N);


                for(i=5;step<N;i++) {
                        s1 ^= s2;
                        s2 ^= s1;
                        s1 ^= s2;
                        s1 += s2;

                        tmp=s1;
                        step=0;
                        while(tmp>0) {
                                tmp/=10;
                                step++;
                        }
                }

                printf("%Lu\n",i);
        }

        return 0;
}
