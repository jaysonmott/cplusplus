//Jayson Mott
//Assignment #1
//COMP 233

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

double calculateAverage(const double * const p, int size);

int main()
{
	string line;
	double * ptr; //done per comment below
	string grade;
    // declare a pointer to a double here which will eventually hold the address of the array of scores for a student
	ifstream fin;
	fin.open("TestData.txt");

	ofstream fout("Output.txt");

	cout << fixed << showpoint;
	cout << setprecision(2) << setfill('_');
	fout << fixed << showpoint;
	fout << setprecision(2) << setfill('_');

	if (!fin)
	{
		cout << "Could not open file.\nTerminating program." << endl;
		return 5;
	}

	cout << setw(60) << setfill(' ') << left << "Student Name"
		<< setw(30) << setfill(' ') << right << "Average" << setw(10) << setfill(' ') << right << "Grade" << endl;
	cout << setw(100) << setfill('-') << left << "-" << endl;
	fout << setw(20) << setfill(' ') << left << "Student Name"
		<< setw(30) << setfill(' ') << right << "Average" << setw(26) << setfill(' ') << left << "" << setw(20) << setfill(' ') << left << "Grade" << setw(5) << setfill(' ') << left << "Data" << endl;
	fout << setw(100) << setfill('-') << left << "-" << endl;
	getline(fin, line);
	while (fin)//get whole line in file
	{

		if (line == "")//if blank line continue with next line
		{

			continue;
		}

		//cout << line << endl; //test

		istringstream str(line);
		string item;
		getline(str, item, ',');
		string sname = item;
		getline(str, item, ',');
		int numTests = stoi(item);
		
		if (numTests == 0)
		{
			cout << setw(60) << setfill('_') << left << sname << setw(30) << setfill('_') << right << "0.00" << setw(10) << setfill('_') << right << "F" << endl;
			fout << setw(20) << setfill('_') << left << sname << setw(30) << setfill('_') << right << "0.00" << setw(30) << setfill('_') << left << "" << setw(15) << setfill(' ') << left << "F" << endl;

		}
		else
		{
			ptr = new double[numTests];

			for (int i = 0; i < numTests; i++)
			{
				getline(str, item, ',');
				ptr[i] = stod(item);
			}


			if (calculateAverage(ptr, numTests) >= 90 || calculateAverage(ptr, numTests) == 100)
			{
				grade = "A";
			}
			else if (calculateAverage(ptr, numTests) >= 80 || calculateAverage(ptr, numTests) == 90)
			{
				grade = "B";
			}
			else if (calculateAverage(ptr, numTests) >= 70 || calculateAverage(ptr, numTests) == 80)
			{
				grade = "C";
			}
			else if (calculateAverage(ptr, numTests) >= 60 || calculateAverage(ptr, numTests) == 70)
			{
				grade = "D";
			}
			else if (calculateAverage(ptr, numTests) < 70)
			{
				grade = "F";
			}
			int pos1 = line.find(',');
			int pos2 = line.find(pos1 + 1);
			string data = line.substr(pos1 + 1);

			cout << setw(60) << setfill('_') << left << sname << setw(30) << setfill('_') << right << calculateAverage(ptr, numTests) << setw(10) << setfill('_') << right << grade << endl;
			fout << setw(20) << setfill('_') << left << sname << setw(30) << setfill('_') << right << calculateAverage(ptr, numTests) << setw(30) << setfill('_') << left << "" << setw(15) << setfill(' ') << left << grade << setw(5) << setfill(' ') << left << data << endl;

			delete[] ptr;
		}
		getline(fin, line);
	}
	fin.close();//close input file
	fout.close();//close output file
	cout << endl;
	char letter;
	cout << "Type q and hit Enter to quit: ";
	cin >> letter;

	return 0;
}


double calculateAverage(const double * const p, int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total = total + p[i];
	}

	
	return total / size;

}