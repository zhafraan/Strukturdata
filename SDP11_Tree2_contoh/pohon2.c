
#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H)
{
    // Kamus lokal
    int i;

    // Algoritma
    if (!IsEmptyTree(P))
    {
        printf("%c\n", info(P));

        if (!IsEmptyTree(GetLeft(P)))
        {
            for (i = 1; i <= H; i++)
            {
                printf("  ");
            }
            PrintTreeInden(GetLeft(P), 2 * H);
        }

        if (!IsEmptyTree(GetRight(P)))
        {
            for (i = 1; i <= H; i++)
            {
                printf("  ");
            }
            PrintTreeInden(GetRight(P), 2 * H);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y)
{
    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (info(*P) == X)
        {
            info(*P) = Y;
        }

        if (!IsEmptyTree(GetLeft(*P)))
        {
            UpdateAllX(&left(*P), X, Y);
        }

        if (!IsEmptyTree(GetRight(*P)))
        {
            UpdateAllX(&right(*P), X, Y);
        }
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        if (IsEmptyTree(GetLeft(P)))
        {
            left(P) = Tree(X, NIL, NIL);
        }
        else
        {
            AddDaunTerkiri(GetLeft(P), X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        if (info(P) == X && IsDaun(P))
        {
            if (Kiri)
            {
                left(P) = Tree(Y, NIL, NIL);
            }
            else
            {
                right(P) = Tree(Y, NIL, NIL);
            }
        }
        else
        {
            if (!IsEmptyTree(GetLeft(P)))
            {
                AddDaun(GetLeft(P), X, Y, Kiri);
            }
            if (!IsEmptyTree(GetRight(P)))
            {
                AddDaun(GetRight(P), X, Y, Kiri);
            }
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X)
{
    // algoritma
    if (IsEmptyTree(*P))
    {
        *P = Tree(X, NIL, NIL);
    }
    else
    {
        if (IsEmptyTree(GetLeft(*P)))
        {
            left(*P) = Tree(X, NIL, NIL);
        }
        else if (IsEmptyTree(GetRight(*P)))
        {
            right(*P) = Tree(X, NIL, NIL);
        }
        else
        {
            InsertX(&left(*P), X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype X)
{
    // kamus lokal
    bintree temp;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (IsDaun(*P))
        {
            X = info(*P);
            temp = *P;
            *P = NIL;
            DealokasiTree(&temp);
        }
        else if (!IsEmptyTree(GetLeft(*P)))
        {
            if (IsDaun(GetLeft(*P)))
            {
                X = info(GetLeft(*P));
                temp = GetLeft(*P);
                left(*P) = NIL;
                DealokasiTree(&temp);
            }
            else
            {
                DelDaunTerkiri(&left(*P), X);
            }
        }
        else if (!IsEmptyTree(GetRight(*P)))
        {
            DelDaunTerkiri(&right(*P), X);
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X)
{
    // kamus lokal
    // algoritma
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X)
{
    // kamus lokal
    // algoritma
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n)
{
    // kamus lokal
    // algoritma
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P)
{
    // kamus lokal
    // algoritma
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P)
{
    // kamus lokal
    // algoritma
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P)
{
    // kamus lokal
    // algoritma
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X)
{
    // kamus lokal
    // algoritma
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X)
{
    // kamus lokal
    // algoritma
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X)
{
    // kamus lokal
    // algoritma
}
