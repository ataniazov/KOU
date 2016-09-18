#include <stdio.h>

int main()
{
    	
    int sayi=0;
    int secim=1;

    while(secim==1)
    {
        printf("Sayi giriniz: ");
        scanf("%d",&sayi);
        if(sayi%2==0){
            printf("Sayi cifttir\n");
        } else {
            printf("Sayi tektir\n");
        }
        printf("Tekrar calishsin mi? 1:evet ");
        scanf("%d",&secim);
    }
	return 0;
}
