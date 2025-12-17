#include "funcHeaders.h"

void human_solver(int A[9][9]) {
	int row, col;
	while (found_zero(A, row, col)) {
		//one in line/block

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
		//key can be only in one place
		if (solver_inBlock(A, row, col) ||
			solver_inRow(A, row, col) ||
			solver_inColom(A, row, col)) continue;

		cout << "Stack in (" << row << "," << col << ").";
		break;
	}
}

bool solver_inRow(int A[9][9], int row, int col) {
	for (int k = 1; k < 10; k++) {

		if (was_inRow(A, k, row, col)) continue;
		int places = 0, place = -1;

		for (int c = 0; c < 9; c++) {
			if (A[row][c] == 0) {
				if (!already_was(A, k, row, c)) {
					places++;
					place = c;
				}
			}
		}

		if (places == 1) {
			A[row][place] = k;
			return true;
		}
	}
	return false;
}
bool solver_inColom(int A[9][9], int row, int col) {
	for (int k = 1; k < 10; k++) {

		if (was_inColom(A, k, row, col)) continue;
		int places = 0, place = -1;

		for (int r = 0; r < 9; r++) {
			if (A[r][col] == 0) {
				if (!already_was(A, k, r, col)) {
					places++;
					place = r;
				}
			}
		}
		if (places == 1) {
			A[place][col] = k;
			return true;
		}
	}
	return false;
}
bool solver_inBlock(int A[9][9], int row, int col){
	int start_row = (row / 3) * 3;
	int start_col = (col / 3) * 3;
	for (int k = 1; k < 10; k++) {

		if (was_inBlock(A, k, row, col)) continue;
		int places = 0, place = -1;

		int place_r = -1, place_c = -1;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int r = start_row + i;
				int c = start_col + j;

				if (A[r][c] == 0) {
					if (!already_was(A, k, r, c)) {
						places++;
						place_r = r;
						place_c = c;
					}
				}
			}
		}
		if (places == 1) {
			A[place_r][place_c] = k;
			return true;
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

bool pensil_marks(int A[9][9], bool marks[9][9][10]) {
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
