#ifndef statusboard_c
#define statusboard_c

#include "statusboard.h"
#include "String/_string.h"
#include <stdio.h>


const dir up = {-1,0};
const dir down = {1,0};
const dir left = {0,-1};
const dir right = {0,1};
const dir upleft = {-1,-1};
const dir downleft = {1,-1};
const dir upright = {-1,1};
const dir downright = {1,1};

char boardfilenamedummy[128];

char * boardfilename(int boardnum){
	char boardnums[6];
	boardnums[0]=boardnum+'0';
	boardnums[1]='.';
	boardnums[2]='t';
	boardnums[3]='x';
	boardnums[4]='t';
	boardnums[5]='\0';
	_strcpy(boardfilenamedummy,"data/boards/");
	return (_strcat(boardfilenamedummy,boardnums));
}

void StartBoard(statusboard * SB, int boardnum){
/*I.S.	sebarang */
/*F.S.	SB->board berisi board dari file eksternal (sesuai nomor)
	SB->visited berisi false semua
	SB->SC kosong
	SB->SP kosong
	SB->pointer berisi <1,1>
	SB->SedangBuatKata false*/	
	mcLoad(boardfilename(boardnum),&SB->board);
	SB->visited=mbCreateEmpty();
	scCreateEmpty(&SB->SC);
	spCreateEmpty(&SB->SP);
	SB->pointer=MakePOINT(1,1);
	SB->SedangBuatKata=false;
}

void StartBuatKata(statusboard * SB){
/*I.S.	SB->SedangBuatKata false*/
/*F.S.	SB->SedangBuatKata true
	SB->visited ke-pointer true
	push point dan karakter yang ditunjuk ke stack*/
	SB->SedangBuatKata=true;
	scPush(&SB->SC,mcGetElmt(SB->board,GetAbsis(SB->pointer),GetOrdinat(SB->pointer)));
	spPush(&SB->SP,SB->pointer);
	mbSetElmt(&SB->visited,GetAbsis(SB->pointer),GetOrdinat(SB->pointer),true);
}

void StopDanKirimKata(statusboard * SB, Kata * K){
/*I.S.	SB-> SedangBuatKata true
	SC dan SP berisi */
/*F.S.	Kata dibentuk dari SC dengan urutan bottom ke top lalu dikirim ke K
	SC dan SP kosong. semua elemen SB->visited diset false
	SedangBuatKata bernilai false */
	char A;
	SB->SedangBuatKata=false;
	stackkar SCrev;
	scCreateEmpty(&SCrev);
	while (!scIsEmpty(SB->SC)){
		scPop(&SB->SC,&A);
		scPush(&SCrev,A);
	}
	int i=0;
	while (!scIsEmpty(SCrev)){
		i++;
		scPop(&SCrev,&A);
		K->TabKata[i]=A;
	}
	K->Length=i;

	//stack point dikosongkan
	POINT dum;
	while (!spIsEmpty(SB->SP)) spPop(&SB->SP,&dum);

	//SB->visited diest false
	SB->visited=mbCreateEmpty();
	
}

void MovePointer(statusboard * SB, dir _dir){
/*I.S.	SB terdefinisi */
/*F.S.	POINT dipindahkan sesuai arah
	bila SB->SedangBuatKata true, dan elemen SB->visited ke-POINT false, 
	push POINT ke SB->SP dan push karakter di SB->board yang ditunjuk
	POINT ke SB->SC.
	bila SB->SedangBuatKata true, dan elemen SB->visited ke-POINT true,
	pop SB->SP dan SB->SC hingga elemen teratas SB->SP adalah POINT*/
	SB->pointer=PPlus(SB->pointer,_dir);
	char dumc;
	POINT dump;
	if (GetAbsis(SB->pointer)<1) SetAbsis(&SB->pointer,1);
	if (GetAbsis(SB->pointer)>4) SetAbsis(&SB->pointer,4);
	if (GetOrdinat(SB->pointer)>4) SetOrdinat(&SB->pointer,4);
	if (GetOrdinat(SB->pointer)<1) SetOrdinat(&SB->pointer,1);
	if (SB->SedangBuatKata){
		if (!mbGetElmt(SB->visited,GetAbsis(SB->pointer),GetOrdinat(SB->pointer))){
			spPush(&SB->SP,SB->pointer);
			scPush(&SB->SC,mcGetElmt(SB->board,GetAbsis(SB->pointer),GetOrdinat(SB->pointer)));
			mbSetElmt(&SB->visited,GetAbsis(SB->pointer),GetOrdinat(SB->pointer),true);
		}else{
			while (NEQ(SB->pointer,Info(Top(SB->SP)))){
				scPop(&SB->SC,&dumc);
				spPop(&SB->SP,&dump);
				mbSetElmt(&SB->visited,GetAbsis(dump),GetOrdinat(dump),false);
			}
		}
	}
}

void TampilkanBoard(statusboard SB){
/*I.S.	SB terdefinisi */
/*F.S.	board, pointer, dan visited ditampilkan dalam satu kotak */
	int i,j;
	for (j=0;j<=12;j++)
		printf("-");
	printf("\n");
	for (i=1;i<=4;i++){
		printf("|");
		for (j=1;j<=4;j++){
			if (EQ(SB.pointer,MakePOINT(i,j)))
				printf(">");
			else if (mbGetElmt(SB.visited,i,j))
				printf("*");
			else	printf(" ");
			printf("%c",mcGetElmt(SB.board,i,j));
			printf("|");
		}
		printf("\n");
		for (j=0;j<=12;j++)
			printf("-");
		printf("\n");
	}

}


void PutarBoard(statusboard *SB){
/*I.S.	SB terdefinisi */
/*F.S.	board dan visited diputar 90 derajat*/
/*	stackpoint dan POINT diputar juga*/
	PutarPoint44(&SB->pointer);
	spPutar44(&SB->SP);
	mcPutar(&SB->board);
	mbPutar(&SB->visited);
}


void DeleteBoard(statusboard *SB){
/*digunakan saat SB tidak akan dipakai lagi.*/
/*I.S.	SB terdefinisi */
/*F.S.	semua memori dinamis di dalam SB didealokasi*/
	char dumc;
	POINT dump;
	while (!spIsEmpty(SB->SP)) spPop(&SB->SP,&dump);
	while (!scIsEmpty(SB->SC)) scPop(&SB->SC,&dumc);
}


#endif
