#pragma once
#include<iostream>
#include<string>
#include "Product.h"
#include "ProductToPurchase.h"
#include "Payment.h"
#include "Customer.h"
#include<list>
using namespace std;

class ShoppingCart
{
	friend class Customer;
protected:
	list <Customer> _customer; //bunu ben ekledim, tüm müsterileri listede tutuyorum
	list <Product *> _products; //bütün productları bu listte tutcam
private:
	Payment* paymentMethod;
	Customer* customer;
	bool isBonusUsed;
	list <ProductToPurchase> productsToPurchase;
public:
	ShoppingCart();
	~ShoppingCart()
	{
		delete paymentMethod;
		delete customer;
		productsToPurchase.clear();
	}
	Payment* getPaymentMethod();
	void setPaymentMethod(Payment*);
	Customer* getCustomer();
	void setCustomer(Customer*);
	void setBonusUsed();
	void addProduct(int);  // shoppingcarta eklemek için
	void addCustomer(Customer*); //sisteme customre eklemek,bunu ben ekledim
	void addNewProductToSystem(Product*); //bunu ben ekledim, sisteme product ekliyor
	void removeProduct(int);
	void placeOrder();
	void cancelOrder();
	void printProducts();
	void printShoppingCart(); //ben ekledim shopping cartımı gösteriyor içindekileri
	void showInvoice();
	void showCustomers(); // bunu ben ekledim, tüm customerları gösterir
	void showProducts(); // bunu ben ekledim, tüm customerları gösterir
	double getBill(); // useBonus için get price
	bool isCustomerListEmpty(); // showCustomers() fonksiyonu için, eğer boşsa false döndürür
};

