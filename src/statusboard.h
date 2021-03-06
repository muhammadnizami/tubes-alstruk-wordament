#ifndef statusboard_h
#define statusboard_h

#include "ADT Matriks/matchar.h"
#include "ADT Matriks/matbool.h"
#include "ADT Stack/stackkar.h"
#include "ADT Stack/stackpoint.h"
#include "ADT Point/point.h"
#include "ADT Boolean/boolean.h"
#include "ADT Mesin Kata/mesinkata1.h"

typedef struct {
	matchar board;
	matbool visited;
	stackkar SC;
	stackpoint SP;
	POINT pointer;
	boolean SedangBuatKata;
}statusboard;

#define SedangBuatKata(SB) (SB).SedangBuatKata

//tipe untuk memindahkan pointer
typedef POINT dir;
extern const dir up;
extern const dir down;
extern const dir left;
extern const dir right;
extern const dir upleft;
extern const dir downleft;
extern const dir upright;
extern const dir downright;

void StartBoard(statusboard * SB, int boardnum);
/*I.S.	sebarang */
/*F.S.	SB->board berisi board dari file eksternal (sesuai nomor)
	SB->visited berisi false semua
	SB->SC kosong
	SB->SP kosong
	SB->POINT berisi <1,1>
	SB->SedangBuatKata false*/

void StartBuatKata(statusboard * SB);
/*I.S. SB->SedangBuatKata false*/
/*F.S. SB->SedangBuatKata true*/

void StopDanKirimKata(statusboard * SB, Kata * K);
/*I.S.	SB-> SedangBuatKata true
	SC dan SP berisi */
/*F.S.	Kata dibentuk dari SC dengan urutan bottom ke top lalu dikirim ke K
	SC dan SP kosong. semua elemen SB->visited diset false
	SedangBuatKata bernilai false */

void MovePointer(statusboard * SB, dir _dir);
/*I.S.	SB terdefinisi */
/*F.S.	POINT dipindahkan sesuai arah
	bila SB->SedangBuatKata true, dan elemen SB->visited ke-POINT false, 
	push POINT ke SB->SP dan push karakter di SB->board yang ditunjuk
	POINT ke SB->SC.
	bila SB->SedangBuatKata true, dan elemen SB->visited ke-POINT true,
	pop SB->SP dan SB->SC hingga elemen teratas SB->SP adalah POINT*/

void TampilkanBoard(statusboard SB);
/*I.S.	SB terdefinisi */
/*F.S.	board, pointer, dan visited ditampilkan dalam satu kotak */

void PutarBoard(statusboard *SB);
/*I.S.	SB terdefinisi */
/*F.S.	board dan visited diputar 90 derajat*/
/*	stackpoint dan POINT diputar juga*/

void DeleteBoard(statusboard *SB);
/*digunakan saat SB tidak akan dipakai lagi.*/
/*I.S.	SB terdefinisi */
/*F.S.	semua memori dinamis di dalam SB didealokasi*/






/***LAINNYA***/

char * boardfilename(int boardnum);

#endif
