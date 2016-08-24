/**
 * Ata Niyazov 130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Insan kaynaklari ve kariyer bilgi sistemi
 */

/**
 * persona.c
 */

#include "headfirst.h"

/**
 *  \//||\/||
 *  // ||  ||__
 */

#define KEYWORD_COUNT           25
#define MAX_KEYWORD_LENGTH      15

/**
 * Formatin kullanilacak anahtar sozcuklerini tanimlama
 */

const char keyword[KEYWORD_COUNT][MAX_KEYWORD_LENGTH] = {
    "",                     // 0 - NULL CHAR (NEVER USED)
    "#",                    // 1 - COMMENT CHAR
    "---",                  // 2 - start
    "...",                  // 3 - end

    //DISABLED (DO NOT USE)
    //"-",
    // X - block format uses a hyphen+space
    // to begin a new item in list

    "id:",                  // 4
    "name:",                // 5
    "address:",             // 6
    "phone:",               // 7
    "email:",               // 8
    "dob:",                 // 9
    "lingo:",               // 10
    "driver:",              // 11

    "edu_status:",          // 12
    "edu_value:",           // 13
    "edu_name:",            // 14
    "degree:",              // 15
    "department:",          // 16
    "started:",             // 17
    "graduated:",           // 18
    "average:",             // 19

    "work_exper:",          // 20
    "work_name:",           // 21
    "work_address:",        // 22
    "position:",            // 23
    "duration:"             // 24
};

/**
 * YAML anahtar kelimesine gore deger donduren,
 * anahtar kelimesi degilse 0 donduren fonksiyon
 */

int key2value(char * str) {
    if((strlen(str) < MAX_KEYWORD_LENGTH)) {
        char * word = malloc(sizeof(strlen(str)+1));
        strcpy(word, deblank(str));

        int i;
        // NULL CHAR okumadan dizini tara
        for(i = 1; i < KEYWORD_COUNT; i++) {
            if(strcmp(keyword[i], word) == 0) {
                //printf("KEYWORD: %s %d\n",str,i);
                free(word);
                return i;
            }
        }
        free(word);
    }
    printf("Error on function key2value():\n");
    printf("Word: \"%s\" NOT A KEYWORD\n",str);
    return 0;
}

/**
 * Girilen stringin "source" karakterlerini "dest" (destination)
 * karakterine ceviren fonksiyon
 */

char * undertaker(const char * str, char source, char dest) {
    int length = strlen(str)+1;
    char * word = malloc(length);
    strcpy(word, str);
    word[length] = '\0';

    unsigned int i;

    for(i = 0; word[i] != '\0' && i < length; i++) {
        if(word[i] == source) {
            word[i] = dest;
        }
    }
    return deblank(word);
}

/**
 * Parametre olarak alinan stringin buyuk harflerini
 * kucuk harflere cevirerek geri donderen fonksiyon
 */

char * str_tolower(const char * str) {
    int length = strlen(str);
    char * word = malloc(length);
    strcpy(word, str);
    word[length] = '\0';

    unsigned int i;

    for(i = 0; word[i] != '\0' && i < length; i++) {
        word[i] = tolower(word[i]);
    }
    return deblank(word);
}

/**
 * Parametre kadar TAB'li ('\t') string ureten
 * fonksiyon
 */

char * tabular(int N) {
    if(N < 1) {
        // in this case tabular will return '\0' char
        return "";
    } else {

        char * str = malloc(sizeof("\t"));
        strcpy(str,"\t");

        if(N > 1) {
            int i;
            for(i = 1; i < N; i++) {
                str = realloc(str,(sizeof('\t')));
                strcat(str,"\t");
            }
        }
        return str;
    }
}

/**
 * Formatli dosyadan agac olusturan fonksiyon
 */

void Tree_Import(char * filename, struct PersonaNode ** RootNode) {

    //*RootNode = NULL;

    FILE * fpPersona;
    // Dosyayi okuma modunda ac
    if ((fpPersona = fopen(filename, "r")) == NULL) {
        printf("Error on function make_tree:\n");
        printf("%s dosyasi acilamadi!\n",filename);
        exit(EXIT_FAILURE);
    }

    char parsed[MAX_ARRAY_SIZE] = "";

    // Dosyadan kisi sayisini aliyorus
    fscanf(fpPersona,"%s",parsed);

    if(key2value(parsed) == 1) {
        fscanf(fpPersona,"%d",&PERSONA_COUNT);
        fscanf(fpPersona,"%d",&LAST_ID);
    }

    // Dosyadan kisi bilgilerini alma islemi
    struct PersonaNode * Node = NULL;
    // Agaca yerlestirilen kisi sayisi
    int counted = 0;

    fscanf(fpPersona,"%s",parsed);

    while(!feof(fpPersona) && key2value(parsed)) {
        if(key2value(parsed) == 2) {
            Node = NULL;
            Persona_Import(fpPersona,&Node);
            counted++;
            //printNode(Node);
            //Tree_Export("export_test.yaml", Node);
            Insert_Node(RootNode, Node);
        }
        fscanf(fpPersona,"%s",parsed);
    }
    fclose(fpPersona);
}

/**
 * Formatli dosyadan kisiye ait bilgileri ceken fonksiyon
 */

void Persona_Import(FILE * fpPersona, struct PersonaNode ** Persona) {
    struct PersonaNode * NewPersona = malloc(sizeof(struct PersonaNode));

    NewPersona->left = NULL;
    NewPersona->right = NULL;

    NewPersona->institute = NULL;
    NewPersona->workplace = NULL;

    char parsed[MAX_ARRAY_SIZE] = "";
    bool done = false;

    while(!done && !feof(fpPersona)) {
        fscanf(fpPersona,"%s",parsed);
        int key = key2value(parsed);
        if(key >= 2 && key < KEYWORD_COUNT) {
            switch(key) {
            case 3: // ...
                (*Persona) = NewPersona;
                done = true;
                break;
            case 4: // id:
                fscanf(fpPersona,"%d",&(NewPersona->id));
                break;
            case 5: // name:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewPersona->name,undertaker(parsed,'_',' '));
                break;
            case 6: // address:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewPersona->address,undertaker(parsed,'_',' '));
                break;
            case 7: // phone:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewPersona->phone,undertaker(parsed,'_',' '));
                break;
            case 8: // email:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewPersona->email,undertaker(parsed,'_',' '));
                break;
            case 9: // dob:
                fscanf(fpPersona,"%d",&(NewPersona->dob));
                break;
            case 10: // lingo:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewPersona->lingo,undertaker(parsed,'_',' '));
                break;
            case 11: // driver:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewPersona->driver,undertaker(parsed,'_',' '));
                break;
            case 12: // edu_status:
                Edu_Import(fpPersona,&(NewPersona->institute));
                break;
            case 20: // work_exper:
                Work_Import(fpPersona,&(NewPersona->workplace));
                break;
            }
        } else {
            printf("make_person() break yapti");
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * Formatli dosyadan kisiye ait egitim durumu ve mezun oldugu
 * veya devam ettigi okullarin bilgilerini ceken fonksiyon
 */

void Edu_Import(FILE * fpPersona, struct edu_status ** institute) {
    struct edu_status * NewEdu = malloc(sizeof(struct edu_status));
    NewEdu->next = NULL;

    char parsed[MAX_ARRAY_SIZE] = "";
    bool done = false;

    while(!done && !feof(fpPersona)) {
        fscanf(fpPersona,"%s",parsed);
        int key = key2value(parsed);
        if(key >= 2 && key < KEYWORD_COUNT) {
            switch(key) {
            case 13: // edu_value:
                fscanf(fpPersona,"%d",&(NewEdu->edu_value));
                break;
            case 14: // edu_name:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewEdu->edu_name,undertaker(parsed,'_',' '));
                break;
            case 15: // degree:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewEdu->degree,undertaker(parsed,'_',' '));
                break;
            case 16: // department:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewEdu->department,undertaker(parsed,'_',' '));
                break;
            case 17: // started:
                fscanf(fpPersona,"%d",&(NewEdu->started));
                break;
            case 18: // graduated:
                fscanf(fpPersona,"%d",&(NewEdu->graduated));
                break;
            case 19: // average:
                fscanf(fpPersona,"%d",&(NewEdu->average));
                done = true;
                break;
            }
        } else {
            printf("make_education() break yapti");
            exit(EXIT_FAILURE);
        }
    }

    if((*institute) == NULL) {
        (*institute) = NewEdu;
    } else {
        struct edu_status * last = NULL;
        for(last = (*institute); last->next != NULL; last = last->next);
        last->next = NewEdu;
    }
}

/**
 * Formatli dosyadan kisiye ait is deneyimi ve calistigi isyerinin
 * bilgilerini ceken fonksiyon
 */

void Work_Import(FILE * fpPersona, struct work_exper ** workplace) {
    struct work_exper * NewWork = malloc(sizeof(struct work_exper));
    NewWork->next = NULL;

    char parsed[MAX_ARRAY_SIZE] = "";
    bool done = false;

    while(!done && !feof(fpPersona)) {
        fscanf(fpPersona,"%s",parsed);
        int key = key2value(parsed);
        if(key >= 2 && key < KEYWORD_COUNT) {
            switch(key) {
            case 21: // work_name:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewWork->work_name,undertaker(parsed,'_',' '));
                break;
            case 22: // work_address:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewWork->work_address,undertaker(parsed,'_',' '));
                break;
            case 23: // position:
                fscanf(fpPersona,"%s",parsed);
                strcpy(NewWork->position,undertaker(parsed,'_',' '));
                break;
            case 24: // duration:
                fscanf(fpPersona,"%f",&(NewWork->duration));
                done = true;
                break;
            }
        } else {
            printf("make_workplace() break yapti");
            exit(EXIT_FAILURE);
        }
    }

    if((*workplace) == NULL) {
        (*workplace) = NewWork;
    } else {
        struct work_exper * last = NULL;
        for(last = (*workplace); last->next != NULL; last = last->next);
        last->next = NewWork;
    }
}

/**
 * Agactan kisilerin bilgilerini dosyaya formatli yazan fonksiyon
 */

void Tree_Export(char * filename, struct PersonaNode * RootNode) {

    clr_file(filename);

    FILE * fpPersona;
    // Dosyayi yazma modunda ac
    if ((fpPersona = fopen(filename, "a")) == NULL) {
        printf("Error on function make_tree:\n");
        printf("%s dosyasi acilamadi!\n",filename);
        exit(EXIT_FAILURE);
    }

    struct PersonaLinkList * head = NULL;
    PersonaTree2LinkList(&head, RootNode);
    head = ID_SortPersonaLinkList(head);

    fprintf(fpPersona, "# %d %d\n",PersonaCounter(RootNode),LAST_ID);

    struct PersonaLinkList * tail = head;

    while(tail != NULL) {
        Persona_Export(fpPersona, tail->Persona);
        tail = tail->next;
    }

    DestroyPersonaLinkList(&head);

    fclose(fpPersona);
}

/**
 * Agac dugumundeki kisiye ait bilgileri dosyaya
 * formatli yazan fonksiyon
 */

void Persona_Export(FILE * fpPersona, struct PersonaNode * Node) {
    fprintf(fpPersona, "%s\n", keyword[2]);

    fprintf(fpPersona, "%s %d\n", keyword[4],Node->id);
    fprintf(fpPersona, "%s %s\n", keyword[5],undertaker(Node->name,' ','_'));
    fprintf(fpPersona, "%s %s\n", keyword[6],undertaker(Node->address,' ','_'));
    fprintf(fpPersona, "%s %s\n", keyword[7],undertaker(Node->phone,' ','_'));
    fprintf(fpPersona, "%s %s\n", keyword[8],undertaker(Node->email,' ','_'));
    fprintf(fpPersona, "%s %d\n", keyword[9],Node->dob);
    fprintf(fpPersona, "%s %s\n", keyword[10],undertaker(Node->lingo,' ','_'));
    fprintf(fpPersona, "%s %s\n", keyword[11],undertaker(Node->driver,' ','_'));

    Edu_Export(fpPersona, Node->institute);
    Work_Export(fpPersona, Node->workplace);

    fprintf(fpPersona, "%s\n", keyword[3]);
}

/**
 * Agac dugumundeki kisiye ait egitim durumu ve mezun oldugu
 * veya devam ettigi okullarin bilgilerini dosya formatli
 * yazan fonksiyon
 */

void Edu_Export(FILE * fpPersona, struct edu_status * institute) {
    struct edu_status * last_edu = NULL;
    for(last_edu = institute; last_edu != NULL; last_edu = last_edu->next) {
        fprintf(fpPersona, "%s\n", keyword[12]);
        fprintf(fpPersona, "\t%s %d\n", keyword[13],last_edu->edu_value);
        fprintf(fpPersona, "\t%s %s\n", keyword[14],undertaker(last_edu->edu_name,' ','_'));
        fprintf(fpPersona, "\t%s %s\n", keyword[15],undertaker(last_edu->degree,' ','_'));
        fprintf(fpPersona, "\t%s %s\n", keyword[16],undertaker(last_edu->department,' ','_'));
        fprintf(fpPersona, "\t%s %d\n", keyword[17],last_edu->started);
        fprintf(fpPersona, "\t%s %d\n", keyword[18],last_edu->graduated);
        fprintf(fpPersona, "\t%s %d\n", keyword[19],last_edu->average);
    }
}

/**
 * Agac dugumundeki kisiye ait is deneyimi ve calistigi isyerinin
 * bilgilerini dosya formatli yazan fonksiyon
 */

void Work_Export(FILE * fpPersona, struct work_exper * workplace) {
    struct work_exper * last_work = NULL;
    for(last_work = workplace; last_work != NULL; last_work = last_work->next) {
        fprintf(fpPersona, "%s\n", keyword[20]);
        fprintf(fpPersona, "\t%s %s\n", keyword[21],undertaker(last_work->work_name,' ','_'));
        fprintf(fpPersona, "\t%s %s\n", keyword[22],undertaker(last_work->work_address,' ','_'));
        fprintf(fpPersona, "\t%s %s\n", keyword[23],undertaker(last_work->position,' ','_'));
        fprintf(fpPersona, "\t%s %.1f\n", keyword[24],last_work->duration);
    }
}

/**
 * Parametre olarak alinan dugumun kisiye ait oldugu verileri,
 * egitim durumu ve mezun oldugu veya devam ettigi okullarin bilgilerini,
 * is deneyimi ve calistigi isyerinin bilgilerini
 * ekrana yazma fonksiyonu
 */

void printNode(struct PersonaNode * Node) {
    if(Node == NULL) {
        return;
    } else {
        printf("id:%s%d\n",tabular(2),Node->id);
        printf("name:%s%s\n",tabular(2),Node->name);
        printf("address:%s%s\n",tabular(1),Node->address);
        printf("phone:%s%s\n",tabular(2),Node->phone);
        printf("email:%s%s\n",tabular(2),Node->email);
        printf("dob:%s%d\n",tabular(2),Node->dob);
        printf("lingo:%s%s\n",tabular(2),Node->lingo);
        printf("driver:%s%s\n",tabular(2),Node->driver);

        struct edu_status * last_edu = NULL;

        for(last_edu = Node->institute; last_edu != NULL; last_edu = last_edu->next) {
            printf("\nedu_status:\n");
            printf("edu_value:%s%d\n",tabular(1),last_edu->edu_value);
            printf("edu_name:%s%s\n",tabular(1),last_edu->edu_name);
            printf("degree:%s%s\n",tabular(2),last_edu->degree);
            printf("department:%s%s\n",tabular(1),last_edu->department);
            printf("started:%s%d\n",tabular(1),last_edu->started);

            if(last_edu->graduated < 0) {
                printf("graduated:%sDevam Ediyor\n",tabular(1));
            } else {
                printf("graduated:%s%d\n",tabular(1),last_edu->graduated);
            }

            if(last_edu->average < 0) {
                printf("average:%se\n",tabular(1));
            } else {
                printf("average:%s%d\n",tabular(1),last_edu->average);
            }
        }

        struct work_exper * last_work = NULL;

        for(last_work = Node->workplace; last_work != NULL; last_work = last_work->next) {
            printf("\nwork_exper:\n");
            printf("work_name:%s%s\n",tabular(1),last_work->work_name);
            printf("work_address:%s%s\n",tabular(1),last_work->work_address);
            printf("position:%s%s\n",tabular(1),last_work->position);
            printf("duration:%s%.1f\n",tabular(1),last_work->duration);
        }
    }
    return;
}

/**
 * Benim eski projede kullanidigim fonksiyonlar
 */

/**
 * Dosya icherigini silen fonksiyon
 */

void clr_file(char * filename) {
    FILE * fp;

    if ((fp = fopen(filename, "w")) == NULL) {
        printf("%s dosyasinin icerigi silinemedi!\n",filename);
        exit(EXIT_FAILURE);
    }
    fclose(fp);
}

/**
 * Parametre olarak verilen dosyaya mesaj yazar
 */

void wrt2file(char * filename, char * msg) {
    FILE * fp;

    // Dosyayi okuma modunda ac
    if ((fp = fopen(filename, "a")) == NULL) {
        printf("%s dosyasi acilamadi!\n",filename);
        exit(EXIT_FAILURE);
    }
    fputs(msg, fp);

    fclose(fp);
}

/**
 * Alinan string'de pes pese gelen boshluk karakterlerini
 * sadece tek boshluk olarak degishtirip geri veriyor
 */

char *deblank(char * inpt_str) {
    int length, c, d;
    char *start;

    c = d = 0;

    length = strlen(inpt_str);

    start = (char*)malloc(length+1);

    if (start == NULL)
        exit(EXIT_FAILURE);

    while (*(inpt_str+c) != '\0') {
        if (*(inpt_str+c) == ' ') {
            int temp = c + 1;
            if (*(inpt_str+temp) != '\0') {
                while (*(inpt_str+temp) == ' ' && *(inpt_str+temp) != '\0') {
                    if (*(inpt_str+temp) == ' ') {
                        c++;
                    }
                    temp++;
                }
            }
        }
        *(start+d) = *(inpt_str+c);
        c++;
        d++;
    }
    *(start+d)= '\0';

    // Bastaki ve sondaki bosluklari silerek
    // geri gonderiyorus

    return trim_wht_sp(start);
}

/**
 * Basdaki ve sondaki bosluklari silen fonksiyon
 */

char *trim_wht_sp(char *str) {
    char *end;

    // Bastaki bosluklari sil
    while(isspace(*str)) str++;

    if(*str == 0)  // Hepsi de bosluk mu?
        return str;

    // Sondaki bosluklari sil
    end = str + strlen(str) - 1;
    while(end > str && isspace(*end)) end--;

    // String sonlandirma isaretini ekle '\0'
    *(end+1) = 0;

    return str;
}

/**
 * String'deki eleman sayisini sayan
 * ve geri donderen fonksiyon
 */

int count_elem(const char *str) {
    int counted = 0; // sonuc

    // state: (durum)
    const char* it = str;
    int inword = 0;

    do switch(*it) {
        case '\0':
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            if (inword) {
                inword = 0;
                counted++;
            }
            break;
        default:
            inword = 1;
        }
    while(*it++);

    return counted;
}
