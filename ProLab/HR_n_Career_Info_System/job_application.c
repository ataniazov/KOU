/**
 * Ata Niyazov 130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Insan kaynaklari ve kariyer bilgi sistemi
 */

/**
 * job_application.c
 */

#include "headfirst.h"

void job_application(struct PersonaNode ** RootNode) {
    getchar();
    fflush(stdin);
    bool done = false;
    while(!done) {
        system("clear");
        printf("╔═══════════════════════════════════════════════════════════════╗\n");
        printf("║\tİş Başvurusu Yapan Kişilerin Kullanacağı Bölüm\t\t║\n");
        printf("╚═══════════════════════════════════════════════════════════════╝\n");
        printf("\t\t\t    ┌──────┐\t\t\t\n");
        printf("┌───────────────────────────┤ MENÜ ├────────────────────────────┐\n");
        printf("│\t\t\t    └──────┘\t\t\t\t│\n");
        printf("│\t\t\t\t\t\t\t\t│\n");
        printf("│ [1] Sisteme kayıt (kendi kişisel bilgilerini girme)\t\t│\n");
        printf("│ [2] Sistemdeki bilgileri görüntüle\t\t\t\t│\n");
        printf("│ [3] Sistemden çıkma (bilgilerini silme)\t\t\t│\n");
        printf("│ [4] Sistemdeki bilgileri güncelleme\t\t\t\t│\n");
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
            MakeNewPersona(RootNode);
            break;
        case 2:
            ShowPersonaNode(*RootNode);
            break;
        case 3:
            ShowAndDeletePersonaNode(RootNode);
            break;
        case 4:
            UpdatePersona(RootNode);
            break;
        default:
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t\t\t HATALI SEÇİM!\t\t\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
            system("sleep 1.2");
            break;
        }
    }
}

void MakeNewPersona(struct PersonaNode ** RootNode) {
    getchar();
    fflush(stdin);
    system("clear");

    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║\tSisteme kayıt (kendi kişisel bilgilerini girme)\t\t║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\tTürkçe karakter kullanmayınız!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");

    struct PersonaNode * NewPersona = malloc(sizeof(struct PersonaNode));

    NewPersona->institute = NULL;
    NewPersona->workplace = NULL;

    NewPersona->left = NULL;
    NewPersona->right = NULL;

    NewPersona->id = 1+LAST_ID;

    get_PersonaName(&NewPersona);
    printf("\n");
    get_PersonaAddress(&NewPersona);
    printf("\n");
    get_PersonaPhone(&NewPersona);
    printf("\n");
    get_PersonaEmail(&NewPersona);
    printf("\n");
    while(!get_PersonaDOB(&NewPersona));
    printf("\n");
    get_PersonaLingo(&NewPersona);
    printf("\n");
    get_PersonaDriver(&NewPersona);
    printf("\n");

    if(wantEduStatus()) {
        get_PersonaEdu(&(NewPersona->institute));
    }

    if(wantWorkExper()) {
        get_PersonaWork(&(NewPersona->workplace));
    }

    system("clear");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t      Lütfen Bilgilerinizi Kontrol Ediniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printPersonaNode(NewPersona);
    getchar();

    if(wantToSave()) {
        LAST_ID = NewPersona->id;
        Insert_Node(RootNode, NewPersona);
    } else {
        NewPersona->institute = Destroy_Edu_List(NewPersona->institute);
        NewPersona->workplace = Destroy_Work_List(NewPersona->workplace);
        free(NewPersona);
        NewPersona = NULL;
    }
}

void get_PersonaName(struct PersonaNode ** Persona) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t    Lütfen Ad-Soyad bilgilerinizi giriniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Ad-Soyad: ");

    fgets(buffer, sizeof(buffer), stdin);
    strcpy((*Persona)->name, deblank(buffer));
}

void get_PersonaAddress(struct PersonaNode ** Persona) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t     Lütfen Adres bilgilerinizi giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Adres: ");

    fgets(buffer, sizeof(buffer), stdin);
    strcpy((*Persona)->address, deblank(buffer));
}

void get_PersonaPhone(struct PersonaNode ** Persona) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t      Lütfen Telefon Numaranızı giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\tTelefon Numaraniz 5431234567 şeklinde olmalıdır\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Telefon No: ");

    fgets(buffer, sizeof(buffer), stdin);
    strcpy((*Persona)->phone, deblank(buffer));
}

void get_PersonaEmail(struct PersonaNode ** Persona) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t      Lütfen E-Posta adresinizi giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│    E-Posta adresi johnsmith@example.com şeklinde olmalıdır\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("E-Posta: ");

    fgets(buffer, sizeof(buffer), stdin);
    strcpy((*Persona)->email, deblank(buffer));
}

bool get_PersonaDOB(struct PersonaNode ** Persona) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t       Lütfen Doğum Tarihinizi giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│   Doğum Tarih sadece [1960, 2000] arası degerler geçerlidir!  │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Doğum Tarih: ");

    fgets(buffer, sizeof(buffer), stdin);

    int value = atoi(buffer);

    if(value >= 1960 && value <= 2000) {
        (*Persona)->dob = value;
        return true;
    }
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t  Hatali Doğum Tarih girisi!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    return false;
}

void get_PersonaLingo(struct PersonaNode ** Persona) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\tLütfen Yabancı Dil bilgilerinizi listeden seçiniz\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[+]───────────────────────────────────────────────────────────┐\n");
    printf("│ [1] İngilizce\t\t\t\t\t\t\t│\n");
    printf("│ [2] Fransızca\t\t\t\t\t\t\t│\n");
    printf("│ [3] Almanca\t\t\t\t\t\t\t│\n");
    printf("│ [4] Arapça\t\t\t\t\t\t\t│\n");
    printf("│ [5] Çince\t\t\t\t\t\t\t│\n");
    printf("│ [6] Japonca\t\t\t\t\t\t\t│\n");
    printf("│ [7] İspanyolca\t\t\t\t\t\t│\n");
    printf("│ [8] Rusça\t\t\t\t\t\t\t│\n");
    printf("│\t\t\t\t\t\t\t\t│\n");
    printf("│ [Enter] IPTAL\t\t\t\t\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│    Çoklu Dil seçimi için seçimler arasına boşluk koyunuz!\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Yabancı Dil: ");

    fgets(buffer, sizeof(buffer), stdin);

    strcpy((*Persona)->lingo, ";");

    if(strchr(buffer, '1')) {
        strcat((*Persona)->lingo, "ingilizce;");
    }
    if(strchr(buffer, '2')) {
        strcat((*Persona)->lingo, "fransizca;");
    }
    if(strchr(buffer, '3')) {
        strcat((*Persona)->lingo, "almanca;");
    }
    if(strchr(buffer, '4')) {
        strcat((*Persona)->lingo, "arapca;");
    }
    if(strchr(buffer, '5')) {
        strcat((*Persona)->lingo, "cince;");
    }
    if(strchr(buffer, '6')) {
        strcat((*Persona)->lingo, "japonca;");
    }
    if(strchr(buffer, '7')) {
        strcat((*Persona)->lingo, "ispanyolca;");
    }
    if(strchr(buffer, '8')) {
        strcat((*Persona)->lingo, "rusca;");
    }
}

void get_PersonaDriver(struct PersonaNode ** Persona) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\tLütfen Ehliyet bilgilerinizi listeden seçiniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[+]───────────────────────────────────────────────────────────┐\n");
    printf("│ [1] A1\t\t\t\t\t\t\t│\n");
    printf("│ [2] A2\t\t\t\t\t\t\t│\n");
    printf("│ [3] B\t\t\t\t\t\t\t\t│\n");
    printf("│ [4] C\t\t\t\t\t\t\t\t│\n");
    printf("│ [5] D\t\t\t\t\t\t\t\t│\n");
    printf("│ [6] E\t\t\t\t\t\t\t\t│\n");
    printf("│ [7] F\t\t\t\t\t\t\t\t│\n");
    printf("│ [8] G\t\t\t\t\t\t\t\t│\n");
    printf("│ [9] H\t\t\t\t\t\t\t\t│\n");
    printf("│\t\t\t\t\t\t\t\t│\n");
    printf("│ [Enter] IPTAL\t\t\t\t\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│  Çoklu Ehliyet seçimi için seçimler arasına boşluk koyunuz!   │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Ehliyet: ");
    fgets(buffer, sizeof(buffer), stdin);

    strcpy((*Persona)->driver, ";");

    if(strchr(buffer, '1')) {
        strcat((*Persona)->driver, "A1;");
    }
    if(strchr(buffer, '2')) {
        strcat((*Persona)->driver, "A2;");
    }
    if(strchr(buffer, '3')) {
        strcat((*Persona)->driver, "B;");
    }
    if(strchr(buffer, '4')) {
        strcat((*Persona)->driver, "C;");
    }
    if(strchr(buffer, '5')) {
        strcat((*Persona)->driver, "D;");
    }
    if(strchr(buffer, '6')) {
        strcat((*Persona)->driver, "E;");
    }
    if(strchr(buffer, '7')) {
        strcat((*Persona)->driver, "F;");
    }
    if(strchr(buffer, '8')) {
        strcat((*Persona)->driver, "G;");
    }
    if(strchr(buffer, '9')) {
        strcat((*Persona)->driver, "H;");
    }
}

/**
 * Egitim durumu ve mezun oldugu veya devam ettigi okullarin bilgilerini
 * islen fonksiyonlar
 */

bool wantEduStatus() {
    bool makeEdu = false;
    bool done = false;

    while(!done) {
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t  Eğitim bilgilerinizi girmek istiyormusunuz?\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│   Evet için 'E' veya 'e', Hayır için 'H' veya 'h' giriniz!    │\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t SEÇİMİNİZ: ");
        char choise = fgetc(stdin);
        getchar();
        fflush(stdin);

        if(choise == 'E' || choise == 'e') {
            makeEdu = true;
            done = true;
        } else if(choise == 'H' || choise == 'h') {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t       Eğitim bilgi girişi gerçekleşmedi\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
            done = true;
        } else {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t   Hatalı giriş! Lütfen girişi tekrarlayınız\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        }
    }
    return makeEdu;
}

void get_PersonaEdu(struct edu_status ** institute) {
    bool done = false;
    while(!done) {
        system("clear");
        printf("╔═══════════════════════════════════════════════════════════════╗\n");
        printf("║\t\t      Eğitim bilgi girişi\t\t\t║\n");
        printf("╚═══════════════════════════════════════════════════════════════╝\n");
        printf("┌─[+]───────────────────────────────────────────────────────────┐\n");
        printf("│ [1] Orta Okul\t\t\t\t\t\t\t│\n");
        printf("│ [2] Lise\t\t\t\t\t\t\t│\n");
        printf("│ [3] Yüksek Okul\t\t\t\t\t\t│\n");
        printf("│ [4] Lisans\t\t\t\t\t\t\t│\n");
        printf("│ [5] Yüksek Lisans\t\t\t\t\t\t│\n");
        printf("│ [6] Doktora\t\t\t\t\t\t\t│\n");
        printf("│\t\t\t\t\t\t\t\t│\n");
        printf("│ [Enter] İPTAL\t\t\t\t\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\tLütfen girilecek Eğitim Türünü listeden seçiniz\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("Eğitim türü: ");

        int eduValue = 0;
        char buffer[2];
        fgets(buffer, sizeof(buffer), stdin);
        int choise = atoi(buffer);

        switch(choise) {
        case 0:
            done = true;
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t       Eğitim bilgi girişi gerçekleşmedi\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
            break;
        case 1:
            eduValue = 5;
            break;
        case 2:
            eduValue = 10;
            break;
        case 3:
            eduValue = 15;
            break;
        case 4:
            eduValue = 20;
            break;
        case 5:
            eduValue = 30;
            break;
        case 6:
            eduValue = 40;
            break;
        default:
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t\t\t HATALI SEÇİM!\t\t\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
            system("sleep 1.2");
            break;
        }

        if(eduValue == 5 || eduValue == 10 || eduValue == 15 || eduValue == 20 || eduValue == 30 || eduValue == 40) {
            MakeNewEdu(institute, eduValue);
            done = !wantEduStatus();
        }
    }
}

void MakeNewEdu(struct edu_status ** institute, int eduValue) {
    getchar();
    fflush(stdin);
    if(eduValue == 5 || eduValue == 10 || eduValue == 15 || eduValue == 20 || eduValue == 30 || eduValue == 40) {
        struct edu_status * NewEdu = malloc(sizeof(struct edu_status));
        NewEdu->next = NULL;

        if(eduValue == 5) {
            NewEdu->edu_value = 5;
            strcpy(NewEdu->degree,"Orta Okul");
        } else if(eduValue == 10) {
            NewEdu->edu_value = 10;
            strcpy(NewEdu->degree,"Lise");
        } else if(eduValue == 15) {
            NewEdu->edu_value = 15;
            strcpy(NewEdu->degree,"Yuksek Okul");
        } else if(eduValue == 20) {
            NewEdu->edu_value = 20;
            strcpy(NewEdu->degree,"Lisans");
        } else if(eduValue == 30) {
            NewEdu->edu_value = 30;
            strcpy(NewEdu->degree,"Yuksek Lisans");
        } else if(eduValue == 40) {
            NewEdu->edu_value = 40;
            strcpy(NewEdu->degree,"Doktora");
        }
        char buffer[MAX_ARRAY_SIZE];
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\tTürkçe karakter kullanmayınız!\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\t  Lütfen Okul Adını giriniz\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("Okul Adı: ");
        fgets(buffer, sizeof(buffer), stdin);
        strcpy(NewEdu->edu_name, deblank(buffer));
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\t  Lütfen Bölümünüzü giriniz\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("Bölümünüz: ");
        fgets(buffer, sizeof(buffer), stdin);
        strcpy(NewEdu->department, deblank(buffer));

        while(!get_EduStart(&NewEdu));

        if(wasEduGraduated()) {
            while(!get_EduGraduate(&NewEdu));
            while(!get_EduAverage(&NewEdu));
        } else {
            NewEdu->graduated = -1;
            NewEdu->average = -1;
        }

        if((*institute) == NULL) {
            (*institute) = NewEdu;
        } else {
            struct edu_status * last = NULL;

            for(last = (*institute); last->next != NULL; last = last->next);
            last->next = NewEdu;
        }
    }
}

bool get_EduStart(struct edu_status ** institute) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t     Lütfen Okula Giriş Tarihinizi giriniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│   Giriş Tarih sadece [1975, 2016] arası degerler geçerlidir!  │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Okula Giriş Tarihiniz: ");

    fgets(buffer, sizeof(buffer), stdin);

    int value = atoi(buffer);

    if(value >= 1975 && value <= 2016) {
        (*institute)->started = value;
        return true;
    }
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t  Hatali Okula Giriş Tarihi!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    return false;
}

bool wasEduGraduated() {
    bool graduated = false;
    bool done = false;

    while(!done) {
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\t   Okuldan Mezun oldunuz mu?\t\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│   Evet için 'E' veya 'e', Hayır için 'H' veya 'h' giriniz!    │\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t SEÇİMİNİZ: ");
        char choise = fgetc(stdin);
        getchar();
        fflush(stdin);

        if(choise == 'E' || choise == 'e') {
            graduated = true;
            done = true;
        } else if(choise == 'H' || choise == 'h') {
            done = true;
        } else {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t   Hatalı giriş! Lütfen girişi tekrarlayınız\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        }
    }
    return graduated;
}

bool get_EduGraduate(struct edu_status ** institute) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t      Lütfen Okul Bitiş Tarihinizi giriniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│   Bitiş Tarih sadece [1980, 2016] arası degerler geçerlidir!  │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Okul Bitiş Tarihiniz: ");

    fgets(buffer, sizeof(buffer), stdin);

    int value = atoi(buffer);

    if(value >= 1980 && value <= 2016) {
        (*institute)->graduated = value;
        return true;
    }
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\tHatali Okul Bitiş Tarih girisi!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    return false;
}

bool get_EduAverage(struct edu_status ** institute) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\tLütfen Not Ortalamanızı giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│    Not Ortalama sadece [0, 100] arası degerler geçerlidir!    │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Not Ortalamanız: ");

    fgets(buffer, sizeof(buffer), stdin);

    int value = atoi(buffer);

    if(value >= 0 && value <= 100) {
        (*institute)->average = value;
        return true;
    }
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t  Hatali Not Ortalama girisi!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    return false;
}

/**
 * Is deneyimi ve calistigi isyerinin bilgilerini islen fonksiyonlar
 */

bool wantWorkExper() {
    bool makeWork = false;
    bool done = false;

    while(!done) {
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t     İş bilgilerinizi girmek istiyormusunuz?\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│   Evet için 'E' veya 'e', Hayır için 'H' veya 'h' giriniz!    │\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t SEÇİMİNİZ: ");
        char choise = fgetc(stdin);
        getchar();
        fflush(stdin);

        if(choise == 'E' || choise == 'e') {
            makeWork = true;
            done = true;
        } else if(choise == 'H' || choise == 'h') {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t\t İş bilgi girişi gerçekleşmedi\t\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
            done = true;
        } else {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t   Hatalı giriş! Lütfen girişi tekrarlayınız\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        }
    }
    return makeWork;
}

void get_PersonaWork(struct work_exper ** workplace) {
    bool done = false;
    while(!done) {
        system("clear");
        printf("╔═══════════════════════════════════════════════════════════════╗\n");
        printf("║\t\t\tİş bilgi girişi\t\t\t\t║\n");
        printf("╚═══════════════════════════════════════════════════════════════╝\n");

        MakeNewWork(workplace);
        done = !wantWorkExper();
    }
}


void MakeNewWork(struct work_exper ** workplace) {
    struct work_exper * NewWork = malloc(sizeof(struct work_exper));
    NewWork->next = NULL;

    char buffer[MAX_ARRAY_SIZE];

    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\tTürkçe karakter kullanmayınız!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t   Lütfen İş Adını giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("İş Adı: ");

    fgets(buffer, sizeof(buffer), stdin);
    strcpy(NewWork->work_name, deblank(buffer));

    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t Lütfen İş Adresini giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("İş Adresi: ");

    fgets(buffer, sizeof(buffer), stdin);
    strcpy(NewWork->work_address, deblank(buffer));

    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t Lütfen İş Pozisyonuzu veya Görevinizi giriniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("İş Pozisyonuz veya Göreviniz: ");

    fgets(buffer, sizeof(buffer), stdin);
    strcpy(NewWork->position, deblank(buffer));

    while(!get_WorkDuration(&NewWork));

    if((*workplace) == NULL) {
        (*workplace) = NewWork;
    } else {
        struct work_exper * last = NULL;
        for(last = (*workplace); last->next != NULL; last = last->next);
        last->next = NewWork;
    }

}

bool get_WorkDuration(struct work_exper ** workplace) {
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\tLütfen Çalışma Sürenizi giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│    Çalışma Süresi sadece [0, 30] arası degerler geçerlidir!   │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Çalışma Sürenizi: ");

    fgets(buffer, sizeof(buffer), stdin);

    float value = atof(buffer);

    if(value >= 0 && value <= 30) {
        (*workplace)->duration = value;
        return true;
    }

    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t  Hatali Çalışma Süre girisi!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    return false;
}

/**
 * Beauty Print
 */

void printPersonaNode(struct PersonaNode * Persona) {
    if(Persona != NULL) {
        printf("┌────┬──────────────────────────┬────────────────┬──────────────┬───────────────────────┬────────┬──────────────────────────────────────┬───────────┐\n");
        printf("│ ID │         Ad-Soyad         │     Adres      │   Telefon    │        E-Posta        │Doğum T.│             Yabancı Dil              │  Ehliyet  │\n");
        printf("├────┼──────────────────────────┼────────────────┼──────────────┼───────────────────────┼────────┼──────────────────────────────────────┼───────────┤\n");
        printf("│%4d│%s│%s│%s│%s│%6d  │", Persona->id,justify(Persona->name,26),justify(Persona->address,16),justify(Persona->phone,14),justify(Persona->email,23),Persona->dob);
        char buffer[40] = "";
        if(strstr(Persona->lingo, "ingilizce")) {
            strcat(buffer,"İngilizce");
            //printf("İngilizce ");
        }
        if(strstr(Persona->lingo, "fransizca")) {
            strcat(buffer," Fransızca");
            //printf("Fransızca ");
        }
        if(strstr(Persona->lingo, "almanca")) {
            strcat(buffer," Almanca");
            //printf("Almanca ");
        }
        if(strstr(Persona->lingo, "arapca")) {
            strcat(buffer," Arapça");
            //printf("Arapça ");
        }
        if(strstr(Persona->lingo, "cince")) {
            strcat(buffer," Çince");
            //printf("Çince ");
        }
        if(strstr(Persona->lingo, "japonca")) {
            strcat(buffer," Japonca");
            //printf("Japonca ");
        }
        if(strstr(Persona->lingo, "ispanyolca")) {
            strcat(buffer," İspanyolca");
            //printf("İspanyolca ");
        }
        if(strstr(Persona->lingo, "rusca")) {
            strcat(buffer," Rusça");
            //printf("Rusça ");
        }

        strcpy(buffer, deblank(buffer));
        printf("%s│",justify(buffer,38 + howManyTurkishChar(buffer)/2));

        char driverBuf[12] = "\0";
        if(strstr(Persona->driver, "A1")) {
            //strcat(driverBuf," ");
            strcat(driverBuf,"A1");
            //printf("A1 ");
        }
        if(strstr(Persona->driver, "A2")) {
            strcat(driverBuf," ");
            strcat(driverBuf,"A2");
            //printf("A1 ");
        }
        if(strstr(Persona->driver, "B")) {
            strcat(driverBuf," ");
            strcat(driverBuf,"B");
            //printf("B ");
        }
        if(strstr(Persona->driver, "C")) {
            strcat(driverBuf," ");
            strcat(driverBuf,"C");
            //printf("C ");
        }
        if(strstr(Persona->driver, "D")) {
            strcat(driverBuf," ");
            strcat(driverBuf,"D");
            //printf("D ");
        }
        if(strstr(Persona->driver, "E")) {
            strcat(driverBuf," ");
            strcat(driverBuf,"E");
            //printf("E ");
        }
        if(strstr(Persona->driver, "F")) {
            strcat(driverBuf," ");
            strcat(driverBuf,"F");
            //printf("F ");
        }
        if(strstr(Persona->driver, "G")) {
            strcat(driverBuf," ");
            strcat(driverBuf,"G");
            //printf("G ");
        }
        if(strstr(Persona->driver, "H")) {
            strcat(driverBuf," ");
            strcat(driverBuf,"H");
            //printf("H ");
        }

        printf("%11s│\n",driverBuf);
        printf("└────┴──────────────────────────┴────────────────┴──────────────┴───────────────────────┴────────┴──────────────────────────────────────┴───────────┘\n");

        printPersonaEdu(Persona->institute);
        printPersonaWork(Persona->workplace);
    }
}

/**
 * <TESTING>
 */

int howManyTurkishChar(const char * str) {
    int length = strlen(str)+1;
    int counter = 0;

    unsigned int i;

    for(i = 0; str[i] != '\0' && i < length; i++) {
        if(isTurkishChar(str[i])) {
            counter++;
        }
    }

    return counter;
}

bool isTurkishChar(char ch) {
    char capitalTurkish[] = {"ÇĞİÖŞÜ"};
    char lowerTurkish[] = {"çğıöşü"};
    int length = 0;

    unsigned int i;

    length = strlen(capitalTurkish);
    for(i = 0; capitalTurkish[i] != '\0' && i < length; i++) {
        if(capitalTurkish[i] == ch) {
            return true;
        }
    }

    length = strlen(lowerTurkish);
    for(i = 0; lowerTurkish[i] != '\0' && i < length; i++) {
        if(lowerTurkish[i] == ch) {
            return true;
        }
    }

    return false;
}

char * justify(char * str, int msgLength) {
    int length = msgLength * sizeof(char)+1;
    char * msg = malloc(length);

    char * format = malloc(length);
    sprintf(format, "%%%ds%s", (msgLength/2 + strlen(str)/2) + (msgLength%2), makeSpaceStr(msgLength/2 - strlen(str)/2));
    sprintf(msg,format,str);

    return msg;
}
/**
 * Parametre kadar Bosluk'lu (' ') string ureten
 * fonksiyon
 */

char * makeSpaceStr(int N) {
    if(N < 1) {
        // in this case tabular will return '\0' char
        return "";
    } else {

        char * str = malloc(sizeof(" "));
        strcpy(str," ");

        if(N > 1) {
            int i;
            for(i = 1; i < N; i++) {
                str = realloc(str,(sizeof(' ')));
                strcat(str," ");
            }
        }
        return str;
    }
}

/**
 * </TESTING>
 */

void printPersonaEdu(struct edu_status * institute) {
    if(institute != NULL) {
        struct edu_status * last_edu = NULL;
        printf("┌────────────────────────────────────────┬──────────────┬─────────────────────────────────┬────────┬────────────┬────────┐\n");
        printf("│                Okul Adı                │     Türü     │             Bölümü              │Başla T.│   Bitiş T. │Not Ort.│\n");
        printf("├────────────────────────────────────────┼──────────────┼─────────────────────────────────┼────────┼────────────┼────────┤\n");

        for(last_edu = institute; last_edu != NULL; last_edu = last_edu->next) {
            printf("│%s│%s│%s│  %d  │",justify(last_edu->edu_name, 40),justify(last_edu->degree, 14),justify(last_edu->department, 33),last_edu->started);
            if(last_edu->graduated == -1) {
                printf("Devam Ediyor");
            } else {
                printf("%8d    ",last_edu->graduated);
            }
            printf("│");
            if(last_edu->average == -1) {
                printf("%5c   ",'E');
            } else {
                printf("%5d   ",last_edu->average);
            }
            printf("│\n");

        }
        printf("└────────────────────────────────────────┴──────────────┴─────────────────────────────────┴────────┴────────────┴────────┘\n");
    }
}

void printPersonaWork(struct work_exper * workplace) {
    if(workplace != NULL) {
        struct work_exper * last_work = NULL;
        printf("┌────────────────────────────────────────┬──────────────────────┬─────────────────────────────────────────────┬────────┐\n");
        printf("│            Çalıştığı Yer Adı           │       İş Adres       │                    Görevi                   │ Süresi │\n");
        printf("├────────────────────────────────────────┼──────────────────────┼─────────────────────────────────────────────┼────────┤\n");


        for(last_work = workplace; last_work != NULL; last_work = last_work->next) {

            printf("│%s│%s│%s│%8.1f│\n",justify(last_work->work_name, 40),justify(last_work->work_address, 22),justify(last_work->position, 45),last_work->duration);

        }
        printf("└────────────────────────────────────────┴──────────────────────┴─────────────────────────────────────────────┴────────┘\n");
    }
}

bool wantToSave() {
    bool toSave = false;
    bool done = false;

    while(!done) {
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t   Bilgilerinizi Kayit Etmek istiyormusunuz?\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│   Evet için 'E' veya 'e', Hayır için 'H' veya 'h' giriniz!    │\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t SEÇİMİNİZ: ");
        char choise = fgetc(stdin);
        getchar();
        fflush(stdin);

        if(choise == 'E' || choise == 'e') {
            toSave = true;
            done = true;
        } else if(choise == 'H' || choise == 'h') {
            done = true;
        } else {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t   Hatalı giriş! Lütfen girişi tekrarlayınız\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        }
    }
    return toSave;
}

void ShowPersonaNode(struct PersonaNode * RootNode) {
    getchar();
    fflush(stdin);
    system("clear");
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║\t\t Sistemdeki bilgileri görüntüle\t\t\t║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\tTürkçe karakter kullanmayınız!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t       Lütfen arananin Ad-Soyad giriniz\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Ad-Soyad: ");

    fgets(buffer, sizeof(buffer), stdin);
    SearchAndPrint(RootNode, deblank(buffer));
    getchar();
}

void SearchAndPrint(struct PersonaNode * RootNode, char * target) {
    if(RootNode != NULL) {
        int pathfinder = strcmp(str_tolower(RootNode->name), str_tolower(target));
        if(pathfinder == 0) {
            printPersonaNode(RootNode);
        } else if(pathfinder > 0) {
            SearchAndPrint((RootNode->left), target);
        } else if(pathfinder < 0) {
            SearchAndPrint((RootNode->right), target);
        }
    } else {
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\tAranan %s Bulunamadi!\n",target);
        printf("└───────────────────────────────────────────────────────────────┘\n");
    }
}

void ShowAndDeletePersonaNode(struct PersonaNode ** RootNode) {
    getchar();
    fflush(stdin);
    system("clear");
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║\t      Sistemden çıkma (bilgilerini silme)\t\t║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\tTürkçe karakter kullanmayınız!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t       Lütfen silinecek Ad-Soyad giriniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Ad-Soyad: ");

    fgets(buffer, sizeof(buffer), stdin);
    SearchAndPrint(*RootNode, deblank(buffer));

    if(sureToDelete()) {
        *RootNode = Delete_Node(*RootNode, deblank(buffer));
    }
}


bool sureToDelete() {
    bool toDelete = false;
    bool done = false;

    while(!done) {
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t      Bu Bilgileri Silmek istiyormusunuz?\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│   Evet için 'E' veya 'e', Hayır için 'H' veya 'h' giriniz!    │\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t SEÇİMİNİZ: ");
        char choise = fgetc(stdin);
        getchar();
        fflush(stdin);

        if(choise == 'E' || choise == 'e') {
            toDelete = true;
            done = true;
        } else if(choise == 'H' || choise == 'h') {
            done = true;
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t\tBilgi Silme işlemi iptal edildi!\t\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        } else {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t   Hatalı giriş! Lütfen girişi tekrarlayınız\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        }
    }
    return toDelete;
}

void UpdatePersona(struct PersonaNode ** RootNode) {
    getchar();
    fflush(stdin);
    system("clear");
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║\t\tSistemdeki bilgileri güncelleme\t\t\t│\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\tTürkçe karakter kullanmayınız!\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    char buffer[MAX_ARRAY_SIZE];
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\t    Lütfen guncellenecek Ad-Soyad giriniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Ad-Soyad: ");

    fgets(buffer, sizeof(buffer), stdin);

    struct PersonaNode * wanted = WantedPersona(RootNode, buffer);
    if(wanted) {
        printPersonaNode(wanted);
        if(sureToUpdate()) {
            *RootNode = Delete_Node(*RootNode, deblank(buffer));
            MakeNewPersona(RootNode);
        }
    }
}

bool sureToUpdate() {
    bool toUpdate = false;
    bool done = false;

    while(!done) {
        printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
        printf("│\t    Bu Bilgileri Güncellemek istiyormusunuz?\t\t│\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│   Evet için 'E' veya 'e', Hayır için 'H' veya 'h' giriniz!    │\n");
        printf("└───────────────────────────────────────────────────────────────┘\n");
        printf("\t\t\t SEÇİMİNİZ: ");
        char choise = fgetc(stdin);
        getchar();
        fflush(stdin);

        if(choise == 'E' || choise == 'e') {
            toUpdate = true;
            done = true;
        } else if(choise == 'H' || choise == 'h') {
            done = true;
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t     Bilgi güncelleme işlemi iptal edildi!\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        } else {
            printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
            printf("│\t   Hatalı giriş! Lütfen girişi tekrarlayınız\t\t│\n");
            printf("└───────────────────────────────────────────────────────────────┘\n");
        }
    }
    return toUpdate;
}


struct PersonaNode * WantedPersona(struct PersonaNode ** RootNode, char * target) {
    if(!(*RootNode)) {
        printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
        printf("│\t\tAranan %s Bulunamadi!\n",target);
        printf("└───────────────────────────────────────────────────────────────┘\n");
        return NULL;
    } else {
        int pathfinder = strcmp(str_tolower((*RootNode)->name), str_tolower(target));
        if(pathfinder == 0) {
            return *RootNode;
        } else if(pathfinder > 0) {
            WantedPersona(&((*RootNode)->left), target);
        } else if(pathfinder < 0) {
            WantedPersona(&((*RootNode)->right), target);
        }
    }
}


/**
 * <TESTING>
 */

void UpdatePersonaNode(struct PersonaNode ** Persona) {
    getchar();
    fflush(stdin);
    system("clear");

    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║\t\tSistemdeki bilgileri güncelleme\t\t\t│\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    printf("┌─[+]───────────────────────────────────────────────────────────┐\n");
    printf("│ [1] Ad-Soyad\t\t\t\t\t\t\t│\n");
    printf("│ [2] Adres\t\t\t\t\t\t\t│\n");
    printf("│ [3] Telefon\t\t\t\t\t\t│\n");
    printf("│ [4] E-Posta\t\t\t\t\t\t\t│\n");
    printf("│ [5] Doğum Tarihi\t\t\t\t\t\t│\n");
    printf("│ [6] Yabancı Dil\t\t\t\t\t\t\t│\n");
    printf("│ [7] Ehliyet\t\t\t\t\t\t\t│\n");
    printf("│ [8] Eğitim bilgileri\t\t\t\t\t\t\t│\n");
    printf("│ [9] İş bilgileri\t\t\t\t\t\t\t│\n");
    printf("│\t\t\t\t\t\t\t\t│\n");
    printf("│ [Enter] İPTAL\t\t\t\t\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[?]───────────────────────────────────────────────────────────┐\n");
    printf("│\tLütfen güncellenecek bilgileri listeden seçiniz\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│ Çoklu güncelleme seçimi için seçimler arasına boşluk koyunuz! │\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("Güncellenecek bilgiler: ");

    char buffer[MAX_ARRAY_SIZE];
    fgets(buffer, sizeof(buffer), stdin);

    if(strchr(buffer, '1')) {

    }
    if(strchr(buffer, '2')) {

    }
    if(strchr(buffer, '3')) {

    }
    if(strchr(buffer, '4')) {

    }
    if(strchr(buffer, '5')) {

    }
    if(strchr(buffer, '6')) {

    }
    if(strchr(buffer, '7')) {

    }
    if(strchr(buffer, '8')) {

    }
    if(strchr(buffer, '9')) {

    }


    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t       Güncelleme işlemi gerçekleşmedi\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");


    printf("┌─[!]───────────────────────────────────────────────────────────┐\n");
    printf("│\t\t\t HATALI SEÇİM!\t\t\t\t│\n");
    printf("└───────────────────────────────────────────────────────────────┘\n");
    system("sleep 1.2");

}

/**
 * </TESTING>
 */
