#ifndef game_h
#define game_h
#include "ADT Priority Queue/priority_queue.h"
#include "ADT Queue/queuelist.h"
#include "ADT Map/score.h"
#include "ADT Set/set.h"

#include <stdio.h>
//dummy

/*Kata _strToKata(char * _str){ //alat bantu untuk pengetesan
	Kata K;
	int count=0;
	char a;
	while (_str[count]!='\0'){
		a=_str[count];
		count++;
		K.TabKata[count]=a;
	}
	K.Length=count;
	return K;
}*/

#include "statusboard.h"
#include "ADT Mesin Kata/mesinkata1.h"

#include <stdlib.h> 
#include <unistd.h> 
#include <sys/select.h> 
#include <termios.h> 
#include <time.h> 
#include <stdio.h>

char * dictionary_path="data/Dictionary.txt";

void Play(double seconds,int board,Queue * Sug, PriorityQueue * Disp, int * score);

void PlayGame(int board, Queue * Sug, PriorityQueue * Disp, int * score){
	Play(120,board,Sug,Disp,score);
/*	printf("\n");
	int i,NumKata,tmpscore;
	Queue Temp;
	CreateEmptyQL(&Temp);
	printf("banyak kata yang dibentuk:");
	scanf("%d",&NumKata);
	Kata CurKat;
	char in[17];
	Queue dictionary;
	CreateEmptyQL(&dictionary);
	printf("loading dictionary\n");
	LoadQL(&dictionary,dictionary_path);
	*score=0;
	for (i=0;i<NumKata;i++){
		if (!IsEmptyQL(*Sug)){
			printf("Suggestion: ");
			PrintKata(InfoHead(*Sug));
			printf("\n");
		}
		printf("Kata yang dibentuk (max. 16 huruf):");
		scanf("%s",in);
		CurKat=_strToKata(in);
		if (!IsMemberQL(dictionary,CurKat)){
			printf("Kata ");
			PrintKata(CurKat);
			printf(" tidak ada di kamus\n");
			i--;
		} else if (IsMemberQL(Temp,CurKat)){
			printf("Kata ");
			PrintKata(CurKat);
			printf(" sudah pernah dibuat\n");
			i--;
		}else {
			AddUniqueQL(&Temp,CurKat);
			tmpscore=getscore(CurKat);
			*score+=tmpscore;
			PQAdd(Disp,CurKat,tmpscore);
			while (!IsEmptyQL(*Sug)&&IsMemberQL(Temp,InfoHead(*Sug)))
				DelQL(Sug,&CurKat);
		}

	}
	
//	mengembalikan Temp ke Sug
	while (!IsEmptyQL(Temp)){
		DelQL(&Temp,&CurKat);
		AddUniqueQL(Sug,CurKat);
	}*/
}

const char empty[]="";
const char tidakada[]=" tidak ada di kamus";
const char sudahdibuat[]=" sudah pernah dibuat";
const char berhasil[]=" berhasil dibentuk";
static struct termios old_termios, new_termios;
/* restore new terminal i/o settings */
void resetTermios(){
	tcsetattr(0,TCSANOW,&old_termios);
}
/* initialize new terminal i/o settings */
void initTermios(){
	tcgetattr(0,&old_termios); // store old terminal 
	new_termios = old_termios; // assign to new setting 
	new_termios.c_lflag &= ~ICANON; // disable buffer i/o 
	new_termios.c_lflag &= ~ECHO; // disable echo mode 
	tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting 
}
/* detect keyboard press */
int kbhit(){
	struct timeval tv = {0L,0L};
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0,&fds);
	return select(1,&fds,NULL,NULL,&tv);
}
/* read 1 character */
char getch(){
	char ch;
	ch = getchar();
	return ch;
}
/* program for play */
void Play(double seconds,int board,Queue * Sug, PriorityQueue * Disp, int * score){
	printf("\n");
	int tmpscore;
	Queue Temp;
	SET KataTerbentuk;
	CreateEmptyQL(&Temp);
	CreateEmptySET(&KataTerbentuk);
	Kata CurKat;
	SET dictionary;
	CreateEmptySET(&dictionary);
	printf("loading dictionary\n");
	LoadSET(&dictionary,dictionary_path);
	*score=0;
	char * msgkata = empty;

	statusboard SB;
	Kata K,dumKata;
	K.TabKata[1]='-';
	K.Length=1;
	StartBoard(&SB,board);
	initTermios(); // initailize new terminal setting to make kbhit() and getch() work 
	char cc;
	const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
	clock_t startTime = clock();
	double secondsleft=seconds;
	double secondsleft1=seconds+2;
	while ((clock() - startTime) <= TIME_LIMIT){
		if (kbhit()){
			cc = getch();
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf) 
			switch (cc){
				case 'R':
				case 'r':PutarBoard(&SB);break;
				case 'Q':
				case 'q':MovePointer(&SB,upleft);break;
				case 'W':
				case 'w':MovePointer(&SB,up);break;
				case 'E':
				case 'e':MovePointer(&SB,upright);break;
				case 'A':
				case 'a':MovePointer(&SB,left);break;
				case 'D':
				case 'd':MovePointer(&SB,right);break;
				case 'Z':
				case 'z':MovePointer(&SB,downleft);break;
				case 'X':
				case 'x':MovePointer(&SB,down);break;
				case 'C':
				case 'c':MovePointer(&SB,downright);break;
				case 'S':
				case 's':
					if (SB.SedangBuatKata){
						StopDanKirimKata(&SB,&K);
						if (!IsMemberSET(dictionary,K)){
							msgkata=tidakada;
						} else if (IsMemberSET(KataTerbentuk,K)){
							msgkata=sudahdibuat;
						} else {
							msgkata=berhasil;
							AddUniqueQL(&Temp,K);
							InsertElmtUniqueSET(&KataTerbentuk,K);
							tmpscore=getscore(K);
							*score+=tmpscore;
							PQAdd(Disp,K,tmpscore);
							while (!IsEmptyQL(*Sug)&&IsMemberQL(Temp,InfoHead(*Sug)))
								DelQL(Sug,&dumKata);
						}
					}else
						StartBuatKata(&SB);
					break;
				default:
					printf("invalid input\n");
					break;
			}// process character
			//tampilan
			printf("\033[2J\033[1;1H");
			PrintSET(KataTerbentuk);
			printf("kata yang sudah dibentuk di atas\n");
			TampilkanBoard(SB);
			printf("time:%.0f\n",secondsleft);
			printf("kata terakhir yang dibentuk:");
			PrintKata(K);
			printf("%s",msgkata);
			printf("\n");
			if (!IsEmptyQL(*Sug)){
				printf("Suggestion: ");
				PrintKata(InfoHead(*Sug));
				printf("\n");
			}
			initTermios(); // use new terminal setting again to make kbhit() and getch() work 
		}
		secondsleft=seconds-(clock()-startTime)/CLOCKS_PER_SEC;
			if (secondsleft1-secondsleft>=1){
				printf("\033[2J\033[1;1H");
				PrintSET(KataTerbentuk);
				printf("kata yang sudah dibentuk di atas\n");
				TampilkanBoard(SB);
				secondsleft1=secondsleft;
				printf("time:%.0f\n",secondsleft);
				printf("kata terakhir yang dibentuk:");
				PrintKata(K);
				printf("%s",msgkata);
				printf("\n");
				if (!IsEmptyQL(*Sug)){
					printf("Suggestion: ");
					PrintKata(InfoHead(*Sug));
					printf("\n");
				}

		}
	}
	printf("\nTime Up\n");
	resetTermios(); // restore default terminal setting 

	DeleteBoard(&SB);

	//membebaskan memori dictionary dan KataTerbentuk
	DeleteSET(&dictionary);
	DeleteSET(&KataTerbentuk);

//	mengembalikan Temp ke Sug
	while (!IsEmptyQL(Temp)){
		DelQL(&Temp,&CurKat);
		AddUniqueQL(Sug,CurKat);
	}
}

#endif
