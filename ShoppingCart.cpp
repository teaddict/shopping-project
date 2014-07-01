#pragma once
#include <iostream>
#include <string>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart()
{
		isBonusUsed=false;
		paymentMethod=new Payment(); // composition
}


Payment* ShoppingCart::getPaymentMethod(){return paymentMethod;}
void ShoppingCart::setPaymentMethod(Payment* _paymentMethod){paymentMethod=_paymentMethod;}
Customer* ShoppingCart::getCustomer(){return customer;}
void ShoppingCart::setCustomer(Customer* _customer){customer=_customer;}
void ShoppingCart::setBonusUsed(){isBonusUsed=true;}
void ShoppingCart::addProduct(int _id)
{
	bool nfound=true; //not found yaptým eðer bulamazsa not found= true
	Product *pr;
	ProductToPurchase *p;
	p= new ProductToPurchase();
	list<Product *>::iterator iter;
	//burda arýyor.eðer tüm product listesinden yoksa bu ürünü ekleyemiycez benim shopping listime
	for(iter=_products.begin(); iter!=_products.end(); iter++) 
	{
		if((*iter)->getID()==_id)
		{
			pr=(*iter)->getProduct();
			p->setProduct(pr);
			productsToPurchase.push_back(*p);
			cout<<"your item is added in your shopping cart.."<<endl;
			nfound=false;
			break;
		}
	}
	if(nfound)
		cout<<"your item is not found.."<<endl;
}
void ShoppingCart::removeProduct(int _id)
{
	bool found=false;
	Product *p;
	Product *purch;
	list<ProductToPurchase>::iterator iter;
	list<Product *>::iterator iterpr;

	//burda arýyor.eðer tüm product listesinden yoksa bu ürünü silemiycez benim shopping listimden,eðer yoksa satýnda alamam zaten !

	for(iterpr=_products.begin(); iterpr!=_products.end(); iter++)
	{
		p=(*iterpr)->getProduct();
		if((p->getID())==_id)
		{
			found=true;
			break;
		}

	}
	if(found) //eðer bulursa onu siliyor shopping listemden 
	{
		for(iter=productsToPurchase.begin(); iter!=productsToPurchase.end(); iter++)
		{
			purch=iter->getProduct();
			if((p->getID())==(purch->getID()))
			{
				productsToPurchase.erase(iter);
				cout<<"the item is removed from your shopping cart.."<<endl;
				break;
			}
			cout<<"this item is not in your shopping cart"<<endl;
		}
	}
	else
		cout<<"this item is not in products"<<endl;
}
void ShoppingCart::placeOrder()
{
	paymentMethod->performPayment();
	customer->sendBill();
}
void ShoppingCart::cancelOrder()
{
	productsToPurchase.clear();
}

void ShoppingCart::printShoppingCart()
{
	list<ProductToPurchase>::iterator iter;
	Product *p;
	for(iter=productsToPurchase.begin(); iter!=productsToPurchase.end(); iter++)
	{
		p=iter->getProduct();
		cout<<"||||-----------------------------------------------"<<endl;
		p->printProperties();
		cout<<"-----------------------------------------------||||"<<endl;;
	}
}

void ShoppingCart::showInvoice()
{
	cout<<"_____________________________________________________"<<endl;
	cout<<"Invoince"<<endl;
	cout<<"Your Shopping Cart: "<<endl;
	this->printShoppingCart();
	cout<<"the amount that you paid is: "<<this->getBill()<<endl;
	cout<<"thank you for choosing us.."<<endl;
	customer->sendBill();
}

double ShoppingCart::getBill()
{
	list<ProductToPurchase>::iterator iter;
	Product *p;
	double _amount=0.0;
	for(iter=productsToPurchase.begin(); iter!=productsToPurchase.end(); iter++)
	{
		p=iter->getProduct();
		_amount+=p->getPrice();
	}

	return _amount;
}

void ShoppingCart::addCustomer(Customer* list)
{
	_customer.push_back(*list);
}

void ShoppingCart::showCustomers()
{
	list<Customer>::iterator iter;
	Customer *p=new Customer();
	for(iter=_customer.begin(); iter!=_customer.end(); iter++)
	{
		*p=*iter;
		cout<<"_____________________________________"<<endl;
		cout<<"customer id: "<<p->getCustomerID()<<endl;
		cout<<"customer name: "<<p->getName()<<endl;
		cout<<"customer email: "<<p->getEmail()<<endl;
		cout<<"_____________________________________"<<endl;
	}
}

void ShoppingCart::addNewProductToSystem(Product* list)
{
	_products.push_back(list);
}

void ShoppingCart::showProducts()
{
	list<Product *>::iterator iter;
	for(iter=_products.begin(); iter!=_products.end(); iter++)
	{
		cout<<"<-----------------------------------------------"<<endl;
		(*iter)->printProperties();
		cout<<"----------------------------------------------->"<<endl;
	}
}
bool ShoppingCart::isCustomerListEmpty()
{
	if(_customer.empty())
		return true;
	else
		return false;
}
