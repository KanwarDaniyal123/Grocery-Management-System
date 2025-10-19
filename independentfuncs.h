#pragma once
#include "..//myproj/user.h"
#include <iostream>
#include <string>
using namespace std;



bool cnicCheck(string n)
{
	if (n.size() != 13)
		return false;
	for (int i = 0; i < 13; i++)
	{
		if (n[i] < '0' || n[i] > '9')
			return false;
	}
	return true;
}
char* stringtochar(string n)
{
	int size = n.size();
	char* ptr = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = n[i];
	}
	ptr[size] = '\0';
	return ptr;
}

bool PasswordCheck(string n)
{
	bool fu = false, fl = false, fn = false, fs = false;
	if (n.size() < 8)
		return false;
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] >= 'A' && n[i] <= 'Z')
			fu = true;
		else if (n[i] >= 'a' && n[i] <= 'z')
			fl = true;
		else if (n[i] >= '0' && n[i] <= '9')
			fn = true;
		else
			fs = true;
	}
	if (fu && fl && fs && fn)
		return true;
	return false;
}
void stringcpy(char*& dest, char* source)
{

	int size = strlen(source);
	dest = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		dest[i] = source[i];
	}
	dest[size] = '\0';
}

//
//void retrieveObject(int rollNumber) {
//	Student temp;
//	ifstream myFile("test.bin", ios::binary);
//
//	while (myFile.read((char*)&temp, sizeof(temp))) {
//		if (temp.getRollNumber() == rollNumber) {
//			temp.display();
//			myFile.close();
//		}
//	}
//}
//
//void retrieveall() {
//	Student temp;
//	ifstream myFile("test.bin", ios::binary);
//
//	while (myFile.read((char*)&temp, sizeof(temp))) {
//
//		temp.display();
//
//	}
//	myFile.close();
//}
//
//

/*while (!(arr1 == cnic && arr2 == password))
		{
			cout << "wrong credentials. enter again" << endl;
			cout << "cnic: ";
			cin >> arr1;
			cout << "password: ";
			cin >> arr2;

		}*/
//void deleteObject(int rollNumber) {
//	Student temp;
//	fstream myFile(fileName, ios::in | ios::out | ios::binary);
//	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
//	while (myFile.read((char*)& temp, sizeof(temp))) {
//		if (temp.getRollNumber() != rollNumber) {
//			myFile_temp.write((char*) temp, sizeof(temp));
//		}
//	}
//	myFile.close();
//	myFile_temp.close();
//	remove(fileName);
//	rename( "temp.bin", fileName);
//}