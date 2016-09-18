/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */

void _test_1(int a_deger, int * a_adres, int * p_deger, int ** p_adres, int p_gosterdigi_deger);
void _test_5(int * ilk_elemanin_adresi, int * son_elemanin_adresi, int * ikinci_elemanin_adresi, int boyut);
void _test_2(int *a, int *sonuc);

void soru_0();
void soru_1(int a, int *p);
void soru_2(int a);
void topla(int s1, int s2, int *y);
void soru_4(int *a, int *b);
void soru_5();
void soru_6(float sayi, char *isaret, int *tam, float * ondalik);
void soru_7(int dizi[]);
int soru_8(int *ilk_eleman, int *son_eleman);

#ifndef DEGERLENDIRME
#include <stdio.h>
extern int stdio_helper_fake_printf(const char *format, ...);
#undef printf
#define printf stdio_helper_fake_printf

extern int stdio_helper_fake_scanf(const char *format, ...);
#undef scanf
#define scanf stdio_helper_fake_scanf
#endif /* USE_REAL_STDIO */
