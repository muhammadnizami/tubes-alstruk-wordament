#ifndef score_h
#define score_h

#include "../ADT Mesin Kata/mesinkata1.h"

#define mapidxundef -999
#define mapvalundef 0

extern const int AlphabeticalScoreMap[];


int hashfunction(char key);
//mengembalikan indeks map untuk huruf inchar. bila tidak ada, kembalikan mapidxundef

int getTabVal(int idx);
//mengembalikan value dari elemen tabel ke-i
//bila idx==mapidxundef, kembalikan mapvalundef

int getMapVal(char key);
//mengembalikan value untuk map. bila tidak ada, kembalikan mapvalundef

int getscore(Kata K);
//mengembalikan score dari kata K dengan spesifikasi sebagai berikut:
//skor = total seluruh huruf pada kata tersebut * panjang kata + bonus kata panjang
//Bonus kata panjang diberikan khusus untuk kata yang lebih atau sama dengan 10 huruf. Besar bonus adalah 100 poin.
//prekondisi: kata K ada di dictionary

#endif
