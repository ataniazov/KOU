// Ata Niyazov   130201108   20

#include <stdio.h>
#include <stdlib.h>

int karakter_sayisi(const char *s);
int cumle_kelime(const char *s);

int main()
{
    char cumle[100];
    int kelime_sayisi;

    printf("Cumle giriniz: ");

    gets(cumle);

    printf("\nGirilen karakter sayisi: %d\n\n",karakter_sayisi(cumle));

    kelime_sayisi = cumle_kelime(cumle);

    printf("kelime sayisi: %d\n\n",kelime_sayisi);

    return 0;
}

int karakter_sayisi(const char *s) {
        int i;
        for (i = 0 ; s[i] != '\0' ; i++) {
                /* bos dongu */
        }
        return i;
}

int cumle_kelime(const char *s) {

    int i;
    int kelime_sayisi = 1;
    int karakter_say = karakter_sayisi(s);

    printf("Cumledeki kelimeler:\n");

    for(i = 0; i <= karakter_say; i++) {

        if(s[i] == ' ') {
            printf("\n");
            kelime_sayisi++;
        } else {
                printf("%c",s[i]);
        }
    }
    printf("\n\n");

    return kelime_sayisi;
}
