/* ADT Stack dengan infotype point*/
#ifndef stackpoint_h
#define stackpoint_h

#include "../ADT Boolean/boolean.h"
#include "../ADT Point/point.h"

#ifndef Nil
#define Nil 0
#endif

typedef POINT spinfotype;
typedef struct ELMTSTACKPOINT ElmtStackPoint;
typedef ElmtStackPoint* spaddress;
typedef struct ELMTSTACKPOINT{
	 spinfotype Info;
	 spaddress Next;
}ElmtStackPoint;
typedef struct { spaddress Top; } stackpoint;



/* Definisi stack S kosong : S.TOP = Nil */
/* Jika S adalah stackpoint maka akses elemen : */
/* S.TOP adalah alamat elemen TOP */
/* Jika S : stackpoint dan P : address (address untuk traversal), maka penulisan : */
/*Top(S) menjadi S.Top
Next(P) menjadi P↑.Next
Info(P) menjadi P↑.Info*/
#define Top(S) (S).Top
#define Next(P) (P)->Next
#define Info(P) (P)->Info
/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void spCreateEmpty (stackpoint * S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean spIsEmpty (stackpoint S);
/* Mengirim true jika stackpoint kosong: lihat definisi di atas */
/* ********** Operator Dasar stackpoint ********* */
void spPush (stackpoint * S, spinfotype X);
/* Menambahkan X sebagai elemen stackpoint S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi info TOP yang baru, Next TOP yang baru adalah TOP lama */
void spPop (stackpoint * S, spinfotype * X);
/* Menghapus X dari stackpoint S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai info elemen TOP yang lama, TOP menjadi next dari TOP lama */

void spPutar44(stackpoint *S);
/* I.S. S terdefinisi, mungkin kosong*/
/* F.S. semua point di dalam stack diputar sesuai matriks 4X4 CW*/
#endif
