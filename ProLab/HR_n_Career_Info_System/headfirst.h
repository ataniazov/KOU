/**
 * Ata Niyazov 130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Insan kaynaklari ve kariyer bilgi sistemi
 */

/**
 * headfirst.h
 */

#ifndef HEADFIRST_H_INCLUDED
#define HEADFIRST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/**
 * bool veri tipleri kutuphanesini ekliyorus
 */

#include <stdbool.h>

/**
 * Veri dosyasini tanimliyorus
 */

#define PERSONA                 "persona.yaml"

/**
 * En buyuk string dizisinin boyutu
 */

#define MAX_ARRAY_SIZE          250

/**
 * Is deneyimi ve calistigi isyerinin biligilerini
 * iceren yapi bagli liste (linked list)
 */

struct work_exper {
    char work_name[120];
    char work_address[MAX_ARRAY_SIZE];
    char position[120];

    float duration;         // 0.5 must be float

    struct work_exper * next;
};

/**
 * Egitim durumu ve mezun oldugu veya devam ettigi
 * okullarin bilgilerini iceren yapi bagli liste (linked list)
 *
 * Egitim turu degerleri:
 *      Orta Okul     : 5
 *      Lise          : 10
 *      Yuksek Okul   : 15
 *      Lisans        : 20
 *      Yuksek Lisans : 30
 *      Doktora       : 40
 *      ...
 */

struct edu_status {
    int edu_value;      // Egitim turune gore degerler

    char edu_name[100];
    char degree[50];
    char department[100];

    int started;
    int graduated;      // -1 if not graduated
    int average;        // -1 if not graduated

    struct edu_status * next;
};

/**
 * Is basvurusu yapan kisilere iliskin bilgilerini
 * iceren yapi, ayni anda insan kaynaklari bilgi sistemi
 * ikili arama agacinin dugum elemani
 */

struct PersonaNode {
    // ID - kisi eklenme sirasini gosterir
    // WARNING: id must start from 1
    int id;
    // "name" - kisi adina gore "key"
    char name[70];

    char address[MAX_ARRAY_SIZE];
    char phone[25];
    char email[100];

    int dob;
    // LOW letters
    char lingo[120];
    // UP letters
    char driver[50];

    struct edu_status * institute;
    struct work_exper * workplace;

    struct PersonaNode * left;
    struct PersonaNode * right;
};

/**
 * Global degiskenler:
 *   LAST_ID - Dosyadan alinan ve sonradan degisen degeri
 *      geri dosyaya yazilan son kisi id'si
 *   PERSONA_COUNT - Dosyadan alinan ve sonradan degisen degeri
 *      geri dosyaya yazilan kisi sayisi
 */

int LAST_ID;
int PERSONA_COUNT;

/**
 * Fonksiyon prototipleri
 */

/**
 * persona.c dosyasinin fonksiyon prototipleri
 */

// Stable
int key2value(char * str);
char * undertaker(const char str[], char source, char dest);
char * str_tolower(const char * str);
char * tabular(int N);

// Testing
void Tree_Import(char * filename, struct PersonaNode ** RootNode);
void Persona_Import(FILE * fpPersona, struct PersonaNode ** NewPerson);
void Edu_Import(FILE * fpPersona, struct edu_status ** institute);
void Work_Import(FILE * fpPersona, struct work_exper ** workplace);

void Tree_Export(char * filename, struct PersonaNode * RootNode);
void Persona_Export(FILE * fpPersona, struct PersonaNode * Node);
void Edu_Export(FILE * fpPersona, struct edu_status * Node);
void Work_Export(FILE * fpPersona, struct work_exper * Node);

void printNode(struct PersonaNode * Node);

/**
 * Benim eski projeleredeki kullanidigim fonksiyonlar
 */

void clr_file(char * filename);
void wrt2file(char * filename, char * msg);
char *deblank(char *inpt_str);
char *trim_wht_sp(char *str);
int count_elem(const char *str);

/**
 * spider.c dosyasinin fonksiyon prototipleri
 */

void Insert_Node(struct PersonaNode ** RootNode, struct PersonaNode * Node);

void Pre_Order(struct PersonaNode * RootNode);
void In_Order(struct PersonaNode * RootNode);
void Post_Order(struct PersonaNode * RootNode);

void Search_Node(struct PersonaNode * RootNode, char * key);

void PersonaCpy(struct PersonaNode * Target, struct PersonaNode * Source);
void EduCpy(struct edu_status ** Target, struct edu_status * Source);
void WorkCpy(struct work_exper ** Target, struct work_exper * Source);

struct PersonaNode * FindMinNode(struct PersonaNode * RootNode);

struct PersonaNode * Delete_Node(struct PersonaNode * RootNode, char * target);
struct edu_status * Destroy_Edu_List(struct edu_status * institute);
struct work_exper * Destroy_Work_List(struct work_exper * workplace);

void Destroy_Tree(struct PersonaNode ** RootNode);

int Max_Depth(struct PersonaNode * RootNode);

/**
 * Persona Linked list
 */

struct PersonaLinkList {
    struct PersonaNode * Persona;
    struct PersonaLinkList * next;
};

void PersonaTree2LinkList(struct PersonaLinkList ** head, struct PersonaNode * RootNode);
void AddPersonaLinkList(struct PersonaLinkList ** head, struct PersonaNode * Node);
void PrintLinkList(struct PersonaLinkList * head);
struct PersonaLinkList * DeletePersonaLinkList(struct PersonaLinkList * head, char * target);

struct PersonaLinkList * ID_SortPersonaLinkList(struct PersonaLinkList * head);
void DestroyPersonaLinkList(struct PersonaLinkList ** head);

int PersonaCounter(struct PersonaNode * RootNode);

bool Is_Leaf(struct PersonaNode * Node);
int PersonaLinkCounter(struct PersonaLinkList * head);
/**
 * job_application.c
 */

void job_application(struct PersonaNode ** RootNode);

void MakeNewPersona(struct PersonaNode ** RootNode);

void get_PersonaName(struct PersonaNode ** Persona);
void get_PersonaAddress(struct PersonaNode ** Persona);
void get_PersonaPhone(struct PersonaNode ** Persona);
void get_PersonaEmail(struct PersonaNode ** Persona);
bool get_PersonaDOB(struct PersonaNode ** Persona);
void get_PersonaLingo(struct PersonaNode ** Persona);
void get_PersonaDriver(struct PersonaNode ** Persona);

// Okul bilgileri
bool wantEduStatus(void);

void get_PersonaEdu(struct edu_status ** institute);
void MakeNewEdu(struct edu_status ** institute, int eduValue);

bool get_EduStart(struct edu_status ** institute);

bool wasEduGraduated(void);
bool get_EduGraduate(struct edu_status ** institute);
bool get_EduAverage(struct edu_status ** institute);

// Is bilgileri
bool wantWorkExper(void);

void get_PersonaWork(struct work_exper ** workplace);
void MakeNewWork(struct work_exper ** workplace);
bool get_WorkDuration(struct work_exper ** workplace);

// Persona Print
void printPersonaNode(struct PersonaNode * Persona);
void printPersonaEdu(struct edu_status * institute);
void printPersonaWork(struct work_exper * workplace);

/**
 * <TESTING>
 */

int howManyTurkishChar(const char * str);
bool isTurkishChar(char ch);
char * makeSpaceStr(int N);
char * justify(char * str, int msgLength);

/**
 * </TESTING>
 */

bool wantToSave(void);

void ShowPersonaNode(struct PersonaNode * RootNode);
void SearchAndPrint(struct PersonaNode * RootNode, char * target);
void ShowAndDeletePersonaNode(struct PersonaNode ** RootNode);
bool sureToDelete(void);

void UpdatePersona(struct PersonaNode ** RootNode);
bool sureToUpdate(void);

struct PersonaNode * WantedPersona(struct PersonaNode ** RootNode, char * target);
/**
 * hr_management.c
 */

void hr_management(struct PersonaNode ** RootNode);
void ListAllOrder(struct PersonaNode * RootNode);
void ListAllPersona(struct PersonaNode * RootNode);
void FilterPersona(struct PersonaNode * RootNode);

struct PersonaLinkList * LeastDegree(struct PersonaLinkList * head);
bool isLeastDegree(struct edu_status * institute);
void PrintFilteredLinkList(struct PersonaLinkList * head);
struct PersonaLinkList * knowEnglish(struct PersonaLinkList * head);
struct PersonaLinkList * MoreThanOneLingo(struct PersonaLinkList * head);
int lingoCounter(struct PersonaNode * Persona);
struct PersonaLinkList * NotWorked(struct PersonaLinkList * head);

struct PersonaLinkList * WorkedDuration(struct PersonaLinkList * head);
float get_MinDuration();
bool isWorkedDuration(struct work_exper * workplace, float duration);

struct PersonaLinkList * MaxAge(struct PersonaLinkList * head);
int get_Age(void);

struct PersonaLinkList * DriverStatus(struct PersonaLinkList * head);
int get_Driver();

bool wantToPrint();
void PrintLinkList2File(char * filename,struct PersonaLinkList * head);
#endif // HEADFIRST_H_INCLUDED
