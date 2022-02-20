#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>


using namespace std;

string vardai[16] = { "Martynas", "Jonas", "Vilijamas", "Kristijonas", "Vincas", "Alberas", "Francas" , "Juozas", "Jurgis", "Antanas", "Henrikas", "Balys", "Augustas", "Justinas", "Ernestas", "Hansas" };
string pavardes[16] = { "Dauksa", "Radvanas", "Marcinkevicius", "Kafka", "Kamiu", "Kudirka", "Shekspyras", "Donelaitis", "Mickevicius", "Biliunas", "Vaizgantas", "Radauskas", "Krivickas", "Savickis", "Sruoga", "Katiliskis" };

const int kiekis = 6;

struct dat {
	string vardas, pavarde;
	int pazymiai[kiekis], egzaminas;
	double answer;
	int quantity;

};

void generavimas(dat& temp, string answer);
void input(int i, dat& temp, string answer);
void rasymas(dat temp[], int n, string answer);
void rikiavimas(int pazymiai[], int n);

int main()
{
	string answer;
	
	do {
		cout << "ar norite ivesti visas reiksmes pats ? (y/n), kitu atveju: programa pati sugeneruos visus duomenis" << endl;
		cin >> answer;
		if (answer != "y" and answer != "n") cout << "ivesta netinkama reiksme, prasome ivesti vel " << endl;
	} while (answer != "y" and answer != "n");
	if (answer == "n")
	{
		srand(time(NULL));
		int n = (double)rand() / RAND_MAX * 10;
		do {
			n = (double)rand() / RAND_MAX * 10;
		} while (n == 0);
		string ans = "v";
		int r = (double)rand() / RAND_MAX * 10;
		if (r>5) ans = "m";
		dat* a=new dat[n];
		for (int i = 0; i < n; i++) generavimas(a[i], ans);
		rasymas(a, n, ans);
		delete[] a;
	}
	else if (answer == "y")
	{
		int n;
		do {
			cout << "iveskite kiek mokiniu bus vedami duomenys (n>0)" << endl;
			cin >> n;
			if(!n) cout << "ivesta netinkama reiksme, prasome ivesti vel" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}while(!n);
		string ans;
		do {
			cout << "Ka norite skaiciuoti ? (v/m), vidurki ar mediana? " << endl;
			cin >> ans;
			if (ans != "v" and ans != "m") cout << "ivesta netinkama reiksme, prasome ivesti vel " << endl;
		} while (ans != "v" and ans != "m");
		dat* a = new dat[n];
		for (int i = 0; i < n; i++) input(i+1, a[i], ans);
		rasymas(a, kiekis, ans);
		delete[] a;
	}
	
	return 0;
}

void rikiavimas(int pazymiai[], int n)
{
	bool rikiuoti = true;
	while (rikiuoti)
	{
		rikiuoti = false;
		for (int i = 0; i < n-1; i++)
		{
			if (pazymiai[i] > pazymiai[i + 1])
			{
				swap(pazymiai[i], pazymiai[i + 1]);
				rikiuoti = true;
			}
		}
	}
}



void input(int i, dat& temp, string answer)
{
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
	for (int j = 0; j < kiekis; j++) {
		do {
			cout << "iveskite " << j + 1 << " pazimi" << endl;
			cin >> temp.pazymiai[j];
			inFail = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!inFail) if (temp.pazymiai[j] > 10 or temp.pazymiai[j] < 0) inFail = true;
		} while (inFail);
	}
	do {
		cout << "iveskite egzamino rezultata" << endl;
		cin >> temp.egzaminas;
		inFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (!inFail) if (temp.egzaminas > 10 or temp.egzaminas < 0) inFail = true;
	} while (inFail);
	
	if (answer == "v")
	{
		int sum = 0;
		for (int j = 0; j < kiekis; j++)
		{
			sum += temp.pazymiai[j];
		}
		temp.answer = 0.4 * (sum*1.0/kiekis) + 0.6 * (temp.egzaminas * 1.0);
	}
	else if (answer == "m")
	{
		rikiavimas(temp.pazymiai, kiekis);
		if (kiekis % 2 == 0) temp.answer = (temp.pazymiai[kiekis / 2] + temp.pazymiai[kiekis / 2 - 1]) * 1.0 / 2 * 0.4 + temp.egzaminas * 1.0 * 0.6;
		else temp.answer = temp.pazymiai[kiekis / 2]*1.0*0.4+temp.egzaminas*1.0*0.6;
	}

}

void generavimas(dat& temp, string answer)
{
	int index = (double)rand() / RAND_MAX * 16;
	temp.vardas = vardai[index];
	int index2 = (double)rand() / RAND_MAX * 16;
	temp.pavarde = pavardes[index2];
	int quantity;
	do {
		quantity = (double)rand() / RAND_MAX * kiekis;
	} while (quantity == 0);
	temp.quantity = quantity;
	int sum = 0;
	for (int i = 0; i < temp.quantity; i++) 
	{
		int value = (double)rand() / RAND_MAX * 10;
		temp.pazymiai[i] = value;
		sum += value;
	}
	int egz = (double)rand() / RAND_MAX * 10;
	temp.egzaminas = egz;
	if (answer == "v") temp.answer = sum * 1.0 / quantity*0.4+temp.egzaminas*1.0*0.6;
	else
	{
		rikiavimas(temp.pazymiai , quantity);
		if (quantity % 2 == 1) temp.answer = temp.pazymiai[quantity / 2]*1.0*0.4+temp.egzaminas*1.0*0.6;
		else temp.answer = (temp.pazymiai[quantity / 2] + temp.pazymiai[quantity / 2 - 1]) * 1.0/2*0.4+temp.egzaminas*1.0*0.6;
	}
	
}

void rasymas(dat temp[], int n, string answer)
{
	cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde"<< "Galutinis";
	if (answer == "v") cout << " (Vid.)" << endl;
	else cout << " (Med.)" << endl;
	cout << "--------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) cout << left << setw(16) << temp[i].vardas << left << setw(16) << temp[i].pavarde << left << setw(7) << fixed << setprecision(2) << temp[i].answer << endl;
}
