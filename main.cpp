#include "funcHeaders.h"

void print_81(int A[9][9]) {
	cout << "\n\n";
	cout << "\t\t\t\t\t+-------+-------+-------+\n";
	for (int i = 0; i < 9;i++) {
		cout << "\t\t\t\t\t";
		cout << "| ";
		for (int j = 0; j < 9; j++) {
			cout << A[i][j];
			if (j == 2 || j == 5)cout << " | ";
			else cout << " ";
		}
		cout << "|";
		cout << "\n";
		if (i == 2 || i == 5) cout << "\t\t\t\t\t+-------+-------+-------+\n";
	}
	cout << "\t\t\t\t\t+-------+-------+-------+\n";
	cout << "\n\n";
}

int main() {
	srand(time(0));
	int latin_square[9][9] = { 0 };
	int difficulty = 0;

	fill_diagonal(latin_square);

	//check
	bool filled = all_generator(latin_square);
	check_filling(latin_square, filled);
	print_81(latin_square);
	int copy[9][9] = { 0 };

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			copy[i][j] = latin_square[i][j];
		}
	}

	int diff = 1 + rand() % 81;
	remove(latin_square,diff);
	print_81(latin_square);

	human_solver(latin_square,copy);
	check_filling(latin_square, filled);

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if (latin_square[i][j] != copy[i][j]) {
				//never but we need to check
				cout << "\nUNCORRECTLY SOLVED";
			}
		}
	}

	print_81(latin_square);
	printDif();

	return 0;
}