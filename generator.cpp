#include "funcHeaders.h"

void mix_array(int A[], int size) {
	//randomazer for block
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);

		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}

void fill_diagonal(int A[9][9]) {
	int block[9] = { 1,2,3,4,5,6,7,8,9 };
	//(0;0)
	mix_array(block, 9);
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A[i][j] = block[k];
			k++;
		}
	}
	//(3;3)
	mix_array(block, 9);
	k = 0;
	for (int i = 3; i < 6; i++) {
		for (int j = 3; j < 6; j++) {
			A[i][j] = block[k];
			k++;
		}
	}
	//(6;6)
	mix_array(block, 9);
	k = 0;
	for (int i = 6; i < 9; i++) {
		for (int j = 6; j < 9; j++) {
			A[i][j] = block[k];
			k++;
		}
	}
}

bool already_was(int A[9][9], int key, int row, int col) {
	//in colom
	for (int i = 0; i < 9; i++) {
		if (i == row) continue;
		if (A[i][col] == key) return true;
	}
	//in row
	for (int j = 0; j < 9; j++) {
		if (j == col) continue;
		if (A[row][j] == key) return true;
	}
	//in block
	int row_start = (row / 3) * 3;
	int col_start = (col / 3) * 3;
	for (int i = 0; i < 3; i++) {
		int r = row_start + i;
		if (r == row)continue;
		for (int j = 0; j < 3; j++) {
			int c = col_start + j;
			if (c == col)continue;

			if (A[r][c] == key)return true;
		}
	}
	return false;
}


bool all_generator(int A[9][9]) {
	int i = 0, j = 0;
	bool needed_to_go_back = false;
	while (i < 9) {
		//already filled (in diagonal)
		if (A[i][j] != 0 && !needed_to_go_back) {
			j++;
			if (j == 9) {
				j = 0; i++;
			}
			continue;
		}
		//finding 1-9 key
		int key = (needed_to_go_back) ? A[i][j] + 1 : 1;
		bool found_new_key = false;
		for (int k = key; k < 10; k++) {
			if (!already_was(A, k, i, j)) {
				A[i][j] = k;
				needed_to_go_back = false;
				found_new_key = true;
				j++;
				if (j == 9) { j = 0; i++; };
				break;
			}
		}
		//going back if all key was used
		if (!found_new_key) {
			A[i][j] = 0;
			j--;
			needed_to_go_back = true;
			if (j < 0) { j = 8; i--; }
			if (i < 0)return false;
		}
	}
	return true;
}
//just to be sure
void check_filling(int A[9][9], bool filled) {
	if (!filled) {
		cout << "WAS NOT FILLED AT ALL";
		return;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (already_was(A, A[i][j], i, j)) {
				cout << "(" << i << "," << j << ") ALREADY WAS";
				return;
			}
		}
	}
	cout << "SUDOKU IS CORRECT";
}