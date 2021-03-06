#include "set.h"

void CreateEmptySET(SET *s){
/* I.S. sembarang */
/* F.S. membentuk set kosong dengan First = Nil */
	First(*s) = Nil;
	Last(*s) = Nil;
}

void LoadSET(SET *s, char *namafile){
/* I.S. s kosong */
/* F.S. Membaca data dari file eksternal sehingga seluruh data dari file eksternal disimpan */
/*     ke dalam s selama belum mencapai end of file (.)*/
	STARTKATA(namafile);
	int n;
	while(!EndKata){
		InsertElmtSET(s,CKata);
		ADVKATA();
	}
	isSETChanged = false;
}

seteladdress AlokasiElmtSET(infotype X){
/*  menghasilkan seteladdress hasil alokasi memori untuk X, jika gagal menghasilkan Nil*/
	seteladdress P = (seteladdress)malloc(sizeof(ElmtListSET));
	if(P!=Nil){
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void DealokasiElmtSET(seteladdress P){
/* mendealokasi memori P*/
	free(P);
}

boolean IsEmptySET(SET s){
/* menghasilkan true jika list empty */
	return ((First(s) == Nil) && (Last(s) == Nil));
}

void InsertElmtSET(SET *s, infotype X){
/* I.S. X belum ada di s */
/* F.S. menambahkan X pada s */
	seteladdress P = AlokasiElmtSET(X);
	if(P!=Nil){
		if(IsEmptySET((*s))){
			First(*s) = P;
		} else {
			Next(Last(*s)) = P;
		}
		Last(*s) = P;
	}
	isSETChanged = true;
}

void InsertElmtUniqueSET(SET *s, infotype X){
/* I.S. sembarang */
/* F.S. menambahkan X pada s jika belum ada */
	if(!(IsMemberSET((*s),X))){
		InsertElmtSET(s,X);
	} else {
		//tidak perlu ditambahkan
	}
}

boolean IsMemberSET(SET s, Kata K){
/* menghasilkan true jika K adalah member s */
	boolean found = false;
	seteladdress P = First(s);
	while ((P != Nil) && (!(found))){
		if(IsKataSama(Info(P),K)){
			found = true;
			break;
		}
		P = Next(P);
	}
	return found;
}

int NbElmtSET(SET s){
/* menghasilkan jumlah elemen SET s */
	int n = 0;
	seteladdress P = First(s);
	while (P != Nil){
		n++;
		P = Next(P);
	}
	return n;
}

void CopySET(SET s1, SET *s2){
/* I.S. s1 adalah set, mungkin kosong */
/* F.S. s2 berisi salinan s1 dengan alokasi memori */
	seteladdress P2;
	CreateEmptySET(s2);
	seteladdress P = First(s1);
	while (P!=Nil){
		InsertElmtSET(s2,Info(P));
		P = Next(P);
	}
}

void UnionSET(SET s1, SET s2, SET *s3){
/* I.S. s1 dan s2 adalah set, mungkin kosong */
/* F.S. s3 berisi hasil gabungan s1 dan s2 */
	CreateEmptySET(s3);
	CopySET(s1,s3);
	seteladdress P = First(s2);
	while(P!=Nil){
		InsertElmtUniqueSET(s3,Info(P));
		P = Next(P);
	}
}


void PrintSET(SET s){

	seteladdress P;
	if(IsEmptySET(s)){
		printf("Empty set\n");
	} else {
		P = First(s);
		do {
			PrintKata(Info(P));
			printf("\n");
			P = Next(P);
		} while (P!=Nil);
	}
}

void DeleteSET(SET * s){
/* I.S. s terdefinisi */
/* F.S. s kosong */
	seteladdress P,NextP;
	for (P=First(*s);P!=Nil;P=NextP){
		NextP=Next(P);
		DealokasiElmtSET(P);
	}
	First(*s)=Nil;
	Last(*s)=Nil;
}
