#include "main_begin.h"
// ------------ YUKARIDAKI KUTUPHANELERI DEGISTIRMEYIN ----------------


/**------------------------------------------------------------
 *							BILGILER
 *------------------------------------------------------------*/

/** TODO: Ogrenci numaranizi asagidaki degiskene atayin */
const long OGRENCI_NO = 130201108;

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

// #define SORU_0
#define SORU_1
#define SORU_2
#define SORU_3
#define SORU_4
#define SORU_5
#define SORU_6
#define SORU_7
#define SORU_8

/**-------------------------------------------------------------
 *							SORU 0
 *------------------------------------------------------------*/
#ifdef SORU_0
void soru_0() {
/**
 * SORU 0: bu soruyu iptal edin, yukaridan yorum satiri olarak AYARLAR yazan kisma bakiniz.
 */
	printf("hatali soru. koddaki AYARLAR kismindan kapatin.\n\n");
}
#endif /* SORU_0 */

/**-------------------------------------------------------------
 *							SORU 1
 *------------------------------------------------------------*/
#ifdef SORU_1

/**
 * SORU 1: soruyu ayarlardan acip, ardindan kod icindeki islemleri yapiniz
 */
void soru_1(int a, int *p) {
	/** TODO: oncelikle soruyu ayarlardan acin */

	/** TODO: a'nin degerini asagidaki degiskene atayin */

	int a_deger = a;

	/** TODO: a'nin adresini asagidaki degiskene atayin */
	int *a_adres = &a;

	/** TODO: p'nin degerini asagidaki degiskene atayin */
	int * p_deger = p;

	/** TODO: p'nin adresini asagidaki degiskene atayin */
	int ** p_adres = &p;

	/** TODO: p'nin gosterdigi bellek adresinin icerigini asagidaki degiskene atayin */
	int p_gosterdigi_deger = *p;

	// ------------ ASAGIDAKI KODU DEGISTIRMEYIN ----------------
	_test_1(a_deger, a_adres, p_deger, p_adres, p_gosterdigi_deger);
}
#endif /* SORU_ 1 */


/**-------------------------------------------------------------
 *							SORU 2
 *------------------------------------------------------------*/
#ifdef SORU_2
/**
 * Bu fonksiyon size hazir olarak verilmistir.
 * Fonksiyon x'in karesini alip y'nin gosterdigi yere atama yapmaktadir.
 * Fonksiyonun icini yazmaniza GEREK YOKTUR.
 */
void kare_al(int x, int *y);

/**
 * SORU 2: girilen sayinin karesini bulmaniz isteniliyor.
 * Bunu yukaridaki fonksiyonu kullanarak yapiniz.
 */
void soru_2(int a) {
	int sonuc;

	kare_al(a,&sonuc);	

	/** TODO: kodu buraya yazin */

}
#endif /* SORU_2 */


/**-------------------------------------------------------------
 *							SORU 3
 *------------------------------------------------------------*/
#ifdef SORU_3
/**
 * SORU 3: s1 ve s2'nin toplamini bulup, sonucu y'nin gosterdigi yere atayan
 * fonksiyonu yaziniz
 */
void topla(int s1, int s2, int *y) {
	/** TODO: kodu buraya yazin */
	*y = s1+s2;

}
#endif /* SORU_3 */


/**-------------------------------------------------------------
 *							SORU 4
 *------------------------------------------------------------*/
#ifdef SORU_4
/**
 * SORU 4: girilen degerler ters ise yerini degistirerek siralar
 *
 * ornek 1:
 *		giris: kucuk = 10, buyuk = 5
 *	    -> yer degistir
 *		cikis: kucuk = 5, buyuk = 10
 *
 * ornek 2:
 *		giris: kucuk = 15, buyuk = 20
 *		-> islem yapmadan birak
 *		cikis: kucuk = 15, buyuk = 20
 */
void soru_4(int *kucuk, int *buyuk) {
	/** TODO: kodu buraya yazin */
	if(*kucuk>*buyuk) {
		*kucuk ^= *buyuk;
		*buyuk ^= *kucuk;
		*kucuk ^= *buyuk;
	}

}
#endif /* SORU_4 */

/**-------------------------------------------------------------
 *							SORU 5
 *------------------------------------------------------------*/
#ifdef SORU_5

int dizi[10];

/**
 * SORU 5: yukarida "dizi" isimli bir dizi verilmistir.
 * fonksiyonun icerisinde istenilenleri yapiniz.
 */
void soru_5() {
	/** TODO: "dizi"nin ilk elemaninin adresini asagidaki degiskene atayin */
	int * ilk_elemanin_adresi = &dizi[0];
	// dizi = &dizi[0];

	/** TODO: "dizi"nin son elemaninin adresini asagidaki degiskene atayin */
	int * son_elemanin_adresi = dizi+9;

	/** TODO: "dizi"nin ikinci elemaninin adresini asagidaki degiskene atayin */
	int * ikinci_elemanin_adresi = dizi+1;

	/** TODO: "dizi"nin boyutunu asagidaki degiskene atayin */
	int boyut = sizeof(dizi);

	// ------------ ASAGIDAKI KODU DEGISTIRMEYIN ----------------
	_test_5(ilk_elemanin_adresi, son_elemanin_adresi, ikinci_elemanin_adresi, boyut);
}
#endif /* SORU_5 */


/**-------------------------------------------------------------
 *							SORU 6
 *------------------------------------------------------------*/
#ifdef SORU_6

/**
 * SORU 6: "sayi"nin isaretini, tam kismini ve ondalik kismini bulan fonksiyonu yaziniz.
 * isaret char tipinde '-' veya '+' olmalidir.
 *
 * ornek 1:
 *   sayi = 55.65
 *   isareti: '+', tam kisim: 55, ondalik kisim: 0.65
 *
 * ornek 2:
 *   sayi = -23.88
 *   isareti: '-', tam kisim: -23, ondalik kisim: 0.88
 *
 * NOT : sayi 0 ise isaretini '+' yapiniz.
 */
void soru_6(float sayi, char * isaret, int * tam, float * ondalik) {
	/** TODO: kodu buraya yazin */
	int tam_kisim = sayi;

	*tam = tam_kisim;
	*ondalik = (sayi - tam_kisim);
	
	if(sayi<0) {
		*isaret = '-';
	} else {
		*isaret = '+';
	}	

}
#endif /* SORU_6 */

/**-------------------------------------------------------------
 *							SORU 7
 *------------------------------------------------------------*/
#ifdef SORU_7
void yazdir(int *ilk_eleman, int *son_eleman);
/**
 * Yukaridaki yazdir fonksiyonu size hazir olarak verilmistir
 * fonksiyonun icindeki kod asagidaki bulunmaktadir:
 *
 *		int * p;
 *		for (p = ilk_eleman ; p <= son_eleman ; p++) {
 *			printf("%d ", *p);
 *		}
 *
 * bu bilgiyi kullanarak asagidaki soruyu yapiniz.
 */

/**
 * SORU 7: yukarida hazir olarak verilen fonksiyonu kullanarak soruda istenilen
 * islemleri yapiniz.
 */
void soru_7(int dizi[]) {
	/** TODO: yazdir fonksiyonunu kullanarak dizinin ilk 10 elemanini yazdirin */
	yazdir(dizi,dizi+9);

	/** TODO: yazdir fonksiyonunu kullanarak dizinin [3, 6] arasindaki elemanlarini yazdirin */
	yazdir(dizi+3,dizi+6);
}
#endif /* SORU_7 */

/**-------------------------------------------------------------
 *							SORU 8
 *------------------------------------------------------------*/
#ifdef SORU_8

/**
 * SORU 8: dizinin elemanlarinin toplamini bulan fonksiyonu yaziniz.
 * Burada dizi adres (pointer) olarak verilmektedir.
 *
 * ilk_eleman : dizinin ilk elemaninin adresi
 * son_eleman : dizinin son elemaninin adresi
 *
 * return : dizinin toplami
 *
 * NOT: SORU 7'deki hazir fonksiyonu ornek alabilirsiniz
 */
int soru_8(int *ilk_eleman, int *son_eleman) {
	/** TODO: kodu buraya yazin */
	int dizi_toplam = 0;
	int *p;

	for(p=ilk_eleman; p <= son_eleman; p++) {
		dizi_toplam += *p;
	}

	return dizi_toplam;
}
#endif /* SORU_8 */

/**-------------------------------------------------------------
 *						SORULAR BITTI
 *------------------------------------------------------------*/


// ------------ ASAGIDAKI KODU DEGISTIRMEYIN ----------------
#include "main_end.h"
