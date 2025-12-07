/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran*/
/* Tanggal : 28 November 2025*/

#include "pohon1.h"
/* function AlokasiTree( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree AlokasiTree(infotype E) {
    //kamus lokal
    bintree P;
    //algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}

/* procedure DealokasiTree (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void DealokasiTree (bintree *P) {
    //kamus lokal
    //algoritma
    if (*P != NIL) {
        free(*P);
        *P = NIL;
    }
}
/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
/*representasi logik fungsi*/
bintree Tree (infotype akar, bintree left, bintree right) {
    //kamus lokal
    bintree P;
    //algoritma
    P = AlokasiTree(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
    }
    return P;
}
/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P){
    //algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
    //algoritma
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P){
    //algoritma
    return (P == NIL);
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        return (left(P) == NIL && right(P) == NIL);
    } 
    else {
        return False;
    }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        return (left(P) != NIL && right(P) != NIL);
    } 
    else {
        return False;
    }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        return (left(P) != NIL && right(P) == NIL);
    } 
    else {
        return False;
    }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        return (left(P) == NIL && right(P) != NIL);
    } 
    else {
        return False;
    }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
    //kamus lokal
    //algoritma 
    if (P == NIL) {
        printf("()");
    } 
    else {
        printf("%c(",info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}
/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
        return 1 + NbElm(left(P)) + NbElm(right(P));
    } 
    else {
        return 0;
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } 
    else if (IsDaun(P)) {
        return 1;
    } 
    else {
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b){
    //kamus lokal
    //algoritma
    if (a > b) {
        return a;
    } 
    else {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return -1;
    } 
    else if (IsDaun(P)) {
        return 0; 
    }
    else {
        return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return False;
    } 
    else {
        if (info(P) == X) {
            return True;
        } 
        else {
            return (SearchX(left(P), X) || SearchX(right(P), X));
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            info(*P) = Y;
        }
        UpdateX(&left(*P), X, Y);
        UpdateX(&right(*P), X, Y);
    }
}
/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X){
    //kamus lokal
    int countL,countR;
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } 
    else {
        countL = CountX(left(P), X);
        countR = CountX(right(P), X);
        if (info(P) == X) {
            return 1 + countL + countR;
        } 
        else {
            return countL + countR;
        }
    }

}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P){
    //Kamus lokal
    //algoritma
    if (IsEmptyTree(P) || IsDaun(P)) {
        return True;
    }
    else if (right(P) != NIL) {
        return False;
    }
    else {
        return IsSkewLeft(left(P));
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P){
    //Kamus lokal
    //algoritma
    if (IsEmptyTree(P) || IsDaun(P)) {
        return True;
    }
    else if (left(P) != NIL) {
        return False;
    }
    else {
        return IsSkewRight(right(P));
    }
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P){
    //Kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
        printf("%c", info(P));
        if (!IsDaun(P)) {
            printf("(");
            if (left(P) != NIL) {
                PrintPrefixRingkas(left(P));
            }
            if (right(P) != NIL) {
                if (left(P) != NIL) {
                    printf(",");
                }
                PrintPrefixRingkas(right(P));
            }
            printf(")");
        }
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X){
    //kamus lokal
    int leftLevel,rightLevel;
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } 
    else if (info(P) == X) {
        return 1;
    } 
    else {
        leftLevel = LevelX(left(P), X);
        if (leftLevel != 0) {
            return 1 + leftLevel;
        } else {
            rightLevel = LevelX(right(P), X);
            if (rightLevel != 0) {
                return 1 + rightLevel;
            } else {
                return 0;
            }
        }
    }
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } 
    else if (T == 1) {
        return 1;
    } 
    else {
        return CountLevel(left(P), T - 1) + CountLevel(right(P), T - 1);
    }
}
/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
        if (N == 1) {
            printf("%c ", info(P));
        } 
        else {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}
/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P){
    //kamus lokal
    //algoritma
    if(IsEmptyTree(P)) {
        return '#';
    } 
    else if (IsDaun(P)) {
        return info(P);
    } 
    else if (left(P) != NIL) {
        return GetDaunTerkiri(left(P));
    }
    else {
        return GetDaunTerkiri(right(P));
    }
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X){
    //kamus lokal
    int countX, totalElm;
    float frequency;
    //algoritma
    totalElm = NbElm(P);
    if (totalElm == 0) {
        return 0.0;
    } 
    else {
        countX = CountX(P, X);
        frequency = (float)countX / (float)totalElm;
        return frequency;
    }
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P){
    //kamus lokal
    int countLeft, countRight;
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } 
    else {
        countLeft = CountVocal(left(P));
        countRight = CountVocal(right(P));
        if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O' ||
            info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
            return 1 + countLeft + countRight;
        } 
        else {
            return countLeft + countRight;
        }
    }
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
        if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O' ||
            info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
            printf("%c ", info(P));
        }
        PrintVocal(left(P));
        PrintVocal(right(P));
    }
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P){
    //kamus lokal
    int countL, countR;
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } 
    else {
        countL = CountConsonant(left(P));
        countR = CountConsonant(right(P));
        if ((info(P) >= 'A' && info(P) <= 'Z' && !(info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O')) ||
            (info(P) >= 'a' && info(P) <= 'z' && !(info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o'))) {
            return 1 + countL + countR;
        } 
        else {
            return countL + countR;
        }
    }
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
        if ((info(P) >= 'A' && info(P) <= 'Z' && !(info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O')) ||
            (info(P) >= 'a' && info(P) <= 'z' && !(info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o'))) {
            printf("%c ", info(P));
        }
        PrintConsonant(left(P));
        PrintConsonant(right(P));
    }
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P){
    // Kamus lokal
    infotype temp;
    int Count;
    char modus;
    
    // algoritma
    if(!IsEmptyTree(P)){
        temp = info(P);
        Count = CountX(P, temp);
        modus = temp;
        // Cek modus dari kiri
        if(!IsEmptyTree(GetLeft(P))){
            temp = Modus(GetLeft(P));
            if(temp != '#'){
                if(CountX(P, temp) > Count){
                    modus = temp;
                    Count = CountX(P, temp);
                }
            }
        }
        // Cek modus dari kanan
        if(!IsEmptyTree(GetRight(P))){
            temp = Modus(GetRight(P));
            if(temp != '#'){  
                if(CountX(P, temp) > Count){
                    modus = temp;
                    Count = CountX(P, temp);
                }
            }
        }
        if(Count == 1){
            return '#';
        }

        return modus;
    }
    else{
        return '#';
    }
}
