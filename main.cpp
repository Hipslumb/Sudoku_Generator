#include <iostream>
#include <windows.h>
using std::cout;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << u8"Привет Мир!";
	return 0;
}