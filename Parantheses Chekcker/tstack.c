#include <stdio.h>
#include <string.h>
#include "tstack.h"
/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    // Kamus Lokal
    int i;
    // Algoritma
    top(*T) = 0;
    for (int i = 1; i <= 10; i++)
    {
        (*T).wadah[i] = '#';
    }
    
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    // Kamus Lokal
    // Algoritma
    return top(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    // Kamus Lokal
    // Algoritma
    return top(T) == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    // Kamus Lokal
    // Algoritma
    if (isFullStack(*T) == false){
        top(*T) = top(*T) + 1;
        (*T).wadah[top(*T)] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    // Kamus Lokal
    // Algoritma
    *X = '#';
    if (isEmptyStack(*T) == false)
    {
        *X = infotop(*T);
        (*T).wadah[(*T).top] = '#';
        (*T).top = (*T).top - 1;
    }
    
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    // Kamus Lokal
    int i;
    char X;
    // Algoritma
    for (i = 1; i <= 10; i++)
    {
        printf("%c", T.wadah[i]);
        if (i < 10){
            printf(", ");
        }

    }
    printf("\n");
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    // Kamus Lokal
    int i;
    char X;
    // Algoritma
    if (!(isEmptyStack(T)))
    {
        for (i = 1; i <= top(T); i++)
        {
            printf("%c", T.wadah[i]);
            if (i < top(T)){
                printf(", ");
            }
        }
        printf("\n");
    }
}


/*function isValidKurung( kata: string ) -> boolean
    {I.S.: kata terdefinisi}
    {F.S.: mengembalikan true jika semua kurung dalam kata berpasangan dengan benar}
    {Proses: mengecek validitas pasangan kurung menggunakan stack} */
boolean isValidKurung(char kata[]) {
    // Kamus Lokal
    Tstack stack;
    int i, Panjang;
    char c, Kurungbuka;
    
    // Algoritma
    createStack(&stack);
    Panjang = strlen(kata);
    
    for (i = 1; i < Panjang; i++) {
        c = kata[i];
        if (c == '(' || c == '[' || c == '{') {
            if (isFullStack(stack)) {
                return false;
            }
            push(&stack, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmptyStack(stack)) {
                return false;
            }
            pop(&stack, &Kurungbuka);
            if (!((Kurungbuka == '(' && c == ')') ||
                  (Kurungbuka == '[' && c == ']') ||
                  (Kurungbuka == '{' && c == '}'))) {
                return false;
            }
        }
    }
    
    return isEmptyStack(stack);
}






	
