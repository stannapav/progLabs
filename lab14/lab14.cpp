#include<iostream>
#include<string>

using namespace std;

class Persone;

class Student
{
private:
	string name;
	int age;
	int mark;

public:
	friend Persone;

	Student(string name = "", int age = 0, int mark = 0)
	{
		this->name = name;
		this->age = age;
		this->mark = mark;
	}

	void setMark(int newMark)
	{
		this->mark = newMark;
	}

	void Print()
	{
		cout << this->name << " is " << this->age << " years old and has mark " << this->mark << "\n";
	}
};

class Persone
{
private:
	string name;
	int age;

public:
	Persone(string name = "", int age = 0)
	{
		this->name = name;
		this->age = age;
	}

	void ChangeStudentMark(Student& obj, int newMark)
	{
		obj.mark = newMark;
	}

	void PrintStudent(Student& obj)
	{
		cout << obj.name << " is " << obj.age << " years old and has mark " << obj.mark << "\n";
	}
};

int main()
{
	Persone teacher("Anna", 18);
	Student nikita("Nikita", 17, 60);

	nikita.Print();
	teacher.ChangeStudentMark(nikita, 75);
	cout << "after change from student print:\n";
	nikita.Print();
	cout << "after change from persone print:\n";
	teacher.PrintStudent(nikita);

	return 0;
}