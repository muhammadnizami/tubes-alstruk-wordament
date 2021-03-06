/*MATRIKS 4*4 dengan infotype char*/
/*indeks 1..4*/

#ifndef matchar_c
#define matchar_c

#include "matchar.h"
#include "../ADT Mesin Kata/mesinkata1.h"

matchar mcCreateEmpty(){
//mengembalikan matriks berisi Nil
	int i,j;
	matchar M;
	for (i=1;i<=4;i++)
		for (j=1;j<=4;j++)
			M.T[i][j]=Nil;
	return M;
}

char mcGetElmt(matchar M, int row, int col){
//prekondisi: M bukan berisi Nil
//mengembalikan isi
	return M.T[row][col];
}

void mcSetElmt(matchar *M, int row, int col, char X){
//I.S. M terdefinisi
//F.S. M.T[row][col] berisi X
	M->T[row][col]=X;
}

void mcLoad(char * Path, matchar * M){
/*I.S. 	M sebarang
	Path menunjuk file yang ada dengan isi: masing-masing baris
	dipisahkan newline. baris kelima berisi titik. kolom dipisahkan
	oleh spasi */
/*F.S.	M berisi matriks karakter yang direpresentasikan file*/
	int i,j;
	*M=mcCreateEmpty();
	STARTKATA(Path);
	i=1;j=1;
	while (!EndKata){
		mcSetElmt(M,i,j,CKata.TabKata[1]);
		j++;
		if (j>4){
			j=1;
			i++;
		}
		ADVKATA();
	}
	
}

void mcPutar(matchar * M){
/*I.S.	M sebarang*/
/*F.S.	M diputar 90 derajat CW*/
	matchar TMP=mcCreateEmpty();
	int i,j;
	for (i=1;i<=4;i++)
		for (j=1;j<=4;j++)
			mcSetElmt(&TMP,i,j,mcGetElmt(*M,5-j,i));
	*M=TMP;
}

#endif
