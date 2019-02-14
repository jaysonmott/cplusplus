//Jayson Mott
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

bool reverseSort(string a, string b)
{
	return b < a;
}
void displayInitial(string s)
{
	cout << s[0] << endl;
}

struct InitialMaker
{
	string s;
	void operator()(string s) { cout << s[0] << endl; }
};

int main()
{
	list<string> names;
	names.push_front("Mark");
	names.push_front("Tom");
	names.push_front("Ed");
	names.push_front("Mary");
	names.push_front("Ann");
	names.push_front("Zebulon");

	int len = names.size();
	cout << "There are " << len << " names in the list." << endl;
	cout << endl;

	vector<string> vnames(6);
	auto it = copy(names.begin(), names.end(), vnames.begin());
	cout << "The vector is: " << endl;
	for (string s : vnames) //could use auto instead of string
	{
		cout << s << endl;
	}
	cout << endl;

	string last = *max_element(vnames.begin(), vnames.end()); //same as auto it = max_element(vnames.begin(), vnames.end()); string last = *it; //auto it can be vector<string>::iterator it .....
	cout << "The last name in the list was: " << last << endl;
	cout << endl;
	string first = *min_element(vnames.begin(), vnames.end()); //same as auto it = max_element(vnames.begin(), vnames.end()); string first = *it; //auto it can be vector<string>::iterator it .....
	cout << "The first name in the list was: " << first << endl;
	cout << endl;

	//displayInitial is a function pointer, address in memory where code is locate
	//cout << displayInitial << endl;
	for_each(vnames.begin(), vnames.end(), displayInitial);
	cout << endl;
	//with struct you can now do
	InitialMaker maker;
	for_each(vnames.begin(), vnames.end(), maker);
	cout << endl;
	sort(vnames.begin(), vnames.end());
	cout << endl;
	for (string s : vnames)
	{
		cout << s << endl;
	}
	cout << endl;
	sort(vnames.begin(), vnames.end(), reverseSort);
	for (string s : vnames)
	{
		cout << s << endl;
	}
	cout << endl;

	//array pointers are considered convertible to iterators
	const int DATA_SIZE = 7;
	int data[DATA_SIZE] = { 34, 79, 22, 15, 98, 32, 47 };
	cout << "Data begins at: " << data << endl;
	cout << "Data ends right before: " << data + DATA_SIZE << endl;
	sort(data, data + DATA_SIZE);
	for (int i = 0; i < DATA_SIZE; i++)
	{
		cout << data[i] << endl;
	}

	cout << endl;
	char letter;
	cout << "Type q and press enter to quit";
	cin >> letter;
}