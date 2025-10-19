#pragma once
#include "..//myproj/inventoryisb.h"
#include "..//myproj/inventorykhi.h"
#include "..//myproj/inventoryp.h"
#include <iostream>
#include <fstream>
using namespace std;

class cart: public inventoryi, public inventorykhi, public inventoryp
{
protected:
	int quan;
public:
	cart()
	{
		quan = 0;
	}


};