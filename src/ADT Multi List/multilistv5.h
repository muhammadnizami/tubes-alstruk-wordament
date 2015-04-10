#include "../ADT Jam + Tanggal/waktu.h"
#include "../ADT Jam + Tanggal/jam.h"
#include "../ADT Jam + Tanggal/tanggal.h"

#ifndef multilist_h
#define multilist_h

#define Nil NULL
#define User(P) P->User
#define Score(P) P->Score
#define Waktu(P) P->W
#define PrevUser(P) P->PrevUser
#define NextUser(P) P->NextUser
#define FirstUser(L) ((L).First)
#define LastUser(L) ((L).Last)
#define NextScore(P) (P)->NextScore

typedef struct{
    char usr[20];
}InfoUser;

typedef struct{
	int scr;
}InfoScore;
typedef struct tElmUser *adrUser;
typedef struct tElmScore *adrScore;
typedef struct tElmUser{
        InfoUser User; 		//Nama User
        adrScore FirstScore[10];	//Skor Board 0-9 dalam array of list
        adrUser NextUser;
        adrUser PrevUser;
}ElmUser;
typedef struct tElmScore{
		WAKTU W;      		//waktu mendapatkan skor
        InfoScore Score;
        adrScore NextScore;
}ElmScore;
typedef struct
{
        adrUser First;
        adrUser Last;
}List;

int Changed;

int IsListEmpty (List L); 
void CreateList(List *L);
adrUser AlokasiUser(InfoUser X);
adrScore AlokasiScore(int X);
adrScore AlokDariFile(unsigned char H, unsigned char B,unsigned char T,int J,int M,int D,int Skor);
void DealokasiUser(adrUser P);
void DealokasiScore(adrScore Q);
adrUser FindUser(List *L,InfoUser X);
void InsVUser (List *L,InfoUser X);
void InsVScore(adrUser P, int Y,int BoardNumber);
void InsertScore(adrUser P,adrScore Q,int BoardNumber);
void InsertFirst (List *L,adrUser P);
void InsertLast (List *L, adrUser P);
void PrintUser(adrUser P,int BoardNumber);
void DelVScoreLast (adrUser P, int *X,int BoardNumber);
void DelScoreLast (adrUser P, adrScore *Q, int BoardNumber);
void Save (List L);
void Load (List *L);
#endif 
