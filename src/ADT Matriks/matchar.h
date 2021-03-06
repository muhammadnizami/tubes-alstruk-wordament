/*MATRIKS 4*4 dengan infotype char*/
/*indeks 1..4*/

#ifndef matchar_h
#define matchar_h

#define Nil 0

typedef struct {
	char T[5][5];
}matchar;

matchar mcCreateEmpty();
//mengembalikan matriks berisi Nil

char mcGetElmt(matchar M, int row, int col);
//prekondisi: M bukan berisi Nil
//mengembalikan isi

void mcSetElmt(matchar *M, int row, int col, char X);
//I.S. M terdefinisi
//F.S. M.T[row][col] berisi X

void mcLoad(char * Path, matchar * M);
/*I.S. 	M sebarang
	Path menunjuk file yang ada dengan isi: masing-masing baris
	dipisahkan newline. baris kelima berisi titik. kolom dipisahkan
	oleh spasi */
/*F.S.	M berisi matriks karakter yang direpresentasikan file*/

void mcPutar(matchar * M);
/*I.S.	M sebarang*/
/*F.S.	M diputar 90 derajat CW*/

#endif
