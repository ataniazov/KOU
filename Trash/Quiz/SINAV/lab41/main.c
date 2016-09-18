#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main_begin.h"
// ------------ YUKARIDAKI KUTUPHANELERI DEGISTIRMEYIN !!! ----------------

/**------------------------------------------------------------
 *							BILGILER
 *------------------------------------------------------------*/

/** TODO: Ogrenci numaranizi asagidaki degiskene atayin */
const long OGRENCI_NO = 130201065;

/** TODO: Terminal numaranizi asagidaki degiskene atayin */
const int TERM_NO = 22;

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
#define SORU_8
#define SORU_9

/**------------------------------------------------------------
 *	  GEREKEBILECEK STRING FONKSIYONLARININ LISTESI
 *------------------------------------------------------------*/
/**
  strcpy(a, b) : b stringini a stringine kopyalar
  strcat(a, b) : b stringini a stringinin sonuna ekler
  strcmp(a, b) : a ve b stringlerini karsilastirir. esitse 0, a > b ise pozitif
	sayi, a < b ise negatif sayi dondurur.

  strchr(s, c) : s stringi icerisinde c karakterini arar. c karakteri s icerisinde
	yoksa NULL, varsa s icerisindeki ilk c karakterinin bellek adrsini dondudur.

  strstr(a, b) : a stringi icerisinde b stringini arar. b stringi a icerisinde
	yuksa NULL,	varsa a icerisindeki ilk b stringinin bellek adresini dondudur.

  atoi(x) : x stringini integera cevirir
  atof(x) : x stringini doublea cevirir

  isdigit(x) : eger x sayi ise 0'dan farkli bir deger, sayi degilse 0 dondudur.
  isalpha(x) : eger x harf ise 0'dan farkli bir deger, harf degilse 0 dondudur.
  islower(x) : eger x kucuk harf ise 0'dan farkli bir deger, kucuk harf degilse 0 dondudur.
  isupper(x) : eger x buyuk harf ise 0'dan farkli bir deger, buyuk harf degilse 0 dondudur.

  toupper(x) : x'in buyuk harf karsiligini fonksiyondan dondurur
  tolower(x) : x'in kucuk harf karsiligini fonksiyondan dondurur
 */

/**-------------------------------------------------------------
 *							SORU 1
 *------------------------------------------------------------*/
#ifdef SORU_1

/**
 * SORU 1: s1 ve s2 karakter dizileri (string) fonksiyona gelmektedir.
 *		bu stringlerle ilgili asagida belirtilen islemleri yapiniz.
 */
void soru_1(char s1[], char s2[]) {
	/** TODO: s1 stringine "Kocaeli Universitesi" degerini kopyalayin */
    strcpy(s1,"Kocaeli Universitesi");

	/** TODO: s1 stringini ekrana yazdirin */

    printf("%s",s1);
	/** TODO: s2 stringinin sonuna "..." ekleyin */
    strcat(s2,"...");

	/** TODO: s2 stringini ekrana yazdirin */
    printf("%s",s2);

}
#endif /* SORU_1 SON */


/**-------------------------------------------------------------
 *							SORU 2
 *------------------------------------------------------------*/
#ifdef SORU_2
/**
 * SORU 2 : float tipinde x degiskeni fonksiyona gelmektedir.
 *		soruda istenilen yazdirma islemlerini yapiniz.
 */
void soru_2(float x) {
	/** TODO: x degiskenini yazdiriniz */

    printf("%f",x);
	/** TODO: x degiskenini virgulenden sonra 3 basamakli olarak yazdiriniz */
    printf("%3.f",x);

}
#endif /* SORU_2 SON */


/**-------------------------------------------------------------
 *							SORU 3
 *------------------------------------------------------------*/
#ifdef SORU_3
/**
 * SORU: s1 ve s2 sayilari string olarak fonksiyona gelmektedir. hazir fonksiyon
 * kullanarak integer'a cevirip s1 ve s2'nin toplamini fonksiyondan dondurunuz.
 *
 * ORNEK 1 : s1:"10" , s2:"5"
 *		   return: 15
 * ORNEK 2 : s1:"2" , s2:"4"
 *		   return: 6
 */
int soru_3(const char *s1, const char *s2) {
	/** TODO: kodu buraya yazin */
    int x,y;
    x=atoi(s1);
    y=atoi(s2);

	return x+y;
}
#endif /* SORU_3 SON */


/**-------------------------------------------------------------
 *							SORU 4
 *------------------------------------------------------------*/
#ifdef SORU_4
/**
 * SORU 4 : asagida anlatilan iki hazir C fonksiyonuna gore soruda istenilen
 *	islemleri yapiniz
 *
 * toupper(x) : x karakterinin buyuk harf karsiligini dondudur
 * tolower(x) : x karakterinin kucuk harf karsiligini dondudur
 */
void soru_4(char a, char b) {
	/** TODO: a degiskenini buyuk harf yapip ekrana yazdirin */
    printf("%c",toupper(a));

	/** TODO: b degiskenini kucuk harf yapip ekrana yazdirin */
    printf("%c",tolower(b));

}
#endif /* SORU_4 SON */


/**-------------------------------------------------------------
 *							SORU 5
 *------------------------------------------------------------*/
#ifdef SORU_5
/**
 * SORU 5 : s stringi fonksiyona gelmektedir. Asagidaki fonksiyonu
 * bu stringdeki tum harfleri buyuk harfe cevirecek sekilde tamamlayiniz.
 */
void soru_5(char s[]) {
	/** TODO: s stringindeki tum harfleri buyuk harf yapiniz */
    int i;

    for(i=0 ; s[i]!='\0' ; i++){
        s[i]=toupper(s[i]);
    }

}
#endif /* SORU_5 SON */


/**-------------------------------------------------------------
 *							SORU 6
 *------------------------------------------------------------*/
#ifdef SORU_6
/**
 * SORU 6 : fonksiyona s1 ve s2 stringleri gelmektedir. fonksiyonda iki stringin
 * degeri ayniysa ekrana "esit" , farkliysa "farkli" yazdirilmalidir.
 *
 * ORNEK 1 :
 *		girdi: s1:"aaa" , s2:"bbb"
 *		ekran ciktisi : farkli
 *
 * ORNEK 2 :
 *		girdi: s1:"aaa" , s2:"aaa"
 *		ekran ciktisi : esit
 *
 * NOT 1 : islemi hazir string fonksiyonlarini kullanarak yapabilirsiniz
 *
 * NOT 2 : ekran ciktisinda ekrana yazilan yazi ornektekiyle bire bir ayni
 *	olmalidir. Ayni olmazsa soru yanlis kabul edilir.
 */
void soru_6(const char s1[], const char s2[]) {
	/** TODO: yukarida anlatilan islemi yapiniz.
		sonucunu printf kullanarak yazdiriniz */



}
#endif /* SORU_6 SON */

/**-------------------------------------------------------------
 *							SORU 7
 *------------------------------------------------------------*/
#ifdef SORU_7
/**
 * SORU 7 : string icerisinde arama yapan ve ilk bulundugu indexi donduren
 *	fonksiyon istenilmektedir.
 *
 * @s : aramanin yapilacakgi string
 * @aranan : s icerisinde aranacak olan string
 * @return : s icinde aranan varsa ilk bulundugu index, yoksa -1
 *
 *
 * ORNEK 1 :
 *    s : "aaa bbb", aranan : "bb"
 *    return : 4
 *
 * ORNEK 2 :
 *    s : "aaa bbb", aranan : "c"
 *    return : -1
 *
 * ORNEK 3 :
 *    s : "aaa bbb", aranan : "aaa"
 *    return : 0
 */
int soru_7(const char s[], const char aranan[]) {
	/** TODO: kodu buraya yazin */

    int x=strstr(s,aranan);
    if(x==0)
   return -1;
   else
    return x;
}
#endif /* SORU_7 SON */

/*-------------------------------------------------------------
 *							SORU 8
 *------------------------------------------------------------*/
#ifdef SORU_8
/**
 * SORU 8 : fonksiyona gelen s stringinin: karakter sayisini, rakam sayisini,
 *	harf sayisini ve bosluk sayisini bulunuz.
 *
 * ORNEK 1:
 *	s : "abc 12 3"
 *	karakter_sayisi: 8, rakam_sayisi: 3, harf_sayisi: 3, bosluk_sayisi: 2
 *
 *	s : "ab12"
 *	karakter_sayisi: 4, rakam_sayisi: 2, harf_sayisi: 2, bosluk_sayisi: 0
 *
 * NOT : Fonksiyona gelen s stringi rastgeledir. Farkli degerler gorebilirsiniz,
 *	bu bir problem degildir.
 */
int soru_8(const char s[]) {
	int karakter_sayisi = 0;
	int rakam_sayisi = 0;
	int harf_sayisi = 0;
	int bosluk_sayisi = 0;
	// ------------ YUKARIDAKI DEGISKENLERI SILMEYIN !!! ----------------

	/** TODO: kodu asagiya yazin ve buldugunuz sonuclari yukarida tanimli olan
	degiskenlere atayin */
    int i;
    for(i=0;s[i]!='\0';i++){
     if(ispunct(s[i]))
        karakter_sayisi++;
   else if(isdigit(s[i]))
    rakam_sayisi++;
    else if(isalpha(s[i]))
        harf_sayisi++;
    else if(s[i]==' ')
        bosluk_sayisi++;
    }

	// ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
	_test_8(karakter_sayisi, rakam_sayisi, harf_sayisi, bosluk_sayisi);
	return 0;
}
#endif /* SORU_8 SON */


/**-------------------------------------------------------------
 *							SORU 9
 *------------------------------------------------------------*/
#ifdef SORU_9
/**
 * SORU 9 : @s stringinin tersten yazilisini @tersten isimli stringe atayacak
 *	sekilde asagidaki fonksiyonu doldurunuz.
 */
void soru_9(const char s[], char tersten[]) {
	/** TODO: s stringinin tersten yazilisini tersten isimli stringe kaydedin */

}
#endif /* SORU_9 SON */


// ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
#include "main_end.h"
