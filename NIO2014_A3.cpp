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