#include"Payment.h"
#include<iostream>
#include<string>
using namespace std;

double Payment::getAmount() { return amount; }
void Payment::setAmount(double _amount) { amount=_amount; } 
Payment::Payment(){ }

CreditCard::CreditCard(long _number,string _type,string _expDate,double _amount)
{
	setNumber(_number);
	setType(_type);
	setExpDate(_expDate);
	setAmount(_amount);
}

long CreditCard::getNumber() { return number; }
void CreditCard::setNumber(long _number) {number=_number; }
string CreditCard::getType() { return type; }
void CreditCard::setType(string _type) { type=_type; }
string CreditCard::getExpDate() { return expDate; }
void CreditCard::setExpDate(string _expDate) { expDate=_expDate; }
void CreditCard::performPayment()
{
	cout<<"payment is successful"<<endl;
}

Cash::Cash(double _amount) 
{
	setAmount(_amount);
}
void Cash::performPayment()
{
	cout<<"payment is successful"<<endl;
}

Check::Check(string _name,string _bankId,double _amount)
{
	setName(_name);
	setBankID(_bankId);
	setAmount(_amount);
}

void Check::performPayment()
{
	cout<<"payment is successful"<<endl;
}
string Check::getName() { return name; }
void Check::setName(string _name) { name=_name; } 
string Check::getBankID() { return bankID; }
void Check::setBankID(string _bankID) { bankID=_bankID;   }
