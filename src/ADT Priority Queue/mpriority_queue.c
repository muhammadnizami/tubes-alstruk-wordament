#include "priority_queue.h"
#include <stdio.h>
Kata strToKata(char * _str){
	Kata K;
	int count=0;
	char a;
	while (_str[count]!='\0'){
		a=_str[count];
		count++;
		K.TabKata[count]=a;
	}
	K.Length=count;
	return K;
}

int main(){
	int b;
	char a[51];
	Kata A;
	Kata Terminator;
	Terminator.TabKata[1]='-';
	Terminator.TabKata[2]='9';
	Terminator.TabKata[3]='9';
	Terminator.TabKata[4]='9';
	Terminator.Length=4;
	PriorityQueue Q;
	CreatePriorityQueue(&Q);
	printf("Kata:");
	scanf("%s",a);
	A=strToKata(a);
	while (!IsKataSama(A,Terminator)){
		printf("Score:");
		scanf("%d",&b);
		PQAdd(&Q,A,b);
		printf("Kata:");
		scanf("%s",a);
		A=strToKata(a);
	}
	PQTulisdanHapus(&Q);
	return 0;
}
