#include "stdio.h"

/*
int board[25] = {
	:,:,:,:,:,
	:,O,-,X,:,
	:,X,-,-,:,
	:,-,-,-,:,
	:,:,:,:,:,
}
*/

const NOUGHTS = 1;
const CROSSES = 2;
const BORDER = 3;
const EMPTY = 0;

const int ConvertTo25[9] = {
	6,7,8,
	11,12,13,
	16,17,18
};

void InitialiseBoard(int *board) {
	int index = 0;
	
	for(index = 0; index < 25; ++index) {
		board[index] = BORDER;
	}
	
	for(index = 0; index < 9; ++index) {
		board[ConvertTo25[index]] = EMPTY;
	}	
}

void PrintBoard(const int *board) {
	int index = 0;
	printf("\nBoard:\n");
	for(index = 0; index < 25; ++index) {
		if(index!=0 && index%5==0) {
			printf("\n");
		}
		printf("%4d",board[index]);
	}
	printf("\n");
}


int main() {		

	int board[25];
	InitialiseBoard(&board[0]);
	board[ConvertTo25[0]] = CROSSES;
	PrintBoard(&board[0]);
		
	return 0;
}














