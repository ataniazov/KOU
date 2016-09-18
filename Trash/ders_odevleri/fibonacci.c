#include <stdio.h>

int main()
{
    int s1=1;
    int s2=1;
    int tmp;

    printf("1\n");
    while(s1<10000)
    {
        printf("%d\n",s1);
        tmp=s1;
        s1=s2+s1;
        s2=tmp;
    }
    return 0;
}
