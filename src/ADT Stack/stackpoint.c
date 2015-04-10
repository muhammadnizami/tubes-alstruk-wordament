/* ADT stackpoint dengan infotype karakter*/
#ifndef stackpoint_c
#define stackpoint_c

#include "stackpoint.h"
#include "../ADT Boolean/boolean.h"
#include <stdlib.h>

/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void spCreateEmpty (stackpoint * S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
	Top(*S)=Nil;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean spIsEmpty (stackpoint S){
/* Mengirim true jika stackpoint kosong: lihat definisi di atas */
	return Top(S)==Nil;
}
/* ********** Operator Dasar stackpoint ********* */
void spPush (stackpoint * S, spinfotype X){
/* Menambahkan X sebagai elemen stackpoint S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi info TOP yang baru, Next TOP yang baru adalah TOP lama */
	spaddress P;
	P=malloc(sizeof(ElmtStackPoint));
	Info(P)=X;
	Next(P)=Top(*S);
	Top(*S)=P;
}
void spPop (stackpoint * S, spinfotype * X){
/* Menghapus X dari stackpoint S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai info elemen TOP yang lama, TOP menjadi next dari TOP lama */
	spaddress P;
	P=Top(*S);
	*X=Info(P);
	Top(*S)=Next(P);
	free(P);

}

void spPutar44(stackpoint *S){
/* I.S. S terdefinisi, mungkin kosong*/
/* F.S. semua point di dalam stack diputar sesuai matriks 4X4 CW*/
	stackpoint temp;
	spinfotype tempx;
	spCreateEmpty(&temp);
	while (!spIsEmpty(*S)){
		spPop(S,&tempx);
		spPush(&temp,tempx);
	}
	while (!spIsEmpty(temp)){
		spPop(&temp,&tempx);
		PutarPoint44(&tempx);
		spPush(S,tempx);
	}
}

#endif
