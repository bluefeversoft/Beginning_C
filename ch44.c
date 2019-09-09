#include "stdio.h"


typedef struct S_RacingCar {

	char name[12];
	int speed;
	struct S_RacingCar *next;
	
} RacingCar;

void PrintList(RacingCar *start) {
	RacingCar *currentCar = start;
	int count = 0;
	
	while(currentCar != NULL) {
		count++;
		printf("Car:%d Name:%s Speed:%d\n",count,
			currentCar->name,
			currentCar->speed);
		currentCar = currentCar->next;
	}
	
	printf("Total Cars:%d\n",count);

}

int main() {	
	
	RacingCar RedBull = { "RedBull", 100, NULL };
	RacingCar Ferrari = { "Ferrari", 90, NULL };
	RacingCar Mercedes = { "Mercedes", 80, NULL };
	RacingCar Lotus = { "Lotus", 70, NULL };
	RacingCar McLaren = { "McLaren", 60, NULL };
	
	RedBull.next = &Ferrari;
	Ferrari.next = &Mercedes;
	Mercedes.next = &Lotus;
	Lotus.next = &McLaren;
	
	PrintList(&Mercedes);
	
	return 0;

}

















































