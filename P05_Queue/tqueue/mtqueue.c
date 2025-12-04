/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul ADT Queue 1*/
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/* Tanggal   : 3 Oktober 2025 */
/***********************************/
#include <stdio.h>
#include "tqueue.c"
#include "boolean.h"
int main() 
{
    /* kamus main */
    tqueue A, B; 
    char c;
    int i;
    
    /* algoritma */
    createQueue(&A);
    printf("Queue A setelah dibuat :\n");
    printQueue(A);
    printf("\n");

    // Enqueue
    printf("Isi queue A dengan karakter :\n");
    enqueue(&A,'A');
    enqueue(&A,'B');
    enqueue(&A,'C');
    enqueue(&A,'D');
    enqueue(&A,'E');
    printQueue(A);
    printf("Size queue A: %d\n", sizeQueue(A));
    printf("Info Head: %c\n", infoHead(A));
    printf("Info Tail: %c\n", infoTail(A));
    printf("Apakah queue A kosong? %s\n", isEmptyQueue(A) ? "YA" : "TIDAK");
    printf("Apakah queue A penuh? %s\n", isFullQueue(A) ? "YA" : "TIDAK");
    printf("\n");

    // Dequeue
    printf("Dequeue 3 elemen dari queue A\n");
    for (i = 1; i <= 3; i++) {
        dequeue(&A, &c);
        printf("Karakter yang didequeue = %c\n", c);
    }
    printQueue(A);
    printf("Size queue A: %d\n", sizeQueue(A));
    printf("Info Head: %c\n", infoHead(A));
    printf("Info Tail: %c\n", infoTail(A));
    printf("Apakah queue A kosong? %s\n", isEmptyQueue(A) ? "YA" : "TIDAK");
    printf("Apakah queue A penuh? %s\n", isFullQueue(A) ? "YA" : "TIDAK");
    printf("\n");

    printf("Dequeue elemen dari queue A hingga kosong\n");
    for (i = 1; i <= 4; i++) {
        dequeue(&A, &c);
        printf("Karakter yang didequeue = %c\n", c);
    }
    printQueue(A);
    printf("Apakah queue A kosong? %s\n", isEmptyQueue(A) ? "YA" : "TIDAK");
    printf("Apakah queue A penuh? %s\n", isFullQueue(A) ? "YA" : "TIDAK");
    printf("\n");

    // Test enqueue setelah kosong
    printf("Test enqueue setelah queue kosong\n");
    enqueue(&A,'X');
    enqueue(&A,'Y');
    enqueue(&A,'Z');

    printQueue(A);
    printf("Size queue A: %d\n", sizeQueue(A));
    printf("Info Head: %c\n", infoHead(A));
    printf("Info Tail: %c\n", infoTail(A));
    printf("\n");

    // Test enqueue2 dan dequeue2
    printf("Test enqueue2 dan dequeue2\n");
    createQueue(&B);
    
    printf("Enqueue2 5 karakter ke queue A dan B\n");
    enqueue2(&A, &B, 'P');
    enqueue2(&A, &B, 'Q');
    enqueue2(&A, &B, 'R');
    enqueue2(&A, &B, 'S');
    enqueue2(&A, &B, 'T');
    
    printf("Queue A: ");
    viewQueue(A);
    printf("Size queue A: %d\n", sizeQueue(A));
    printf("Queue B: ");
    viewQueue(B);
    printf("Size queue B: %d\n", sizeQueue(B));
    printf("\n");

    printf("Dequeue2 dari queue A dan B\n");
    for (i = 1; i <= 3; i++) {
        dequeue2(&A, &B, &c);
        printf("Karakter yang didequeue = %c\n", c);
    }
    printf("Queue A: ");
    viewQueue(A);
    printf("Size queue A: %d\n", sizeQueue(A));
    printf("Queue B: ");
    viewQueue(B);
    printf("Size queue B: %d\n", sizeQueue(B));
    printf("\n");

    return 0;
}