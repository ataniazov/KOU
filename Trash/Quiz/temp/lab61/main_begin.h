/*
 *	UYARI: SINAVDA BURADAKI KODLARI DEGISTIRMEYIN !!!
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SORU_0_PROTOTYPE() void soru_0()
#define SORU_1_PROTOTYPE() void soru_1()
#define SORU_2_PROTOTYPE() int * soru_2(int N)
#define SORU_3_PROTOTYPE() char * soru_3()
#define SORU_4_PROTOTYPE() char * soru_4()
struct soru5;
#define SORU_5_PROTOTYPE() int soru_5(struct soru5 * ilk)
struct soru6;
#define SORU_6_PROTOTYPE() struct soru6 * soru_6(int sayi1, int sayi2)
struct soru7;
#define SORU_7_PROTOTYPE() struct soru7 * soru_7(const int dizi[], int N)
#define SORU_8_PROTOTYPE() void soru_8()
#define SORU_9_PROTOTYPE() void soru_9()

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

extern int stdio_helper_fake_printf(const char *format, ...);
#undef printf
#define printf stdio_helper_fake_printf

/* extern int scanf (const char *__restrict __format, ...) __wur; */
/* extern int stdio_helper_fake_scanf(const char *format, ...); */
/* #undef scanf */
/* #define scanf stdio_helper_fake_scanf */

extern void *malloc_helper_fake_malloc(size_t size);
#undef malloc
#define malloc malloc_helper_fake_malloc

extern void *malloc_helper_fake_realloc(void * p, size_t size);
#undef realloc
#define realloc malloc_helper_fake_realloc

extern void malloc_helper_fake_free();
#undef free
#define free malloc_helper_fake_free

#endif /* USE_REAL_STDIO */
