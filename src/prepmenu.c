#ifndef prepmenu_c
#define prepmenu_c

#include "mainmenu.h"
#include "ADT Priority Queue/priority_queue.h"
#include "ADT Queue/queuelist.h"
#include "ADT Array Terurut Mengecil/arraymengecil.h"
#include "game.h"

#include <stdio.h>
#include "String/_string.h"

Kata strToKata(char * _str){
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
}

char filenamedummy[128];

char * highscorefilename(int boardnum){
	char boardnums[2];
	boardnums[1]='\0';
	boardnums[0]=boardnum+'0';
	_strcpy(filenamedummy,"data/allhighscore/");
	return _strcat(filenamedummy,boardnums);
}

char * suggestionfilename(char * uname, int boardnum){
	char boardnums[2];
	boardnums[1]='\0';
	boardnums[0]=boardnum+'0';
	_strcpy(filenamedummy,"data/suggestion/");
	return _strcat(_strcat(filenamedummy,uname),boardnums);

}

//mengecek apakah ada file
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int doesFileExist(const char *filename) {
    struct stat st;
    int result = stat(filename, &st);
    return result == 0;
}

void prepmenu(adrUser P){
	allhighscores A;
	int boardnum,score,i;
	PriorityQueue Disp;
	Queue Sug[10];
	boolean logout;
	int pilihan;
	TabTerurutMengecil AllHighScores[10];
	logout=false;
	boardnum=1;
	CreatePriorityQueue(&Disp);
	//load file-file atau inisialisasi
	for (i=0;i<10;i++){
		CreateEmptyQL(&Sug[i]);
		if (doesFileExist(suggestionfilename(User(P).usr,i))) LoadQL(&Sug[i],suggestionfilename(User(P).usr,i));
		CreateTabTerurutMengecil(&AllHighScores[i]);
		if (doesFileExist(highscorefilename(i))) LoadAllHighScores(&AllHighScores[i],highscorefilename(i));
	}
	while (!logout){
		printf("Menu:\n1. Play Game\n2. Select Board\n3. View My Highscore\n4. View All Highscore\n5. Logout\npilihan:");
		scanf("%d",&pilihan);
		switch(pilihan){
			case 1:
				PlayGame(boardnum,&Sug[boardnum],&Disp,&score);
				printf("kata-kata yang dibentuk:\n");PQTulisdanHapus(&Disp);
				printf("\ntotal score:%d\n\n",score);
				InsertScore(P,AlokasiScore(score),boardnum);
				A.user=strToKata(User(P).usr);
				A.score=score;
				GetCurrentTime(&A.w);
				AddElmtTabTerurutMengecil(A,&AllHighScores[boardnum]);
				break;
			case 2:
				printf("current board: %d\n",boardnum);
				do{
					printf("Pilih board (0 s.d. 9) :");
					scanf("%d",&boardnum);
				}while (boardnum < 0 || boardnum > 9);
				break;
			case 3:
				PrintUser(P,boardnum);
				break;
			case 4:
				ShowTabTerurutMengecil(AllHighScores[boardnum]);
				break;
			case 5:
				for (i=0;i<10;i++)SaveAllHighScores(AllHighScores[i],highscorefilename(i));
				for (i=0;i<10;i++)SaveQL(Sug[i],suggestionfilename(User(P).usr,i));
				logout=true;break;
			default:
				printf("invalid input\n");
		}		
	}
	
}
#endif
