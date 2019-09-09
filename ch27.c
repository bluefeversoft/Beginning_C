#include "stdio.h"

void PrintOnOff(char Name, int SwitchNum);
void PrintStatus();

     					  // ABCD	
int statusOfMachine = 13; // 1101
int CheckSwitchA = 8;     // 1000
int CheckSwitchB = 4;     // 0100
int CheckSwitchC = 2;     // 0010
int CheckSwitchD = 1;     // 0001

int main() {

	// 1101 statusOfMachine
	
	// 000000000000000000000000000000001000 CheckSwitchA	
	// 111111111111111111111111111111110111 ~CheckSwitchA
	
	// 1101 statusOfMachine
	// 0111 ~CheckSwitchA
	// 0101 statusOfMachine & ~CheckSwitchA
	
	// 00001100100100010111100000000011101101 Info
	// 00000000000000000000000000000011111111 MASK
	// Info & MASK
	// 00000000000000000000000000000011101101
	
	PrintStatus();	
	statusOfMachine = statusOfMachine & (~CheckSwitchA);
	PrintStatus();
	statusOfMachine = statusOfMachine & (~CheckSwitchD);
	PrintStatus();
	
	printf("CheckSwitchA:%d ~CheckSwitchA:%d\n",
				CheckSwitchA,~CheckSwitchA);
	
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













