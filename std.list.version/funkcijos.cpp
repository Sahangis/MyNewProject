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
	vector<int> pazymiai;
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

	vector<int> pazymiai = vector<int>(n);
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
			list<int>::iterator it = a.pazymiai.begin();
			for (int j = 0; j < i; j++) it++;
			if (*it == 10) output += "        " + to_string(*it);
			else output += "         " + to_string(*it);
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

bool palyginimas(const dat &a, const dat &b)
{
	return a.answer > b.answer;
}

bool palyginimas2(const dat& a, const dat& b)
{
	return a.vardas > b.vardas;
}

void isskyrimas(list<dat>& poor, list<dat>& cool, list<dat> all)
{
	list<dat>::iterator it;
	for (it = all.begin(); it != all.end(); it++)
	{
		if(it->answer >=5) cool.push_back(*it);
		else poor.push_back(*it);
	}
}

void rasymas(list<dat> temp)
{
	cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(18) << "Galutinis (Vid.)" << left << setw(16) << "Galutinis(Med.)" << endl;
	cout << "----------------------------------------------------------------" << endl;
	list<dat>::iterator it = temp.begin();
	for (int i = 0; i < temp.size(); i++) 
	{
		cout << left << setw(16) << it->vardas << left << setw(16) << it->pavarde << left << setw(18) << fixed << setprecision(2) << it->answer << endl;
		it++;
	}
}

void rasymas_s(list<dat> temp, const string RF)
{
	ofstream fr(RF);
	fr << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.)" << endl;
	fr << "-------------------------------------------------" << endl;
	list<dat>::iterator it = temp.begin();
	for (int i = 0; i < temp.size(); i++)
	{
		string eile = "";
		outputas(eile, *it, false);
		fr << eile;
		it++;
	}
	fr.close();
}
