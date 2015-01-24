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

using namespace std;

int main()
{
	string diagram[4][4];
	int hor02 = 0, hor03 = 0, hor04 = 0, hor12 = 0, hor13 = 0, hor14 = 0;
	int ver02 = 0, ver03 = 0, ver04 = 0, ver12 = 0, ver13 = 0, ver14 = 0;

	for (int i = 0; i < 4; i++)
	{
		string x = "";
		cin >> x;

		for (int j = 0; j < 4; j++)
			diagram[i][j] = x.substr(j, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		// 0
		if (diagram[i][0] == diagram[i][1] && diagram[i][0] == "0")
		{
			if (diagram[i][1] == diagram[i][2])
			{
				if (diagram[i][2] == diagram[i][3])
				{
					hor04++;
				}
				else
				{
					hor03++;
				}
			}
			else
			{
				hor02++;
			}
		}
		else
		{
			if (diagram[i][1] == diagram[i][2] && diagram[i][1] == "0")
			{
				if (diagram[i][2] == diagram[i][3])
				{
					hor03++;
				}
				else
				{
					hor02++;
				}
			}
			else
			{
				if (diagram[i][2] == diagram[i][3] && diagram[i][2] == "0")
				{
					hor02++;
				}
			}
		}

		// 1
		if (diagram[i][0] == diagram[i][1] && diagram[i][0] == "1")
		{
			if (diagram[i][1] == diagram[i][2])
			{
				if (diagram[i][2] == diagram[i][3])
				{
					hor14++;
				}
				else
				{
					hor13++;
				}
			}
			else
			{
				hor12++;
			}
		}
		else
		{
			if (diagram[i][1] == diagram[i][2] && diagram[i][1] == "1")
			{
				if (diagram[i][2] == diagram[i][3])
				{
					hor13++;
				}
				else
				{
					hor12++;
				}
			}
			else
			{
				if (diagram[i][2] == diagram[i][3] && diagram[i][2] == "1")
				{
					hor12++;
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		// 0
		if (diagram[0][i] == diagram[1][i] && diagram[0][i] == "0")
		{
			if (diagram[1][i] == diagram[2][i])
			{
				if (diagram[2][i] == diagram[3][i])
				{
					hor04++;
				}
				else
				{
					hor03++;
				}
			}
			else
			{
				hor02++;
			}
		}
		else
		{
			if (diagram[1][i] == diagram[2][i] && diagram[1][i] == "0")
			{
				if (diagram[2][i] == diagram[3][i])
				{
					hor03++;
				}
				else
				{
					hor02++;
				}
			}
			else
			{
				if (diagram[2][i] == diagram[3][i] && diagram[2][i] == "0")
				{
					hor02++;
				}
			}
		}

		// 1
		if (diagram[0][i] == diagram[1][i] && diagram[0][i] == "1")
		{
			if (diagram[1][i] == diagram[2][i])
			{
				if (diagram[2][i] == diagram[3][i])
				{
					hor14++;
				}
				else
				{
					hor13++;
				}
			}
			else
			{
				hor12++;
			}
		}
		else
		{
			if (diagram[1][i] == diagram[2][i] && diagram[1][i] == "1")
			{
				if (diagram[2][i] == diagram[3][i])
				{
					hor13++;
				}
				else
				{
					hor12++;
				}
			}
			else
			{
				if (diagram[2][i] == diagram[3][i] && diagram[2][i] == "1")
				{
					hor12++;
				}
			}
		}
	}

	cout << hor02 + ver02 << " " << hor12 + ver12 << endl;
	cout << hor03 + ver03 << " " << hor13 + ver13 << endl;
	cout << hor04 + ver04 << " " << hor14 + ver14 << endl;

	cin.get();
	cin.get();
	return 0;
}