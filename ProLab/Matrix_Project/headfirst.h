#ifndef HEADFIRST_H_INCLUDED
#define HEADFIRST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
// bool veri tipleri ekliyorus
#include <stdbool.h>

// Matris dosyalarini tanimlama
#define MATRIS          "matris.txt"
#define HADAMARD        "hadamard.txt"
#define MDS             "mds.txt"
#define SIMETRIK        "simetrik.txt"
#define DAIRESEL        "dairesel.txt"

// Gecici matris dosyasi tanimlama
#define TMP             "tmp.txt"


/**
 * Fonksiyonlarin prototipleri
 */
int get_mtrx_size();
void get_mtrx_elem(int mtrx_size);
char * deblank(char * inpt_str);
char * trim_wht_sp(char *str);
int count_elem(const char *str);


// matris fonksiyonlari
void file2mtrx(char * filename, int mtrx_size, int mat[mtrx_size][mtrx_size]);
void mtrx2file(char * filename, int mtrx_size, int mat[mtrx_size][mtrx_size]);
void clr_file(char * filename);
void wrt2file(char * filename, char * msg);
void cpy_mtrx(int mtrx_size, int src[mtrx_size][mtrx_size], int dst[mtrx_size][mtrx_size]);
bool is_mtrx_equal(int mtrx_size, int mtrx1[mtrx_size][mtrx_size], int mtrx2[mtrx_size][mtrx_size]);

int get_file_mtrx_size(char * filename);

/**
 * Determinant hesabini yapan fonksiyon
 * http://blog.amila.co/determinant-of-a-square-matrix-c/
 * sitesinden alinmishtir
 */
int determinant(int mtrx_size, int mat[mtrx_size][mtrx_size]);

// Prolab 1 fonksiyonlari
bool hadamard(int mtrx_size, int mat[mtrx_size][mtrx_size]);
bool mds(int mtrx_size, int mtrx[mtrx_size][mtrx_size]);
bool simetrik(int mtrx_size, int mat[mtrx_size][mtrx_size]);
bool dairesel(int mtrx_size, int mat[mtrx_size][mtrx_size]);

// Tetikleciler
void get_hadamard(char * filename);
void get_mds(char * filename);
void get_simetrik(char * filename);
void get_dairesel(char * filename);

#endif // HEADFIRST_H_INCLUDED
