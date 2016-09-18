#include "main_begin.h"
// ------------ YUKARIDAKI KUTUPHANELERI DEGISTIRMEYIN ----------------


/*-------------------------------------------------------------
 *							BILGILER
 *------------------------------------------------------------*/

// TODO: Ogrenci numaranizi asagidaki degiskene atayin
const long OGRENCI_NO = -1;

// TODO: Terminal numaranizi asagidaki degiskene atayin
const int TERM_NO = -1;


/*-------------------------------------------------------------
 *							AYARLAR
 *------------------------------------------------------------*/

/*
  soruyu gecersiz yapmak icin ilgili satiri yorum yapabilirsiniz
  ornek:
  // #define SORU_123
*/

#define SORU_1
#define SORU_2
#define SORU_3
#define SORU_4
#define SORU_5


/*-------------------------------------------------------------
 *							SORU 1
 *------------------------------------------------------------*/
#ifdef SORU_1

/**
 * A dizisinin ayni olmayan elemanlarini sonuc dizisine atar.
 *
 * ornek 1
 *		girdi:
 *			A = {1, 1, 1, 2, 2}
 *			N = 5
 *			sonuc = {?, ?, ?, ?, ?} // fonksiyona ici belirsiz olarak geldi
 *		cikti:
 *			sonuc = {1, 2, ?, ?, ?} // sonuc dizisi buldugunuz farkli elemanlari icermeli
 *			return 2;
 *
 * ornek 2
 *		girdi:
 *			A = {1, 3, 2, 4}
 *			N = 4
 *			sonuc = {?, ?, ?, ?}
 *		cikti:
 *			sonuc = {1, 3, 2, 4}
 *			return 4;
 *
 * @A : girilen dizi
 * @N : A dizisinin boyutu
 *
 * @sonuc : farkli elemanlari saklayan dizi
 * @return : farkli elemanlarin sayisi
 */
int farkli_elemanlari_bul(int A[], int N, int sonuc[]) {

	// TODO: yukaridaki dokumana gore kodu buraya yazin

	return -1;
}
#endif /* SORU_ 1 */


/*-------------------------------------------------------------
 *							SORU 2
 *------------------------------------------------------------*/
#ifdef SORU_2
/**
 * B dizisinin, A'nin alt kumesi olup olmadigini tespit eder.
 *
 * ornek 1
 *		girdi:
 *			A = {1, 2, 3}
 *			A_size = 3
 *			B = {1, 3}
 *			B_size = 2
 *		cikti:
 *			return 1; // B, A'nin alt kumesidir
 *
 * ornek 2
 *		girdi:
 *			A = {1, 3, 4, 2}
 *			A_size = 4
 *			B = {4, 5}
 *			B_size = 2
 *		cikti:
 *			return 0; // B, A'nin alt kumesi degil
 *
 * @A : buyuk olan dizi
 * @A_size : A dizisinin boyutu
 * @B : alt kume kontrolu yapilan dizi
 * @B_size : B dizisinin boyutu
 *
 * @return : B, A'nin alt kumesiyse 1, degilse 0
 */
int alt_kume_mi(int A[], int A_size, int B[], int B_size) {

	// TODO: yukaridaki dokumana gore kodu buraya yazin

	return -1;
}
#endif /* SORU_2 */


/*-------------------------------------------------------------
 *							SORU 3
 *------------------------------------------------------------*/
#ifdef SORU_3
/**
 * A ve B dizilerinin kume mantigiyla kesisimini bulur ve sonuc isimli diziye atar
 *
 * ornek 1
 *		girdi:
 *			A = {1, 2, 3}
 *			A_size = 3
 *			B = {3, 4}
 *			B_size = 2
 *			sonuc = {?, ?, ?}
 *		cikti:
 *			sonuc = {3, ?, ?} // buldugunuz kesisimi sonuc dizisine atiyorsunuz
 *			return 1; // sonucta 1 tane eleman var
 *
 * ornek 2
 *		girdi:
 *			A = {1, 2, 3}
 *			A_size = 3
 *			B = {4, 6, 5}
 *			B_size = 3
 *			sonuc = {?, ?, ?}
 *		cikti:
 *			sonuc = {?, ?, ?} // kesisim olmadigi icin sonuc dizisi degismedi
 *			return 0; // sonucta 0 tane eleman var (kesisim bos kume)
 *
 * @A : A dizisi
 * @A_size : A dizisinin boyutu
 * @B : B dizisi
 * @B_size : B dizisinin boyutu
 *
 * @sonuc : kesisen elemanlarin bulundugu dizi
 * @return : kesisimdeki eleman sayisi
 */
int kume_kesisimi_bul(int A[], int A_size, int B[], int B_size, int sonuc[]) {

	// TODO: yukaridaki dokumana gore kodu buraya yazin

	return -1;
}
#endif /* SORU_3 */


/*-------------------------------------------------------------
 *							SORU 4
 *------------------------------------------------------------*/
#ifdef SORU_4
/**
 * A ve B dizilerinin kume mantigiyla birlesimini bulur ve sonuc isimli diziye atar
 *
 * ornek 1
 *		girdi:
 *			A = {1, 2, 3}
 *			A_size = 3
 *			B = {3, 4}
 *			B_size = 2
 *			sonuc = {?, ?, ?, ?, ?}
 *		cikti:
 *			sonuc = {1, 2, 3, 4, ?} // Kume islemi oldugu icin dizide 3 degerli eleman bir kere bulunmali.
 *			return 4; // sonucta 4 tane eleman var
 *
 * ornek 2
 *		girdi:
 *			A = {1, 2, 3}
 *			A_size = 3
 *			B = {4, 6, 5}
 *			B_size = 3
 *			sonuc = {?, ?, ?, ?, ?, ?}
 *		cikti:
 *			sonuc = {1, 2, 3, 4, 5, 6} // buldugunuz birlesim elemanlarini sonuca atiyorsunuz
 *			return 0; // sonucta 0 tane eleman var (kesisim bos kume)
 *
 * @A : A dizisi
 * @A_size : A dizisinin boyutu
 * @B : B dizisi
 * @B_size : B dizisinin boyutu
 *
 * @sonuc : birlesimin bulundugu dizi
 * @return : birlesimdeki eleman sayisi
 */
int kume_birlesimi_bul(int A[], int A_size, int B[], int B_size, int sonuc[]) {

	// TODO: yukaridaki dokumana gore kodu buraya yazin

	return -1;
}
#endif /* SORU_4 */

/*-------------------------------------------------------------
 *							SORU 5
 *------------------------------------------------------------*/
#ifdef SORU_5
/**
 * A ve B dizilerinde kume mantigiyla A'nin B'den farkini bulur ve sonuc isimli diziye atar
 *
 * ornek 1
 *		girdi:
 *			A = {1, 2, 3}
 *			A_size = 3
 *			B = {3, 4}
 *			B_size = 2
 *			sonuc = {?, ?, ?}
 *		cikti:
 *			sonuc = {1, 2, ?} // A'da bulunup B'de bulunmayan 1 ve 2 elemanlari
 *			return 2; // sonucta 2 tane eleman var
 *
 * ornek 2
 *		girdi:
 *			A = {1, 2, 3}
 *			A_size = 3
 *			B = {4, 6, 5}
 *			B_size = 3
 *			sonuc = {?, ?, ?}
 *		cikti:
 *			sonuc = {1, 2, 3}
 *			return 3; // sonucta 3 tane eleman var (kesisim bos kume)
 *
 * @A : A dizisi
 * @A_size : A dizisinin boyutu
 * @B : B dizisi
 * @B_size : B dizisinin boyutu
 *
 * @sonuc : A fark B kumesi
 * @return : A fark B kumesindeki eleman sayisi
 */
int kume_farki_bul(int A[], int A_size, int B[], int B_size, int sonuc[]) {

	// TODO: yukaridaki dokumana gore kodu buraya yazin

	return -1;
}
#endif /* SORU_5 */


/*-------------------------------------------------------------
 *						SORULAR BITTI
 *------------------------------------------------------------*/


// ------------ ASAGIDAKI KODU DEGISTIRMEYIN ----------------
#include "main_end.h"
