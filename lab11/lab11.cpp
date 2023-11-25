#include<iostream>
#include<vector>

using namespace std;

template<typename T>
int countLowerThenEl(vector<T> arr, T el)
{
	int count = 0;

	for (T a : arr)
	{
		if (a < el)
			count++;
	}

	return count;
}

int main() 
{
	vector<int> A = { 1, 4, 76, 2, 8, 69, 100 };
	vector<double> B = { 1.03, 84.5, 12.4, 7.5, 54.7};
	vector<char> C = { 'a', 'b', 'c', 'A', 'B', 'C' };

	cout << "int: " << countLowerThenEl(A, 69) << '\n';
	cout << "double: " << countLowerThenEl(B, 12.4) << '\n';
	cout << "char: " << countLowerThenEl(C, 'a') << '\n';

	return 0;
}