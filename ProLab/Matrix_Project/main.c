/**
 * Ata Niyazov  130201108
 */

#include "headfirst.h"
#include "artwork.h"

/**
 * Programin main kismi
 */

int main(int argc, char* argv[])
{
    init_allegator();
    game_loop();
    kill_allegator();

    //get_hadamard(MATRIS);
    int mtrx_size = get_mtrx_size();
    get_mtrx_elem(mtrx_size);

    int secim = 0;

    do
    {
        printf("\n");

        printf("1 - Hadamard\n");
        printf("2 - MDS\n");
        printf("3 - Simetrik\n");
        printf("4 - Dairesel\n");
        printf("Islem seciminizi yapiniz: ");

        scanf("%d",&secim);
        getchar();

        if(secim < 1 || secim > 4)
        {
            printf("Hatali islem secimi!\n");
            printf("Lutfen tekrar deneyin\n");
        }
    }
    while(secim < 1 || secim > 4);

    int mtrx_file_size = get_file_mtrx_size(MATRIS);

    switch(secim)
    {
    case 1:
        if(mtrx_file_size == 4 || mtrx_file_size == 8 || mtrx_file_size == 16)
        {
            get_hadamard(MATRIS);
        }
        else
        {
            printf("Matrisin boyutu 4x4, 8x8, 16x16 farkli oldugu icin hadamard islemini secemezsiniz!\n");
        };
        break;
    case 2:
        get_mds(MATRIS);
        break;
    case 3:
        get_simetrik(MATRIS);
        break;
    case 4:
        get_dairesel(MATRIS);
        break;
    }
    return 0;
}
