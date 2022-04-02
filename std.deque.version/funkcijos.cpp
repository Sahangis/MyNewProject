#include "funkcijos.h"
#include <random>

string vardai[16] = { "Martynas", "Jonas", "Vilijamas", "Kristijonas", "Vincas", "Alberas", "Francas" , "Juozas", "Jurgis", "Antanas", "Henrikas", "Balys", "Augustas", "Justinas", "Ernestas", "Hansas" };
string pavardes[16] = { "Dauksa", "Radvanas", "Marcinkevicius", "Kafka", "Kamiu", "Kudirka", "Shekspyras", "Donelaitis", "Mickevicius", "Biliunas", "Vaizgantas", "Radauskas", "Krivickas", "Savickis", "Sruoga", "Katiliskis" };


dat input(int i)
{
	dat temp;
	do {
		cout << "iveskite " << i << " -ojo mokinio varda(ilgis ne daugiau 15 simboliu): " << endl;
		cin >> temp.vardas;
		if (temp.vardas.length() >= 16) cout << "ivestas per ilgas vardas, prasome ivesti trumpesni" << endl;
	} while (temp.vardas.length() >= 16);
	do {
		cout << "iveskite " << i << " -ojo mokinio pavarde(ilgis ne daugiau 15 simboliu): " << endl;
		cin >> temp.pavarde;
		if (temp.pavarde.length() >= 16) cout << "ivesta per ilga pavarde, prasome ivesti trumpesne" << endl;
	} while (temp.pavarde.length() >= 16);
	bool inFail;
	int sk;
	deque<int> pazymiai;
	do {
		int j = 0;
		do {
			cout << "iveskite " << j + 1 << " pazimi" << endl;
			cin >> sk;
			inFail = cin.fail();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			if (!inFail)
			{
				if (sk > 10 or sk < 0) inFail = true;
				else pazymiai.push_back(sk);
			}
			j++;
		} while (!inFail);
		if (pazymiai.size() == 0) cout << "Negalime skaiciuoti rezultatu su mokiniu kuris neturi pazymiu, prasome vesti vel" << endl;
	} while (pazymiai.size() == 0);

	do {
		cout << "iveskite egzamino rezultata" << endl;
		cin >> temp.egzaminas;
		inFail = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		if (!inFail) if (temp.egzaminas > 10 or temp.egzaminas < 0) inFail = true;
	} while (inFail);

	int sum = 0;
	for (int j = 0; j < pazymiai.size(); j++) sum += pazymiai[j];
	temp.answer = 0.4 * (sum * 1.0 / pazymiai.size()) + 0.6 * (temp.egzaminas * 1.0);
	pazymiai.clear();
	return temp;
}

dat generavimas(int quantity)
{
	dat temp;
	int index = (double)rand() / RAND_MAX * 15.9;
	temp.vardas = vardai[index];
	int index2 = (double)rand() / RAND_MAX * 15.9;
	temp.pavarde = pavardes[index2];
	int sum = 0;
	for (int i = 0; i < quantity; i++)
	{
		int value = (double)rand() / RAND_MAX * 10.9;
		temp.pazymiai.push_back(value);
		sum += value;
	}
	int egz = (double)rand() / RAND_MAX * 10.9;
	temp.egzaminas = egz;
	return temp;
}

dat skaitymas(int n, ifstream& fd)
{
	dat temp;
	int sk, sum = 0;
	fd >> temp.vardas;
	if (fd.eof()) return temp;
	fd >> temp.pavarde;

	deque<int> pazymiai = deque<int>(n);
	for (int i = 0; i < n; i++)
	{
		fd >> sk;
		sum += sk;
		pazymiai[i] = sk;
	}
	fd >> temp.egzaminas;
	temp.answer = sum * 1.0 / n * 0.4 + temp.egzaminas * 1.0 * 0.6;
	return temp;
}

void outputas(string& output, dat a, bool kurimas)
{
	string atribute = "";
	for (int i = 0; i < 20 - a.vardas.length(); i++) atribute.insert(0, " ");
	atribute.insert(0, a.vardas);
	output += atribute;
	atribute = "";
	for (int i = 0; i < 25 - a.pavarde.length(); i++) atribute.insert(0, " ");
	atribute.insert(0, a.pavarde);
	output += atribute;
	if (kurimas)
	{
		for (int i = 0; i < a.pazymiai.size(); i++)
		{
			if (a.pazymiai[i] == 10) output += "        " + to_string(a.pazymiai[i]);
			else output += "         " + to_string(a.pazymiai[i]);
		}
		if (a.egzaminas == 10) output += "        " + to_string(a.egzaminas) + "\n";
		else output += "         " + to_string(a.egzaminas) + "\n";
	}
	else
	{
		string answer = to_string(a.answer);
		output += answer + "\n";
	}
}

bool FileExists(string filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		return 1;
		file.close();
	}
	else
	{
		return 0;
	}
}

void isskyrimas(deque<dat>& poor, deque<dat>& cool, deque<dat> all)
{
	for (int i = 0; i < all.size(); i++)
	{
		if (all[i].answer >= 5) cool.push_back(all[i]);
		else poor.push_back(all[i]);
	}
}

void rasymas(deque<dat> temp)
{
	cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(18) << "Galutinis (Vid.)" << left << setw(16) << "Galutinis(Med.)" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << left << setw(16) << temp[i].vardas << left << setw(16) << temp[i].pavarde << left << setw(18) << fixed << setprecision(2) << temp[i].answer << endl;
	}
}

void rasymas_s(deque<dat> temp, const string RF)
{
	ofstream fr(RF);
	fr << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.)" << endl;
	fr << "-------------------------------------------------" << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		string eile = "";
		outputas(eile, temp[i], false);
		fr << eile;
	}
	fr.close();
}
