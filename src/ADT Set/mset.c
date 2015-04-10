#include<stdio.h>
#include "set.h"

int main(){
	SET s,s2,s3;
	
	CreateEmptySET(&s);
	LoadSET(&s,"Dictionary.txt");
	
	printf("Isi s\n");
	PrintSET(s);
	printf("NbElmtSET = %d\n",NbElmtSET(s));
	printf("\n");
	
	//Copy set
	CopySET(s,&s2);
	printf("Hasil Copy s (s2)\n");
	PrintSET(s2);
	printf("NbElmtSET2 = %d\n",NbElmtSET(s));
	printf("\n");
	
	//Saat permainan, jika ingin menambahkan suatu kata ke dalam set, gunakan InsertElmtUniqueSET
	
	//Kata yang ingin ditambahkan
	Kata kt1;
	kt1.Length = 5;
	kt1.TabKata[1] = 'z';
	kt1.TabKata[2] = 'z';
	kt1.TabKata[3] = 'z';
	kt1.TabKata[4] = 'z';
	kt1.TabKata[5] = 'z';
	InsertElmtUniqueSET(&s,kt1);
	
	//Isi s setelah ditambah suatu kata
	printf("Isi s\n");
	PrintSET(s);
	printf("NbElmtSET = %d\n",NbElmtSET(s));
	printf("\n");
	
	//Jika kata yang sudah ada ditambahkan, s tidak berubah
	//Misalkan 'ABACUS' sudah ada
	kt1.Length = 6;
	kt1.TabKata[1] = 'A';
	kt1.TabKata[2] = 'B';
	kt1.TabKata[3] = 'A';
	kt1.TabKata[4] = 'C';
	kt1.TabKata[5] = 'U';
	kt1.TabKata[6] = 'S';
	InsertElmtUniqueSET(&s,kt1);
	
	//Isi s tidak berubah jika ditambahkan kata yang sama
	printf("Isi s\n");
	PrintSET(s);
	printf("NbElmtSET = %d\n",NbElmtSET(s));
	printf("\n");
	
/*
	//Hasil Union s dan s2
	printf("Hasil Union s dan s2 (s3)\n");
	UnionSET(s,s2,&s3);
	PrintSET(s3);
	printf("NbElmtSET3 = %d\n",NbElmtSET(s));*/

	DeleteSET(&s);
	PrintSET(s);
	return 0;
}
