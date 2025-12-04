#include <stdio.h>
#include "header.h"
#include "boolean.h"
#include "body.c"
/* Program   : PenjadwalanProsesCPU.c */
/* Deskripsi : Implementasi ADT Queue dan Proses */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/***********************************/
int main(){
    Proses P, P1, P2, P3, P4, P5, x;
    Queue Q;
    // Inisialisasi semua proses
    createProses(&P);
    createProses(&P1);
    createProses(&P2);
    createProses(&P3);
    createProses(&P4);
    createProses(&P5);
    createProses(&x);
    createQueue(&Q,&P);
    // NIM = 40124
    addProses(&P1, 'A', 4);
    addProses(&P2, 'B', 7);
    addProses(&P3, 'C', 1);
    addProses(&P4, 'D', 2);
    addProses(&P5, 'E', 4);
    // Enqueue proses
    enqueue(&Q, P1);
    enqueue(&Q, P2);
    enqueue(&Q, P3);
    enqueue(&Q, P4);
    enqueue(&Q, P5);
    printf("STATUS QUEUE SETELAH ENQUEUE\n");
    printf("Isi Queue: ");
    printQueue(Q);
    infoHead(Q);
    infoTail(Q);
    printf("Tail ada di posisi: %d\n", tail(Q));
    printf("Ukuran Queue: %d\n\n", sizeQueue(Q));
    printf("EKSEKUSI PROSES (SJF - Shortest Job First)\n");
    ProsesSimulasi (&Q, &x);
    printf("\nSTATUS QUEUE SETELAH EKSEKUSI\n");
    printf("Isi Queue: ");
    printQueue(Q);
    
    return 0;
}