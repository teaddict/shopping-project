#include <iostream>
#include <string>
#include"ProductToPurchase.h"
using namespace std;


	Product* ProductToPurchase::getProduct(){return product;}
	void ProductToPurchase::setProduct(Product* _product) {product=_product;}
	int ProductToPurchase::getQuantity(){return quantity;}
	void ProductToPurchase::setQuantity(int _quantity){quantity=_quantity;}


