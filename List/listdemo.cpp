//Jayson Mott
#include <iostream>
#include <string>
#include <list>

using namespace std;

template <class T> //or typename instead of class
void printList(list<T> & lst)
{
	cout << "The size of the list is: " << lst.size() << endl;
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << endl;
	}
}

template <typename T>
void insertOrdered(list<T> &lst, const T & val)
{
	auto it = lst.begin();
	while (it != lst.end() && *it < val)
	{
		++it;
	}
	// when exiting, it will be pointing at the first value greater than or equal to val
	lst.insert(it, val);
}

int main()
{
	list<string> names;
	names.push_front("Adam");
	names.push_back("Zebulon");
	printList(names);
	cout << endl;
	insertOrdered<string>(names, "Mark");
	printList(names);
	insertOrdered<string>(names, "Abe");
	printList(names);
	insertOrdered<string>(names, "Zek");
	printList(names);

	char letter;
	cout << "Type q and press enter to quit: ";
	cin >> letter;
	return 0;
}