#include "funcHeaders.h"

void human_solver(int A[9][9]) {
	int row, col;
	while (found_zero(A, row, col)) {
		//1. one in line/block
		bool skip = false;
		if (one_zero(A, row, col)) {
			for (int k = 1;k < 10;k++) {
				if (!already_was(A, k, row, col)) {
					A[row][col] = k;
					skip = true;
					break;
				}
			}
			if (skip) continue;
		}
	
		if (solving_with_marks(A)) continue;

		cout << "Stack in (" << row << "," << col << ").";
		break;
	}
}

bool solver_inRow(int A[9][9], bool marks[9][9][10]) {
	for (int row = 0; row < 9; row++) {
		for (int k = 1; k < 10; k++) {
			int count = 0, col = -1;
			for (int c = 0; c < 9; c++) {
				if (marks[row][c][k]) {
					count++;
					col = c;
				}
			}
			if (count == 1) {
				A[row][col] = k;
				return true;
			}
		}
	}
	return false;
}
bool solver_inColom(int A[9][9], bool marks[9][9][10]) {
	for (int col = 0; col < 9; col++) {
		for (int k = 1; k < 10; k++) {
			int count = 0, row = -1;
			for (int r = 0; r < 9; r++) {
				if (marks[r][col][k]) {
					count++;
					row = r;
				}
			}
			if (count == 1) {
				A[row][col] = k;
				return true;
			}
		}
	}
	return false;
}
bool solver_inBlock(int A[9][9], bool marks[9][9][10]){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 1; k < 10; k++) {
				int count = 0, found_r = -1, found_c = -1;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						int r = i * 3 + i;
						int c = j * 3 + j;
						if (marks[r][c][k]) {
							count++;
							found_r = r;
							found_c = c;
						}
					}
				}
				if (count == 1) {
					A[found_r][found_c] = k;
					return true;
				}
			}
		}
	}
	return false;
}


bool one_zero(int A[9][9], int row, int col) {
	//in colom
	int countCol = 0;
	for (int i = 0; i < 9; i++) {
		if (i == row) continue;
		if (A[i][col] == 0) {
			countCol++;
			break;
		}
	}
	//in row
	int countRow = 0;
	for (int j = 0; j < 9; j++) {
		if (j == col) continue;
		if (A[row][j] == 0) {
			countRow++;
			break;
		}
	}
	//in block
	int countBlock = 0;
	int row_start = (row / 3) * 3;
	int col_start = (col / 3) * 3;
	for (int i = 0; i < 3; i++) {
		int r = row_start + i;
		if (r == row)continue;
		for (int j = 0; j < 3; j++) {
			int c = col_start + j;
			if (c == col)continue;
			if (A[r][c] == 0) {
				countBlock++;
				break;
			}
		}
	}
	return (countCol + countRow + countBlock) < 3;
}

void pensil_marks(int A[9][9], bool marks[9][9][10]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (A[i][j] == 0) {
				for (int key = 1; key < 10; key++) {
					A[i][j] = key;
					marks[i][j][key] = !already_was(A, key, i, j);
					A[i][j] = 0;
				}
			}
			else {
				for (int key = 1; key < 10; key++) {
					marks[i][j][key] = false;
				}
			}
		}
	}
}

bool solving_with_marks(int A[9][9]) {
	bool marks[9][9][10];
	pensil_marks(A, marks);

	//1. one in line/block
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (A[i][j] == 0) {
				int count = 0, candidate = 0;
				for (int k = 1; k <= 9; k++) {
					if (marks[i][j][k]) {
						count++;
						candidate = k;
					}
				}
				if (count == 1) {
					A[i][j] = candidate;
					return true;
				}
			}
		}
	}
	//2. key can be only in one place
	if (solver_inBlock(A, marks) ||
		solver_inRow(A, marks) ||
		solver_inColom(A, marks)) return true;
	return false;
}