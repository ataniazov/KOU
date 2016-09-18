#include<stdio.h>
#include<conio.h>

      main()
      {
      int x,y;
      int a,b,c,d,e;
      printf("5 basamakli bir sayi giriniz");
      scanf("%d",&x);
      y=x;
      a=y/10000;
      y=y-a*10000;
      b=y/1000;
      y=y-b*1000;
      c=y/100;
      y=y-c*100;
      d=y/10;
      y=y-d*10;
      e=y/1;

      if(a==e&&b==d&&c==c)
        printf("bu sayi polindroniktir.=%d",x);
      else
        printf("bu sayi polindromik degildir");
    getch();
      }
