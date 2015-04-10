#include"point.h"
#include<stdio.h>
#include<math.h>
static const POINT pointnol={0,0};
/* DEFINISI PROTOTIPE PRIMITIF */
/*** Konstruktor membentuk POINT ***/
 POINT MakePOINT (int X, int Y){
	POINT P;
	Absis(P)=X;
	Ordinat(P)=Y;
	return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */
/** Operasi terhadap komponen : selekstor Get dan Set **/
/*** Selektor POINT ***/
int  GetAbsis(POINT P) {
	return Absis(P);
} 
/*Mengirimkan komponen Absis dari P*/
int  GetOrdinat (POINT P) {
	return Ordinat(P);
} 
/* Mengirimkan komponen Ordinat dari P POINT*/
/** Set nilai komponen **/
void SetAbsis(POINT * P,   int newX){
	 Absis(*P)=newX;
	return;
}
/*Menngubah nilai komponen Absis dari P*/
void SetOrdinat (POINT * P,   int newY){
	Ordinat(*P)=newY;
	return;
}
/* Mengubah nilai komponen Ordinat dari P */
/*** Destruktor/Dealokator: tidak perlu ***/
/**** KELOMPOK Interaksi dengan I/O device, BACA/TULIS ****/
void BacaPOINT (POINT * P){
	int x,y;
	/*printf("(XXXX,YYYY)");
	scanf("(%f,%f)",&x,&y);*/
	printf("X=");
	scanf("%d",&x);
	
	printf("Y=");
	scanf("%d",&y);
	SetAbsis(P,x);
	SetOrdinat(P,y);
	
	return;
}
/* Makepoint(x,y,P) membentuk P dari x dan y yang dibaca */
void TulisPOINT(  POINT P){
	printf("(%d,%d)",GetAbsis(P),GetOrdinat(P));
	return;
}
/* Nilai P ditulis ke layar dg format “(X,Y)” */
/*perhatikanlah nama fungsi untuk operator aritmatika dan relasional*/
/* dalam beberapa bahasa, dimungkinkan nama seperti */
/* operator aritmatika untuk numerik dan operator relasional */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE*/
 POINT PPlus (POINT P1, POINT P2) {
	SetAbsis(&P1,GetAbsis(P1)+GetAbsis(P2));
	SetOrdinat(&P1,GetOrdinat(P1)+GetOrdinat(P2));
	return P1;
} 
/* Menghasilkan POINT yang bernilai P1+P2 */
/* Melakukan operasi penjumlahan vektor*/
 POINT PMinus (POINT P1, POINT P2) {
	SetAbsis(&P1,GetAbsis(P1)-GetAbsis(P2));
	SetOrdinat(&P1,GetOrdinat(P1)-GetOrdinat(P2));
	return P1;
} 
/* Menghasilkan POINT bernilai P1-P2 . */
/*Buatlah spesifikasi pengurangan dua buah POINT*/
 int PDot (POINT P1, POINT P2) {
	return GetAbsis(P1)*GetAbsis(P2)+GetOrdinat(P1)*GetOrdinat(P2);
} 
/* Operasi perkalian P1.P2, Melakukan operasi dot product*/
/*** Kelompok operasi relasional terhadap POINT */
 unsigned char EQ(POINT P1, POINT P2) {
	return GetAbsis(P1)==GetAbsis(P2)&&GetOrdinat(P1)==GetOrdinat(P2);
} 
/*Mengirimkan true jika P1 = P2: absis dan ordinatnya sama */
unsigned char  NEQ(POINT P1, POINT P2) {
	return GetAbsis(P1)!=GetAbsis(P2)||GetOrdinat(P1)!=GetOrdinat(P2);
} 
/*Mengirimkan true jika P1 tidak sama dengan P2 */

unsigned char  PLT(POINT P1, POINT P2) {
	if (GetAbsis(P1)<GetAbsis(P2))
		return 1;
	else if(GetAbsis(P1)==GetAbsis(P2) && GetOrdinat(P1)<GetOrdinat(P2))
		return 1;
	else return 0;
} 
/*Mengirimkan true jika P1 < P2. Definisi lebih kecil: lebih “kiri-bawah”
dalam bidang kartesian */ //leksikografis
unsigned char  PGT(POINT P1, POINT P2) {
	if (GetAbsis(P1)>GetAbsis(P2))
		return 1;
	else if(GetAbsis(P1)==GetAbsis(P2) && GetOrdinat(P1)>GetOrdinat(P2))
		return 1;
	else return 0;
} 
/*Mengirimkan true jika P1 > P2. Definisi lebih besar: lebih “kanan-atas”
dalam bidang kartesian */ //leksikografis
/* ** Kelompok menentukan di mana P berada ***/
unsigned char  IsOrigin (POINT P) {
	if (GetAbsis(P)==0 && GetOrdinat(P)==0)
		return 1;
	else return 0;
} 
/* Menghasilkan true jika P adalah titik origin */
unsigned char  IsOnSbX (POINT P){
	if (GetOrdinat(P)==0)
		return 1;
	else return 0;
} 
/* Menghasilkan true jika P terletak Pada sumbu X*/
unsigned char  IsOnSbY (POINT P){
	if (GetAbsis(P)==0)
		return 1;
	else return 0;
} 
/* Menghasilkan true jika P terletak pada sumbu Y*/
int  Kuadran(POINT P) {
	int x,y;
	if (IsOnSbX(P)||IsOnSbY(P))
		return 0;
	else {
		x=GetAbsis(P);
		y=GetOrdinat(P);
		if (x>0)
			if (y>0)
				return 1;
			else	return 4;
		else
			if (y>0)
				return 2;
			else	return 3;
	}
} 
/* Menghasilkan kuadran dari P: 1,2,3, atau 4*/
/* Precondition : P bukan Titik Origin, */
/*
dan P tidak terletak di salah satu sumbu*/
/* ** KELOMPOK OPERASI LAIN TERHADAP TYPE
*/
POINT  NextX (POINT P) {
	SetAbsis(&P,GetAbsis(P)+1);
	return P;
} 
/* Mengirim salinan P dengan absis ditambah satu
*/
POINT  NextY (POINT P) {
	SetOrdinat(&P,GetOrdinat(P)+1);
	return P;
} 
/* Mengirim salinan P dengan ordinat ditambah satu*/
POINT  PlusDelta (POINT P, int DeltaX, int DeltaY) {
	SetAbsis(&P,GetAbsis(P)+DeltaX);
	SetOrdinat(&P,GetOrdinat(P)+DeltaY);
	return P;
} 
/* Mengirim salinan P yang absisnya = Absis(P)+DeltaX dan */
/* Ordinatnya adalah Ordinat(P)+ DeltaY*/
POINT  MirrorOf (POINT P, unsigned char SbX, unsigned char SbY) {
	if (SbY)
		SetAbsis(&P,0-GetAbsis(P));
	if (SbX)
		SetOrdinat(&P,0-GetOrdinat(P));
	return P;
} 
/* Menghasilkan salinan P yang dicerminkan*/
/* tergantung nilai SbX dan SBY*/
/* Jika SbX bernilai true, maka dicerminkan thd Sumbu X*/
/* Jika SbY bernilai true, maka dicerminkan thd Sumbu Y*/
float  Jarak0 (POINT P) {
	return sqrt(GetAbsis(P)*GetAbsis(P)+GetOrdinat(P)*GetOrdinat(P));
} 
/* Menghitung jarak P ke (0,0) */
float  Panjang (POINT P1, POINT P2) {
	P1=PMinus(P1,P2);
	return Jarak0(P1);
} 
/* Menghitung panjang garis yang dibentuk P1 dan P2*/
/* Perhatikanlah bahwa di sini spec fungsi “kurang” baik*/
/* sebab menyangkut ADT Garis!!! */
void Geser (POINT * P,   int DeltaX, int DeltaY){
	if (P){		
		POINT PGeseran;
		PGeseran=MakePOINT(DeltaX,DeltaY);
		*P=PPlus(*P,PGeseran);
	}
	return;
}
/*I.S. P terdefinisi*/
/*F.S. P digeser sebesar DeltaX dan ordinatnya sebesar Delta Y*/
void GeserKeSbX (POINT * P){
	SetOrdinat(P,0);
	return;
}
/*I.S. P terdefinisi*/
/*F.S. P di Sumbu X dg absis sama dg absis semula.
/* Proses :tergeser Ke Sumbu X. */
/* Contoh: Jika koordinat semula(9,9) menjadi (9,0) */
void GeserKeSbY(POINT * P){
	SetAbsis(P,0);
	return;
}
/*I.S. P terdefinisi*/
/*F.S. P di Sumbu Y dengan absis yang sama dengan semula
/* P digeser Ke Sumbu Y. */
/* Contoh: Jika koordinat semula(9,9) menjadi (0,9) */
void Mirror (POINT * P,   unsigned char SbX, unsigned char SbY){
	*P=MirrorOf(*P,SbX,SbY);
	return;
}
/*I.S. P terdefinisi*/
/*F.S. P dicerminkan tergantung nilai SbX atau SBY*/
/* Jika SbX true maka dicerminkan terhadap Sumbu X */
/* Jika SbY true maka dicerminkan terhadap Sumbu Y*/
void Putar (POINT * P,   int sudut){
	POINT dummy;
	int x,y;
	int new_x,new_y;
	int alpha;
	int temp_sudut;
	alpha=sudut*180/M_PI;
	x=GetAbsis(*P);
	y=GetAbsis(*P);
	temp_sudut = asin((x / Jarak0(*P))) + (sudut * M_PI / 180);
	new_x=Jarak0(*P)*sin(temp_sudut);
	new_y=Jarak0(*P)*cos(temp_sudut);


	SetAbsis(&dummy, new_x);
	SetOrdinat(&dummy, new_y);
	*P=dummy;
	return;
}
/*I.S. P terdefinisi*/
/*F.S. P diputar sebesar (Sudut) derajat */
void PutarPoint44 (POINT * p){
/*I.S. P terdefinisi, antara (1,1) s.d. (4,4)*/
/*F.S. P diputar meunjuk sel yang pada matriks 4*4 yang berputar 90 derajat
	CW*/
	int i,j;
	i=GetAbsis(*p);
	j=GetOrdinat(*p);
	SetAbsis(p,j);
	SetOrdinat(p,5-i);
}
