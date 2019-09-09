#include "stdio.h"

void PrintBinary(int num) {

	int index = 0;
	printf("Dec:%d As binary:\n",num);
	for(index = 7; index >= 0; index--) {
	
		if( (1 << index) & num) {
			printf("1");
		} else  {
			printf("0");
		}
		
		if(index!=7 && index%4==0) {
			printf(" ");
		}
	}
	printf("\n");
}

int main() {		

	// 0000 0000
	
	int tA = 10;
	int tB = 7;
	
	// 1010 0111
	int infoMachine = ((tA << 4) | tB);
	
	printf("infoMachine\n");
	PrintBinary(infoMachine);
	
	int mask = 15; // 1111
	
	int getTa = ( (infoMachine >> 4) & mask);
	printf("getTa\n");
	PrintBinary(getTa);
	
	//            tA   tB
	// 0111 1110 1010 0000 
	// 0000 0111 1110 1010 : Right Shift >> 4
	// 0000 0000 0000 1111 -> &
	// 0000 0000 0000 1010 -> Result 10 == tA
	
	return 0;
}














