#include "stdio.h"


int main() {	
	
	FILE *pToFile = fopen("text.dat","r");
	
	int line = 0;
	
	char input[512];
	
	while( fgets( input, 512, pToFile )) {
		line++;
		printf("Line:%d -> %s",line,input);
	}
	
	printf("\n\nEnd Of Program\n");
	
	fclose(pToFile);
	
	return 0;

}
































