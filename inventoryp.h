#pragma once
#pragma once
#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;

class inventoryp
{
protected:
	char name[20];
	int pr; int quant;

public:
	inventoryp()
	{
		name[0] = '\0';
		pr = 0;
		quant = 0;
	}

	char* getname()
	{
		return name;
	}

	void setname(string x)
	{
		strcpy_s(name, x.length() + 1, x.c_str());
	}

	void setquantity(int y)
	{
		quant = y;
	}

	int getquantity()
	{
		return quant;
	}

	int getprice()
	{
		return pr;
	}

	void setall()
	{
		cout << "enter name of product you want to add: ";
		cin >> name;
		cout << "enter price per unit: ";
		cin >> pr;
		cout << "enter quantity: ";
		cin >> quant;
	}
	void setnotall()
	{
		cin >> name >> quant;
	}
	void display()
	{
		cout << "\n" << name << "\t\t\t" << pr << "\t\t\t" << quant << endl;
	}

	void writei()
	{
		ofstream myFile("inventoryp.bin", ios::binary | ios::app);
		myFile.write((char*)this, sizeof(*this));
		myFile.close();
	}


	void dele()
	{
		bool found = 0;
		cout << "enter product you want to delete: ";
		string str1;
		cin >> str1;
		inventoryp temp;
		fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getname() != str1)
			{
				myFile_temp.write((char*)&temp, sizeof(temp));
			}
			else
			{
				cout << "successfully deleted.";
				found = 1;
			}

		}
		if (found == 0)
		{
			cout << "record not found.";
		}
		cin.get();
		cin.get();


		myFile.close();
		myFile_temp.close();
		remove("inventoryp.bin");
		rename("temp.bin", "inventoryp.bin");

	}

	void updatein()
	{
		string str1, str2;
		cout << "enter old item: ";
		cin >> str1;
		cout << "enter new item: ";
		cin >> str2;
		inventoryp temp;
		fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))

		{
			if (temp.getname() == str1)
			{
				temp.setname(str2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
	}


	void addtocart()
	{
		//inventoryp inventry;
		bool found = 0;
		string str1[100];
		int q[100];
		int c = 0;
		int b = 0;
		char ch = ' ';
	start:
		do
		{

			cout << endl << "enter product you want to add to cart : ";
			cin >> str1[c];
			cout << "enter quantity: ";
			cin >> q[c];
			c++;
			cout << "Do you want to buy another product(if yes press y otherwise press any key) :   ";
			cin >> ch;

		} while (ch == 'y' || ch == 'Y');

		system("cls");

		inventoryp temp;

		cout << "\----------CAAAAARRRRRRTTTTTTTTTTT---------- " << endl << endl;
		cout << "\tPRODUCT" << "       " << "QUANTITY" << "       " << "PRICE PER UNIT" << endl;

		//	fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
		for (int i = 0; i < c; i++)
		{
			fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
			myFile.read((char*)&temp, sizeof(temp));
			while (!myFile.eof())

			{

				if (temp.getname() == str1[i])
				{

					cout << "\t" << str1[i] << "     " << "\t" << q[i] << "     " << "\t\t" << temp.getprice() << endl;
					found = 1;
				}
				myFile.read((char*)&temp, sizeof(temp));
			}
			if (found == 0)
				cout << "record not found. " << endl;

		}
		cout << "\t\t    1.Proceed to checkout\n";
		cout << "\t\t    2.Return to Menu\n";
		cin >> b;
		while (b > 2 || b < 1)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> b;
		}
		if (b == 1)
		{

			int sum = 0;
			system("CLS");
			cout << "\t" << "NAME" << "     " << "\t" << "QUANTITY" << "     " << "\t" << "PRICE" << endl;
			/*for (int i = 0; i < c; i++)
			{

				sum += q[i] * temp.getprice();
				cout << "\t" << str1[i] << "     " << "\t" << q[i] << "     " << "\t" << q[i] * temp.getprice() << endl;


			}*/
			for (int i = 0; i < c; i++)
			{
				fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
				myFile.read((char*)&temp, sizeof(temp));
				while (!myFile.eof())

				{

					if (temp.getname() == str1[i])
					{

						cout << "\t" << str1[i] << "     " << "\t" << q[i] << "\t\t" << temp.getprice() * q[i] << endl;
						sum += q[i] * temp.getprice();
					}

					myFile.read((char*)&temp, sizeof(temp));
				}

			}

			cout << "\t\tTotal Price: " << sum << endl;
			cout << "\t\tChoose Payment Option: \n";
			int s = 0;
			cout << "\t\t    1.Easypaisa\n";
			cout << "\t\t    2.Jazzcash\n";
			cout << "\t\t    3.Credit or Debit Card\n";
			cout << "\t\t    4.Cash On Delivery\n";
			cout << "\t\t        select:";
			cin >> s;
			while (s > 4 || s < 1)
			{
				cout << "Invalid input. \n-->Please Enter valid input: ";
				cin >> s;
			}
			if (s == 1)
			{
				payment* p = new easypaisa;
				p->input();
				cout << "PAYMENT SUCCESSFUL . WE HOPE TO SEE YOU AGAIN :) ";
				inventoryp temp;
				fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
				for (int i = 0; i < c; i++)
				{
					/*while (myFile.read((char*)&temp, sizeof(temp)))
					{*/
					fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
					myFile.read((char*)&temp, sizeof(temp));
					while (!myFile.eof())
					{
						if (temp.getname() == str1[i])
						{
							temp.setquantity(temp.getquantity() - q[i]);
							int current = myFile.tellg();
							int oneblock = sizeof(temp);
							myFile.seekg(current - oneblock);
							myFile.write((char*)&temp, sizeof(temp));
							myFile.close();
						}
						myFile.read((char*)&temp, sizeof(temp));
					}
				}
				cout << endl;
				cout << "Remaining Balance: " << 20000 - sum << endl;
				cin.get();
				cin.get();

			}
			else if (s == 2)
			{
				payment* p = new jazzcash;
				p->input();
				cout << "PAYMENT SUCCESSFUL . WE HOPE TO SEE YOU AGAIN :) ";
				inventoryp temp;
				fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
				for (int i = 0; i < c; i++)
				{
					fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
					myFile.read((char*)&temp, sizeof(temp));
					while (!myFile.eof())
					{
						if (temp.getname() == str1[i])
						{
							temp.setquantity(temp.getquantity() - q[i]);
							int current = myFile.tellg();
							int oneblock = sizeof(temp);
							myFile.seekg(current - oneblock);
							myFile.write((char*)&temp, sizeof(temp));
							myFile.close();
						}
						myFile.read((char*)&temp, sizeof(temp));
					}
				}
				cout << endl;
				cout << "Remaining Balance: " << 20000 - sum << endl;
				cin.get();
				cin.get();

			}
			else if (s == 3)
			{
				payment* p = new debit;
				p->input();
				cout << "PAYMENT SUCCESSFUL . WE HOPE TO SEE YOU AGAIN :) " << endl;
				inventoryp temp;
				fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
				for (int i = 0; i < c; i++)
				{
					/*while (myFile.read((char*)&temp, sizeof(temp)))
					{*/
					fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
					myFile.read((char*)&temp, sizeof(temp));
					while (!myFile.eof())
					{
						if (temp.getname() == str1[i])
						{
							temp.setquantity(temp.getquantity() - q[i]);
							int current = myFile.tellg();
							int oneblock = sizeof(temp);
							myFile.seekg(current - oneblock);
							myFile.write((char*)&temp, sizeof(temp));
							myFile.close();
						}
						myFile.read((char*)&temp, sizeof(temp));
					}
				}
				cout << endl;
				cout << "Remaining Balance: " << 20000 - sum << endl;
				cin.get();
				cin.get();


			}
			else if (s == 4)
			{
				payment* p = new cod;
				p->input();
				cout << "PAYMENT SUCCESSFUL . WE HOPE TO SEE YOU AGAIN :) ";
				inventoryp temp;
				fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
				for (int i = 0; i < c; i++)
				{
					/*while (myFile.read((char*)&temp, sizeof(temp)))
					{*/
					fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
					myFile.read((char*)&temp, sizeof(temp));
					while (!myFile.eof())
					{
						if (temp.getname() == str1[i])
						{
							temp.setquantity(temp.getquantity() - q[i]);
							int current = myFile.tellg();
							int oneblock = sizeof(temp);
							myFile.seekg(current - oneblock);
							myFile.write((char*)&temp, sizeof(temp));
							myFile.close();
						}
						myFile.read((char*)&temp, sizeof(temp));
					}
				}
				cout << endl;
				cout << "Remaining Balance: " << 20000 - sum << endl;
				cin.get();
				cin.get();

			}


		}
		else if (b == 2)
			return;

	}



	void search()
	{
		bool found = 0;
		string str1;
		cout << endl << "search any product : ";
		cin >> str1;

		inventoryp temp;
		fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))

		{
			if (temp.getname() == str1)
			{
				temp.display();
				found = 1;
			}
		}
		if (found == 0)
			cout << "record not found. " << endl;


	}

	void retrieve()
	{
		cout << endl << "\t\tWELCOME TO INVENTORY OF PESHAWAR";
		cout << left << "\n" << "NAME" << "\t\t\t" << "PRICE PER UNIT" << "\t\t" << "QUANTITY";
		inventoryp temp;
		ifstream myFile("inventoryp.bin", ios::binary);

		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			temp.display();
		}
		myFile.close();
	}

	void refil()
	{
		int qty = 0;
		string str1;
		cout << endl << "enter item whose quantity you want to refill: ";
		cin >> str1;
		cout << "enter quantity to be added: ";
		cin >> qty;
		inventoryp temp;
		fstream myFile("inventoryp.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))

		{
			if (temp.getname() == str1)
			{
				temp.setquantity(temp.getquantity() + qty);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		cout << "\n\nStock updated.";
		cin.get();
		cin.get();

	}

};

