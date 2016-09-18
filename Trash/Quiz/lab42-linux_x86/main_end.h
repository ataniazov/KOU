/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */

#ifndef SORU_0
SORU_0_PROTOTYPE() { while (1);}
#endif

#ifndef SORU_1
SORU_1_PROTOTYPE() { while (1);}
#endif

#ifndef SORU_2
SORU_2_PROTOTYPE() { while (1); }
#endif

#ifndef SORU_3
SORU_3_PROTOTYPE() { while (1); }
#endif

#ifndef SORU_4
SORU_4_PROTOTYPE() { while (1); }
#endif

#ifndef SORU_5
SORU_5_PROTOTYPE() { while (1); }
#endif

#ifndef SORU_6
SORU_6_PROTOTYPE() { while (1); }
#endif

#ifndef SORU_7
SORU_7_PROTOTYPE() { while (1); }
#endif

#ifndef SORU_8
SORU_8_PROTOTYPE() { while (1); }
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

/* #ifdef SORU_0 */
/* 	extern void test_0(); */
/* 	test_0(); */
/* #endif */
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
#ifdef SORU_9
	extern void test_9();
	test_9();
#endif

	sonuc();

	return 0;
}
