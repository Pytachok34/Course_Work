#pragma once
#include "Student.h"
using TInfo = Student;

struct NODE2
{
	TInfo info;
	NODE2* next, * prev;
	NODE2(TInfo info, NODE2* next = nullptr, NODE2* prev = nullptr) :info(info), next(next), prev(prev) {}
	~NODE2()
	{
		next = nullptr;
		prev = nullptr;
	}
};

using  ptrNODE = NODE2*;
class DLIST_2
{
private:
	ptrNODE begin, end;
	size_t size;
public:
	DLIST_2() { begin = nullptr, end = nullptr; };
	DLIST_2(std::ifstream& file);
	void first_node(const TInfo& student);
	bool empty();
	void add_after(ptrNODE ptr, const TInfo& student);
	void add_before(ptrNODE ptr, const TInfo& student);
	void del_before(ptrNODE& ptr);
	void del_after(ptrNODE& ptr);
	void print();
	~DLIST_2();
	TInfo& Delete(ptrNODE& ptr);
	ptrNODE get_begin()
	{
		return begin;
	}
};

