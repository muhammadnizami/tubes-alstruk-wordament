#include <stdio.h>
#include "matbool.h"

int main(){
	matbool M;
	M=mbCreateEmpty();
	mbSetElmt(&M,3,3,true);
	printf("%x\n",mbGetElmt(M,3,3));
}
