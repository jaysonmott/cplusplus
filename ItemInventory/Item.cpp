//Jayson Mott
//COMP 233
//Wednesday Night

#include "Item.h"
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>


using namespace std;

//constructors
Item::Item()
{
	partID = "------";
	deptID = "---";
	costStr = "0";

	cout << "Default Item Before Input is: " << partID << " " << deptID << " " << costStr << endl;

}

Item::Item(string partNum, string dept, double price)
{
	partID = partNum;
	deptID = dept;
	cost = price;

}
//
Item::Item(string partNum, string dept, string priceStr)
{
	partID = partNum;
	deptID = dept;
	cost = stod(priceStr);

}

Item::Item(string line)
{

	stringline = line;

}

//Accessor member functions
string Item::getPartNumber() const
{
	return partID;
}

string Item::getDepartmentCode() const
{
	return deptID;
}

double Item::getPrice() const
{

	return cost;
}

string Item::getData() const
{
	cout << "The Part Number, Department Code and Price for this Item is: " << partID
		<< " " << deptID << " " << fixed << setprecision(2) << cost << endl;
	return stringline;
}

//Mutator member functions
void Item::setPartNumber(string partNum)
{
	partID = partNum;
}

void Item::setDepartmentCode(string dept)
{
	deptID = dept;
}

void Item::setPrice(double price)
{
	cost = price;
}

void Item::setPrice(string priceStr)
{

	priceString = priceStr;
	cost = stod(priceString);
}

void Item::setData(string line)
{

	bool prev_is_space = true;
	line.erase(std::remove_if(line.begin(), line.end(), [&prev_is_space](char curr) {
		bool r = std::isspace(curr) && prev_is_space;
		prev_is_space = std::isspace(curr);
		return r;
	}), line.end());

	stringline = line;
	int space1 = line.find(' ');
	partID = line.substr(0, space1);
	int space2 = line.find(' ', space1 + 1);
	deptID = line.substr(space1 + 1, space2 - space1 - 1);
	int space3 = line.find(' ', space2 + 1);
	cost = stod(line.substr(space2 + 1, space3 - space2 - 1));
}

//Friend two operator overloads
ostream & operator<<(ostream & out, const Item & i)
{
	out << i.getPartNumber() << " " << i.getDepartmentCode() << " " << fixed << setprecision(2) << i.getPrice() << endl;
	return out;
}

istream & operator>>(istream & in, Item & i)
{
	in >> i.partID >> i.deptID >> i.cost;
	return in;
}