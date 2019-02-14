//Jayson Mott
#include <iostream>
#include <string>
using namespace std;

void printData(const double * const p, int size);


int main()
{
	int numScores;
	double * ptr;
	
	cout << "How many numbers do you want to enter: ";
	cin >> numScores;
	// allocate memory
	ptr = new double[numScores];
	// initialize
	for (int i = 0; i < numScores; i++)
	{
		cout << "Enter score #" << (i + 1) << ": ";
		cin >> ptr[i];  // cin >> *(ptr + i);
	}
	// process
	cout << "The data entered was" << endl;
	printData(ptr, numScores);
	cout << endl;
	// release memory
	delete[] ptr;

	char letter;
	cout << "Enter q and press Enter to quit: ";
	cin >> letter;
	return 0;
}

void printData(const double * const p, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << " ";
	}
	//p = p + 1;  // doesn't work because of  "const p"
	//p[1] = 42;  // doesn't work because of "const double"

}