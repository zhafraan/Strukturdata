/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran*/
/* Tanggal   : 25 september 2025 */
/***********************************/

#include <stdio.h>
#include "tstack.c"
#include "boolean.h"

int main() 
{	/* kamus main */
	Tstack A; 
	char c;
	int i;
	int N;
	char kata[30];
	boolean Palindrom;
	
	/* algoritma */
	createStack(&A);
	printf("Stack A setelah dibuat :\n");
	printStack(A);
	printf("\n");

	//Push
	printf("Isi stack A dengan karakter :\n");
	push(&A,'A');
	push(&A,'B');
	push(&A,'C');
	push(&A,'D');
	push(&A,'E');
	push(&A,'F');
	push(&A,'G');
	printStack(A);
	printf("Apakah stack A kosong? %s\n", isEmptyStack(A) ? "YA" : "TIDAK");
	printf("Apakah stack A penuh? %s\n", isFullStack(A) ? "YA" : "TIDAK");
	printf("\n");

	//Pop
	printf("Pop 3 elemen dari stack A\n");
	for ( i = 1; i <= 3; i++ ) {
		pop( &A, &c );
		printf("Karakter yang dipop = %c\n", c);
	}
	printStack(A);
	printf("Apakah stack A kosong? %s\n", isEmptyStack(A) ? "YA" : "TIDAK");
	printf("Apakah stack A penuh? %s\n", isFullStack(A) ? "YA" : "TIDAK");
	printf("\n");

	printf("Pop elemen dari stack A hingga kosong\n");
	for ( i = 1; i <= 4; i++ ) {
		pop( &A, &c );
		printf("Karakter yang dipop = %c\n", c);
	}
	printStack(A);
	printf("Apakah stack A kosong? %s\n", isEmptyStack(A) ? "YA" : "TIDAK");
	printf("Apakah stack A penuh? %s\n", isFullStack(A) ? "YA" : "TIDAK");
	printf("\n");


	//PushN
	printf("Isi stack A dengan N karakter :\n");
	printf("Masukkan N (1..10) = ");
	scanf("%d", &N);

	pushN(&A, N);
	printStack(A);
	printf("Apakah stack A kosong? %s\n", isEmptyStack(A) ? "YA" : "TIDAK");
	printf("Apakah stack A penuh? %s\n", isFullStack(A) ? "YA" : "TIDAK");
	printf("\n");

	//Palindrom
	printf("Masukkan sebuah kata (maks. 30 karakter): ");
	scanf("%s", &kata[1]);
	
	Palindrom = isPalindrom(kata);
	
	if (Palindrom) {
		printf("Kata %s adalah palindrom\n", &kata[1]);
	} 
	else {
		printf("Kata %s bukan palindrom\n", &kata[1]);
	}

	return 0;
}
