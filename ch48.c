#include "stdio.h"


int main() {	
	
	FILE *pToFile = fopen("text.txt","a");	
	
	int num = 40;
	char single = 'C';
	char myWord[4] = "Cat";
	
	if(pToFile != NULL) {
		fprintf(pToFile, "%d %c %s %s\n", num, single, myWord, myWord);
		fclose(pToFile);
	} else {
		printf("File Not Found!\n");
	}	
	
	return 0;

}
































