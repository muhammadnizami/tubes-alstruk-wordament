#include<stdio.h>
#include"arraymengecil.h"

TabTerurutMengecil T;
allhighscores X;
Kata kt1;

int main(){
	CreateTabTerurutMengecil(&T);
	
	//CATATAN: Untuk setiap board digunakan file eksternal yang berbeda
	
	//Membaca high scores (top 10) dari file eksternal
	LoadAllHighScores(&T,"file_eks1.txt");
	//printf("%d\n",T.Neff);
	//Sort elemen, misalkan ada yang belum terurut, tapi seharusnya sudah terurut
	SortTabTerurutMengecil(&T);
	//Contoh high score baru yang ingin ditambahkan
	kt1.Length = 5;
	kt1.TabKata[1] = 'c';
	kt1.TabKata[2] = 'h';
	kt1.TabKata[3] = 'i';
	kt1.TabKata[4] = 'b';
	kt1.TabKata[5] = 'i';
	X.user = kt1;
	X.score = 15;
	X.w.TT.DD = 2;
	X.w.TT.MM = 1;
	X.w.TT.YY = 2010;
	X.w.JJ.HH = 20;
	X.w.JJ.MM = 20;
	X.w.JJ.SS = 10;
	
	
	//Setiap kali suatu permainan selesai insert dengan fungsi AddElmtTabTerurutMengecil.
	//Jika masih belum penuh (10 high scores) atau sudah penuh tapi score baru masuk ke dalam top 10, high score
	//baru akan ditambahkan
	//Jika sudah penuh dan score baru tidak masuk top 10, high score baru tidak ditambahkan
	//prosedur AddElmtTabTerurutMengecil sudah dibuat sedimikian
	AddElmtTabTerurutMengecil(X, &T);
	//Menampilkan high scores (top 10) ke layar
	ShowTabTerurutMengecil(T);
	
	//Menyimpan ke file eksternal
	SaveAllHighScores(T,"file_eks1.txt");
	return 0;
}