#include "stdio.h"

typedef struct {
	char *name;
	int people;
	int speed;
	int seats;
} CarType;

/*

printf("%d",*pInt);
printf("%d",(*ourCar).speed);

*/

void PrintCar( const CarType *ourCar  ) {
	printf("Name:%s Speed:%d People:%d Seats:%d\n",
		ourCar->name,
		ourCar->people,
		ourCar->speed,
		ourCar->seats
					);
}

int main() {	
	printf("\n");
	
	CarType car1 = { "Focus", 5, 10, 5 };
	CarType car2 = { "Cayman", 2, 50, 4 };
	
	PrintCar(&car1);
	PrintCar(&car2);
	
	printf("\n");
	
	return 0;
}