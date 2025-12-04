/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124140124/Aqiatillah Rezi Zhafran */
/* Tanggal   : 5 September 2025*/
/***********************************/
#include <stdio.h>
#include "titik.h"
#include "titik.c"

int main() {
	//kamus main
	Titik T1;
    Titik T2;
	int x;
	int y;
	float k;
    
	//algoritma
	printf("\nHalo, ini driver modul Titik\n");

/*********KONSTRUKTOR**********/
	printf("\nMasukkan koordinat T1 (x y): ");
	scanf("%d %d", &x, &y);
    	makeTitik(&T1, x, y);
    printf("T1 dibuat: (%d,%d)\n", getAbsis(T1), getOrdinat(T1));
    
    printf("Masukkan koordinat T2 (x y): ");
    	scanf("%d %d", &x, &y);
    	makeTitik(&T2, x, y);
    printf("T2 dibuat: (%d,%d)\n", getAbsis(T2), getOrdinat(T2));

/*********SELECTOR**********/
	printf("\nAbsis T1: %d\n", getAbsis(T1));
    printf("Ordinat T1: %d\n", getOrdinat(T1));
    printf("Absis T2: %d\n", getAbsis(T2));
    printf("Ordinat T2: %d\n", getOrdinat(T2));

	
/*********MUTATOR**********/
	printf("T1 sebelum diubah nilai:(%d,%d)\n",getAbsis(T1),getOrdinat(T1));
	printf("Masukkan nilai baru untuk absis T1:");
		scanf("%d",&x);
		setAbsis(&T1 ,x);
	printf("Masukkan nilai baru untuk ordinat T1: ");
    	scanf("%d", &y);
    	setOrdinat(&T1, y);

	printf("T1 setelah diubah: (%d,%d)\n", getAbsis(T1), getOrdinat(T1));


/*********PREDIKAT**********/
	//isOrigin
	printf("\nApakah T1 (%d,%d) ada di titik(0,0)? %s",getAbsis(T1),getOrdinat(T1),
		 isOrigin(T1)?"true" : "false");

	//isOnSumbuX
	printf("\nApakah T1 (%d,%d) ada di titik sumbu X? %s",getAbsis(T1),getOrdinat(T1),
		 isOnSumbuX(T2)?"true" : "false");

	//isOnSumbuY
	printf("\nApakah T1 (%d,%d) ada di titik sumbu Y? %s",getAbsis(T1),getOrdinat(T1),
		 isOnSumbuY(T2)?"true" : "false");

	//isEqual
	printf("\nApakah T1(%d,%d) dan T2(%d,%d) sama? %s\n",getAbsis(T1),getOrdinat(T1),getAbsis(T2),getOrdinat(T2),
		isEqual(T1, T2)?"true" : "false");
		

/*********SUBRUTIN LAIN*********/
	//Geser
	printf("\nGeser titik");
	printf("\nT1 before: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	printf("\nMasukkan nilai x dan y untuk menggeser T1:");
	printf("\nMasukkan nilai x: ");
		scanf("%d", &x);
	printf("Masukkan nilai y: ");
		scanf("%d", &y);

	geser(&T1, x, y);
	printf("T1 after: (%d,%d)\n", getAbsis(T1), getOrdinat(T1));


	//Refleksi X
	printf("\nRefleksi titik terhadap Absis");
	printf("\nT1 before terhadap sumbu X: (%d,%d)", getAbsis(T1), getOrdinat(T1));
		refleksiX(&T1);
	printf("\nT1 after terhadap sumbu X: (%d,%d)\n", getAbsis(T1), getOrdinat(T1));


	//Refleksi Y
	printf("\nRefleksi titik terhadap Ordinat");
	printf("\nT1 before terhadap sumbu Y: (%d,%d)", getAbsis(T1), getOrdinat(T1));
		refleksiY(&T1);
	printf("\nT1 after terhadap sumbu Y: (%d,%d)\n", getAbsis(T1), getOrdinat(T1));

	
	// Dilatasi 
	printf("\nDilatasi titik");
	printf("\nT1 before dilatasi: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	printf("\nMasukkan faktor skala dilatasi: ");
		scanf("%f", &k);
		dilatasi(&T1, k);
	printf("\nT1 after dilatasi dengan faktor %.2f: (%d,%d)", k, getAbsis(T1), getOrdinat(T1));


	//Dilatasi terhadap titik tertentu 
	printf("\nDilatasi terhadap titik tertentu");
	printf("\nT1 sebelum didilatasi terhadap T2: (%d,%d)", getAbsis(T1), getOrdinat(T1)); 
	printf("\nTitik pusat dilatasi T2: (%d,%d)", getAbsis(T2), getOrdinat(T2)); 
	printf("\nMasukkan faktor skala untuk dilatasi T1 terhadap T2: ");
		scanf("%f", &k); 
		dilatasiX(&T1, T2, k); 
	printf("T1 setelah didilatasi terhadap T2 dengan faktor %.2f: (%d,%d)\n", k, getAbsis(T1), getOrdinat(T1));



	//Kuadran
	printf("\nTitik di kuadran berapa :");
	printf("\nT1 berada di kuadran ke-%d", kuadran(T1));
	printf("\nT2 berada di kuadran ke-%d", kuadran(T2));
	
	return 0;

}
