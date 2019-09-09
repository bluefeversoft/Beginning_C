#include "stdio.h"


int main() {	
	
	FILE *pToFile = fopen("text.txt","w");	
	int index = 0;
	int num = 40;
	char single = 'C';
	char myWord[4] = "Cat";
	
	if(pToFile != NULL) {
		fputc(num, pToFile);
		fputc(' ', pToFile);
		fputc(single, pToFile);
		fputc(' ', pToFile);
		for(index = 0; index < 4; ++index) {
			fputc(myWord[index], pToFile);
		}
		fclose(pToFile);
	} else {
		printf("File Not Found!\n");
	}	
	
	return 0;

}
































