/**
 * Matris islemleri fonksiyonlari
 */

#include "headfirst.h"

/**
 * txt dosyasindaki matrisi
 * dizi matrisine atan fonksiyon
 */

void file2mtrx(char * filename, int mtrx_size, int mat[mtrx_size][mtrx_size])
{
    //printf("Matrix size is %d\n",mtrx_size);
    FILE * pMtrx_txt;

    // Dosyayi okuma modunda ac
    if ((pMtrx_txt = fopen(filename, "r")) == NULL)
    {
        printf("%s dosyasi acilamadi!\n",filename);
        exit(EXIT_FAILURE);
    }

    int i,j;
    for(i = 0; i < mtrx_size; i++)
    {
        for(j = 0; j < mtrx_size; j++)
        {
            if (!fscanf(pMtrx_txt, "%d", &mat[i][j]))
            {
                break;
            }
            // mat[i][j] -= '0';
            //printf("%d ",mat[i][j]);
        }
        //printf("\n");
    }

    fclose(pMtrx_txt);
}

/**
 * dizi matrisini txt dosyasina yazan fonksiyon
 */

void mtrx2file(char * filename, int mtrx_size, int mat[mtrx_size][mtrx_size])
{
    FILE * pMtrx_txt;

    // Dosyayi yazma modunda ac
    if ((pMtrx_txt = fopen(filename, "a")) == NULL)
    {
        printf("%s dosyasi acilamadi!\n",filename);
        exit(EXIT_FAILURE);
    }

    int i,j;

    for(i = 0; i < mtrx_size; i++)
    {
        for(j = 0; j < mtrx_size; j++)
        {
            fprintf(pMtrx_txt,"%d",mat[i][j]);
            if(j < mtrx_size - 1)
            {
                fprintf(pMtrx_txt," ");
            }
        }
        fprintf(pMtrx_txt,"\n");
    }
    fprintf(pMtrx_txt,"\n");
    fclose(pMtrx_txt);
}

/**
 * Dosya icherigini silen fonksiyon
 */

void clr_file(char * filename)
{
    FILE * fp;

    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("%s dosyasinin icerigi silinemedi!\n",filename);
        exit(EXIT_FAILURE);
    }
    fclose(fp);
}

/**
 * Parametre olarak verilen dosyaya mesaj yazar
 */

void wrt2file(char * filename, char * msg)
{
    FILE * fp;

    // Dosyayi okuma modunda ac
    if ((fp = fopen(filename, "a")) == NULL)
    {
        printf("%s dosyasi acilamadi!\n",filename);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, msg);

    fclose(fp);
}

/**
 * Matris elemanlarini baska matrise kopyalama fonksiyonu
 */

void cpy_mtrx(int mtrx_size, int src[mtrx_size][mtrx_size], int dst[mtrx_size][mtrx_size])
{
    int i,j;
    for(i = 0; i < mtrx_size; i++)
    {
        for(j = 0; j < mtrx_size; j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

/**
 * Iki matrisin esitligini kontrol ediyor
 */

bool is_mtrx_equal(int mtrx_size, int mtrx1[mtrx_size][mtrx_size], int mtrx2[mtrx_size][mtrx_size])
{
    int i,j;
    for(i = 0; i < mtrx_size; i++)
    {
        for(j = 0; j < mtrx_size; j++)
        {
            if(mtrx1[i][j] != mtrx2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * matris.txt dosyasindaki matrisin boyut kontrolunu yapan
 * ve geri boyutunu gonderen fonksiyon
 */

int get_file_mtrx_size(char * filename)
{
    FILE * pMtrx_txt;

    // Dosyayi okuma modunda ac
    if ((pMtrx_txt = fopen(filename, "r")) == NULL)
    {
        printf("%s dosyasi acilamadi!\n",filename);
        exit(EXIT_FAILURE);
    }

    int row = 0;
    int column = 0;
    int status = 0;
    char ch = EOF;

    int counted = 0;
    int counter = 0;

    while(!feof(pMtrx_txt))
    {
        ch = fgetc(pMtrx_txt);
        if(!isdigit(ch) && !isspace(ch) && !(ch == '\n') && !(ch == EOF))
        {
            return 0;
        }
        else
        {
            if(isdigit(ch))
            {
                if(counter == 0 || status == 0)
                {
                    counter++;
                    status = 1;
                }
            }
            if(isspace(ch))
            {
                status = 0;
            }
            if(ch == '\n' || ch == EOF)
            {
                if(counter != 0)
                {
                    row++;
                    if(counted == 0)
                    {
                        counted = counter;
                    }
                    else if (counted == counter)
                    {
                        column = counted;
                    }
                    else if (counted != counter)
                    {
                        return 0;
                    }
                }
                counter = 0;
            }
        }
    }

    fclose(pMtrx_txt);

    if(row == column && row >= 2)
    {
        return row;
    }

    printf("ROW: %d, COLUMN: %d", row, column);
    return 0;
}

/**
 * Determinant hesabi yapan fonksiyon
 * http://blog.amila.co/determinant-of-a-square-matrix-c/
 * sitesinden alinmishtir
 */

int determinant(int mtrx_size, int mat[mtrx_size][mtrx_size])
{
    int i, j, i_count, j_count, count=0;
    int array[mtrx_size-1][mtrx_size-1], det = 0;

    if(mtrx_size < 1)
    {
        printf("Determinant hesabi hata verdi!\n");
        exit(EXIT_FAILURE);
    }
    if(mtrx_size == 1)
    {
        return mat[0][0];
    }
    if(mtrx_size == 2)
    {
        return (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
    }
    for(count = 0; count < mtrx_size; count++)
    {
        i_count = 0;

        for(i = 1; i < mtrx_size; i++)
        {
            j_count = 0;

            for(j = 0; j < mtrx_size; j++)
            {
                if(j == count)
                {
                    continue;
                }
                array[i_count][j_count] = mat[i][j];
                j_count++;
            }
            i_count++;
        }
        det += pow(-1, count) * mat[0][count] * determinant(mtrx_size-1,array);
    }
    return det;
}

/**
 * Hadamard
 */

bool hadamard(int mtrx_size,int mat[mtrx_size][mtrx_size])
{
    if(mtrx_size == 2 || mtrx_size == 4 || mtrx_size == 8 || mtrx_size == 16)
    {
        int had[mtrx_size][mtrx_size];
        // Hadamard matris uretme islemleri
        if(mtrx_size == 2 )
        {
            int ptrn[2][2] =
            {
                { mat[0][0], mat[0][1]},
                { mat[0][1], mat[0][0]}
            };
            cpy_mtrx(mtrx_size, ptrn, had);
        }
        else if(mtrx_size == 4)
        {
            int ptrn[4][4] =
            {
                { mat[0][0], mat[0][1], mat[0][2], mat[0][3]},
                { mat[0][1], mat[0][0], mat[0][3], mat[0][2]},
                { mat[0][2], mat[0][3], mat[0][0], mat[0][1]},
                { mat[0][3], mat[0][2], mat[0][1], mat[0][0]}

            };
            cpy_mtrx(mtrx_size, ptrn, had);
        }
        else if(mtrx_size == 8)
        {
            int ptrn[8][8] =
            {
                { mat[0][0], mat[0][1], mat[0][2], mat[0][3], mat[0][4], mat[0][5], mat[0][6], mat[0][7]},
                { mat[0][1], mat[0][0], mat[0][3], mat[0][2], mat[0][5], mat[0][4], mat[0][7], mat[0][6]},
                { mat[0][2], mat[0][3], mat[0][0], mat[0][1], mat[0][6], mat[0][7], mat[0][4], mat[0][5]},
                { mat[0][3], mat[0][2], mat[0][1], mat[0][0], mat[0][7], mat[0][6], mat[0][5], mat[0][4]},
                { mat[0][4], mat[0][5], mat[0][6], mat[0][7], mat[0][0], mat[0][1], mat[0][2], mat[0][3]},
                { mat[0][5], mat[0][4], mat[0][7], mat[0][6], mat[0][1], mat[0][0], mat[0][3], mat[0][2]},
                { mat[0][6], mat[0][7], mat[0][4], mat[0][5], mat[0][2], mat[0][3], mat[0][0], mat[0][1]},
                { mat[0][7], mat[0][6], mat[0][5], mat[0][4], mat[0][3], mat[0][2], mat[0][1], mat[0][0]}
            };
            cpy_mtrx(mtrx_size, ptrn, had);
        }
        else if(mtrx_size == 16)
        {
            int ptrn[16][16] =
            {
                { mat[0][0], mat[0][1], mat[0][2], mat[0][3], mat[0][4], mat[0][5], mat[0][6], mat[0][7], mat[0][8], mat[0][9], mat[0][10], mat[0][11], mat[0][12], mat[0][13], mat[0][14], mat[0][15]},
                { mat[0][1], mat[0][0], mat[0][3], mat[0][2], mat[0][5], mat[0][4], mat[0][7], mat[0][6], mat[0][9], mat[0][8], mat[0][11], mat[0][10], mat[0][13], mat[0][12], mat[0][15], mat[0][14]},
                { mat[0][2], mat[0][3], mat[0][0], mat[0][1], mat[0][6], mat[0][7], mat[0][4], mat[0][5], mat[0][10], mat[0][11], mat[0][8], mat[0][9], mat[0][14], mat[0][15], mat[0][12], mat[0][13]},
                { mat[0][3], mat[0][2], mat[0][1], mat[0][0], mat[0][7], mat[0][6], mat[0][5], mat[0][4], mat[0][11], mat[0][10], mat[0][9], mat[0][8], mat[0][15], mat[0][14], mat[0][13], mat[0][12]},
                { mat[0][4], mat[0][5], mat[0][6], mat[0][7], mat[0][0], mat[0][1], mat[0][2], mat[0][3], mat[0][12], mat[0][13], mat[0][14], mat[0][15], mat[0][8], mat[0][9], mat[0][10], mat[0][11]},
                { mat[0][5], mat[0][4], mat[0][7], mat[0][6], mat[0][1], mat[0][0], mat[0][3], mat[0][2], mat[0][13], mat[0][12], mat[0][15], mat[0][14], mat[0][9], mat[0][8], mat[0][11], mat[0][10]},
                { mat[0][6], mat[0][7], mat[0][4], mat[0][5], mat[0][2], mat[0][3], mat[0][0], mat[0][1], mat[0][14], mat[0][15], mat[0][12], mat[0][13], mat[0][10], mat[0][11], mat[0][8], mat[0][9]},
                { mat[0][7], mat[0][6], mat[0][5], mat[0][4], mat[0][3], mat[0][2], mat[0][1], mat[0][0], mat[0][15], mat[0][14], mat[0][13], mat[0][12], mat[0][11], mat[0][10], mat[0][9], mat[0][8]},
                { mat[0][8], mat[0][9], mat[0][10], mat[0][11], mat[0][12], mat[0][13], mat[0][14], mat[0][15], mat[0][0], mat[0][1], mat[0][2], mat[0][3], mat[0][4], mat[0][5], mat[0][6], mat[0][7]},
                { mat[0][9], mat[0][8], mat[0][11], mat[0][10], mat[0][13], mat[0][12], mat[0][15], mat[0][14], mat[0][1], mat[0][0], mat[0][3], mat[0][2], mat[0][5], mat[0][4], mat[0][7], mat[0][6]},
                { mat[0][10], mat[0][11], mat[0][8], mat[0][9], mat[0][14], mat[0][15], mat[0][12], mat[0][13], mat[0][2], mat[0][3], mat[0][0], mat[0][1], mat[0][6], mat[0][7], mat[0][4], mat[0][5]},
                { mat[0][11], mat[0][10], mat[0][9], mat[0][8], mat[0][15], mat[0][14], mat[0][13], mat[0][12], mat[0][3], mat[0][2], mat[0][1], mat[0][0], mat[0][7], mat[0][6], mat[0][5], mat[0][4]},
                { mat[0][12], mat[0][13], mat[0][14], mat[0][15], mat[0][8], mat[0][9], mat[0][10], mat[0][11], mat[0][4], mat[0][5], mat[0][6], mat[0][7], mat[0][0], mat[0][1], mat[0][2], mat[0][3]},
                { mat[0][13], mat[0][12], mat[0][15], mat[0][14], mat[0][9], mat[0][8], mat[0][11], mat[0][10], mat[0][5], mat[0][4], mat[0][7], mat[0][6], mat[0][1], mat[0][0], mat[0][3], mat[0][2]},
                { mat[0][14], mat[0][15], mat[0][12], mat[0][13], mat[0][10], mat[0][11], mat[0][8], mat[0][9], mat[0][6], mat[0][7], mat[0][4], mat[0][5], mat[0][2], mat[0][3], mat[0][0], mat[0][1]},
                { mat[0][15], mat[0][14], mat[0][13], mat[0][12], mat[0][11], mat[0][10], mat[0][9], mat[0][8], mat[0][7], mat[0][6], mat[0][5], mat[0][4], mat[0][3], mat[0][2], mat[0][1], mat[0][0]}
            };
            cpy_mtrx(mtrx_size, ptrn, had);
        }
        /*
        int i,j;
        for(i = 0; i < mtrx_size; i++)
        {
            for(j = 0; j < mtrx_size; j++)
            {
                printf("%3d ",had[i][j]);
            }
            printf("\n");
        }
        */
        if(is_mtrx_equal(mtrx_size, mat, had))
        {
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}

/**
 * MDS
 */

bool mds(int mtrx_size, int mtrx[mtrx_size][mtrx_size])
{
    int i, j, ioff, joff, off_cnt;
    int sub_mtrx_size;

    for(sub_mtrx_size = 2; sub_mtrx_size <= mtrx_size; sub_mtrx_size++)
    {
        int tmp_mtrx[sub_mtrx_size][sub_mtrx_size];
        // off_cnt (offset count) aralik (buyukluk)
        off_cnt = mtrx_size - sub_mtrx_size + 1;
        for (ioff = 0; ioff < off_cnt; ioff++)
        {
            for (joff = 0; joff < off_cnt; joff++)
            {
                for (i = 0; i < sub_mtrx_size; i++)
                {
                    for (j = 0; j < sub_mtrx_size; j++)
                    {
                        tmp_mtrx[i][j] = mtrx[i+ioff][j+joff];
                    }
                }
                if(determinant(sub_mtrx_size,tmp_mtrx) == 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

/**
 * Simetrik
 */

bool simetrik(int mtrx_size, int mat[mtrx_size][mtrx_size])
{
    int transpose[mtrx_size][mtrx_size];
    int i,j;

    // Matris transpozu alma islemi
    for( i = 0 ; i < mtrx_size ; i++ )
    {
        for( j = 0 ; j < mtrx_size ; j++ )
        {
            transpose[j][i] = mat[i][j];
        }
    }

    for ( i = 0 ; i < mtrx_size ; i++ )
    {
        for ( j = 0 ; j < mtrx_size ; j++ )
        {
            if ( mat[i][j] != transpose[i][j] )
            {
                break;
            }
        }
        if ( j != mtrx_size )
        {
            break;
        }
    }
    if ( i == mtrx_size )
    {
        return true;
    }
    return false;
}

/**
 * Dairesel
 */

bool dairesel(int mtrx_size,int mtrx[mtrx_size][mtrx_size])
{
    int i,j;
    for(i = 1; i < mtrx_size; i++)
    {
        for(j = 0; j < mtrx_size; j++)
        {
            if(mtrx[i][((j+i)%mtrx_size)] != mtrx[0][j])
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * "Hadamard" secildiginde calishacak tetikleyci
 */

void get_hadamard(char * filename)
{
    clr_file(HADAMARD);

    int mtrx_size = get_file_mtrx_size(filename);

    if(mtrx_size == 4 || mtrx_size == 8 || mtrx_size == 16)
    {
        int mat[mtrx_size][mtrx_size];
        file2mtrx(filename,mtrx_size,mat);

        if(hadamard(mtrx_size, mat))
        {
            wrt2file(HADAMARD, "Girilen matris hadamard matristir\n\n");
            printf("\nGirilen matris hadamard matristir\n");
        }
        else
        {
            wrt2file(HADAMARD, "Girilen matris hadamard degildir\n\n");
            printf("\nGirilen matris hadamard degildir\n");
        }

        int i, j, ioff, joff, off_cnt;
        int sub_mtrx_size;
        // tersten yapmak icin for(sub_mtrx_size = 2; sub_mtrx_size > mtrx_size ; sub_mtrx_size++) kullan
        for(sub_mtrx_size = mtrx_size; sub_mtrx_size > 1 ; sub_mtrx_size--)
        {
            int tmp_mtrx[sub_mtrx_size][sub_mtrx_size];
            // off_cnt (offset count) aralik (buyukluk)
            off_cnt = mtrx_size - sub_mtrx_size + 1;
            for (ioff = 0; ioff < off_cnt; ioff++)
            {
                for (joff = 0; joff < off_cnt; joff++)
                {
                    for (i = 0; i < sub_mtrx_size; i++)
                    {
                        for (j = 0; j < sub_mtrx_size; j++)
                        {
                            tmp_mtrx[i][j] = mat[i+ioff][j+joff];
                        }
                    }
                    if(hadamard(sub_mtrx_size, tmp_mtrx))
                    {
                        mtrx2file(HADAMARD, sub_mtrx_size, tmp_mtrx);
                    }
                    /*
                    for(i = 0; i < sub_mtrx_size; i++)
                    {
                        for(j = 0; j < sub_mtrx_size; j++)
                        {
                            printf("%3d",tmp_mtrx[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    */
                }
            }
        }
    }
    else
    {
        printf("get_hadamart(): Hatali matris formati\n");
    }
}

/**
 * "MDS" secildiginde calishacak tetikleyci
 */

void get_mds(char * filename)
{
    clr_file(MDS);

    int mtrx_size = get_file_mtrx_size(filename);

    if(mtrx_size >= 4 && mtrx_size <= 16)
    {
        int mat[mtrx_size][mtrx_size];
        file2mtrx(filename,mtrx_size,mat);

        if(mds(mtrx_size, mat))
        {
            wrt2file(MDS, "Girilen matris MDS matristir\n\n");
            printf("\nGirilen matris MDS matristir\n");
        }
        else
        {
            wrt2file(MDS, "Girilen matris MDS degildir\n\n");
            printf("\nGirilen matris MDS degildir\n");
        }

        int i, j, ioff, joff, off_cnt;
        int sub_mtrx_size;
        // tersten yapmak icin for(sub_mtrx_size = 2; sub_mtrx_size > mtrx_size ; sub_mtrx_size++) kullan
        for(sub_mtrx_size = mtrx_size; sub_mtrx_size > 1 ; sub_mtrx_size--)
        {
            int tmp_mtrx[sub_mtrx_size][sub_mtrx_size];
            // off_cnt (offset count) aralik (buyukluk)
            off_cnt = mtrx_size - sub_mtrx_size + 1;
            for (ioff = 0; ioff < off_cnt; ioff++)
            {
                for (joff = 0; joff < off_cnt; joff++)
                {
                    for (i = 0; i < sub_mtrx_size; i++)
                    {
                        for (j = 0; j < sub_mtrx_size; j++)
                        {
                            tmp_mtrx[i][j] = mat[i+ioff][j+joff];
                        }
                    }
                    if(mds(sub_mtrx_size, tmp_mtrx))
                    {
                        mtrx2file(MDS, sub_mtrx_size, tmp_mtrx);
                    }
                    /*
                    for(i = 0; i < sub_mtrx_size; i++)
                    {
                        for(j = 0; j < sub_mtrx_size; j++)
                        {
                            printf("%3d",tmp_mtrx[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    */
                }
            }
        }

    }
    else
    {
        printf("get_mds(): Hatali matris formati\n");
    }
}

/**
 * "Simetrik" secildiginde calishacak tetikleyci
 */

void get_simetrik(char * filename)
{
    clr_file(SIMETRIK);

    int mtrx_size = get_file_mtrx_size(filename);

    if(mtrx_size >= 4 && mtrx_size <= 16)
    {
        int mat[mtrx_size][mtrx_size];
        file2mtrx(filename,mtrx_size,mat);

        if(simetrik(mtrx_size, mat))
        {
            wrt2file(SIMETRIK, "Girilen matris simetrik matristir\n\n");
            printf("\nGirilen matris simetrik matristir\n");
        }
        else
        {
            wrt2file(SIMETRIK, "Girilen matris simetrik degildir\n\n");
            printf("\nGirilen matris simetrik degildir\n");
        }

        int i, j, ioff, joff, off_cnt;
        int sub_mtrx_size;
        // tersten yapmak icin for(sub_mtrx_size = 2; sub_mtrx_size > mtrx_size ; sub_mtrx_size++) kullan
        for(sub_mtrx_size = mtrx_size; sub_mtrx_size > 1 ; sub_mtrx_size--)
        {
            int tmp_mtrx[sub_mtrx_size][sub_mtrx_size];
            // off_cnt (offset count) aralik (buyukluk)
            off_cnt = mtrx_size - sub_mtrx_size + 1;
            for (ioff = 0; ioff < off_cnt; ioff++)
            {
                for (joff = 0; joff < off_cnt; joff++)
                {
                    for (i = 0; i < sub_mtrx_size; i++)
                    {
                        for (j = 0; j < sub_mtrx_size; j++)
                        {
                            tmp_mtrx[i][j] = mat[i+ioff][j+joff];
                        }
                    }
                    if(simetrik(sub_mtrx_size, tmp_mtrx))
                    {
                        mtrx2file(SIMETRIK, sub_mtrx_size, tmp_mtrx);
                    }
                    /*
                    for(i = 0; i < sub_mtrx_size; i++)
                    {
                        for(j = 0; j < sub_mtrx_size; j++)
                        {
                            printf("%3d",tmp_mtrx[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    */
                }
            }
        }
    }
    else
    {
        printf("get_simetrik(): Hatali matris formati\n");
    }
}

/**
 * "Dairesel" secildiginde calishacak tetikleyci
 */

void get_dairesel(char * filename)
{
    clr_file(DAIRESEL);

    int mtrx_size = get_file_mtrx_size(filename);

    if(mtrx_size >= 4 && mtrx_size <= 16)
    {
        int mat[mtrx_size][mtrx_size];
        file2mtrx(filename,mtrx_size,mat);

        if(dairesel(mtrx_size, mat))
        {
            wrt2file(DAIRESEL, "Girilen matris dairesel matristir\n\n");
            printf("\nGirilen matris dairesel matristir\n");
        }
        else
        {
            wrt2file(DAIRESEL, "Girilen matris dairesel degildir\n\n");
            printf("\nGirilen matris dairesel degildir\n");
        }

        int i, j, ioff, joff, off_cnt;
        int sub_mtrx_size;
        // tersten yapmak icin for(sub_mtrx_size = 2; sub_mtrx_size > mtrx_size ; sub_mtrx_size++) kullan
        for(sub_mtrx_size = mtrx_size; sub_mtrx_size > 1 ; sub_mtrx_size--)
        {
            int tmp_mtrx[sub_mtrx_size][sub_mtrx_size];
            // off_cnt (offset count) aralik (buyukluk)
            off_cnt = mtrx_size - sub_mtrx_size + 1;
            for (ioff = 0; ioff < off_cnt; ioff++)
            {
                for (joff = 0; joff < off_cnt; joff++)
                {
                    for (i = 0; i < sub_mtrx_size; i++)
                    {
                        for (j = 0; j < sub_mtrx_size; j++)
                        {
                            tmp_mtrx[i][j] = mat[i+ioff][j+joff];
                        }
                    }
                    if(dairesel(sub_mtrx_size, tmp_mtrx))
                    {
                        mtrx2file(DAIRESEL, sub_mtrx_size, tmp_mtrx);
                    }
                    /*
                    for(i = 0; i < sub_mtrx_size; i++)
                    {
                        for(j = 0; j < sub_mtrx_size; j++)
                        {
                            printf("%3d",tmp_mtrx[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    */
                }
            }
        }
    }
    else
    {
        printf("get_dairesel(): Hatali matris formati\n");
    }
}
