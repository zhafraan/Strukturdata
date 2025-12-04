#include <stdio.h>
#include "tabel.h"
#include "tabel.c"

/************************************/
/* Program   : mtabel.c */
/* Deskripsi : aplikasi driver modul tabel */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran */
/* Tanggal   : 12 September 2025*/
/***********************************/

int main() {
    //kamus main
    Tabel T1, T2, T3,T4;
    int pos,count,modus;
    boolean equal;

    /*algoritma*/
    // Create Table
    createTable(&T1);
    printf("T1 kosong? %s\n", isEmptyTable(T1) ? "True" : "False");

    //Getsize
	printf("Size T1: %d\n", getSize(T1));
    printTable(T1);

    //addXtable
    printf("\nBuat tabel baru untuk T1");
    addXTable(&T1, 'A');
    addXTable(&T1, 'B');
    addXTable(&T1, 'C');
    addXTable(&T1, 'A');
    addXTable(&T1, 'I');
    addXTable(&T1, 'U');
    addXTable(&T1, 'O');

    printf("\nSetelah addXTable, isi T1: ");
    viewTable(T1);
    printf("Size T1: %d\n", getSize(T1));
    printf("\n");
    

    // Search x
    printf("\nMencari Elemen X di Tabel");
    searchX(T1, 'I', &pos);
    printf("\nPosisi huruf I = %d", pos);
    searchX(T1, 'A', &pos);
    printf("\nPosisi huruf R = %d", pos);
    searchX(T1, 'U', &pos);
    printf("\nPosisi huruf U = %d", pos);
    printf("\n");

    // Hitung jumlah elemen tertentu
    printf("\nMenghitung Jumlah Elemen Tertentu");
    printf("Jumlah huruf A = %d\n", countX(T1, 'A'));
    printf("Jumlah huruf vokal = %d\n", countVocal(T1));
    printf("\n");

    // addUniqueXTable
    printf("\nMenambahkan Elemen unik di Table");
	addUniqueXTable(&T1, 'D'); 
	addUniqueXTable(&T1, 'T');
    addUniqueXTable(&T1, 'H');
	printf("\nSetelah unique add T,D:\n");
	viewTable(T1);
    printf("\n");

    // Hapus satu elemen
    printf("\nMenghapus sebuah elemen di Tabel");
    printf("\nSebelum delete:\n");
	viewTable(T1);
	delXTable(&T1, 'B');
	printf("Setelah delete B:\n");
	viewTable(T1);
    
	delTable(&T1, 2);
	printf("Setelah delete index 2:\n");
	viewTable(T1);
    printf("\n");

    //Hapus semua element bernaiali X
    printf("\nMenghapus Semua Element X");
    delAllXTable(&T1, 'A');
    printf("Setelah delAllXTable(A), isi T1: ");
    viewTable(T1);
    printf("\n");

    // Isi tabel lain
    printf("\nBuat Tabel baru T2");
    createTable(&T2);
    addXTable(&T2, 'Z');
    addXTable(&T2, 'X');
    addXTable(&T2, 'Y');
    addXTable(&T2, 'X');
    addXTable(&T2, 'X');
    printf("\nIsi T2: ");
    viewTable(T2);
    printf("Size T2: %d\n", getSize(T2));
    printf("\n");


    // Modus
    printf("\nCek modus yang ada di T2");
    printf("\nIsi T2: ");
    viewTable(T2);
    printf("Modus T2 = %c\n", (char)Modus(T2));
    printf("\n");

    // Equal Table
    printf("\nApakah T1 dan T2 sama? %s\n", isEqualTable(T1, T2) ? "Ya" : "Tidak");
    printf("\n");

    // Invers tabel
    printf("\nInverse Tabel T2");
    printf("Isi T2: ");
    viewTable(T2);
    T3 = getInverseTable(T2);
    printf("T2 dibalik (T3): ");
    viewTable(T3);

    inverseTable(&T2);
    printf("\nT2 setelah inverseTable: ");
    viewTable(T2);
    printf("\n");

    // Sortir T2
    printf("\nPengurutan element di dalam Tabel");
    printf("\nIsi T2: ");
    viewTable(T2);
    sortAsc(&T2);
    printf("T2 setelah sortAsc: ");
    viewTable(T2);
    sortDesc(&T2);
    printf("T2 setelah sortDesc: ");
    viewTable(T2);
    printf("\n");

    // Masukaan elemen untuk tabel baru
    createTable(&T4);
    populateTable(&T4, 3);
    printf("Hasil populateTable: ");
    viewTable(T4);
    printf("\n");

    return 0;
}
