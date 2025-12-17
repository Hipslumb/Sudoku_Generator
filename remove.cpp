#include "funcHeaders.h"

void remove(int A[9][9], int diff) {

	int value, cannot_delete = 0;

	for (int i = 81; i > diff; i--) {

		int row = rand() % 9, col = rand() % 9;
		if (cannot_delete >= 81 - (81 - i)) break;
		if (A[row][col] == 0) {i++; continue;}

		value = A[row][col];
		A[row][col] = 0;

		if (!one_solution(A)) {
			i++;
			A[row][col] = value;
			cannot_delete++;
			continue;
		}
		cannot_delete = 0;
	}
}

bool found_zero(int A[9][9], int& row, int& col) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (A[i][j] == 0) {
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool one_solution(int A[9][9]) {

	int tmp[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			tmp[i][j] = A[i][j];
		}
	}

	int count = 0;
	int first[9][9] = { 0 };

	count_solutions(A, count, first);

	return (count == 1);

}

void count_solutions(int tmp[9][9],int& count, int first[9][9]) {

	if (count > 1) return;
	int row, col;
	if (!found_zero(tmp, row, col)) {

		if (count == 0) {

			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					first[i][j] = tmp[i][j];
				}
			}
			count++;
		}
		else  {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (first[i][j] == tmp[i][j]) {
						count++;
						return;
					}
				}
			}
		}
		return;

	}

	for (int Z = 1; Z < 10; Z++) {
		if (!already_was(tmp, Z, row, col)) {
			tmp[row][col] = Z;
			count_solutions(tmp,count, first);
			tmp[row][col] = 0;
			if (count > 1) return;
		}
	}

}