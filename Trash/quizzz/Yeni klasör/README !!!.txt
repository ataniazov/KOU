#include <stdio.h>

int main() {
 printf("1: faktoriel\n");
 printf("2: ust\n");

 printf("giris:");
 int giris = getc(stdin);

 int i = 0;
 int sonuc;
 int sayi;


 switch (giris) {
 case '1': {
   printf("sayi giriniz:");
   scanf("%d", &sayi);
   sonuc = 1;
   for (i = 1 ; i <= sayi ; i++) {
     sonuc = sonuc * i;
   }
   printf("sonuc = %d\n", sonuc);
   break;
 }
 case '2': {
   printf("sayi giriniz:");
   scanf("%d", &sayi);
   sonuc = sayi;
   for (i = 2 ; i <= sayi ; i++) {
     sonuc = sonuc * sayi;
   }
   printf("sonuc = %d\n", sonuc);
   break;
 }
 default:
   printf("yanlis giris\n");
 }
}









#include<stdio.h>
#include<conio.h>

main()
{


       int n=5;
       int i;
       int j;
       
       /*printf("Boyut Giriniz : ");
       scanf("%d",&n);*/

       int icbosluk=-1;
       int disbosluk=n-1;
       
       
       for(i=1;i<=n;i++)
       {
         for(j=1;j<=disbosluk;j++)
         printf(" ");
         
         printf("*");

         if(i!=1)
         {
            for(j=1;j<=icbosluk;j++)
            printf(" ");
           
            printf("*");
         }
         printf("\n");
         disbosluk--;
         icbosluk+=2;
       }

       disbosluk=1;

       icbosluk-=4;
       
       for(i=1;i<=n-1;i++)
       {
         for(j=1;j<=disbosluk;j++)
         printf(" ");
         
         printf("*");
         
         if(i!=n-1)
         {
           for(j=1;j<=icbosluk;j++)
           printf(" ");
           
           printf("*");
         }
         printf("\n");

         disbosluk++;
         icbosluk-=2;
       }
         
       getch();
}