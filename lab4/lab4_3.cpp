#include<iostream>
#include<string>
using namespace std;

class Contractor
{
protected:
	string firstName;
	string lastName;
	int age;

public:
	Contractor(string firstName = "", string lastName = "", int age = 0)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
	}

	Contractor(Contractor& obj)
	{
		this->firstName = obj.firstName;
		this->lastName = obj.lastName;
		this->age = obj.age;
	}

	virtual void Print() = 0;
};

class JuridicalPerson : public Contractor
{
private:
	string contract;

public:
	JuridicalPerson(string firstName = "", string lastName = "", int age = 0, string contract = "") :
		Contractor(firstName, lastName, age)
	{
		this->contract = contract;
	}

	JuridicalPerson(JuridicalPerson& obj) : Contractor(obj.firstName, obj.lastName, obj.age)
	{
		this->contract = obj.contract;
		cout << "JuridicalPerson copy\n\n";
	}

	void operator=(JuridicalPerson& obj)
	{
		this->firstName = obj.firstName;
		this->lastName = obj.lastName;
		this->age = obj.age;
		this->contract = obj.contract;

		cout << "JuridicalPerson operator=\n\n";
	}

	void Print()
	{
		cout << "Juridical person info:\n"
			<< "First name: " << this->firstName
			<< "\nLast name: " << this->lastName
			<< "\nAge: " << this->age
			<< "\nContract: " << this->contract << "\n\n";
	}
};

class NaturalPerson : public Contractor
{
private:
	string profession;

public:
	NaturalPerson(string firstName = "", string lastName = "", int age = 0, string profession = "") :
		Contractor(firstName, lastName, age)
	{
		this->profession = profession;
	}

	NaturalPerson(NaturalPerson& obj) : Contractor(obj.firstName, obj.lastName, obj.age)
	{
		this->profession = obj.profession;

		cout << "NaturalPerson copy\n\n";
	}

	void operator=(NaturalPerson& obj)
	{
		this->firstName = obj.firstName;
		this->lastName = obj.lastName;
		this->age = obj.age;
		this->profession = obj.profession;

		cout << "NaturalPerson operator=\n\n";
	}

	void Print()
	{
		cout << "Natural person info:\n"
			<< "First name: " << this->firstName
			<< "\nLast name: " << this->lastName
			<< "\nAge: " << this->age
			<< "\nProfession: " << this->profession << "\n\n";
	}
};

int main()
{
	NaturalPerson teacher("Mark", "Smith", 28, "English teacher");
	JuridicalPerson lawyer("Diana", "Willson", 30, "Lawyer");
	teacher.Print();
	lawyer.Print();

	NaturalPerson teacherCopy = teacher;
	teacherCopy.Print();
	JuridicalPerson lawyerCopy = lawyer;
	lawyerCopy.Print();

	NaturalPerson copyOfTeacherCopy;
	JuridicalPerson copyOfLawyerCopy;
	copyOfTeacherCopy = teacherCopy;
	copyOfTeacherCopy.Print();
	copyOfLawyerCopy = lawyerCopy;
	copyOfLawyerCopy.Print();

	return 0;
}