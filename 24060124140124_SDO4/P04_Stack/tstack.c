/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/* Tanggal   : 25 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    int i;

    top(*T) = 0;
    for (int i = 1; i <= 10; i++)
    {
        (*T).wadah[i] = '#';
    }
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    return top(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    return top(T) == 10;
}   

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
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
    if (isEmptyStack(*T) == false){
        *X = infotop(*T);
        (*T).wadah[top(*T)] = '#';
        top(*T) = top(*T) - 1;
    }
    else{
        *X = '#';
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    int i;
    char X;
   
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
    int i;
    char X;
   
    if (!isEmptyStack(T))
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
    else
    {
        printf("Stack kosong\n");
    }
}

/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30]){
    Tstack S1;          
    int p = 0;                
    int i;              
    char X;             
    boolean isSama = true;  
    
    while (kata[p] != '\0') {
        p++;
    }
    p--;  

    if (p >= 0) {
        createStack(&S1);
        
        for (i = 0; i <= (p / 2); i++) {
            push(&S1, kata[i]);
        }
        
        if (p % 2 == 1) {
            i = i + 1;
        }
        
        while (isSama && i <= p) {
            pop(&S1, &X);
            
            if (X != kata[i]) {
                isSama = false;  
            } else {
                i++;
            }
        }
    }
    return isSama;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keybo  ard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    int i;
    char X;

    i = 1;
    while (i <= N && !isFullStack(*T))
    {
        scanf(" %c", &X);
        push(T, X);
        i = i + 1;
    }  
}




