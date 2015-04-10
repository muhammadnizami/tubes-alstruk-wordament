#include "score.h"
#include <stdio.h>

int main(){
	char a;
	for (a='A';a<='Z';a++)
		printf("score[\'%c\']=%d\n",a,getMapVal(a));
	
	Kata Test;
	Test.TabKata[1]='A';
	Test.TabKata[2]='B';
	Test.Length=2;
	printf("score:%d\n",getscore(Test));
	return 0;
	
}
