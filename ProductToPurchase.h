#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;


class ProductToPurchase
{
public:
	Product* getProduct();
	void setProduct(Product*);
	int getQuantity();
	void setQuantity(int);

private:
	Product *product;
	int quantity;
};
