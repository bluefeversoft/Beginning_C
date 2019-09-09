#include "stdio.h"


int main() {	
	
	FILE *pToFile = fopen("text.txt","r");
	
	int line = 0;
	char single;
	
	while ( (single = fgetc(pToFile) ) != EOF) {
		printf("%c",single);
	}
	
	printf("\n\nEnd Of Program\n");
	
	fclose(pToFile);
	
	return 0;

}
































