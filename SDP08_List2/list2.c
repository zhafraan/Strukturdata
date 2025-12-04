/* File : list2.c */
/* Deskripsi : realisasi body ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran */
/* Tanggal : 16 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.h" 

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E} */
address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma 
    P = (address) malloc(sizeof(Elm2)); //casting
    if (P != NULL ) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    //kamus lokal
	//algoritma
    if ( *P != NIL ) {
		next(*P) = NIL;
    free(*P);
    *P = NIL;}
}
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L){
    //kamus lokal
    //algoritma
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L){
    //kamus lokal
    //algoritma
    return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L){
    //kamus lokal
    //algoritma
    return ( !IsEmptyList(L) && (next(First(L)) == First(L)) );
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L){
    //kamus lokal 
    address P;
    //algoritma
    P = First(L);
    if (P != NIL) {
        printf("\nElemen = ");
        do {
            printf("\t%c", info(P));
            P = next(P);
        } while( P != First(L) );
    }
}
/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L){
    //kamus lokal
    address P;
    int hitung;

    //algoritma
    hitung = 0;
    P = First(L);
    if (P != NIL) {
        do {
            hitung++;
            P = next(P);
        } while (P != First(L));
    }
    return hitung;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ){
    //kamus lokal
    address P;
    address last;

    //algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) { 
            First(*L) = P;
            next(P) = P; 
        } 
        else {
            last = First(*L);
            while (next(last) != First(*L)) {
                last = next(last);
            }
            next(last) = P;
            next(P) = First(*L);
            First(*L) = P;
            
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ){
    //kamus lokal
    address P;
    address last;

    //algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P; 
        } 
        else {
            last = First(*L);
            while (next(last) != First(*L)) {
                last = next(last);
            }
            next(last) = P;
            next(P) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V){
    //kamus lokal
    address P;
    address last;

    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);

        if (IsOneElm(*L)) {
            First(*L) = NIL;
        } 
        else { 
            last = First(*L);
            while (next(last) != First(*L)) {
                last = next(last);
            }
            First(*L) = next(P);
            next(last) = First(*L);
        }
        Dealokasi(&P);
    }
    else {
        *V = '#';
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V){
    //kamus lokal
    address P;
    address Q;

    //algoritma
    if(First(*L) != NIL){
        P = First(*L);

        if (IsOneElm(*L)) { 
            *V = info(P);
            First(*L) = NIL;
            Dealokasi(&P);
        } 
         else { 
             Q = NIL;  
            while (next(P) != First(*L)) {
                Q = P;
                P = next(P);
            }
            *V = info(P);
            next(Q) = First(*L);
            Dealokasi(&P);
        }
    }
    else {
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X){
    //kamus lokal
    address P;
    address Q;
    address last;
    boolean found;
    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        Q = NIL;
        found = False;

        do {
            if (info(P) == X) {
                found = True;
                if (P == First(*L)) {
                    if (IsOneElm(*L)) {  
                        First(*L) = NIL;
                        Dealokasi(&P);
                        break;
                    } 
                    else {
                        last= First(*L);
                        while (next(last) != First(*L)) {
                            last = next(last);
                        }
                        First(*L) = next(P);
                        next(last) = First(*L);
                        Dealokasi(&P);
                        break;
                    }
                } 
                else {
                    next(Q) = next(P);
                    Dealokasi(&P);
                    break;
                }
            } 
            else {
                Q = P;
                P = next(P);
            }
        } while (P != First(*L) && !found);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A){
    //kamus lokal
    address P;

    //algoritma
    P = First(L);
    *A = NIL;
    if(!IsEmptyList(L)){
        do {
            if (info(P) == X) {
                *A = P;
                break;
            }
            P = next(P);
        } while (P != First(L));
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y){
    //kamus lokal
    address P;

    //algoritma
    if (!IsEmptyList(*L)) {  
        P = First(*L);
        do {
            if (info(P) == X) {
                info(P) = Y;
                break;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L){
    //kamus lokal
    address prev;
    address curr;
    address Q;
    address P;
    
    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        prev = NIL;
        curr = First(*L);
        do {
            Q = next(curr);
            next(curr) = prev;
            prev = curr;
            curr = Q;
        } while (curr != P);
        next(P) = prev;
        First(*L) = prev;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X){
    //kamus lokal
    address P;
    int count;
    
    // Algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X){
    // Kamus lokal
    int total, countX;
    float frekuensi;
    
    // Algoritma
    total = NbElm(L);
    if (total == 0) {
        return 0.0;
    }
    
    countX = CountX(L, X);
    frekuensi = (float)countX / (float)total;
    return frekuensi;
}


/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    // Kamus lokal
    address P;
    int hitung;
    
    // Algoritma
    P = First(L);
    hitung = 0;
    
    if (!IsEmptyList(L)) {
        do {
            if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O' ||
                info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
                hitung++;
            }
            P = next(P);
        } while (P != First(L));
    }
    
    return hitung;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L){
    // Kamus lokal
    address P;
    int count;
    char current, nextChar;
    
    // Algoritma
    count = 0;
    if (!IsEmptyList(L) && !IsOneElm(L)) {
        P = First(L);
        do {
            current = info(P);
            nextChar = info(next(P));
            // Cek pola NG atau ng
            if ((current == 'N' || current == 'n') && (nextChar == 'G' || nextChar == 'g')) {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V){
    //kamus lokal
    address P;
    address Q;

    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                Q = Alokasi(V);
                if (Q != NIL) {
                    next(Q) = next(P);
                    next(P) = Q;
                }
                break;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V){
    // Kamus lokal
    address P;
    address Q;
    address Prec;
    
    // Algoritma
    if (!IsEmptyList(*L)) {
        // Jika hanya 1 elemen, langsung insert di awal
        if (IsOneElm(*L)) {
            InsertVFirst(L, V);
            return;
        }
        P = First(*L);
        // Jika X adalah elemen pertama
        if (info(P) == X) {
            InsertVFirst(L, V);
            return;}
        // Cari elemen X di tengah atau akhir
        Prec = NIL;
        do {
            if (info(P) == X) {
                Q = Alokasi(V);
                if (Q != NIL) {
                    next(Prec) = Q;
                    next(Q) = P;
                }
                return;
            }
            Prec = P;
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V){
    // Kamus lokal
    address P;
    address Q;
    address Last ;
    
    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                Q = next(P);
                *V = info(Q);
            // Jika yang dihapus adalah First
            if (Q == First(*L)) {
                if (IsOneElm(*L)) {
                        First(*L) = NIL;
                    } 
                else {
                    // Cari last
                    Last = First(*L);
                    while (next(Last) != First(*L)) {
                        Last = next(Last);
                        }
                        First(*L) = next(Q);
                        next(Last) = First(*L);
                    }
                } 
            else { 
                next(P) = next(Q);
                }
                Dealokasi(&Q);
                return;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V){
    // Kamus lokal
    address P;
    address Q;
    address Prec;
    address Last;
    
    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        // Jika X adalah elemen pertama
        if (info(P) == X) {
            // Cari last
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            // Hapus elemen last
            *V = info(Last);
            if (IsOneElm(*L)) {
                First(*L) = NIL;
            } 
            else {
            // Cari Prec dari Last
                Prec = First(*L);
                while (next(Prec) != Last) {
                    Prec = next(Prec);
                }
                next(Prec) = First(*L);
            }
            Dealokasi(&Last);
            return;
        }
        // Cari elemen X
        Prec = NIL;
        do {
            if (info(P) == X) {
                // Hapus elemen Prec
                if (Prec != NIL) {
                    *V = info(Prec);
                    // Jika Prec adalah First
                    if (Prec == First(*L)) {
                        First(*L) = next(First(*L));
                    } 
                    else {
                        address Temp = First(*L);
                        while (next(Temp) != Prec) {
                            Temp = next(Temp);
                        }
                        next(Temp) = next(Prec);
                    }
                    Dealokasi(&Prec);
                }
                return;
            }
            Prec = P;
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X){
    // Kamus lokal
    address P;
    address Prec;
    address Del;
    address Last;
    
    // Algoritma
    if (!IsEmptyList(*L)) {
        // Hapus semua X diawal 
        while (!IsEmptyList(*L) && info(First(*L)) == X) {
            P = First(*L);
            if (IsOneElm(*L)) {
                First(*L) = NIL;
                Dealokasi(&P);
                return; 
            } 
            else {
                // Cari last
                Last = First(*L);
                while (next(Last) != First(*L)) {
                    Last = next(Last);
                }
                First(*L) = next(P);
                next(Last) = First(*L);
                Dealokasi(&P);
            }
        }
        // Jika list sudah kosong
        if (IsEmptyList(*L)) {
            return;
        }
        // Hapus sisanya di tengah/akhir
        Prec = First(*L);
        P = next(Prec);
        do {
            if (info(P) == X) {
                Del = P;
                P = next(P);
                next(Prec) = P;
                Dealokasi(&Del);
            } else {
                Prec = P;
                P = next(P);
            }
        } while (P != First(*L));
    }
}
/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X){
    //kamus lokal
    address P;
    int posisi;
    int count;

    //algoritma
    P = First(L);
    posisi = 1;
    count = 0;
    printf("\nPosisi kemunculan elemen %c: ", X);
    if (!IsEmptyList(L)) {
        do {
            if (info(P) == X) {
                printf("%d ", posisi);
                count++;
            }
            P = next(P);
            posisi++;
        } while (P != First(L));
    }
    if (count == 0) {
        printf("0");
    }
    printf("\n");
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L){
    //kamus lokal
    address P;
    int max;
    int temp;

    //algoritma
    max = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            temp = CountX(L, info(P));
            if (temp > max) {
                max = temp;
            }
            P = next(P);
        } while (P != First(L));
    }
    return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L){
    //kamus lokal
    address P;
    char modus;
    int max;
    int temp;

    //algoritma
    modus = '#'; 
    max = 0;

    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            temp = CountX(L, info(P));
            if (temp > max) {
                max = temp;
                modus = info(P);
            }
            P = next(P);
        } while (P != First(L));
    }

    return modus;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    //kamus lokal
    address P;
    
    //algoritma
    CreateList(L);
    P = First(L1);
    if (!IsEmptyList(L1)) {
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    }

    P = First(L2);
    if (!IsEmptyList(L2)) {
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L2));
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2){
    //kamus lokal
    address P;
    int mid;
    int count;
    
    //algoritma
    CreateList(L1);
    CreateList(L2);
    mid = (NbElm(L) + 1) / 2;
    count = 0;
    P = First(L);
    if (!IsEmptyList(L)) {
        do {
            if (count <= mid) {
                InsertVLast(L1, info(P));
            } 
            else {
                InsertVLast(L2, info(P));
            }
            P = next(P);
            count++;
        } while (P != First(L));
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2){
    //kamus lokal
    address P;

    //algoritma
    CreateList(L2);
    P = First(L1);
    if (!IsEmptyList(L1)) {
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    }
}

