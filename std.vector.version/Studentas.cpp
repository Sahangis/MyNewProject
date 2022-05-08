#include "Studentas.h"
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>

using std::setw;
using std::left;
using std::setprecision;
using std::fixed;
using std::cin;
using std::endl;
using std::cout;
using std::ofstream;
using std::to_string;
using std::sort;
using std::stringstream;
using std::ifstream;

const string vardai[16] = { "Martynas", "Jonas", "Vilijamas", "Kristijonas", "Vincas", "Alberas", "Francas" , "Juozas", "Jurgis", "Antanas", "Henrikas", "Balys", "Augustas", "Justinas", "Ernestas", "Hansas" };
const string pavardes[16] = { "Dauksa", "Radvanas", "Marcinkevicius", "Kafka", "Kamiu", "Kudirka", "Shekspyras", "Donelaitis", "Mickevicius", "Biliunas", "Vaizgantas", "Radauskas", "Krivickas", "Savickis", "Sruoga", "Katiliskis" };

//Ja modifikavus i klase, o taip pat atsizvelgiant i anksciau sukurtas funkcijas, kurios operavo su Studentas tipo objektais, preliminarus antrastes(header) failas Studentas.h / Studentas.hpp:

// Reikia includinti visas priklausomybes: <iostream>, <string>, <vector>, "mediana.h"
//1st. rule - copy constructor
Studentas::Studentas(const Studentas& source)
{
	vardas_ = source.vardas_;
	pavarde_ = source.pavarde_;
	egzaminas_ = source.egzaminas_;
	nd_ = source.nd_;
}

//2nd. rule - overloaded assignment operator
Studentas& Studentas::operator=(const Studentas& source)
{
	// check for self assignment
	if (this == &source)
	{
		return *this;
	}
	vardas_ = source.vardas_;
	pavarde_ = source.pavarde_;
	egzaminas_ = source.egzaminas_;
	nd_ = source.nd_;
	return *this;
}

//3rd. rule - destructor
Studentas::~Studentas()
{
	
}

double mediana(const vector<double>&pazymiai)
{
	if (pazymiai.size() / 2 == 1) return pazymiai[pazymiai.size() / 2];
	else return (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) / 2;
}
double average(const vector<double>&pazymiai)
{
	double sum = 0;
	for (auto pazymys : pazymiai)
	{
		sum += pazymys;
	}
	return sum / pazymiai.size();
}

double Studentas::galutinisBalas(double (*sudedamas) (const vector<double>&)) const  // get'eriai
{ 
	return sudedamas(nd_) *0.4 + egzaminas_ * 0.6;
}

bool compare(const Studentas&a, const Studentas&b)
{
	return a.vardas() < b.vardas();
}
bool comparePagalPavarde(const Studentas&a, const Studentas&b)
{
	return a.pavarde() < b.pavarde();
}
bool comparePagalGalutiniBala(const Studentas&a, const Studentas&b)
{
	return a.galutinisBalas(average) > b.galutinisBalas(average);
}

Studentas skaitymas(int n, ifstream& fd)
{
	int sk, sum = 0;
	double egzaminas;
	string vardas, pavarde;
	fd >> vardas;
	if (fd.eof()) return Studentas();
	fd >> pavarde;

	vector<double> pazymiai(n);
	for (int i = 0; i < n; i++)
	{
		fd >> sk;
		sum += sk;
		pazymiai[i] = sk;
	}
	fd >> egzaminas;
	//temp.answer = sum * 1.0 / n * 0.4 + temp.egzaminas * 1.0 * 0.6;
	return Studentas(vardas, pavarde, egzaminas, pazymiai);
}

Studentas input(int i)
{
	Studentas temp;
	string vardas, pavarde;
	do {
		cout << "iveskite " << i << " -ojo mokinio varda(ilgis ne daugiau 15 simboliu): " << endl;
		cin >> vardas;
		if (vardas.length() >= 16) cout << "ivestas per ilgas vardas, prasome ivesti trumpesni" << endl;
	} while (vardas.length() >= 16);
	do {
		cout << "iveskite " << i << " -ojo mokinio pavarde(ilgis ne daugiau 15 simboliu): " << endl;
		cin >> pavarde;
		if (pavarde.length() >= 16) cout << "ivesta per ilga pavarde, prasome ivesti trumpesne" << endl;
	} while (pavarde.length() >= 16);
	bool inFail;
	int sk;
	vector<double> pazymiai;
	double egzaminas;
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
		cin >> egzaminas;
		inFail = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		if (!inFail) if (egzaminas > 10 or egzaminas < 0) inFail = true;
	} while (inFail);
	return Studentas(vardas, pavarde, egzaminas, pazymiai);
}

Studentas generavimas(int quantity)
{
	string vardas, pavarde;
	vector<double> pazymiai;
	double egzaminas;
	int index = (double)rand() / RAND_MAX * 15.9;
	vardas = vardai[index];
	int index2 = (double)rand() / RAND_MAX * 15.9;
	pavarde = pavardes[index2];
	int sum = 0;
	for (int i = 0; i < quantity; i++)
	{
		int value = (double)rand() / RAND_MAX * 10.9;
		pazymiai.push_back(value);
		sum += value;
	}
	int egz = (double)rand() / RAND_MAX * 10.9;
	egzaminas = egz;
	return Studentas(vardas, pavarde, egzaminas, pazymiai);
}

void isskyrimas(vector<Studentas>& poor, vector<Studentas>& cool, vector<Studentas>& all)
{
	auto answer = std::find_if(all.begin(), all.end(), [](Studentas a) { return a.galutinisBalas(average) < 5; });
	poor.insert(poor.begin(), answer, all.end());
	all.erase(answer, all.end());
	cool.insert(cool.begin(), all.begin(), all.end());
}

void isskyrimas2(vector<Studentas>& poor, vector<Studentas>& all)
{
	auto answer = std::find_if(all.begin(), all.end(), [](Studentas a) { return a.galutinisBalas(average) < 5; });
	poor.insert(poor.begin(), answer, all.end());
	all.erase(answer, all.end());
}

bool FileExists(const string& filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		file.close();
		return 1;

	}
	else
	{
		return 0;
	}
}

void outputas(string& output, const Studentas& a, bool kurimas)
{
	stringstream stream;
	stream << left << setw(16) << a.vardas() << left << setw(16) << a.pavarde();
	if (kurimas)
	{
		for (int i = 0; i < a.pazymiai().size(); i++)
		{
			stream << left << setw(10) << fixed << setprecision(0) << a.pazymiai()[i];
		}
		stream << left << setw(10) << fixed << setprecision(0) << a.egzaminas() << endl;
	}
	else
	{
		stream << a.galutinisBalas(average) << endl;
	}
	output + stream.str();
}

void rasymas(const vector<Studentas>& temp)
{
	cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(18) << "Galutinis (Vid.)" << left << setw(16) << "Galutinis(Med.)" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << left << setw(16) << temp[i].vardas() << left << setw(16) << temp[i].pavarde() << left << setw(18) << fixed << setprecision(2) << temp[i].galutinisBalas(average) << left << setw(18) << fixed << setprecision(2) << temp[i].galutinisBalas(mediana) << endl;
	}
}

void rasymas_s(const vector<Studentas>& temp, const string& RF)
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
