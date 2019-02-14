//Jayson Mott
#include <iostream>
#include <string>

using namespace std;

void printTwoInts(int, int);

int main()
{
    int x = 10; // const int would mean can't be changed but can't do with pointer
	int y = 15;

	printTwoInts(x, y);
	
	int * ptr = 0; //or 0 = NULL says pointer is not pointing anywhere //could add const here as well in front of * ptr can also add additional const in front of int
	//const in
	ptr = &x;
	cout << "The address of x is " << &x << endl;
	cout << "The value of ptr is " << ptr << endl;
	cout << "Ptr is pointed at the value " << *ptr << endl; //10 will show because 
	
	*ptr = 42; //change value

	cout << "The address of x is " << &x << endl;
	cout << "The value of ptr is " << ptr << endl;
	cout << "Ptr is pointed at the value " << *ptr << endl; //42 will show because 
	cout << "X is " << x << endl;

	ptr = &y;

	cout << "Y is " << y << endl;
	*ptr = 99;
	cout << "Y is " << y << endl;

	int data[5] = { 1,2,3,4,5 };
	//type of data is actually: int * const
	cout << "Data contains " << data << endl;
	*data = 10; // same as data[0] = 10
	*(data + 4) = 50; //same as data[4] = 50;
	for (int i = 0; i < 5; i++)
	{
		cout << data[i] << "\t" << *(data + i) << endl;
	}

	cout << "The next four bytes after y are: " << *(ptr + 1) << endl; //shouldn't do
	cout << "The next four bytes after y are: " << ptr[1] << endl; //shouldn't do
	cout << "Ptr is " << ptr << endl;
	int q = (int) ptr;
	cout << "Ptr is " << q << endl;

	char letter;
	cout << "Type q and hit enter to quit: ";
	cin >> letter;

	return 0;
}

void printTwoInts(int a, int b)
{
	cout << "The two ints are: " << a << ' ' << b << endl;
}