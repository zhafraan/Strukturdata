#ifndef HEADER_H  
#define HEADER_H
#include "boolean.h" 
/* Program   : header.h */
/* Deskripsi : Header file untuk ADT Queue dan Proses */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/***********************************/


/* type Proses = <IDProses  : character ,
                  BurstTime : integer > */
typedef struct {
    char IDProses;
    int BurstTime;
} Proses;

/* type Queue = < wadah: array [1..5] of character ,
				head: integer ,
				tail: integer >*/
typedef struct {
    Proses wadah[6];
    int head;
    int tail;
} Queue;

/*function isEmpty(Q:Queue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(Queue Q);

/*function isFull(Q:Queue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(Queue Q);

/*function isOneElement(Q:Queue) -> boolean
{mengembalikan true jika Q hanya memiliki satu elemen}*/
boolean isOneElementQueue(Queue Q);

/*procedure createProses (output Q:Queue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/
void createProses(Proses *P);

/*procedure addProses (output P:Proses, input id:character, input bt:integer)
{I.S.: id dan bt terdefinisi}
{F.S.: P terdefinisi, P.IDProses=id, P.BurstTime=bt}
{Proses: mengisi elemen P dengan id dan bt} */
void addProses(Proses *P, char id, int bt);

/*procedure createQueue ( output Q:Queue, output P:Proses)
{I.S.: -}
{F.S.: Q terdefinisi, kosong, P terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/
void createQueue(Queue *Q,Proses *P);

/*Function Head(Q:Queue) -> integer
{mengembalikan posisi elemen terdepan} */
int head(Queue Q);

/*Function Tail(Q:Queue) -> integer
{mengembalikan posisi elemen terakhir} */
int tail(Queue Q);

/*Function InfoHead(Q:Queue) -> Proses
{mengembalikan nilai elemen terdepan} */
Proses infoHead(Queue Q);

/*Function InfoTail(Q:Queue) -> Proses
{mengembalikan nilai elemen terakhir} */
Proses infoTail(Queue Q);

/*function sizeQueue(Q:Queue)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue(Queue Q);

/*procedure printQueue(input Q:Queue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong,dimulai
dari head}*/
void printQueue(Queue Q);

/*procedure viewQueue(input Q:Queue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue(Queue Q);

/*procedure Tukar(input/output a:Proses, input/output b:Proses)
{I.S.: a dan b terdefinisi}
{F.S.: a dan b bertukar nilai}
{Proses: menukar nilai a dan b}*/
void Tukar(Proses *a, Proses *b) ;
/*function getBT(P:Proses) -> integer
{mengembalikan nilai BurstTime dari P} */
int getBT(Proses P);

/*function getID(P:Proses) -> char
{mengembalikan nilai IDProses dari P} */    
char getID(Proses P);

/*procedure enqueue( input/output Q:Queue, input E: Proses )
{I.S.: E terdefinisi}
{F.S.: Q mungkin berubah, E ditambahkan di belakang}
{Proses: menambahkan E ke dalam Q jika Q tidak penuh}*/
void enqueue(Queue *Q, Proses P);

/*procedure dequeue( input/output Q:Queue, output E: Proses )
{I.S.: Q mungkin kosong}
{F.S.: Q mungkin berubah, E dihapus dari depan}
{Proses: menghapus elemen terdepan dari Q jika Q tidak kosong}*/
void dequeue(Queue *Q, Proses *P);

#endif