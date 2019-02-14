//Jayson Mott
//COMP 233
//Wednesday Night

#include "Item.h"
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
	//set precision
	cout << fixed << setprecision(2);
	//test default item
	Item noItem;
	//test string, string, double
	Item tv("CF6283", "HST", 998.56);
	//TV get part number
	cout << "The Part Number for the TV is: " << tv.getPartNumber() << endl;
	//TV get dept code
	cout << "The Department Code for the TV is: " << tv.getDepartmentCode() << endl;
	//TV get price
	cout << "The Price for the TV is: " << tv.getPrice() << endl;
	//set new part num TV
	tv.setPartNumber("HY1827");
	//set new department code for TV
	tv.setDepartmentCode("BDR");
	//set new price for item TV
	tv.setPrice(665.34);
	//TV's new part num
	cout << "The New Part Number for the TV is: " << tv.getPartNumber() << endl;
	//TV's new dept code
	cout << "The New Department Code for the TV is: " << tv.getDepartmentCode() << endl;
	//TV's new price
	cout << "The New Price for the TV is: " << tv.getPrice() << endl;
	//TV price test if user inputs 3 or more numbers after decimal
	//TV set new price
	tv.setPrice(987.544);
	//TV's new price
	cout << "The New Price for the TV is: " << tv.getPrice() << endl;
	//test string line
	Item chair("HY8765 KIK 98.34");
	//new string setData to test stod, retun only 2 decimals places and white space
	chair.setData("   GF6523    JFT      87.233 ");
	//return string
	chair.getData();
	//chair part number
	cout << "The Part Number for the Chair is: " << chair.getPartNumber() << endl;
	//chair dept code
	cout << "The Department Code for the Chair is: " << chair.getDepartmentCode() << endl;
	//chair price
	cout << "The Price for the Chair is: " << chair.getPrice() << endl;
	//test string, string, string
	Item table("HS7263", "FRF", "87.32");
	//table part num
	cout << "The Part Number the Table is: " << table.getPartNumber() << endl;
	//table dept code
	cout << "The Department Code for the Table is: " << table.getDepartmentCode() << endl;
	//table price
	cout << "The Price for the Table is: " << table.getPrice() << endl;
	//test stod and return only two decimal places
	table.setPrice("98.122");
	cout << "The New Price for the Table is: " << table.getPrice() << endl;
	//test cin
	//removing whitespace and if 3 decimal places are entered returns two decimal places
	cout << "Enter Item Information - Example AA9999 GGG 0.00: " << endl;
	cin >> tv;
	cout << "The Item Info You Entered for the TV was: " << tv << endl;
	//test cin >> i2 >> i3; also removes whitespaces and sets two decimal places 
	cout << "Enter Different Item Information Twice, Once on Each Input - Example AA9999 GGG 0.00: " << endl;
	cin >> tv >> chair;
	cout << "The Information You Entered for the TV was: " << tv << endl;
	cout << "The Information You Entered for the Chair was: " << chair << endl;
	cout << endl;
	
	char letter;
	cout << "Type q and hit Enter to quit: ";
	cin >> letter;

	return 0;
}