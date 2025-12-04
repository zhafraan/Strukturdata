#include <stdio.h>
#include "tqueue3.c"
#include "boolean.h"

/* Program   : mtqueue3.c */
/* Deskripsi : Main ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/* Tanggal   : 9 Oktober 2025*/
/***********************************/

int main() {
    // kamus main
    tqueue3 A, B;
    char e;
    int i;
    
    // algoritma
    printf("Buat Queue A \n");
    createQueue3(&A);
    printf("Size queue A: %d\n", sizeQueue3(A));
    printf("Info Head: %c\n", infoHead3(A));
    printf("Info Tail: %c\n", infoTail3(A));
    printf("apakah A kosong? %s\n", isEmptyQueue3(A) ? "True" : "False");
    printf("apakah A penuh? %s\n", isFullQueue3(A) ? "True" : "False");
    printQueue3(A);
    printf("\n");

    //Enqueue beberapa elemen ke A dan B
    printf("Enqueue 5 elemen ke A\n");
    enqueue3(&A, 'X');
    enqueue3(&A, 'Y');
    enqueue3(&A, 'Z');
    enqueue3(&A, 'W');
    enqueue3(&A, 'V');
    viewQueue3(A);
    printf("\n");
    printf("Size A = %d, Head = %c, Tail = %c\n", sizeQueue3(A), infoHead3(A), infoTail3(A));
    printf("apakah A kosong? %s\n", isEmptyQueue3(A) ? "True" : "False");
    printf("apakah A penuh? %s\n", isFullQueue3(A) ? "True" : "False");
    printQueue3(A);
    printf("\n");

    createQueue3(&B);
    enqueue3(&B, 'A');
    viewQueue3(B);
    printf("\n");
    printf("Size B = %d, Head = %c, Tail = %c\n", sizeQueue3(B), infoHead3(B), infoTail3(B));
    printf("apakah B isonelement? %s\n", isOneElement3(B) ? "True" : "False");
    printQueue3(B);
    printf("\n");
    enqueue3(&B, 'B');
    enqueue3(&B, 'C');
    viewQueue3(B);
    printf("\n");
    printf("Size B = %d, Head = %c, Tail = %c\n", sizeQueue3(B), infoHead3(B), infoTail3(B));
    printf("apakah B isonelement? %s\n", isOneElement3(B) ? "True" : "False");
    printf("apakah B penuh? %s\n", isFullQueue3(B) ? "True" : "False");
    printf("apakah B kosong? %s\n", isEmptyQueue3(B) ? "True" : "False");
    printQueue3(B);

    // Dequeue berputar elemen A
    printf("\nDequeue 3 elemen dari A\n");
    for (i = 1; i <= 3; i++) {
        dequeue3(&A, &e);
        printf("Elemen yang didequeue: %c\n", e);
    }
    viewQueue3(A);
    printf("\n");
    printf("Size A = %d, Head = %c, Tail = %c\n", sizeQueue3(A), infoHead3(A), infoTail3(A));
    printf("Head A sekarang di posisi: %d\n", head3(A));
    printf("Tail A sekarang di posisi: %d\n", tail3(A));
    printf("apakah A isonelement? %s\n", isOneElement3(A) ? "True" : "False");
    printf("apakah A penuh? %s\n", isFullQueue3(A) ? "True" : "False");
    printf("apakah A kosong? %s\n", isEmptyQueue3(A) ? "True" : "False");
    printQueue3(A);
    printf("\n");

    // Test Enqueue berputar A
    printf("Isi Queue A sekarang: ");
    viewQueue3(A);
    printf("\n");
    printf("Head A sekarang di posisi: %d\n", head3(A));
    printf("Tail A sekarang di posisi: %d\n", tail3(A));
    printf("Size A = %d\n", sizeQueue3(A));
    printf("apakah tail di depan head? %s\n", isTailOverHead(A) ? "True" : "False");
    printQueue3(A);
    printf("\n");

    printf("Enqueue 3 elemen baru ke A: P, Q, R\n");
    enqueue3(&A, 'P');
    enqueue3(&A, 'Q');
    printf("Setelah enqueue P, Q:\n");
    printf("Head: %d, Tail: %d\n", head3(A), tail3(A));
    viewQueue3(A);
    printf("\n");
    enqueue3(&A, 'R');
    printf("Setelah enqueue R:\n");
    printf("Head: %d, Tail: %d\n", head3(A), tail3(A));
    viewQueue3(A);
    printf("\n");
    printf("Size A = %d\n", sizeQueue3(A));
    printf("apakah A penuh? %s\n", isFullQueue3(A) ? "True" : "False");

    //Tailoverhead
    dequeue3(&A, &e);
    printf("Setelah dequeue 1 elemen dari A (elemen %c):\n", e);
    printf("apakah tail di depan head? %s\n", isTailOverHead(A) ? "True" : "False");
    printQueue3(A);
    viewQueue3(A);
    printf("\n");
    printf("Head: %d, Tail: %d\n", head3(A), tail3(A));
    printf("\n");


    return 0;
}

    
