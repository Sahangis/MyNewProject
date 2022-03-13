#include <iostream>
#include <iomanip>
#include <time.h>
#include <algorithm>
#include "funkcijos.h"

int main()
{
	
	string answer;

	do {
		cout << "ar norite ivesti visas reiksmes pats ? (y/n/s), n atveju: programa pati sugeneruos visus duomenis, o s atveju programa skaitys duomenis is failo" << endl;
		cin >> answer;
		if (answer != "y" and answer != "n" and answer != "s") cout << "ivesta netinkama reiksme, prasome ivesti vel " << endl;
	} while (answer != "y" and answer != "n" and answer !="s");
	if (answer == "n")
	{
		srand(time(NULL));
		int n = (double)rand() / RAND_MAX * 10;
		do {
			n = (double)rand() / RAND_MAX * 10;
		} while (n == 0);
		string ans = "v";
		int r = (double)rand() / RAND_MAX * 10;
		if (r > 5) ans = "m";
		vector<dat> a;
		for (int i = 0; i < n; i++) a.push_back(generavimas());
		sort(a.begin(), a.end(), [](const dat& a, const dat& b)
			{
				return a.vardas < b.vardas;
			});
		rasymas(a);
	}
	else if (answer == "y")
	{
		int n;
		do {
			cout << "iveskite kiek mokiniu bus vedami duomenys (n>0)" << endl;
			cin >> n;
			if (!n) cout << "ivesta netinkama reiksme, prasome ivesti vel" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			if (n)
			{
				if (n < 0)
				{
					cout << "ivesta netinkama reiksme, prasome ivesti vel" << endl;
					n = !n;
				}
			}
		} while (!n);
		vector<dat> a;
		for (int i = 0; i < n; i++) a.push_back(input(i + 1));
		sort(a.begin(), a.end(), [](const dat& a, const dat& b)
			{
				return a.vardas < b.vardas;
			});
		rasymas(a);
	}
	else if(answer == "s")
	{
		vector<dat> a;
		const char DF[] = "kursiokai.txt";
		ifstream fd;
		fd.exceptions(ifstream::failbit | ifstream::badbit);
		try
		{
			fd.open(DF);
			string filler;
			int pazymiai = 0;
			fd >> filler;
			fd >> filler;
			do {
				fd >> filler;
				if (filler[0] == 'N') pazymiai++;
			} while (filler[0] == 'N');
			while (!fd.eof()) a.push_back(skaitymas(pazymiai, fd));
			a.pop_back();
			fd.close();
		}
		catch (ifstream::failure e){
			cout<<e.what()<<endl;
			exit(-1);
		}
		sort(a.begin(), a.end(), [](const dat& a, const dat& b)
			{
				return a.vardas < b.vardas;
			});
		rasymas(a);
	}
	system("PAUSE");
	return 0;
}
