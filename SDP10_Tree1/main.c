/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran*/
/* Tanggal : 28 November 2025*/

#include "pohon1.c"
int main(){
     //kamus
     bintree B,C;
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

     //PrintPrefix
     printf("POHON B:\n ");
     PrintPrefix(B);
     printf("\n");
     printf("POHON C:\n");
     PrintPrefix(C);
     printf("\n");
     //GetLeft
     printf("\nGetLeft & GetRight\n");
     printf("GetLeft dari akar T adalah :");
     PrintPrefix(GetLeft(B));
     //GetRight
     printf("\nGetRight dari akar T adalah :");
     PrintPrefix(GetRight(B));
     printf("\n");
     //IsEmptyTree
     printf("\nIsEmptyTree\n");
     printf("Apakah pohon B kosong? %s\n", IsEmptyTree(B) ? "Ya" : "Tidak");
     printf("\n");
     //IsDaun
     printf("\nIsDaun & IsBiner\n");
     printf("Apakah akar T adalah daun? %s\n", IsDaun(B) ? "Ya" : "Tidak");
     //IsBiner
     printf("Apakah pohon B adalah biner? %s\n", IsBiner(B) ? "Ya" : "Tidak");
     printf("\n");
     //IsunerLeft
     printf("\nIsunerLeft & IsUnerRight\n");
     printf("Apakah pohon B adalah uner left? %s\n", IsUnerLeft(B) ? "Ya" : "Tidak");
     printf("Apakah pohon C adalah uner left? %s\n", IsUnerLeft(C) ? "Ya" : "Tidak");
     //IsUnerRight
     printf("Apakah pohon B adalah uner right? %s\n", IsUnerRight(B) ? "Ya" : "Tidak");
     printf("Apakah pohon C adalah uner right? %s\n", IsUnerRight(C) ? "Ya" : "Tidak");
     printf("\n");
     //NbElm
     printf("\nNbElm & NbDaun\n");
     printf("Banyaknya elemen pada pohon B adalah : %d\n", NbElm(B));
     //NbDaun
     printf("Banyaknya daun pada pohon B adalah : %d\n", NbDaun(B));
     printf("\n");
     //Tinggi
     printf("\nTinggi\n");
     printf("Tinggi pohon B adalah : %d\n", Tinggi(B));
     printf("Tinggi pohon C adalah : %d\n", Tinggi(C));
     printf("\n");
     //SearchX
     printf("\nSearchX\n");
     printf("Mencari huruf A dalam pohon B:\n");
     SearchX(B, 'A');
     printf("Hasil pencarian huruf A: %s\n",SearchX(B,'A') ? "DITEMUKAN" : "TIDAK DITEMUKAN");
     printf("\n");
     //UpdateX
     printf("\nUpdateX\n");
     printf("Update A menjadi Z :\n");
     UpdateX(&C, 'A', 'Z');
     printf("Setelah UpdateX, pohon C menjadi: ");
     PrintPrefix(C);
     printf("\n");
     //SOAL TAMBAHAN
     printf("\nCountX\n");
     //CountX
     printf("Banyaknya kemunculan huruf A pada pohon B adalah : %d\n", CountX(B, 'A'));
     printf("\n");
     //IsSkewLeft
     printf("\nIsSkew\n");
     printf("Apakah pohon C adalah pohon condong kiri? %s\n", IsSkewLeft(C) ? "Ya" : "Tidak");
     //IsSkewRight
     printf("Apakah pohon B adalah pohon condong kanan? %s\n", IsSkewRight(B) ? "Ya" : "Tidak");
     printf("\n");
     //PrintPrefixRingkas
     printf("PrintPrefixRingkas pohon B adalah : \n");
     PrintPrefixRingkas(B);
     printf("\n");
     //LevelX
     printf("\nLevelX\n");
     printf("Level dari huruf K pada pohon B adalah : %d\n", LevelX(B, 'K'));
     printf("Level dari huruf R pada pohon B adalah : %d\n", LevelX(B, 'R'));
     printf("Level dari huruf T pada pohon B adalah : %d\n", LevelX(B, 'T'));
     printf("\n");
     //Countlevel
     printf("\nCountLevel\n");
     printf("Banyaknya node pada level 1 di pohon B adalah : %d\n", CountLevel(B, 1));
     printf("Banyaknya node pada level 2 di pohon B adalah : %d\n", CountLevel(B, 2));
     printf("Banyaknya node pada level 3 di pohon B adalah : %d\n", CountLevel(B, 3));
     printf("Banyaknya node pada level 4 di pohon B adalah : %d\n", CountLevel(B, 4));
     printf("Banyaknya node pada level 5 di pohon B adalah : %d\n", CountLevel(B, 5));
     printf("\n");
     //PrintLevel
     printf("\nPrintLevel\n");
     printf("PrintLevel pohon B pada level 2 adalah : ");
     PrintLevel(B, 2);
     printf("\n");
     printf("PrintLevel pohon B pada level 3 adalah : ");
     PrintLevel(B, 3);
     printf("\n");
     //GetDaunTerkiri
     printf("\nGetDaunTerkiri\n");
     printf("Daun terkiri pada pohon B adalah : %c\n", GetDaunTerkiri(B));
     printf("Daun terkiri pada pohon C adalah : %c\n", GetDaunTerkiri(C));
     printf("\n");
     //FrekuensiX
     printf("\nFrekuensi\n");
     printf("Pohon B\n");
     PrintPrefixRingkas(B);
     printf("\nFrekuensi kemunculan huruf A pada pohon B adalah : %.2f\n", FrekuensiX(B, 'A'));
     printf("Frekuensi kemunculan huruf T pada pohon B adalah : %.2f\n", FrekuensiX(B, 'T'));
     printf("\n");
     //Countvocal
     printf("\nVocal\n");
     printf("Pohon B\n");
     PrintPrefixRingkas(B);
     printf("\nBanyaknya kemunculan huruf vokal pada pohon B adalah : %d\n", CountVocal(B));
     //PrintVocal
     printf("Huruf vokal pada pohon B adalah : ");
     PrintVocal(B);
     printf("\n");
     //CountConsonant
     printf("\nConsonant\n");
     printf("Pohon B\n");
     PrintPrefixRingkas(B);
     printf("\nBanyaknya kemunculan huruf konsonan pada pohon B adalah : %d\n", CountConsonant(B));
     //PrintConsonant
     printf("Huruf konsonan pada pohon B adalah : ");
     PrintConsonant(B);
     printf("\n");
     //Modus
     printf("\nModus\n");
     printf("Pohon B\n");
     PrintPrefixRingkas(B);
     printf("\nModus pada pohon B adalah : %c\n", Modus(B));
     printf("Pohon C\n");
     PrintPrefixRingkas(C);
     printf("\nModus pada pohon C adalah : %c\n", Modus(C));
     printf("\n");
    return 0;
}
