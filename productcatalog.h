#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "..//myproj/food.h"
#include "..//myproj/personalhygiene.h"
#include "..//myproj/householdcleaning.h"


class catalog :public food, public personalhygiene, public householdcleaning
{
public:
	void displaycatalog()
	{
		cout << "\t\t\t***** CATALOG *****\n";
		cout << "[1] Food\n[2] Personal Hygiene\n[3] Household Cleaning\n---------------------------------------------------------------------------\n";
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
			displayfoods();
			write();
			//retrieve();
			break;
		case 2:
			displaypersonalhygiene();
			write();
			//retrieve();
			break;
		case 3:
			displayhosuehold();
			write();
			//retrieve();
			break;
		}
	}


	void display()
	{
		if(hhprice!=0)
			cout << hhname << "    " << hhprice << endl;
		else if(phprice!=0)
			cout << phname << "    " << phprice << endl;
		else if (cerprice != 0)
			cout << cername << "    " << cerprice << endl;
		else if (grainprice != 0)
			cout << gnname << "    " << grainprice << endl;
		else if (spiceprice != 0)
			cout << spicename << "    " << spiceprice << endl;
		else if (snackprice != 0)
			cout << snackname << "    " << snackprice << endl;
		else if (vegprice != 0)
			cout << vegname << "    " << vegprice << endl;
		else if (fruitprice != 0)
			cout << fruitname << "    " << fruitprice << endl;
		else if (dairyprice != 0)
			cout << dairyname << "    " << dairyprice << endl;
		else if (meatprice != 0)
			cout << meatname << "    " << meatprice << endl;
		/*if(meatprice!=0)
			cout << meatname << "    " << meatprice << endl;
		else if(dairyprice!=0)
		cout << dairyname << "    " << dairyprice << endl;
		else if(fruitprice!=0)
		cout << fruitname << "    " << fruitprice << endl;
		else if(vegprice!=0)
		cout << vegname << "    " <<vegprice  << endl;
		else if(snackprice!=0)
		cout << snackname << "    " <<snackprice << endl;
		else if (spiceprice != 0)
		cout << spicename << "    " << spiceprice << endl;
		else if (grainprice != 0)
		cout << gnname << "    " << grainprice << endl;
		else if (cerprice != 0)
		cout << cername <<  "    " << cerprice << endl;
		else if (phprice != 0)
		cout << phname <<  "    " << phprice << endl;
		else if (hhprice != 0)
		cout << hhname << "    " << hhprice << endl;*/
	}

	void write()
	{
		ofstream myFile("catalog.bin", ios::binary | ios::app);
		myFile.write((char*)this, sizeof(*this));
		myFile.close();
	}

	void retrieve()
	{
			catalog temp;
			ifstream myFile("catalog.bin", ios::binary);

			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				temp.display();
			}
			myFile.close();
	}

	void update(int y)
	{
		string str1, str2;
		cout << "enter old item: ";
		cin >> str1;
		cout << "enter new item: ";
		cin >> str2;
		catalog temp;
		fstream myFile("catalog.bin", ios::in | ios::out | ios::binary);
		switch (y)
		{
		case 1:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getmeatname() == str1)
				{
					temp.setmeatname(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;
		case 2:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getdairyname() == str1)
				{
					temp.setdairyname(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;
		case 3:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getfruitname() == str1)
				{
					temp.setfruitname(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;
		case 4:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getvegname() == str1)
				{
					temp.setvegname(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break; 
		case 5:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getsnackname() == str1)
				{
					temp.setsnackname(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;
		case 6:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getspicename() == str1)
				{
					temp.setspicename(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;
		case 7:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getgrainname() == str1)
				{
					temp.setgrainname(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;
		case 8:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getcername() == str1)
				{
					temp.setcername(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;
		case 9:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.getphname() == str1)
				{
					temp.setphhname(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;
		case 10:
			while (myFile.read((char*)&temp, sizeof(temp)))

			{
				if (temp.gethhnname() == str1)
				{
					temp.sethhname(str2);
					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}
			break;


		}
			
		

	}


	void del(int y)
	{
		cout << "enter product you want to delete: ";
		string str1;
		cin >> str1;
		catalog temp;
		fstream myFile("catalog.bin", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		switch (y)
		{
		case 1:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getmeatname() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;

		case 2:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getdairyname() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;
		case 3:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getfruitname() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;
		case 4:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getvegname() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;
		case 5:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getsnackname() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;

		case 6:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getspicename() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;
		case 7:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getgrainname() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;
		case 8:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getcername() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;
		case 9:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getphname() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;
		case 10:
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.gethhnname() != str1) {
					myFile_temp.write((char*)&temp, sizeof(temp));
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("catalog.bin");
			rename("temp.bin", "catalog.bin");
			break;

		}


	}



};
