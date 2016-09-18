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
#define SORU_6
#define SORU_7


/*-------------------------------------------------------------
 *							SORU 1
 *------------------------------------------------------------*/
#ifdef SORU_1
void soru_1() {
	// TODO: dizinin ilk 5 elemanina sirasiyla 1, 2, 3, 4, 5 degerlerini atayin.
	int dizi[100];

	// ------------ ASAGIDAKI KODU DEGISTIRMEYIN ----------------
	_test_1(dizi);
}
#endif /* SORU_ 1 */


/*-------------------------------------------------------------
 *							SORU 2
 *------------------------------------------------------------*/
#ifdef SORU_2
void soru_2(int dizi[], int N) {

	// TODO: dizinin ilk elemanini asagidaki degiskene atayin
	int ilk = -1;

	// TODO: dizinin ucuncu elemanini asagidaki degiskene atayin
	int bastan_ucuncu = -1;

	// TODO: dizinin son elemanini asagidaki degiskene atayin
	int son = -1;

	// TODO: dizinin sondan ikinci elemanini asagidaki degiskene atayin
	int sondan_ikinci = -1;

	// ------------ ASAGIDAKI KODU DEGISTIRMEYIN ----------------
	_test_2(dizi, N, ilk, bastan_ucuncu, son, sondan_ikinci);
}
#endif /* SORU_2 */


#ifdef SORU_3
/*-------------------------------------------------------------
 *							SORU 3
 *------------------------------------------------------------*/
int soru_3(int dizi[], int N) {

	// TODO: dizinin elemanlarinin toplamini bulun ve fonksiyondan dondurun
	return -1;
}
#endif /* SORU_3 */


/*-------------------------------------------------------------
 *							SORU 4
 *------------------------------------------------------------*/
#ifdef SORU_4
void soru_4(int dizi[], int N) {
/*
  - @dizi 'yi kucukten buyuge dogru siralayan kodu yaziniz
*/

	// TODO: diziyi kucukten buyuge dogru siralayiniz

}
#endif /* SORU_4 */

/*-------------------------------------------------------------
 *							SORU 5
 *------------------------------------------------------------*/
#ifdef SORU_5
/**
 * girilen diziyi buyukten kucuge siralar
 * NOT: Bu fonksiya kod yazmayin. Kodlari size hazir olarak verildi.
 */
extern void sirala_s5(int dizi[], int N);

int soru_5(int dizi[], int N) {
/*
  - dizideki en buyuk 5 elemanin toplamini bulunuz

  - en buyuk X tane elemani bulmanin en kolay yolu, dizinin buyukten kucuge
    siralanarak ilk X tane elemanin alinmasidir.
*/

	// TODO: diziyi buyukten kucuge siralayiniz
	// bunun icin yukarida verilen hazir fonksiyonu (sirala_s5) kullaniniz


	return -1;
}
#endif /* SORU_5 */


/*-------------------------------------------------------------
 *							SORU 6
 *------------------------------------------------------------*/
#ifdef SORU_6
int soru_6(int dizi[], int N, int aranan) {
/*
  - @aranan degerine sahip elemanlardan @dizi 'de kac tane oldugunu bulan
  fonksiyonu yaziniz. @N dizinin eleman sayisidir

  - ORNEK: {1,2,3,1,2,2,2}
	aranan: 1 -> 2 dondurur
	aranan: 2 -> 4 dondurur
	aranan: 4 -> 0 dondurur
*/

	// TODO: sonucu bulun ve fonksiyondan dondurun

	return -1;
}
#endif /* SORU_6 */


/*-------------------------------------------------------------
 *							SORU 7
 *------------------------------------------------------------*/
#ifdef SORU_7
void soru_7(int dizi[], int N) {
/*
  - dizide en cok olan elemani ve kac tane oldugunu bulunuz

  - ornek: {1, 1, 2, 2, 2, 3, 4}
	EN_COK: 2
	EN_COK_TANE: 3

  - ornek: {1, 2, 3, 1} -> 2
    EN_COK: 1
	EN_COK_TANE: 2
*/

	// TODO: soruda anlatilan islemi yapin



	// TODO: en cok bulunan elemanin degerini bu degiskene atayin
	int EN_COK = -1;

	// TODO: en cok bulunan elemanin kac kere bulundugu bu degiskene atayin
	int EN_COK_TANE = -1;

	// ------------ ASAGIDAKI KODU DEGISTIRMEYIN ----------------
	_test_7(dizi, N, EN_COK, EN_COK_TANE);
}
#endif /* SORU_7 */


/*-------------------------------------------------------------
 *						SORULAR BITTI
 *------------------------------------------------------------*/


// ------------ ASAGIDAKI KODU DEGISTIRMEYIN ----------------
#include "main_end.h"
