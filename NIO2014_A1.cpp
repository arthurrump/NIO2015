#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			cout << "-";
		}

		for (int j = 0; j < 1 + 4 * i; j += 2)
		{
			cout << "*";
		}

		for (int j = 0; j < n - i - 1; j++)
		{
			cout << "-";
		}
		cout << endl;
	}

	for (int i = 0; i < n - 1; i++)
	{
		cout << "-";
	}

	cout << "*";

	for (int i = 0; i < n - 1; i++)
	{
		cout << "-";
	}

	cin.get();
	cin.get();
	return 0;
}