#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

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
	int block[9] = {1,2,3,4,5,6,7,8,9};
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


bool solver(int A[9][9]) {
	int i = 0, j = 0;
	bool error = false;
	while (i < 9) {
		if (A[i][j] != 0 && !error) {
			j++;
			if (j == 9) {
				j = 0; i++;
			}
			continue;
		}
		int key = (error) ? A[i][j] + 1 : 1;
		bool new_key = false;
		for (int k = key; k < 10; k++) {
			if (!already_was(A, k, i, j)) {
				A[i][j] = k;
				error = false;
				new_key = true;
				j++;
				if (j == 9) { j = 0; i++; };
				break;
			}
			
		}
		if (!new_key) {
			j--;
			error = true;
			if (j < 0) { j = 8; i--; }
			if (i < 0)return false;
		}
	}
	return true;
}

void print_81(int A[9][9]) {
	cout << "\n\n\n\n\n\n";
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
	cout << "\n\n\n\n\n\n";
}


int main() {
	srand(time(0));
	int latin_square[9][9] = { 0 };

	fill_diagonal(latin_square);
	solver(latin_square);
	print_81(latin_square);
	
	return 0;
}