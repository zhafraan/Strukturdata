/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140161 - Azka Wayasy Al Hafizh*/
/* Tanggal : 3 Desember 2025 */

#include "pohon2.h"

int main()
{ // kamus
     bintree B, A;
     // algirtma
     B = Tree('T',
              Tree('I',
                   Tree('N', NIL, NIL),
                   Tree('F',
                        Tree('O', NIL, NIL),
                        NIL)),
              Tree('R',
                   Tree('M',
                        Tree('A', NIL, NIL),
                        Tree('T', NIL, NIL)),
                   Tree('I',
                        NIL,
                        Tree('K',
                             NIL,
                             Tree('A', NIL, NIL)))));

     PrintTreeInden(B, 1);
     printf("\n");
     printf("Update All T to X:\n");
     UpdateAllX(&B, 'T', 'X');
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Add Daun Terkiri with Z:\n");
     AddDaunTerkiri(B, 'Z');
     printf("\n");
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Add Daun Y to Daun F di kanan:\n");
     AddDaun(B, 'F', 'Y', FALSE);
     printf("\n");
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Insert X:\n");
     InsertX(&B, 'X');
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Delete Daun Terkiri:\n");
     DelDaunTerkiri(&B, 'X');
     PrintTreeInden(B, 1);
     printf("\n");
     return 0;
}
