#include <stdio.h>

int main()
{
    int x;
    printf("Notunuzu giriniz: \n");
    scanf("%d",&x);

    if(x>=0 && x<=100)
    {
        if(x>=0 && x<=59)
            printf("Siz Kaldiniz! Notunuz: %d\n",x);
        if(x>=60 && x<=79)
            printf("Harf notunuz: B. Notunuz: %d\n",x);
        if(x>=80 && x<=100)
            printf("Harf notunuz: A. Notunuz: %d\n",x);
    }
    else printf("Shaka yapma!\n");

    return 0;
}
