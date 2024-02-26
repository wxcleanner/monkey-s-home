#include<iostream>
using namespace std;
#include "workmanager.h"
#include"worker.h"
#include"employee.h"
int main()
{
	workmanager wm;
	int choice;
	cout << "请输入你的选择" << endl;
	;
	while (true)
	{ 
		wm.showmenu();
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitsystem();//退出系统
			break;
		case 1:
			wm.addemp();
			break;
		case 2:
			wm.showemp();
			break;
		case 3:
			wm.delemp();//删除
			break;
		case 4:
			wm.modemp();//修改
			break;
		case 5:
			wm.findemp();//查找
			break;
		case 6:
			wm.cleanfile();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}