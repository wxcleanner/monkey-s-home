#include"employee.h"
employee::employee(int id,string location,string description,string name,int secret)
{
	this->id = id;
	this->name = name;
	this->secret= secret;
	this->location = location;
	this->descrption = description;

}
void employee::showinfo()
{
	cout << "��ţ�" << this->id
		<< "\t�˺�λ�ã�" << this->location
		<< "\t�˺�������" << this->descrption
		<< "\t�˺���"<<this->name<<"����"<<this->secret << endl;
}