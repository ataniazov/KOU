/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */

int farkli_elemanlari_bul(int A[], int N, int sonuc[]);
int alt_kume_mi(int A[], int A_size, int B[], int B_size);
int kume_kesisimi_bul(int A[], int A_size, int B[], int B_size, int sonuc[]);
int kume_birlesimi_bul(int A[], int A_size, int B[], int B_size, int sonuc[]);
int kume_farki_bul(int A[], int A_size, int B[], int B_size, int sonuc[]);

#ifndef DEGERLENDIRME
#include <stdio.h>
extern int stdio_helper_fake_printf(const char *format, ...);
#undef printf
#define printf stdio_helper_fake_printf

extern int stdio_helper_fake_scanf(const char *format, ...);
#undef scanf
#define scanf stdio_helper_fake_scanf
#endif /* USE_REAL_STDIO */
