#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <Windows.h>

struct Student
{
	std::string name = "";
	std::string surname = "";
	float Average_mark = 0;
	bool flag_troechnik = true;
	Student() {};
	Student(std::ifstream& file)
	{
		file >> name;
		file >> surname;
		int mark;
		for (int i = 0; i < 4; ++i)
		{
			file >> mark;
			Average_mark += mark;
			if (flag_troechnik && mark != 3)
				flag_troechnik = false;
		}
		Average_mark = Average_mark / 4;
	}
	void print()
	{
		std::cout << name << ' ' << surname << '\n';
		std::cout << "Average mark= " << Average_mark << '\n';
	}

};


