#pragma once
#include <iostream>
using namespace std;
class vegetables
{
protected:
	char vegname[100];
	int vegprice;
public:
	vegetables()
	{
		vegname[0] = '\0';
		vegprice = 0;
	}

	void setvegname(string x)
	{
		strcpy_s(vegname, x.length() + 1, x.c_str());
	}

	char* getvegname()
	{
		return vegname;
	}

	void setvegprice(int n)
	{
		vegprice = n;
	}

	int getvegprice()
	{
		return vegprice;
	}

	void displayveg()
	{
		cout << "\t\t\t***** VEGETABLE SHOP *****\n";
		cout << "[1] Tomato\n[2] Onion\n[3] Cucumber\n[4] Potatoes\n---------------------------------------------------------------------------\n";
		int n1 = 0;
		cin >> n1;

		while (n1 > 4 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			setvegname("tomato");
			setvegprice(20);
			break;
		case 2:
			setvegname("onion");
			setvegprice(30);
			break;
		case 3:
			setvegname("cucumber"); 
			setvegprice(25);
			break;
		case 4:
			setvegname("potatoes"); 
			setvegprice(40);
			break;
		}
	}
};




class fruit

{
protected:
	char fruitname[100];
	int fruitprice;
public:
	fruit()
	{
		fruitname[0] = '\0';
		fruitprice = 0;
	}

	void setfruitname(string x)
	{
		strcpy_s(fruitname, x.length() + 1, x.c_str());
	}

	char* getfruitname()
	{
		return fruitname;
	}

	void setfruitprice(int n)
	{
		fruitprice = n;
	}

	int getfruitprice()
	{
		return fruitprice;
	}

	void displayfruit()
	{
		cout << "\t\t\t***** FRUIT SHOP *****\n";
		cout << "[1] Apple\n[2] Banana\n[3] Mango\n[4] Orange\n[5] Watermelon\n---------------------------------------------------------------------------\n";
		int n1 = 0;
		cin >> n1;

		while (n1 > 5 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			setfruitname("apple");
			setfruitprice(160);
			break;
		case 2:
			setfruitname("banana"); 
			setfruitprice(100);
			break;
		case 3:
			setfruitname("mango"); 
			setfruitprice(130);
			break;
		case 4:
			setfruitname("orange"); 
			
			setfruitprice(180);
			break;
		case 5:
			setfruitname("watermelon"); 
			setfruitprice(300);
			break;
		}
	}
};




class dairy
{
protected:
	char dairyname[100];
	int dairyprice ;
public:
	dairy()
	{
		dairyname[0] = '\0';
		dairyprice = 0;
	}

	void setdairyname(string x)
	{
		strcpy_s(dairyname, x.length() + 1, x.c_str());
	}

	char* getdairyname()
	{
		return dairyname;
	}

	void setdairyprice(int n)
	{
		dairyprice = n;
	}

	int getdairyprice()
	{
		return dairyprice;
	}

	void displaydairy()
	{
		cout << "\t\t\t***** DAIRY SHOP *****\n";
		cout << "[1] Milk\n[2] Eggs\n[3] Yogurt\n[4] Cheese\n---------------------------------------------------------------------------\n";
		int n1 = 0;
		cin >> n1;

		while (n1 > 4 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			setdairyname("milk");
			setdairyprice(180);
			break;
		case 2:
			setdairyname("eggs");
			setdairyprice(150);
			break;
		case 3:
			setdairyname("yogurt"); 
			setdairyprice(130);
			break;
		case 4:
			setdairyname("cheese"); 
			setdairyprice(250);
			break;
		}
	}
};



class meat
{
protected:
	char meatname[100];
	int meatprice;
public:
	meat()
	{
		meatname[0] = '\0';
		meatprice = 0;
	}

	void setmeatname(string x)
	{
		strcpy_s(meatname, x.length() + 1, x.c_str());
	}

	char* getmeatname()
	{
		return meatname;
	}

	void setmeatprice(int n)
	{
		meatprice = n;
	}

	int getmeatprice()
	{
		return meatprice;
	}

	void displaymeat()
	{
		cout << "\t\t\t***** MEAT SHOP *****\n";
		cout << "[1] Chicken\n[2] Beef\n[3] Mutton\n[4] Fish\n---------------------------------------------------------------------------\n";
		int n1 = 0;
		cin >> n1;

		while (n1 > 4 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			setmeatname("chicken");
			setmeatprice(300);
			break;
		case 2:
			setmeatname("beef"); 
			setmeatprice(600);
			break;
		case 3:
			setmeatname("mutton"); 
			setmeatprice(1000); break;
		case 4:
			setmeatname("fish");
			setmeatprice(800); break;
		}
	}
};


///////NONPERISHABLE STARTING---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

class snacks
{
protected:
	char snackname[100];
	int snackprice;
public:
	snacks()
	{
		snackname[0] = '\0';
		snackprice =0;
	}

	void setsnackname(string x)
	{
		strcpy_s(snackname, x.length() + 1, x.c_str());
	}

	char* getsnackname()
	{
		return snackname;
	}

	void setsnackprice(int n)
	{
		snackprice = n;
	}

	int getsnackprice()
	{
		return snackprice;
	}

	void displaysnacks()
	{
		cout << "\t\t\t***** SNACKS SHOP *****\n";
		cout << "[1] Chocolates\n[2] Chips\n[3] Biscuits\n---------------------------------------------------------------------------\n";
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
			setsnackname("chocolates");
			setsnackprice(500);
			break;
		case 2:
			setsnackname("chips");
			setsnackprice(50);
			break;
		case 3:
			setsnackname("biscuits"); 
			setsnackprice(80);
			break;
		}
	}
};

class spices
{
protected:
	char spicename[100];
	int spiceprice;
public:
	spices()
	{
		spicename[0] = '\0';
		spiceprice = 0;
	}

	void setspicename(string x)
	{
		strcpy_s(spicename, x.length() + 1, x.c_str());
	}

	char* getspicename()
	{
		return spicename;
	}

	void setspiceprice(int n)
	{
		spiceprice = n;
	}

	int getspiceprice()
	{
		return spiceprice;
	}

	void displayspices()
	{
		cout << "\t\t\t***** SPICES SHOP *****\n";
		cout << "[1] Black Salt\n[2] Black Pepper\n[3] Red Pepper\n---------------------------------------------------------------------------\n";
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
			setspicename("black_salt");
			setspiceprice(85);
			break;
		case 2:
			setspicename("black_pepper"); 
			setspiceprice(70);
			break;
		case 3:
			setspicename("red_pepper");
			setspiceprice(40); 
			break;
		}
	}
};


class grains
{
protected:
	char gnname[100];
	int grainprice;
public:
	grains()
	{
		gnname[0] = '\0';
		grainprice = 0;
	}

	void setgrainname(string x)
	{
		strcpy_s(gnname, x.length() + 1, x.c_str());
	}

	char* getgrainname()
	{
		return gnname;
	}

	void setgrainprice(int n)
	{
		grainprice = n;
	}

	int getgrainprice()
	{
		return grainprice;
	}

	void displaygrains()
	{
		cout << "\t\t\t***** GRAINS SHOP *****\n";
		cout << "[1] Lentils\n[2] Wheat\n[3] Flour\n[4] Rice\n---------------------------------------------------------------------------\n";
		int n1 = 0;
		cin >> n1;

		while (n1 > 4 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			setgrainname("lentils");
			setgrainprice(70);
			break;
		case 2:
			setgrainname("wheat");
			setgrainprice(100);
			break;
		case 3:
			setgrainname("flour");
			setgrainprice(150); 
			break;
		case 4:
			setgrainname("rice"); 
			setgrainprice(180); 
			break;
		}
	}
};


class cereal
{
protected:
	char cername[100];
	int cerprice;
public:
	cereal()
	{
		cername[0] = '\0';
		cerprice = 0;
	}

	void setcername(string x)
	{
		strcpy_s(cername, x.length() + 1, x.c_str());
	}

	char* getcername()
	{
		return cername;
	}

	void setcerprice(int n)
	{
		cerprice = n;
	}

	int getcerprice()
	{
		return cerprice;
	}

	void displaycereal()
	{
		cout << "\t\t\t***** CEREALS SHOP *****\n";
		cout << "[1] Corn flakes\n[2] Coco Krunch\n[3] Barley\n[4] Custard Powder\n---------------------------------------------------------------------------\n";
		int n1 = 0;
		cin >> n1;

		while (n1 > 4 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			setcername("corn_flakes");
			setcerprice(280);
			break;
		case 2:
			setcername("koko_crunch"); 
			setcerprice(170); 
			break;
		case 3:
			setcername("barley");
			setcerprice(130); 
			break;
		case 4:
			setcername("custard_powder"); 
			setcerprice(280); 
			break;

		}
	}
};




class nonperishable : public snacks, public spices, public grains, public cereal
{
public:
	void displaynonperishable()
	{
		int n1 = 0;
		cout << "\t\t\t***** NON PERISHABLE GOODS *****\n";
		cout << "[1] Snacks\n[2] Spices\n[3] Grains\n[4] Cereal\n---------------------------------------------------------------------------\n";
		cin >> n1;

		while (n1 > 4 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			system("cls");
			displaysnacks();
			break;
		case 2:
			system("cls");
			displayspices();
			break;
		case 3:
			system("cls");
			displaygrains();
			break;
		case 4:
			system("cls");
			displaycereal();
			break;
		}
	}
};



class perishable : public meat, public dairy, public fruit, public vegetables
{
public:
	void displayperishable()
	{
		int n1 = 0;
		cout << "\t\t\t***** PERISHABLE GOODS *****\n";
		cout << "[1] Meat\n[2] Dairy\n[3] Fruit\n[4] Vegetable\n---------------------------------------------------------------------------\n";
		cin >> n1;

		while (n1 > 4 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			system("cls");
			displaymeat();
			break;
		case 2:
			system("cls");
			displaydairy();
			break;
		case 3:
			system("cls");
			displayfruit();
			break;
		case 4:
			system("cls");
			displayveg();
			break;
		}
	}
};



class food :public perishable, public nonperishable
{
public:
	void displayfoods()
	{
		int n1 = 0;
		cout << "\t\t\t***** FOOD SHOP *****\n";
		cout << "[1]Perishable goods \n[2]Non-Perishable goods\n---------------------------------------------------------------------------\n";
		cin >> n1;

		while (n1 > 2 || n1 < 0)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}

		switch (n1)
		{
		case 1:
			system("cls");
			displayperishable();
			break;
		case 2:
			system("cls");
			displaynonperishable();
			break;


		}
	}
};




