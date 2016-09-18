
int sayi = 28;

int main() {
    int i;

    for (i = 0 ; i < 30 ; i++) {
        if ((sayi >> i) % 2 == 1) {
            printf("%d + ", 1 << i);
        }
    }
    return 0;
}

