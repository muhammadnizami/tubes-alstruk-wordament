#include <stdio.h>
#include "matchar.h"

int main(){
	matchar M;
	M=mcCreateEmpty();
	mcSetElmt(&M,3,3,'a');
	printf("%c\n",mcGetElmt(M,3,3));
}
