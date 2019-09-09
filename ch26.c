#include "stdio.h"

void PrintOnOff(char Name, int SwitchNum);
void PrintStatus();

     					 // ABCD	
int statusOfMachine = 6; // 0110
int CheckSwitchA = 8;    // 1000
int CheckSwitchB = 4;    // 0100
int CheckSwitchC = 2;    // 0010
int CheckSwitchD = 1;    // 0001


int main() {		
	
	PrintStatus();
	
	
	// 0110 -> statusOfMachine
	// 1000	-> CheckSwitchA
	
	// 1110 -> OR Result
	
	statusOfMachine |= CheckSwitchA;
	PrintStatus();
	
	
	statusOfMachine |= CheckSwitchD;
	PrintStatus();
	
	
	return 0;
}

void PrintOnOff(char Name, int SwitchNum) {
	if(statusOfMachine & SwitchNum) {
		printf("%c:ON ",Name);
	} else {
		printf("%c:OFF ",Name);
	}
}

void PrintStatus() {

	printf("\nMachine Status:\n");
	PrintOnOff('A',CheckSwitchA);
	PrintOnOff('B',CheckSwitchB);
	PrintOnOff('C',CheckSwitchC);
	PrintOnOff('D',CheckSwitchD);
	printf("\n");
}













