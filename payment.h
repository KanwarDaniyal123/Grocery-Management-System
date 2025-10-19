#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class payment
{
protected:
	int balance = 20000;
	char acc[100];
public:
	virtual void input()
	{

	}

};

class easypaisa: public payment
{
protected:
	char epnumber[20];
public:
	easypaisa()
	{
		acc[0] = '\0';
		epnumber[0] = 0;
	}

	virtual void input()
	{
		cout << "enter easy paisa number: ";
		cin >> acc;
	}
};

class jazzcash: public payment
{
public:
	jazzcash()
	{
		acc[0] = '\0';
	}
	virtual void input()
	{

		cout << "enter jazzcash number: ";
		cin >> acc;
	}

};

class cod :public payment
{
protected:
	char address[100];
	char city[50];
	
public:
	cod()
	{
		acc[0] = '\0';
		address[0] = '\0';
		city[0] = '\0';
	}

	virtual void input()
	{
		cout << "enter card no: ";
		cin >> acc;
		cout << "enter your city: ";
		cin >> city;
		cout << "enter address: ";
		cin >> address;
	}
};

class debit: public payment
{
protected:
	
public:
	debit()
	{
		acc[0] = '\0';
	}
	virtual void input()
	{
		cout << "enter card number: ";
		cin >> acc;
	}

};

