#include<iostream>
using namespace std;
#include "workmanager.h"
#include"worker.h"
#include"employee.h"

int main()
{
	workmanager wm;
	int choice;
	cout << "���������ѡ��" << endl;
	;
	while (true)
	{
		wm.showmenu();
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitsystem();//�˳�ϵͳ
			break;
		case 1:
			wm.addemp();
			break;
		case 2:
			wm.showemp();
			break;
		case 3:
			wm.delemp();
			break;
		case 4:
			wm.modemp();
			break;
		case 5:
			wm.findemp();
			break;
		case 7:
			wm.cleanfile();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}