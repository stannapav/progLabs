#include<iostream>
#include<string>

using namespace std;
struct Date
{
    int day;
    int month;
    int year;

    Date(int day = 1, int month = 1, int year = 2023)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    } 

    string Show() { return to_string(day) + "/" + to_string(month) + "/" + to_string(year); }
};

class Service
{
protected:
    string serviceName;
    double price;
    int discount;

public:
    Service(string serviceName = "", double price = 0.0, bool regular = false)
    {
        this->serviceName = serviceName;
        this->price = price;
        this->discount = regular ? 15 : 0;
    }

    virtual void Name()
    {
        cout << "Service name " << serviceName
            << " price is " << price << ((discount == 0 ) ? " no discount price stays the same " : " whit dicount ") 
            << price - (price * discount / 100) << "\n";
    }
};

class Record
{
protected:
    string firstName;
    string lastName;
    int age;
    string gender;
    Date date;

public:
    Record(string firstName = "", string lastName = "", int age = 0, string gender = "", Date date = { 1, 1, 2023 })
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
        this->date = date;
    }

    virtual void Name()
    {
        cout << "Persone: " << firstName << " " << lastName
            << "\nAge: " << age
            << "\nGender: " << gender
            << "\nDate : " << date.Show() << '\n';
    }
};

class FitnessClub : public Service, public Record
{
private:
    string clubName;

public:
    FitnessClub(string clubName = "",
        string firstName = "", string lastName = "", int age = 0, string gender = "", Date date = { 1, 1, 2023 },
        string serviceName = "", double price = 0.0, bool regular = false)
        : Service(serviceName, price, regular), Record(firstName, lastName, age, gender, date)
    {
        this->clubName = clubName;
    }

    void Name()
    {
        cout << "Club name: " << clubName
            << "\nPersone: " << firstName << " " << lastName
            << "\nAge: " << age
            << "\nGender: " << gender
            << "\nDate : " << date.Show()
            << "\nService name :" << serviceName
            << " price is " << price
            << " whit dicount " << price - (price * discount / 100) << "\n";
    }
};

int main()
{
    Date day(31, 10, 2023);
    Service service("Swimming", 175.75, false);
    Record record("Alex", "Smith", 17, "male", day);
    FitnessClub buffCat("BuffCat", "Anna", "Striharchuk", 18, "female", day, "Swimming", 175.75, true);

    service.Name();
    record.Name();

    cout << '\n';

    buffCat.Name();

    return 0;
}