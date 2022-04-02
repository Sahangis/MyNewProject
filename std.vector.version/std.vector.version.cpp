#include <time.h>
#include "funkcijos.h"


int main()
{

	string answer, ats;
	do {
		cout << "ar norite kruti rezultatu faila ? {0} ar norite generuoti 5 duomenu failus ? {1} (Duomenys saugomi Vektoriuose)" << endl;
		cin >> ats;
		if (ats != "1" and ats != "0") cout << "ivesta reiksme netinkama, prasome ivesti vel" << endl;
	} while (ats != "1" and ats != "0");
	if (ats == "0")
	{
		do {
			cout << "ar norite ivesti visas reiksmes pats ? (y/s), s atveju programa skaitys visus duomenis is sugeneruotu failu" << endl;
			cin >> answer;
			if (answer != "y" and answer != "s") cout << "ivesta netinkama reiksme, prasome ivesti vel " << endl;
		} while (answer != "y" and answer != "s");
		if (answer == "y")
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
			sort(a.begin(), a.end(), [](const dat& c, const dat& b)
				{
					return c.vardas > b.vardas;
				});
			rasymas(a);
		}
		else if (answer == "s")
		{
			string ax;
			vector<dat> all;
			vector<dat> poor;
			vector<dat> cool;
			const string DF[5] = { "kursiokai1000.txt", "kursiokai10000.txt", "kursiokai100000.txt", "kursiokai1000000.txt", "kursiokai10000000.txt" };
			const string RF[5] = { "kietekai1000.txt", "kietekai10000.txt", "kietekai100000.txt", "kietekai1000000.txt", "kietekai10000000.txt" };
			const string Rf[5] = { "vargsiukai1000.txt", "vargsiukai10000.txt", "vargsiukai100000.txt", "vargsiukai1000000.txt", "vargsiukai10000000.txt" };
			for (int i = 0; i < 5; i++)
			{
				ifstream fd;
				if (!FileExists(DF[i])) fd.exceptions(ifstream::failbit | ifstream::badbit);
				try
				{
					auto read_start = std::chrono::high_resolution_clock::now();
					cout << DF[i] << endl;
					fd.open(DF[i]);
					string filler;
					int pazymiai = 0;
					fd >> filler;
					fd >> filler;
					do {
						fd >> filler;
						if (filler[0] == 'N') pazymiai++;
					} while (filler[0] == 'N');
					while (!fd.eof()) all.push_back(skaitymas(pazymiai, fd));
					all.pop_back();
					auto read_end = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double> read_diff = read_end - read_start;
					std::cout << "Failo nuskaitymas tesiai i vectoriu uztruko: " << read_diff.count() << " s\n";
					fd.close();
					auto sort_start = std::chrono::high_resolution_clock::now();
					sort(all.begin(), all.end(), [](const dat& a, const dat& b)
						{
							return a.answer > b.answer;
						});
					isskyrimas(poor, cool, all);
					auto sort_end = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double> sort_diff = sort_end - sort_start;
					std::cout << "Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: " << sort_diff.count() << " s\n";
				}
				catch (ifstream::failure e) {
					cout << e.what() << endl;
					exit(-1);
				}
				rasymas_s(poor, Rf[i]);
				rasymas_s(cool, RF[i]);
				system("PAUSE");
				all.clear();
				poor.clear();
				cool.clear();
			}

		}
	}
	else if (ats == "1")
	{
		int quantity;
		const string RF[5] = { "kursiokai1000.txt", "kursiokai10000.txt", "kursiokai100000.txt", "kursiokai1000000.txt", "kursiokai10000000.txt" };
		srand(time(NULL));
		for (int i = 0; i < 5; i++)
		{
			auto create_start = std::chrono::high_resolution_clock::now();
			string output = "";
			ofstream fr(RF[i]);
			do {
				quantity = (double)rand() / RAND_MAX * 7;
			} while (quantity == 0);
			output = "Vardas                   Pavarde             ";
			for (int j = 1; j <= quantity; j++)
			{
				string atribute = "ND";
				atribute += to_string(j);
				int length = atribute.length();
				for (int k = 0; k < 10 - length; k++) atribute.insert(0, " ");
				output += atribute;
			}
			output += "      Egz.\n";
			for (int j = 0; j < 1 * pow(10, i); j++)
			{
				for (int k = 0; k < 1000; k++)
				{
					dat dummy = generavimas(quantity);
					outputas(output, dummy, true);
				}
				fr << output;
				output = "";
			}
			fr.close();
			auto create_end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> create_diff = create_end - create_start;
			std::cout << "sukurtas: " << RF[i] << ", kuris uztruko: " << create_diff.count() << " s\n";
		}
	}
	system("PAUSE");
	return 0;
}
