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
const long OGRENCI_NO = 0;

/** TODO: Terminal numaranizi asagidaki degiskene atayin */
const int TERM_NO = 0;

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

  isdigit(x) : eger x bir sayi ise 0'dan farkli bir deger, sayi degilse 0 dondudur.
  isalpha(x) : eger x bir harf ise 0'dan farkli bir deger, harf degilse 0 dondudur.
  islower(x) : eger x bir kucuk harf ise 0'dan farkli bir deger, kucuk harf degilse 0 dondudur.
  isupper(x) : eger x bir buyuk harf ise 0'dan farkli bir deger, buyuk harf degilse 0 dondudur.

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
	/** TODO: x'i yazdiriniz */
	printf("%f",x);

	/** TODO: x'i virgulenden sonra 2 basamakli olarak yazdiriniz */
	printf("%.2f",x);

}
#endif /* SORU_2 SON */


/**-------------------------------------------------------------
 *							SORU 3
 *------------------------------------------------------------*/
#ifdef SORU_3
/**
 * SORU: s1 ve s2 sayilari string olarak fonksiyona gelmektedir. hazir fonksiyon
 * kullanarak double'a cevirip s1 ve s2'nin toplamini fonksiyondan dondurunuz.
 *
 * ORNEK 1 : s1:"3.5" , s2:"5.0"
 *		   return: 8.50000
 * ORNEK 2 : s1:"2.2" , s2:"2.8"
 *		   return: 5.00000
 */
double soru_3(const char s1[], const char s2[]) {
	/** TODO: kodu buraya yazin */
	int sum = atof(s1) + atof(s2);

	return sum;
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
 * toupper(x) : x karakterinin buyuk harf versiyonunu dondudur
 * tolower(x) : x karakterinin kucuk harf versiyonunu dondudur
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
 * bu stringdeki tum harfleri kucuk harfe cevirecek sekilde tamamlayiniz.
 *
 * NOT : "toupper" ve "tolower" fonksiyonlarini kullanabilirsiniz.
 */
void soru_5(char s[]) {
	/** TODO: s stringindeki tum harfleri kucuk harf yapiniz */
	int i;
	printf("%s\n",s);

	for(i=0; s[i] != '\0'; i++) {
		s[i] = tolower(s[i]);
	}
	printf("%s\n",s);

}
#endif /* SORU_5 SON */


/**-------------------------------------------------------------
 *							SORU 6
 *------------------------------------------------------------*/
#ifdef SORU_6
/**
 * SORU 6 : fonksiyona s1 ve s2 stringleri gelmektedir. fonksiyonda iki stringin
 * degeri ayniysa 1, farkliysa 0 degeri fonksiyondan dondurulmelidir.
 *
 * ORNEK 1 :
 *		girdi: s1:"aaa" , s2:"bbb"
 *		return: 0
 *
 * ORNEK 2 :
 *		girdi: s1:"aaa" , s2:"aaa"
 *		return: 1
 *
 * NOT : islemi hazir string fonksiyonlarini kullanarak yapabilirsiniz
 */
int soru_6(const char s1[], const char s2[]) {
	/** TODO: kodu buraya yazin */

	return (strcmp(s1,s2)) ? 0 : 1;
}
#endif /* SORU_6 SON */

/**-------------------------------------------------------------
 *							SORU 7
 *------------------------------------------------------------*/
#ifdef SORU_7
/**
 * SORU 7 : string icerisinde arama yapmaniz istenilmektedir. Arananin ilk
 *	bulundugu bellek adresi ve dizi indexi fonksiyon icerisinde tanimli
 *	degiskenlere atanmalidir.
 *
 * @s : aramanin yapilacagi string
 * @aranan : s icerisinde aranacak olan string
 *
 * bulundugu_ilk_adres : arananin bulundugu ilk bellek adresi, eger aranan yoksa NULL atanmali
 * bulundugu_ilk_index : arananin bulundugu ilk index, eger aranan yoksa -1 atanmali
 *
 * ORNEK 1:
 *		s : "abc def", aranan : "bc"
 *		ilk_bulundugu_index : 1
 *
 * ORNEK 2:
 *		s : "abc def", aranan : "xyz"
 *		ilk_bulundugu_index : -1
 */
void soru_7(const char s[], const char aranan[]) {
	char * bulundugu_ilk_adres = strstr(s,aranan);
	int bulundugu_ilk_index = (bulundugu_ilk_adres == NULL) ? -1 : (bulundugu_ilk_adres - s);
	// ------------ YUKARIDAKI DEGISKENLERI SILMEYIN !!! ----------------

	/** TODO: islemi asagida yapin ve buldugunuz sonuclari yukarida tanimli degiskenlere atayin */





	// ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
	_test_7(bulundugu_ilk_adres, bulundugu_ilk_index);
}
#endif /* SORU_7 SON */

/*-------------------------------------------------------------
 *							SORU 8
 *------------------------------------------------------------*/
#ifdef SORU_8
/**
 * SORU 8 : string icerisindeki rakamlari bulmaniz istenilmektedir.
 *  buldugunuz rakamlar @rakamlar isimli string icerisine kaydedilmelidir.
 *
 * @s : icerisinde rakamlarin aranacagi string
 *
 * @rakamlar: buldugunuz rakamlari sirayla ekleyeceginiz string
 * @return : s icersindeki rakamlarin sayisi
 *
 * ORNEK 1: s:"aaa 123 bc 67"
 *	cikti : rakamlar : "12367"
 *			return : 5
 *
 * ORNEK 2: s:"abc"
 *	cikti : rakamlar : ""
 *			return : 0
 *
 * ORNEK 3: s:"4ab67c"
 *	cikti : rakamlar : "467"
 *			return : 0
 */
int soru_8(const char s[], char rakamlar[]) {
	/** TODO: kodu buraya yazin */
	int i,j=0;

	for(i=0; s[i] != '\0'; i++) {
		if(isdigit(s[i])) {
			rakamlar[j++] = s[i];
		}
	}
	rakamlar[j] = '\0';

	return j;
}
#endif /* SORU_8 SON */


/**-------------------------------------------------------------
 *							SORU 9
 *------------------------------------------------------------*/
#ifdef SORU_9
/**
 * SORU 9 : s ve sonuc stringleri fonksiyona gelmektedir. s stringindeki:
 *		tum kucuk harfleri buyuk harfe,
 *		tum buyuk harfleri kucuk harfe,
 *	donusturerek sonuc stringine atayiniz.
 *
 * ORNEK 1:
 *		girdi: s:"a B"
 *		cikti: sonuc:"A b"
 *
 * ORNEK 2:
 *		girdi: s:"ab cDefGH 98"
 *		cikti: sonuc:"AB CdEFgh 98"
 */
void soru_9(const char s[], char sonuc[]) {
	/** TODO: kodu buraya yazin */
	int i;

	for(i=0; s[i] != '\0'; i++) {
		sonuc[i] = (islower(s[i])) ? toupper(s[i]) : tolower(s[i]);
	}
	sonuc[i] = '\0';
}
#endif /* SORU_9 SON */


// ------------ ASAGIDAKI KODU DEGISTIRMEYIN !!! ----------------
#include "main_end.h"
