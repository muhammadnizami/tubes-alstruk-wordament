#include <stdio.h>
#include <stdlib.h>
#include "../String/_string.h"
#include "../ADT Multi List/multilistv5.h"
#include "../ADT Jam + Tanggal/waktu.h"
#include "../ADT Jam + Tanggal/jam.h"
#include "../ADT Jam + Tanggal/tanggal.h"
#include "../ADT Mesin Kata/mesinkata1.h"

#define HIGHSCOREPATH "data/High Score.txt"

//(*** Test List Kosong ***))))))
int IsListEmpty(List L){
//Mengirimkan true jika list kosong: First(L) = Nil dan Last(L) = Nil.
    return ((FirstUser(L)==Nil) && (LastUser(L)==Nil));
}

//(***Pembuatan List Kosong ***)
void CreateList(List *L){
// I.S. Sembarang.
// F.S. Terbentuk list kosong.
    FirstUser(*L)=Nil;
    LastUser(*L)=Nil;
}

//(***Manajemen Memori ***)
adrUser AlokasiUser(InfoUser X){
/*  Mengirimkan address hasil alokasi untuk User.
    Jika alokasi berhasil, maka address tidak Nil, dan jika menghasilkan address P,
    maka User(P) = X, P->FirstScore[10] = Nil, NextUser(P)=Nil, PrevUser(P)=Nil.
    Jika alokasi gagal, mengirimkan Nil
*/
//Kamus Lokal
    adrUser P;
    int i;
//Algoritma
    P=(adrUser) malloc (sizeof(ElmUser));
    if (P!=Nil){
        User(P)=X;
        for (i=0;i<10;i++) P->FirstScore[i]=Nil;
        NextUser(P)=Nil;
        PrevUser(P)=Nil;
    }
    return P;
}
adrScore AlokasiScore(int X){
/*  Mengirimkan address hasil alokasi untuk Score.
    Jika alokasi berhasil, maka address tidak Nil, dan jika mengjasilkan address P,
    maka Waktu(P) = Waktu Alokasi skor, Score (P).scr= X, NextScore(P)=Nil.
    Jika alokasi gagal, mengirimkan Nil*/
//Kamus Lokal
    adrScore P;
   
//Algoritma
    P=(adrScore) malloc (sizeof(ElmScore));
    if (P!=Nil){
        GetCurrentTime(&(Waktu(P)));
        Score(P).scr=X;
        NextScore(P)=Nil;
    }
    return P;
}
adrScore AlokDariFile(unsigned char H, unsigned char B,unsigned char T,int J,int M,int D,int Skor){
//Kamus Lokal
  JAM A;
  TANGGAL C;
  WAKTU E;
  adrScore P;
//Algoritma
  C = MakeTANGGAL(H,B,T);
  A = MakeJAM(J,M,D);
  P = (adrScore) malloc (sizeof(ElmScore));
  if (P!=Nil){
    Waktu(P)=MakeWAKTU(C,A);
    Score(P).scr=Skor;
    NextScore(P)=Nil;
  }
  return P;
}
void DealokasiUser(adrUser P){
/*  I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
    Melakukan dealokasi/pengembalian address P*/
    free(P);
}
void DealokasiScore(adrScore Q){
/*  I.S. Q terdefinisi
    F.S. Q dikembalikan ke sistem
    Melakukan dealokasi/pengembalian address Q*/
    free(Q);
}

//(*** Pencarian Elemen List ***)
adrUser FindUser(List *L,InfoUser X){
/*Mengirimkan address P, di mana User(P)=X
Jika tidak ditemukan mengirimkan Nil */
//Kamus Lokal
    adrUser P;
//Algoritma
    P=FirstUser(*L);
    if(IsListEmpty(*L)){
        P=Nil;
    }
    else{
        while((NextUser(P)!=Nil)&&((_strcmp(User(P).usr,X.usr))!=0)) P=NextUser(P);
        if ((_strcmp(User(P).usr,X.usr))!=0) P=Nil;
    }
    return P;
}

//(*** Penambahan Elemen ***)
void InsVUser (List *L,InfoUser X){
/*  I.S.*L merupakan list sembarang
    F.S. X dimasukkan ke dalam list */
    InsertLast(&(*L),AlokasiUser(X));
    Changed=1;
}

void InsVScore(adrUser P, int Y,int BoardNumber){
    InsertScore(P,AlokasiScore(Y),BoardNumber);
    Changed=1;
}

void InsertScore(adrUser P,adrScore Q,int BoardNumber){
//Kamus Lokal
    adrScore temp,prec,after;
    int i,X;
//Algoritma
    if(P!=Nil)
    {
        if((P->FirstScore[BoardNumber])!=Nil)
        {
            temp = P->FirstScore[BoardNumber]; 
            prec = Nil;
            while ((temp)!=Nil) {
              if(Score(Q).scr < Score(temp).scr){
              prec = temp;
              }
              temp = NextScore(temp);
            }
            if (prec == Nil) {
              NextScore(Q)=P->FirstScore[BoardNumber];
              P->FirstScore[BoardNumber]=Q;
            }
            else {
              NextScore(Q)=NextScore(prec);
              NextScore(prec)=Q;
            }
            i=0;
            temp=P->FirstScore[BoardNumber];
            while ((temp)!=Nil){
              i++;
              temp=NextScore(temp);
            }
            if (i>10) DelVScoreLast(P,&X,BoardNumber);
        }
        else
        { 
             P->FirstScore[BoardNumber]=Q;
        }
    Changed=1;
   }
   else if(P==Nil){
        printf("User Not Found\n");
   }
}


void InsertFirst (List *L,adrUser P){
//{ I.S. Sembarang, P sudah dialokasi }
//{ F.S. Menambahkan elemen ber-address P sebagai elemen pertama }
    NextUser(P)=FirstUser(*L);
    if (IsListEmpty(*L)){
        LastUser(*L)=P; 
    }else{
        PrevUser(FirstUser(*L))=P;
    } 
    FirstUser(*L)=P;
    Changed=1;
}
void InsertLast (List *L, adrUser P){
//{ I.S. Sembarang, P sudah dialokasi }
//{ F.S. P ditambahkan sebagai elemen terakhir yang baru, }
//{ yaitu menjadi elemen sebelum dummy }
//Kamus Lokal
//Algoritma
    PrevUser(P)=LastUser(*L);
    if (IsListEmpty(*L)) InsertFirst(&(*L),P);
    else{ 
        NextUser(LastUser(*L))=P;
    }
    LastUser(*L) = P;
    Changed=1;
}

//(*** Penghapusan ELemen List ***)
void DelScoreLast (adrUser P, adrScore *Q,int BoardNumber){
//{ I.S. List tidak kosong }
//{ F.S. P adalah alamat elemen terakhir list sebelum penghapusan }
//{ Elemen list berkurang satu (mungkin menjadi kosong) }
//{ Last element baru adalah predesesor elemen pertama yang lama, jika ada }
//Kamus Lokal
  adrScore Last, PrecLast;
//Algoritma
  Last=P->FirstScore[BoardNumber];
  PrecLast=Nil;
  while (NextScore(Last)!= Nil){
    PrecLast=Last;
    Last=NextScore(Last);
  }
  (*Q)=Last;
  if (PrecLast==Nil) *Q=Nil;
  else NextScore(PrecLast)=Nil;
    Changed=1;
}

void DelVScoreLast (adrUser P, int *X,int BoardNumber ){
//{ I.S. list tidak kosong }
//{ F.S. Elemen terakhir list dihapus : nilai info disimpan pada X }
//{ dan alamat elemen terakhir di-dealokasi }
//Kamus Lokal
  adrScore Q;
//Algoritma
  DelScoreLast(P,&Q,BoardNumber);
  *X = Score(Q).scr;
  DealokasiScore(Q);
    Changed=1;
}
//(*** Pemrosesan semua elemen list ***)
void PrintUser(adrUser P,int BoardNumber){
/*  I.S. P terdefinisi
    F.S. Menuliskan semua skor pada board dengan nomor BoardNumber ke layar */
//Kamus Lokal
    adrScore Q;
//Algoritma
    printf("User : %s\n",User(P).usr);    
    if (P->FirstScore[BoardNumber]== Nil) printf("Highscore Board %d masih kosong\n",BoardNumber);
    else {
        printf("Board %d\n",BoardNumber );
        Q = P->FirstScore[BoardNumber];
        while (Q!=Nil){
           TulisWAKTU(Waktu(Q));
           printf(" %d\n",Score(Q).scr);
           Q=NextScore(Q);
        }
    }
}

void Save (List L){
/* I.S. */
/* F.S. */
//Kamus Lokal
  adrUser P;
  adrScore Q;
  int i;
  char c[20];
//Algoritma
  if(Changed){
    FILE *f = fopen(HIGHSCOREPATH, "wb");
    if (f == NULL)
    {
      printf("Error opening file!\n");
    }
    else {
      P=FirstUser(L);
      while (P!=Nil){

        _strcpy(c,User(P).usr);
        fprintf(f,"+ ");
        fprintf(f, "%s\n", c);
        for (i=0;i<10;i++){
          fprintf(f, "Board %d\n",i);
          Q=P->FirstScore[i];
          while (Q!=Nil){
            fprintf(f, "%d ", Day(GetTanggal(Waktu(Q))));
            fprintf(f, "%d ", Month(GetTanggal(Waktu(Q))));
            fprintf(f, "%d ", Year(GetTanggal(Waktu(Q))));
            fprintf(f, "%d ", GetHour(GetJam(Waktu(Q))));              
            fprintf(f, "%d ", GetMinute(GetJam(Waktu(Q))));              
            fprintf(f, "%d ", GetSecond(GetJam(Waktu(Q)))); 
            fprintf(f, "%d\n", Score(Q).scr); 

            Q=NextScore(Q);            
          }
        }
        P=NextUser(P);
      }
    }
    fprintf(f,".");
    fclose(f);
  } else {
    //Tidak perlu mengupdate file eksternal
  }
  Changed = 0;
}

KataToStr(char * dest, Kata K){
//Kamus Lokal
  int i;
//Algoritma
  for (i=1;i<=K.Length;i++)
    dest[i-1]=K.TabKata[i];
  dest[K.Length]='\0';
}


//mengecek apakah ada file
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int __doesFileExist(const char *filename) {
    struct stat st;
    int result = stat(filename, &st);
    return result == 0;
}

void Load(List *L){
	
	
	Kata plus;
	plus.TabKata[1]='+';
	plus.Length=1;
	
	Kata board;
	board.TabKata[1]='B';
	board.TabKata[2]='o';
	board.TabKata[3]='a';
	board.TabKata[4]='r';
	board.TabKata[5]='d';
	board.Length=5;
	
	InfoUser X;
	adrUser P;
	
	int curBoard;
	
	unsigned char day,month,hh,mm,ss;
	unsigned short year;
	
	int curScore;
	
	adrScore PS;
	
	CreateList(L);
		
	if (__doesFileExist(HIGHSCOREPATH)){
		STARTKATA(HIGHSCOREPATH);
		while (!EndKata){
			if (IsKataSama(CKata,plus)){
				ADVKATA();
				KataToStr(X.usr,CKata);
				P=AlokasiUser(X);
				InsertLast(L,P);
				ADVKATA();
			}else if (IsKataSama(CKata,board)){
				ADVKATA();
				curBoard=kataToInt(CKata);
				ADVKATA();
			}else{
				day=kataToInt(CKata);ADVKATA();
				month=kataToInt(CKata);ADVKATA();
				year=kataToInt(CKata);ADVKATA();
				hh=kataToInt(CKata);ADVKATA();
				mm=kataToInt(CKata);ADVKATA();
				ss=kataToInt(CKata);ADVKATA();
				curScore=kataToInt(CKata);ADVKATA();
				PS=AlokasiScore(curScore);
				PS->W=MakeWAKTU(MakeTANGGAL(day,month,year),MakeJAM(hh,mm,ss));
				InsertScore(P,PS,curBoard);
			}
		}
	}
    Changed=0;
}
