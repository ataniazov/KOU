/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */

#ifndef SORU_0
void soru_0() {}
#endif

#ifndef SORU_1
void soru_1(int a, int *p) {}
#endif

#ifndef SORU_2
void soru_2(int a) {-1}
#endif

#ifndef SORU_3
void topla(int s1, int s2, int *y) {}
#endif

#ifndef SORU_4
void soru_4(int *a, int *b) {}
#endif

#ifndef SORU_5
void soru_5(int dizi[10]) {}
#endif

#ifndef SORU_6
void soru_6(float sayi, char *isaret, int *tam, float * ondalik) {}
#endif

#ifndef SORU_7
void soru_7(int dizi[]) {}
#endif

#ifndef SORU_7
int soru_8(int *ilk_eleman, int *son_eleman) { return -1; }
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

#ifdef SORU_0
	extern void test_0();
	test_0();
#endif
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
#ifdef SORU_6
	extern void test_6();
	test_6();
#endif
#ifdef SORU_7
	extern void test_7();
	test_7();
#endif
#ifdef SORU_8
	extern void test_8();
	test_8();
#endif

	sonuc();

	return 0;
}
