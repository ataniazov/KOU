/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */

#ifndef SORU_1
int farkli_elemanlari_bul(int A[], int N, int sonuc[]) {return -1};
#endif

#ifndef SORU_2
int alt_kume_mi(int A[], int A_size, int B[], int B_size) {return -1}
#endif

#ifndef SORU_3
int kume_kesisimi_bul(int A[], int A_size, int B[], int B_size, int sonuc[]) {return -1}
#endif

#ifndef SORU_4
int kume_birlesimi_bul(int A[], int A_size, int B[], int B_size, int sonuc[]) {return -1}
#endif

#ifndef SORU_5
int kume_farki_bul(int A[], int A_size, int B[], int B_size, int sonuc[]) {return -1};
#endif


extern void test_ogrenci_bilgileri();
extern void sonuc();
extern void exception_helper_sighandler(int signum);

#include <unistd.h>
#include <signal.h>

int main() {

	int i;
	for (i = 1 ; i < 32 ; i++)
		signal(i, exception_helper_sighandler);

	test_ogrenci_bilgileri();

#ifdef SORU_1
	extern void test_1();
	test_1();
#endif
#ifdef SORU_2
	extern void test_2();
	test_2();
#endif
#ifdef SORU_3
	extern void test_3();
	test_3();
#endif
#ifdef SORU_4
	extern void test_4();
	test_4();
#endif
#ifdef SORU_5
	extern void test_5();
	test_5();
#endif

	sonuc();

	return 0;
}
