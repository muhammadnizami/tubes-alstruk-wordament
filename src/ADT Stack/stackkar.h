/* ADT Stack dengan infotype karakter*/
#ifndef stackkar_h
#define stackkar_h

#include "../ADT Boolean/boolean.h"

#define Nil 0

typedef char scinfotype;
typedef struct ELMTSTACKCHAR ElmtStackChar;
typedef ElmtStackChar* scaddress;
typedef struct ELMTSTACKCHAR{
	 scinfotype Info;
	 scaddress Next;
}ElmtStackChar;
typedef struct { scaddress Top; } stackkar;



/* Definisi stack S kosong : S.TOP = Nil */
/* Jika S adalah stackkar maka akses elemen : */
/* S.TOP adalah alamat elemen TOP */
/* Jika S : stackkar dan P : address (address untuk traversal), maka penulisan : */
/*Top(S) menjadi S.Top
Next(P) menjadi P↑.Next
Info(P) menjadi P↑.Info*/
#define Top(S) (S).Top
#define Next(P) (P)->Next
#define Info(P) (P)->Info
/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void scCreateEmpty (stackkar * S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean scIsEmpty (stackkar S);
/* Mengirim true jika stackkar kosong: lihat definisi di atas */
/* ********** Operator Dasar stackkar ********* */
void scPush (stackkar * S, scinfotype X);
/* Menambahkan X sebagai elemen stackkar S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi info TOP yang baru, Next TOP yang baru adalah TOP lama */
void scPop (stackkar * S, scinfotype * X);
/* Menghapus X dari stackkar S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai info elemen TOP yang lama, TOP menjadi next dari TOP lama */
#endif
