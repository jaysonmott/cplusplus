//Jayson Mott

#include "Assignment.h"

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
using namespace std;

//two ordered lists
Ordered_List<Assignment *, AssignDate>ordered_by_assign;

Ordered_List<Assignment *, AssignDue>ordered_by_due;

//print details
void print_detail(Assignment *a)
{
	std::cout << "Assignment Name: " << a->getName();
	cout << endl;
	cout << "Assigned Date: " << a->getAssignDate();
	cout << endl;
	cout << "Due Date: " << a->getDueDate();
	cout << endl << endl;
}


int main()
{
	while (true)
	{
		cout << "************************************" << endl;
		cout << "1. Add New Assignment" << endl;
		cout << "2. Remove An Assignment" << endl;
		cout << "3. List The Assignments" << endl;
		cout << "4. List The Earliest Due Assignment" << endl;
		cout << "5. Exit" << endl;
		cout << "************************************" << endl;
		cout << "Please Enter Your Choice: ";
		int choice;
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			int more = 1;
			while (more)
			{
				string name;
				
				cout << "Please Enter The Name Of The Assignment: ";
				cin.ignore();
				getline(cin, name);
				string assign;
				int entered_month;
				int entered_year;
				int entered_day;
				cout << "Please Enter The Day The Assignment Was Assigned, In DD/MM/YYYY Format: ";
				
				cin >> assign;
				entered_month = stoi(assign.substr(3, 2));
				entered_day = stoi(assign.substr(0, 2));
				entered_year = stoi(assign.substr(6));
				while ((entered_day < 01) || (entered_day > 31))
				{
					cout << "Wrong Day Format, Day Must Be Between 01 and 31 (DD/MM/YYYY): " << endl;
					cout << "Exit Program And Try Again!" << endl;
					cout << "************************************" << endl;
					cout << "1. Exit" << endl;
					cout << "************************************" << endl;
					cout << "Please Enter Your Choice: ";
					int echoice;
					cin >> echoice;
					cout << endl;
					if (echoice == 1)
					{
						exit(1);
					}
					else
					{
						//exit anyway
						exit(1);
					}
				}
				while ((entered_month < 01) || (entered_month > 12))
				{
					cout << "Wrong Month, Month Must Be Between 01 and 12  (DD/MM/YYYY): " << endl;
					cout << "Exit Program And Try Again!" << endl;
					cout << "************************************" << endl;
					cout << "1. Exit" << endl;
					cout << "************************************" << endl;
					cout << "Please Enter Your Choice: ";
					int echoice;
					cin >> echoice;
					cout << endl;
					if (echoice == 1)
					{
						exit(1);
					}
					else
					{
						//exit anyway
						exit(1);
					}
				}
				while ((entered_year < 1900) || (entered_year > 2200))
				{
					cout << "Wrong Year Format, Year Must Be Between 1900 and 2200  (DD/MM/YYYY): " << endl;
					cout << "Exit Program And Try Again!" << endl;
					cout << "************************************" << endl;
					cout << "1. Exit" << endl;
					cout << "************************************" << endl;
					cout << "Please Enter Your Choice: ";
					int echoice;
					cin >> echoice;
					cout << endl;
					if (echoice == 1)
					{
						exit(1);
					}
					else
					{
						//exit anyway
						exit(1);
					}
				}
				bool correct = false;
				while (!correct)
				{
					cout << "Please Enter The Date The Assignment Is Due, In DD/MM/YYYY Format: ";
					string due;
					int entered_month;
					int entered_year;
					int entered_day;
					cin >> due;
					entered_month = stoi(due.substr(3, 2));
					entered_day = stoi(due.substr(0, 2));
					entered_year = stoi(due.substr(6));
					while ((entered_day < 01) || (entered_day > 31))
					{
						cout << "Wrong Day Format, Day Must Be Between 01 and 31 (DD/MM/YYYY): " << endl;
						cout << "Exit Program And Try Again!" << endl;
						cout << "************************************" << endl;
						cout << "1. Exit" << endl;
						cout << "************************************" << endl;
						cout << "Please Enter Your Choice: ";
						int echoice;
						cin >> echoice;
						cout << endl;
						if (echoice == 1)
						{
							exit(1);
						}
						else
						{
							//exit anyway
							exit(1);
						}
					}
					while ((entered_month < 01) || (entered_month > 12))
					{
						cout << "Wrong Month, Month Must Be Between 01 and 12  (DD/MM/YYYY): " << endl;
						cout << "Exit Program And Try Again!" << endl;
						cout << "************************************" << endl;
						cout << "1. Exit" << endl;
						cout << "************************************" << endl;
						cout << "Please Enter Your Choice: ";
						int echoice;
						cin >> echoice;
						cout << endl;
						if (echoice == 1)
						{
							exit(1);
						}
						else
						{
							//exit anyway
							exit(1);
						}
					}
					while ((entered_year < 1900) || (entered_year > 2200))
					{
						cout << "Wrong Year Format, Year Must Be Between 1900 and 2200  (DD/MM/YYYY): " << endl;
						cout << "Exit Program And Try Again!" << endl;
						cout << "************************************" << endl;
						cout << "1. Exit" << endl;
						cout << "************************************" << endl;
						cout << "Please Enter Your Choice: ";
						int echoice;
						cin >> echoice;
						cout << endl;
						if (echoice == 1)
						{
							exit(1);
						}
						else
						{
							//exit anyway
							exit(1);
						}
					}
					Assignment *newas = new Assignment(name, assign, due);
					ordered_by_assign.insert(newas);
					ordered_by_due.insert(newas);
					correct = true;
				}
				cout << "The Assignment Was Added Successfully" << endl;
				cout << endl;
				cout << "Would You Like To Add Another Assignment? (1 for yes or 0 for no): ";
				cin >> more;
				cout << endl;
			}
		}
		else if (choice == 2)
		{
			string name;
			cout << "Please Enter The Name Of The Assignment: ";
			getline(cin, name);
			getline(cin, name);
			cout << endl;
			bool flag = false;
				
			Ordered_List<Assignment *, AssignDate>::iterator itr = ordered_by_assign.begin();
			for (; itr != ordered_by_assign.end(); ++itr)
			{
				Assignment *a = *itr;
				if (a->getName() == name)
				{
					ordered_by_assign.erase(itr);
					break;
				}
					
			}
			cout << "The Assignment Was Removed" << endl << endl;
			flag = true;
		}
		else if (choice == 3)
		{
			Ordered_List<Assignment *, AssignDate>::const_iterator itr = ordered_by_assign.begin();
			for (; itr != ordered_by_assign.end(); ++itr)
			{
				Assignment *a = *itr;
				print_detail(a);
			}
		}
		else if (choice == 4)
		{
			Ordered_List<Assignment *, AssignDue>::const_iterator itr2 = ordered_by_due.begin();
			if (itr2 != ordered_by_due.end())
			{
				Assignment *a = *itr2;
				string d = a->getDueDate();
				for (; itr2 != ordered_by_due.end() && a->getDueDate() == d; ++itr2, a = *itr2)
				{
					print_detail(a);
				}
			}
		}
		else if (choice == 5)
		{
			exit(1);
		}
		else
		{
			cout << "Invalid Choice Please Try Again!" << endl << endl;
		}
			
	}
}