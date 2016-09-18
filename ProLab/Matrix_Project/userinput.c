/**
 * Kullanicidan girdi alma ve dosya islemleri fonksiyonlari
 */

#include "headfirst.h"

// String ile islemler
#include <string.h>
#include <ctype.h>

// Kare matrisin boyut sinirlarini tanimlama
#define MTRX_MIN_SIZE 4
#define MTRX_MAX_SIZE 16


/**
 * Kullanicidan matris boyutunu isteme fonksiyonu
 */

int get_mtrx_size()
{
    int mtrx_size = 0;

    while(1)
    {

        printf("Kare matrisin boyutunu giriniz [%d,%d]: ", MTRX_MIN_SIZE, MTRX_MAX_SIZE);

        char buf[BUFSIZ];
        if (fgets(buf, sizeof(buf), stdin) != NULL)
        {
            mtrx_size = atoi(buf);
        }

        if(mtrx_size >= MTRX_MIN_SIZE && mtrx_size <= MTRX_MAX_SIZE)
        {
            printf("Kare matrisin boyutu %dx%d\n",mtrx_size,mtrx_size);
            return mtrx_size;
        }
        else
        {
            printf("HATALI GIRIS! Sadece [%d,%d] araligi sayi degeri gecerlidir\n", MTRX_MIN_SIZE, MTRX_MAX_SIZE);
            mtrx_size = 0;
        }
    }
    printf("DEBUG INFO: Function get_mtrx_size() has an error!\n");
    exit(EXIT_FAILURE);   //Fonksiyon problem yaratti
}


/**
 * Kullanicidan matris elemanlarini isteme ve
 * matrix.txt dosyasina yazma fonksiyonu.
 */

void get_mtrx_elem(int mtrx_size)
{
    //printf("Matrix size is %d\n",mtrx_size);
    FILE * pMtrx_txt;

    // Dosyayi yazma modunda ac
    if ((pMtrx_txt = fopen(MATRIS, "w")) == NULL)
    {
        printf("%s dosyasi acilamadi!\n",MATRIS);
        exit(EXIT_FAILURE);
    }

    printf("Martis elemanlarini giriniz:\n");
    printf("(Eleman aralarinda BOSLUK (SPACE) koyunuz)\n");

    char buffer[BUFSIZ];
    int i = 0;

    do
    {
        //printf((i == 0 || i == (mtrx_size - 1))?"[ ":"| ");
        fgets(buffer,100,stdin);
        //printf((i == 0 || i == (mtrx_size - 1))?" ]\n":" |\n");
        if(count_elem(buffer) == mtrx_size)
        {
            fprintf(pMtrx_txt, "%s\n",deblank(buffer));
        }
        else
        {
            printf("HATA: %dx%d matrisin %d satirinda eleman sayisi %d olmak zorunda\n",mtrx_size,mtrx_size,i+1,mtrx_size);
            continue;
        }
        i++;
    }
    while(i < mtrx_size);

    printf("%s dosyasi olusturuldu\n",MATRIS);

    // Dosyayi kapat
    fclose(pMtrx_txt);
}


/**
 * Alinan string'de pes pese gelen boshluk karakterlerini
 * sadece tek boshluk olarak degishtirip geri veriyor
 */

char *deblank(char *inpt_str)
{
    int length, c, d;
    char *start;

    c = d = 0;

    length = strlen(inpt_str);

    start = (char*)malloc(length+1);

    if (start == NULL)
        exit(EXIT_FAILURE);

    while (*(inpt_str+c) != '\0')
    {
        if (*(inpt_str+c) == ' ')
        {
            int temp = c + 1;
            if (*(inpt_str+temp) != '\0')
            {
                while (*(inpt_str+temp) == ' ' && *(inpt_str+temp) != '\0')
                {
                    if (*(inpt_str+temp) == ' ')
                    {
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

char *trim_wht_sp(char *str)
{
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
 * String'deki eleman sayisini sayan fonksiyon
 */

int count_elem(const char *str)
{
    int counted = 0; // sonuc

    // state: (durum)
    const char* it = str;
    int inword = 0;

    do switch(*it)
        {
        case '\0':
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            if (inword)
            {
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
