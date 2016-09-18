#include <stdio.h>

int main()
{
    int x;
    int i=1;
    printf("Sayiyi giriniz: ");
    scanf("%d",&x);
    while(i<=x)
    {
        printf("%d\n",i);
        i++;
    }
    return 0;
}
