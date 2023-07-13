#include "DLIST_2.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file("input.txt");
	DLIST_2 D(file);
	D.print();
	std::cin.get();
	return 0;
}