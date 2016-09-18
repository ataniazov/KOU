#include <stdio.h>

int main() {

	int i,j;
	int dizi[10];

	int a = 0;

	int *p;
	
	p = &a;

	printf("p = &a : %d\nsizeof p %u\n",*p,sizeof(p));

	for(i=0;i<10;i++) {
		dizi[i] = i+1;
	}
	for(i=0;i<10;i++) {
		printf("%d ",dizi[i]);
	}



	return 0;
}
