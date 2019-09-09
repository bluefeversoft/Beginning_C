#include "stdio.h"

int NumA = 12;     // 1100
int NumB = 9;      // 1001
// Exclusive OR		  0101	
// Exclusive OR		  1100	-> Step2

int main() {	
	
	printf("Step 1 NumA:%d NumB:%d\n",NumA,NumB);
	NumA = NumA ^ NumB;
	printf("Step 2 NumA:%d NumB:%d\n",NumA,NumB);
	NumB = NumA ^ NumB;
	printf("Step 3 NumA:%d NumB:%d\n",NumA,NumB);
	NumA = NumA ^ NumB;
	printf("Step 4 NumA:%d NumB:%d\n",NumA,NumB);
	printf("\n\n");
	
	int RandOne = rand();
	int RandTwo = rand();
	int RandThree = rand();
	
	printf("RandOne:%d RandTwo:%d RandThree:%d\n",
		RandOne,RandTwo,RandThree);
	int Key1 = RandOne ^ RandTwo ^ RandThree;
	int Key2 = RandOne ^ RandThree;
	printf("Key1:%d Key2:%d\n",
		Key1,Key2);
		
	Key1 = Key1 ^ RandTwo;
	printf("Key1:%d Key2:%d\n",
		Key1,Key2);
	
	Key1 = Key1 ^ RandOne;
	printf("Key1:%d Key2:%d\n",
		Key1,Key2);
	
	return 0;
}














