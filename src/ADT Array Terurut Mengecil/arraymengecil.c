#include <stdio.h>
#include "arraymengecil.h"
#include <math.h>

FILE * filehighscores;
char bufchar;
Kata Kata2;

void CreateTabTerurutMengecil(TabTerurutMengecil *T){
/* I.S. sembarang */
/* F.S. membentuk TabHighScores kosong dengan Neff = 0 */
	(*T).Neff = 0;
}

void LoadAllHighScores(TabTerurutMengecil *T, char* namafile){
/* I.S. T kosong */
/* F.S. Membaca data dari file eksternal sehingga seluruh data dari file eksternal disimpan */
/*     ke dalam T selama belum mencapai end of file (.) dan T belum penuh(seharusnya tidak mungkin penuh) */
/*     dengan menggunakan proesedur AddElmtTabTerurutMengecil */
	//Baca dari file eksternal		
		STARTKATA(namafile);
		int z=1;
		idx n;
		int i;
		int s;
		int x = 1;
		int tanggal, bulan, tahun, jam, menit, detik;
		TANGGAL tgl;
		JAM j;
		(*T).Neff = 0;
		while(!EndKata){
			//Baca user
			(*T).Tb[x].user = CKata;
			ADVKATA();
			
			//Baca score
			(*T).Tb[x].score = kataToInt(CKata);
			ADVKATA();
			
			//Baca tanggal
			tanggal = kataToInt(CKata);
			ADVKATA();
			
			//Baca bulan
			bulan = kataToInt(CKata);
			ADVKATA();
			
			//Baca tahun
			tahun = kataToInt(CKata);
			ADVKATA();
			
			//Baca jam
			jam = kataToInt(CKata);
			ADVKATA();
			
			//Baca menit
			menit = kataToInt(CKata);
			ADVKATA();
			
			//Baca detik
			detik = kataToInt(CKata);
			ADVKATA();
			
			//MakeTanggal
			tgl = MakeTANGGAL(tanggal,bulan,tahun);
			
			//MakeJAM
			j = MakeJAM(jam,menit,detik);
			//MakeWAKTU
			(*T).Tb[x].w = MakeWAKTU (tgl,j);
			
			x++;
		
			/*n = ((z-1)/8) + 1;
			if(n>10){
				n = 10;
				break;
			}
			if((z % 8) == 1){
				(*T).Tb[n].user = CKata;
			} else if((z % 8) == 2){
				i = 1;
				s = 0;
				int pgkt;
				while(i<=CKata.Length){
					pgkt = pow(10,CKata.Length - i);
					s += convertToInt(CKata.TabKata[i]) * pgkt;
					i++;
				}
				(*T).Tb[n].score = s;
			} else if((z % 8) == 3){
				i = 1;
				s = 0;
				int pgkt;
				while(i<=CKata.Length){
					pgkt = pow(10,CKata.Length - i);
					s += convertToInt(CKata.TabKata[i]) * pgkt;
					i++;
				}
				(*T).Tb[n].w.TT.DD = s;
			} else if((z % 8) == 4){
				i = 1;
				s = 0;
				int pgkt;
				while(i<=CKata.Length){
					pgkt = pow(10,CKata.Length - i);
					s += convertToInt(CKata.TabKata[i]) * pgkt;
					i++;
				}
				(*T).Tb[n].w.TT.MM = s;
			} else if((z % 8) == 5){
				i = 1;
				s = 0;
				int pgkt;
				while(i<=CKata.Length){
					pgkt = pow(10,CKata.Length - i);
					s += convertToInt(CKata.TabKata[i]) * pgkt;
					i++;
				}
				(*T).Tb[n].w.TT.YY = s;
			} else if((z % 8) == 6){
				i = 1;
				s = 0;
				int pgkt;
				while(i<=CKata.Length){
					pgkt = pow(10,CKata.Length - i);
					s += convertToInt(CKata.TabKata[i]) * pgkt;
					i++;
				}
				(*T).Tb[n].w.JJ.HH = s;
			} else if((z % 8) == 7){
				i = 1;
				s = 0;
				int pgkt;
				while(i<=CKata.Length){
					pgkt = pow(10,CKata.Length - i);
					s += convertToInt(CKata.TabKata[i]) * pgkt;
					i++;
				}
				(*T).Tb[n].w.JJ.MM = s;
			} else if((z % 8) == 0){
				i = 1;
				s = 0;
				int pgkt;
				while(i<=CKata.Length){
					pgkt = pow(10,CKata.Length - i);
					s += convertToInt(CKata.TabKata[i]) * pgkt;
					i++;
				}
				(*T).Tb[n].w.JJ.SS = s;
			}
			z++;
			ADVKATA();*/
		}
		(*T).Neff += (x-1);
		isTabTerurutMengecilChanged = false;
	}

boolean IsTabTerurutMengecilEmpty(TabTerurutMengecil T){
/* menghasilkan true jika T empty, yaitu Neff = 0 */
	return (T.Neff == 0);
}
boolean IsTabTerurutMengecilFull(TabTerurutMengecil T){
/* menghasilkan true jika T penuh, yaitu Neff = MaxTabTerurutMengecilElmt */
	return (T.Neff == MaxTabTerurutMengecilElmt);
}

int MinTabTerurutMengecilFull(TabTerurutMengecil T){
/* menghasilkan nilai score minimum dari T */
	if(IsTabTerurutMengecilEmpty(T)){
		return ValUndef;
	} else {
		int min = T.Tb[1].score;
		idx  i = 2;
		while(i <= T.Neff){
			if(T.Tb[i].score < min){
				min = T.Tb[i].score;
			}
			i++;	
		}
	}

}

void AddSortedElement(allhighscores X, TabTerurutMengecil *T){
/* I.S. T tidak penuh */
/* F.S. Elemen T bertambah 1 secara terurut */
	
	/*if(IsTabTerurutMengecilEmpty(*T)){
		(*T).Neff = 0;
		(*T).Tb[1] = X;
	} else {*/
		idx i = 1;
		idx j;
		boolean added = false;
		while(!(added) && (i<=(*T).Neff)){
			if((*T).Tb[i].score < X.score){
				j = (*T).Neff + 1;
				//Menggeser setiap elemen
				while(j>i){
					(*T).Tb[j] = (*T).Tb[j-1];
					j--;
				}
				(*T).Tb[i] = X;
				added = true;
			}
			i++;
		}
		if(!(added)){
			(*T).Tb[(*T).Neff + 1] = X;
		}
	//}
	(*T).Neff++;
}

void AddElmtTabTerurutMengecil(allhighscores X, TabTerurutMengecil *T){
/* I.S. T terurut mengecil */
/* F.S. Menambahkan elemen secara terurut jika Tab belum penuh atau Tab sudah penuh tetapi ada high score baru yang  */
/*         menghapus elemen yang paling kecil */
	allhighscores Y;
	if(IsTabTerurutMengecilFull(*T)){
		if(X.score > MinTabTerurutMengecilFull(*T)){
			DelLastElmtTabTerurutMengecil(&Y,T);
			//tambahkan secara terurut
			AddSortedElement(X,T);
			isTabTerurutMengecilChanged = true;
		} else {
			//tidak perlu diganti
		}	
	} else {
		//T belum penuh, tambahkan secara terurut
		AddSortedElement(X,T);
		isTabTerurutMengecilChanged = true;
	}
}

void DelLastElmtTabTerurutMengecil(allhighscores *X, TabTerurutMengecil *T){
/* I.S. T tidak kosong */
/* F.S. Elemen terakhir yang nilai elemennya paling kecil dihapus */
	(*T).Neff--;
	isTabTerurutMengecilChanged = true;
}

void SortTabTerurutMengecil(TabTerurutMengecil *T){
/* I.S. T tidak kosong */
/* F.S. Elemen T terurut mengecil berdasarkan score */
	if(((*T).Neff >= 1) && ((*T).Neff<=10)){
		int i,j;
		int temp;
		for (i=1; i<=((*T).Neff-1); i++){
			for (j=1; j<=((*T).Neff-1); j++){
				if((*T).Tb[j].score<=(*T).Tb[j+1].score){
					temp = (*T).Tb[j].score;
					(*T).Tb[j].score = (*T).Tb[j+1].score;
					(*T).Tb[j+1].score = temp;
				}
			}
		}
	}
}

void ShowTabTerurutMengecil(TabTerurutMengecil T){
/* I.S. T semabarang */
/* F.S. Menulis isi dari highscore ke layar */
	if(IsTabTerurutMengecilEmpty(T)){
		printf("List kosong\n");
	} else {
		int i = 1;
		do{
			
			PrintKata ((T).Tb[i].user);
			printf("%d ",(T).Tb[i].score);
			TulisWAKTU((T).Tb[i].w);
			printf("\n");
			//printf("%d %d %d %d %d %d %d\n", (T).Tb[i].score, (T).Tb[i].w.TT.DD, (T).Tb[i].w.TT.MM, (T).Tb[i].w.TT.YY, (T).Tb[i].w.JJ.HH, (T).Tb[i].w.JJ.MM, (T).Tb[i].w.JJ.SS);
			i++;
		} while (i <= (T).Neff);
	}
}

void SaveAllHighScores(TabTerurutMengecil T, char* namafile){
/* I.S. T terisi */
/* F.S. Menulis isi dari highscore ke file eksternal jika ada perubahan */
	if(isTabTerurutMengecilChanged){
		FILE *f = fopen(namafile, "w");
		Kata kt;
		if (f == NULL)
		{
			printf("Error opening file!\n");
		}
		int i = 1;
		int j;
		while(i<=(T).Neff){
			//Mencetak user
			kt = T.Tb[i].user;
			j = 1;
			while(j <= kt.Length){
				fprintf(f,"%c",T.Tb[i].user.TabKata[j]);
				j++;
			}
			fprintf(f," ");
			
			//mencetak score
			fprintf(f,"%d ",T.Tb[i].score);
			
			//mencetak tanggal
			if ((T.Tb[i].w.TT.DD) < 10)
				fprintf(f,"0");
			fprintf(f,"%d ",T.Tb[i].w.TT.DD);
			
			//mencetak bulan
			if ((T.Tb[i].w.TT.MM) < 10)
				fprintf(f,"0");
			fprintf(f,"%d ",T.Tb[i].w.TT.MM);
			
			//mencetak tahun
			if ((T.Tb[i].w.TT.YY) < 10){
				fprintf(f,"000");
			} else if ((T.Tb[i].w.TT.YY) < 100){
				fprintf(f,"00");
			} else if ((T.Tb[i].w.TT.YY) < 1000){
				fprintf(f,"0");
			}
			fprintf(f,"%d ",T.Tb[i].w.TT.YY);
			
			//mencetak jam
			if ((T.Tb[i].w.JJ.HH) < 10)
				fprintf(f,"0");
			fprintf(f,"%d ",T.Tb[i].w.JJ.HH);
			
			//mencetak menit
			if ((T.Tb[i].w.JJ.MM) < 10)
				fprintf(f,"0");
			fprintf(f,"%d ",T.Tb[i].w.JJ.MM);
			
			//mencetak detik
			if ((T.Tb[i].w.JJ.SS) < 10)
				fprintf(f,"0");
			fprintf(f,"%d",T.Tb[i].w.JJ.SS);
			
			i++;
			
			if(i<=(T).Neff)
				fprintf(f,"\n");
		}
		fprintf(f,".");
		fclose(f);
	} else {
		//Tidak perlu mengupdate file eksternal
	}
}
