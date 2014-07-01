#pragma once
#include<iostream>
#include<string>
#include"ShoppingCart.h"
using namespace std;

class Customer
{
	friend class ShoppingCart;
private:
	long customerID;
	string name;
	string address;
	string phone;
	double bonus;
	string email;
	string username;
	string password;

public:
	//Customer(string,string,string,string,string,string,long);
	Customer();
	void sendBill();
	long getCustomerID();
	void setCustomerID(long);
	string getName();
	void setName(string);
	string getAdress();
	void setAdress(string);
	string getPhone();
	void setPhone(string);
	double getBonus();
	string getEmail();
	void setEmail(string);
	string getUsername();
	void setUsername(string);
	string getPassword();
	void setPassword(string);
    bool checkAccount(string,string,ShoppingCart*);
	void addBonus(double);
	void useBonus(ShoppingCart*);
};

