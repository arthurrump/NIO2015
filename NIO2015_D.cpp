#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Type variabelen
typedef enum { LEEG, WIT, ZWART, MUUR } s;
int speler, tegenstander, ronde;

// Klassen
class Veld
{
public:
	Veld() : speler(LEEG), ID(""), sBoven(LEEG),
		sOnder(LEEG), sRechts(LEEG), sLinks(LEEG)
	{
	}

	string ID;
	int speler;
	int sBoven, sOnder,
		sRechts, sLinks;
};

class Bord
{
public:
	Bord()
	{
		for (char i = 'A'; i <= 'I'; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				ostringstream oss;
				oss << i << j;
				veld[i - 'A'][j - 1].ID = oss.str();
				veld[i - 'A'][j - 1].speler = LEEG;

				veld[i - 'A'][0].sOnder = MUUR;
				veld[i - 'A'][8].sBoven = MUUR;

				veld[0][j - 1].sLinks = MUUR;
				veld[8][j - 1].sRechts = MUUR;
			}
		}
	}

	Veld veld[9][9];
};

class Zet
{
public:
	Zet(int k, int r) :
		kolom(k), rij(r)
	{ }

	int kolom, rij;
};

// Functiedeclaraties
Zet naarZetIntern(string input);
string naarZetExtern(Zet zet);
Zet randomZet(void);
void doeZet(int kleur, Zet zet);
Zet berekenZet(void);

// Klasse variabelen
Zet laatsteZetTegenstander(0, 0),
	laatsteZetSpeler(0, 0);
Bord speelbord;

int main()
{
	cerr << "NIO2015_D: CaptureGo" << endl << "© Arthur Rump, 2014 - 2015" << endl;

	string input;

	cin >> input;
	cerr << "input: " << input << endl;

	if (input == "Start")
	{
		speler = WIT;
		tegenstander = ZWART;
		cerr << "WIT" << endl;
		doeZet(speler, Zet(4, 4));

		while (true)
		{
			cin >> input;
			cerr << "input: " << input << endl;
			if (input == "Quit")
			{
				cerr << "quit" << endl;
				return 0;
			}

			doeZet(tegenstander, naarZetIntern(input));
			doeZet(speler, berekenZet());
		}
	}
	else
	{
		speler = ZWART;
		tegenstander = WIT;
		cerr << "ZWART" << endl;

		doeZet(tegenstander, naarZetIntern(input));
		doeZet(speler, Zet(4, 4));

		while (true)
		{
			cin >> input;
			cerr << "input: " << input << endl;
			if (input == "Quit")
			{
				cerr << "quit" << endl;
				return 0;
			}

			doeZet(tegenstander, naarZetIntern(input));
			doeZet(speler, berekenZet());
		}
	}

	cin.get();
	cin.get();
	return 0;
}

// Functies
Zet naarZetIntern(string input)
{
	return Zet(input[0] - 'A', input[1] - '1');
}

string naarZetExtern(Zet zet)
{
	ostringstream oss;
	char kolomCh = zet.kolom + 'A';
	char rijCh = zet.rij + '1';
	oss << kolomCh << rijCh;
	return oss.str();
}

void doeZet(int kleur, Zet zet)
{
	ronde++;

	if (speelbord.veld[zet.kolom][zet.rij].speler != LEEG)
		zet = randomZet();

	speelbord.veld[zet.kolom][zet.rij].speler = kleur;

	if (zet.rij - 1 > 0)
		speelbord.veld[zet.kolom][zet.rij - 1].sBoven = kleur;
	if (zet.rij + 1 < 8)
		speelbord.veld[zet.kolom][zet.rij + 1].sOnder = kleur;
	if (zet.kolom - 1 > 0)
		speelbord.veld[zet.kolom - 1][zet.rij].sRechts = kleur;
	if (zet.kolom + 1 < 8)
		speelbord.veld[zet.kolom + 1][zet.rij].sLinks = kleur;

	if (kleur == speler)
	{
		cout << naarZetExtern(zet) << endl;
		cout.flush();
		cerr << "zet: " << naarZetExtern(zet) << endl;
		laatsteZetSpeler = zet;
	}

	if (kleur == tegenstander)
	{
		laatsteZetTegenstander = zet;
		cerr << "tegenzet: " << naarZetExtern(zet) << endl;
	}
}

Zet randomZet(void)
{
	cerr << "random ";

	int kolom, rij;
	do
	{
		kolom = rand() % 8 + 1;
		rij = rand() % 8 + 1;
	} while (speelbord.veld[kolom][rij].speler != LEEG);

	return Zet(kolom, rij);
}

Zet berekenZet(void)
{
	cerr << "berekenen" << endl;

	// Controleer elk vakje of er iemand bijna af is
	for (char i = 'A'; i <= 'I'; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			Veld v = speelbord.veld[i - 'A'][j - 1];

			// Tegenspeler bijna af (met 1 steen)
			if (v.speler == tegenstander &&
				(v.sBoven == speler || v.sBoven == MUUR) && (v.sLinks == speler || v.sLinks == MUUR) &&
				(v.sRechts == speler || v.sRechts == MUUR) && v.sOnder != tegenstander)
			{
				cerr << "tegenstander bijna omringd blr, veld: " << v.ID << " -> ";
				return Zet(naarZetIntern(v.ID).kolom, naarZetIntern(v.ID).rij - 1);
			}

			if (v.speler == tegenstander &&
				(v.sLinks == speler || v.sLinks == MUUR) && (v.sRechts == speler || v.sRechts == MUUR) && 
				(v.sOnder == speler || v.sOnder == MUUR) && v.sBoven != tegenstander)
			{
				cerr << "tegenstander bijna omringd lro, veld: " << v.ID << " -> ";
				return Zet(naarZetIntern(v.ID).kolom, naarZetIntern(v.ID).rij + 1);
			}

			if (v.speler == tegenstander &&
				(v.sRechts == speler || v.sRechts == MUUR) && (v.sOnder == speler || v.sOnder == MUUR) && 
				(v.sBoven == speler || v.sBoven == MUUR) && v.sLinks != tegenstander)
			{
				cerr << "tegenstander bijna omringd rob, veld: " << v.ID << " -> ";
				return Zet(naarZetIntern(v.ID).kolom - 1, naarZetIntern(v.ID).rij);
			}

			if (v.speler == tegenstander &&
				(v.sOnder == speler || v.sOnder == MUUR) && (v.sBoven == speler || v.sBoven == MUUR) && 
				(v.sLinks == speler || v.sLinks == MUUR) && v.sRechts != tegenstander)
			{
				cerr << "tegenstander bijna omringd obl, veld: " << v.ID << " -> ";
				return Zet(naarZetIntern(v.ID).kolom + 1, naarZetIntern(v.ID).rij);
			}

			// Zelf bijna af (met 1 steen)
			if (v.speler == speler &&
				(v.sBoven == tegenstander || v.sBoven == MUUR) && (v.sLinks == tegenstander || v.sLinks == MUUR) &&
				(v.sRechts == tegenstander || v.sRechts == MUUR) && v.sOnder != speler)
			{
				cerr << "zelf bijna omringd blr, veld: " << v.ID << " -> ";
				return Zet(naarZetIntern(v.ID).kolom, naarZetIntern(v.ID).rij - 1);
			}

			if (v.speler == speler &&
				(v.sLinks == tegenstander || v.sLinks == MUUR) && (v.sRechts == tegenstander || v.sRechts == MUUR) && 
				(v.sOnder == tegenstander || v.sOnder == MUUR) && v.sBoven != speler)
			{
				cerr << "zelf bijna omringd lro, veld: " << v.ID << " -> ";
				return Zet(naarZetIntern(v.ID).kolom, naarZetIntern(v.ID).rij + 1);
			}

			if (v.speler == speler &&
				(v.sRechts == tegenstander || v.sRechts == MUUR) && (v.sOnder == tegenstander || v.sOnder == MUUR) &&
				(v.sBoven == tegenstander || v.sBoven == MUUR) && v.sLinks != speler)
			{
				cerr << "zelf bijna omringd rob, veld: " << v.ID << " -> ";
				return Zet(naarZetIntern(v.ID).kolom - 1, naarZetIntern(v.ID).rij);
			}

			if (v.speler == speler &&
				(v.sOnder == tegenstander || v.sOnder == MUUR) && (v.sBoven == tegenstander || v.sBoven == MUUR) &&
				(v.sLinks == tegenstander || v.sLinks == MUUR) && v.sRechts != speler)
			{
				cerr << "zelf bijna omringd obl, veld: " << v.ID << " -> ";
				return Zet(naarZetIntern(v.ID).kolom + 1, naarZetIntern(v.ID).rij);
			}
		}
	}

	// Zet (direct) boven, onder, links, rechts van eigen laatste zet, maar alleen 
	// als dan niet (bijna) ingesloten door tegenstander
	if (speelbord.veld[laatsteZetSpeler.kolom][laatsteZetSpeler.rij].sBoven == LEEG ||
		speelbord.veld[laatsteZetSpeler.kolom][laatsteZetSpeler.rij].sOnder == LEEG ||
		speelbord.veld[laatsteZetSpeler.kolom][laatsteZetSpeler.rij].sLinks == LEEG ||
		speelbord.veld[laatsteZetSpeler.kolom][laatsteZetSpeler.rij].sRechts == LEEG)
	{
		cerr << "een van direct naast eigen vrij" << endl;

		bool nul = true, een = true, twee = true, drie = true;

		while (true)
		{
			cerr << "naast eigen while-loop" << endl;

			switch (rand() % 4)
			{
			case 0:
				if (laatsteZetSpeler.rij + 1 <= 7 &&
					speelbord.veld[laatsteZetSpeler.kolom][laatsteZetSpeler.rij + 1].speler == LEEG)
				{
					Veld v = speelbord.veld[laatsteZetSpeler.kolom][laatsteZetSpeler.rij + 1];

					if (!((v.sBoven == tegenstander && v.sOnder == tegenstander && v.sLinks == tegenstander) ||
						(v.sOnder == tegenstander && v.sLinks == tegenstander && v.sRechts == tegenstander) ||
						(v.sLinks == tegenstander && v.sRechts == tegenstander && v.sBoven == tegenstander) ||
						(v.sRechts == tegenstander && v.sBoven == tegenstander && v.sOnder == tegenstander)))
					{
						cerr << "boven ";
						return Zet(laatsteZetSpeler.kolom, laatsteZetSpeler.rij + 1);
					}
				}
				nul = false;
				break;

			case 1:
				if (laatsteZetSpeler.rij - 1 >= 1 &&
					speelbord.veld[laatsteZetSpeler.kolom][laatsteZetSpeler.rij - 1].speler == LEEG)
				{
					Veld v = speelbord.veld[laatsteZetSpeler.kolom][laatsteZetSpeler.rij - 1];

					if (!((v.sBoven == tegenstander && v.sOnder == tegenstander && v.sLinks == tegenstander) ||
						(v.sOnder == tegenstander && v.sLinks == tegenstander && v.sRechts == tegenstander) ||
						(v.sLinks == tegenstander && v.sRechts == tegenstander && v.sBoven == tegenstander) ||
						(v.sRechts == tegenstander && v.sBoven == tegenstander && v.sOnder == tegenstander)))
					{
						cerr << "onder ";
						return Zet(laatsteZetSpeler.kolom, laatsteZetSpeler.rij - 1);
					}
				}
				een = false;
				break;

			case 2:
				if (laatsteZetSpeler.kolom - 1 >= 0 &&
					speelbord.veld[laatsteZetSpeler.kolom - 1][laatsteZetSpeler.rij].speler == LEEG)
				{
					Veld v = speelbord.veld[laatsteZetSpeler.kolom - 1][laatsteZetSpeler.rij];

					if (!((v.sBoven == tegenstander && v.sOnder == tegenstander && v.sLinks == tegenstander) ||
						(v.sOnder == tegenstander && v.sLinks == tegenstander && v.sRechts == tegenstander) ||
						(v.sLinks == tegenstander && v.sRechts == tegenstander && v.sBoven == tegenstander) ||
						(v.sRechts == tegenstander && v.sBoven == tegenstander && v.sOnder == tegenstander)))
					{
						cerr << "links ";
						return Zet(laatsteZetSpeler.kolom - 1, laatsteZetSpeler.rij);
					}
				}
				twee = false;
				break;

			case 3:
				if (laatsteZetSpeler.kolom + 1 <= 8 &&
					speelbord.veld[laatsteZetSpeler.kolom + 1][laatsteZetSpeler.rij].speler == LEEG)
				{
					Veld v = speelbord.veld[laatsteZetSpeler.kolom + 1][laatsteZetSpeler.rij];

					if (!((v.sBoven == tegenstander && v.sOnder == tegenstander && v.sLinks == tegenstander) ||
						(v.sOnder == tegenstander && v.sLinks == tegenstander && v.sRechts == tegenstander) ||
						(v.sLinks == tegenstander && v.sRechts == tegenstander && v.sBoven == tegenstander) ||
						(v.sRechts == tegenstander && v.sBoven == tegenstander && v.sOnder == tegenstander)))
					{
						cerr << "rechts ";
						return Zet(laatsteZetSpeler.kolom + 1, laatsteZetSpeler.rij);
					}
				}
				drie = false;
				break;
			}

			if (nul == false && een == false && twee == false && drie == false)
			{
				cerr << "overal naast eigen laatste (bijna) ingesloten" << endl;
				goto naastVorigeTegenstander;
			}
		}
	}

	naastVorigeTegenstander:
	// Zet boven, onder, links, rechts van tegenstanders laatste zet, daarna 1 verderweg enz, maar alleen 
	// als dan niet (bijna) ingesloten door tegenstander
	for (int i = 1; i < 9; i++)
	{
		cerr << i << " naast vorige van tegenstander" << endl;

		if (laatsteZetTegenstander.rij + i <= 8 &&
			speelbord.veld[laatsteZetTegenstander.kolom][laatsteZetTegenstander.rij + i].speler == LEEG)
		{
			Veld v = speelbord.veld[laatsteZetTegenstander.kolom][laatsteZetTegenstander.rij + i];

			if (((v.sBoven == tegenstander && v.sOnder == tegenstander && v.sLinks == tegenstander) ||
				(v.sOnder == tegenstander && v.sLinks == tegenstander && v.sRechts == tegenstander) ||
				(v.sLinks == tegenstander && v.sRechts == tegenstander && v.sBoven == tegenstander) ||
				(v.sRechts == tegenstander && v.sBoven == tegenstander && v.sOnder == tegenstander)) != true)
			{
				cerr << "boven ";
				return Zet(laatsteZetTegenstander.kolom, laatsteZetTegenstander.rij + i);
			}
		}

		if (laatsteZetTegenstander.rij - i >= 0 &&
			speelbord.veld[laatsteZetTegenstander.kolom][laatsteZetTegenstander.rij - i].speler == LEEG)
		{
			Veld v = speelbord.veld[laatsteZetTegenstander.kolom][laatsteZetTegenstander.rij - i];

			if (((v.sBoven == tegenstander && v.sOnder == tegenstander && v.sLinks == tegenstander) ||
				(v.sOnder == tegenstander && v.sLinks == tegenstander && v.sRechts == tegenstander) ||
				(v.sLinks == tegenstander && v.sRechts == tegenstander && v.sBoven == tegenstander) ||
				(v.sRechts == tegenstander && v.sBoven == tegenstander && v.sOnder == tegenstander)) != true)
			{
				cerr << "onder ";
				return Zet(laatsteZetTegenstander.kolom, laatsteZetTegenstander.rij - i);
			}
		}

		if (laatsteZetTegenstander.kolom - i >= 0 &&
			speelbord.veld[laatsteZetTegenstander.kolom - i][laatsteZetTegenstander.rij].speler == LEEG)
		{
			Veld v = speelbord.veld[laatsteZetTegenstander.kolom - i][laatsteZetTegenstander.rij];

			if (((v.sBoven == tegenstander && v.sOnder == tegenstander && v.sLinks == tegenstander) ||
				(v.sOnder == tegenstander && v.sLinks == tegenstander && v.sRechts == tegenstander) ||
				(v.sLinks == tegenstander && v.sRechts == tegenstander && v.sBoven == tegenstander) ||
				(v.sRechts == tegenstander && v.sBoven == tegenstander && v.sOnder == tegenstander)) != true)
			{
				cerr << "links ";
				return Zet(laatsteZetTegenstander.kolom - i, laatsteZetTegenstander.rij);
			}
		}

		if (laatsteZetTegenstander.kolom + i <= 8 &&
			speelbord.veld[laatsteZetTegenstander.kolom + i][laatsteZetTegenstander.rij].speler == LEEG)
		{
			Veld v = speelbord.veld[laatsteZetTegenstander.kolom + i][laatsteZetTegenstander.rij];

			if (((v.sBoven == tegenstander && v.sOnder == tegenstander && v.sLinks == tegenstander) ||
				(v.sOnder == tegenstander && v.sLinks == tegenstander && v.sRechts == tegenstander) ||
				(v.sLinks == tegenstander && v.sRechts == tegenstander && v.sBoven == tegenstander) ||
				(v.sRechts == tegenstander && v.sBoven == tegenstander && v.sOnder == tegenstander)) != true)
			{
				cerr << "rechts ";
				return Zet(laatsteZetTegenstander.kolom + i, laatsteZetTegenstander.rij);
			}
		}
	}

	cerr << "geen van alles mogelijk" << endl;
	return randomZet();
}