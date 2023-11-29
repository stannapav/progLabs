#include<iostream>
#include<string>
#include<vector>
#include <fstream>

using namespace std;

class Ingredient
{
private:
	string name;
	string measurement;
	double quantity;
	double price;

public:
	Ingredient(string name = "", string measurement = "", double quantity = 0.0, double price = 0.0)
	{
		this->name = name;
		this->measurement = measurement;
		this->quantity = quantity;
		this->price = price;
	}

	inline string GetName() { return this->name; }

	inline string GetMeasurement() { return this->measurement; }

	inline double GetQuantity() { return this->quantity; }

	inline double GetPrice() { return this->price; }

	string Info()
	{
		return this->name + " " + to_string(this->quantity) + " " + this->measurement + " (price: " + to_string(this->price) + ")";
	}
};

class Recipe
{
private:
	string name;
	vector<Ingredient>* ingredients;

public:
	Recipe(string name = "")
	{
		this->name = name;
		this->ingredients = new vector<Ingredient>;
	}

	inline void AddIngredient(Ingredient ingredient) { this->ingredients->push_back(ingredient); }

	inline string GetName() { return this->name; }

	inline vector<Ingredient>* GetIngredients() { return this->ingredients; }

	double TotalPrice()
	{
		double total = 0.0;

		for (int i = 0; i < this->ingredients->size(); i++)
			total += this->ingredients->at(i).GetPrice();

		return total;
	}

	string StrRecipe()
	{
		string allIngrediens = "";

		for (int i = 0; i < this->ingredients->size(); i++)
			allIngrediens += this->ingredients->at(i).Info() + "\n";

		return "Recipe for " + this->name + ":\n" + allIngrediens + "Total price: " + to_string(TotalPrice());
	}

	~Recipe()
	{
		ofstream MyFile(this->name + ".txt");

		MyFile << StrRecipe();

		MyFile.close();
		delete this->ingredients;
	}
};

int main()
{
	Ingredient butter("unsalted butter", "tablespoon", 4, 2.5);

	{
		Recipe chocolateCupcake("Chocolate cupcake");

		chocolateCupcake.AddIngredient(butter);
		chocolateCupcake.AddIngredient(Ingredient("vegetable oil", "cup", 0.25, 5));
		chocolateCupcake.AddIngredient(Ingredient("water", "cup", 0.5, 0));
		chocolateCupcake.AddIngredient(Ingredient("all-purpose flour", "cup", 1, 10));
		chocolateCupcake.AddIngredient(Ingredient("cocoa powder", "cup", 0.30, 7));
		chocolateCupcake.AddIngredient(Ingredient("baking soda", "teaspoon", 3 / 4, 9.7));
		chocolateCupcake.AddIngredient(Ingredient("kosher salt", "teaspoon", 1 / 8, 11.2));
		chocolateCupcake.AddIngredient(Ingredient("egg", "item", 1, 17));
		chocolateCupcake.AddIngredient(Ingredient("buttermilk", "cup", 0.25, 20));
		chocolateCupcake.AddIngredient(Ingredient("pure vanilla extract", "teaspoon", 1, 13));

		cout << chocolateCupcake.StrRecipe();
	}

	cout << "\n\nStill exists: " << butter.Info();

	return 0;
}