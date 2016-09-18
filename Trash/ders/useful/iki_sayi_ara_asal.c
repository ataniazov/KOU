#include <stdio.h>
int asal_sayisi(int ilk, int son);
int asal_mi(int x);
int main() {
	int ilk = 100, son = 300;
	int S;
	S = asal_sayisi(ilk, son);
	printf("[%d, %d] arasinda %d tane asal sayi vardir", ilk, son, S);
	return 0;
}
int asal_sayisi(int ilk, int son) {
	int i;
	int S = 0;
	for (i = ilk ; i <= son ; i++) {
		if ( asal_mi(i) == 1 )
			S++;
	}
	return S;
}
int asal_mi(int x) {
	int i;
	for (i = 2 ; i < x ; i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}
