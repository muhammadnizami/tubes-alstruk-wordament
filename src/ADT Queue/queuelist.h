/* File : queuelist.h */
#ifndef QUEUELIST_H
#define QUEUELIST_H

#include "../ADT Boolean/boolean.h"
#include "../ADT Mesin Kata/mesinkar1.h"
#include "../ADT Mesin Kata/mesinkata1.h"
#include <stdlib.h>

#ifndef Nil
#define Nil NULL
#endif
/* Deklarasi infotypeQL */
typedef Kata infotypeQL;
/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * address;
typedef struct tElmtQueue { 
	Kata Info;
	address Next; 
} ElmtQueue;
/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct { 
address HEAD; /* alamat penghapusan */
address TAIL; /* alamat penambahan */
} Queue;
boolean isQLchanged;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info
/* Prototype manajemen memori */

void LoadQL(Queue*Q, char* namafile);
/* I.S. file namafile berisi kata-kata yang sudah ditebak atau bisa saja kosong */
/* F.S. semua kata disimpan di dalam Q */

void AlokasiQL (address *P, infotypeQL X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
Next(P)=Nil */
/* P=Nil jika alokasi gagal */

void DealokasiQL (address *P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsEmptyQL (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */

int NBElmtQL(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/

void CreateEmptyQL(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/

void AddQL (Queue * Q, infotypeQL X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */

void DelQL(Queue * Q, infotypeQL * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

void AddUniqueQL(Queue *Q, infotypeQL X);
/* I.S. Sembarang */
/* F.S. Elemen Q bertambah 1 jika X belum ada sebelumnya */

boolean IsMemberQL(Queue Q, infotypeQL k);
/* menghasilkan true jika k adalah anggota Q */

void CopyQL(Queue Q, Queue *Q2);
/* Proses: Mengcopy Q dan menyimpan hasilnya pada Q2 */
/* I.S. Q tidak kosong */
/* F.S. Q2 berisi elemen yang sama dengan Q1 */

void PrintQL (Queue Q);
/* Proses mencetak seluruh elemen dari Q */
/* I.S. Q sembarang */
/* F.S. Jika Q kosong, mencetak elemen kosong */
/*		Jika Q tidak kosong, seluruh elemen Q dicetak */

void SaveQL(Queue Q, char* namafile);
/* I.S. Q sudah berisi elemen yang ditambahkan jika memang ada */
/* F.S. Isi dari Q disimpan di file eksternal */

#endif
