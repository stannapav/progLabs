#include <iostream> 
#include <string> 

using namespace std;
// 9 var 
class Product
{
private:
	string name;
	double price;
	int quantity;

public:
	Product(string name = "none", double price = 0.0, int quantity = 0)
	{
		this->name = name;
		this->price = price;
		this->quantity = quantity;
	}

	double SaleAmount()
	{
		return this->price * this->quantity;
	}

	void Info()
	{
		cout << "This products name is " << this->name << " price is " << this->price << " and quanity is " << this->quantity << "\n";
		cout << "Sum of sale: " << this->SaleAmount() << "\n";
	}

	static Product Input()
	{
		cout << "Enter name of a product: ";
		string name;
		cin >> name;
		cout << "Enter price of a product: ";
		double price;
		cin >> price;
		cout << "Enter quantity of a product: ";
		int quantity;
		cin >> quantity;

		return Product(name, price, quantity);
	}
};

int main()
{
	Product phone("Samsung 31A", 25, 10);
	phone.Info();

	Product anotherPhone = Product::Input();
	anotherPhone.Info();

	return 0;
}