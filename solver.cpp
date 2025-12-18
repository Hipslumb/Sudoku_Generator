#include "funcHeaders.h"

void human_solver(int A[9][9],int original[9][9]) {
	int row, col;
	while (found_zero(A, row, col)) {
		bool marks[9][9][10];
		pensil_marks(A, marks);
		bool skip = false;
		//1 trick. one in line/block (easy one)
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (A[i][j] == 0) {
					int count = 0, candidate = 0;
					for (int k = 1; k < 10; k++) {
						if (marks[i][j][k]) {
							count++;
							candidate = k;
						}
					}
					if (count == 1) {
						A[i][j] = candidate;
						skip = true;
						break;
					}
				}
			}
			if (skip) break;
		}
		if (skip) continue;
		//2 trick. key can be only in one place (middle dificulty)
		if (solver_inBlock(A, marks) ||
			solver_inRow(A, marks) ||
			solver_inColom(A, marks)) continue;

		//3. using help dificulty * 1,5 or 2
		cout << "Stack in (" << row << "," << col << ").";
		cout << "\nTOO DIFICULT TO HUMAN, HELP WAS USED\n";
		A[row][col] = original[row][col];
	}
	if (!found_zero(A, row, col)) {
		cout << "WAS SOLVED LOGICALLY =)\n";
	}
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
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			for (int k = 1; k < 10; k++) {
				int count = 0, found_r = -1, found_c = -1;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						int r = row * 3 + i;
						int c = col * 3 + j;
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

