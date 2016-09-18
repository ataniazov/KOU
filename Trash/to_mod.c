#include <stdio.h>

void itob(int N, char *s, unsigned int b);

int main()
{
	char s[100];
	return 0;
}

void itob(int N, char *s, unsigned int b)
{
	int i = 0;
	do {
		*(s + (i++)) = N % b;

	} while ((N /= b) > 0);
}

