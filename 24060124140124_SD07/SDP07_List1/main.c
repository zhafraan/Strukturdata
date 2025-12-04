/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran*/
/* Tanggal : 9 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.c"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  List1 Senarai;
  List1 L2, L3, L4, L5, L6;
  infotype V;
  //algoritma
  
  //aplikasi tipe address
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List1
  Senarai.First = B; //First(Senarai) = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL) {
	  printf("\t%c",info(P));
	  P = next(P);
  }
  printf("\n");

  //Create list & isempty
  CreateList(&Senarai);
  printf("List Senarai dibuat.\n");
  printf("Apakah list kosong? %s\n", IsEmptyList(Senarai) ? "Ya" : "Tidak");

  //InsertVFirst
  InsertVFirst(&Senarai, 'A');
  InsertVFirst(&Senarai, 'B');
  InsertVFirst(&Senarai, 'C');
  InsertVFirst(&Senarai, 'D');
  InsertVFirst(&Senarai, 'E');
  printf("Setelah InsertVFirst, isi Senarai :");
  //PrintList
  PrintList(Senarai);
  //NbElement
  printf("\njumlah elemen = %d", NbElm(Senarai));
  printf("\n");

  //InsertVLast
  InsertVLast(&Senarai, 'H');
  InsertVLast(&Senarai, 'G');
  InsertVLast(&Senarai, 'F');
  printf("Setelah InsertVLast, isi Senarai :");
  PrintList(Senarai);
  printf("\njumlah elemen = %d", NbElm(Senarai));
  printf("\n");

  //DeleteVFirst
  DeleteVFirst(&Senarai, &V);
  printf("Elemen yang dihapus: %c", V);
  printf("\nList setelah DeleteVFirst:");
  PrintList(Senarai);
  printf("\n");

  //DeleteVLast
  DeleteVLast(&Senarai, &V);
  printf("\nElemen yang dihapus: %c", V);
  printf("\nList setelah DeleteVLast:");
  PrintList(Senarai);
  printf("\n");

  //SearchX
  SearchX(Senarai, 'D', &A);
  printf("Mencari 'D': %s\n", A!= NIL ? "DITEMUKAN" : "TIDAK DITEMUKAN");
  SearchX(Senarai, 'X', &A);
  printf("Mencari 'X': %s\n", A!= NIL ? "DITEMUKAN" : "TIDAK DITEMUKAN");
  printf("\n");
  
 //UpdateX
  UpdateX(&Senarai, 'H', 'Z');
  printf("Setelah UpdateX , isi Senarai :");
  PrintList(Senarai);
  printf("\n");

 //Invers
  Invers(&Senarai);
  printf("Setelah Invers , isi Senarai :");
  PrintList(Senarai);
  printf("\n");

  //CountVocal
  InsertVLast(&Senarai, 'I');
  InsertVLast(&Senarai, 'U');
  int jumlahVokal = CountVocal(Senarai);
  printf("Jumlah huruf vokal dalam list: %d\n", jumlahVokal);
  printf("\n");

  //CountX
   InsertVLast(&Senarai, 'A');
  int jumlahX = CountX(Senarai, 'A');
  printf("Jumlah kemunculan 'A' dalam list: %d\n", jumlahX);
  printf("\n");

  //FrekuensiX
  float frekuensiX = FrekuensiX(Senarai, 'A');
  printf("Frekuensi kemunculan 'A' dalam list: %.2f\n", frekuensiX);
  printf("\n");

  //SearchAllX
  PrintList(Senarai);
  SearchAllX(Senarai, 'A');
  printf("\n");

  //UpdateAllX
  UpdateAllX(&Senarai, 'A', 'X');
  printf("Setelah UpdateAllX , isi Senarai :");
  PrintList(Senarai);
  printf("\n");

  //InsertVAfter
  InsertVAfter(&Senarai, 'X', 'Y');
  printf("Setelah InsertVAfter , isi Senarai :");
  PrintList(Senarai);
  printf("\njumlah elemen = %d", NbElm(Senarai));
  printf("\n");

  //Modus
  PrintList(Senarai);
  printf("\nModus: %c", Modus(Senarai));
  //NbModus
  printf("\nNbModus: %d", NbModus(Senarai));
  printf("\n");

  //ConcatList
  CreateList(&L2);
  InsertVLast(&L2, 'P');
  InsertVLast(&L2, 'Q');
  ConcatList(Senarai, L2, &L3);
  printf("\nSetelah ConcatList , isi Senarai L3 :");
  PrintList(L3);
  printf("\n");

  //SplitList
  SplitList(L3, &L4, &L5);
  printf("\nSetelah SplitList , isi Senarai L4 :");
  PrintList(L4);
  printf("\n");
  printf("Setelah SplitList , isi Senarai L5 :");
  PrintList(L5);
  printf("\n");

  //CopyList
  PrintList(Senarai);
  CopyList(Senarai, &L6);
  printf("\nSetelah CopyList , isi Senarai L6 :");
  PrintList(L6);
  printf("\n");


  return 0;
}
