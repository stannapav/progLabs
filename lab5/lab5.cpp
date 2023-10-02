#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>

using namespace std;
struct Date
{
	int Day, Month;
};

ostream& operator<<(ostream& os, Date date)
{
	os << date.Day << "/" << date.Month;
	return os;
}

class Storage
{
private:
	int amount;
	int storagePeriod;
	Date deliveryDate;
	int deliveryNumber;
	static int count;

public:
	Storage(int amount = 0, int storagePeriod = 0, Date deliveryDate = {0, 0})
	{
		this->amount = amount;
		this->storagePeriod = storagePeriod;
		this->deliveryDate = deliveryDate;
		this->deliveryNumber = ++count;
	}

	inline int AmountGet() { return this->amount; }
	inline int StoragePeriodGet() { return this->storagePeriod; }
	inline Date DeliveryDatetGet() { return this->deliveryDate; }
	inline int DeliveryNumberGet() { return this->deliveryNumber; }

	virtual void Info() {}
};

int Storage::count = 0;

class Cabbage : public Storage
{
private:
	int leafCount;
	double vitaminC;

public:
	Cabbage(int amount = 0, int storagePeriod = 0, Date deliveryDate = { 0, 0 }, int leafCount = 0, double vitaminC = 0.0)
		:Storage(amount, storagePeriod, deliveryDate)
	{
		this->leafCount = leafCount;
		this->vitaminC = vitaminC;
	}

	void Info()
	{
		cout << "Cabbage info:"
			<< "\nAmount: " << this->AmountGet()
			<< "\nStorage period: " << this->StoragePeriodGet()
			<< "\nDelivery Date: " << this->DeliveryDatetGet()
			<< "\nDelivery Number: " << this->DeliveryNumberGet()
			<< "\nLeaf Count: " << this->leafCount
			<< "\nVitamin C: " << this->vitaminC
			<< "\n\n";
	}

	static Cabbage* Input()
	{
		int amount, storagePeriod, leafCount;
		double vitaminC;
		Date deliveryDate = {0, 0};

		cout << "Enter amount: ";
		cin >> amount;
		cout << "Enter storage period: ";
		cin >> storagePeriod;
		cout << "Enter cabbage leaf count: ";
		cin >> leafCount;
		cout << "Enter leaf vitamin C: ";
		cin >> vitaminC;

		while (true)
		{
			cout << "Enter month of delivery day: ";
			cin >> deliveryDate.Month;

			if (deliveryDate.Month >= 1 && deliveryDate.Month <= 12)
			{
				cout << "Enter day of delivery day: ";
				cin >> deliveryDate.Day;

				if (deliveryDate.Day >= 1 && deliveryDate.Day <= 30)
					break;
				else
					cout << "Wrong input\n\n";
			}
			else 
				cout << "Wrong input\n\n";
		}	

		cout << "\n";
		Cabbage* temp = new Cabbage(amount, storagePeriod, deliveryDate, leafCount, vitaminC);
		return temp;
	}
};

class Carrot : protected Storage
{
private:
	double lenght;
	double vitaminA;

public:
	Carrot(int amount = 0, int storagePeriod = 0, Date deliveryDate = { 0, 0 }, double lenght = 0.0, double vitaminA = 0.0)
		:Storage(amount, storagePeriod, deliveryDate)
	{
		this->lenght = lenght;
		this->vitaminA = vitaminA;
	}

	void Info()
	{
		cout << "Carrot info:"
			<< "\nAmount: " << this->AmountGet()
			<< "\nStorage period: " << this->StoragePeriodGet()
			<< "\nDelivery Date: " << this->DeliveryDatetGet()
			<< "\nDelivery Number: " << this->DeliveryNumberGet()
			<< "\nCarrot lenght: " << this->lenght
			<< "\nVitamin A: " << this->vitaminA
			<< "\n\n";
	}

	static Carrot* Input()
	{
		int amount, storagePeriod;
		double lenght, vitaminA;
		Date deliveryDate = { 0, 0 };

		cout << "Enter amount: ";
		cin >> amount;
		cout << "Enter storage period: ";
		cin >> storagePeriod;
		cout << "Enter lenght of carrot: ";
		cin >> lenght;
		cout << "Enter leaf vitamin A: ";
		cin >> vitaminA;

		while (true)
		{
			cout << "Enter month of delivery day: ";
			cin >> deliveryDate.Month;

			if (deliveryDate.Month >= 1 && deliveryDate.Month <= 12)
			{
				cout << "Enter day of delivery day: ";
				cin >> deliveryDate.Day;

				if (deliveryDate.Day >= 1 && deliveryDate.Day <= 30)
					break;
				else
					cout << "Wrong input\n\n";
			}
			else
				cout << "Wrong input\n\n";
		}

		cout << "\n";
		Carrot* temp = new Carrot(amount, storagePeriod, deliveryDate, lenght, vitaminA);
		return temp;
	}
};

class Beetroot : private Storage
{
private:
	double radius;
	double vitaminB;

public:
	Storage::AmountGet; //that's how you restore

	Beetroot(int amount = 0, int storagePeriod = 0, Date deliveryDate = { 0, 0 }, double radius = 0.0, double vitaminB = 0.0)
		:Storage(amount, storagePeriod, deliveryDate)
	{
		this->radius = radius;
		this->vitaminB = vitaminB;
	}

	void Info()
	{
		cout << "Beetroot info:"
			<< "\nAmount: " << this->AmountGet()
			<< "\nStorage period: " << this->StoragePeriodGet()
			<< "\nDelivery Date: " << this->DeliveryDatetGet()
			<< "\nDelivery Number: " << this->DeliveryNumberGet()
			<< "\nBeetroot radius: " << this->radius
			<< "\nVitamin B: " << this->vitaminB
			<< "\n\n";
	}

	static Beetroot* Input()
	{
		int amount, storagePeriod;
		double radius, vitaminB;
		Date deliveryDate = { 0, 0 };

		cout << "Enter amount: ";
		cin >> amount;
		cout << "Enter storage period: ";
		cin >> storagePeriod;
		cout << "Enter beetroot radius: ";
		cin >> radius;
		cout << "Enter leaf vitamin B: ";
		cin >> vitaminB;

		while (true)
		{
			cout << "Enter month of delivery day: ";
			cin >> deliveryDate.Month;

			if (deliveryDate.Month >= 1 && deliveryDate.Month <= 12)
			{
				cout << "Enter day of delivery day: ";
				cin >> deliveryDate.Day;

				if (deliveryDate.Day >= 1 && deliveryDate.Day <= 30)
					break;
				else
					cout << "Wrong input\n\n";
			}
			else
				cout << "Wrong input\n\n";
		}

		cout << "\n";
		Beetroot* temp = new Beetroot(amount, storagePeriod, deliveryDate, radius, vitaminB);
		return temp;
	}
};

bool Menu(vector<Storage*>& storage)
{
	int choice;
	cout << "\tMenu"
		<< "\n1: Add Cabbage"
		<< "\n2: Add Carrot"
		<< "\n3: Add Beetroot"
		<< "\n4: Look at whole list"
		<< "\n5: Look at spesific vegetable"
		<< "\n0: Exit"
		<< "\n\nEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		storage.push_back(Cabbage::Input());
		cout << "Cabbage added\n\n";
		break;

	case 2:
		storage.push_back((Storage*)Carrot::Input());
		cout << "Carrot added\n\n";
		break;

	case 3:
		storage.push_back((Storage*)Beetroot::Input());
		cout << "Beetroot added\n\n";
		break;

	case 4:
		if (storage.size() == 0)
			cout << "You cannot look vegetables add someting\n";
		else
		{
			for(int i = 0; i < storage.size(); i++)
			{
				if (typeid(*storage[i]).name() == typeid(Cabbage).name())
					((Cabbage*)storage[i])->Info();
				else if (typeid(*storage[i]).name() == typeid(Carrot).name())
					((Carrot*)storage[i])->Info();
				else if (typeid(*storage[i]).name() == typeid(Beetroot).name())
					((Beetroot*)storage[i])->Info();
			}
		}
		break;

	case 5:
		if (storage.size() == 0)
			cout << "You cannot look at spesific vegetable add someting\n";
		else
		{
			while (true)
			{
				cout << "Enter index [0 - " << storage.size() - 1 << "]";
				cin >> choice;
				if (choice >= 0 && choice < storage.size())
				{
					if (typeid(*storage[choice]).name() == typeid(Cabbage).name())
						((Cabbage*)storage[choice])->Info();
					else if (typeid(*storage[choice]).name() == typeid(Carrot).name())
						((Carrot*)storage[choice])->Info();
					else if (typeid(*storage[choice]).name() == typeid(Beetroot).name())
						((Beetroot*)storage[choice])->Info();

					break;
				}
				else
					cout << "Wrong input\n\n";
			}
		}
		break;

	case 0:
		return false;
		break;

	default:
		cout << "Wrong input\n\n";
		break;
	}

	return true;
}

int main()
{
	bool menu = false;
	vector<Storage *> storage;

	do
	{
		menu = Menu(storage);
	} while (menu);

	for (int i = 0; i < storage.size(); i++)
		delete storage[i];

	return 0;
}