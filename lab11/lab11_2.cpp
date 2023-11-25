#include<iostream>
#include<vector>

using namespace std;

template<typename T>
vector<vector<T>> matrixOperations(vector<vector<T>>& matx1, vector<vector<T>>& matx2, char operation)
{
	vector<vector<T>> result(matx1.size(), vector<int>(matx1[0].size(), 0));

	if (matx1.size() == matx2.size() && matx1[0].size() == matx2[0].size())
	{
		for (int i = 0; i < matx1.size(); i++)
		{
			for (int j = 0; j < matx1[0].size(); j++)
			{
				switch (operation)
				{
				case '1':
					result[i][j] = matx1[i][j] + matx2[i][j];
					break;

				case '2':
					result[i][j] = matx1[i][j] - matx2[i][j];
					break;
				}
			}
		}
	}
	else
		cout << "We cannot work with this matrix. please change it first\n";

	return result;
}

int main()
{
	vector<vector<int>> matx1 =
	{
		{1, 2, 3},
		{3, 2, 1},
		{2, 1, 3}
	};

	vector<vector<int>> matx2 =
	{
		{4, 5, 9},
		{8, 7, 5},
		{9, 4, 6}
	};

	vector<vector<int>> matx3;
	char opt = ' ';
	do
	{
		cout << "Choose operation(1 - Add, 2 - Sub, 0 - quit): ";
		cin >> opt;

		matx3 = matrixOperations(matx1, matx2, opt);

		cout << "Show result:\n";
		for (vector<int> arr : matx3)
		{
			for (int el : arr)
				cout << el << " ";
			cout << '\n';
		}
		cout << '\n';
	} while (opt != '0');

	return 0;
}