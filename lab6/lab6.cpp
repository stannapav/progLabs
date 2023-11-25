#include<iostream>
#include<string>

using namespace std;
class Persone
{
protected:
	string firstName;
	string lastName;
	int age;

public:
	Persone(string firstName = "", string lastName = "", int age = 0)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
	}

	virtual void Show()
	{
		cout << "Persone info:"
			<< "\nFirst name: " << this->firstName
			<< "\nLast name: " << this->lastName
			<< "\nAge: " << this->age << "\n\n";
	}
};

class Profession
{
protected:
	string name;
	double wage;

public:
	Profession(string name = "", double wage = 0.0)
	{
		this->name = name;
		this->wage = wage;
	}

	virtual void Show()
	{
		cout << "Profession info:"
			<< "\nProfession name: " << this->name
			<< "\nWage: " << this->wage << "\n\n";
	}
};

class PersoneWithProfession : public Persone, public Profession
{
public:
	PersoneWithProfession(string firstName = "", string lastName = "", int age = 0, string name = "", double wage = 0.0)
		: Persone(firstName, lastName, age), Profession(name, wage)
	{
	}

	void Show()
	{
		cout << "Persone with profession info:"
			<< "\nFirst name: " << this->firstName
			<< "\nLast name: " << this->lastName
			<< "\nAge: " << this->age
			<< "\nProfession name: " << this->name
			<< "\nWage: " << this->wage << "\n\n";
	}
};

int main()
{
	Persone ann("Ann", "Striharchuk", 18);
	Profession programmer("Programmer", 1000.0);
	PersoneWithProfession annProgramer("Ann", "Striharchuk", 18, "Programmer", 1000.0);

	ann.Show();
	programmer.Show();
	annProgramer.Show();

	return 0;
}