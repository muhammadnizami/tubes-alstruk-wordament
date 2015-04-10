/* ADT stackkar dengan infotype karakter*/
#ifndef stackkar_c
#define stackkar_c

#include "stackkar.h"
#include "../ADT Boolean/boolean.h"
#include <stdlib.h>

/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void scCreateEmpty (stackkar * S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
	Top(*S)=Nil;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean scIsEmpty (stackkar S){
/* Mengirim true jika stackkar kosong: lihat definisi di atas */
	return Top(S)==Nil;
}
/* ********** Operator Dasar stackkar ********* */
void scPush (stackkar * S, scinfotype X){
/* Menambahkan X sebagai elemen stackkar S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi info TOP yang baru, Next TOP yang baru adalah TOP lama */
	scaddress P;
	P=malloc(sizeof(ElmtStackChar));
	Info(P)=X;
	Next(P)=Top(*S);
	Top(*S)=P;
}
void scPop (stackkar * S, scinfotype * X){
/* Menghapus X dari stackkar S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai info elemen TOP yang lama, TOP menjadi next dari TOP lama */
	scaddress P;
	P=Top(*S);
	*X=Info(P);
	Top(*S)=Next(P);
	free(P);

}
#endif
