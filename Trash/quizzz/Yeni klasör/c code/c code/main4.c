int sayi = 55;

int main() {
    int i;
    int j;

    for (i = 0 ; i < 30 ; i++) {
        int ikinin_kuvveti = 1;
        for (j = 1 ; j <= i ; j++) {
	    ikinin_kuvveti = ikinin_kuvveti * 2;
        }
        if ((sayi/ikinin_kuvveti) % 2 == 1) {
            printf("%d + ", ikinin_kuvveti);
        }
    }
    return 0;
}

