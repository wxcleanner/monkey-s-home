#include"workmanager.h"
workmanager::workmanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在!" << endl;
		this->empnum = 0;
		this->emparray = NULL;
		this->fileisempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空!" << endl;
		this->empnum = 0;
		this->emparray = NULL;
		this->fileisempty = true;
		ifs.close();
		return;
	}
}
void workmanager::showmenu()
{
		cout << "**********************************" << endl;
		cout << "********欢迎使用隐私管理系统******" << endl;
		cout << "*********0，退出管理系统**********" << endl;
		cout << "*********1，增加隐私信息**********" << endl;
		cout << "*********2，显示隐私信息**********" << endl;
	    cout << "*********3，删除隐私信息**********" << endl;
		cout << "*********4，修改隐私信息**********" << endl;
		cout << "*********5，查找隐私信息**********" << endl;
		cout << "*********6，清空所有文档**********" << endl;
		cout << "**********************************" << endl;
}
void workmanager::exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workmanager::addemp()
{
	cout << "请输入添加的数量" << endl;
	int addnum = 0;
	cin >> addnum;                         
	if (addnum > 0)
	{
		int newsize = this->empnum + addnum;
		worker**newspace=new worker* [newsize];
		if (this->emparray != NULL)
		{
			for (int i = 0; i < this->empnum; i++)
			{
				newspace[i] = this->emparray[i];
			}
		}
			for (int i = 0; i < addnum; i++)
			{
				int id;
				string name;
				string location;
				cout << "请输入第" << i + 1 << "个新隐私编号" << endl;
				cin >> id;
				cout << "请输入第" << i + 1 << "位置信息" << endl;
				cin >> location;
				cout << "请描述账号" << endl;
				string description;
				cin >> description;
				cout << "输入账号名" << endl;
				cin >> name;
				cout << "请输入密码" << endl;
				int secret;
				cin >> secret;
				worker* worker = NULL;
				worker = new employee(id, location, description, name, secret);
				newspace[this->empnum + i] = worker;
			}
			delete[] this->emparray;
			this->emparray = newspace;
			this->empnum = newsize;
			this->fileisempty = false;
			cout << "成功添加" << addnum << "个隐私" << endl;
			this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void workmanager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->empnum; i++)
	{
		ofs << this->emparray[i]->id << " "
			<<this->emparray[i]->location<<" "
			<<this->emparray[i]->descrption<<" "
			<< this->emparray[i]->name << " "
			<< this->emparray[i]->secret<< endl;
	}
	ofs.close();
}
int workmanager::getempnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string location;
	string description;
	string name;
	int secret;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> secret&&ifs>>location&&ifs>>description)
	{
		num++;
	}
	return num;
}
void workmanager::initemp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string location;
	string description;
	string name;
	int secret;
	int index = 0;
	ifs.close();
}
void workmanager::showemp()
{
	if (this->fileisempty)
		cout <<  "文件为空或着不存在" << endl;
	else
	{
		for (int i = 0; i < empnum; i++)
		{
			this->emparray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
	workmanager::~workmanager()
{
	if (this->emparray != NULL)
	{
		delete[] this->emparray;
		this->emparray = NULL;
	}
}

	void workmanager::delemp()
	{
		if (this->fileisempty)
		{
			cout << "文件不存在或者文件为空" << endl;
		}
		else
		{
			cout << "请输入想要删除的编号" << endl;
			int id = 0;
			cin >> id;
			int index = this->isexist(id);
			if (index != -1)
			{
				for (int i = index; i < this->empnum - 1; i++)
				{
					this->emparray[i] = this->emparray[i + 1];
				}
			this->empnum--;
			this->save();
			cout << "删除成功!" << endl;
			}
			else
			{
				cout << "删除失败，未找到该员工" << endl;
			}
		 }
		system("pause");
		system("cls");
	 }
	int workmanager::isexist(int id)
	{
		int index = -1;
		for (int i = 0; i < this->empnum; i++)
		{
			if (this->emparray[i]->id == id)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	void workmanager::modemp()
	{
		if (this->fileisempty)
		{
			cout << "文件不存在或者记录为空" << endl;
		}
		else
		{
			cout<<"请输入职工的编号" << endl;
			int id;
			cin >> id;
			int ret = this->isexist(id);
			if (ret != -1)
			{
				delete this->emparray[ret];
				int newid = 0;
				string newlocation;
				int dselect = 0;
				cout << "查到：" << id << "号职工，请输入新：" << endl;
				cin >> newid;
				cout << "请输入地址" << endl;
				cin >> newlocation;
				string newdescription;
				cout << "请输入解释" << endl;
				cin >> newdescription;
				cin >> dselect;
				string newname;
				cout << "请输入新的名字" << endl;
				cin >> newname;
				int newsecret;
				cin >> newsecret;
				worker* worker = NULL;
				this->emparray[ret] = worker;
				cout << "修改成功" << endl;
				this->save();
			} 
			else
			{
				cout << "修改失败，查无此人" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void workmanager::findemp()
	{
		if (this->fileisempty)
		{
			cout << "文件不存在或者记录为空" << endl;
		}
		else
		{
			cout << "请输入查找方式:" << endl;
			cout << "按照职工姓名查找" << endl;
			
				string name;
				cout << "输入查找的姓名" << endl;
				cin >> name;
				bool flag;
				for (int i = 0; i < empnum; i++)
				{
					if (this->emparray[i]->name == name)
					{
						cout << "查找成功，职工编号为" <<
							this->emparray[i]->id << "号职工信息如下" << endl;
						flag = true;
						this->emparray[i]->showinfo();
					}
				}
				if (flag = false)
				{
					cout << "查找失败查无此人" << endl;
				}
			else
			{
				cout << "输入有误" << endl;
			}
		}
		system("pause");
		system("cls");
    }
	void workmanager::cleanfile()
	{
		cout << "确认清空？" << endl;
		cout << "1、确认" << endl;
		cout << "2、返回" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
			if (this->emparray != NULL)
			{
				for (int i = 0; i <this->empnum; i++)
				{
					delete this->emparray[i];
					this->emparray[i] = NULL;
				}
					delete[] this->emparray;
					this->emparray = NULL;
					this->empnum = 0;
					this->fileisempty = true;
				}
				cout << "清空成功！" << endl;
			}
			system("pause");
			system("cls");
		}
	