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
#include <algorithm>

using namespace std;

int main()
{
	int waslijnLengte = 0, aantalKleding = 0, laatsteIndex = 0, lengteOver = 0,
		aantalLijnen = 0;
	vector<int> kledingLengtes;

	std::cin >> waslijnLengte;
	std::cin >> aantalKleding;

	for (int i = 0; i < aantalKleding; i++)
	{
		int buf;
		std::cin >> buf;
		kledingLengtes.push_back(buf);
	}

	laatsteIndex = kledingLengtes.size() - 1;
	lengteOver = waslijnLengte;

	sort(kledingLengtes.begin(), kledingLengtes.end());
	reverse(kledingLengtes.begin(), kledingLengtes.end());

	while (kledingLengtes.empty() == false)
	{
		for (unsigned int i = 0; i < kledingLengtes.size(); i++)
		{
			if (kledingLengtes[i] <= lengteOver)
			{
				lengteOver -= kledingLengtes[i];
				vector<int>::iterator pos = kledingLengtes.begin() + i;
				kledingLengtes.erase(pos);
				goto kledingPast;
			}
		}

		aantalLijnen++;
		lengteOver = waslijnLengte;

	kledingPast:;
	}

	std::cout << aantalLijnen;

	std::cin.get();
	std::cin.get();
	return 0;
}