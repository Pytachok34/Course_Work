#pragma once
#include "Student.h"

using TInfo = Student;

struct NODE
{
	TInfo info;
	NODE* next, * prev;
	NODE(TInfo info, NODE* next = nullptr, NODE* prev = nullptr) :info(info), next(next), prev(prev) {}
	~NODE()
	{
		next = nullptr;
		prev = nullptr;
	}
};

using  ptrNODE = NODE*;
struct DLIST
{
private:
	ptrNODE begin, end;
	size_t size;
public:
	DLIST() { begin = nullptr, end = nullptr; };
	DLIST(std::ifstream& file);
	void first_node(const TInfo& student);
	bool empty();
	void add_after(ptrNODE ptr, const TInfo& student);
	void add_before(ptrNODE ptr, const TInfo& student);
	void del_before(ptrNODE& ptr);
	void del_after(ptrNODE& ptr);
	void print();
	~DLIST();
	TInfo& Delete(ptrNODE& ptr);
	ptrNODE get_begin()
	{
		return begin;
	}
};

