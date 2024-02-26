#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
class employee :public worker
{
public:
	employee(int id,string location,string description,string name,int secret);
	virtual void showinfo();
};
