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
#include <string>
#include <set>
#include <vector>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	cout << s.length() << endl;
	
	string::iterator pos;
	vector<char> charsVec;

	int upperCaseCount = 0;

	for (pos = s.begin(); pos != s.end(); ++pos)
	{
		if (*pos >= 65 && *pos <= 90)
		{
			upperCaseCount++;
		}
		charsVec.push_back(*pos);
	}

	cout << upperCaseCount << endl;

	set<char> uniqueCharsSet;
	for (pos = s.begin(); pos != s.end(); ++pos)
	{
		uniqueCharsSet.insert(*pos);
	}
	cout << uniqueCharsSet.size() << endl;


	for (int i = charsVec.size() - 1; i >= 0; i--)
		cout << charsVec[i];

	cout << endl;
	
	cin.get();
	return 0;
}