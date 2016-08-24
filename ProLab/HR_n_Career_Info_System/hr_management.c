/**
 * Ata Niyazov 130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Insan kaynaklari ve kariyer bilgi sistemi
 */

/**
 * hr_management.c
 */

#include "headfirst.h"

void hr_management(struct PersonaNode ** RootNode) {
    bool done = false;
    while(!done) {
        getchar();
        fflush(stdin);
        system("clear");
        printf("╔═══════════════════════════════════════════════════════════════╗\n");
        printf("║\t    Eleman Arayan Şirketin Kullanacağı Bölüm\t\t║\n");
        printf("╚═══════════════════════════════════════════════════════════════╝\n");
        printf("\t\t\t    ┌──────┐\t\t\t\n");
        printf("┌───────────────────────────┤ MENÜ ├────────────────────────────┐\n");
        printf("│\t\t\t    └──────┘\t\t\t\t│\n");
        printf("│\t\t\t\t\t\t\t\t│\n");
        printf("│ [1] Tüm kişilerin adlarını düzeyleri ile birlikte listele\t│\n");
        printf("│ [2] İşe başvuran tüm adayların bilgilerini listele\t\t│\n");
        printf("│ [3] Adından kişi arama, tüm bilgilerini listele\t\t│\n");
        printf("│ [4] Filtreleme işlemleri\t\t\t\t\t│\n");

        //printf("│ [4] En az lisans mezunu olan kişileri listele\t\t\t│\n");
        printf("│\t\t\t\t\t\t\t\t│\n");
        printf("│ [0] ANA MENÜ\t\t\t\t\t\t\t│\n");
        printf("│\t\t\t\t\t\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\t   Lütfen seçiminizi yapınız\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t SEÇİMİNİZ: ");
        char buffer[2];
        fgets(buffer, sizeof(buffer), stdin);
        int choise = atoi(buffer);
        switch(choise) {
        case 0:
            done = true;
            break;
        case 1:
            ListAllOrder(*RootNode);
            break;
        case 2:
            ListAllPersona(*RootNode);
            break;
        case 3:
            ShowPersonaNode(*RootNode);
            break;
        case 4:
            FilterPersona(*RootNode);
            break;
        default:
            printf("\n┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t\t\t HATALI SEÇİM!\t\t\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
            fflush(stdin);
            system("sleep 1.2");
            break;
        }
    }
}

void ListAllOrder(struct PersonaNode * RootNode) {
    system("clear");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t\t   PRE-ORDER\t\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌────┬──────────────────────────┐\n");
    printf("│ ID │         Ad-Soyad         │\n");
    printf("├────┼──────────────────────────┤\n");
    Pre_Order(RootNode);
    printf("└────┴──────────────────────────┘\n");

    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t\t   IN-ORDER\t\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌────┬──────────────────────────┐\n");
    printf("│ ID │         Ad-Soyad         │\n");
    printf("├────┼──────────────────────────┤\n");
    In_Order(RootNode);
    printf("└────┴──────────────────────────┘\n");

    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t\t  POST-ORDER\t\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌────┬──────────────────────────┐\n");
    printf("│ ID │         Ad-Soyad         │\n");
    printf("├────┼──────────────────────────┤\n");
    Post_Order(RootNode);
    printf("└────┴──────────────────────────┘\n");

    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t      Ağacın derinliği: %d\t\t\t│\n",Max_Depth(RootNode));
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t\tEleman Sayısı: %d\t\t\t│\n",PersonaCounter(RootNode));
    printf("└───────────────────────────────────────────────────────────────┘\n");

    getchar();
}


void ListAllPersona(struct PersonaNode * RootNode) {
    system("clear");
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║\t     İşe başvuran tüm adayların bilgileri\t\t║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    struct PersonaLinkList * head = NULL;
    PersonaTree2LinkList(&head, RootNode);
    head = ID_SortPersonaLinkList(head);
    PrintLinkList(head);
    getchar();
    DestroyPersonaLinkList(&head);
}

void FilterPersona(struct PersonaNode * RootNode) {
    getchar();
    fflush(stdin);
    system("clear");
    char buffer[MAX_ARRAY_SIZE];
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║\t\t      Filtreleme İşlemleri\t\t\t║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\tLütfen Yabancı Dil bilgilerinizi listeden seçiniz\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[+]───────────────────────────────────────────────────────────┐\n");
    printf("│ [1] En az Lisans mezunu olan kişileri listele\t\t\t│\n");
    printf("│ [2] İngilizce bilen kişileri listele\t\t\t\t│\n");
    printf("│ [3] Birden fazla dil bilen kişileri listele\t\t\t│\n");
    printf("│ [4] Girilecek minimum deneyim süresine göre başvuru listele   │\n");
    printf("│ [5] Deneyimsiz kişileri listele\t\t\t\t│\n");
    printf("│ [6] Girilecek olan yaş altındaki kişileri listele\t\t│\n");
    printf("│ [7] Belirli tip ehliyeti olan kişileri listele\t\t│\n");
    printf("│\t\t\t\t\t\t\t\t│\n");
    printf("│ [Enter] IPTAL\t\t\t\t\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│    Çoklu Filtre seçimi için seçimler arasına boşluk koyunuz!  │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Filtreleme seçimi: ");
    struct PersonaLinkList * head = NULL;
    PersonaTree2LinkList(&head, RootNode);
    head = ID_SortPersonaLinkList(head);

    fgets(buffer, sizeof(buffer), stdin);

    if(strchr(buffer, '1')) {
        head = LeastDegree(head);
    }
    if(strchr(buffer, '2')) {
        head = knowEnglish(head);
    }
    if(strchr(buffer, '3')) {
        head = MoreThanOneLingo(head);
    }
    if(strchr(buffer, '4')) {
        head = WorkedDuration(head);
    }
    if(strchr(buffer, '5')) {
        head = NotWorked(head);
    }
    if(strchr(buffer, '6')) {
        head = MaxAge(head);
    }
    if(strchr(buffer, '7')) {
        head = DriverStatus(head);

    }
    printf("┌────┬──────────────────────────┐\n");
    printf("│ ID │         Ad-Soyad         │\n");
    printf("├────┼──────────────────────────┤\n");
    PrintFilteredLinkList(head);
    printf("└────┴──────────────────────────┘\n");

    if(wantToPrint()) {
        PrintLinkList2File("printer.txt", head);
    }

    getchar();
    DestroyPersonaLinkList(&head);
}

struct PersonaLinkList * LeastDegree(struct PersonaLinkList * head) {
    if(head == NULL) {
        return head;
    } else {
        int i = 0;
        int N = PersonaLinkCounter(head);
        while(i <= N) {
            struct PersonaLinkList * tail = head;
            while(tail != NULL) {
                if(!isLeastDegree(tail->Persona->institute)) {
                    head = DeletePersonaLinkList(head, tail->Persona->name);
                    break;
                }
                tail = tail->next;
            }
            i++;
        }
        return head;
    }
}

bool isLeastDegree(struct edu_status * institute) {
    if(institute != NULL) {
        struct edu_status * last = NULL;
        for(last = institute; last != NULL; last = last->next) {
            if(last->edu_value >= 20) {
                return true;
            }
        }
    }
    return false;
}

void PrintFilteredLinkList(struct PersonaLinkList * head) {
    struct PersonaLinkList * tail = head;
    while(tail != NULL) {
        printf("│%4d│%26s│\n",tail->Persona->id,tail->Persona->name);
        tail = tail->next;
    }
}

struct PersonaLinkList * knowEnglish(struct PersonaLinkList * head) {
    if(head == NULL) {
        return head;
    } else {
        int i = 0;
        int N = PersonaLinkCounter(head);
        while(i <= N) {
            struct PersonaLinkList * tail = head;
            while(tail != NULL) {
                if(strstr(tail->Persona->lingo, "ingilizce") == NULL) {
                    head = DeletePersonaLinkList(head, tail->Persona->name);
                    break;
                }
                tail = tail->next;
            }
            i++;
        }
        return head;
    }
}

struct PersonaLinkList * MoreThanOneLingo(struct PersonaLinkList * head) {
    if(head == NULL) {
        return head;
    } else {
        int i = 0;
        int N = PersonaLinkCounter(head);
        while(i <= N) {
            struct PersonaLinkList * tail = head;
            while(tail != NULL) {
                if(lingoCounter(tail->Persona) < 2) {
                    head = DeletePersonaLinkList(head, tail->Persona->name);
                    break;
                }
                tail = tail->next;
            }
            i++;
        }
        return head;
    }
}

int lingoCounter(struct PersonaNode * Persona) {
    int counter = 0;

    if(strstr(Persona->lingo, "ingilizce") != NULL) {
        counter++;
    }
    if(strstr(Persona->lingo, "fransizca") != NULL) {
        counter++;
    }
    if(strstr(Persona->lingo, "almanca") != NULL) {
        counter++;
    }
    if(strstr(Persona->lingo, "arapca") != NULL) {
        counter++;
    }
    if(strstr(Persona->lingo, "cince") != NULL) {
        counter++;
    }
    if(strstr(Persona->lingo, "japonca") != NULL) {
        counter++;
    }
    if(strstr(Persona->lingo, "ispanyolca") != NULL) {
        counter++;
    }
    if(strstr(Persona->lingo, "rusca") != NULL) {
        counter++;
    }
    return counter;
}

struct PersonaLinkList * NotWorked(struct PersonaLinkList * head) {
    if(head == NULL) {
        return head;
    } else {
        int i = 0;
        int N = PersonaLinkCounter(head);
        while(i <= N) {
            struct PersonaLinkList * tail = head;
            while(tail != NULL) {
                if(!(tail->Persona->workplace == NULL)) {
                    head = DeletePersonaLinkList(head, tail->Persona->name);
                    break;
                }
                tail = tail->next;
            }
            i++;
        }
        return head;
    }
}

struct PersonaLinkList * WorkedDuration(struct PersonaLinkList * head) {

    float duration;

    do {
        duration = get_MinDuration();
    } while(duration <= 0);

    if(head == NULL) {
        return head;
    } else {
        int i = 0;
        int N = PersonaLinkCounter(head);
        while(i <= N) {
            struct PersonaLinkList * tail = head;
            while(tail != NULL) {
                if(!isWorkedDuration(head->Persona->workplace, duration)) {
                    head = DeletePersonaLinkList(head, tail->Persona->name);
                    break;
                }
                tail = tail->next;
            }
            i++;
        }
        return head;
    }
}

float get_MinDuration() {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t    Lütfen minimum Deneyim Süresini giriniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│    Deneyim Süresi sadece (0, 50] arası degerler geçerlidir!   │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Deneyim Süresi: ");

    fgets(buffer, sizeof(buffer), stdin);

    float value = atof(buffer);

    if(value > 0 && value <= 50) {
        return value;
    }
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t Hatali Deneyim Süresi girisi!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    return -1;
}

bool isWorkedDuration(struct work_exper * workplace, float duration) {
    if(workplace != NULL) {
        struct work_exper * last = NULL;
        for(last = workplace; last != NULL; last = last->next) {
            if(last->duration >= duration) {
                return true;
            }
        }
    }
    return false;
}


struct PersonaLinkList * MaxAge(struct PersonaLinkList * head) {

    int age;

    do {
        age = get_Age();
    } while(age < 10);

    if(head == NULL) {
        return head;
    } else {
        int i = 0;
        int N = PersonaLinkCounter(head);
        while(i <= N) {
            struct PersonaLinkList * tail = head;
            while(tail != NULL) {
                if((2016 - (tail->Persona->dob)) > age) {
                    head = DeletePersonaLinkList(head, tail->Persona->name);
                    break;
                }
                tail = tail->next;
            }
            i++;
        }
        return head;
    }
}

int get_Age() {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\tLütfen Max. Yaş değerini giriniz\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│   Max. Yaş değeri sadece [10, 60] arası degerler geçerlidir!  │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Max. Yaş değeri: ");

    fgets(buffer, sizeof(buffer), stdin);

    int value = atoi(buffer);

    if(value >= 10 && value <= 60) {
        return value;
    }
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t Hatali Max. Yaş değeri girisi!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    return -1;
}

struct PersonaLinkList * DriverStatus(struct PersonaLinkList * head) {

    int driver;

    do {
        driver = get_Driver();
    } while(driver < 1 || driver > 9);

    char buffer[MAX_ARRAY_SIZE];

    if(driver == 1) {
        strcpy(buffer, "A1");
    } else if(driver == 2) {
        strcpy(buffer, "A2");
    } else if(driver == 3) {
        strcpy(buffer, "B");
    } else if(driver == 4) {
        strcpy(buffer, "C");
    } else if(driver == 5) {
        strcpy(buffer, "D");
    } else if(driver == 6) {
        strcpy(buffer, "E");
    } else if(driver == 7) {
        strcpy(buffer, "F");
    } else if(driver == 8) {
        strcpy(buffer, "G");
    } else if(driver == 9) {
        strcpy(buffer, "H");
    }

    if(head == NULL) {
        return head;
    } else {
        int i = 0;
        int N = PersonaLinkCounter(head);
        while(i <= N) {
            struct PersonaLinkList * tail = head;
            while(tail != NULL) {
                if(strstr(tail->Persona->driver, buffer) == NULL) {
                    head = DeletePersonaLinkList(head, tail->Persona->name);
                    break;
                }
                tail = tail->next;
            }
            i++;
        }
        return head;
    }
}

int get_Driver() {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t Lütfen Ehliyet türünü giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│  Ehliyet türü sadece A1,A2,B,C,D,E,F,G,H degerler geçerlidir! │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Ehliyet türü: ");

    fgets(buffer, sizeof(buffer), stdin);
    buffer[0] = toupper(buffer[0]);

    if(strstr(buffer,"A1")) {
        return 1;
    } else if(strstr(buffer,"A2")) {
        return 2;
    } else if(strstr(buffer,"B")) {
        return 3;
    } else if(strstr(buffer,"C")) {
        return 4;
    } else if(strstr(buffer,"D")) {
        return 5;
    } else if(strstr(buffer,"E")) {
        return 6;
    } else if(strstr(buffer,"F")) {
        return 7;
    } else if(strstr(buffer,"G")) {
        return 8;
    } else if(strstr(buffer,"H")) {
        return 9;
    }

    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t Hatali Ehliyet türü girisi!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    return 0;
}

bool wantToPrint() {
    bool toPrint = false;
    bool done = false;

    while(!done) {
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\t  Çıktı almak istiyormusunuz?\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│   Evet için 'E' veya 'e', Hayır için 'H' veya 'h' giriniz!    │\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t SEÇİMİNİZ: ");
        char choise = fgetc(stdin);
        getchar();
        fflush(stdin);

        if(choise == 'E' || choise == 'e') {
            toPrint = true;
            done = true;
        } else if(choise == 'H' || choise == 'h') {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t\t Yazdırma işlemi gerçekleşmedi\t\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
            done = true;
        } else {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t   Hatalı giriş! Lütfen girişi tekrarlayınız\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        }
    }
    return toPrint;
}

void PrintLinkList2File(char * filename,struct PersonaLinkList * head) {
    FILE * fp;

    // Dosyayi okuma modunda ac
    if ((fp = fopen(filename, "a")) == NULL) {
        printf("%s dosyasi acilamadi!\n",filename);
        exit(EXIT_FAILURE);
    }
    fprintf(fp,"┌────┬──────────────────────────┐\n");
    fprintf(fp,"│ ID │         Ad-Soyad         │\n");
    fprintf(fp,"├────┼──────────────────────────┤\n");

    struct PersonaLinkList * tail = head;

    while(tail != NULL) {
        fprintf(fp,"│%4d│%26s│\n",tail->Persona->id,tail->Persona->name);
        tail = tail->next;
    }

    fprintf(fp,"└────┴──────────────────────────┘\n");
    fclose(fp);
}
