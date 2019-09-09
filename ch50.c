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

void ReadSomeData() {
	MY_DATA dataArray[NUMDATA];
	
	FILE *pFile;
	pFile = fopen("myData.bin","rb");
	
	fseek(pFile, 0, SEEK_END);
	long fileSize = ftell(pFile);
	rewind(pFile);
	printf("ReadSomeData(): fileSize:%ld\n",fileSize);
	
	int numStructures = (int)(fileSize / (sizeof(MY_DATA)));
	printf("ReadSomeData(): numStructures:%d\n",numStructures);
	
	size_t returnValue;
	returnValue = fread(dataArray, sizeof(MY_DATA), numStructures, pFile );
	printf("ReadSomeData(): returnValue:%ld\n",returnValue);
	
	PrintData(dataArray);
}

void ReadOneData(int index) {
	// index * sizeof(MY_DATA)
	// ---- ---- ----
	MY_DATA data;	
	FILE *pFile;
	pFile = fopen("myData.bin","rb");
	fseek(pFile, (sizeof(MY_DATA)*index), SEEK_SET);
	size_t returnValue;
	returnValue = fread(&data, sizeof(MY_DATA), 1, pFile );
	printf("ReadOneData(%d): %s %d %.3f\n",index,data.name,data.numOne,data.numTwo);
}

int main() {	
	
	/*MY_DATA dataArray[NUMDATA] = {
		{ 10, "Dog", 111.123 },
		{ 20, "Beer", 222.456 },
		{ 30, "Iguana", 333.789 }
	};*/
	
	//PrintData(dataArray);
	//WriteDataToFile(dataArray);		
	//ReadSomeData();
	int index = 0;
	for(index = 0; index < NUMDATA; index++) {
		ReadOneData(index);
	}
}
































