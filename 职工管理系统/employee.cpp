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
	cout << "±àºÅ£º" << this->id
		<< "\tÕËºÅÎ»ÖÃ£º" << this->location
		<< "\tÕËºÅÃèÊö£º" << this->descrption
		<< "\tÕËºÅÃû"<<this->name<<"ÃÜÂë"<<this->secret << endl;
}