/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama :24060124140161 - Azka Wayasy Al Hafizh */
/* Tanggal : 26 November 2025*/

#include "pohon1.h"

bintree AlokasiTree(infotype E)
{
    // kamus lokal
    bintree P;
    // algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL)
    {
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
void DealokasiTree(bintree *P)
{
    // algoritma
    free(*P);
    *P = NIL;
}

bintree Tree(infotype akar, bintree left, bintree right)
{
    // kamus lokal
    bintree P;
    // algoritma
    P = AlokasiTree(akar);
    if (P != NIL)
    {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan info/akar dari pohon biner P }*/
infotype GetAkar(bintree P)
{
    return info(P);
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P)
{
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P)
{
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree(bintree P)
{
    return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P)
{
    // kamus lokal
    // algoritma
    if (P != NIL)
    {
        return (left(P) == NIL) && (right(P) == NIL);
    }
    else
    {
        return FALSE;
    }
}

/* function IsBiner (P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P)
{
    // kamus lokal
    // algoritma
    if (P != NIL)
    {
        return (left(P) != NIL) && (right(P) != NIL);
    }
    else
    {
        return FALSE;
    }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P)
{
    // kamus lokal
    // algoritma
    if (P != NIL)
    {
        return (left(P) != NIL) && (right(P) == NIL);
    }
    else
    {
        return FALSE;
    }
}

/* function IsUnerRight(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P)
{
    // kamus lokal
    // algoritma
    if (P != NIL)
    {
        return (left(P) == NIL) && (right(P) != NIL);
    }
    else
    {
        return FALSE;
    }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        printf("()");
    }
    else
    {
        printf("%c(", info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P)
{
    // kamus lokal
    int count;
    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        count = 1 + NbElm(left(P)) + NbElm(right(P));
        return count;
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P)
{
    // kamus lokal
    int count;
    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else if (IsDaun(P))
    {
        return 1;
    }
    else
    {
        count = NbDaun(left(P)) + NbDaun(right(P));
        return count;
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P)
{
    // kamus lokal
    int heightLeft, heightRight;
    // algoritma
    if (P != NIL)
    {
        heightLeft = Tinggi(left(P));
        heightRight = Tinggi(right(P));
        return 1 + max2(heightLeft, heightRight);
    }
    else
    {
        return -1;
    }
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X)
{
    // kamus lokal
    // algoritma
    if (P == NIL)
    {
        return FALSE;
    }
    else if (info(P) == X)
    {
        return TRUE;
    }
    else
    {
        return SearchX(left(P), X) || SearchX(right(P), X);
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y)
{
    // kamus lokal
    // algoritma
    if (*P != NIL)
    {
        if (info(*P) == X)
        {
            info(*P) = Y;
        }
        UpdateX(&left(*P), X, Y);
        UpdateX(&right(*P), X, Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X)
{
    // kamus lokal
    int count;
    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        count = (info(P) == X ? 1 : 0) + CountX(left(P), X) + CountX(right(P), X);
        return count;
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft(bintree P)
{
    // kamus lokal

    // algoritma
    while (P != NIL)

    {
        if (right(P) != NIL)
        {
            return FALSE;
        }
        P = left(P);
    }
    return TRUE;
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight(bintree P)
{
    // kamus lokal

    // algoritma
    while (P != NIL)

    {
        if (left(P) != NIL)
        {
            return FALSE;
        }
        P = right(P);
    }
    return TRUE;
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        printf("()");
    }
    else if (IsDaun(P))
    {
        printf("%c", info(P));
    }
    else
    {
        printf("%c(", info(P));
        PrintPrefixRingkas(left(P));
        printf(",");
        PrintPrefixRingkas(right(P));
        printf(")");
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X)
{
    // kamus lokal
    int levelLeft, levelRight;
    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else if (info(P) == X)
    {
        return 1;
    }
    else
    {
        levelLeft = LevelX(left(P), X);
        levelRight = LevelX(right(P), X);
        if (levelLeft != 0)
        {
            return levelLeft + 1;
        }
        else if (levelRight != 0)
        {
            return levelRight + 1;
        }
        else
        {
            return 0;
        }
    }
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T)
{
    // kamus lokal
    int count;
    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else if (T == 1)
    {
        return 1;
    }
    else
    {
        count = CountLevel(left(P), T - 1) + CountLevel(right(P), T - 1);
        return count;
    }
}

/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N)
{
    // kamus lokal

    // algoritma
    if (P != NIL)
    {
        if (N == 1)
        {
            printf("%c ", info(P));
        }
        else
        {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P)
{
    // kamus lokal
    // algoritma
    if (P == NIL)
    {
        return '#';
    }
    else if (IsDaun(P))
    {
        return info(P);
    }
    else
    {
        return GetDaunTerkiri(left(P));
    }
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X)
{
    // kamus lokal
    int countX;
    int total;
    float ratio;
    // algoritma
    total = NbElm(P);
    if (total == 0)
    {
        return 0.0;
    }
    else
    {
        countX = CountX(P, X);
        ratio = (float)countX / (float)total;
        return ratio;
    }
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P)
{
    // kamus lokal
    int count;
    char c;
    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        c = info(P);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count = 1 + CountVocal(left(P)) + CountVocal(right(P));
        }
        else
        {
            count = CountVocal(left(P)) + CountVocal(right(P));
        }
        return count;
    }
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P)
{
    // kamus lokal
    char c;
    // algoritma
    if (P != NIL)
    {
        c = info(P);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            printf("%c ", c);
        }
        PrintVocal(left(P));
        PrintVocal(right(P));
    }
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P)
{
    // kamus lokal
    int count;
    char c;
    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        c = info(P);
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (!(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
            {
                count = 1 + CountConsonant(left(P)) + CountConsonant(right(P));
            }
            else
            {
                count = CountConsonant(left(P)) + CountConsonant(right(P));
            }
        }
        else
        {
            count = CountConsonant(left(P)) + CountConsonant(right(P));
        }
        return count;
    }
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P)
{
    // kamus lokal
    char c;
    // algoritma
    if (P != NIL)
    {
        c = info(P);
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (!(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
            {
                printf("%c ", c);
            }
        }
        PrintConsonant(left(P));
        PrintConsonant(right(P));
    }
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P)
{
    // Kamus lokal
    infotype temp;
    int Count;
    char modus;

    // algoritma
    if (!IsEmptyTree(P))
    {
        temp = info(P);
        Count = CountX(P, temp);
        modus = temp;
        // Cek modus dari kiri
        if (!IsEmptyTree(GetLeft(P)))
        {
            temp = Modus(GetLeft(P));
            if (temp != '#')
            {
                if (CountX(P, temp) > Count)
                {
                    modus = temp;
                    Count = CountX(P, temp);
                }
            }
        }
        // Cek modus dari kanan
        if (!IsEmptyTree(GetRight(P)))
        {
            temp = Modus(GetRight(P));
            if (temp != '#')
            {
                if (CountX(P, temp) > Count)
                {
                    modus = temp;
                    Count = CountX(P, temp);
                }
            }
        }
        if (Count == 1)
        {
            return '#';
        }

        return modus;
    }
    else
    {
        return '#';
    }
}