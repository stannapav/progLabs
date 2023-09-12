#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;
class C_int
{
private:
	int num;

public:
	C_int(int num = 0) { this->num = num; }

	static C_int Input()
	{
		int num;
		cout << "Enter num: ";
		cin >> num;

		return C_int(num);
	}

	void SetRandom()
	{
		srand(time(NULL));
		this->num = rand() % 100;
	}

	static int Plus(int a, int b){ return a + b; }

	int Plus(int a) { return this->num += a; }

	void operator=(int num){ this->num = num; }

	int operator+(int num) { return this->num + num; }

	void operator+=(int num) { this->num += num; }

	friend ostream& operator<<(ostream& os, C_int num);
};

ostream& operator<<(ostream& os, C_int num) 
{
	os << num.num;
	return os;
}

class Triangle
{
private:
	double a, b, c;

public:
	Triangle(double a = 0, double b = 0, double c = 0)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	double Area()
	{
		double perimetr = this->a + this->b + this->c;
		double semiper = perimetr / 2;
		double area = sqrt(semiper * (semiper - this->a) * (semiper - this->b) * (semiper - this->c));

		return area;
	}

	static Triangle Input()
	{
		double a, b, c;

		do 
		{
			cout << "Enter a: ";
			cin >> a;

			cout << "Enter b: ";
			cin >> b;

			cout << "Enter c: ";
			cin >> c;

			
			if (a + b <= c)
				cout << "c cannot be bigger than sum of a and b re-enter sides\n";
			else if (c + b <= a)
				cout << "a cannot be bigger than sum of b and c re-enter sides\n";
			else if (a + c <= b)
				cout << "b cannot be bigger than sum of a and c re-enter sides\n";
			else
				break;

		} while (true);
		

		return Triangle(a, b, c);
	}

	friend ostream& operator<<(ostream& os, Triangle triangle);
};

ostream& operator<<(ostream& os, Triangle triangle)
{
	os << "side a: " << triangle.a << " side b: " << triangle.b << "  c: " << triangle.c << "\n" <<
		"area: " << triangle.Area() << "\n";
	return os;
}

bool menuForC_int(C_int& num);

int main() 
{
	C_int num;
	bool loop;
	
	do
	{
		loop = menuForC_int(num);
	} while (loop);

	Triangle a;
	Triangle b(4.0, 5.0, 3.0);

	a = Triangle::Input();
	cout << a << "\n" << b;

	return 0;
}

bool menuForC_int(C_int& num)
{
	int choice, a, b;
	cout << "\n\tMenu:\n";
	cout << "1: initialize number with your num\n";
	cout << "2: initialze with rundom num\n";
	cout << "3: print num\n";
	cout << "4: plus your num with another\n";
	cout << "5: plus some numbers\n";
	cout << "6: show your num plus some\n";
	cout << "0: exit this prog\n";
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		num = C_int::Input();
		return true;
		break;
	case 2:
		num.SetRandom();
		return true;
		break;
	case 3:
		cout << num;
		return true;
		break;
	case 4:
		cout << "Enter num: ";
		cin >> a;
		num.Plus(a); //or num += a;
		return true;
		break;
	case 5:
		cout << "Enter num1: ";
		cin >> a;
		cout << "Enter num2: ";
		cin >> b;
		cout << "result: " << C_int::Plus(a, b);
		return true;
		break;
	case 6:
		cout << "Enter num: ";
		cin >> a;
		cout << "result: " << num + a;
		return true;
		break;
	case 0:
		return false;
		break;
	default:
		cout << "Wrong input";
		return true;
		break;
	}
}