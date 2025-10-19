#pragma once
#pragma once
#include <iostream>
using namespace std;
#include <fstream>


class householdcleaning
{
protected:
	char hhname[100];
	int hhprice;
public:
	householdcleaning()
	{
		hhname[0] = '\0';
		hhprice = 0;
	}

	void sethhname(string x)
	{
		strcpy_s(hhname, x.length() + 1, x.c_str());
	}

	char* gethhnname()
	{
		return hhname;
	}

	void sethhprice(int n)
	{
		hhprice = n;
	}

	int gethhprice()
	{
		return hhprice;
	}

	void displayhosuehold()
	{
		cout << "\t\t\t***** HOUSEHOLD CLEANING *****\n";
		cout << "[1] Detergent\n[2] Dish Soap\n[3] Washroom Cleaner\n---------------------------------------------------------------------------\n";
		int n1 = 0;
		cin >> n1;

		while (n1 > 3 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			sethhname("detergent");
			sethhprice(160);
			break;
		case 2:
			sethhname("dish_shop"); 
			sethhprice(60); 
			break;
		case 3:
			sethhname("washroom_cleaner");
			sethhprice(90); 
			break;
		}
	}
};

