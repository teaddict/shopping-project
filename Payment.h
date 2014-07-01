#pragma once
#include<iostream>
#include<string>
using namespace std;
class Payment
{
private:
	double amount;
public:
    Payment();
	double getAmount();
	void setAmount(double);
	virtual void performPayment()
	{

	}
};

class CreditCard:public Payment
{
private:
	long number;
	string type;
	string expDate;

public:
    CreditCard(long,string,string,double);
	long getNumber();
	void setNumber(long);
	string getType();
	void setType(string);
	string getExpDate();
	void setExpDate(string);
	void performPayment();
};

class Cash:public Payment
{
public:
    Cash(double);
	void performPayment();
};

class Check:public Payment
{
private:
	string name;
	string bankID;
public:
    Check(string,string,double);
	void performPayment();
	string getName();
	void setName(string);
	string getBankID();
	void setBankID(string);
};
