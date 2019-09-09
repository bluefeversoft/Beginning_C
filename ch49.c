#include "stdio.h"

#define NUMDATA 3

typedef struct {

	int numOne;
	char name[16];
	double numTwo;
	
} MY_DATA;

void PrintData(MY_DATA *data) {

	int index = 0;
	
	for(index = 0; index < NUMDATA; ++index) {
		printf("%s %d %.3f\n",data[index].name,data[index].numOne,data[index].numTwo);
	}

}

void WriteDataToFile(MY_DATA *data) {
	
	FILE *pFile;
	pFile = fopen("myData.bin","wb");
	
	if(pFile != NULL) {
		fwrite(data, sizeof(MY_DATA), NUMDATA, pFile ); 
		fclose(pFile);
	} else {
		printf("ERROR WRITING\n");
	}	

}

int main() {	
	
	MY_DATA dataArray[NUMDATA] = {
		{ 10, "Dog", 111.123 },
		{ 20, "Beer", 222.456 },
		{ 30, "Iguana", 333.789 }
	};
	
	PrintData(dataArray);
	WriteDataToFile(dataArray);
	return 0;

}
































