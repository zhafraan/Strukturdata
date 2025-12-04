#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
#include "boolean.h"
/*********************************************************/
/* Program   : tabel.c */
/* Deskripsi : realisasi body modul Tabel */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/* Tanggal   : 11 September 2025*/
/*********************************************************/

/************************KONSTRUKTOR*************************/				 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T){
    (*T).size = 0;
    for (int i=1; i<= (*T).size ; i++) {
    (*T).wadah[i] = ' ';
    }
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T){
    return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T){
    return getSize(T) == 0;
}

/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T){
    return getSize(T)== 10;
}


/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos){
    int i = 1;
    *pos = -999;

    while (i <= T.size && *pos == -999) {
        if (T.wadah[i] == x) {
            *pos = i;
        }
        i++;
    }
}
/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x){
    int count = 0;
    for(int i = 1; i <= getSize(T); i++){
        if(T.wadah[i] == x){
            count++;
        }
    }
    return count;
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T){
    int count = 0;
    
    for(int i = 0;i<=getSize(T);i++){
        char a = T.wadah[i];
        if(a == 'A'|| a =='I' || a == 'U' || a == 'O' || a == 'E'){
            count++;
        }

    }
    return count;
}


/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x){
    if (!isFullTable(*T)) {       
        (*T).size++;
        (*T).wadah[(*T).size] = x;
    }
}


/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x) {
    int pos;
    searchX(*T, x, &pos);  
    
    if (pos == -999 && isFullTable(*T) == false) {  
       addXTable(T, x);
    }
}


/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x){ 
    int pos;
    int i;
    searchX(*T, x, &pos);

    if (pos != -999) {
        for (i = pos; i < (*T).size; i++) {
            (*T).wadah[i] = (*T).wadah[i + 1];
        }
        (*T).wadah[(*T).size] = ' ';
        (*T).size--;
    }
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx){
    int i;
    if (idx >= 1 && idx <= (*T).size && isEmptyTable(*T) == false) {
        for (i = idx; i < (*T).size; i++) {
            (*T).wadah[i] = (*T).wadah[i + 1];
        }
        (*T).wadah[(*T).size] = ' ';
        (*T).size--;
    }
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x){
    int i = 1;
    while (i <= (*T).size) {
        if ((*T).wadah[i] == x) 
            {
                delTable(T, i);
            } 
        else
            { i++;
        }
    }
}


/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T){
    int i;
    printf("[");
    if(T.size <= 0 && T.size <= 10){
        for (i = 1; i <= T.size; i++) {
            printf("%c", T.wadah[i]);
            if (i < T.size) {
            printf(",");
        }
    }
}
    printf("]\n");
}


/* procedure viewTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T){
    int i;
    printf("[");
    for (i = 1; i <= T.size; i++) {
        printf("%c", T.wadah[i]);
        if (i < T.size) {
            printf(",");
        }
    }
    printf("]\n");
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N){
    int i;
    char input;
    createTable(T);
    
    printf("Masukkan %d karakter:\n", N);
    for (i = 1; i <= N; i++) {
        printf("Masukkan Karakter ke-%d: ", i);
        scanf(" %c", &input);
        addXTable(T, input);
    }
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus(Tabel T){
    int i;
    int Max = 0;
    int Count;
    char modus = ' ';
    
    if (isEmptyTable(T)) {
        return ' '; 
    }

    for (i = 1; i <= T.size; i++) {
        Count = countX(T, T.wadah[i]);
        if (Count > Max) {
            Max = Count;
            modus = T.wadah[i];
        }
    }
    return modus;
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean 
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2) {
    int i;
    boolean equal = true;
    
    if (T1.size != T2.size) {
        return false;
    }
    
    i = 1;
    while (i <= T1.size && equal == true) {
        if (T1.wadah[i] != T2.wadah[i]) {
            equal = false;
        }
        i++;
    }
    
    return equal;
}



/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel 
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T) {
    Tabel result;
    createTable(&result);
    result.size = T.size;

    for (int i = 1; i <= T.size; i++) {
        result.wadah[i] = T.wadah[T.size - i + 1];
    }
    
    return result;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T) {
    int i;
    char temp;
    for (i = 1; i <= (*T).size / 2; i++) {
        temp = (*T).wadah[i];
        (*T).wadah[i] = (*T).wadah[(*T).size - i + 1];
        (*T).wadah[(*T).size - i + 1] = temp;
    }
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T){
    int i;
    int j;
    char temp;
    
    for (i = 1; i <= (*T).size - 1; i++) {
        for (j = i + 1; j <= (*T).size; j++) {
            if ((*T).wadah[i] > (*T).wadah[j]) {
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[j];
                (*T).wadah[j] = temp;
            }
        }
    }
}

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T){
    int i;
    int j;
    char temp;
    
    for (i = 1; i <= (*T).size - 1; i++) {
        for (j = i + 1; j <= (*T).size; j++) {
            if ((*T).wadah[i] < (*T).wadah[j]) {
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[j];
                (*T).wadah[j] = temp;
            }
        }
    }
}

#endif