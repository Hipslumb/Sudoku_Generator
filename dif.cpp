#include "funcHeaders.h"

unsigned difficulty = 1;
unsigned k = 1;

void diff_update(int key) {

	switch (key) {

	case 1:
		difficulty = k * (difficulty + 1);
		break;

	case 2:

		difficulty = k * (difficulty + 3);
		break;

	case 3:

		k *= 2;
		break;

	default: return;

	}

}

void printDif() {
	cout << "\t\t\t\t\t    Difficulty: " << difficulty << "\n\n";
}