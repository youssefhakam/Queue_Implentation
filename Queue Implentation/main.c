#include <stdio.h>
#include "Queue.h"

int main() {
	Queue db;

	Init(&db);
	if (IsEmpty(&db)) {
		printf("The Queue is EMPTY\n");
	}

}

