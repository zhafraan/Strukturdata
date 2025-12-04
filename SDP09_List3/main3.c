/* File : main3.c */
/* Deskripsi : aplikasi driver ADT list list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran */
/* Tanggal : 23 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.c"

int main() {
    List3 L,L1,L2,L3,L4;
    infotype V;
    address A;
    
    // Create list & isempty
    CreateList(&L);
    printf("List L dibuat kosong.\n");
    printf("Apakah list kosong? %s\n", IsEmptyList(L) ? "Ya" : "Tidak");
    printf("\n");

    // InsertVFirst
    InsertVFirst(&L, 'E');
    InsertVFirst(&L, 'D');
    InsertVFirst(&L, 'C');
    InsertVFirst(&L, 'B');
    InsertVFirst(&L, 'A');
    printf("Setelah InsertVFirst,isi L: \n");
    // PrintList
    PrintList(L);
    // NbElement
    printf("jumlah elemen = %d\n", NbElm(L));
    printf("\n");

    // InsertVLast
    InsertVLast(&L, 'F');
    InsertVLast(&L, 'G');
    InsertVLast(&L, 'H');
    printf("Setelah InsertVLast,isi L: \n");
    PrintList(L);
    printf("jumlah elemen = %d\n", NbElm(L));
    printf("\n");

    // DeleteVFirst
    DeleteVFirst(&L, &V);
    printf("Elemen yang dihapus: %c\n", V);
    printf("List setelah DeleteVFirst: \n");
    PrintList(L);
    printf("jumlah elemen = %d\n", NbElm(L));
    printf("\n");

    // DeleteVLast
    DeleteVLast(&L, &V);
    printf("Elemen yang dihapus: %c\n", V);
    printf("List setelah DeleteVLast: \n");
    PrintList(L);
    printf("jumlah elemen = %d\n", NbElm(L));
    printf("\n");

    // DeleteX
    printf("Menghapus elemen C dan G\n");
    DeleteX(&L, 'C');
    DeleteX(&L, 'G');
    printf("List setelah DeleteX: ");
    PrintList(L);
    printf("jumlah elemen = %d\n", NbElm(L));
    printf("\n");
    

    // SearchX
    SearchX(L, 'D', &A);
    printf("Mencari D: %s\n", A != NIL ? "DITEMUKAN" : "TIDAK DITEMUKAN");
    SearchX(L, 'F', &A);
    printf("Mencari F: %s\n", A != NIL ? "DITEMUKAN" : "TIDAK DITEMUKAN");
    SearchX(L, 'A', &A);
    printf("Mencari A: %s\n", A != NIL ? "DITEMUKAN" : "TIDAK DITEMUKAN");
    printf("\n");
    
    // UpdateX
    printf("Sebelum UpdateX, isi L: \n");
    PrintList(L);
    UpdateX(&L, 'B', 'U');
    UpdateX(&L, 'D', 'J');
    UpdateX(&L, 'E', 'A');
    UpdateX(&L, 'F', 'M');
    printf("Setelah UpdateX,isi L:\n ");
    PrintList(L);
    printf("jumlah elemen = %d\n", NbElm(L));
    printf("\n");

    // Invers
    printf("Sebelum Invers,isi L: ");
    PrintList(L);
    Invers(&L);
    printf("Setelah Invers,isi L: ");
    PrintList(L);
    printf("\n");

    //InsertVAfterX
    printf("Sebelum InsertVAfterX,isi L: ");
    PrintList(L);
    InsertVAfterX(&L, 'U', 'X');
    InsertVAfterX(&L, 'X', 'Y');
    InsertVAfterX(&L, 'Y', 'Z');
    printf("Setelah InsertVAfterX, isi L: ");
    PrintList(L);
    printf("\n");

    //InsertVBeforeX
    printf("Sebelum InsertVBeforeX,isi L: ");
    PrintList(L);
    InsertVBeforeX(&L, 'U', 'H');
    InsertVBeforeX(&L, 'H', 'G');
    InsertVBeforeX(&L, 'G', 'F');
    printf("Setelah InsertVBeforeX, isi L: ");
    PrintList(L);
    printf("\n");

    // DeleteVAfterX
    printf("Sebelum DeleteVAfterX,isi L: ");
    PrintList(L);
    DeleteVAfterX(&L, 'Y', &V);
    DeleteVAfterX(&L, 'X', &V);
    DeleteVAfterX(&L, 'U', &V);
    printf("Setelah DeleteVAfterX, isi L: ");
    PrintList(L);
    printf("\n");

   //DeleteVBeforeX
    CreateList(&L1);
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'I');
    InsertVLast(&L1, 'U');
    InsertVLast(&L1, 'E');
    InsertVLast(&L1, 'X');
    InsertVLast(&L1, 'O');
    printf("Sebelum DeleteVBeforeX,isi L: ");
    PrintList(L1);
    DeleteVBeforeX(&L1,'O', &V);
    printf("Setelah DeleteVBeforeX, isi L: ");
    PrintList(L1);
    printf("\n");

    //CountX
    CreateList(&L2);
    InsertVLast(&L2, 'A');
    InsertVLast(&L2, 'P');
    InsertVLast(&L2, 'A');
    InsertVLast(&L2, 'I');
    InsertVLast(&L2, 'T');
    InsertVLast(&L2, 'U');
    printf("Isi L2: ");
    PrintList(L2);
    printf("Jumlah kemunculan huruf A dalam L: %d\n", CountX(L2, 'A'));
    printf("\n");

    //FrekuensiX
    printf("FrekuensiX('A') = %.2f (%.0f%%)", 
    FrekuensiX(L2, 'A'), 
    FrekuensiX(L2, 'A') * 100);
    printf("\n");

    //MaxMember
    printf("Isi L2: ");
    PrintList(L2);
    printf("\nMaxMember = %d", MaxMember(L2));
    printf("\n(Kemunculan terbanyak adalah %d kali)", MaxMember(L2));
    printf("\n");
    //Modus
    printf("Modus = '%c'", Modus(L2));
    printf("\n(Karakter yang paling sering muncul adalah '%c')", Modus(L2));
    printf("\n"); 

    //CountVocal
    printf("Isi L1: "); 
    PrintList(L1);
    printf("Jumlah huruf vokal dalam L1: %d\n", CountVocal(L1));
    printf("\n");

    //CountNG
    InsertVLast(&L2, 'N');
    InsertVLast(&L2, 'G');
    InsertVLast(&L2, 'G');
    printf("Isi L2: ");
    PrintList(L2);
    printf("Jumlah huruf N yang diikuti G dalam L2: %d\n", CountNG(L2));
    printf("\n");

    //searchAllX
    printf("Isi L2: ");
    PrintList(L2);
    printf("Posisi kemunculan huruf A dalam L2: ");
    SearchAllX(L2, 'A');
    printf("Posisi kemunculan huruf T dalam L2: ");
    SearchAllX(L2, 'T');
    printf("\n");

    //DeleteAllX
    printf("Sebelum DeleteAllX, isi L2: ");
    PrintList(L2);
    DeleteAllX(&L2, 'A');
    printf("Setelah DeleteAllX('A'), isi L2: ");
    PrintList(L2);
    printf("\n");

    //ConcatList
    CreateList(&L3);
    ConcatList(L1, L2, &L3);
    printf("Hasil ConcatList L1 dan L2 ke L3: ");
    PrintList(L3);
    printf("\n");

    //SplitList
    SplitList(L3, &L1, &L2);
    printf("Hasil SplitList L3 ke L1 dan L2: \n");
    printf("L1: ");
    PrintList(L1);
    printf("L2: ");
    PrintList(L2);
    printf("\n");

    //COpyList
    printf("Sebelum CopyList, isi L3: ");
    PrintList(L3);
    CreateList(&L4);
    CopyList(L3, &L4);
    printf("Hasil CopyList L3 ke L4: ");
    PrintList(L4);





   
    return 0;
}