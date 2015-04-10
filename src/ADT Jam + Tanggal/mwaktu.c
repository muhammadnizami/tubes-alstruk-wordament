#include <stdio.h>
#include "waktu.h"

int main(){
	WAKTU W;
	GetCurrentTime(&W);
	printf("WAKTU sekarang: ");
	TulisWAKTU(W);
	printf("\n");

	return 0;
}
