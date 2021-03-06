#ifndef MESINKATA1_C
#define MESINKATA1_C
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include "../ADT Boolean/boolean.h"
#include "mesinkata1.h"

/* { ***** Mesin lain yang dipakai ***** } */
//use MESINKAR

/* { TabKata adalah tempat penampung/container kata, Length menyatakan panjangnya kata }
{ ***** Definisi State Mesin Kata ***** } */
boolean EndKata; //{ penanda akhir akuisisi kata }
Kata CKata; //{ kata yang sudah diakuisisi dan akan diproses }
char CC;

/* { ***** Primitif-Primitif Mesin Kata ***** } */
void Ignore_Blank(){
/* { Mengabaikan satu atau beberapa BLANK }
{ I.S. : CC sembarang }
{ F.S. : CC ≠ BLANK atau CC = MARK } */
	while (((CC == BLANK)||(CC == '\n')) && (CC != MARK)) {
		ADV();
	}
}
void STARTKATA(char* namafile){
/* { I.S. : CC sembarang }
{ F.S. : EndKata = true, dan CC = Mark; }
{        atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
		 CC karakter pertama sesudah karakter terakhir kata } */
	START(namafile);
	Ignore_Blank();
	if (CC == MARK) {
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA(){
/* { I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
     dari kata yg sudah diakuisisi } { F.S. : Jika CC = MARK, maka EndKata = true
     atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
     CC karakter pertama sesudah karakter terakhir kata } */
	Ignore_Blank();
	if(CC == MARK){
		EndKata = true;
	} else {
		SalinKata();
	}
}

void SalinKata(){
/* { Mengakuisisi kata, menyimpan dalam CKata }
{ I.S. : CC adalah karakter pertama dari kata }
{ F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
           NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
           karakter sesudah karakter terakhir yang diakuisisi } */
	int i = 1;
	for(;;) {
		if(CC == '\n'){
			ADV();
		}
		CKata.TabKata[i] = CC;
		ADV();
		if((CC == MARK) || (CC == BLANK) || (CC == '\n')){
			break;
		} else {
			i++;
		}
	}
	CKata.Length = i;
}

/* { ***** Operasi Lain ***** } */
boolean IsKataSama (Kata K1, Kata K2){
/* { Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama
 dan urutan karakter yang menyusun kata juga sama } */
	if(K1.Length != K2.Length){
		return false;
	} else {
		int i = 1;
		boolean sama = true;
		while(sama && (i<= K1.Length)){
			if(K1.TabKata[i] != K2.TabKata[i]){
				sama = false;
			}
			i++;
		}
		return sama;
	}
 
 }
 
void PrintKata(Kata K){
	int i = 1;
	while (i <= K.Length){
		printf("%c",K.TabKata[i]);
		i++;
	}
	printf(" ");
 }
 
int convertToInt(char C){
	switch(C){
		case '0': return 0; break;
		case '1': return 1; break;
		case '2': return 2; break;
		case '3': return 3; break;
		case '4': return 4; break;
		case '5': return 5; break;
		case '6': return 6; break;
		case '7': return 7; break;
		case '8': return 8; break;
		case '9': return 9; break;
	}
}

int kataToInt(Kata K){
/* I.S. Kata berisi kumpulan karakter 0 sampai 9 */
/* F.S. Kata diubah menjadi integer */
	int i = 1;
	int s = 0;
	int pgkt;
	while(i<=K.Length){
		pgkt = pow(10,K.Length - i);
		s += convertToInt(K.TabKata[i]) * pgkt;
		i++;
	}
	return s;
}
 #endif
