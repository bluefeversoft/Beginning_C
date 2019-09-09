#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct S_RacingCar {

	char name[12];
	int speed;
	struct S_RacingCar *next;
	struct S_RacingCar *previous;
	
} RacingCar;

void PrintList(RacingCar *start) {
	RacingCar *currentCar = start;
	int count = 0;
	
	RacingCar *ahead = NULL;
	RacingCar *behind = NULL;
	
	while(currentCar != NULL) {
		count++;
		
		ahead = currentCar->next;
		behind = currentCar->previous;
		
		printf("Car:%d Name:%s Speed:%d Ahead:%s Behind:%s\n",count,
			currentCar->name,
			currentCar->speed,
			(ahead == NULL) ? "None" : ahead->name,
			(behind == NULL) ? "None" : behind->name
			);
		currentCar = currentCar->next;
		ahead = NULL;
		behind = NULL;
	}	
	printf("Total Cars:%d\n",count);
}

RacingCar *MakeNewCar() {

	printf("Enter Name And Speed: ");
	char input[16];
	fgets( input, 15, stdin);
	
	RacingCar *newCar = malloc(sizeof(RacingCar));
	sscanf(input, "%s %d", newCar->name, &newCar->speed);
	printf("Added:%s Speed:%d\n\n",newCar->name,newCar->speed);
	
	newCar->next = NULL;
	newCar->previous = NULL;
	
	return newCar;
}

RacingCar *AddToStart(RacingCar *startPtr) {
	RacingCar *newCar = MakeNewCar();
	if(startPtr != NULL) {
		startPtr->previous = newCar;
		newCar->next = startPtr;
	}
	
	return newCar;
}

RacingCar *AddToEnd(RacingCar *startPtr) {
	RacingCar *returnPtr = startPtr;
	RacingCar *newCar = NULL;
	
	if(startPtr == NULL) {
		newCar = AddToStart(startPtr);
		returnPtr = newCar;
	} else {
		RacingCar *indexCar = startPtr;
		while (indexCar->next != NULL) {
			indexCar = indexCar->next;
		}
		newCar = MakeNewCar();
		indexCar->next = newCar;
		newCar->next = NULL;
		newCar->previous = indexCar;
	}
	return returnPtr;
}

RacingCar *Delete(RacingCar *startPtr) {

	printf("Enter Name To Delete:");
	char input[16];
	fgets(input, 15, stdin);
	
	RacingCar *carRef = startPtr;
	RacingCar *carToDelete = NULL;
	
	while(carRef != NULL) {
	
		if(strncmp(input, carRef->name, strlen(carRef->name)) == 0) {
			carToDelete = carRef;
			break;
		}
		
		carRef = carRef->next;
	}
	
	if(startPtr != NULL && carToDelete == startPtr) {
		if(carToDelete->next != NULL) {
			carToDelete->next->previous = NULL;
			startPtr = carToDelete->next;
		} else {
			startPtr = NULL;
		}
	} else {
		if(carToDelete != NULL) {
			if(carToDelete->previous != NULL) {
				carToDelete->previous->next = carToDelete->next;
			}
			
			if(carToDelete->next != NULL) {
				carToDelete->next->previous = carToDelete->previous;
			}
		}
	}
	
	if(carToDelete != NULL) {
		carToDelete = NULL;
		free(carToDelete);
	}
	
	return startPtr;
	
}

RacingCar *Insert(RacingCar *startPtr) {
	printf("Insert New Car After Car:");
	char input[16];
	fgets(input, 15, stdin);
	
	RacingCar *afterCar = startPtr;
	RacingCar *newCar = NULL;
	
	if(strncmp(input, afterCar->name, strlen(afterCar->name)) == 0) {
		newCar = MakeNewCar();
	} else {
		while(afterCar->next != NULL) {
			afterCar = afterCar->next;
			if(strncmp(input, afterCar->name, strlen(afterCar->name)) == 0) {
				newCar = MakeNewCar();
				break;
			}
		}
	}
	
	if(newCar != NULL) {
		newCar->next = afterCar->next;
		if(newCar->next != NULL) {
			newCar->next->previous = newCar;
		}
		afterCar->next = newCar;
		newCar->previous = afterCar;
	} else {
		printf("Car Not Found\n");
	}
	
	return startPtr;
}

void CleanUp(RacingCar *start) {
	
	RacingCar *freeMe = start;
	RacingCar *holdMe = NULL;	
	while(freeMe != NULL) {
		holdMe = freeMe->next;
		printf("Free Name:%s Speed:%d\n",
			freeMe->name,
			freeMe->speed);
		free(freeMe);
		freeMe = holdMe;
	}	
}

void WriteListToFile(RacingCar *start) {
	FILE *pFile;
	pFile = fopen("myList.bin", "wb");
	
	if(pFile != NULL) {
		RacingCar *currentCar = start;
		
		RacingCar *holdNext = NULL;
		RacingCar *holdPrevious = NULL;
		
		while(currentCar != NULL) {
			holdNext = currentCar->next;
			holdPrevious = currentCar->previous;
			
			currentCar->next = NULL;
			currentCar->previous = NULL;
			
			fseek(pFile, 0, SEEK_END);
			fwrite(currentCar, sizeof(RacingCar), 1, pFile);
			
			printf("Writing:%s to file\n",currentCar->name);
			
			currentCar->next = holdNext;
			currentCar->previous = holdPrevious;
			
			holdNext = NULL;
			holdPrevious = NULL;
			
			currentCar = currentCar->next;
		}
		fclose(pFile);
		pFile = NULL;
	} else {
		printf("FILE OPEN ERROR\n");
	}
	
}

RacingCar *ReadNextFromFile(RacingCar *start, FILE *pFile) {
	size_t returnValue;
	if(start == NULL) {
		start = malloc(sizeof(RacingCar));
		returnValue = fread(start, sizeof(RacingCar), 1, pFile);
		start->next = NULL;
		start->previous = NULL;
	} else {
		RacingCar *indexCar = start;
		RacingCar *newCar = malloc(sizeof(RacingCar));
		while(indexCar->next != NULL) {
			indexCar = indexCar->next;
		}
		returnValue = fread(newCar, sizeof(RacingCar), 1, pFile);
		indexCar->next = newCar;
		newCar->next = NULL;
		newCar->previous = indexCar;
	}
	return start;
}

RacingCar *ReadListIn(RacingCar *start) {
	
	FILE *pFile;
	pFile = fopen("myList.bin", "rb");
	if(pFile != NULL) {
	
		CleanUp(start);
		start = NULL;
		
		fseek(pFile, 0, SEEK_END);
		long fileSize = ftell(pFile);
		rewind(pFile);
		
		int numEntries = (int)(fileSize / (sizeof(RacingCar)));
		printf("numEntries:%d\n",numEntries);
		
		int loop = 0;
		for(loop = 0; loop < numEntries; ++loop) {
			fseek(pFile, (sizeof(RacingCar) * loop), SEEK_SET);
			start = ReadNextFromFile(start, pFile);
		}
	}  else {
		printf("FILE OPEN ERROR FOR READ\n");
	}
	
	return start;

}

int main() {	
	
	char command[16];
	char input[16];	
	
	RacingCar *start = NULL;
	
	while( fgets( input, 15, stdin) ) {
		
		sscanf(input,"%s",command);	
		
		if ( strncmp(command, "quit", 4) == 0) {
			printf("\n\nBreaking...\n");
			break;		
		} else if ( strncmp(command, "print", 5) == 0) {
			PrintList(start);
		} else if ( strncmp(command, "write", 5) == 0) {
			WriteListToFile(start);
		} else if ( strncmp(command, "read", 4) == 0) {
			start = ReadListIn(start);
		} else if ( strncmp(command, "addstart", 8) == 0) {
			start = AddToStart(start);
			PrintList(start);
		} else if ( strncmp(command, "add", 3) == 0) {
			start = AddToEnd(start);
			PrintList(start);
		} else if ( strncmp(command, "insert", 6) == 0) {
			if(start == NULL) {
				start = AddToStart(start);
			} else {
				start = Insert(start);
			}
			PrintList(start);
		}
	}
	
	CleanUp(start);
	
	return 0;

}














