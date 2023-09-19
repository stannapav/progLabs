#include<iostream>
#include<string>

using namespace std;
class Printer
{
private:
	string markName;
	string paperFormat;
	double printSpeed;
	double price;

public:
	Printer(string markName = "", string paperFormat = "", double printSpeed = 0.0, double price = 0.0)
	{
		this->markName = markName;
		this->paperFormat = paperFormat;
		this->price = price;
		this->printSpeed = printSpeed;
	}

	static Printer Input()
	{
		string markName, paperFormat;
		double printSpeed, price;

		cout << "Enter mark name of the printer: ";
		cin.ignore();
		getline(cin, markName);

		cout << "Enter paper format for the printer: ";
		cin.ignore();
		getline(cin, paperFormat);

		cout << "Enter price of the printer: ";
		cin >> price;

		cout << "Enter print speed of the printer: ";
		cin >> printSpeed;
		cout << "\n";

		return Printer(markName, paperFormat, price, printSpeed);
	}

	int Price() { return this->price; }

	friend ostream& operator<<(ostream& os, Printer printer);
};

ostream& operator<<(ostream& os, Printer printer) 
{
	os << "Printer info:\n";
	os << "Mark: " << printer.markName << "\n";
	os << "Paper format: " << printer.paperFormat << "\n";
	os << "Price: " << printer.price << "\n";
	os << "Print speed: " << printer.printSpeed << "\n\n";

	return os;
}

void cheapPrinter(Printer* printers, int size)
{
	int min = printers[0].Price();
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (min > printers[i].Price())
		{
			min = printers[i].Price();
			index = i;
		}		
	}

	cout << "The cheapest printer price :" << min << " and index in array: " << index << "\n";
}

int main()
{
	int size = 5;
	Printer* printers = new Printer[size];

	for (int i = 0; i < size; i++)
		printers[i] = Printer::Input();

	for (int i = 0; i < size; i++)
		cout << printers[i] << "\n";
	
	cheapPrinter(printers, size);

	delete[] printers;
	return 0;
}