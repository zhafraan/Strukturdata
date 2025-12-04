/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/* Tanggal   : 18 September 2024*/
/***********************************/
#ifndef matriks_C
#define matriks_C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"
#include "boolean.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    int i, j;
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            (*M).cell[i][j] = -999;
        }
    }
    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    return M.nbaris;
}


/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    return (M.nbaris== 0 && M.nkolom == 0);
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    return (M.nbaris == 10 && M.nkolom == 10);
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    if (!isFullMatriks(*M)&&(*M).cell[row][col] == -999) {
       (*M).cell[row][col] = X;
        if (row > getNBaris(*M)) {
            (*M).nbaris = row;
        }
        if (col > getNKolom(*M)) {
            (*M).nkolom = col;
        }
    }
}


/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    int i, j;
    boolean found = false;

    i = 1;
    while (i <= getNBaris(*M) && !found) {
        j = 1;
        while (j <= getNKolom(*M) && !found) {
            if ((*M).cell[i][j] == X) {
                (*M).cell[i][j] = -999;
                found = true;
            }
            j++;
        }
        i++;
    }
    
    if (!found) return; 
    
    i = 1;
    while (i <= getNBaris(*M)) {
        boolean emptyRow = true;
        j = 1;
        while (j <= getNKolom(*M) && emptyRow) {
            if ((*M).cell[i][j] != -999) {
                emptyRow = false;
            }
            j++;
        }
        
        if (emptyRow) {
            int k = i;
            while (k < getNBaris(*M)) {
                j = 1;
                while (j <= getNKolom(*M)) {
                    (*M).cell[k][j] = (*M).cell[k+1][j];
                    j++;
                }
                k++;
            }
            (*M).nbaris--;
        } else {
            i++;
        }
    }
    
    j = 1;
    while (j <= getNKolom(*M)) {
        boolean emptyCol = true; 
        i = 1;
        while (i <= getNBaris(*M) && emptyCol) {
            if ((*M).cell[i][j] != -999) {
                emptyCol = false;
            }
            i++;
        }
        
        if (emptyCol) {
            int l = j;
            while (l < getNKolom(*M)) {
                i = 1;
                while (i <= getNBaris(*M)) {
                    (*M).cell[i][l] = (*M).cell[i][l+1];
                    i++;
                }
                l++;
            }
            (*M).nkolom--;
        } else {
            j++;
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    int i, j;
    srand(time(NULL));
    (*M).nbaris  = x;
    (*M).nkolom = y;
    
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            (*M).cell[i][j] = rand() % 100; 
        }
    }
}


/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    int i, j;
   (*M).nbaris = n;
   (*M).nkolom = n;
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
               (*M).cell[i][j] = 1;
            } else {
               (*M).cell[i][j] = 0;
            }
        }
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
   int i,j ;
   (*M).nbaris = x;
   (*M).nkolom = y;

    printf("Masukkan elemen matriks %dx%d:\n", x, y);
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &(*M).cell[i][j]);
        }
    }
    
}


/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    int i, j;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}


/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks(Matriks M) {
    int i, j;
    
    if(isEmptyMatriks(M)) {
        printf("Matriks kosong\n");
        return;
    }
    
    printf("Matriks %dx%d:\n", M.nbaris, M.nkolom);
    for(i = 1; i <= M.nbaris; i++) {
        for(j = 1; j <= M.nkolom; j++) {
            printf("%4d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    if(getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2) && !isEmptyMatriks(M1) && !isEmptyMatriks(M2)){
        int i,j;
        Matriks add;
        initMatriks(&add);
        add.nbaris = getNBaris(M1);
        add.nkolom = getNKolom(M1);

        for(i = 1;i<=getNBaris(M1);i++){
            for(j=1;j<=getNKolom(M1);j++){
                if(M1.cell[i][j] == -999 && M2.cell[i][j] == -999){
                    add.cell[i][j] = 0;
                }
                else if (M1.cell[i][j] == -999)
                {
                    add.cell[i][j] = M2.cell[i][j];
                }
                else if (M2.cell[i][j] == -999)
                {
                    add.cell[i][j] = M1.cell[i][j];
                }
                else{
                    add.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
                }
                
            }
        }
        return add;

    }
}



/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
       if(getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2) && !isEmptyMatriks(M1) && !isEmptyMatriks(M2)){
        int i,j;
        Matriks sub;
        initMatriks(&sub);
        sub.nbaris = getNBaris(M1);
        sub.nkolom = getNKolom(M1);

        for(i = 1;i<=getNBaris(M1);i++){
            for(j=1;j<=getNKolom(M1);j++){
                if(M1.cell[i][j] == -999 && M2.cell[i][j] == -999){
                    sub.cell[i][j] = 0;
                }
                else if (M1.cell[i][j] == -999)
                {
                    sub.cell[i][j] = M2.cell[i][j];
                }
                else if (M2.cell[i][j] == -999)
                {
                    sub.cell[i][j] = M1.cell[i][j];
                }
                else{
                    sub.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
                }
                
            }
        }
        return sub;
    }
}
/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    Matriks KaliM;
    initMatriks(&KaliM);
    
    if (getNKolom(M1) == getNBaris(M2) && !isEmptyMatriks(M1) && !isEmptyMatriks(M2)) {
        int i, j, k;
        KaliM.nbaris = getNBaris(M1);
        KaliM.nkolom = getNKolom(M2);
        
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M2); j++) {
                KaliM.cell[i][j] = 0;
                
                for (k = 1; k <= getNKolom(M1); k++) {
                    if (M1.cell[i][k] == -999 && M2.cell[k][j] == -999) {
                    }
                    else if (M1.cell[i][k] == -999) {
                    }
                    else if (M2.cell[k][j] == -999) {
                    }
                    else {
                        KaliM.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
                    }
                }
            }
        }
    }
    
    return KaliM;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x){
    Matriks Skalar;
    initMatriks(&Skalar);
    int i, j;
    
    Skalar.nbaris = M1.nbaris;
    Skalar.nkolom = M1.nkolom;
    
    for (i = 1; i <= M1.nbaris; i++) {
        for (j = 1; j <= M1.nkolom; j++) {
            if (M1.cell[i][j] == -999) {
                Skalar.cell[i][j] = 0; 
            } else {
                Skalar.cell[i][j] = M1.cell[i][j] * x;
            }
        }
    }
    
    return Skalar;
}


/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    int temp[11][11];
    int i, j, dimensi;
    
    for(i = 1; i <= (*M).nbaris; i++) {
        for(j = 1; j <= (*M).nkolom; j++) {
            temp[j][i] = (*M).cell[i][j];
        }
    }
    
    dimensi = (*M).nbaris;
    (*M).nbaris = (*M).nkolom;
    (*M).nkolom =  dimensi;
    
    for(i = 1; i <= (*M).nbaris; i++) {
        for(j = 1; j <= (*M).nkolom; j++) {
            (*M).cell[i][j] = temp[i][j];
        }
    }
}


/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
    Matriks TM;
    int i, j;
    
    initMatriks(&TM);
    TM.nbaris = M.nkolom;
    TM.nkolom = M.nbaris;
    
    for(i = 1; i <= TM.nbaris; i++) {
        for(j = 1; j <= TM.nkolom; j++) {
            TM.cell[i][j] = M.cell[j][i];
        }
    }
    
    return TM;
}



/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n){
    Matriks AP;
    int i, j;
    
    initMatriks(&AP);
    AP.nbaris = M.nbaris + 2 * n;
    AP.nkolom = M.nkolom + 2 * n;
    
    for (i = 1; i <= AP.nbaris; i++) {
        for (j = 1; j <= AP.nkolom; j++) {
            AP.cell[i][j] = 0;
        }
    }

    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            if (M.cell[i][j] == -999) {
                AP.cell[i + n][j + n] = 0; 
            } else {
                AP.cell[i + n][j + n] = M.cell[i][j];
            }
        }
    }
    
    return AP;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size){
    Matriks MP;
    int i, j, x, y, max;
    boolean Valid;
    
    initMatriks(&MP);
    MP.nbaris = M.nbaris / size;
    MP.nkolom = M.nkolom / size;
    
    for (i = 1; i <= MP.nbaris; i++) {
        for (j = 1; j <= MP.nkolom; j++) {
            Valid = false;
            
            for (x = (i-1)*size + 1; x <= i*size && !Valid; x++) {
                for (y = (j-1)*size + 1; y <= j*size && !Valid; y++) {
                    if (M.cell[x][y] != -999) {
                        max = M.cell[x][y];
                        Valid = true;
                    }
                }
            }
            
            if (!Valid) {
                max = 0;
            }
            
            for (x = (i-1)*size + 1; x <= i*size; x++) {
                for (y = (j-1)*size + 1; y <= j*size; y++) {
                    if (M.cell[x][y] != -999 && M.cell[x][y] > max) {
                        max = M.cell[x][y];
                    } else if (M.cell[x][y] == -999 && 0 > max) {
                        max = 0;
                    }
                }
            }
            MP.cell[i][j] = max;
        }
    }
    
    return MP;
}


/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size){
    Matriks hasil;
    int i, j, x, y, sum;
    
    initMatriks(&hasil);
    hasil.nbaris = M.nbaris / size;
    hasil.nkolom = M.nkolom / size;
    
    for(i = 1; i <= hasil.nbaris; i++) {
        for(j = 1; j <= hasil.nkolom; j++) {
            sum = 0;
            
            for(x = (i-1)*size + 1; x < i*size + 1; x++) {
                for(y = (j-1)*size + 1; y < j*size + 1; y++) {
                    if (M.cell[x][y] == -999) {
                        sum += 0; 
                    } else {
                        sum += M.cell[x][y];
                    }
                }
            }
            hasil.cell[i][j] = sum / (size * size);
        }
    }
    
    return hasil;
}




/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K) {
    Matriks Conv;
    int i, j, x, y, sum;
    
    initMatriks(&Conv);
    Conv.nbaris = M.nbaris - K.nbaris + 1;
    Conv.nkolom = M.nkolom - K.nkolom + 1;
    
    for(i = 1; i <= Conv.nbaris; i++) {
        for(j = 1; j <= Conv.nkolom; j++) {
            sum = 0;
            
            for(x = 1; x <= K.nbaris; x++) {
                for(y = 1; y <= K.nkolom; y++) {
                    sum += M.cell[i+x-1][j+y-1] * K.cell[x][y];
                }
            }
            Conv.cell[i][j] = sum;
        }
    }
    
    return Conv;
}


/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    int i, j;
    boolean found = false;
    (*row) = -999;
    (*col) = -999;
    
    for(i = 1; i <= M.nbaris && !found; i++) {
        for(j = 1; j <= M.nkolom && !found; j++) {
            if(M.cell[i][j] == X) {
                (*row) = i;
                (*col) = j;
                found = true;
            }
        }
    }
}



/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX(Matriks M, int X) {
    int i, j, count = 0;
    
    for(i = 1; i <= M.nbaris; i++) {
        for(j = 1; j <= M.nkolom; j++) {
            if(M.cell[i][j] == X) {
                count++;
            }
        }
    }
    
    return count;
}
#endif