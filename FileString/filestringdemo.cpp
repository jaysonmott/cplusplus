//Jayson Mott
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;


int main()
{

	string line;
	double total = 0;

	ifstream fin;
	fin.open("Inventory.txt");

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

	cout << setw(30) << setfill('_') << left << "Product"
		<< "$"
		<< setw(12) << setfill(' ') << right << "Value" << endl << endl;
	fout << setw(30) << setfill('_') << left << "Product"
		<< "$"
		<< setw(12) << setfill(' ') << right << "Value" << endl << endl;

	while (fin)
	{
		getline(fin, line);
		//fin >> line;  # never use this if there might be whitespace
		if (line == "")
		{
			continue;
		}
		//cout << line << endl;

		/*
		int pos1 = line.find(',');
		int pos2 = line.find(',', pos1 + 1);
		int pos3 = line.find(',', pos2 + 1);
		int pos4 = line.find(',', pos3 + 1);
		int pos5 = line.find(',', pos4 + 1);
		int pos6 = line.find(',', pos5 + 1);

		int quant = stoi(line.substr(0, pos1));
		double itemPrice = stod(line.substr(pos6 + 1));
		string genCat = line.substr(pos2 + 1, pos3 - pos2 - 1);
		string specName = line.substr(pos3 + 1, pos4 - pos3 - 1);
		*/

		istringstream str(line);
		string item;
		getline(str, item, ',');
		int quant = stoi(item);
		getline(str, item, ',');
		getline(str, item, ',');
		string genCat = item;
		getline(str, item, ',');
		string specName = item;
		getline(str, item, ',');
		getline(str, item, ',');
		getline(str, item, ',');
		double itemPrice = stod(item);

		double value = quant * itemPrice;
		string fullName = specName + " " + genCat;
		total += value;
		cout << setw(30) << setfill('_') << left << fullName
			<< "$"
			<< setw(12) << setfill(' ') << right << value << endl;
		fout << setw(30) << setfill('_') << left << fullName
			<< "$"
			<< setw(12) << setfill(' ') << right << value << endl;
	}
	cout << endl << setw(30) << setfill('_') << left << "Total Inventory"
		<< "$"
		<< setw(12) << setfill(' ') << right << total << endl;
	fout << endl << setw(30) << setfill('_') << left << "Total Inventory"
		<< "$"
		<< setw(12) << setfill(' ') << right << total << endl;


	fin.close();
	fout.close();

	char letter;
	cout << "Type q and hit Enter to quit: ";
	cin >> letter;

	return 0;
}