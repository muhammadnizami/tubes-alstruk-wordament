#include <stdio.h>
#include <stdlib.h>
#include "multilistv5.h"

int main(){
//Kamus Lokal
	int Y;
	int i,j;
	int input;
	List tes;
	InfoUser X,Z;
	adrUser usr; 

//Algoritma
	/*
	Load(&tes);
	usr=FirstUser(tes);
	for(i=1;i<10;i++)PrintUser(usr,i);
	usr=NextUser(usr);
	for(i=1;i<10;i++)PrintUser(usr,i);
	*/
	CreateList(&tes);
	printf("List Kosong : %d\n",IsListEmpty (tes));
	printf("Masukkan nama user \n");
	scanf("%s",&X.usr);	
	printf("%s\n", X.usr);
	InsVUser(&tes,X);
	scanf("%s",&Z.usr);	
	InsVUser(&tes,Z);
	usr = FindUser(&tes,X);
	printf("%x\n",usr);
	j=-1;
	for (i=0;i<10;i++){
		j=j*-1;
		InsVScore(usr,j*i*100000,0);	
		InsVScore(usr,j*i*j*100000,1);
		InsVScore(usr,j*i*i*100000,2);
		InsVScore(usr,j*i*100000,3);
		InsVScore(usr,j*i*100000,4);
		InsVScore(usr,j*i*100000,5);
		InsVScore(usr,j*i*100000,6);
		InsVScore(usr,j*i*100000,7);
	}
			PrintUser(usr,0);
	usr=NextUser(usr);
	for (i=10;i>=0;i--){
		j=j*-1;
		InsVScore(usr,j*i*100000,0);
		InsVScore(usr,j*i*j*100000,1);	
	}
				PrintUser(usr,0);
	Save(tes);

	return 0;
}