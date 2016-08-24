/**
 * Ata Niyazov 130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Insan kaynaklari ve kariyer bilgi sistemi
 */

/**
 * main.c
 */

#include "headfirst.h"

int main() {
    struct PersonaNode * RootNode = NULL;
    Tree_Import(PERSONA, &RootNode);

    bool done = false;
    while(!done) {
        getchar();
        fflush(stdin);
        system("clear");
        printf("╔═══════════════════════════════════════════════════════════════╗\n");
        printf("║\t    İNSAN KAYNAKLARI ve KARİYER BİLGİ SİSTEMİ\t\t║\n");
        printf("╚═══════════════════════════════════════════════════════════════╝\n");
        printf("\t\t\t    ┌──────┐\t\t\t\n");
        printf("┌───────────────────────────┤ MENÜ ├────────────────────────────┐\n");
        printf("│\t\t\t    └──────┘\t\t\t\t│\n");
        printf("│\t\t\t\t\t\t\t\t│\n");
        printf("│ [1] İş Başvurusu Yapan Kişilerin Kullanacağı Bölüm\t\t│\n");
        printf("│ [2] Eleman Arayan Şirketin Kullanacağı Bölüm\t\t\t│\n");
        printf("│\t\t\t\t\t\t\t\t│\n");
        printf("│ [0] ÇIKIŞ\t\t\t\t\t\t\t│\n");
        printf("│\t\t\t\t\t\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\t   Lütfen seçiminizi yapınız\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t  SEÇİMİNİZ: ");
        char buffer[2];
        fgets(buffer, sizeof(buffer), stdin);

        int choise = atoi(buffer);

        switch(choise) {
        case 0:
            done = true;
            break;
        case 1:
            job_application(&RootNode);
            break;
        case 2:
            hr_management(&RootNode);
            break;
        default:
            printf("\n┌─[!]───────────────────────────────────────────────────┐\n");
            printf("│\t\t     HATALI SEÇİM!\t\t\t│\n");
            printf("└───────────────────────────────────────────────────────┘\n");
            system("sleep 1.2");
            break;
        }
    }

    //Tree_Export(PERSONA, RootNode);
    return 0;
}
