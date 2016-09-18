/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */

#include <stdio.h>

void test_1();
void _test_1();
void test_2();
void _test_2();
void test_3();
void test_4();
void test_5();
void test_6();
void test_7();
void _test_7();

void soru_1();
void soru_2(int dizi[], int N);
int soru_3(int dizi[], int N);
void soru_4(int dizi[], int N);
int soru_5(int dizi[], int N);
int soru_6(int dizi[], int N, int aranan);
void soru_7(int dizi[], int N);

extern int stdio_helper_fake_printf(const char *format, ...);
#undef printf
#define printf stdio_helper_fake_printf

extern int stdio_helper_fake_scanf(const char *format, ...);
#undef scanf
#define scanf stdio_helper_fake_scanf
