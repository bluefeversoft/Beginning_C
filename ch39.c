#include "stdio.h"

struct s_car {
	char *name;
	int people;
	int speed;
	int seats;
};

void PrintCar( struct s_car ourCar  ) {
	printf("Name:%s Speed:%d People:%d Seats:%d\n",
		ourCar.name,
		ourCar.people,
		ourCar.speed,
		ourCar.seats
					);
}

int main() {	
	printf("\n");
	
	struct s_car car1 = { "Focus", 5, 10, 5 };
	struct s_car car2 = { "Cayman", 2, 50, 4 };
	
	PrintCar(car1);
	PrintCar(car2);
	
	printf("\n");
	
	return 0;
}













