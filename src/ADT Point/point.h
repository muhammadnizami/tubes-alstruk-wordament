#ifndef point_h
#define point_h

#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* Definisi ABSTRACT DATA TYPE POINT */
typedef struct dummystrtag{
		int X; /* absis */
		int Y;	/* ordinat*/ 
} POINT ;
static const POINT pointnol;
/* DEFINISI PROTOTIPE PRIMITIF */
/*** Konstruktor membentuk POINT ***/
 POINT MakePOINT (int X, int Y); 
/* Membentuk sebuah POINT dari komponen-komponennya */
/** Operasi terhadap komponen : selekstor Get dan Set **/
/*** Selektor POINT ***/
int  GetAbsis(POINT P) ; 
/*Mengirimkan komponen Absis dari P*/
int  GetOrdinat (POINT P) ; 
/* Mengirimkan komponen Ordinat dari P POINT*/
/** Set nilai komponen **/
void SetAbsis(POINT * P,   int newX);
/*Menngubah nilai komponen Absis dari P*/
void SetOrdinat (POINT * P,   int newY);
/* Mengubah nilai komponen Ordinat dari P */
/*** Destruktor/Dealokator: tidak perlu ***/
/**** KELOMPOK Interaksi dengan I/O device, BACA/TULIS ****/
void BacaPOINT (POINT * P);
/* Makepoint(x,y,P) membentuk P dari x dan y yang dibaca */
/* Pembacaan dilakukan dari stdin dengan format (xxxx,yyyy)\n*/
void TulisPOINT(  POINT P);
/* Nilai P ditulis ke layar dg format “(X,Y)” */
/*perhatikanlah nama fungsi untuk operator aritmatika dan relasional*/
/* dalam beberapa bahasa, dimungkinkan nama seperti */
/* operator aritmatika untuk numerik dan operator relasional */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE*/
// *******************DIKTAT ******************
 POINT PPlus (POINT P1, POINT P2) ; 
/* Menghasilkan POINT yang bernilai P1+P2 */
/* Melakukan operasi penjumlahan vektor*/
 //POINT PMinus (POINT P1, POINT P2) ; 
/* Menghasilkan POINT bernilai P1-P2 . */
/*Buatlah spesifikasi pengurangan dua buah POINT*/
 //int PDot (POINT P1, POINT P2) ; 
/* Operasi perkalian P1.P2, Melakukan operasi dot product*/
/*** Kelompok operasi relasional terhadap POINT */
// ***************MODUL PRAKTIKUM*****************
 unsigned char EQ(POINT P1, POINT P2) ; 
/*Mengirimkan true jika P1 = P2: absis dan ordinatnya sama */
unsigned char  NEQ(POINT P1, POINT P2) ; 
/*Mengirimkan true jika P1 tidak sama dengan P2 */
/*
	******* INI DARI ADT DI DIKTAT *******

unsigned char  PLT(POINT P1, POINT P2) ; 
/*Mengirimkan true jika P1 < P2. Definisi lebih kecil: lebih “kiri-bawah”
dalam bidang kartesian */ //leksikografis
//unsigned char  PGT(POINT P1, POINT P2) ; 
/*Mengirimkan true jika P1 > P2. Definisi lebih besar: lebih “kanan-atas”
dalam bidang kartesian */ //leksikografis

// *************MULAI INI KEMBALI LAGI KE MODUL PRAKTIKUM

/* ** Kelompok menentukan di mana P berada ***/
unsigned char  IsOrigin (POINT P) ; 
/* Menghasilkan true jika P adalah titik origin */
unsigned char  IsOnSbX (POINT P); 
/* Menghasilkan true jika P terletak Pada sumbu X*/
unsigned char  IsOnSbY (POINT P); 
/* Menghasilkan true jika P terletak pada sumbu Y*/
int  Kuadran(POINT P) ; 
/* Menghasilkan kuadran dari P: 1,2,3, atau 4*/
/* Precondition : P bukan Titik Origin, */
/*
dan P tidak terletak di salah satu sumbu*/
/* ** KELOMPOK OPERASI LAIN TERHADAP TYPE
*/
POINT  NextX (POINT P) ; 
/* Mengirim salinan P dengan absis ditambah satu
*/
POINT  NextY (POINT P) ; 
/* Mengirim salinan P dengan ordinat ditambah satu*/
POINT  PlusDelta (POINT P, int DeltaX, int DeltaY) ; 
/* Mengirim salinan P yang absisnya = Absis(P)+DeltaX dan */
/* Ordinatnya adalah Ordinat(P)+ DeltaY*/
POINT  MirrorOf (POINT P, unsigned char SbX, unsigned char SbY) ; 
/* Menghasilkan salinan P yang dicerminkan*/
/* tergantung nilai SbX dan SBY*/
/* Jika SbX bernilai true, maka dicerminkan thd Sumbu X*/
/* Jika SbY bernilai true, maka dicerminkan thd Sumbu Y*/
float  Jarak0 (POINT P) ; 
/* Menghitung jarak P ke (0,0) */
float  Panjang (POINT P1, POINT P2) ; 
/* Menghitung panjang garis yang dibentuk P1 dan P2*/
/* Perhatikanlah bahwa di sini spec fungsi “kurang” baik*/
/* sebab menyangkut ADT Garis!!! */
void Geser (POINT * P,   int DeltaX, int DeltaY);
/*I.S. P terdefinisi*/
/*F.S. P digeser sebesar DeltaX dan ordinatnya sebesar Delta Y*/
void GeserKeSbX (POINT * P);
/*I.S. P terdefinisi*/
/*F.S. P di Sumbu X dg absis sama dg absis semula.
/* Proses :tergeser Ke Sumbu X. */
/* Contoh: Jika koordinat semula(9,9) menjadi (9,0) */
void GeserKeSbY(POINT * P);
/*I.S. P terdefinisi*/
/*F.S. P di Sumbu Y dengan absis yang sama dengan semula
/* P digeser Ke Sumbu Y. */
/* Contoh: Jika koordinat semula(9,9) menjadi (0,9) */
void Mirror (POINT * P,   unsigned char SbX, unsigned char SbY);
/*I.S. P terdefinisi*/
/*F.S. P dicerminkan tergantung nilai SbX atau SBY*/
/* Jika SbX true maka dicerminkan terhadap Sumbu X */
/* Jika SbY true maka dicerminkan terhadap Sumbu Y*/
void Putar (POINT * P,   int sudut);
/*I.S. P terdefinisi*/
/*F.S. P diputar sebesar (Sudut) derajat */

void PutarPoint44 (POINT * p);
/*I.S. P terdefinisi, antara (1,1) s.d. (4,4)*/
/*F.S. P diputar meunjuk sel yang pada matriks 4*4 yang berputar 90 derajat
	CW*/


#endif
