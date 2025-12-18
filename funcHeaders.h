#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>


using std::cout;
using std::list;

void mix_array(int A[], int size);
void fill_diagonal(int A[9][9]);

bool already_was(int A[9][9], int key, int row, int col);
bool was_inColom(int A[9][9], int key, int row, int col);
bool was_inRow(int A[9][9], int key, int row, int col);
bool was_inBlock(int A[9][9], int key, int row, int col);

bool all_generator(int A[9][9]);
void check_filling(int A[9][9], bool filled);

void remove(int A[9][9], int diff);
bool found_zero(int A[9][9], int& row, int& col);
void remove(int A[9][9], int diff);
bool one_solution(int A[9][9]);
void count_solutions(int tmp[9][9], int& count, int first[9][9]);

void human_solver(int A[9][9], int original[9][9]);
bool solver_inRow(int A[9][9], bool marks[9][9][10]);
bool solver_inColom(int A[9][9], bool marks[9][9][10]);
bool solver_inBlock(int A[9][9], bool marks[9][9][10]);
void pensil_marks(int A[9][9], bool marks[9][9][10]);

