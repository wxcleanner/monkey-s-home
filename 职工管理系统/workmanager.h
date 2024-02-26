#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empfile.txt"
class workmanager
{
public:
	workmanager();
	void showmenu();
	void exitsystem();
	int empnum;
	worker** emparray;
	void addemp();
	void save();
	~workmanager();
	bool fileisempty;
	int getempnum();
	void initemp();
	void showemp();
	void delemp();
int isexist(int id);
void modemp();
void findemp();
void sortemp();
void cleanfile();
};
