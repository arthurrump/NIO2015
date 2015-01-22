#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int x;
	int sum = 0;
	vector<int> list;

	do
	{
		cin >> x;
		list.push_back(x);
	} while (x != 0);

	for (int i : list)
	{
		if (i % 2 != 0)
			sum += i*i;
	}

	cout << sum;

	cin.get();
	cin.get();
	return 0;
}