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
		} else if ( strncmp(command, "addstart", 8) == 0) {
			start = AddToStart(start);
		} else if ( strncmp(command, "addend", 6) == 0) {
			start = AddToEnd(start);
		}
	}
	
	CleanUp(start);
	
	return 0;

}
































