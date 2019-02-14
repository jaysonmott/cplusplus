//Jayson Mott

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

#include <list>
#include <string>

template<typename Item_Type, typename Comp>
class Ordered_List
{
private:
	//a list to contain ordered list
	std::list<Item_Type> a_list;

	//comparision object
	Comp comp;
public:
	//typedefs
	typedef typename std::list<Item_Type>::const_iterator const_iterator;
	typedef typename std::list<Item_Type>::iterator iterator;

	//insert new item into list and maintain order
	void insert(const Item_Type& an_item)
	{
		typename std::list<Item_Type>::iterator itr = a_list.begin();
		while (itr != a_list.end() && comp(*itr, an_item))
		{
			++itr;
		}
		//insert function
		a_list.insert(itr, an_item);
	}

	//remove an item pointed to by itr
	iterator erase(iterator itr)
	{
		return a_list.erase(itr);
	}

	//remove element from list
	void remove(const Item_Type& item)
	{
		a_list.remove();
	}

	//make iterator point to start of list
	iterator begin()
	{
		return a_list.begin();
	}

	//make iterator point to end of list
	iterator end()
	{
		return a_list.end();
	}
};

class Assignment
{
private:
	std::string name;
	std::string date;
	std::string due;

public:
	//construct new assignment
	Assignment(std::string n, std::string a, std::string d) :
		name(n), date(a), due(d)
	{}

	//return the name of assignment
	std::string getName()
	{
		return name;
	}

	//return date the assignment was given
	std::string getAssignDate()
	{
		return date;
	}

	//return due date
	std::string getDueDate()
	{
		return due;
	}

};

//compare assigned dates
class AssignDate
{
public:
	bool operator()(Assignment *a1, Assignment *a2)
	{
		return a1->getAssignDate() < a2->getAssignDate();
	}
};

//compare due dates
class AssignDue
{
public:
	bool operator()(Assignment *a1, Assignment *a2)
	{
		return a1->getDueDate() < a2->getDueDate();
	}
};

#endif
