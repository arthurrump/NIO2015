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
#include <vector>

using namespace std;

class Kandidaat
{
public:
	Kandidaat(int id) : ID(id), stemmenVoor(0), afgevallen(false)
	{
	}

	int ID;
	int stemmenVoor;
	bool afgevallen;
};

class Deelnemer
{
public:
	Deelnemer(int id) : ID(id)
	{
	}

	int ID;
	vector<int> stemmen;
};

int main()
{
	int aantalKandidatenK, aantalDeelnemersD;
	vector<Deelnemer> deelnemersD;
	vector<Kandidaat> kandidatenK;

	cin >> aantalKandidatenK;
	cin >> aantalDeelnemersD;

	for (int d = 0; d < aantalDeelnemersD; d++)
	{
		Deelnemer deelnemer(d+1);

		for (int s = 0; s < aantalKandidatenK - 1; s++)
		{
			string x;
			getline(cin, x, ' ');
			deelnemer.stemmen.push_back(stoi(x));
		}

		string x;
		getline(cin, x);
		deelnemer.stemmen.push_back(stoi(x));

		deelnemersD.push_back(deelnemer);
	}

	for (int k = 0; k < aantalKandidatenK; k++)
	{
		kandidatenK.push_back(Kandidaat(k+1));
	}

	NieuweRonde:
	for (Deelnemer d : deelnemersD)
	{
		int voorkeurNo = 0;

		for (int k : d.stemmen)
		{
			if (kandidatenK[k-1].afgevallen == false)
			{
				voorkeurNo = k;
				goto Stemmen;
			}
		}

		Stemmen:
		kandidatenK[voorkeurNo-1].stemmenVoor++;
	}

	for (Kandidaat k : kandidatenK)
	{
		if (k.stemmenVoor > (static_cast<double>(aantalDeelnemersD) / 2))
		{
			cout << k.ID << endl;

			cin.get();
			return 0;
		}
	}

	int kleinste = kandidatenK[0].stemmenVoor;
	int kleinsteID = 0;

	for (Kandidaat k2 : kandidatenK)
	{
		if (k2.stemmenVoor <= kleinste && k2.afgevallen == false)
		{
			kleinste = k2.stemmenVoor;
			kleinsteID = k2.ID;
		}
	}

	kandidatenK[kleinsteID - 1].afgevallen = true;

	for (int k = 0; k < aantalKandidatenK; k++)
		kandidatenK[k].stemmenVoor = 0;

	goto NieuweRonde;

	cin.get();
	return 0;
}