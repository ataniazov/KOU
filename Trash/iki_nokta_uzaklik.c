#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Nokta {
	int x;
	int y;
};

int main() {

	system("clear");

	struct Nokta nokta_1;
	struct Nokta nokta_2;
	double uzaklik;

	printf("1. Nokta koordinatlarini giriniz: ");
	scanf("%d %d",&nokta_1.x,&nokta_1.y);

	printf("2. Nokta koordinatlarini giriniz: ");
	scanf("%d %d",&nokta_2.x,&nokta_2.y);

	uzaklik = sqrt(pow((nokta_1.x - nokta_2.x),2) + pow((nokta_1.y - nokta_2.y),2));

	printf("=====================================\n");

	printf("Iki nokta arasindaki uzaklik %f\n",uzaklik);

	return 0;
}
