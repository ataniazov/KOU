#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, T;

    scanf("%d", &T);
    while (T--) {

        int total=0;
        int i=3;


        scanf("%d",&N);

        while(i < N) {
            if((i % 3) == 0 || (i % 5) == 0) {
                total += i;
            }
            i++;
        }

        printf("%d\n",total);
    }
    return 0;
}
