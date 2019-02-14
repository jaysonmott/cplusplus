//Jayson Mott
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


int main()
{
	//can also do stack<string>, vector<string> > names;
	stack<string> names;

	names.push("Ed");
	names.push("Joseph");
	names.push("Mary");
	names.push("Ann");
	names.push("Mark");

	cout << "The size of the stack is " << names.size() << endl;
	cout << endl;
	cout << "The name on top is " << names.top() << endl;

	names.push("Thomas");
	names.pop();
	names.pop();
	names.push("Ed");
	names.pop();
	cout << "The name on top is now " << names.top() << endl;

	cout << endl;
	char letter;
	cout << "Type q and press enter to quit: ";
	cin >> letter;
	return 0;
}