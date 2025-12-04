/* File : list3.c */
/* Deskripsi : realisasi body ADT list berkait dengan representasi fisik pointer  */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran */
/* Tanggal : 23 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) //representasi fisik fungsi
{	//kamus lokal
	address P;
	//algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL) {
        info(P) = E;
		next(P) = NIL;
		prev(P) = NIL;
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
        prev(*P) = NIL;
    free(*P);
    *P = NIL;}
}
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
	//kamus lokal
	//algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
	//kamus lokal
	//algoritma
	return (First(L) == NIL);
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L){
	//kamus lokal 
	address P;
	//algoritma
	if (!IsEmptyList(L)) { // 
		printf("\nElemen = ");
		P = First(L); 
		while (P != NIL) { 
			printf("\t%c", info(P)); 
			P = next(P);
		} 
		printf("\n");
	} 
    else {
		printf("List kosong\n"); 
	}
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
	//kamus lokal
    address P;
    int hitung;

    //algoritma
    hitung = 0;
    P = First(L);
    while (P != NIL) {
        hitung++;
        P = next(P);
    }
    return hitung;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ){
	//kamus lokal
	address P;
	
	//algoritma
	P = Alokasi(V);
	 if (P != NIL) {
        // jika list kosong
        if (IsEmptyList(*L)) {
            First(*L) = P;
        } 
		else {
            //Hubungkan P ke elemen pertama yang lama
            next(P) = First(*L);
            prev(First(*L)) = P;
            First(*L) = P; // P menjadi elemen pertama yang baru
        }
    }
}
/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
	//kamus lokal
	address P;
	address last;

	//algoritma
	P = Alokasi(V);
	 if (P != NIL) {
        // jika list kosong
		if (IsEmptyList(*L)) {
			First(*L) = P;
		} 
		else {
            // mencari elemen terakhir
			last = First(*L);
			while (next(last) != NIL) {
				last = next(last);
			}
            // Hubungkan elemen terakhir dengan P
			next(last) = P;
			prev(P) = last;
		}
	}
    
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
	//kamus lokal
	 address P;

	//algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);	
        *V = info(P);
        // jika hanya ada satu elemen
        if (next(P) == NIL) {
            First(*L) = NIL;
        } 
		else {
            // Elemen kedua menjadi elemen pertama
            First(*L) = next(P);
            prev(First(*L)) = NIL;
        }
        Dealokasi(&P);
    }
	else {
        *V = '#';
    }
}



/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
	//kamus lokal
	 address P;
	 address last;

	//algoritma
    if (!IsEmptyList(*L)) {
        last = First(*L);
        // mencari elemen terakhir
        while (next(last) != NIL) {
            last = next(last);
        }
        *V = info(last);
        // jika last adalah elemen pertama
        if (prev(last) == NIL) {
            First(*L) = NIL;
        } 
		else {
            // elemen sebelum last menjadi elemen terakhir
            next(prev(last)) = NIL;
        }
        Dealokasi(&last);
    } 
	else {
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X){
    //kamus lokal
    address P;

    //algoritma
    if (!IsEmptyList(*L)) { 
        P = First(*L);
        // Cari elemen dengan nilai X
        while (P != NIL && info(P) != X) { 
            P = next(P);
        }
        // Jika elemen ditemukan
        if (P != NIL) {
            // Jika P adalah elemen pertama
            if (P == First(*L)) { 
                First(*L) = next(P);
                if (First(*L) != NIL) {
                    prev(First(*L)) = NIL;
                }
            } 
            // Jika P adalah elemen terakhir
            else if (next(P) == NIL) {
                next(prev(P)) = NIL;
            }
            // Jika P di tengah
            else {
                next(prev(P)) = next(P);
                prev(next(P)) = prev(P);
            }
            Dealokasi(&P);
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A){
	//kamus lokal
    address P;

    //algoritma
    *A = NIL;
    P = First(L);
    while (P != NIL) {
        if (info(P) == X) {
            *A = P;
            break;
        }
        P = next(P);
    }   
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
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

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L){
	// kamus lokal
	address P;
    address Q; 
    address Next;

	// algoritma
	P = NIL;
	Q = First(*L);
	while (Q != NIL) {
		Next = next(Q);
		next(Q) = P;
		prev(Q) = Next;
		P = Q;
		Q = Next;
	}
	First(*L) = P;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
    // Kamus lokal
    address P;
    address Q;
    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (P != NIL && info(P) != X) {
            P = next(P);
        }
        if (P != NIL) {
            Q = Alokasi(V);
            if (Q != NIL) {
                next(Q) = next(P);      
                prev(Q) = P;            
                if (next(P) != NIL) {
                    prev(next(P)) = Q;  
                }
                next(P) = Q;        
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V){
    // Kamus lokal
    address P;
    address Q;
    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (P != NIL && info(P) != X) {
            P = next(P);
        }
        if(info(P) == X){
            Q = Alokasi(V);
            if (Q != NIL) {
                prev(Q) = prev(P);  
                next(Q) = P;        
                if (prev(P) != NIL) {
                    next(prev(P)) = Q; 
                }
                else {
                    First(*L) = Q;
                    prev(Q) = prev(P);
                    next(Q) = P;
                    prev(P) = Q;    
                }
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V){
    // Kamus lokal
    address Q;
    address P;

    // Algoritma
    *V = '#'; 
    if (!IsEmptyList(*L)) {
        Q = First(*L);
        while (Q != NIL && info(Q) != X) {
            Q = next(Q);
        }
        if (Q != NIL && next(Q) != NIL) {
            P = next(Q);
            *V = info(P);
            next(Q) = next(P);
            if (next(P) != NIL) {
                prev(next(P)) = Q;
            }
            Dealokasi(&P);
        }
    }
}


/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
    // Kamus lokal
    address P;
    address Q;
    // Algoritma
    *V = '#'; 
    
    if (!IsEmptyList(*L)) {
        // Cari elemen X
        Q = First(*L);
        while (Q != NIL && info(Q) != X) {
            Q = next(Q);
        }
        // Jika elemen X ditemukan dan ada elemen sebelum X
        if (Q != NIL && prev(Q) != NIL) {
            P = prev(Q); 
            *V = info(P);
            
            if (prev(P) == NIL) {
                // P adalah elemen pertama
                First(*L) = Q;
                prev(Q) = NIL;
            } 
            else {
                next(prev(P)) = Q;  
                prev(Q) = prev(P);  
            }
            next(P) = NIL;
            prev(P) = NIL;
            
            Dealokasi(&P);
        }
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X){
    // kamus lokal
    address P;
    int count;

   // algoritma
    count = 0;
    P = First(L);
    
    while (P != NIL) {
        if (info(P) == X) {
            count++;
        }
        P = next(P);
    }
    
    return count;}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X){
    // kamus lokal
    int total;
    int countX;
    // algoritma
    total = NbElm(L);
    if (total == 0) {
        return 0.0;
    }
    countX = CountX(L, X);
    return
     (float)countX / total;
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
    // Kamus lokal
    address P;
    int max;
    int temp;

    // Algoritma
    max = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        while (P != NIL) {
            temp = CountX(L, info(P));
            if (temp > max) {
                max = temp;
            }
            P = next(P);
        }
    }
    return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L){
    // Kamus lokal
    address P;
    char modusChar, currentChar;
    int maxCount, count;
    // Algoritma
    modusChar = '#';
    maxCount = 0;
    P = First(L);
    
    while (P != NIL) {
        currentChar = info(P);
        count = CountX(L, currentChar);
        if (count > maxCount) {
            maxCount = count;
            modusChar = currentChar;
        }
        
        P = next(P);
    }
    
    return modusChar;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L){
    // Kamus lokal
    address P;
    int hitung;
    // Algoritma
    P = First(L);
    hitung = 0;
    while (P != NIL) {
        // Cek apakah karakter adalah vokal (huruf besar atau kecil)
        if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O' ||
            info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
            hitung++;
        }
        P = next(P);
    }
    
    return hitung;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L){
    // Kamus lokal
    address P;
    int count;
    // Algoritma
    count = 0;
    P = First(L);
    while (P != NIL && next(P) != NIL) {
        if ((info(P) == 'N' || info(P) == 'n') && 
            (info(next(P)) == 'G' || info(next(P)) == 'g')) {
            count++;
        }
        P = next(P);
    }
    
    return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X){
    // kamus lokal
    address P;
    int posisi;
    int found;
    // Algoritma
    posisi = 1;
    found = 0;
    P = First(L);
   
    while (P != NIL) {
        if (info(P) == X) {
            if (found > 0) {
                printf(","); 
            }
            printf("%d", posisi);
            found++;
        }
        P = next(P);
        posisi++;
    }
    if (found == 0) {
        printf("0");
    }
    printf("\n");
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X){
    // kamus lokal
    address P;
    address temp;
    
    // algoritma
    P = First(*L);
    while (P != NIL) {
        if (info(P) == X) {
            temp = P;
            // Jika P adalah elemen pertama
            if (prev(P) == NIL) {
                First(*L) = next(P);
                if (next(P) != NIL) {
                    prev(next(P)) = NIL;
                }
            } 
            // Jika P adalah elemen terakhir
            else if (next(P) == NIL) {
                next(prev(P)) = NIL;
            } 
            // Jika P di tengah
            else {
                next(prev(P)) = next(P);
                prev(next(P)) = prev(P);
            }
            P = next(P);
            Dealokasi(&temp);
        } 
        else {
            P = next(P);
        }
    }
}


/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L){
    //kamus lokal
    address P;
    
    //algoritma
    CreateList(L);
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }
    
    // Salin semua elemen dari L2
    P = First(L2);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2){
    //kamus lokal
    address P;
    int count, mid, i;

    //algoritma
    CreateList(L1);
    CreateList(L2);
    // Hitung jumlah elemen
    count = NbElm(L);
    // Tentukan titik tengah
    mid = (count + 1) / 2; // Pembulatan ke atas
    
    // Salin elemen ke L1 dan L2
    P = First(L);
    i = 1;
    while (P != NIL) {
        if (i <= mid) {
            InsertVLast(L1, info(P));
        } else {
            InsertVLast(L2, info(P));
        }
        P = next(P);
        i++;
    }
}


/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2){
    // kamus lokal
    address P;
    // algoritma
    CreateList(L2);
    // Salin semua elemen dari L1 ke L2
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L2, info(P));
        P = next(P);
    }
}