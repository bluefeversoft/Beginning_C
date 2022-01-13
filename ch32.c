#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

/*
int board[25] = {
	:,:,:,:,:,
	:,O,-,X,:,
	:,X,-,-,:,
	:,-,-,-,:,
	:,:,:,:,:,
}
*/

enum { NOUGHTS, CROSSES, BORDER, EMPTY };
enum { HUMANWIN, COMPWIN, DRAW };

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
	char pceChars[] = "OX|-";
	printf("\n\nBoard:\n\n");
	for(index = 0; index < 9; ++index) {
		if(index!=0 && index%3==0) {
			printf("\n\n");
		}
		printf("%4c",pceChars[board[ConvertTo25[index]]]);
	}
	printf("\n");
}

int HasEmpty(const int *board) {
	int index = 0;
	
	for(index = 0; index < 9; ++index) {
		if( board[ConvertTo25[index]] == EMPTY) return 1;
	}
	return 0;
}

void MakeMove(int *board, const int sq, const side) {
	board[sq] = side;
}

void RunGame() {

	int GameOver = 0;
	int Side = NOUGHTS;
	int LastMoveMade = 0;
	int board[25];
	
	InitialiseBoard(&board[0]);
	PrintBoard(&board[0]);
	
	while(!GameOver) {
		if(Side==NOUGHTS) {		
			// get move from human, make move on board, change side
		} else {
			// get move from computer, make move on board, change side
			PrintBoard(&board[0]);
		}
		
		// if three in a row exists Game is over

		// if no more moves, game is a draw	
		
		
		GameOver = 1; // REMOVE ME !!
	}
}

int main() {		
	
	srand(time(NULL));
	RunGame();
		
	return 0;
}














