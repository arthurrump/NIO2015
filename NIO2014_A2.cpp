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