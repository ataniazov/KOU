#include<stdio.h>
#include<conio.h>

main()
{
      int saat,dk,saniye,x,zmn;
      printf("Sureyi saniye cinsinden giriniz:");
      scanf("%d",&zmn);
      saat=zmn /3600;
      x=zmn % 3600;
      dk=x / 60;
      saniye=x % 60;
      printf("Saat Dakika Saniye\n");
      printf(".................. \n");
      printf("%d  /%d  /%d\t",saat,dk,saniye);
      getch();
      return 0;
}



