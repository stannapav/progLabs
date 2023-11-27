#include<iostream>

using namespace std;

template<typename T>
class ProperFraction
{
protected:
	T numerator; //чисельник
	T denominator; //знаменик

public:
	ProperFraction()
	{
		this->numerator = 0;
		this->denominator = 0;
	}

	ProperFraction(T numerator, T denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}

	ProperFraction(const ProperFraction<T>& copy)
	{
		this->numerator = copy.numerator;
		this->denominator = copy.denominator;
	}
	
	ProperFraction<T> operator+(const ProperFraction<T>& rpf)
	{
		ProperFraction<T> result;

		if (this->denominator == rpf.denominator)
		{
			result.denominator = this->denominator;
			result.numerator = this->numerator + rpf.numerator;
		}
		else
		{
			result.denominator = this->denominator * rpf.denominator;
			result.numerator = (this->numerator * rpf.denominator) + (rpf.numerator * this->denominator);
		}

		return result;
	}

	ProperFraction<T> operator-(const ProperFraction<T>& rpf)
	{
		ProperFraction<T> result;

		if (this->denominator == rpf.denominator)
		{
			result.denominator = this->denominator;
			result.numerator = this->numerator - rpf.numerator;
		}
		else
		{
			result.denominator = this->denominator * rpf.denominator;
			result.numerator = (this->numerator * rpf.denominator) - (rpf.numerator * this->denominator);
		}

		return result;
	}

	ProperFraction<T> operator*(const ProperFraction<T>& rpf)
	{
		ProperFraction<T> result;

		result.denominator = this->denominator * rpf.denominator;
		result.numerator = this->numerator * rpf.numerator;

		return result;
	}

	static ProperFraction<T> Input()
	{
		T numerator;
		T denominator;

		cout << "Enter denominator for Proper Fraction: ";
		cin >> denominator;

		do 
		{
			cout << "Enter numerator than lesser than denominator: ";
			cin >> numerator;
		} while (numerator >= denominator);

		return ProperFraction<T>(numerator, denominator);
	}

	inline virtual void Show() { cout << this->numerator << "/" << this->denominator; }

	template<typename T>
	friend ostream& operator<<(ostream& os, const ProperFraction<T>& pf);
};

template<typename T>
ostream& operator<<(ostream& os, const ProperFraction<T>& pf)
{
	os << pf.numerator << "/" << pf.denominator;
	return os;
}

template<typename T>
class ArbitraryFraction : ProperFraction<T>
{
public:
	ArbitraryFraction() : ProperFraction<T>()
	{
	}

	ArbitraryFraction(T numerator, T denominator) : ProperFraction<T>(numerator, denominator)
	{
	}

	ArbitraryFraction(const ArbitraryFraction<T>& copy)
	{
		this->numerator = copy.numerator;
		this->denominator = copy.denominator;
	}

	ArbitraryFraction<T> operator+(const ArbitraryFraction<T>& rpf)
	{
		ArbitraryFraction<T> result;

		if (this->denominator == rpf.denominator)
		{
			result.denominator = this->denominator;
			result.numerator = this->numerator + rpf.numerator;
		}
		else
		{
			result.denominator = this->denominator * rpf.denominator;
			result.numerator = (this->numerator * rpf.denominator) + (rpf.numerator * this->denominator);
		}

		return result;
	}

	ArbitraryFraction<T> operator-(const ArbitraryFraction<T>& rpf)
	{
		ArbitraryFraction<T> result;

		if (this->denominator == rpf.denominator)
		{
			result.denominator = this->denominator;
			result.numerator = this->numerator - rpf.numerator;
		}
		else
		{
			result.denominator = this->denominator * rpf.denominator;
			result.numerator = (this->numerator * rpf.denominator) - (rpf.numerator * this->denominator);
		}

		return result;
	}

	ArbitraryFraction<T> operator*(const ArbitraryFraction<T>& rpf)
	{
		ArbitraryFraction<T> result;

		result.denominator = this->denominator * rpf.denominator;
		result.numerator = this->numerator * rpf.numerator;

		return result;
	}

	static ArbitraryFraction<T> Input()
	{
		T numerator;
		T denominator;

		cout << "Enter denominator for Arbitrary Fraction: ";
		cin >> denominator;
		cout << "Enter numerator than lesser than denominator: ";
	    cin >> numerator;
		
		return ArbitraryFraction<T>(numerator, denominator);
	}

	inline void Show() { cout << this->numerator << "/" << this->denominator; }

	template<typename T>
	friend ostream& operator<<(ostream& os, const ArbitraryFraction<T>& af);
};

template<typename T>
ostream& operator<<(ostream& os, const ArbitraryFraction<T>& af)
{
	os << af.numerator << "/" << af.denominator;
	return os;
}

int main()
{
	ProperFraction<int> a(2, 3), b(1, 2);
	ProperFraction<int> d = a;
	ArbitraryFraction<int> q(5, 3), w(6, 2);
	ArbitraryFraction<int> e = q;

	cout << "Proper Fraction:" << "\n";
	cout << "a: ";
	a.Show();
	cout << "\n" << "b: ";
	b.Show();
	cout << "\n" << "copy a: ";
	d.Show();

	cout << "\n\n" << "Arbitrary Fraction:" << "\n";
	cout << "q: ";
	q.Show();
	cout << "\n" << "w: ";
	w.Show();
	cout << "\n" << "copy q: ";
	e.Show();

	cout << "\n\n" << "Proper Fraction:" << "\n";
	cout << "a + b: " << a + b << "\n";
	cout << "a - b: " << a - b << "\n";
	cout << "a * b: " << a * b << "\n";

	cout << "\n"  << "Arbitrary Fraction:" << "\n";
	cout << "q + w: " << q + w << "\n";
	cout << "q - w: " << q - w << "\n";
	cout << "q * w: " << q * w << "\n";

	ProperFraction<int> h = ProperFraction<int>::Input();
	cout << h << "\n";
	ArbitraryFraction<int> f = ArbitraryFraction<int>::Input();
	cout << f << "\n";

	return 0;
}