#include<iostream>
#include<string>
#include"Customer.h"
using namespace std;


Customer::Customer():bonus(0.0) {}
void Customer::sendBill() 
{
	cout<<"----------------------------------------------------------"<<endl;
	cout<<"dear "<<getName()<<endl;
	cout<<"your bill is sending from us to "<<getEmail()<<endl;
	cout<<"----------------------------------------------------------"<<endl;
}
long Customer::getCustomerID() { return customerID; }
void Customer::setCustomerID(long _customerID) { customerID=_customerID; }
string Customer::getName() { return name; }
void Customer::setName(string _name) { name=_name; }
string Customer::getAdress() { return address; }
void Customer::setAdress(string _address) { address=_address; }
string Customer::getPhone() { return phone; }
void Customer::setPhone(string _phone) { phone=_phone; }
double Customer::getBonus() { return bonus; }
string Customer::getEmail() {return email; }
void Customer::setEmail(string _email) { email=_email; }
string Customer::getUsername(){ return username; }
void Customer::setUsername(string _username) { username=_username; }
string Customer::getPassword() { return password; }
void Customer::setPassword(string _password) { password=_password; }
bool Customer::checkAccount(string _username,string _password,ShoppingCart *temp)
{
	Customer *tmp=new Customer();
	list<Customer>::iterator iter;

	for(iter=temp->_customer.begin(); iter!=temp->_customer.end(); iter++)
	{

		if(iter->getUsername()==_username && iter->getPassword()==_password)
		{
			*tmp=*iter;
			temp->setCustomer(tmp);
			return true;
		}

	}
	return false;

}
void Customer::addBonus(double _bonus) { bonus+=_bonus; }
void Customer::useBonus(ShoppingCart *s){ bonus=bonus-s->getBill(); } // bonus yetiyorsa satýn alabilsin, yetmiyorsa alamasýn menuye dönsün
