#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

void mix_array(int A[], int size);
void fill_diagonal(int A[9][9]);
bool already_was(int A[9][9], int key, int row, int col);
bool all_generator(int A[9][9]);
void check_filling(int A[9][9], bool filled);