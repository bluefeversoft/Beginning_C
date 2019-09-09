#include "stdio.h"

#define PRINTMINION

#define NUMBOTTLES 10
#define MINION "Hello I Am A Minion"

#define ADD(a,b,c) (a + b + c)
#define FORLOOP(i,max) for(i = 0; i < max; ++i)


int main() {	
	
	printf("\nmain()\n");
	
	printf("NUMBOTTLES:%d\n",NUMBOTTLES);
	
#ifndef PRINTMINION
	printf("MINION:%s\n",MINION);
#else
	printf("MINION NOT DEFINED\n");
#endif

	printf("ADD(4,5,6):%d\n",ADD(4,5,6));
	
	int index = 0;
	FORLOOP(index,10) {
		printf("index:%d\n",index);
	}
	
	printf("\nmain(): Program Quit\n");
	
	return 0;
}
































