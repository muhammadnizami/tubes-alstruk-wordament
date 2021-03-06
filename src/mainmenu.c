#include "ADT Boolean/boolean.h"
#include "mainmenu.h"
#include "prepmenu.h"
#include <stdio.h>

void mainmenu(){
	boolean quit;
	int pilihan;
	List UsrList;
	Load(&UsrList);
	quit=false;
	while (!quit){
		printf("Menu:\n1. Register\n2. Login\n3. How to Play\n4. About\n5. Quit\npilihan:");
		scanf("%d",&pilihan);
		switch(pilihan){
			case 1:
				Register(&UsrList);break;
			case 2:
				Login(&UsrList); break;
			case 3:
				HowTo();break;
			case 4:
				About();break;
			case 5:
				Quit(&UsrList,&quit);break;
			default:
				printf("invalid input\n");
		}		
	}
		
}

void Register(List * L){
	InfoUser X;
	char yn[2];
	adrUser P;
	boolean tryagain;
	do{
		printf("username (alfanumerik maks 19 karakter):");
		scanf("%s",X.usr);
		if (FindUser(L,X)!=Nil){
			printf("username sudah dipakai\n");
			printf("coba lagi? (y/n)");
			scanf("%s",yn);
			if (yn[0]=='y')
				tryagain=true;
			else
				tryagain=false;
		}else {
			InsVUser(L,X);
			tryagain=false;
		}
	}while (tryagain);
}

void Login(List * L){
	InfoUser X;
	char yn[2];
	adrUser P;
	boolean tryagain;
	do{
		printf("username:");
		scanf("%s",X.usr);
		P=FindUser(L,X);
		if (P==Nil){
			printf("username tidak ada\n");
			printf("coba lagi? (y/n)");
			scanf("%s",yn);
			if (yn[0]=='y')
				tryagain=true;
			else
				tryagain=false;
		}else {
			printf("user ada\n");
			prepmenu(P);
			tryagain=false;
		}
	}while (tryagain);
}

void HowTo(){

	printf("/************HOW TO PLAY****************/\nRegister if you haven't played before\nLogin if you have played before\nAfter login, choose \"play game\" option to start playing.\nMake words by moving the cursor. the word you're making is indicated by *. try to make as many words as possible.\nControls:\nq: move cursor up-left\nw: move cursor up\ne: move cursor up-right\na: move cursor left\ns: start/finish making a word\nd: move cursor right\nz: move cursor down-left\nx: move cursor down\nc: move cursor down-right\nr: rotate\n");

}

void About(){

	printf("/************ABOUT****************/\nWordament-0 clone\nTugas Besar IF2110 Algoritma dan Struktur Data\n13512501 Muhammad Nizami\n13513039 Ivan Andrianto\n13513045 Ghazwan Sihamudin M\n13513051 Ignatius Alriana\n13513061 Lucky Cahyadi Kurniawan\n\n");

}

void Quit(List * L,boolean * quit){
	*quit=true;
	Save(*L);
}
