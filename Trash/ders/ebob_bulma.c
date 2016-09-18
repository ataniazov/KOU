#include <stdio.h>

int main() {
    int i,n,sayi,buyuk,ebob;
    printf("Kac sayi girilecek: ");
    scanf("%d",&n);

    buyuk=0;
    for(i=1;i<=n;i++) {

        printf("%d. sayi giriniz: ",i);
        scanf("%d",&sayi);

        if(buyuk<sayi) {
            if(buyuk%i==0 && sayi%i==0) {
                ebob=i;
            }
            buyuk=sayi;
        }
    }
    printf("ebob = %d",ebob);
    return 0;
}
