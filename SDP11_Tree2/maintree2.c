/* File : maintree2.c */
/* Deskripsi : driver ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran*/
/* Tanggal :  7 Desember 2025*/

#include <stdio.h>
#include "pohon2.h"
#include "pohon1.h"

int main(){
     //kamus
     bintree B, C, BST;
     infotype X;

     //algoritma
     B = Tree('T',
             Tree('I',
                  Tree('N',NIL,NIL),
                  Tree('F',
                       Tree('O',NIL,NIL),
                       NIL)),
             Tree('R',
                  Tree('M',
                       Tree('A',NIL,NIL),
                       Tree('T',NIL,NIL)),
                  Tree('I',
                       NIL,
                       Tree('K',
                            NIL,
                            Tree('A',NIL,NIL))))
            );

     C = Tree('A',
         Tree('B',
              Tree('C',
                   Tree('D',
                        Tree('E', NIL, NIL),
                        NIL),
                   NIL),
              NIL),
         NIL);

     printf("POHON B (Prefix):\n");
     PrintPrefix(B);
     printf("\n");

     printf("POHON C (Prefix):\n");
     PrintPrefix(C);
     printf("\n");

     // PrintTreeInden
     printf("\nPrintTreeInden Pohon B:\n");
     PrintTreeInden(B, 0);

     // UpdateAllX
     printf("\nUpdateAllX (A menjadi Z) pada Pohon B:\n");
     UpdateAllX(&B, 'A', 'Z');
     PrintPrefix(B);
     printf("\n");

     // AddDaunTerkiri
     printf("\nAddDaunTerkiri (X) ke Pohon C:\n");
     AddDaunTerkiri(&C, 'X');
     PrintPrefix(C);
     printf("\n");

     // AddDaun
     printf("\nAddDaun (Tambah Y di daun X kiri):\n");
     AddDaun(&C, 'X', 'Y', True);
     PrintPrefix(C);
     printf("\n");

     // InsertX
     printf("\nInsertX ke Pohon C (huruf Q):\n");
     InsertX(&C, 'Q');
     PrintPrefix(C);
     printf("\n");

     // DelDaunTerkiri
     printf("\nDelDaunTerkiri Pohon C:\n");
     DelDaunTerkiri(&C, &X);
     printf("Daun terhapus: %c\n", X);
     PrintPrefix(C);
     printf("\n");

     // DelDaun
     printf("\nDelDaun (hapus Q) Pohon C:\n");
     DelDaun(&C, 'Q');
     PrintPrefix(C);
     printf("\n");

     // DeleteX
     printf("\nDeleteX (hapus C) Pohon C:\n");
     DeleteX(&C, 'C');
     PrintPrefix(C);
     printf("\n");

     // BuildBalanceTree
     printf("\nBuildBalanceTree (5 node):\n");
     bintree D = BuildBalanceTree(5);
     PrintPrefix(D);
     printf("\n");
     PrintTreeInden(D, 0);

     // IsBalanceTree
     printf("\nIsBalanceTree\n");
     printf("Apakah pohon D seimbang? %s\n", IsBalanceTree(D) ? "Ya" : "Tidak");

     // maxTree & minTree
     printf("\nmaxTree & minTree\n");
     printf("Nilai maksimal pohon B : %c\n", maxTree(B));
     printf("Nilai minimal pohon B  : %c\n", minTree(B));

     // Binary Search Tree
     printf("\n=== Binary Search Tree ===\n");
     BST = NIL;
     BST = InsSearch(BST, 'M');
     BST = InsSearch(BST, 'D');
     BST = InsSearch(BST, 'R');
     BST = InsSearch(BST, 'A');
     BST = InsSearch(BST, 'Z');

     printf("BST Prefix:\n");
     PrintPrefix(BST);
     printf("\n");

     printf("\nBSearch huruf A: %s\n", BSearch(BST, 'A') ? "DITEMUKAN" : "TIDAK DITEMUKAN");
     printf("BSearch huruf X: %s\n", BSearch(BST, 'X') ? "DITEMUKAN" : "TIDAK DITEMUKAN");

     // DelBtree
     printf("\nDelBtree (hapus D):\n");
     DelBtree(&BST, 'D');
     PrintPrefix(BST);
     printf("\n");

     return 0;
}