#include<iostream>
#include<string>

using namespace std;

class Adult
{
private:
	string name;
	int height;
	double weight;

public:
	Adult(string name = "",	int height = 0,	double weight = 0.0)
	{
		this->name = name;
		this->height = height;
		this->weight = weight;
	}

	inline string GetName() { return this->name; }

	inline int GetHeight() { return this->height; }

	inline double GetWeight() { return this->weight; }

	void BMI()
	{
		double bmi = (this->weight * 1000) / this->height;

		if (bmi < 280)
			cout << this->name << " BMI less than normal" << "\n";
		else if (bmi <= 350)
			cout << this->name << " BMI normal" << "\n";
		else if (bmi > 350)
			cout << this->name << " BMI more than normal" << "\n";
		else
			cout << this->name << " ain't no way" << "\n";
	}

	friend void friendBMI(const Adult& obj);
};

void friendBMI(const Adult& obj)
{
	double bmi = (obj.weight * 1000) / obj.height;

	if (bmi < 280)
		cout << obj.name << " BMI less than normal" << "\n";
	else if (bmi <= 350)
		cout << obj.name << " BMI normal" << "\n";
	else if (bmi > 350)
		cout << obj.name << " BMI more than normal" << "\n";
	else
		cout << obj.name << " ain't no way" << "\n";
}

int main()
{
	Adult anna("Anna", 160, 54), igor("Igor", 183, 73), vlad("Vlad", 180, 50);

	anna.BMI();
	friendBMI(igor);
	vlad.BMI();

	return 0;
}