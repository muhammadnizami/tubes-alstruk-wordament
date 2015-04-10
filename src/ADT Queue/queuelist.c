#include<stdio.h>
#include "queuelist.h"

void LoadQL(Queue*Q, char* namafile){
/* I.S. file namafile berisi kata-kata yang sudah ditebak atau bisa saja kosong */
/* F.S. semua kata disimpan di dalam Q */
	STARTKATA(namafile);
	while(!EndKata){
		AddQL(Q,CKata);//digunakan AddQL (bukan AddUnique QL) karena seharusnya isi file eksternal
		//mengandung kata-kata yang unique, tidak ada yang dobel, sehingga mempercepat proses
		ADVKATA();
	}
	isQLchanged = false;
}

void AlokasiQL (address *P, infotypeQL X){
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
Next(P)=Nil */
/* P=Nil jika alokasi gagal */
	(*P) = (address)malloc(sizeof(ElmtQueue));
	if (P != Nil){
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void DealokasiQL (address *P){
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
	free(*P);
}

boolean IsEmptyQL (Queue Q){
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
	return (((Head(Q)) == Nil) && (Tail(Q) == Nil));
}
int NBElmtQL(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
	int count;
	if (IsEmptyQL(Q)){
		return 0;
	} else {
		address P = Head(Q);
		while(P!=Nil){
			count++;
			P = Next(P);
		}
		return count;
	}
}
void CreateEmptyQL(Queue * Q){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

void AddQL (Queue * Q, infotypeQL X){
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
/* Kamus Lokal */
	address P;
	/* Algoritma */
	AlokasiQL(&P,X);
	if (P!=Nil) {
		if (IsEmptyQL(*Q)) {
			Head(*Q) = P; 
			Tail(*Q) = P; 
		} else {
			Next(Tail(*Q)) = P;
			Tail(*Q) = P;
		}
	} /* else: alokasi gagal, Q tetap */
}

void DelQL(Queue * Q, infotypeQL * X){
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
 /* Kamus Lokal */
	address P;
	/* Algoritma */
	*X = InfoHead(*Q);
	P = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q)==Nil) {
		Tail(*Q) = Nil;
	}
	DealokasiQL(&P);
}

void AddUniqueQL(Queue *Q, infotypeQL X){
/* I.S. Sembarang */
/* F.S. Elemen Q bertambah 1 jika X belum ada sebelumnya */
	if(!(IsMemberQL(*Q,X))){
		AddQL(Q,X);
		isQLchanged = true;
	}
}

boolean IsMemberQL(Queue Q, infotypeQL k){
/* menghasilkan true jika k adalah anggota Q */
	
	address P;
	boolean found = false;
	if(IsEmptyQL(Q)){
		return false;
	} else {
		
		P = Head(Q);
		while((P != Nil) && !(found)){
			if(IsKataSama(Info(P),k)){
				found = true;
				break;
			} else {
				
			}
			P = Next(P);
		}
		return found;
	}
}

void CopyQL(Queue Q, Queue *Q2){
/* Proses: Mengcopy Q dan menyimpan hasilnya pada Q2 */
/* I.S. Q tidak kosong */
/* F.S. Q2 berisi elemen yang sama dengan Q */

	CreateEmptyQL(Q2);
	
	address P = Head(Q);
	while (P != Nil){
		AddQL(Q2, Info(P));
		P = Next(P);
	}
}

void PrintQL (Queue Q){
/* Proses mencetak seluruh elemen dari Q */
/* I.S. Q sembarang */
/* F.S. Jika Q kosong, mencetak elemen kosong */
/*		Jika Q tidak kosong, seluruh elemen Q dicetak */
	if (IsEmptyQL(Q)){
		printf("Queue kosong\n");
	} else {
		address P = Head(Q);
		while (P != Nil){
			PrintKata(Info(P));
			P = Next(P);
		}
	}
}

void SaveQL(Queue Q, char* namafile){
/* I.S. Q sudah berisi elemen yang ditambahkan jika memang ada */
/* F.S. Isi dari Q disimpan di file eksternal */
	address P;
	int j;
	if(isQLchanged){
		FILE *f = fopen(namafile, "w");
		P = Head(Q);
		while(P != Nil){
			j = 1;
			while(j <= Info(P).Length){
				fprintf(f,"%c",Info(P).TabKata[j]);
				j++;
			}
			P = Next(P);
			if(P != Nil)
				fprintf(f,"\n");
		}
		fprintf(f,".");
		fclose(f);
	} else {
		//Tidak perlu mengupdate file eksternal
	}
}