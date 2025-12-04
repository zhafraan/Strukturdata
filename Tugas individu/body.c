#include <stdio.h>
#include "header.h"
#include "boolean.h"
/* Program   : body.c */
/* Deskripsi : Body file untuk ADT Queue dan Proses */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/***********************************/

/*function isEmptyQueue(Q:Queue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(Queue Q){
    return (Q.head == 0 && Q.tail == 0);
}
/*function isFullQueue(Q:Queue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(Queue Q){
    return(Q.tail == 5);
}
/*function isOneElement(Q:Queue) -> boolean
{mengembalikan true jika Q hanya memiliki satu elemen}*/
boolean isOneElementQueue(Queue Q){
    return(Q.tail == 1);
}
/*procedure createProses (output Q:Queue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/
void createProses(Proses *P){
    (*P).IDProses = '#';
    (*P).BurstTime = 999;
}
/*procedure addProses (output P:Proses, input id:character, input bt:integer)
{I.S.: id dan bt terdefinisi}
{F.S.: P terdefinisi, P.IDProses=id, P.BurstTime=bt}
{Proses: mengisi elemen P dengan id dan bt} */
void addProses(Proses *P, char id, int bt){
    (*P).IDProses = id;
    (*P).BurstTime = bt;
}
/*procedure createQueue ( output Q:Queue, output P:Proses)
{I.S.: -}
{F.S.: Q terdefinisi, kosong, P terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/
void createQueue(Queue *Q,Proses *P){
    int i;
    for (i = 1; i <= 5; i++) {
        (*Q).wadah[i] = *P; 
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}
/*function getBT(P:Proses) -> integer
{mengembalikan nilai BurstTime dari P} */
int getBT(Proses P){
    return P.BurstTime;
}
/*function getID(P:Proses) -> char
{mengembalikan nilai IDProses dari P} */    
char getID(Proses P){
    return P.IDProses;
}
/*Function Head(Q:Queue) -> integer
{mengembalikan posisi elemen terdepan} */
int head(Queue Q){
    return Q.head;
}
/*Function Tail(Q:Queue) -> integer
{mengembalikan posisi elemen terakhir} */
int tail(Queue Q){
    return Q.tail;
}
/*Function InfoHead(Q:Queue) -> Proses
{mengembalikan nilai elemen terdepan} */
Proses infoHead(Queue Q){
    printf("Head:<%c,%d>\n", Q.wadah[Q.head].IDProses, Q.wadah[Q.head].BurstTime);
    return Q.wadah[Q.head];
}
/*Function InfoTail(Q:Queue) -> Proses
{mengembalikan nilai elemen terakhir} */
Proses infoTail(Queue Q){
    printf("Tail: <%c,%d>\n", Q.wadah[Q.tail].IDProses, Q.wadah[Q.tail].BurstTime);
    return Q.wadah[Q.tail];
}
/*function sizeQueue(Q:Queue)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue(Queue Q){
    if (isEmptyQueue(Q)){
        return 0;
    } 
    else {
        return (Q.tail - Q.head + 1);
    }
}
/*procedure printQueue(input Q:Queue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong,dimulai
dari head}*/
void printQueue(Queue Q){
    int i;
    if (isEmptyQueue(Q)){
        printf("Queue kosong\n");
    } 
    else {
        for(i=1 ; i<=5 ; i++){
            printf("%c ",Q.wadah[i].IDProses);
        }
        printf("\n");
    }
 
}
/*procedure viewQueue(input Q:Queue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue(Queue Q) {
    int i;
    if (isEmptyQueue(Q)){
        printf("Queue kosong\n");
    } else {
        for(i=1 ; i<=5 ; i++){
            if (Q.wadah[i].IDProses != '#') {
                printf("%c ",Q.wadah[i].IDProses);
            }
        }
        printf("\n");
    }
    
}
/*procedure Tukar(input/output a:Proses, input/output b:Proses)
{I.S.: a dan b terdefinisi}
{F.S.: a dan b bertukar nilai}
{Proses: menukar nilai a dan b}*/
void Tukar(Proses *a, Proses *b) {
    Proses temp = *a;
    *a = *b;
    *b = temp;
}
/*procedure enqueue( input/output Q:Queue, input P: Proses )
{I.S.: E terdefinisi}
{F.S.: Q mungkin berubah, P ditambahkan di belakang}
{Proses: menambahkan P ke dalam Q jika Q tidak penuh}*/
void enqueue(Queue *Q, Proses P) {
    if (isFullQueue(*Q)) {
        printf("Queue penuh!\n");
        return;
    }

    // Jika queue kosong
    if (isEmptyQueue(*Q)) {
        (*Q).head = 1;
        (*Q).tail = 1;
        (*Q).wadah[(*Q).tail] = P;
    } 
    else {
        (*Q).tail++;
        (*Q).wadah[(*Q).tail] = P;
    }

    // Sorting ascending berdasarkan BurstTime
    for (int i = (*Q).head; i < (*Q).tail; i++) {
        for (int j = (*Q).head; j < (*Q).tail - (i - (*Q).head); j++) {
            if ((*Q).wadah[j].BurstTime > (*Q).wadah[j + 1].BurstTime) {
                Tukar(&(*Q).wadah[j], &(*Q).wadah[j + 1]);
            }
        }
    }
}
/*procedure dequeue( input/output Q:Queue, output P: Proses )
{I.S.: Q mungkin kosong}
{F.S.: Q mungkin berubah, P dihapus dari depan}
{Proses: menghapus elemen terdepan dari Q jika Q tidak kosong}*/
void dequeue(Queue *Q, Proses *P){
    Proses E;
    createProses(&E);
    if(isEmptyQueue(*Q)){
        return;
    }
    else if(isOneElementQueue(*Q)){
        *P = (*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head] = E;
        (*Q).head = 0;
        (*Q).tail = 0;
    }
    else{
        *P = (*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head] = E;
        for(int i = (*Q).head; i < (*Q).tail; i++){
            (*Q).wadah[i] = (*Q).wadah[i+1];
        }
        (*Q).wadah[(*Q).tail] = E;
        (*Q).tail--;
    }
}

/*procedure ProsesSimulasi (input/output Q:Queue, output P:Proses)
{I.S.: Q mungkin kosong}
{F.S.: Q mungkin berubah, P terdefinisi}
{Proses: mengurangi BurstTime elemen terdepan Q sebanyak 1, bila
BurstTime menjadi 0, elemen dihapus dari Q dan disimpan di P}*/
void ProsesSimulasi(Queue *Q, Proses *P){
    if(isEmptyQueue(*Q)){
        return;
    }
    else{
        int waktu = 0;
        int akhir = tail(*Q);
        for(int i = 1;i<= akhir;i++){
            dequeue(Q,P);
            printf("Proses ke %d = thread %c\t| waktu mulai = %d\t| waktu selesai = %d\n",i,getID(*P),waktu,getBT(*P)+waktu);
            waktu += getBT(*P);
        }
    }
}


