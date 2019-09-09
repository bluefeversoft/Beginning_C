#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"

int main() {	
	
	char input[32];	
	
	int OurInt = 0;
	long OurLong = 0;
	float OurFloat = 0.0;
	double OurDouble = 0.0;
	
	printf("INT_MAX:%d\n",INT_MAX);
	printf("LONG_MAX:%ld\n",LONG_MAX);

	while( 1 ) {
		
		printf("Enter Number > ");
		fgets( input, 31, stdin);
		if ( strncmp(input, "quit", 4) == 0) {
			printf("\n\nQuit Program...\n");
			break;		
		}
		
		OurInt = atoi(input);
		OurLong = atol(input);
		OurDouble = atof(input);
		OurFloat = atof(input);
		
		printf("OurInt:%d\n",OurInt);
		printf("OurLong:%ld\n",OurLong);
		printf("OurDouble:%f\n",OurDouble);
		printf("OurFloat:%f\n",OurFloat);
	
	}
	
	return 0;

}
































