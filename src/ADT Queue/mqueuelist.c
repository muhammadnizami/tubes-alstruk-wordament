#include<stdio.h>
#include "queuelist.h"

int main(){
	Queue Q,Q2,Q3;
	infotypeQL kt1, kt2;
	address P;
	CreateEmptyQL(&Q);
	LoadQL(&Q,"kataditebak1.txt");
	
	
	//Contoh pengunaan copy, isi dari Q dicopy ke dalam Q2
	//Q2 inilah yang akan disimpan ke file eksternal dan ditambahkan kata baru yang belum ditebak
	CopyQL(Q,&Q2);
	
	//Misalkan ini kata yang mau ditambahkan
	kt1.Length = 5;
	kt1.TabKata[1] = 'c';
	kt1.TabKata[2] = 'h';
	kt1.TabKata[3] = 'i';
	kt1.TabKata[4] = 'b';
	kt1.TabKata[5] = 'i';
	
	//Misalkan ini kata lain yang mau ditambahkan
	kt2.Length = 5;
	kt2.TabKata[1] = 'a';
	kt2.TabKata[2] = 'h';
	kt2.TabKata[3] = 'i';
	kt2.TabKata[4] = 'b';
	kt2.TabKata[5] = 'i';
	
	//Jika dalam permainan kata yang berada dilist ditebak, maka hapus kata tersebut dari Q
	//Masalahnya tidak selalu kata yang berada di head yang ditebak oleh user, bisa saja kata di tengah-tengah queue
	//sehingga perlu dibuat queue baru misalkan Q3 yang berisi kata-kata yang ditebak saat permainan yang sedang dijalankan
	CreateEmptyQL(&Q3);
	//CATATAN, berikut ini cuma saran tapi belum dapat ditest karena belum ada file permainan
	//Setiap berhasil menebak kata dari kamus:
	//- cek apakah kata sudah pernah ditebak dalam permainan kali ini dengan IsMemberQL(Q3,Info(Head(Q)))
	//- Jika menghasilkan true, berarti sudah ditebak
	//- Jika menghasilkan false, berarti belum ditebak
	//- tambahkan ke Q3 jika belum ditebak, misalkan AddUniqueQL(&Q3,kt1);
	//- cek apakah head dari Q sama dengan salah satu kata dari Q3 dengan function IsMemberQL(Q3,Info(Head(Q)))
	//jika ya, maka head(Q) dihapus dengan
	//DelQL(&Q,&kt1);
	//Gunakan loop, mungkin seperti ini
	/*
	while((IsMemberQL(Q3,Info(Head(Q)))) && !(IsEmptyQL(Q))){
		DelQL(&Q,&kt1);
	}
	*/
	//loop digunakan karena misalnya kasus berikut:
	//user menebak kata di urutan ke-2 dari Q
	//karena Head(Q) bukan member dari Q3, maka tidak dihapus
	//misalkan user berhasil menebak kata yang ada di head(Q)
	//maka Head(Q) dihapus, tetapi jika loop tidak digunakan, maka penghapusan hanya akan dilakukan pada head,
	//sedangkan elemen berikutnya tidak dihapus
	//sehingga digunakan loop
	
	//selain itu, setiap kata yang ditebak juga ditambahkan ke Q2 dengan cara sebagai berikut:
	//Jika dalam permainan user menebak suatu kata, gunakan AddUniqueQL agar dilakukan pengecekan apakah kata
	//sudah pernah ditebak atau belum, jika belum pernah tambahkan ke Q2 (hasil copy), bukan Q
	//Jangan menggunakan AddQL karena jika kata sudah pernah ditebak sebelumnya akan ditambahkan lagi
	AddUniqueQL(&Q2,kt1);
	AddUniqueQL(&Q2,kt2);
	
	printf("Isi Q2 setelah AddUniqueQL\n");
	PrintQL(Q2);
	printf("\n");

	//Simpan hasilnya di file eksternal, yang disimpan adalah Q2 bukan Q
	SaveQL(Q2,"kataditebak1.txt");
	return 0;
}
