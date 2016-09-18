#ifndef SORU_1
void soru_1() { }
#endif

#ifndef SORU_2
void soru_2(int dizi[], int N) {}
#endif

#ifndef SORU_3
int soru_3(int dizi[], int N) {return 0;}
#endif

#ifndef SORU_4
void soru_4(int dizi[], int N) {}
#endif

#ifndef SORU_5
int soru_5(int dizi[], int N) {return 0;}
#endif

#ifndef SORU_6
int soru_6(int dizi[], int N, int aranan) {return 0;}
#endif

#ifndef SORU_7
void soru_7(int dizi[], int N) {}
#endif


extern void test_ogrenci_bilgileri();
extern void sonuc();
extern void sighandler(int signum);

#include <unistd.h>
#include <signal.h>

int main() {

	int i;
	for (i = 1 ; i < 32 ; i++)
		signal(i, sighandler);

	test_ogrenci_bilgileri();
#ifdef SORU_1
	test_1();
#endif
#ifdef SORU_2
	test_2();
#endif
#ifdef SORU_3
	test_3();
#endif
#ifdef SORU_4
	test_4();
#endif
#ifdef SORU_5
	test_5();
#endif
#ifdef SORU_6
	test_6();
#endif
#ifdef SORU_7
	test_7();
#endif

	sonuc();

	return 0;
}
