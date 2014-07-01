#include"Product.h"
#include<iostream>
#include<string>
using namespace std;


Product* Product::getProduct(){return this;}

Book::Book(int _ID,string _name,double _price,string _author,string _publisher,int _page)
{
	Product::setId(_ID);
	Product::setName(_name);
	Product::setPrice(_price);
	setAuthor(_author);
	setPublisher(_publisher);
	setPage(_page);

}


int Product::getID(){return ID;}
void Product::setId(int _ID){ID=_ID;}
string Product::getName(){return name;}
void Product::setName(string _name){name=_name;}
double Product::getPrice(){return price;}
void Product::setPrice(double _price){price=_price;}

void Book::printProperties()
{
	cout<<"Book Title: "<<Product::getName()<<endl;
	cout<<"Author: "<<author<<endl;
	cout<<"Publisher: "<<publisher<<endl;
	cout<<"Page: "<<page<<endl;
	cout<<"Price: "<<Product::getPrice()<<endl;
	cout<<"ID: "<<Product::getID()<<endl;
}

string Book::getAuthor(){return author;}
void Book::setAuthor(string _author){author=_author;}
string Book::getPublisher(){return publisher;}
void Book::setPublisher(string _publisher){publisher=_publisher;}
int Book::getPage(){return page;}
void Book::setPage(int _page){page=_page;}


Magazine::Magazine(int _ID,string _name,double _price,int _issue,string _type)
{
	Product::setId(_ID);
	Product::setName(_name);
	Product::setPrice(_price);
	setIssue(_issue);
	setType(_type);

}
void Magazine::printProperties()

{	cout<<"Magazin Title: "<<Product::getName()<<endl;
cout<<"Issue: "<<Issue<<endl;
cout<<"Type: "<<type<<endl;
cout<<"Price: "<<Product::getPrice()<<endl;
cout<<"ID: "<<Product::getID()<<endl;
}
int Magazine::getIssue(){return Issue; }
void Magazine::setIssue(int _issue){Issue=_issue;}
string Magazine::getType(){return type; }
void Magazine::setType(string _type){type=_type;}


MusicCd::MusicCd(int _ID,string _name,double _price,string _singer,string _type)
{
	Product::setId(_ID);
	Product::setName(_name);
	Product::setPrice(_price);
	setSinger(_singer);
	setType(_type);

}
void MusicCd::printProperties()
{

	cout<<"Album Name: "<<Product::getName()<<endl;
	cout<<"Singer: "<<singer<<endl;
	cout<<"Type: "<<type<<endl;	
	cout<<"Price: "<<Product::getPrice()<<endl;
	cout<<"ID: "<<Product::getID()<<endl;
}
string MusicCd::getSinger(){return singer;}
void MusicCd::setSinger(string _singer){singer=_singer;}
string MusicCd::getType(){return type;}
void MusicCd::setType(string _type){type=_type;}

