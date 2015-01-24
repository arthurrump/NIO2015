/**************************************************************************
   Copyright 2015 Arthur Rump

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**************************************************************************/

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