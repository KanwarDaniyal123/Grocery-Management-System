#pragma once
#include "..//myproj/customer.h"
#include "..//myproj/manager.h"
#include "..//myproj/admin.h"
#include "..//myproj/independentfuncs.h"
#include "..//myproj/inventoryisb.h"
#include "..//myproj/inventorykhi.h"
#include "..//myproj/inventoryp.h"
#include "..//myproj/feedback.h"
#include <iostream>
#include <fstream>
using namespace std;
class user : public customer, public admin, public manager
{
protected:
	char cnic[25];
	char password[25];
public:
	user()
	{
		g = ' ';
		pn[0] = '\0';
		address[0] = '\0';
		password[0] = '\0';
		cnic[0] = '\0';
	}

	void setcnic(string s)
	{
		strcpy_s(cnic, s.length() + 1, s.c_str());
	}

	void setpassword(string s)
	{
		strcpy_s(password, s.length() + 1, s.c_str());
	}

	char* getcnic()
	{
		return cnic;
	}

	char* getpassword()
	{
		return password;
	}


	void  usermenu()
	{
		int n, n1, n3;
		cout << "\t\t\t***** GROCERY STORE *****\n";
		cout << "[1] REGISTER\n[2] LOGIN\n[3] Exit\n---------------------------------------------------------------------------\n";

		cin >> n;

		while (n > 3 || n < 1)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n;
		}

		switch (n)
		{
		case 1:
			cout << "-->Press 1 to Register as a customer. \n-->Press 2 to Register as a manager(need to login through admin first): \n";
			cin >> n1;

			while (n1 > 2 || n1 < 1)
			{
				cout << "Invalid input. \n-->Please Enter valid input: ";
				cin >> n1;
			}

			switch (n1)
			{
			case 1:
				registercustomer();
				break;
			case 2:
				loginadmin();
				break;
			}
			break;
		case 2:

			cout << "-->Press 1 if you are a customer.\n-->Press 2 If you are a manager.\n-->Press 3 f you are an admin.\n";
			cin >> n3;
			while (n3 > 3 || n3 < 1)
			{
				cout << "Invalid input. \n-->Please Enter valid input: ";
				cin >> n3;
			}
			system("cls");
			switch (n3)
			{
			case 1:
				logincustomer();
				break;
			case 2:
				loginmanager();
				break;
			case 3:
				loginadmin();
				break;
			}

			break;

		case 3:
	        //exiting from program if user wants
			break;

		}

	}

	////register as customer
	void registercustomer()
	{
		system("cls");
		cout << "Enter cnic: ";
		cin >> cnic;

		while (!(cnicCheck(cnic)))
		{
			cout << "Enter a valid 13-digit cnic number: ";
			cin >> cnic;
		}
		while (findornot())
		{
			cout << "already registered cnic. enter a unique cnic: ";
			cin >> cnic;
		}

		cout << "Enter password: ";
		cin >> password;
		while (!(PasswordCheck(password)))
		{
			cout << "Enter a password with atleast 8 characters long, one uppercase and one special character: " << endl;
			cin >> password;
		}
		cout << "Reenter the password: ";
		string po;
		cin >> po;
		while (!(PasswordCheck(po)))
		{
			cout << "Enter a password with atleast 8 characters long, one uppercase and one special character: " << endl;
			cin >> po;
		}
		while (po!=password)
		{
			cout << "passwords dont match, enter again :";
			cin >> po;
		}

		cout << "Enter your gender(m for male , f for female) : ";
		cin >> g;

		while ((g != 'm' && g != 'f'))
		{
			cout << "enter valid gender(m for male , f for female) : ";
			cin >> g;
		}

		cout << "Enter your city : ";
		cin >> city;

		cout << "Enter your phone number: ";
		cin >> pn;
		string cppn = pn;
		while (cppn.length() != 11)
		{
			cout << "enter valid 11 digit phone number: ";
			cin >> pn;
			cppn = pn;
		}

		cout << "Enter your address: ";
		cin >> address;


		ofstream myFile("customer.bin", ios::binary | ios::app);
		myFile.write((char*)this, sizeof(*this));
		myFile.close();


		cout << "YOU ARE SUCCESSFULLY REGISTERED" << endl;


		logincustomer();


	}

	void display()
	{
		cout << "cnic: " << cnic << endl << "password: " << password << endl << "gender: " << g << endl << "phone number: " << pn << endl << "address: " << address << endl;
	}


	/// Login As Customer

	void logincustomer()
	{
		system("cls");
		cout << "Enter your credetials to login: ";
		while (!(findobject()))
		{
			cout << "wrong credentials entered. try again: " << endl;
			//findobject();
		}
		//customer menu
		int c = 0;
		po:
		system("cls");
		cout << "\t\t   WELCOME \n";
		cout << "\t\t    1.Show My details\n";
		cout << "\t\t    2.Online Shopping\n";
		cout << "\t\t    press 0 to log out\n";
		cout << "\t\t        select:";
		cin >> c;
		while (c > 3 || c < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> c;
		}
		if (c == 1)
		{
			retobject();
		}
		else if (c == 2)
		{
			system("cls");
			cout << "\tyou wanna shop from which store: " << endl;
			int p = 0;
			int s = 0;
		
			cout << "\t\t    1.Islamabad\n";
			cout << "\t\t    2.Karachi\n";
			cout << "\t\t    3.Peshawar\n";
			cout << "\t\t        select:";
			cin >> p;
			while (p > 3 || p < 1)
			{
				cout << "Invalid input. \n-->Please Enter valid input: ";
				cin >> p;
			}
			inventoryi shopi;
			inventorykhi shopk;
			inventoryp shopp;
			int h = 0;
			switch (p)
			{
			case 1:
				shopi.retrieve();
				cout << "\t\t    1.Search Specific Product\n";
				cout << "\t\t    2.Add To Cart\n";
				cout << "\t\t        select:";
				cin >> s;
				system("cls");
				while (s > 2 || s < 1)
				{
					cout << "Invalid input. \n-->Please Enter valid input: ";
					cin >> s;
				}
				switch (s)
				{
				case 1:
					shopi.retrieve();
					shopi.search();
					cin.get();
					cin.get();
					goto po;
					break;
				case 2:
					
					shopi.retrieve();
					shopi.addtocart();
					
			
					goto po;
					break;
				}
				break;
			case 2:
				shopk.retrieve();
				cout << "\t\t    1.Search Specific Product\n";
				cout << "\t\t    2.Add To Cart\n";
				cout << "\t\t        select:";
				cin >> s;
				system("cls");
				while (s > 2 || s < 1)
				{
					cout << "Invalid input. \n-->Please Enter valid input: ";
					cin >> s;
				}
				switch (s)
				{
				case 1:
					shopk.retrieve();
					shopk.search();
					cin.get();
					cin.get();
					goto po;
					break;
				case 2:
		
					shopk.retrieve();
					shopk.addtocart();

					goto po;
					break;
				}

				break;
			case 3:
				system("cls");
				shopp.retrieve();
				cout << "\t\t    1.Search Specific Product\n";
				cout << "\t\t    2.Add To Cart\n";
				cout << "\t\t        select:";
				cin >> s;
				system("cls");
				while (s > 2 || s < 1)
				{
					cout << "Invalid input. \n-->Please Enter valid input: ";
					cin >> s;
				}
				switch (s)
				{
				case 1:
					shopp.retrieve();
					shopp.search();
					cin.get();
					cin.get();
					goto po;
					break;
				case 2:

					shopp.retrieve();
					shopp.addtocart();

					goto po;
					break;
				}



				break;

			}

		}
		
		else
		{
			system("cls");
			usermenu();
		}
	}

	////////MANAGEERRRRRRRRRRRRRRRRRRRRRRRR WORRKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK


	void registermanager()
	{
		system("cls");

		cout << "Enter your name: ";
		cin >> mname;

		cout << "Enter your cnic: ";
		cin >> cnic;
		while (!(cnicCheck(cnic)))
		{
			cout << "Enter a valid 13-digit cnic number: ";
			cin >> cnic;
		}
		while (findornotm())
		{
			cout << "already registered cnic. enter a unique cnic: ";
			cin >> cnic;
		}

		cout << "Enter password: ";
		cin >> password;
		while (!(PasswordCheck(password)))
		{
			cout << "Enter a password with atleast 8 characters long, one uppercase and one special character: " << endl;
			cin >> password;
		}

		cout << "Reenter the password: ";
		string po;
		cin >> po;
		while (!(PasswordCheck(po)))
		{
			cout << "Enter a password with atleast 8 characters long, one uppercase and one special character: " << endl;
			cin >> po;
		}
		while (po != password)
		{
			cout << "passwords dont match, enter again :";
			cin >> po;
		}

		
		ofstream myFile("manager.bin", ios::binary | ios::app);
		myFile.write((char*)this, sizeof(*this));
		myFile.close();


		cout << "YOU ARE SUCCESSFULLY REGISTERED" << endl;


		loginmanager();


	}
	void loginmanager()
	{
			system("cls");
			cout << "Enter your credetials to login: ";
			while (!(findobjectm()))
			{
				cout << "wrong credentials entered. try again: " << endl;
				//findobjectm();
			}

			system("cls");
			char isbpass[] = "islamabad";
			char khipassword[] = "karachi";
			char pespassword[] = "peshawar";
			cout << "you are manager of which store: " << endl;
			int p = 0;

			cout << "\t\t    1.Islamabad\n";
			cout << "\t\t    2.Karachi\n";
			cout << "\t\t    3.Peshawar\n";
			cout << "\t\t        select:";
			cin >> p;
			while (p > 3 || p < 1)
			{
				cout << "Invalid input. \n-->Please Enter valid input: ";
				cin >> p;
			}

			int c = 0;
			int c8 = 0;
			inventoryi obj;
			inventorykhi objk;
			inventoryp objp;

			string x;
			//manager menu
			switch (p)
			{
			case 1:
				
				cout << "enter password of islamabad store: ";
				cin >> x;
				while (isbpass != x)
				{
					cout << "wrong password, try again: ";
					cin >> x;
				}

				
				system("cls");
			menu1:
				cout << "\t\t   WELCOME \n";

				cout << "\t\t    1.Add, remove or update from inventory\n";
				cout << "\t\t    2.Refill stock\n";
				cout << "\t\t    3.Show Inventories\n";
				cout << "\t\t    press 0 to log out\n";
				cout << "\t\t        select:";
				cin >> c;
				while (c > 3 || c < 0)
				{
					cout << "Invalid input. \n-->Please Enter valid input: ";
					cin >> c;
				}
				if (c == 1)
				{
					system("cls");
					obj.retrieve();
					cout << "\t\t    1.Add product\n";
					cout << "\t\t    2.Remove product\n";
					cout << "\t\t    3.Update product\n";
					cout << "\t\t        select:";
					cin >> c8;
					while (c8 > 3 || c8 < 1)
					{
						cout << "Invalid input. \n-->Please Enter valid input: ";
						cin >> c8;
					}
					switch (c8)
					{
					case 1:
						obj.setall();
						obj.writei();
						system("cls");
						goto menu1;
						break;
					case 2:
						obj.dele();
						system("cls");
						goto menu1;
						break;
					case 3:
						obj.updatein();
						system("cls");
						goto menu1;
						break;

					}
				}
				else if (c == 2)
				{
					obj.retrieve();
					obj.refil();
					system("cls");
					goto menu1;

				}
				else if (c == 3)
				{
					system("cls");
					cout << "\t\t    1.Islamabad Inventory\n";
					cout << "\t\t    2.Karachi Inventory\n";
					cout << "\t\t    3.Peshawar Inventory\n";
					cout << "\t\t        select:";
					cin >> c8;
					while (c8 > 3 || c8 < 1)
					{
						cout << "Invalid input. \n-->Please Enter valid input: ";
						cin >> c8;
					}
					switch (c8)
					{
					case 1:
						system("cls");
						obj.retrieve();
						obj.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;
					case 2:
						system("cls");
						objk.retrieve();
						objk.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;
					case 3:
						system("cls");
						objp.retrieve();
						objp.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;

					}



				}
				{
					system("cls");
					usermenu();
				}
				break;

			//karachi store
			case 2:
				cout << "enter password of karachi store: ";
				cin >> x;
				while (khipassword != x)
				{
					cout << "wrong password, try again: ";
					cin >> x;
				}

				
				system("cls");
			menu2:
				cout << "\t\t   WELCOME \n";

				cout << "\t\t    1.Add, remove or update from inventory\n";
				cout << "\t\t    2.Refill stock\n";
				cout << "\t\t    3.Show Inventories\n";
				cout << "\t\t    press 0 to log out\n";
				cout << "\t\t        select:";
				cin >> c;
				while (c > 3 || c< 0)
				{
					cout << "Invalid input. \n-->Please Enter valid input: ";
					cin >> c;
				}
				if (c == 1)
				{
					system("cls");
					objk.retrieve();
					cout << "\t\t    1.Add product\n";
					cout << "\t\t    2.Remove product\n";
					cout << "\t\t    3.Update product\n";
					cout << "\t\t        select:";
					cin >> c8;
					while (c8 > 3 || c8 < 1)
					{
						cout << "Invalid input. \n-->Please Enter valid input: ";
						cin >> c8;
					}
					switch (c8)
					{
					case 1:
						objk.setall();
						objk.writei();
						system("cls");
						goto menu2;
						break;
					case 2:
						objk.dele();
						system("cls");
						goto menu2;
						break;
					case 3:
						objk.updatein();
						system("cls");
						goto menu2;
						break;

					}
				}
				else if (c == 2)
				{
					objk.retrieve();
					objk.refil();
					system("cls");
					goto menu2;

				}
				else if (c == 3)
				{
					system("cls");
					cout << "\t\t    1.Islamabad Inventory\n";
					cout << "\t\t    2.Karachi Inventory\n";
					cout << "\t\t    3.Peshawar Inventory\n";
					cout << "\t\t        select:";
					cin >> c8;
					while (c8 > 3 || c8 < 1)
					{
						cout << "Invalid input. \n-->Please Enter valid input: ";
						cin >> c8;
					}
					switch (c8)
					{
					case 1:
						system("cls");
						obj.retrieve();
						obj.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;
					case 2:
						system("cls");
						objk.retrieve();
						objk.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;
					case 3:
						system("cls");
						objp.retrieve();
						objp.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;
					}
				

				}
				else
				{
					system("cls");
					usermenu();
				}
				break;
				//peshawar store
			case 3:
				cout << "enter password of peshawar store: ";
				cin >> x;
				while (pespassword != x)
				{
					cout << "wrong password, try again: ";
					cin >> x;
				}

				system("cls");
			menu3:
				cout << "\t\t   WELCOME \n";

				cout << "\t\t    1.Add, remove or update from inventory\n";
				cout << "\t\t    2.Refill stock\n";
				cout << "\t\t    3.Show Inventories\n";
				cout << "\t\t    press 0 to log out\n";
				cout << "\t\t        select:";
				cin >> c;
				while (c > 3 || c < 0)
				{
					cout << "Invalid input. \n-->Please Enter valid input: ";
					cin >> c;
				}
				if (c == 1)
				{
					system("cls");
					objp.retrieve();
					cout << "\t\t    1.Add product\n";
					cout << "\t\t    2.Remove product\n";
					cout << "\t\t    3.Update product\n";
					cout << "\t\t        select:";
					cin >> c8;
					while (c8 > 3 || c8 < 1)
					{
						cout << "Invalid input. \n-->Please Enter valid input: ";
						cin >> c8;
					}
					switch (c8)
					{
					case 1:
						objp.setall();
						objp.writei();
						system("cls");
						goto menu3;
						break;
					case 2:
						objp.dele();
						system("cls");
						goto menu3;
						break;
					case 3:
						objp.updatein();
						system("cls");
						goto menu3;
						break;

					}
				}
				else if (c == 2)
				{
					objp.retrieve();
					objp.refil();
					system("cls");
					goto menu3;

				}
				else if (c == 3)
				{
					system("cls");
					cout << "\t\t    1.Islamabad Inventory\n";
					cout << "\t\t    2.Karachi Inventory\n";
					cout << "\t\t    3.Peshawar Inventory\n";
					cout << "\t\t        select:";
					cin >> c8;
					while (c8 > 3 || c8 < 1)
					{
						cout << "Invalid input. \n-->Please Enter valid input: ";
						cin >> c8;
					}
					switch (c8)
					{
					case 1:
						system("cls");
						obj.retrieve();
						obj.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;
					case 2:
						system("cls");
						objk.retrieve();
						objk.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;
					case 3:
						system("cls");
						objp.retrieve();
						objp.search();
						cout << "enter anything to go to menu: ";
						cin.get();
						cin.get();
						system("cls");
						goto menu1;
						break;
					}
				}
				else
				{
					system("cls");
					usermenu();
				}
				break;

			}
	}


	///ADMIIIIIIIIIIINNNNNN WOOOOOOORRRRRRRRRRKKKKKKKKKKKKKKKKKK
	void loginadmin()
	{
		/*string x = "admin";
		setusername(x);
		setpassadmin(x);*/
		ofstream myFile("admin.bin", ios::binary | ios::app);
		myFile.write((char*)this, sizeof(*this));
		myFile.close();

			system("cls");
			cout << "Enter credentials to login as admin: ";

			while (!(findobjecta()))
			{
				cout << "wrong credentials entered. try again: " << endl;
				//findobjecta();
			}

			//admin menu
			menu:
			int c = 0;
			int c8=1;
			system("cls");
			cout << "\t\t   WELCOME \n";
			cout << "\t\t    1.Add or remove manager\n";
			cout << "\t\t    2.Add,update or delete items from catalog\n";
			cout << "\t\t    3.show all products\n";
			cout << "\t\t    4.Delete feedback\n" ;
			cout << "\t\t    press 0 to log out\n";
			cout << "\t\t        select:";
			cin >> c;
			while (c > 4 || c < 0)
			{
				cout << "Invalid input. \n-->Please Enter valid input: ";
				cin >> c;
			}
			if (c == 1)
			{
				cout << "\t\t    1.Add manager\n";
				cout << "\t\t    2.Remove manager\n";
				cout << "\t\t        select:";
				cin >> c8;
				while (c8 > 2 || c8 < 1)
				{
					cout << "Invalid input. \n-->Please Enter valid input: ";
					cin >> c8;
				}
				if (c8 == 1)
					registermanager();
				else
					deleteManager();
			}
			else if (c == 2)
			{
				cout << "\t\t    1.Add item\n";
				cout << "\t\t    2.Update item\n";
				cout << "\t\t    3.Delete item\n";
				cout << "\t\t        select:";
				cin >> c8;
				while (c8 > 3 || c8 < 1)
				{
					cout << "Invalid input. \n-->Please Enter valid input: ";
					cin >> c8;
				}
				if (c8 == 1)
				{
					system("cls");
					displaycatalog();
					goto menu;
				}
				if (c8 == 2)
				{
					int u1 = 0;
					system("cls");
					cout << "\t\t\t***** CHOOSE FROM THESE WHAT YOU WANT TO UPDATE *****\n";
					cout << "[1] Meet\n[2] Dairy\n[3] Fruit\n[4] Vegetables\n[5] Snacks\n[6] Spices\n[7] Grains\n[8] Cereals\n[9] Personal Hygiene\n[10] Household Cleaning\n---------------------------------------------------------------------------\n";
	
					cin >> u1;

					while (u1 > 10 || u1 < 0)
					{
						cout << "Invalid input. \n-->Please Enter valid input: ";
						cin >> u1;
					}
					switch (u1)
					{
					case 1:
						catalog::update(u1);
						goto menu; break;
					case 2:
						catalog::update(u1);
						goto menu; break;
					case 3:
						catalog::update(u1);
						goto menu; break;
					case 4:
						catalog::update(u1);
						goto menu; break;
					case 5:
						catalog::update(u1);
						goto menu; break;
					case 6:
						catalog::update(u1);
						goto menu; break;
					case 7:
						catalog::update(u1);
						goto menu; break;
					case 8:
						catalog::update(u1);
						goto menu; break;
					case 9:
						catalog::update(u1);
						goto menu; break;
					case 10:
						catalog::update(u1);
						goto menu; break;
					}

				}
				if (c8 == 3)
				{
					int u1 = 0;
					system("cls");
					cout << "\t\t\t***** CHOOSE FROM THESE WHAT YOU WANT TO DELETE *****\n";
					cout << "[1] Meet\n[2] Dairy\n[3] Fruit\n[4] Vegetables\n[5] Snacks\n[6] Spices\n[7] Grains\n[8] Cereals\n[9] Personal Hygiene\n[10] Household Cleaning\n---------------------------------------------------------------------------\n";

					cin >> u1;

					while (u1 > 10 || u1 < 0)
					{
						cout << "Invalid input. \n-->Please Enter valid input: ";
						cin >> u1;
					}
					switch (u1)
					{
					case 1:
						catalog::del(u1);
						goto menu; break;
					case 2:
						catalog::del(u1);
						goto menu; break;
					case 3:
						catalog::del(u1);
						goto menu; break;
					case 4:
						catalog::del(u1);
						goto menu; break;
					case 5:
						catalog::del(u1);
						goto menu; break;
					case 6:
						catalog::del(u1);
						goto menu; break;
					case 7:
						catalog::del(u1);
						goto menu; break;
					case 8:
						catalog::del(u1);
						goto menu; break;
					case 9:
						catalog::del(u1);
						goto menu; break;
					case 10:
						catalog::del(u1);
						goto menu; break;
					}


				}
					
			}

			else if (c == 3)
			{
				catalog::retrieve();
				cout << "press any key for admin menu:  ";
				cin.get();

				cin.get();
				goto menu;
			}
			else if (c == 4)
			{
			feedback pu;
			pu.read();
			bool yesorno = delfeedback();
			if (yesorno == 1)
			{
				cout << "SUCCESSFULLY DELETED\n";
				cout << "Press any key to go to menu: ";
				cin.get();
				cin.get();
				goto menu;
			}
			else
			{
				cout << "NOT FOUND";
				cout << "Press any key to go to menu: ";
				cin.get();
				cin.get();
				goto menu;

			}

			}
			else 
			{
				system("cls");
				usermenu();
			}

	}



	// HELPING FUNCS FOR CUSTOMERRR

	bool findobject()
	{
		string x, y;
		cout << endl;
		cout << "cnic: ";
		cin >> x;
		cout << endl;
		cout << "password: ";
		cin >> y;
		bool check = false;

		user temp, temp2;
		temp2.setcnic(x);
		temp2.setpassword(y);

		ifstream myFile("customer.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (strcmp(temp.getcnic(), temp2.getcnic()) == 0)
			{
				if (strcmp(temp.getpassword(), temp2.getpassword()) == 0)
				{
					return 1;
					myFile.close();
				}
			}
		}
		return 0;

	}



	bool retobject()
	{
		string x, y;
		cout << endl;
		cout << "cnic: ";
		cin >> x;
		cout << endl;
		user temp, temp2;
		temp2.setcnic(x);

		ifstream myFile("customer.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (strcmp(temp.getcnic(), temp2.getcnic()) == 0)
			{
				temp.display();
				return 1;
			}
		}
		return 0;

	}


	bool findornot()
	{
		user temp;
		ifstream myFile("customer.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (strcmp(temp.getcnic(), this->getcnic()) == 0)
			{
				return 1;
			}
		}
		return 0;

	}
	///HELPINGGG FUNCTIONSSS FOR MANAGERRRR
	bool findornotm()
	{
		user temp;
		ifstream myFile("manager.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (strcmp(temp.getcnic(), this->getcnic()) == 0)
			{
				return 1;
			}
		}
		return 0;

	}

	bool findobjectm()
	{
		string x, y;
		cout << endl;
		cout << "cnic: ";
		cin >> x;
		cout << endl;
		cout << "password: ";
		cin >> y;
		bool check = false;

		user temp, temp2;
		temp2.setcnic(x);
		temp2.setpassword(y);

		ifstream myFile("manager.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (strcmp(temp.getcnic(), temp2.getcnic()) == 0)
			{
				if (strcmp(temp.getpassword(), temp2.getpassword()) == 0)
				{
					return 1;
					myFile.close();
				}
			}
		}
		return 0;

	}


	///ADMINNNN LOGIN CHECKING
	bool findobjecta()
	{
		

		string x, y;
		cout << endl;
		cout << "username: ";
		cin >> x;
		cout << endl;
		cout << "password: ";
		cin >> y;

		user temp, temp2;
		temp2.setusername(x);
		temp2.setpassadmin(y);

		ifstream myFile("admin.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (strcmp(temp.getusername(), temp2.getusername()) == 0)
			{
				if (strcmp(temp.getpassadmin(), temp2.getpassadmin()) == 0)
				{
					return 1;
					myFile.close();
				}
			}
		}
		return 0;

	}


	bool delfeedback()
	{
		bool check = 0;
		string x;
		cout << "enter person whose feedback you want to delete: ";
		cin >> x;
			feedback temp,temp2;
			temp2.setname(x);
			fstream myFile("feedback.bin", ios::in | ios::out | ios::binary);
			ofstream myFile_temp("feedback.bin" , ios::app | ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getname() != temp2.getname()) 
				{
					myFile_temp.write((char*)&temp, sizeof(temp));
					check = 1;
				}
			}
			myFile.close();
			myFile_temp.close();
			remove("feedback.bin");
			rename("temp.bin", "feedback.bin");
			if (check == 0)
				return 0;
			else
				return 1;
	}

	void deleteManager() {
		string x, y;
		cout << endl;
		cout << "cnic: ";
		cin >> x;
		cout << endl;
		user temp, temp2;
		temp2.setcnic(x);

		fstream myFile("manager.bin", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getcnic() != temp2.getcnic()) {
				myFile_temp.write((char*)this, sizeof(temp));
			}
		}
		myFile.close();
		myFile_temp.close();
		remove("manager.bin");
		rename("temp.bin", "manager.bin");
	}



};



	
