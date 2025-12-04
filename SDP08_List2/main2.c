/* File : main2.c */
/* Deskripsi : aplikasi driver ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran*/
/* Tanggal : 16 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.c"

int main(){
    // Kamus
    List2 L, L1, L2, L3;
    infotype V;
    address A;

    // Algoritma

    // Buat list kosong
    CreateList(&L);
    printf("\nList dibuat kosong.\n");
    printf("Apakah list kosong? %s\n", IsEmptyList(L) ? "Ya" : "Tidak");

    // Insert elemen di awal
    InsertVFirst(&L, 'C');
    InsertVFirst(&L, 'B');
    InsertVFirst(&L, 'A');
    printf("\nSetelah InsertVFirst(A) dan InsertVFirst(B):");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // Insert elemen di akhir
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'F');
    printf("\nSetelah InsertVLast(C) dan InsertVLast(D):");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // Delete elemen pertama
    DeleteVFirst(&L, &V);
    printf("\nSetelah DeleteVFirst: elemen '%c' dihapus", V);
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // Delete elemen terakhir
    DeleteVLast(&L, &V);
    printf("\nSetelah DeleteVLast: elemen '%c' dihapus", V);
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // Insert beberapa elemen untuk uji berikutnya
    InsertVLast(&L, 'G');
    InsertVLast(&L, 'H');
    printf("\nSetelah menambah :");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // Delete elemen bernilai X
    DeleteX(&L, 'F');
    DeleteX(&L, 'D');
    printf("\nSetelah DeleteX('F'dan 'D'):");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // Search elemen
    SearchX(L, 'A', &A);
    if (A != NIL) {
        printf("\nElemen 'A' ditemukan di alamat %p\n", A);
    } else {
        printf("\nElemen 'A' tidak ditemukan\n");
    }

    // Update elemen
    UpdateX(&L, 'B', 'Z');
    printf("\nSetelah UpdateX(B->Z):");
    PrintList(L);

    //Inverse
    Invers(&L);
    printf("\nSetelah Invers (dibalik):");
    PrintList(L);

/*********** SOAL TAMBAHAN *****************/
    // Buat list baru 
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'N');
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'U');
    InsertVLast(&L, 'N');
    InsertVLast(&L, 'G');
    printf("\nList untuk test fungsi tambahan:");
    PrintList(L);

    // CountX
    printf("\n\nCountX('N') = %d", CountX(L, 'N'));

    // CountVocal
    printf("\n\nCountVocal() = %d", CountVocal(L));
    printf("\n(Huruf vokal: A, U dalam list)");

    // CountNG
    printf("\n\nCountNG() = %d", CountNG(L));
    printf("\n(Pola 'NG' ditemukan di akhir: 'N' diikuti 'G')");

    // FrekuensiX
    printf("\n\nFrekuensiX('N') = %.2f (%.0f%%)", 
        FrekuensiX(L, 'N'), //untuk nilai
        FrekuensiX(L, 'N') * 100); //untuk persentase

    // Modus
    printf("\n\nModus() = '%c'", Modus(L));
    printf("\n(Karakter yang paling sering muncul adalah '%c')", Modus(L));

    // InsertVAfterX
    InsertVAfterX(&L, 'A', 'X');
    printf("\n\nSetelah InsertVAfterX('A', 'X'):");
    PrintList(L);
    printf("\n('X' diinsert setelah 'A')");

    // InsertVBeforeX
    InsertVBeforeX(&L, 'N', 'Y');
    printf("\n\nSetelah InsertVBeforeX('N', 'Y'):");
    PrintList(L);
    printf("\n('Y' diinsert sebelum 'N' pertama)");

    // DeleteVAfterX
    DeleteVAfterX(&L, 'A', &V);
    printf("\n\nSetelah DeleteVAfterX('A', '%c'):", V);
    PrintList(L);
    printf("\n(Elemen setelah 'A' yaitu '%c' dihapus)", V);

    // DeleteVBeforeX
    DeleteVBeforeX(&L, 'D', &V);
    printf("\n\nSetelah DeleteVBeforeX('D', '%c'):", V);
    PrintList(L);
    printf("\n(Elemen sebelum 'D' yaitu '%c' dihapus)", V);

    // Tambah beberapa 'N' untuk testing DeleteAllX
    InsertVLast(&L, 'N');
    InsertVFirst(&L, 'N');
    printf("\n\nSetelah menambah 'N' di awal dan akhir:");
    PrintList(L);
    printf("\nJumlah 'N': %d", CountX(L, 'N'));

    // DeleteAllX
    DeleteAllX(&L, 'N');
    printf("\n\nSetelah DeleteAllX('N'):");
    PrintList(L);
    printf("\nJumlah 'N': %d (semua 'N' terhapus)", CountX(L, 'N'));

    // Buat list baru
    CreateList(&L);
    InsertVLast(&L, 'M');
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'N');
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'A');
    printf("\nList untuk testing pencarian:");
    PrintList(L);

    // SearchAllX
    SearchAllX(L, 'A');
    printf("(Elemen 'A' ada di posisi 2 dan 5)");
    SearchAllX(L, 'Z');
    printf("(Elemen 'Z' tidak ditemukan)");

    // MaxMember
    printf("\n\nMaxMember() = %d", MaxMember(L));
    printf("\n(Kemunculan terbanyak adalah %d kali)", MaxMember(L));  

    // Modus
    printf("\n\nModus() = '%c'", Modus(L));
    printf("\n(Karakter yang paling sering muncul adalah '%c')", Modus(L)); 

    // ConcatList
    CreateList(&L1);
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'B');
    InsertVLast(&L1, 'C');
    
    CreateList(&L2);
    InsertVLast(&L2, 'X');
    InsertVLast(&L2, 'Y');
    InsertVLast(&L2, 'Z');

    printf("\nList L1:");
    PrintList(L1);
    printf("\nList L2:");
    PrintList(L2);

    ConcatList(L1, L2, &L3);
    printf("\n\nSetelah ConcatList(L1, L2, L3):");
    printf("\nList L3 (hasil concat):");
    PrintList(L3);

    // SplitList
    CreateList(&L);
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'C');
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'E');

    printf("\n\nList L untuk di-split:");
    PrintList(L);
    printf("\nJumlah elemen: %d", NbElm(L));

    SplitList(L, &L1, &L2);
    printf("\n\nSetelah SplitList(L, L1, L2):");
    printf("\nList L1 (bagian 1):");
    PrintList(L1);
    printf("\nJumlah elemen L1: %d", NbElm(L1));
    printf("\nList L2 (bagian 2):");
    PrintList(L2);
    printf("\nJumlah elemen L2: %d", NbElm(L2));

    // CopyList
    CreateList(&L);
    InsertVLast(&L, 'P');
    InsertVLast(&L, 'Q');
    InsertVLast(&L, 'R');

    printf("\n\nList L asli:");
    PrintList(L);

    CopyList(L, &L1);
    printf("\n\nSetelah CopyList(L, L1):");
    printf("\nList L1 (salinan):");
    PrintList(L1);

    return 0;
}


