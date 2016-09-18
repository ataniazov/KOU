#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, T;

    scanf("%d", &T);
    while (T--) {

        int total;
        int i;
        int status=0;
        int mirror=0,a=0,b=0,c=0;

        scanf("%d",&N);
        total=N;
        while(status==0) {
            i=100;
            while(i <= 999) {
                if((total % i) == 0 && (total/i) <= 999) {
                    c = ((total%1000)%10)*100;
                    b = (((total%1000)/10)%10)*10;
                    a = (total%1000)/100;
                    mirror = c+b+a;
                    if((total/1000) == mirror) {
                        status=1;
                    }
                    break;
                }
                else i++;
            }
            if(status==0) total--;
        }
        printf("%d\n",total);
    }
    return 0;
}

