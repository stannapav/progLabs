#include<iostream>
#include<string>

using namespace std;

struct Date
{
	int day, month;

	Date(int day = 1, int month = 1)
	{
		this->day = day;
		this->month = month;
	}

	static Date Input()
	{
		int day, month;
		do
		{
			cout << "\nPlease enter right date. ( 1 <= day <= 31) (1 <= month <= 12)\n";
			cout << "Enter day: ";
			cin >> day;
			cout << "Enter month: ";
			cin >> month;
		} while (day < 1 || day > 31 || month < 1 || month > 12);
		return Date(day, month);
	}
};

class Product
{
public:
	virtual void Show() = 0;
	virtual Date GetDate() = 0;
};

class Sweets : public Product
{
private:
	string name;
	double weight;
	Date date;

public:
	Sweets(string name = "None", double weight = 0.0, Date date = {1, 1})
	{
		this->name = name;
		this->weight = weight;
		this->date = date;
	}

	void Show()
	{
		cout << "\nSweets info:\n"
			<< "Name: " << this->name 
			<< "\nWeight: " << this->weight
			<< "\nDate: " << this->date.day << "/" << this->date.month << "\n";
	}

	Date GetDate() { return date; };

	static Sweets* Input()
	{
		string name;
		double weight;
		Date date;

		cout << "Enter name of sweets: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter weight: ";
		cin >> weight;
		cout << "Enter date when made: ";
		date = Date::Input();

		return new Sweets(name, weight, date);
	}
};

class Dairy : public Product
{
private:
	string name;
	Date date;
	Date expirationDate;

public:
	Dairy(string name = "None", Date date = { 1, 1 }, Date expirationDate = {1, 1})
	{
		this->name = name;
		this->date = date;
		this->expirationDate = expirationDate;
	}

	void Show()
	{
		cout << "\nDairy info:\n"
			<< "Name: " << this->name
			<< "\nDate: " << this->date.day << "/" << this->date.month 
			<< "\nExpiration date: " << this->expirationDate.day << "/" << this->expirationDate.month << "\n";
	}

	Date GetDate() { return date; };

	static Dairy* Input()
	{
		string name;
		Date date;
		Date expirationDate;

		cout << "Enter name of dairy: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter date when made: ";
		date = Date::Input();
		cout << "Enter expiration date: ";
		expirationDate = Date::Input();

		return new Dairy(name, date, expirationDate);
	}
};

class Meat : public Product
{
private:
	string name;
	Date date;
	double GMO;

public:
	Meat(string name = "None", Date date = { 1, 1 }, double GMO = 0)
	{
		this->name = name;
		this->date = date;
		this->GMO = GMO;
	}

	void Show()
	{
		cout << "\nDairy info:\n"
			<< "Name: " << this->name
			<< "\nDate: " << this->date.day << "/" << this->date.month
			<< "\nGMO indicator: " << this->GMO << "%" << "\n";
	}

	Date GetDate() { return date; };

	static Meat* Input()
	{
		string name;
		Date date;
		double GMO;

		cout << "Enter name of meat: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter date when made: ";
		date = Date::Input();
		cout << "Enter GMO indicator: ";
		cin >> GMO;

		return new Meat(name, date, GMO);
	}
};

int main() 
{
	Product* products[3];

	int counter = 0;
	while (counter != 3)
	{
		int choice;
		cout << "\nEnter choice what product add(1 - Sweets, 2 - Dairy, 3 - Meat): ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			products[counter++] = Sweets::Input();
			break;

		case 2:
			products[counter++] = Dairy::Input();
			break;
		
		case 3:
			products[counter++] = Meat::Input();
			break;

		default:
			cout << "Wrong input!";
			break;
		}
	}

	cout << "\n\n";
	for (int i = 0; i < 3; i++)
		products[i]->Show();

	Date start, end;
	cout << "\nShow in range\n";
	cout << "Enter start date: ";
	start = Date::Input();
	cout << "Enter end date: ";
	end = Date::Input();

	for (int i = 0; i < 3; i++)
	{
		Date getDate = products[i]->GetDate();
		if (getDate.day >= start.day && getDate.month >= start.day
			&& getDate.month <= end.month && ((start.month < end.month) ? 
				((getDate.day <= 31 && getDate.month < end.month) || (getDate.day <= end.day && getDate.month == end.month))
				: getDate.day < end.day))
		{
			products[i]->Show();
		}
	}

	for (int i = 0; i < 3; i++)
		delete products[i];

	return 0;
}