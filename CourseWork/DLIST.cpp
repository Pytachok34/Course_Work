#include "DLIST.h"
ptrNODE find_place(ptrNODE begin, const TInfo& student)
{
	ptrNODE p = begin;
	if (student.flag_troechnik)
		while (p && p->info.flag_troechnik)
			p = p->next;
	else
	{
		while (p)
			p = p->next;
	}
	return p;
}
DLIST::DLIST(std::ifstream& file)
{
	TInfo student(file);
	first_node(student);
	ptrNODE place;
	while (!file.eof())
	{
		TInfo student(file);
		place = find_place(begin, student);
		if (place)
			add_before(place, student);
		else
			add_after(end, student);
	}
	file.close();
}

void DLIST::first_node(const TInfo& student)
{
	begin = new NODE(student);
	end = begin;
}

bool DLIST::empty()
{
	return begin == nullptr;
}

void DLIST::add_after(ptrNODE ptr, const TInfo& student)
{
	ptrNODE p = new NODE(student, ptr->next, ptr);
	if (ptr == end)
		end = p;
	else
		ptr->next->prev = p;
	ptr->next = p;
}

void DLIST::add_before(ptrNODE ptr, const TInfo& student)
{
	ptrNODE p = new NODE(student, ptr, ptr->prev);
	if (ptr == begin)
		begin = p;
	else
		ptr->prev->next = p;
	ptr->prev = p;
}

void DLIST::del_before(ptrNODE& ptr)
{
	if (ptr && ptr->prev)
	{
		if (ptr->prev == begin)
			begin = ptr;
		Delete(ptr->prev);
		--size;
	}
}

void DLIST::del_after(ptrNODE& ptr)
{
	if (ptr && ptr->next)
	{
		if (ptr->next == end)
			end = ptr;
		Delete(ptr->next);
		--size;
	}
}

void DLIST::print()
{
	ptrNODE ptr = begin;
	while (ptr)
	{
		ptr->info.print();
		ptr = ptr->next;
	}
}

DLIST::~DLIST()
{
	while (!empty())
		Delete(begin);
}

TInfo& DLIST::Delete(ptrNODE& ptr)
{
	ptrNODE p = ptr;
	if (ptr == begin)
	{
		begin = p->next;
		ptr = begin;
		if (p->next)
			p->next->prev = nullptr;
	}
	else
		if (ptr == end)
		{
			end = p->prev;
			ptr = end;
			if (p->prev)
				p->prev->next = nullptr;
		}
		else
		{
			ptr = ptr->next;
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
	static TInfo student;
	student = p->info;
	delete p;
	return student;
}