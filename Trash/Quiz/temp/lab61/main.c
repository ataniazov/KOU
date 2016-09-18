// Ata Niyazov  130201108  20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_begin.h"
// ------------ YUKARIDAKI KUTUPHANELERI DEGISTIRMEYIN !!! ----------------
// ------------ YENI KUTUPHANE EKLEMEYIN !!! ----------------

/**------------------------------------------------------------
 *							BILGILER
 *------------------------------------------------------------*/

/** TODO: Ogrenci numaranizi asagidaki degiskene atayin */
const long OGRENCI_NO = 130201108;

/** TODO: Terminal numaranizi asagidaki degiskene atayin */
const int TERM_NO = 20;

/**------------------------------------------------------------
 *							AYARLAR
 *------------------------------------------------------------*/

/**
  soruyu devre disi birakmak icin ilgili satiri yorum yapabilirsiniz
  ornek:
  // #define SORU_123
*/

#define SORU_1
#define SORU_2
#define SORU_3
#define SORU_4
#define SORU_5
#define SORU_6
#define SORU_7

/**-------------------------------------------------------------
 *							UYARILAR
 *------------------------------------------------------------*/
/**
 * ONEMLI UYARI: bu uygulamada sadece asagidaki fonksiyonlari kullanabilirsiniz:
 * printf, sizeof,
 * memcpy, memcmp, memset,
 * strlen, strcpy, strcmp, strcat,
 * malloc, realloc, free
 *
 * Sinav sirasinda yukaridaki fonksiyonlar haricindeki fonksiyonlari kullanarak
 * tam puan almayi basarsaniz bile sinavdan sonra yapilacak kontrol sonucunda
 * cozumunuz yanlis sayilacaktir.
 */


/**-------------------------------------------------------------
 *							SORU 1
 *------------------------------------------------------------*/
#ifdef SORU_1

/**
 * SORU 1 : bellekten 1 tane integer sigacak kadar yer alip, icersine 1234
 * sayisini atayin. Fonksiyon bitmeden once aldiginiz yeri iade edin.
 */
void soru_1()
{
    /** TODO: 1 tane integer sigacak kadar bellekten yer alin. */
    int * pA = (int *)malloc(sizeof(int));

    /** TODO: yukarida aldiginiz bellek alanina 1234 sayisini atayin */
    *pA = 1234;

    /** TODO: yukarida aldiginiz bellek alanini sisteme iade edin */
    free(pA);

}
#endif /* SORU_1 SON */


/**-------------------------------------------------------------
 *							SORU 2
 *------------------------------------------------------------*/
#ifdef SORU_2
/**
 * SORU 2 : bellekten N elemanli integer dizisi icin dinamik olarak yer alin.
 * Bu dinamik diziye [0,N) arasindaki sayilarin karelerini atayip fonksiyondan dondurun.
 *
 * @N : dinamik dizinin eleman sayisi
 * @return : bellekten alinan alanin adresi
 *
 * ornek 1:
 *    N : 3
 *	  return : dinamik dizi (0, 1, 4)
 *
 * ornek 2:
 *    N : 5
 *	  return : dinamik dizi (0, 1, 4, 9, 16)
 */
int * soru_2(int N)
{

    /** TODO: kodu buraya yazin */
    int i;
    int * dizi = (int *)malloc(N * sizeof(int));

    for(i = 0; i < N; i++)
    {
        dizi[i] = i*i;
    }

    return dizi;

}
#endif /* SORU_2 SON */


/**-------------------------------------------------------------
 *							SORU 3
 *------------------------------------------------------------*/
#ifdef SORU_3
/**
 * SORU 3 : Fonksiyona gelen x stringi daha onceden malloc ile olustrulmustur.
 *
 * Sizden asagidaki iki islem istenilmektedir.
 *	1. Bu stringin boyutunu degistirerek sonuna "..." ekleyiniz.
 *	2. stringin son halini fonksiyondan dondurunuz
 *
 * ornek girdi cikti:
 *	x : abc => x : abc...
 *	x : 11111 => x : 11111...
 *
 */
char * soru_3(char * x)
{

    /** TODO: kodu buraya yazin */
    x = (char *)realloc(x,(strlen(x)+1) + (3 * sizeof(char)));

    strcat(x,"...");

    return x;

}
#endif /* SORU_3 SON */


/**-------------------------------------------------------------
 *							SORU 4
 *------------------------------------------------------------*/
#ifdef SORU_4
/**
 * SORU 4 : fonksiyona gelen 3 stringin birlesmis halini olusturan
 * fonksiyonu yaziniz.
 *
 * ornek :
 *   x : "aaa"
 *   y : "bbb"
 *   z : "c"
 *   return : "aaabbbc"
 *
 * UYARI: x, y, z'nin degerlerini degistirmeyin.
 */
char * soru_4(const char * x, const char * y, const char * z)
{

    /** TODO: x, y, z karakter dizilerini pes pese sigacagi kadar yer alin.
    	(Not: yer eksik ya da fazla degil, tam sigacagi kadar olamlidir) */
    char * birles = (char *)malloc((strlen(x) + strlen(y) + strlen(z) + 1) * sizeof(char));

    strcpy(birles,x);
    strcat(birles,y);
    strcat(birles,z);

    /** TODO: aldiginiz yere x, y, z stringlerini pes pese ekleyerek kopyalayin
    	ve fonksiyondan dondurun */

    return birles;

}
#endif /* SORU_4 SON */


/**-------------------------------------------------------------
 *							SORU 5
 *------------------------------------------------------------*/

// ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
struct soru5
{
    int sayi;
    struct soru5 * sonraki;
};
// ------------ YUKARIDAKI KODU DEGISTIRMEYIN !!! ----------------

#ifdef SORU_5
/**
 * Fonksiyona ilk elemanin adresi gelen bagli listenin tum elemanlarinin
 * degerlerinin toplamini bulup fonksiyondan dondurun.
 *
 * ornek girdi : bagli liste (1 -> 2 -> 5 -> NULL)
 * cikti : return 8
 *
 * ornek girdi 2: bagli liste (5 -> 1 -> NULL)
 * cikti : return 6
 *
 */
int soru_5(struct soru5 * ilk)
{
    /** TODO: kodu buraya yazin */
    struct soru5 *e;
    int toplam = 0;
    for (e = ilk ; e != NULL ; e = e->sonraki)
    {
        toplam += e->sayi;
    }

    return toplam;

}
#endif /* SORU_5 SON */

/**-------------------------------------------------------------
 *							SORU 6
 *------------------------------------------------------------*/
#ifdef SORU_6

// ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
struct soru6
{
    int sayi;
    struct soru6 * sonraki;
};
// ------------ YUKARIDAKI KODU DEGISTIRMEYIN !!! ----------------

/**
 * Fonksiyona sayi1 ve sayi2 parametreleri gelmektedir.
 * Yukaridaki structa (struct soru6) gore bir bagli liste olusturmaniz
 * istenilmektedir.
 * "sayi1 -> sayi2 -> NULL" seklindeki iki elemanli bagli listeyi olusturunuz.
 *
 * ornek :
 *		sayi1:5
 *		sayi2:9
 *		return: bagli liste (5 -> 9 -> NULL)
 */
struct soru6 * soru_6(int sayi1, int sayi2)
{
    struct soru6 * ilk = NULL;
    struct soru6 * son = NULL;




    // ------------ YUKARIDAKI KODU DEGISTIRMEYIN !!! ----------------

    /** TODO: kodu buraya yazin */
    struct soru6 * yeni = malloc(sizeof(struct soru6));

    yeni->sayi = sayi1;
    ilk = yeni;

    yeni = malloc(sizeof(struct soru6));

    ilk->sonraki = yeni;

    yeni->sayi = sayi2;
    yeni->sonraki = NULL;


    // ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
    return ilk;
}
#endif /* SORU_6 SON */

/*-------------------------------------------------------------
 *							SORU 7
 *------------------------------------------------------------*/

// ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
#ifdef SORU_7
struct soru7
{
    int sayi;
    struct soru7 * sonraki;
};
// ------------ YUKARIDAKI KODU DEGISTIRMEYIN !!! ----------------

/**
 * diziye karsilik gelen bagli listeyi olusturan fonksiyon istenilmektedir.
 *
 * @dizi : icerisinde @N tane eleman bulunan bir dizi
 * @N : [1, 10] arasinda bir sayi
 * @return : olusturulan bagli liste (struct soru7 tipinde)
 *
 * ornek 1:
 *		dizi: {1, 2, 3, 4}
 *		return : bagli liste (1 -> 2 -> 3 -> 4 -> NULL)
 *
 * ornek 2:
 *		dizi: {5, 2}
 *		return : bagli liste (5 -> 2 -> NULL)
 *
 * NOT : elemanlarin bellek alanlarini malloc fonksiyonu ile ayri ayri aliniz
 */
struct soru7 * soru_7(const int dizi[], int N)
{
    struct soru7 * ilk = NULL;
    // ------------ YUKARIDAKI KODU DEGISTIRMEYIN !!! ----------------

    /** TODO: kodu buraya yazin */
    int state = 0;
    int i;
    struct soru7 * son = malloc(sizeof(struct soru7));


    for(i = 0; i<N; i++)
    {
        struct soru7 * yeni = malloc(sizeof(struct soru7));
        yeni->sayi = dizi[i];
        yeni->sonraki = NULL;
        if(state == 0)
       /*{
            ilk = yeni;
            state = 1;
        }

        son = yeni;
        if(i == (N-1))
        {
            son->sonraki=NULL;
        }
        */
    }



    // ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
    return ilk;
}
#endif /* SORU_7 SON */


// ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
#include "main_end.h"

