/**
 * Ata Niyazov      130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Dosya Organizasyonunda Hashing uygulamasi
 */

/**
 * persona.h
 */

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


// This header introduces string types, character traits and a set of converting functions
//#include <string>
// C++ provides the classes to perform output and input of characters to/from files
#include <fstream>
// reverse function
#include <algorithm>

// Here is the C functions that was needed for this project.
// const char *, strlen(), strncpy(), strcmp()
#include <cstring>
//#include <cmath>
#include <ctime>

// temporary file
#define TEMP_FILE       "data/temp.txt"
// random file
#define RANDOM_FILE     "data/random_dosya.txt"
// linear file
#define LINEAR_FILE     "data/lineer_dosya.txt"
// division remainder linear probing
#define DIVREMAIN_LP    "data/bolen_kalan_lineer_yoklama.txt"
// division remainder separate overflow
#define DIVREMAIN_SO    "data/bolen_kalan_ayrik_tasma.txt"
// folding linear probing
#define FOLDING_LP      "data/katlama_lineer_yoklama.txt"
// folding separate overflow
#define FOLDING_SO      "data/katlama_ayrik_tasma.txt"
// middle-square linear probing
#define MIDSQUARE_LP    "data/kare_ortasi_lineer_yoklama.txt"
// middle-square separate overflow
#define MIDSQUARE_SO    "data/kare_ortasi_ayrik_tasma.txt"

// ogrenci kayit sayisi
#define ENTRIES_NUM     500
// uretilecek rasgele ogrenci no. araligi belirme
#define RANGE_MIN       100000000
#define RANGE_MAX       199999999

// uretilecek rasgele ogrenci adi boyutu
#define UID_LEN         9
#define DATA_LEN        10
// bir kayit icin toplam karakter sayisi
#define RECORD_LEN      21
// kayit formati
#define RECORD_FORM     "         \t          "
#define CHARSET         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// bolen-kalan hashing boleni
#define DIVREMAIN_MOD   997

/**
 *  Asal Sayi:          503
 *  Yukleme Faktoru:    0.994
 *
 * ┌─────┬───────┐  ┌─────┬───────┐  ┌─────┬───────┐
 * │ A.S │ Y.FAK │  │ A.S │ Y.FAK │  │ A.S │ Y.FAK │
 * ├─────┼───────┤  ├─────┼───────┤  ├─────┼───────┤
 * │ 617 │ 0.810 │  │ 743 │ 0.000 │  │ 863 │ 0.000 │
 * │ 619 │ 0.808 │  │ 751 │ 0.000 │  │ 877 │ 0.000 │
 * │ 631 │ 0.792 │  │ 757 │ 0.000 │  │ 881 │ 0.000 │
 * │ 641 │ 0.780 │  │ 761 │ 0.000 │  │ 883 │ 0.000 │
 * │ 643 │ 0.778 │  │ 769 │ 0.000 │  │ 887 │ 0.000 │
 * │ 647 │ 0.773 │  │ 773 │ 0.000 │  │ 907 │ 0.000 │
 * │ 653 │ 0.766 │  │ 787 │ 0.000 │  │ 911 │ 0.000 │
 * │ 659 │ 0.759 │  │ 797 │ 0.000 │  │ 919 │ 0.000 │
 * │ 661 │ 0.756 │  │ 809 │ 0.000 │  │ 929 │ 0.000 │
 * │ 673 │ 0.743 │  │ 811 │ 0.000 │  │ 937 │ 0.000 │
 * │ 677 │ 0.739 │  │ 821 │ 0.000 │  │ 941 │ 0.000 │
 * │ 683 │ 0.732 │  │ 823 │ 0.000 │  │ 947 │ 0.000 │
 * │ 691 │ 0.723 │  │ 827 │ 0.000 │  │ 953 │ 0.000 │
 * │ 701 │ 0.713 │  │ 829 │ 0.000 │  │ 967 │ 0.000 │
 * │ 709 │ 0.705 │  │ 839 │ 0.000 │  │ 971 │ 0.000 │
 * │ 719 │ 0.695 │  │ 853 │ 0.000 │  │ 977 │ 0.000 │
 * │ 727 │ 0.688 │  │ 853 │ 0.000 │  │ 983 │ 0.000 │
 * │ 733 │ 0.688 │  │ 857 │ 0.000 │  │ 991 │ 0.000 │
 * │ 739 │ 0.000 │  │ 859 │ 0.000 │  │ 997 │ 0.000 │
 * └─────┴───────┘  └─────┴───────┘  └─────┴───────┘
 */

// bin'lik bolen
#define THOUSAND_MOD    1000
// milyon'luk bolen
#define TENMILLION_DIV  10000000
// bir ve sifir:)
#define ONE             1
#define ZERO            0

// Kayit yapisini belirliyorus
class Record {
public:
    string uid;
    string name;
};

/**
 * Base Class
 */

class Base {
protected:
    // class'a bagli dosya ismini saklar
    const char * filename;
    // islem sayisini saklan degisken
    unsigned int transaction;
public:
    // constractor
    Base(const char *);

    void FileName(void);
    unsigned int Transaction(void);

    int Destroy(const char *);

    Record Parser(string);

    int Composer(unsigned int);
    int Collision(unsigned int);

    int Write(Record, unsigned int);
    string Search(string, unsigned int);
    // destructor
    ~Base();
};

/**
 * Random Dosya Class'i
 */

class Randomizer : public Base {
public:
    Randomizer(const char *);

    Record CreatePersona(void);

    int Append(Record);
    string Search(string);

    ~Randomizer();
};

/**
 * Lineer Dosya Class'i
 */

class Linear : public Base {
public:
    Linear(const char *, const char *);

    ~Linear();
};

/**
 * Bolen-Kalan
 */

class DivRemain : public Base {
public:
    DivRemain(const char *);

    unsigned int HashFunction(string);

    ~DivRemain();
};

/**
 * Bolen-Kalan Lineer Yoklama
 */

class DivRemainLP : public DivRemain {
public:
    DivRemainLP(const char *, const char *);

    ~DivRemainLP();
};

/**
 * Bolen-Kalan Ayrik Tasma
 */

class DivRemainSO : public DivRemain {
private:
    // Ayrik Tasma dosyasinin sonunu gosterir
    unsigned int endpoint;
public:
    DivRemainSO(const char *, const char *);

    ~DivRemainSO();
};

/**
 * Katlama
 */

class Folding : public Base {
public:
    Folding(const char *);

    unsigned int HashFunction(string);

    ~Folding();
};

/**
 * Katlama Lineer Yoklama
 */

class FoldingLP : public Folding {
public:
    FoldingLP(const char *, const char *);

    ~FoldingLP();
};

/**
 * Katlama Ayrik Tasma
 */

class FoldingSO : public Folding {
private:
    // Ayrik Tasma dosyasinin sonunu gosterir
    unsigned int endpoint;
public:
    FoldingSO(const char *, const char *);

    ~FoldingSO();
};

/**
 * Kare-Ortasi
 */

class MidSquare : public Base {
public:
    MidSquare(const char *);

    unsigned int HashFunction(string);

    ~MidSquare();
};

/**
 * Kare-Ortasi Lineer Yoklama
 */

class MidSquareLP : public MidSquare {
public:
    MidSquareLP(const char *, const char *);

    ~MidSquareLP();
};

/**
 * Kare-Ortasi Ayrik Tasma
 */

class MidSquareSO : public MidSquare {
private:
    // Ayrik Tasma dosyasinin sonunu gosterir
    unsigned int endpoint;
public:
    MidSquareSO(const char *, const char *);

    ~MidSquareSO();
};

#endif // PERSONA_H_INCLUDED
