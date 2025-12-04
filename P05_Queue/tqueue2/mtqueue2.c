/* Program   : mtqueue2.c */
/* Deskripsi : file DRIVER modul ADT Queue 2*/
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/* Tanggal   : 3 Oktober 2025 */
/***********************************/
#include <stdio.h>
#include "tqueue2.c"
#include "boolean.h"

int main() {
    // kamus main
    tqueue2 A, B;
    char e;
    int i;
    // algoritma
    // Buat Queue A dan B
    printf("Buat Queue A dan B\n\n");
    createQueue2(&A);
    createQueue2(&B);
    printf("Queue A dan B  dibuat\n");
    printQueue2(A);
    printf("Size queue A: %d\n", sizeQueue2(A));
    printf("Info Head: %c\n", infoHead2(A));
    printf("Info Tail: %c\n", infoTail2(A));
    printQueue2(B);
    printf("Size queue B: %d\n", sizeQueue2(B));
    printf("Info Head: %c\n", infoHead2(B));
    printf("Info Tail: %c\n", infoTail2(B));
    printf("\n");

    //Enqueue beberapa elemen ke A
    printf("Enqueue A: X,Y,Z,W,V\n");
    enqueue2(&A, 'X');
    enqueue2(&A, 'Y');
    enqueue2(&A, 'Z');
    enqueue2(&A, 'W');
    enqueue2(&A, 'V');
    viewQueue2(A);
    printf("Size A = %d, Head = %c, Tail = %c\n", sizeQueue2(A), infoHead2(A), infoTail2(A));
    printf("\n");

    //Enqueue beberapa elemen ke B
    printf("Enqueue B:A,B,C\n");
    enqueue2(&B, 'A');
    enqueue2(&B, 'B');
    enqueue2(&B, 'C');
    viewQueue2(B);
    printf("Size B = %d, Head = %c, Tail = %c\n", sizeQueue2(B), infoHead2(B), infoTail2(B));
    printf("\n");

    //Dequeue 1 elemen dari A
    dequeue2(&A, &e);
    printf("Dequeue dari A = %c\n", e);
    viewQueue2(A);
    printf("Size A = %d, Head = %c, Tail = %c\n", sizeQueue2(A), infoHead2(A), infoTail2(A));
    printf("\n");

    //Tambah elemen lagi ke A (cek resetHead)
    printf("Tambah lagi ke A: P, Q, R\n");
    enqueue2(&A, 'P');
    enqueue2(&A, 'Q');
    enqueue2(&A, 'R');
    viewQueue2(A);
    printf("\n");

    //Bandingkan isi queue A dan B
    printf("Apakah Queue A dan Queue B sama? %s\n", isEqualQueue2(A, B) ? "YA" : "TIDAK");
    printf("\n");

    //EnqueueN ke B
    printf("Masukkan 2 elemen ke B:\n");
    enqueue2N(&B, 2);
    printf("Isi Queue B sekarang: ");
    viewQueue2(B);

    return 0;
}