#pragma once
#include "..//myproj/user.h"
#include "..//myproj/independentfuncs.h"

class customer
{
protected:
	char g;
	char pn[20];
	char address[80];
	char city[50];
public:
	customer()
	{
		city[0] = '\0';
		g = ' ';
		pn[0] = '\0';
		address[0] = '\0';
	}




};