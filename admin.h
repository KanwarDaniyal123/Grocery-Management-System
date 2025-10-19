#pragma once
#include "..//myproj/productcatalog.h"

class admin : public catalog
{
protected:
	char useradmin[6]="admin";
	char passadmin[6]="admin";
public:

	void setusername(string s)
	{
		strcpy_s(useradmin, s.length() + 1, s.c_str());
	}
	char* getusername()
	{
		return useradmin;
	}
	void setpassadmin(string s)
	{
		strcpy_s(passadmin, s.length() + 1, s.c_str());
	}
	char* getpassadmin()
	{
		return passadmin;
	}

};