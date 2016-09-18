#include <stdio.h>
int f(int x);
int main() {
	int sonuc = f(3);
	printf("3! = %d\n", sonuc);
	sonuc = f(6);
	printf("6! = %d\n", sonuc);
	return 0;
}
// faktoriyel fonksiyonu (recursive hesaplama yontemi)
int f(int x) {
	if (x == 1)
		return 1;
	else
		return x * f(x-1);
}
