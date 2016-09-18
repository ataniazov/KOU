/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */

void _test_7(char *bulundugu_ilk_adres, int bulundugu_ilk_index);

#define SORU_0_PROTOTYPE() void soru_0()
#define SORU_1_PROTOTYPE() void soru_1(char s1[], char s2[])
#define SORU_2_PROTOTYPE() void soru_2(float x)
#define SORU_3_PROTOTYPE() double soru_3(const char *s1, const char *s2)
#define SORU_4_PROTOTYPE() void soru_4(char a, char b)
#define SORU_5_PROTOTYPE() void soru_5(char s[])
#define SORU_6_PROTOTYPE() int soru_6(const char s1[], const char s2[])
#define SORU_7_PROTOTYPE() void soru_7(const char str[], const char aranan[])
#define SORU_8_PROTOTYPE() int soru_8(const char s[], char rakamlar[])
#define SORU_9_PROTOTYPE() void soru_9(const char str[], char sonuc[])

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
