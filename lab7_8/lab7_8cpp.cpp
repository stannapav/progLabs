#include<iostream>
#include<string>

using namespace std;

class A1 
{
private:
	string a1;
public:
	A1(string a1 = "") { this->a1 = a1; }
	A1(A1& obj) { this->a1 = obj.a1; }
	~A1() { cout << "A1 dead\n"; }
	string getA1() { return a1; }
	void print() { cout << "A1 is " << a1 << '\n'; }
};

class A3
{
private:
	string a3;
public:
	A3(string a3 = "") { this->a3 = a3; }
	A3(A3& obj) { this->a3 = obj.a3; }
	~A3() { cout << "A3 dead\n"; }
	string getA3() { return a3; }
	void print() { cout << "A3 is " << a3 << '\n'; }
};

class B1 : private A1
{
private:
	int b1;
public:
	A1::getA1;
	B1(string a1 = "", int b1 = 0) : A1(a1) { this->b1 = b1; }
	B1(B1& obj) : A1(obj.getA1()) { this->b1 = b1; }
	~B1() { cout << "B1 dead\n"; }
	int getB1() { return b1; }
	void print() 
	{ 
		A1::print();
		cout << "B1 is " << b1 << '\n'; 
	}
};

class B2 :  public A1,  public A3
{
private:
	int b2;
public:
	B2(string a1 = "", string a3 = "", int b2 = 0) : A1(a1), A3(a3) { this->b2 = b2; }
	B2(B2& obj) : A1(obj.getA1()), A3(obj.getA3()) { this->b2 = b2; }
	~B2() { cout << "B2 dead\n"; }
	int getB2() { return b2; }
	void print()
	{
		A1::print();
		A3::print();
		cout << "B2 is " << b2 << '\n';
	}
};

class B3 :  protected A3
{
private:
	int b3;
public:
	A3::getA3;
	B3(string a3 = "",  int b3 = 0) : A3(a3) { this->b3 = b3; }
	B3(B3& obj) : A3(obj.getA3()) { this->b3 = b3; }
	~B3() { cout << "B3 dead\n"; }
	int getB3() { return b3; }
	void print()
	{
		A3::print();
		cout << "B3 is " << b3 << '\n';
	}
};

class C1 :  protected B1,   public B2
{
private:
	float c1;
public:
	B1::getB1; B1::getA1;
	C1(string a11 = "", int b1 = 0, string a21 = "", string a23 = "", int b2 = 0 ,float c1 = 0.0) 
		: B1(a11, b1), B2(a21, a23, b2) { this->c1 = c1; }
	C1(C1& obj) : B1(obj.B1::getA1(), obj.getB1()), B2(obj.B2::getA1(), obj.getA3(), obj.getB2()) { this->c1 = c1; }
	~C1() { cout << "C1 dead\n"; }
	float getC1() { return c1; }
	void print()
	{
		B1::print();
		B2::print();
		cout << "C1 is " << c1 << '\n';
	}
};

class C2 :  private B1,  public B2,   protected B3
{
private:
	float c2;
public:
	B1::getA1; B1::getB1; B3::getA3; B3::getB3;
	C2(string a11 = "", int b1 = 0, string a21 = "", string a23 = "", int b2 = 0, string a33 = "", int b3 = 0, float c2 = 0.0f) 
		: B1(a11, b1), B2(a21, a23, b2), B3(a33, b3)  { this->c2 = c2; }
	C2(C2& obj) : B1(obj.B1::getA1(), obj.getB1()), B2(obj.B2::getA1(), obj.B2::getA3(), obj.getB2()), B3(obj.B3::getA3(), obj.getB3()) { this->c2 = c2; }
	~C2() { cout << "C2 dead\n"; }
	float getC2() { return c2; }
	void print()
	{
		B1::print();
		B2::print();
		B3::print();
		cout << "C2 is " << c2 << '\n';
	}
};

class C3 :  protected B2,  private B3
{
private:
	float c3;
public:
	B2::getA1; B2::getA3; B2::getB2; B3::getA3; B3::getB3;
	C3(string a21 = "", string a23 = "", int b2 = 0, string a33 = "", int b3 = 0, float c3 = 0.0f) 
		:B2(a21, a23, b2), B3(a33, b3) { this->c3 = c3; }
	C3(C3& obj) : B2(obj.getA1(), obj.B2::getA3(), obj.getB2()), B3(obj.B3::getA3(), obj.getB3()) { this->c3 = obj.c3; }
	~C3() { cout << "C3 dead\n"; }
	float getC3() { return c3; }
	void print()
	{
		B2::print();
		B3::print();
		cout << "C3 is " << c3 << '\n';
	}
};

class D2 :  protected C2,  public C3
{
private:
	char d2;
public:
	C2::getA1; C2::getA3; C2::getB1; C2::getB2; C2::getB3; C2::getC2; C3::getA1; C3::getA3; C3::getB2; C3::getB3; C3::getC3;
	D2(string a211 = "", int b21 = 0, string a221 = "", string a223 = "", int b22 = 0, string a233 = "", int b23 = 0, float c2 = 0.0f, 
		string a321 = "", string a323 = "", int b32 = 0, string a333 = "", int b33 = 0, float c3 = 0.0f, char d2 = ' ')
		: C2(a211, b21, a221, a223, b22, a233, b23, c2), C3(a321, a323, b32, a333, b33, c3) { this->d2 = d2; }
	D2(D2& obj) : C2(obj.C2::B2::getA1(), obj.getB1(), obj.C2::B2::getA1(), obj.C2::B2::getA3(), obj.C2::getB2(), obj.C2::B3::getA3(), obj.C2::getB3(), obj.getC3()),
		C3(obj.C3::getA1(), obj.C3::B2::getA3(), obj.C3::getB2(), obj.C3::B2::getA3(), obj.C3::getB3(), obj.getC3()) { this->d2 = obj.d2; }
	~D2() { cout << "D2 dead\n"; }
	char getD2() { return d2; }
	void print()
	{
		C2::print();
		C3::print();
		cout << "D2 is " << d2 << '\n';
	}
};

class E1 : public D2
{
private:
	bool e1;
public:
	E1(string a211 = "", int b21 = 0, string a221 = "", string a223 = "", int b22 = 0, string a233 = "", int b23 = 0, float c2 = 0.0f,
		string a321 = "", string a323 = "", int b32 = 0, string a333 = "", int b33 = 0, float c3 = 0.0f, char d2 = ' ', bool e1 = true)
		: D2(a211, b21, a221, a223, b22, a233, b23, c2, a321, a323, b32, a333, b33, c3, d2) { this->e1 = e1; }
	E1(E1& obj) : D2(obj.D2::C2::B2::getA1(), obj.getB1(), obj.D2::C2::B2::getA1(), obj.D2::C2::B2::getA3(), obj.D2::C2::getB2(), obj.D2::C2::B3::getA3(), obj.D2::C2::getB3(), obj.getC2(),
		obj.D2::C3::B2::getA1(), obj.D2::C3::B2::getA3(), obj.D2::C3::getB2(), obj.D2::C3::B2::getA3(), obj.D2::C3::getB3(), obj.getC3(), obj.getD2()) { this->e1 = obj.e1; }
	~E1() { cout << "E1 dead\n"; }
	bool getE1() { return e1; }
	void print()
	{
		D2::print();
		cout << "E1 is " << (e1 ? "True" : "False") << '\n';
	}
};

int main()
{
	E1 e("Hah", 3, "Hi", "Whasup", 27, "lol", 666, 312.123f, "meaw", "bark", 96, "heh", 57, 987.34f, 'a', true);
	e.print();

	return 0;
}