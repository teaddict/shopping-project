#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
	Product* getProduct();
	int getID(); 
	void setId(int);
	string getName();
	void setName(string);
	double getPrice();
	void setPrice(double);
	virtual void printProperties()=0;
    static int pi;

private:
	int ID; 
	string name;
	double price;

};


class Book:public Product
{
public:
	Book(int,string,double,string,string,int);
	void printProperties();
	string getAuthor();
	void setAuthor(string);
	string getPublisher();
	void setPublisher(string);
	int getPage();
	void setPage(int);

private:
	string author;
	string publisher;
	int page;
};

class Magazine:public Product
{
public:
	Magazine(int,string,double,int,string);
	void printProperties();
	int getIssue();
	void setIssue(int);
	string getType();
	void setType(string);
private:
	int Issue;
	string type;
};

class MusicCd:public Product
{
public:
	MusicCd(int,string,double,string,string);

	void printProperties();
	string getSinger();
	void setSinger(string);
	string getType();
	void setType(string);
private:
	string singer;
	string type;
};



