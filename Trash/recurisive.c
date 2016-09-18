#include <stdio.h>

void recurse(unsigned int i);
int factorial(int);

int main() {
	printf("%u\n",factorial(10));

	return 0;
}

void recurse(unsigned int i)
{
	printf("%d\n",i);
	if(i<10)
		recurse(i+1);
	printf("%d\n",i);
}
int factorial(int i)
{
	if(i < 0)
		return 0;
	return !i ? 1 : i * factorial(i - 1);
}
