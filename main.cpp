#include"Payment.h"
#include"Product.h"
#include"ProductToPurchase.h"
#include"ShoppingCart.h"
#include<list>
#include<string>
#include<iostream>
int Product::pi=0; //productlara otomatik id atamak için
using namespace std;
void customerMenu();
void itemMenu();
void shoppingMenu();
void mainMenu();

int ch,ch1,ch2,control;
Customer *c;
Customer *tmpc=new Customer(); //loginden sonra bu temp e atýyorum o useri ve iþlemlere bununla devam ediyorum
Product *p;
ShoppingCart *s=new ShoppingCart();
Payment *pay;
bool logged;
string username;
string password;
char quit;
int id;
double amount;
double bonus;

void mainMenu()
{
	cout<<"##################ONLINE BOOK STORE################"<<endl;

	cout<<"Main Menu"<<endl;
	cout<<"1. Customer"<<endl;
	cout<<"2. Item"<<endl;
	cout<<"3. Shopping"<<endl;
	cout<<"4. Quit"<<endl;
	cout<<"Choose one: "<<endl;
	cin>>ch;
	while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
	{
		cout << "Bad input, try again." << std::endl;
		// Reset the stream.
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cin>>ch;
	}
	switch(ch)
	{
	case 1: customerMenu(); break;
	case 2: itemMenu(); break;
	case 3: shoppingMenu(); break;
	case 4: exit(0); break;
	default: cout<<"error! please be careful while entering.."<<endl; mainMenu(); break;
	}

}


void customerMenu()
{
	cout<<"_____________"<<endl;
	cout<<"Customer Menu"<<endl;
	cout<<"1. Add a new customer to system"<<endl;
	cout<<"2. Show the customers in the system"<<endl;
	cout<<"3. Back"<<endl;
	cout<<"Choose one: "<<endl;
	cin>>ch1;
	while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
	{
		cout << "Bad input, try again." << std::endl;
		// Reset the stream.
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cin>>ch1;
	}
	if(ch1==1)
	{
		long customerID;
		string name;
		string address;
		string phone;
		double bonus;
		string email;
		string username;
		string password;
		cout<<"__________________________________________"<<endl;
		cout<<"Add Customer"<<endl;
		cout<<"enter customer id: ";
		cin>>customerID;
		while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
		{
			cout << "Bad input, try again." << std::endl;
			// Reset the stream.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cin>>customerID;
		}
		cout<<"enter customer name: ";
		cin>>name;
		cin.sync();
		cout<<"enter customer address: ";
		cin>>address;
		cin.sync();
		cout<<"enter customer phone: ";
		cin>>phone;
		cin.sync();
		cout<<"enter customer email: ";
		cin>>email;
		cin.sync();
		cout<<"enter customer username: ";
		cin>>username;
		cout<<"enter customer password: ";
		cin>>password;

		c=new Customer();
		c->setAdress(address);
		c->setCustomerID(customerID);
		c->setEmail(email);
		c->setName(name);
		c->setPassword(password);
		c->setPhone(phone);
		c->setUsername(username);
		s->addCustomer(c);

	}

	else if(ch1==2)
	{
		if(s->isCustomerListEmpty())
			cout<<"there is no customer.."<<endl;
		else
			s->showCustomers();
	}

	else if(ch1==3)
	{
		mainMenu();
	}
	else
	{
		cout<<"please choose correct one.."<<endl;
	}

	system("pause");
	customerMenu();

}

void itemMenu()
{
	cout<<"_________"<<endl;
	cout<<"Item Menu"<<endl;
	cout<<"1. Add a new item to system"<<endl;
	cout<<"2. Show the items in the system"<<endl;
	cout<<"3. Back"<<endl;
	cout<<"Choose one: "<<endl;
	cin>>ch1;

	if(ch1==1)
	{
		cout<<"__________________________________________"<<endl;
		cout<<"Add Item"<<endl;
		cout<<"1. Add Book"<<endl;
		cout<<"2. Add Music CD"<<endl;
		cout<<"3. Add Magazine"<<endl;
		cout<<"Choose one: "<<endl;
		cin>>ch2;
		while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
		{
			cout << "Bad input, try again." << std::endl;
			// Reset the stream.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cin>>ch2;
		}
		if(ch2==1)
		{
			string name;
			double price;
			string author;
			string publisher;
			int page;

			cout<<"enter book name: ";
			cin>>name;
			cin.sync();
			cout<<"price: ";
			cin>>price;
			while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
			{
				cout << "Bad input, try again." << std::endl;
				// Reset the stream.
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin>>price;
			}
			cout<<"enter author: ";
			cin>>author;
			cin.sync();
			cout<<"enter publisher: ";
			cin>>publisher;
			cin.sync();
			cout<<"enter page: ";
			cin>>page;
			while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
			{
				cout << "Bad input, try again." << std::endl;
				// Reset the stream.
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin>>page;
			}

			p=new Book(Product::pi,name,price,author,publisher,page); //abstract product class
			s->addNewProductToSystem(p); //oluþan productu tüm productlarý topladýðým listeye atadým
			Product::pi++;

		}

		else if(ch2==2)
		{
			string name;
			double price;
			string singer;
			string type;

			cout<<"enter album name: ";
			cin>>name;
			cin.sync();
			cout<<"price: ";
			cin>>price;
			while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
			{
				cout << "Bad input, try again." << std::endl;
				// Reset the stream.
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin>>price;
			}
			cout<<"enter singer: ";
			cin>>singer;
			cin.sync();
			cout<<"enter type: ";
			cin>>type;
			cin.sync();
			p=new MusicCd(Product::pi,name,price,singer,type);
			s->addNewProductToSystem(p); //oluþan productu tüm productlarý topladýðým listeye atadým
			Product::pi++;


		}

		else if(ch2==3)
		{
			string name;
			double price;
			int Issue;
			string type;

			cout<<"enter magazine name: ";
			cin>>name;
			cin.sync();
			cout<<"price: ";
			cin>>price;
			while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
			{
				cout << "Bad input, try again." << std::endl;
				// Reset the stream.
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin>>price;
			}
			cout<<"enter Issue: ";
			cin>>Issue;
			while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
			{
				cout << "Bad input, try again.(int)" << std::endl;
				// Reset the stream.
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin>>Issue;
			}
			cout<<"enter type: ";
			cin>>type;
			cin.sync();
			p=new Magazine(Product::pi,name,price,Issue,type);
			s->addNewProductToSystem(p); //oluþan productu tüm productlarý topladýðým listeye atadým
			Product::pi++;


		}
		else
		{
			cout<<"choose one of them please.."<<endl;
			itemMenu();
		}

	}

	else if(ch1==2)
	{
		if(Product::pi==0)
			cout<<"there is no product.."<<endl;
		else
			s->showProducts();

	}

	else if(ch1==3)
	{
		mainMenu();
	}

	system("pause");
	itemMenu();
}

void shoppingMenu()
{
	cout<<"_____________"<<endl;
	cout<<"Shopping Menu"<<endl;
	cout<<"1.  Login"<<endl;
	cout<<"2.  Add product"<<endl;
	cout<<"3.  Remove Product"<<endl;
	cout<<"4.  List all products"<<endl;
	cout<<"5.  List shopping cart"<<endl;
	cout<<"6.  Show Bonus"<<endl;
	cout<<"7.  Use Bonus"<<endl;
	cout<<"8.  Place Order"<<endl;
	cout<<"9.  Cancel Order"<<endl;
	cout<<"10. Show Invoice"<<endl;
	cout<<"11. Quit"<<endl;
	cout<<"choose one: ";
	cin>>ch1;
	while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
	{
		cout << "Bad input, try again." << std::endl;
		// Reset the stream.
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cin>>ch1;
	}
	if(ch1==1)
	{
		/* kullanici bilgilerini 	bool checkAccount(string,string,shoppingcart);
		dogruysa -> dogruysa setCustomer fonksiyonuyal bu usernamedeki customer set yapcak ve menuye dön ,
		yanlissa hata ver tekrar gir , ya da menuye dön*/
		do
		{
			cout<<"__________________________________________"<<endl;
			cout<<"Login Menu"<<endl;
			cout<<"enter username: ";
			cin>>username;
			cout<<"enter password: ";
			cin>>password;
			logged=c->checkAccount(username,password,s); // login kontrol

			if(logged) //artýk burdaki geçerli customerimýzý set yaptýk
			{
				cout<<"#############"<<endl;
				cout<<"	 WELCOME"<<endl;
				cout<<"#############"<<endl;
			}
			else
			{
				cout<<"please re-enter or quit(q): ";
				cin>>quit;
			}
		}while(logged==false && quit!='q');
	}
	else if(ch1==2)
	{
		/*
		shopping cart listesine product ekle fonksiyonunu çagir menuye dön
		*/
		cout<<"__________________________________________"<<endl;
		cout<<"Add Product To Shoppingcart"<<endl;
		cout<<"enter the product id: "<<endl;
		cin>>id;
		while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
		{
			cout << "Bad input, try again." << std::endl;
			// Reset the stream.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cin>>id;
		}
		s->addProduct(id);
	}
	else if(ch1==3)
	{
		/*
		shopping cart listesinden remove fonksiyonu ile ürün çýkart
		yazildi bu
		*/
		cout<<"__________________________________________"<<endl;
		cout<<"Remove Product From Shoppingcart"<<endl;
		cout<<"enter the product id: "<<endl;
		cin>>id;
		while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
		{
			cout << "Bad input, try again." << std::endl;
			// Reset the stream.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cin>>id;
		}
		s->removeProduct(id);
	}
	else if(ch1==4) // tüm productlarý göster
	{
		cout<<"-------------------------------"<<endl;
		cout<<"All Products\n"<<endl;
		s->showProducts();
	}
	else if(ch1==5)
	{
		//shopping listesini göster ->printShoppingCart()
		//yazýldý
		cout<<"-------------------------------"<<endl;
		cout<<"Your Shoppingcart\n"<<endl;
		s->printShoppingCart();
	}
	else if(ch1==6)
	{
		//if not logged first log in yourself
		//if logged bool logged=true;
		//call the getBonus();
		//customer.h get bonus çaðýr
		if(logged)
		{
			tmpc=s->getCustomer();
			cout<<"your bonus amount is: "<<tmpc->getBonus()<<endl;
		}
		else
		{
			cout<<"you are not logged\nplease login.."<<endl;
		}

	}
	else if(ch1==7)
	{
		//product fiyatina bakcak eger yetiyorsa satis gerçeklesir
		tmpc=s->getCustomer();
		if(s->getBill()>tmpc->getBonus())
		{
			cout<<"your bonus is not enough to buy.."<<endl;
		}
		else
		{
			tmpc->useBonus(s);
			s->setBonusUsed();
			s->showInvoice();
		}
	}
	else if(ch1==8)
	{
		int x;
		/*perform the payment for the items in the cart and send invoice to
		custumer’s email. */
		if(logged)
		{
Pay:
			cout<<"__________________________________________"<<endl;
			cout<<"Payment Menu"<<endl;
			cout<<"1)Credit Card"<<endl;
			cout<<"2)Cash"<<endl;
			cout<<"3)Check"<<endl;
			cout<<"please choose one of them: ";
			cin>>x;
			if(x==1)
			{
				long number;
				string type;
				string expDate;
				cout<<"enter credit card number: "<<endl;
				cin>>number;
				while( cin.fail() ) //eðer yanlýþ girerse int yerine char vs.. düzeltiyor
				{
					cout << "Bad input, try again." << std::endl;
					// Reset the stream.
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					cin>>number;
				}
				cout<<"enter type(master/visa): "<<endl;
				cin>>type;
				cin.sync();
				cout<<"enter expiration date of the card: "<<endl;
				cin>>expDate;
				cin.sync();
				amount=s->getBill();
				bonus=amount/100;
				pay=new CreditCard(number,type,expDate,amount);
				s->setPaymentMethod(pay);
				s->placeOrder();
				tmpc=s->getCustomer();
				tmpc->addBonus(bonus);

			}
			else if(x==2)
			{
				amount=s->getBill();
				bonus=amount/100;
				pay=new Cash(amount);
				s->setPaymentMethod(pay);
				s->placeOrder();
				tmpc=s->getCustomer();
				tmpc->addBonus(bonus);
			}

			else if(x==3)
			{
				string name;
				string bankId;
				double amount;
				double bonus;
				cout<<"enter name: "<<endl;
				cin>>name;
				cin.sync();
				cout<<"enter bank ID: "<<endl;
				cin>>bankId;
				amount=s->getBill();
				bonus=amount/100;
				pay=new Check(name,bankId,amount);
				s->setPaymentMethod(pay);
				s->placeOrder();
				tmpc=s->getCustomer();
				tmpc->addBonus(bonus);
			}
			else
			{
				cout<<"choose the correct payment please!.."<<endl;
				goto Pay;
			}
		}
		else
		{
			cout<<"please log in..."<<endl;
		}
	}
	else if(ch1==9)
	{
		//iptal et
		s->cancelOrder();
	}
	else if(ch1==10)
	{
		//faturayi göster showInvoice() komutuyla
		s->showInvoice();

	}
	else if(ch1==11)
	{
		mainMenu();
	}
	else
		cout<<"please choose one of them.."<<endl;

	system("pause");
	shoppingMenu();
}


int main()
{
	mainMenu();
	return 0;
}