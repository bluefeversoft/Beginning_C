#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

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
	int reguessed = 0; // EDIT
	
	char guess[16];
	char letterEntered;	
	
    // game loop	
	while ( numCorrect < lengthOfWord ) {
	
		printf("\n\nNew Turn....\nHangman Word:");
	
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
		
			if(letterGuessed[loopIndex] == 1) {
				printf("%c",guessWords[randomIndex][loopIndex]);				
			} else {
				printf("-");
			}
		
		}	
		
		printf("\n");
	
		printf("Number Correct So Far:%d\n",numCorrect);
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);
		
		if( strncmp(guess, "quit", 4) == 0) {
			quit = 1;
			break;
		}
		
		letterEntered = guess[0];
		reguessed = 0; 
		
		printf("letterEntered:%c\n",letterEntered);
		
		oldCorrect = numCorrect;
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
		
			if(letterGuessed[loopIndex] == 1) {
				if(guessWords[randomIndex][loopIndex] == letterEntered) {
					reguessed = 1; 
					break;
				} 
				continue;
			}
		
			if( letterEntered == guessWords[randomIndex][loopIndex] ) {
				letterGuessed[loopIndex] = 1;
				numCorrect++;				
			}		
		
		}	
		
		if( oldCorrect == numCorrect && reguessed == 0) {
			numLives--;
			printf("Sorry, wrong guess\n");
			if (numLives == 0) {
				break;
			}
		} else if( reguessed == 1) {
			printf("Already Guessed!!\n");
		} else {
			printf("Correct guess :)\n");
		}
	
	} // while loop
	
	if( quit == 1 ) {	
		printf("\nthe user quit early\n");
	} else if (numLives == 0) {
		printf("\nSorry you lose, the word was: %s\n",
		guessWords[randomIndex]);	
	} else  {	
		printf("\nYOU WIN!!! :)\n");
	} 
	
		
	return 0;
}


