#ifndef priority_queue_c
#define priority_queue_c

#include "priority_queue.h"
#include <stdlib.h>
#include <stdio.h>

/*KONSTRUKTOR DAN DESTRUKTOR PQEL*/

pqaddress AlokasiPQEL(pqinfotype I, int Priority){
//mengembalikan pqaddress hasil alokasi dengan info I dan prioritas Priority
//dan next Nil
	pqaddress P;
	P=malloc(sizeof(pqel));
	Info(P)=I;
	Priority(P)=Priority;
	Next(P)=Nil;
}
void DealokasiPQEL(pqaddress * P){
//mengembalikan P pada sistem
	free(*P);
}
void CreatePriorityQueue(PriorityQueue * Q){
/*I.S. Sembarang*/
/*F.S. Q Priority Queue Kosong: Head dan Tail Nil*/
	Head(*Q)=Nil;
}

/*TEST QUEUE KOSONG*/
boolean PQIsEmpty(PriorityQueue Q){
/*mengembalikan true bila Q kosong (lihat definisi di atas)*/
	return Head(Q)==Nil;
}

void PQAdd(PriorityQueue * Q, pqinfotype I, int Priority){
/*I.S. Q terdefinisi, mungkin kosong*/
/*F.S. elemen baru dengan Info I dan prioritas Priority ditambahkan pada 
	queue, elemen Q terurut berdasarkan Priority tiap elemen*/
	pqaddress P,PSearch,Prec;
	boolean more;
	P=AlokasiPQEL(I,Priority);
	if (PQIsEmpty(*Q)){
		Head(*Q)=P;
	}else if (Priority(Head(*Q))<Priority){
		Next(P)=Head(*Q);
		Head(*Q)=P;
	}else{
		Prec=Head(*Q);
		PSearch=Next(Prec);
		more=true;
		while (PSearch!=Nil && more){
			if (Priority(PSearch)<Priority)
				more=false;
			else{
				Prec=PSearch;
				PSearch=Next(PSearch);
			}
			
		}
		Next(Prec)=P;
		Next(P)=PSearch;

	}

}

void PQDel(PriorityQueue * Q, pqinfotype * I, int * Priority){
/*I.S. Q terdefinisi dan tidak kosong*/
/*F.S. Head(Q) didealokasi setelah isinya disimpan pada I dan Priority,
	Head(Q) yang baru adalah Next dari Head(Q) lama*/
	pqaddress P;
	*I=Info(Head(*Q));
	*Priority=Priority(Head(*Q));
	P=Head(*Q);
	Head(*Q)=Next(P);
	DealokasiPQEL(&P);
}

void PQTulisdanHapus(PriorityQueue * Q){
/*I.S. Q terdefinisi*/
/*F.S. semua info dan prioritas ditulis terurut,
	Q kosong*/
	pqinfotype I;
	int Priority;
	while (!PQIsEmpty(*Q)){
		PQDel(Q,&I,&Priority);
		PrintKata(I);
		printf(" %d\n",Priority);
	}

}
#endif
