/* Menghitung banyaknya kata WHILE dalam pita karakter */
/* Model akuisisi kata versi 1 */
/*KAMUS*/
/* *** Mesin yang digunakan *** */
#include "mesinkata1.h"
#include <stdio.h>
Kata KataWHILE; /* Kata yang menyimpan WHILE */
int NWHILE; /* banyaknya kata WHILE */
int main(){
	/*ALGORITMA*/
	/* Inisialisasi KataWHILE */
	KataWHILE.TabKata[1] = 'W';
	KataWHILE.TabKata[2] = 'H';
	KataWHILE.TabKata[3] = 'I';
	KataWHILE.TabKata[4] = 'L';
	KataWHILE.TabKata[5] = 'E';
	KataWHILE.Length = 5;
	NWHILE = 0;
	STARTKATA("pitakar.txt");
	while (!EndKata){
		if (IsKataSama(KataWHILE, CKata))
			NWHILE = NWHILE + 1;
		ADVKATA();
	}
	/* CKata.Length = 0: CC sampai pada MARK */
	printf ("%d\n",NWHILE);
	return 0;
}
