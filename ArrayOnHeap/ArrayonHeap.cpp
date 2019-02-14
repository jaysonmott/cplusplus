//Jayson Mott
#include <iostream>
#include <string>

using namespace std;

int * createArray(int x);
void printArray(const int data[], int size);

int main()
{

	int * const data = createArray(5);
	printArray(data, 5);
	delete[] data; //deletes heap from array

	double * x = new double(5.24);
	cout << "x is pointing at " << *x << endl;
	delete x; //normal delete for var
	x = NULL;
	if (x != NULL)
		delete x;
	
	//cout << text;
	
	
	char letter;
	cout << "Type q and hit enter to quit: ";
	cin >> letter;

	return 0;
}

void printArray(const int data[], int size)
{
	cout << "The data is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

int * createArray(int size)
{
	int * location = new int[size];
	for (int i = 0; i < size; i++)
	{
		location[i] = 0;
	}
	return location;
}
