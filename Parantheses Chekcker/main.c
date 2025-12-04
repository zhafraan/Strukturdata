/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "tstack.c"

/* ========== PROTOTIPE FUNGSI ========== */
void testKurungValidation();

/* ========== FUNGSI UTAMA ========== */
int main() {
    testKurungValidation();
    return 0; 
}

/* ========== IMPLEMENTASI FUNGSI TEST ========== */
/*procedure testKurungValidation()
    {I.S.: -}
    {F.S.: Hasil validasi kurung ditampilkan ke layar}
    {Proses: Menguji fungsi isValidKurung dengan beberapa contoh}*/
void testKurungValidation() {
    // Kamus Lokal
    char test1[] = "{[(A+B) * (C+D)] - (7*D)}";      
    char test2[] = "{[(A+B) * (C+D)] - (7*D)";      
    char test3[] = "{[(A+B) * (C+D]) - (7*D)}";      
    char test4[] = "{[(A+B) * (C+D)] - (7*D))} ";    
    
    // Algoritma
    printf("=== TEST BRACKET VALIDATION ===\n\n");
    
    // Test case 1
    printf("String: \"%s\"\n", test1);
    printf("Result: %s\n", isValidKurung(test1) ? "TRUE" : "FALSE");
    printf("Expected: TRUE (Kurung valid)\n\n");
    
    // Test case 2
    printf("String: \"%s\"\n", test2);
    printf("Result: %s\n", isValidKurung(test2) ? "TRUE" : "FALSE");
    printf("Expected: FALSE (Kurung tidak valid)\n\n");
    
    // Test case 3
    printf("String: \"%s\"\n", test3);
    printf("Result: %s\n", isValidKurung(test3) ? "TRUE" : "FALSE");
    printf("Expected: FALSE (Kurung tidak valid)\n\n");
    
    // Test case 4
    printf("String: \"%s\"\n", test4);
    printf("Result: %s\n", isValidKurung(test4) ? "TRUE" : "FALSE");
    printf("Expected: FALSE (Kurung tidak valid)\n\n");
    
}