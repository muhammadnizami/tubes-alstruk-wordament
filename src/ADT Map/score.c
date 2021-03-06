#ifndef score_c
#define score_c

#include "score.h"

const int AlphabeticalScoreMap [] ={2,5,3,3,1,5,4,4,2,10,6,3,4,2,2,4,10,2,2,2,4,6,6,9,5,8};

int hashfunction(char key){
//mengembalikan indeks map untuk huruf inchar. bila tidak ada, kembalikan mapidxundef
//A s.d. Z: key-'A'
//a s.d. z: key-'a'
//lainnya: undef
	if (key>='A' && key<='Z') return key-'A';
	else if (key>='a' && key <='z') return key-'a';
	else return mapidxundef;
	
}


int getTabVal(int idx){
//mengembalikan value dari elemen tabel ke-i
//bila idx==mapidxundef, kembalikan mapvalundef
	if (idx!=mapidxundef) return AlphabeticalScoreMap[idx];
	else return mapvalundef;
}

int getMapVal(char key){
//mengembalikan value untuk map. bila tidak ada, kembalikan mapvalundef
	return getTabVal(hashfunction(key));
}

int getscore(Kata K){
//mengembalikan score dari kata K dengan spesifikasi sebagai berikut:
//skor = total seluruh huruf pada kata tersebut * panjang kata + bonus kata panjang
//Bonus kata panjang diberikan khusus untuk kata yang lebih atau sama dengan 10 huruf. Besar bonus adalah 100 poin.
//prekondisi: kata K ada di dictionary
	int i;
	int sum=0;
	int bonuskatapanjang;
	for (i=1;i<=K.Length;i++)
		sum+=getMapVal(K.TabKata[i]);
	if (K.Length>=10) bonuskatapanjang=100; else bonuskatapanjang=0;
	return sum*K.Length+bonuskatapanjang;
}

#endif
