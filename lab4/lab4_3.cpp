#include<string>
using namespace std;

class Contractor
{
protected:
	string firstName;
	string lastName;
	int age;
	string ID;

public:
	Contractor(string firstName = "", string lastName = "", string ID = "", int age = 0)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
		this->ID = ID;
	}

	Contractor(Contractor& obj)
	{
		this->firstName = obj.firstName;
		this->lastName = obj.lastName;
		this->age = obj.age;
		this->ID = obj.ID;
	}

	Contractor& operator=(Contractor& obj)
	{
		Contractor temp;
		temp.firstName = obj.firstName;
		temp.lastName = obj.lastName;
		temp.age = obj.age;
		temp.ID = obj.ID;

		return temp;
	}
};

class JuridicalPerson : public Contractor
{
private:
	string contract;

public:
	JuridicalPerson(string firstName = "", string lastName = "", string ID = "", int age = 0, string contract = "") :
		Contractor(firstName, lastName, ID, age)
	{
		this->contract = contract;
	}
};

class PhisicalPerson : public Contractor
{
private:
	string contract;

public:
	JuridicalPerson(string firstName = "", string lastName = "", string ID = "", int age = 0, string contract = "") :
		Contractor(firstName, lastName, ID, age)
	{
		this->contract = contract;
	}
};

