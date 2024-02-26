#include"workmanager.h"
workmanager::workmanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������!" << endl;
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
		//cout << "�ļ�Ϊ��!" << endl;
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
		cout << "********��ӭʹ����˽����ϵͳ******" << endl;
		cout << "*********0���˳�����ϵͳ**********" << endl;
		cout << "*********1��������˽��Ϣ**********" << endl;
		cout << "*********2����ʾ��˽��Ϣ**********" << endl;
	    cout << "*********3��ɾ����˽��Ϣ**********" << endl;
		cout << "*********4���޸���˽��Ϣ**********" << endl;
		cout << "*********5��������˽��Ϣ**********" << endl;
		cout << "*********6����������ĵ�**********" << endl;
		cout << "**********************************" << endl;
}
void workmanager::exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workmanager::addemp()
{
	cout << "��������ӵ�����" << endl;
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
				cout << "�������" << i + 1 << "������˽���" << endl;
				cin >> id;
				cout << "�������" << i + 1 << "λ����Ϣ" << endl;
				cin >> location;
				cout << "�������˺�" << endl;
				string description;
				cin >> description;
				cout << "�����˺���" << endl;
				cin >> name;
				cout << "����������" << endl;
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
			cout << "�ɹ����" << addnum << "����˽" << endl;
			this->save();
	}
	else
	{
		cout << "��������" << endl;
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
		cout <<  "�ļ�Ϊ�ջ��Ų�����" << endl;
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
			cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
		}
		else
		{
			cout << "��������Ҫɾ���ı��" << endl;
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
			cout << "ɾ���ɹ�!" << endl;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
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
			cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		}
		else
		{
			cout<<"������ְ���ı��" << endl;
			int id;
			cin >> id;
			int ret = this->isexist(id);
			if (ret != -1)
			{
				delete this->emparray[ret];
				int newid = 0;
				string newlocation;
				int dselect = 0;
				cout << "�鵽��" << id << "��ְ�����������£�" << endl;
				cin >> newid;
				cout << "�������ַ" << endl;
				cin >> newlocation;
				string newdescription;
				cout << "���������" << endl;
				cin >> newdescription;
				cin >> dselect;
				string newname;
				cout << "�������µ�����" << endl;
				cin >> newname;
				int newsecret;
				cin >> newsecret;
				worker* worker = NULL;
				this->emparray[ret] = worker;
				cout << "�޸ĳɹ�" << endl;
				this->save();
			} 
			else
			{
				cout << "�޸�ʧ�ܣ����޴���" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void workmanager::findemp()
	{
		if (this->fileisempty)
		{
			cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		}
		else
		{
			cout << "��������ҷ�ʽ:" << endl;
			cout << "����ְ����������" << endl;
			
				string name;
				cout << "������ҵ�����" << endl;
				cin >> name;
				bool flag;
				for (int i = 0; i < empnum; i++)
				{
					if (this->emparray[i]->name == name)
					{
						cout << "���ҳɹ���ְ�����Ϊ" <<
							this->emparray[i]->id << "��ְ����Ϣ����" << endl;
						flag = true;
						this->emparray[i]->showinfo();
					}
				}
				if (flag = false)
				{
					cout << "����ʧ�ܲ��޴���" << endl;
				}
			else
			{
				cout << "��������" << endl;
			}
		}
		system("pause");
		system("cls");
    }
	void workmanager::cleanfile()
	{
		cout << "ȷ����գ�" << endl;
		cout << "1��ȷ��" << endl;
		cout << "2������" << endl;
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
				cout << "��ճɹ���" << endl;
			}
			system("pause");
			system("cls");
		}
	