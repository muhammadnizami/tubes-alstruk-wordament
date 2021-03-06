/*MATRIKS 4*4 dengan infotype boolean*/
/*indeks 1..4*/

#ifndef matbool_c
#define matbool_c

#include "matbool.h"

matbool mbCreateEmpty(){
//mengembalikan matriks berisi Nil
	int i,j;
	matbool M;
	for (i=1;i<=4;i++)
		for (j=1;j<=4;j++)
			M.T[i][j]=Nil;
	return M;
}

boolean mbGetElmt(matbool M, int row, int col){
//prekondisi: M bukan berisi Nil
//mengembalikan isi
	return M.T[row][col];
}

void mbSetElmt(matbool *M, int row, int col, boolean X){
//I.S. M terdefinisi
//F.S. M.T[row][col] berisi X
	M->T[row][col]=X;
}


void mbPutar(matbool * M){
/*I.S.	M sebarang*/
/*F.S.	M diputar 90 derajat CW*/
	matbool TMP=mbCreateEmpty();
	int i,j;
	for (i=1;i<=4;i++)
		for (j=1;j<=4;j++)
			mbSetElmt(&TMP,i,j,mbGetElmt(*M,5-j,i));
	*M=TMP;
}

#endif
