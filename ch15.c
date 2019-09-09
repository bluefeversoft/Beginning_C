#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {

	srand(time(NULL));
	
	char guessWords[][16] = {
		"green", 
		"yellow",
		"purple",
		"windows",
		"linux",
		"apple"	
	};
	
	// index for random word
	int randomIndex = rand() % 6;
	
	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = strlen(guessWords[randomIndex]);
	
	//					     0 1 2 3 4 5
	//				         p u r p l e
	//  letterGuessed[8] = { 0,0,0,0,0,0,0,0 };
	int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };
	
	int quit = 0;	
	
	int loopIndex = 0;
	
	char guess[16];
	char letterEntered;
	
	
	printf("guessWords:%s randomIndex:%d lengthOfWord:%d\n\n",
		guessWords[randomIndex],
		randomIndex,
		lengthOfWord);
	
    // game loop	
	while ( numCorrect < lengthOfWord ) {
	
		printf("Number Correct So Far:%d\n",numCorrect);
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);
		
		if( strncmp(guess, "quit", 4) == 0) {
			quit = 1;
			break;
		}
		
		letterEntered = guess[0];
		
		printf("letterEntered:%c\n",letterEntered);
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
		
			if(letterGuessed[loopIndex] == 1) {
				continue;
			}
		
			if( letterEntered == guessWords[randomIndex][loopIndex] ) {
				letterGuessed[loopIndex] = 1;
				numCorrect++;				
			}		
		
		}	
	
	} // while loop
	
	if( quit == 1 ) {	
		printf("\nthe user quit early\n");
	}
	
		
	return 0;
}


