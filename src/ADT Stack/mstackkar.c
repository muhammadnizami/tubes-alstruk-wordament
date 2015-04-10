#include "stackkar.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){
	srand(time(NULL));
	stackkar S;
	scinfotype X;
	scinfotype i;
	scCreateEmpty(&S);
	printf("scIsEmpty:%x\n",scIsEmpty(S));
	for (i=1;i<=10;i++){
		printf("pushing %d to stack\n",i);
		scPush(&S,i);
	}
	printf("scIsEmpty:%x\n",scIsEmpty(S));
	for (i=1;i<=10;i++){
		scPop(&S,&X);
		printf("pop:%d\n",X);
	}
	printf("scIsEmpty:%x\n",scIsEmpty(S));
	for (i=1;i<=5;i++){
		X=rand();
		printf("pushing %d to stack\n",X);
		scPush(&S,X);
	}
	printf("scIsEmpty:%x\n",scIsEmpty(S));
	for (i=1;i<=5;i++){
		X=rand();
		printf("pushing %d to stack\n",X);
		scPush(&S,X);
	}
	printf("scIsEmpty:%x\n",scIsEmpty(S));
	for (i=1;i<=10;i++){
		scPop(&S,&X);
		printf("pop:%d\n",X);
	}
	printf("scIsEmpty:%x\n",scIsEmpty(S));
	return 0;
}
