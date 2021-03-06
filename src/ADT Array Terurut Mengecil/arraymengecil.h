#ifndef ARRAYMENGECIL_H
#define ARRAYMENGECIL_H

#include "../ADT Jam + Tanggal/waktu.h"
#include "../ADT Boolean/boolean.h"
#include "../ADT Mesin Kata/mesinkata1.h"
#include "../ADT Mesin Kata/mesinkar1.h"

#ifndef MaxTabTerurutMengecilElmt
#define MaxTabTerurutMengecilElmt 10
#endif

#ifndef ValUndef
#define ValUndef -9999
#endif

typedef int idx;
typedef struct{
	Kata user;
	WAKTU w;/* terdiri dari jam dan tanggal */
	int score;
	
} allhighscores;
typedef struct{
	allhighscores Tb[11];
	int Neff;
}TabTerurutMengecil;

typedef struct{
	int Tz[5];
	int Neffz;
}Tabz;

boolean isTabTerurutMengecilChanged;

void CreateTabTerurutMengecil(TabTerurutMengecil *T);
/* I.S. sembarang */
/* F.S. membentuk TabHighScores kosong dengan Neff = 0 */

void LoadAllHighScores(TabTerurutMengecil *T, char* namafile);
/* I.S. T kosong */
/* F.S. Membaca data dari file eksternal sehingga seluruh data dari file eksternal disimpan */
/*     ke dalam T selama belum mencapai end of file (.) dan T belum penuh(seharusnya tidak mungkin penuh) */
/*     dengan menggunakan proesedur AddElmtTabTerurutMengecil */

boolean IsTabTerurutMengecilEmpty(TabTerurutMengecil T);
/* menghasilkan true jika T empty, yaitu Neff = 0 */

boolean IsTabTerurutMengecilFull(TabTerurutMengecil T);
/* menghasilkan true jika T penuh, yaitu Neff = MaxTabTerurutMengecilElmt */

int MinTabTerurutMengecil(TabTerurutMengecil T);
/* menghasilkan nilai score minimum dari T */

void AddSortedElement(allhighscores X, TabTerurutMengecil *T);
/* I.S. T tidak penuh */
/* F.S. Elemen T bertambah 1 secara terurut */

void AddElmtTabTerurutMengecil(allhighscores X, TabTerurutMengecil *T);
/* I.S. T terurut mengecil */
/* F.S. Menambahkan elemen secara terurut jika Tab belum penuh atau Tab sudah penuh tetapi ada high score baru yang  */
/*         menghapus elemen yang paling kecil */

void DelLastElmtTabTerurutMengecil(allhighscores *X, TabTerurutMengecil *T);
/* I.S. T tidak kosong */
/* F.S. Elemen terakhir yang nilai elemennya paling kecil dihapus */

void SortTabTerurutMengecil(TabTerurutMengecil *T);
/* I.S. T tidak kosong */
/* F.S. Elemen T terurut mengecil berdasarkan score */

void ShowTabTerurutMengecil(TabTerurutMengecil T);
/* I.S. T semabarang */
/* F.S. Menulis isi dari highscore ke layar */

void SaveAllHighScores(TabTerurutMengecil T, char* namafile);
/* I.S. T terisi */
/* F.S. Menulis isi dari highscore ke file eksternal jika ada perubahan */
#endif
