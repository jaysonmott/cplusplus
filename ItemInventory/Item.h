//Jayson Mott
//COMP 233
//Wednesday Night

//Inclusion guard
#ifndef ITEM_H_
#define ITEM_H_

//no using namespace std
#include <string>
#include <sstream>
#include <iostream>

//class definition
class Item
{
	public:

		//Constructors
		Item();
		Item(std::string partNum, std::string dept, double price);
		Item(std::string partNum, std::string dept, std::string priceStr);
		Item(std::string line);

		//Accessor member functions
		std::string getPartNumber() const;
		std::string getDepartmentCode() const;
		double getPrice() const;
		std::string getData() const;

		//Mutator member functions
		void setPartNumber(std::string partNum);
		void setDepartmentCode(std::string dept);
		void setPrice(double price);
		void setPrice(std::string priceStr);
		void setData(std::string line);

		//friend two operator overloads
		friend std::ostream & operator<<(std::ostream & out, const Item & i);		friend std::istream & operator>>(std::istream & in, Item & i);

	private:

		//private data members
		std::string partID; //part number
		std::string deptID; //department code
		std::string priceString; //priceStr for string, string, string constructor
		double cost; //price for string, string, double constructor
		std::string stringline; //line
		std::string costStr; //cost as a string for default constructor

};

#endif

