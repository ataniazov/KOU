/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */

void _test_8(int uzunluk, int rakam_sayisi, int harf_sayisi, int bosluk_sayisi);

#define SORU_0_PROTOTYPE() void soru_0()
#define SORU_1_PROTOTYPE() void soru_1(char s1[], char s2[])
#define SORU_2_PROTOTYPE() void soru_2(float x)
#define SORU_3_PROTOTYPE() int soru_3(const char *s1, const char *s2)
#define SORU_4_PROTOTYPE() void soru_4(char a, char b)
#define SORU_5_PROTOTYPE() void soru_5(char s[])
#define SORU_6_PROTOTYPE() void soru_6(const char s1[], const char s2[])
#define SORU_7_PROTOTYPE() int soru_7(const char str[], const char aranan[])
#define SORU_8_PROTOTYPE() int soru_8(const char s[])
#define SORU_9_PROTOTYPE() void soru_9(const char str[], char tersten[])

SORU_0_PROTOTYPE();
SORU_1_PROTOTYPE();
SORU_2_PROTOTYPE();
SORU_3_PROTOTYPE();
SORU_4_PROTOTYPE();
SORU_5_PROTOTYPE();
SORU_6_PROTOTYPE();
SORU_7_PROTOTYPE();
SORU_8_PROTOTYPE();
SORU_9_PROTOTYPE();

#ifndef DEGERLENDIRME
#include <stdio.h>
extern int stdio_helper_fake_printf(const char *format, ...);
#undef printf
#define printf stdio_helper_fake_printf

extern int stdio_helper_fake_scanf(const char *format, ...);
#undef scanf
#define scanf stdio_helper_fake_scanf
#endif /* USE_REAL_STDIO */
