#include <stdio.h>

int main()
{
    int sayi1=0;
    int sayi2;
    int tmp;
    while(sayi1<500)
    {
        sayi1++;
        sayi2=1;
        tmp=0;
        while(sayi2<sayi1)
        {

            if(sayi1%sayi2==0)
            {
                //printf("%d\n",sayi2);
                tmp=tmp+sayi2;
            }
            sayi2++;
        }
        if(sayi1==tmp) {
            //printf("%d sayi Mukemmeldir!\n",sayi1);
        }
        else {
            //printf("%d sayi mukemmel degil.\n",sayi1);
        }
    }
    return 0;
}

