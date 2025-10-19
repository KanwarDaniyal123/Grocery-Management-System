#pragma once
#include <iostream>
using namespace std;
#include <fstream>


class personalhygiene
{
protected:
	char phname[100];
	int phprice;
public:
	personalhygiene()
	{
		phname[0] = '\0';
		phprice = 0;
	}

	void setphhname(string x)
	{
		strcpy_s(phname, x.length() + 1, x.c_str());
	}

	char* getphname()
	{
		return phname;
	}

	void setphprice(int n)
	{
		phprice = n;
	}

	int getphprice()
	{
		return phprice;
	}

	void displaypersonalhygiene()
	{
		cout << "\t\t\t***** PERSONAL HYGIENE *****\n";
		cout << "[1] Shampoo\n[2] Soap\n[3] Hand Sanitizer\n---------------------------------------------------------------------------\n";
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
			setphhname("shampoo");
			setphprice(90);
			break;
		case 2:
			setphhname("soap"); 
			setphprice(60); 
			break;
		case 3:
			setphhname("hand_sanitizer"); 
			setphprice(120); 
			break;
		}
	}
};

