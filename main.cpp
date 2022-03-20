#include <time.h>
#include "funkcijos.h"


int main()
{
	
	string answer, ats;
	do {
		cout << "ar norite kruti rezultatu faila ? {0} ar norite generuoti 5 duomenu failus ? {1}"<<endl;
		cin >> ats;
		if (ats != "1" and ats != "0") cout << "ivesta reiksme netinkama, prasome ivesti vel" << endl;
	} while (ats!="1" and ats!="0");
	if (ats == "0")
	{
		do	{
			cout << "ar norite ivesti visas reiksmes pats ? (y/s), s atveju programa skaitys duomenis is failo" << endl;
			cin >> answer;
			if (answer != "y" and answer != "s") cout << "ivesta netinkama reiksme, prasome ivesti vel " << endl;
		} while (answer != "y" and answer !="s");
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
			sort(a.begin(), a.end(), [](const dat& a, const dat& b)
				{
					return a.vardas < b.vardas;
				});
			rasymas(a);
		}
		else if(answer == "s")
		{
			string ax;
			vector<dat> poor;
			vector<dat> cool;
			const char DF[5][22] = { "kursiokai1000.txt", "kursiokai10000.txt", "kursiokai100000.txt", "kursiokai1000000.txt", "kursiokai10000000.txt" };
			do {
				cout << "iveskite kiek duomenu faila norite skaityti? {1}=1000, {2}=10000, {3}=100000, {4}=1000000, {5}=10000000" << endl;
				cin >> ax;
				if (ax != "1" and ax != "2" and ax != "3" and ax != "4" and ax != "5") cout << "ivesta reiksme nera tinkama, prasome ivesti vel" << endl;
			} while (ax != "1" and ax != "2" and ax != "3" and ax != "4" and ax != "5");
			auto start = std::chrono::high_resolution_clock::now();
			ifstream fd;
			try
			{
				auto read_start = std::chrono::high_resolution_clock::now();
				cout << DF[std::stoi(ax) - 1 ]<< endl;
				fd.open(DF[std::stoi(ax)-1]);
				string filler;
				int pazymiai = 0;
				fd >> filler;
				fd >> filler;
				do {
					fd >> filler;
					if (filler[0] == 'N') pazymiai++;
				} while (filler[0] == 'N');
				auto sort_start = std::chrono::high_resolution_clock::now();
				while (!fd.eof())
				{
					dat temp = skaitymas(pazymiai, fd);
					if (temp.answer >= 5) cool.push_back(temp);
					else poor.push_back(temp);
				}
				poor.pop_back();
				auto sort_end = std::chrono::high_resolution_clock::now();
				//a.pop_back();
				auto read_end = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> read_diff = read_end - read_start;
				std::cout << "Failo nuskaitymas tesiai i eiluciu vektoriu uztruko: " << read_diff.count() << " s\n";
				fd.close();
				std::chrono::duration<double> sort_diff = sort_end - sort_start;
				std::cout << "Duomenu isskyrimas i du atskirus kieteku, ir vargsiuku vektorius uztruko: " << sort_diff.count() << " s\n";
			}
			catch (ifstream::failure e){
				cout<<e.what()<<endl;
				exit(-1);
			}
			auto poor_start = std::chrono::high_resolution_clock::now();
			sort(poor.begin(), poor.end(), [](const dat& a, const dat& b)
			{
				return a.answer > b.answer;
			});
			rasymas_s(poor, "vargsiukai.txt");
			auto poor_end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> poor_diff = poor_end - poor_start;
			std::cout << "vargsiuku rikiavimas ir isvedimas uztruko: " << poor_diff.count() << " s\n";
			auto cool_start = std::chrono::high_resolution_clock::now();
			sort(cool.begin(), cool.end(), [](const dat& a, const dat& b)
				{
					return a.answer > b.answer;
				});
			rasymas_s(cool, "kietekai.txt");
			auto cool_end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> cool_diff = cool_end - cool_start;
			std::cout << "kieteku rikiavimas ir isvedimas uztruko: " << cool_diff.count() << " s\n";
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> diff = end - start;
			std::cout << "Visos programos darbo laikas dirbant su " << DF[std::stoi(ax) - 1] << ": " << diff.count() << " s\n";
		}
	}
	else if (ats == "1")
	{
		int quantity;
		const char RF[5][22] = { "kursiokai1000.txt", "kursiokai10000.txt", "kursiokai100000.txt", "kursiokai1000000.txt", "kursiokai10000000.txt"};
		srand(time(NULL));
		for (int i = 0; i < 5; i++)
		{
			string output="";
			ofstream fr(RF[i]);
			vector<dat> a;
			do {
				quantity = (double)rand() / RAND_MAX * 10;
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
			cout << "sukurtas: " << RF[i] << endl;
		}	
	}
	system("PAUSE");
	return 0;
}
