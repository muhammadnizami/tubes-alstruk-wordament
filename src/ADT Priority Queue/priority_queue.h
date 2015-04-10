#ifndef priority_queue_h
#define priority_queue_h

#include "../ADT Boolean/boolean.h"
#include "../ADT Mesin Kata/mesinkata1.h"
typedef Kata pqinfotype;
typedef struct PQEL pqel;
typedef pqel* pqaddress;
#define Nil 0

struct PQEL{
	pqinfotype Info;
	int Priority;
	pqaddress Next;
};

#define Info(P) (P)->Info
#define Priority(P) (P)->Priority
#define Next(P) (P)->Next


/*KONSTRUKTOR DAN DESTRUKTOR PQEL*/

pqaddress AlokasiPQEL(pqinfotype I, int Priority);
//mengembalikan pqaddress hasil alokasi dengan info I dan prioritas Priority
//dan next Nil

void DealokasiPQEL(pqaddress * P);
//mengembalikan P pada sistem

	
typedef struct {
	pqaddress HEAD;
/*	pqaddress Tail;*//*mungkin tidak dibutuhkan*/
}PriorityQueue;

#define Head(Q) (Q).HEAD
/*#define Tail(Q) (Q).Tail*//*mungkin tidak dibutuhkan*/

/*KONSTRUKTOR*/

void CreatePriorityQueue(PriorityQueue * Q);
/*I.S. Sembarang*/
/*F.S. Q Priority Queue Kosong: Head dan Tail Nil*/

/*TEST QUEUE KOSONG*/
boolean PQIsEmpty(PriorityQueue Q);
/*mengembalikan true bila Q kosong (lihat definisi di atas)*/

void PQAdd(PriorityQueue * Q, pqinfotype I, int Priority);
/*I.S. Q terdefinisi, mungkin kosong*/
/*F.S. elemen baru dengan pqinfotype I dan prioritas Priority ditambahkan pada 
	queue, elemen Q terurut berdasarkan Priority tiap elemen*/

void PQDel(PriorityQueue * Q, pqinfotype * I, int * Priority);
/*I.S. Q terdefinisi dan tidak kosong*/
/*F.S. Head(Q) didealokasi setelah isinya disimpan pada I dan Priority,
	Head(Q) yang baru adalah Next dari Head(Q) lama*/

void PQTulisdanHapus(PriorityQueue * Q);
/*I.S. Q terdefinisi*/
/*F.S. semua info dan prioritas ditulis terurut,
	Q kosong*/
#endif
