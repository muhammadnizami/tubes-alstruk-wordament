#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"point.h"
#include<math.h>
	
int main(){
	int i,h,DX,DY;
	float sudut;
	POINT ptest,p1,p2;
	srand(time(NULL));
	ptest=MakePOINT(rand(),rand());
	TulisPOINT(ptest);
	SetAbsis(&ptest,rand());
	TulisPOINT(ptest);
	SetOrdinat(&ptest,rand());
	TulisPOINT(ptest);
	BacaPOINT(&ptest);
	TulisPOINT(ptest);

//cek operator relasional
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		p2=MakePOINT(rand(),rand());
		TulisPOINT(p1);
		printf("==");
		TulisPOINT(p2);
		printf("=");
		h=EQ(p1,p2);
		printf("%x\n",h);
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		p2=p1;
		TulisPOINT(p1);
		printf("==");
		TulisPOINT(p2);
		printf("=");
		h=EQ(p1,p2);
		printf("%x\n",h);
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		p2=MakePOINT(rand(),rand());
		TulisPOINT(p1);
		printf("!=");
		TulisPOINT(p2);
		printf("=");
		h=NEQ(p1,p2);
		printf("%x\n",h);
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		p2=p1;
		TulisPOINT(p1);
		printf("!=");
		TulisPOINT(p2);
		printf("=");
		h=NEQ(p1,p2);
		printf("%x\n",h);
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		TulisPOINT(p1);
		printf("is Origin");
		printf("=");
		h=IsOrigin(p1);
		printf("%x\n",h);
	}
	p1=MakePOINT(0,0);
	TulisPOINT(p1);
	printf("is Origin");
	printf("=");
	h=IsOrigin(p1);
	printf("%x\n",h);
	printf("\n\ncek\n");
	p1=MakePOINT(0,rand());
	TulisPOINT(p1);
	printf("is Origin");
	printf("=");
	h=IsOrigin(p1);
	printf("%x\n",h);
	printf("\n\ncek\n");
	p1=MakePOINT(rand(),0);
	TulisPOINT(p1);
	printf("is Origin");
	printf("=");
	h=IsOrigin(p1);
	printf("%x\n",h);
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		TulisPOINT(p1);
		printf("is On SbX");
		printf("=");
		h=IsOnSbX(p1);
		printf("%x\n",h);
	}
	p1=MakePOINT(0,0);
	TulisPOINT(p1);
	printf("is SbX");
	printf("=");
	h=IsOnSbX(p1);
	printf("%x\n",h);
	p1=MakePOINT(0,rand());
	TulisPOINT(p1);
	printf("is SbX");
	printf("=");
	h=IsOnSbX(p1);
	printf("%x\n",h);
	p1=MakePOINT(rand(),0);
	TulisPOINT(p1);
	printf("is SbX");
	printf("=");
	h=IsOnSbX(p1);
	printf("%x\n",h);
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		TulisPOINT(p1);
		printf("is On SbY");
		printf("=");
		h=IsOnSbY(p1);
		printf("%x\n",h);
	}
	p1=MakePOINT(0,0);
	TulisPOINT(p1);
	printf("is SbY");
	printf("=");
	h=IsOnSbY(p1);
	printf("%x\n",h);
	p1=MakePOINT(0,rand());
	TulisPOINT(p1);
	printf("is SbY");
	printf("=");
	h=IsOnSbY(p1);
	printf("%x\n",h);
	p1=MakePOINT(rand(),0);
	TulisPOINT(p1);
	printf("is SbY");
	printf("=");
	h=IsOnSbY(p1);
	printf("%x\n",h);
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand()-rand(),rand()-rand());
		printf("kuadran ");
		TulisPOINT(p1);
		printf("=");
		h=Kuadran(p1);
		printf("%d\n",h);
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		printf("NextX ");
		TulisPOINT(p1);
		printf("=");
		TulisPOINT(NextX(p1));
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand(),rand());
		printf("NextY ");
		TulisPOINT(p1);
		printf("=");
		TulisPOINT(NextY(p1));
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand()-rand(),rand()-rand());
		TulisPOINT(p1);
		DX=rand()%10;
		DY=rand()%10;
		printf(" + (%d,%d) =",DX,DY);
		TulisPOINT(PlusDelta(p1,DX,DY));
		printf("\n");
		TulisPOINT(p1);
		printf(" + (%d,%d)g =",DX,DY);
		Geser(&p1,DX,DY);
		TulisPOINT(p1);
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT(rand()-rand(),rand()-rand());
		printf("MirrorOf(");
		TulisPOINT(p1);
		printf(",1,0) =");
		TulisPOINT(MirrorOf(p1,1,0));
		printf("\n");
	}
	for (i=0;i<14;i++){
		p1=MakePOINT(rand()-rand(),rand()-rand());
		printf("MirrorOf(");
		TulisPOINT(p1);
		printf(",0,1) =");
		TulisPOINT(MirrorOf(p1,0,1));
		printf("\n");
	}
	for (i=0;i<14;i++){
		p1=MakePOINT(rand()-rand(),rand()-rand());
		printf("MirrorOf(");
		TulisPOINT(p1);
		printf(",1,1) =");
		TulisPOINT(MirrorOf(p1,1,1));
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		printf("Jarak0(");
		TulisPOINT(p1);
		printf(") = %f",Jarak0(p1));
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		p2=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		printf("Panjang(");
		TulisPOINT(p1);
		printf(",");
		TulisPOINT(p2);
		printf(") = %f",Panjang(p1,p2));
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		TulisPOINT(p1);
		printf("digeser ke Sb-X menjadi ");
		GeserKeSbX(&p1);
		TulisPOINT(p1);
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		TulisPOINT(p1);
		printf("digeser ke Sb-Y menjadi ");
		GeserKeSbY(&p1);
		TulisPOINT(p1);
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		TulisPOINT(p1);
		printf("dicerminkan dengan Sb-X menjadi ");
		Mirror(&p1,1,0);
		TulisPOINT(p1);
		printf("\n");
	}
	for (i=0;i<14;i++){
		p1=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		TulisPOINT(p1);
		printf("dicerminkan dengan Sb-Y menjadi ");
		Mirror(&p1,0,1);
		TulisPOINT(p1);
		printf("\n");
	}
	for (i=0;i<14;i++){
		p1=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		TulisPOINT(p1);
		printf("dicerminkan dengan (0,0) menjadi ");
		Mirror(&p1,1,1);
		TulisPOINT(p1);
		printf("\n");
	}
	printf("\n\ncek\n");
	for (i=0;i<14;i++){
		p1=MakePOINT((rand()-rand())%10,(rand()-rand())%10);
		sudut=(float) (rand()%360);
		
		TulisPOINT(p1);
		printf("diputar %0.0f derajat menjadi ",sudut);
		Putar(&p1,sudut);
		TulisPOINT(p1);
		printf("\n");
	}
	printf("M_PI=%f\n",M_PI);
	return 0;
}
