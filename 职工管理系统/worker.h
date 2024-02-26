#pragma once
#include<iostream>
using namespace std;
#include<string.h>
class worker
{
public:
	virtual void showinfo() = 0;
	//virtual string getdeptname() = 0;
	int id;
	string location;
	string descrption;
	string name;
	int secret;
};