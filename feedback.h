#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class feedback
{
protected:
	int total;
	char nm[30];
	char f[200];
public:
	feedback()
	{
		total = 0;
		nm[0] = '\0';
		f[0] = '\0';
	}

	void setname(string x)
	{
		strcpy_s(nm, x.length() + 1, x.c_str());
	}

	void setfeedback(string x)
	{
		strcpy_s(nm, x.length() + 1, x.c_str());
	}

	char* getname()
	{
		return nm;
	}

	char* getfeedback()
	{
		return f;
	}

	void inc()
	{
		total++;
	}

	void read()
	{
		feedback temp;
		ifstream myFile("feedback.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			cout << endl;
			cout << temp.getname();
			cout << endl;
			cout << temp.getfeedback();
		}

		myFile.close();
	}
	void write()
	{
		ofstream myFile("feedback.bin", ios::binary | ios::app);
		myFile.write((char*)this, sizeof(*this));
		myFile.close();
	}

};
