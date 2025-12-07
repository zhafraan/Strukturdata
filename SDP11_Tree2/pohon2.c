/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran*/
/* Tanggal : 4 Desember 2025*/

#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ){
    // Kamus lokal
    int i;
    // Algoritma
    if(!IsEmptyTree(P)) {
        printf("%c\n", info(P));
        if(!IsEmptyTree(Left(P)) || !IsEmptyTree(Right(P))){ 
                for(i=0; i<=H; i++) {
                    printf("  ");
                }
                PrintTreeInden(Left(P), H + 3);
                for(i=0; i<=H; i++) {
                    printf("  ");
                }
                PrintTreeInden(Right(P), H + 3);
            }
        }
    else {
        printf("()\n");
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
// void PrintLevel(bintree P, int N){
//      //kamus lokal
//     //algoritma
//     if (!IsEmptyTree(P)) {
//         if (N == 1) {
//             printf("%c ", info(P));
//         } 
//         else {
//             PrintLevel(left(P), N - 1);
//             PrintLevel(right(P), N - 1);
//         }
//     }
// }

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y){
    //Kamus lokal
    //Algoritma
    // algoritma
    if (!IsEmptyTree(*P)){
        if (info(*P) == X){ 
            info(*P) = Y;
        }
        if(!IsEmptyTree(GetLeft(*P))) {
            UpdateAllX(&left(*P), X, Y);
        }
        if(!IsEmptyTree(GetRight(*P))) {
            UpdateAllX(&right(*P), X, Y);
        }
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X){
    //Kamus lokal
    //Algoritma
    if(IsEmptyTree(*P)) {
        *P = AlokasiTree(X);
    }
    else {
        if(IsUnerRight(*P) || IsDaun(*P)){
            left(*P) = AlokasiTree(X);
        }
        else{
            AddDaunTerkiri(&left(*P), X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri){
    //Kamus lokal
    //Algoritma
    if(!IsEmptyTree(*P)) {
        if(info(*P) == X && IsDaun(*P)) {
            if(Kiri) {
                left(*P) = AlokasiTree(Y);
            }
            else {
                right(*P) = AlokasiTree(Y);
            }
        }
        else {
            if(!IsDaun(*P)) {
                if(SearchX(GetLeft(*P), X)) {
                    AddDaun(&left(*P), X, Y, Kiri);
                }
                else {
                    AddDaun(&right(*P), X, Y, Kiri);
                }
            }
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X){
    //Kamus lokal
    //Algoritma
    if(IsEmptyTree(*P)) {
        *P = AlokasiTree(X);
    }
    else if(IsDaun(*P)) {
        left(*P) = AlokasiTree(X);
    }
    else {
            if (nbelmtree(GetLeft(*P)) <= nbelmtree(GetRight(*P))){
                InsertX(&left(*P), X);
            }
            else{ 
                InsertX(&right(*P), X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X){
    // kamus lokal
    // algoritma
    if(!IsEmptyTree(*P)) {
        if(IsDaun(*P)) {
            *X = info(*P);
            DealokasiTree(P);
            *P = NIL;
        }
        else{
            if(Left(*P) != NIL) {
                DelDaunTerkiri(&left(*P), &X);
            }
            else {
                DelDaunTerkiri(&right(*P), &X);
            }
        }
    }

}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X){
    // kamus lokal
    // algoritma
    if (*P != NIL){
        if (info(*P) == X && IsDaun(*P)){
            DealokasiTree(*P);
            *P = NIL;
        }
        else{
            DelDaun(&left(*P), X);
            DelDaun(&right(*P), X);
        }
    }
}
/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X){
   if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            if (IsDaun(*P)) {
                // Node daun
                DealokasiTree(*P);
                *P = NIL;
            } 
            else if (IsUnerLeft(*P)) {
                //Hanya ada anak kiri
                *P = left(*P);
            } 
            else if (IsUnerRight(*P)) {
                //Hanya ada anak kanan
                *P = right(*P);
            } 
            else {
                // Ada dua anak - ganti dengan anak kiri
                *P = left(*P);
            }
        } 
        else {
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n){
    // Kamus lokal
    bintree P;
    infotype X;
    int nLeft, nRight;
    // Algoritma
    if (n <= 0) {
        return NIL;// Pohon kosong
    } 
    else {
        printf("Masukkan nilai node: ");
        scanf(" %c", &X);
        P = AlokasiTree(X);
        nLeft = n / 2;// Jumlah node di subpohon kiri
        nRight = n - nLeft - 1;// Jumlah node di subpohon kanan
        left(P) = BuildBalanceTree(nLeft);
        right(P) = BuildBalanceTree(nRight);
        return P;
    }

}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    // Kamus lokal
    int leftCount, rightCount, diff;
    // Algoritma
    if (IsEmptyTree(P)) {
        return true;
    } 
    else {
        // Hitung jumlah node di subpohon kiri dan kanan
        diff = nbelmtree(Left(P))- nbelmtree(Right(P));
        // Ambil nilai absolut dari selisih
        if (diff < 0) {
            diff = -diff;
        }
        // Cek keseimbangan pada subpohon kiri dan kanan
        if (diff <= 1 && IsBalanceTree(Left(P)) && IsBalanceTree(Right(P))) {
            return true;
        } 
        else {
            return false;
        }
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P){
    // Kamus lokal
    int maxLeft, maxRight,;
    // Algoritma
    if (IsEmptyTree(P)) {
        return '\0'; 
    } 
    else {
        maxLeft = maxTree(Left(P));
        maxRight = maxTree(Right(P));
        // Cek dengan anak kiri
        if (maxLeft > info(P)) {
           info(P) = maxLeft;
        }
        // Cek dengan anak kanan
        if (maxRight > info(P)) {
            info(P) = maxRight;
        }
        return info(P);
    }


}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P){
    // Kamus lokal
    int minLeft, minRight;
    // Algoritma
    if (IsEmptyTree(P)) {
        return '\0'; 
    } 
    else {
        minLeft = minTree(Left(P));
        minRight = minTree(Right(P));
        // Cek dengan anak kiri
        if (minLeft < info(P) && minLeft != '\0') {
           info(P) = minLeft;
        }
        // Cek dengan anak kanan
        if (minRight < info(P) && minRight != '\0') {
            info(P) = minRight;
        }
        return info(P);
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X){
    // Kamus lokal
    // Algoritma
    if (IsEmptyTree(P)) {
        return False;
    } 
    else {
        // Cek nilai pada node saat ini
        if (info(P) == X) {
            return True;
        } 
        else if (X < info(P)) // Cari di subpohon kiri
        {
            return BSearch(Left(P), X);
        } 
        else {// Cari di subpohon kanan
            return BSearch(Right(P), X);
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X){
    // Kamus lokal
    // Algoritma
    if (IsEmptyTree(P)) {
        return AlokasiTree(X);
    } 
    else {
        if (X < info(P)) {
            left(P) = InsSearch(Left(P), X);
        } 
        else {
            right(P) = InsSearch(Right(P), X);
        }
        return P;
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X){
    // Kamus lokal
    bintree temp;
    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (X < info(*P)) {
            DelBtree(&left(*P), X);
        } 
        else if (X > info(*P)) {
            DelBtree(&right(*P), X);
        } 
        else {
            if (IsDaun(*P)) {
                // Node daun
                DealokasiTree(*P);
                *P = NIL;
            } 
            else if (IsUnerLeft(*P)) {
                // Hanya ada anak kiri
                temp = *P;
                *P = left(*P);
                DealokasiTree(temp);
            } 
            else if (IsUnerRight(*P)) {
                // Hanya ada anak kanan
                temp = *P;
                *P = right(*P);
                DealokasiTree(temp);
            } 
            else {
                // Ada dua anak - cari pengganti dari subpohon kanan
                bintree successor = right(*P);
                while (!IsEmptyTree(left(successor))) {
                    successor = left(successor);
                }
                info(*P) = info(successor); // Ganti nilai dengan successor
                DelBtree(&right(*P), info(successor)); // Hapus successor
            }
        }
    }
}


