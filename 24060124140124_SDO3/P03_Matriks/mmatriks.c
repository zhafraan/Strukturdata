/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/* Tanggal   : 20 September 2024*/
/***********************************/


#include <stdio.h>
#include "matriks.h"
#include "matriks.c"

int main() {
	/*kamus*/
	Matriks M1,M2,M3,M4,K;
    int row,col;

	/*algoritma*/
    printf("\nTEST KONSTRUKTOR & SELEKTOR\n");
    //initMatriks
    printf("initMatriks\n");
    initMatriks(&M1);
    addX(&M1, 10, 1, 1);
    addX(&M1, 9, 1, 2);
    addX(&M1, 8, 1, 3);
    addX(&M1, 7, 2, 1);
    addX(&M1, 6, 2, 2);
    addX(&M1, 5, 2, 3);
    addX(&M1, 4, 3, 1);
    addX(&M1, 3, 3, 2);
    addX(&M1, 2, 3, 3);
    viewMatriks(M1);
    printf("\n");
    //GetNBaris & GetNKolom
    printf("GetNBaris & GetNKolom\n");
    printf("Nbaris: %d\n", getNBaris(M1));
    printf("Nkolom: %d\n", getNKolom(M1));
    //IsEmptyMatriks & IsFullMatriks
    printf("IsEmptyMatriks & IsFullMatriks\n");
    printf("IsEmpty: %s\n", isEmptyMatriks(M1) ? "TRUE" : "FALSE");
    printf("IsFull: %s\n", isFullMatriks(M1) ? "TRUE" : "FALSE");
    printf("\n");

    printf("\nTEST MUTATOR\n");
    //addX
    printf("addX\n");
    addX(&M1, 19, 1, 4);
    addX(&M1, 1,  2, 4);
    addX(&M1, 15, 3, 4);
    addX(&M1, 17, 4, 1);
    addX(&M1, 26,  4, 2);
    addX(&M1, 31, 4, 3);
    viewMatriks(M1);
    printf("Nbaris: %d\n", getNBaris(M1));
    printf("Nkolom: %d\n", getNKolom(M1));
    printf("\n");
    //delX
    printf("delX\n");
    delX(&M1, 3);
    delX(&M1, 10);
    printf("Hasil setelah delX:\n");
    viewMatriks(M1);
    printf("\n");
    //isiMatriksRandom
    printf("isiMatriksRandom\n");
    initMatriks(&M2);
    isiMatriksRandom(&M2, 4, 4);
    viewMatriks(M2);
    printf("\n");
    //isiMatriksIndentitas
    printf("isiMatriksIdentitas\n");
    initMatriks(&M3);
    isiMatriksIdentitas(&M3,5);
    viewMatriks(M3);
    printf("\n");

    printf("\nTEST OPERASI BACA/TULIS\n");
    //populateMatriks
    printf("populateMatriks\n");
    initMatriks(&M4);
    populateMatriks(&M4, 2, 2);
    printf("Hasil input manual:\n");
    //viewMatriks
    printf("viewMatriks\n");
    viewMatriks(M4);
    printf("\n");
    //printMatriks
    printf("printMatriks\n");
    printMatriks(M1);
    printf("\n");

    printf("\nOPERASI ARITMATIKA\n");
    viewMatriks(M1);
    viewMatriks(M2);
    //addMatriks
    printf("addMatriks\n");
    M3 = addMatriks(M1, M2);
    printf("HasiladdMatriks:\n");
    viewMatriks(M3);
    printf("\n");
    //subMatriks
    printf("subMatriks\n");
    M3 = subMatriks(M1, M2);
    printf("Hasil subMatriks:\n");
    viewMatriks(M3);
    printf("\n");
    //kaliMatriks
    printf("kaliMatriks\n");
    M3 = kaliMatriks(M1, M2);
    printf("Hasil kaliMatriks:\n");
    viewMatriks(M3);
    printf("\n");
    //kaliSkalar
    printf("kaliSkalar\n");
    viewMatriks(M1);
    M3 = kaliSkalarMatriks(M1, 2);
    printf("Hasil kaliSkalar:\n");
    viewMatriks(M3);
    printf("\n");

    printf("\nTEST OPERASI LAINNYA\n");
    //transposeMatriks
    printf("transposeMatriks\n");
    printf("Before transposeMatriks\n");
    viewMatriks(M1);
    printf("After transposeMatriks\n");
    transposeMatriks(&M1);
    viewMatriks(M1);
    printf("\n");
    //gettransposeMatriks
    printf("gettransposeMatriks\n");
    printf("Before gettransposeMatriks\n");
    viewMatriks(M1);
    printf("After gettransposeMatriks\n");
    M4 = getTransposeMatriks(M1);
    viewMatriks(M4);
    printf("\n");
    //addPaddding
    printf("addPadddingMatriks\n");
    M4 = addPadding(M2, 1);
    viewMatriks(M4);
    printf("\n");
    //maxPolling
    printf("maxPollingMatriks\n");
    M4 = maxPooling(M2, 2);
    viewMatriks(M4);
    printf("\n");
    //avgPolling
    printf("avgPooling\n");
    M4 = avgPooling(M2, 2);
    viewMatriks(M4);
    printf("\n");
    //Conv
    printf("convMatriks\n");
    initMatriks(&K);
    isiMatriksIdentitas(&K, 2);
    M4 = conv(M2, K);
    viewMatriks(M4);
    printf("\n");

    printf("\nTEST OPERASI PENCARIAN\n");
    //searchX
    printf("searchX\n");
    viewMatriks(M2);
    searchX(M2, M2.cell[2][1], &row, &col);
    if (row != -999 && col != -999) {
        printf("Elemen %d ditemukan di posisi (%d, %d)\n", M2.cell[2][1], row, col);
    } else {
        printf("Elemen tidak ditemukan\n");
    }
    printf("\n");
    //countX
    printf("countX\n");
    int count = countX(M2, M2.cell[2][1]);
    printf("Elemen %d muncul sebanyak %d kali\n", M2.cell[2][1], count);
    printf("\n");
    
	return 0;
}
