#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>


using namespace std;

string vardai[16] = { "Martynas", "Jonas", "Vilijamas", "Kristijonas", "Vincas", "Alberas", "Francas" , "Juozas", "Jurgis", "Antanas", "Henrikas", "Balys", "Augustas", "Justinas", "Ernestas", "Hansas" };
string pavardes[16] = { "Dauksa", "Radvanas", "Marcinkevicius", "Kafka", "Kamiu", "Kudirka", "Shekspyras", "Donelaitis", "Mickevicius", "Biliunas", "Vaizgantas", "Radauskas", "Krivickas", "Savickis", "Sruoga", "Katiliskis" };

struct dat {
	string vardas, pavarde;
	int pazymiai[10], egzaminas;
	double answer;
	int quantity;

};

void generavimas(dat& temp, char answer);
void input(int i, dat& temp, char answer);
void isvedimas(dat temp);
void rasymas(dat temp[], int n, char answer);

int main()
{
	char answer;
	
	do {
		cout << "ar norite ivesti visas reiksmes pats ? (y/n), kitu atveju: programa pati sugeneruos visus duomenis" << endl;
		cin >> answer;
		if (answer != 'y' and answer != 'n') cout << "ivesta netinkama reiksme, prasome ivesti vel " << endl;
	} while (answer != 'y' and answer != 'n');
	if (answer == 'n')
	{
		srand(time(NULL));
		int n = (double)rand() / RAND_MAX * 10;
		do {
			n = (double)rand() / RAND_MAX * 10;
		} while (n == 0);
		char ans = 'v';
		int r = (double)rand() / RAND_MAX * 10;
		if (r>5) ans = 'm';
		dat* a=new dat[n];
		for (int i = 0; i < n; i++) generavimas(a[i], ans);
		rasymas(a, n, ans);
		delete[] a;
	}
	else if (answer == 'y')
	{
		int n;
		
		do {
			cout << "iveskite kiek mokiniu bus vedami duomenys (n>0)"<<endl;
			cin >> n;
			if (n <= 0) cout << "Pateiktas negalimas skaicius, prasome ivesti vel" << endl;
		} while (n <= 0);
		char ans;
		do {
			cout << "Ka norite skaiciuoti ? (v/m), vidurki ar mediana? " << endl;
			cin >> ans;
			if (ans != 'v' and ans != 'm') cout << "ivesta netinkama reiksme, prasome ivesti vel " << endl;
		} while (ans != 'v' and ans != 'm');
		dat* a = new dat[n];
		for (int i = 0; i < n; i++) input(i+1, a[i], ans);
		rasymas(a, 10, ans);
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



void input(int i, dat& temp, char answer)
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
	for (int j = 0; j < 10; j++) {
		cout << "iveskite " << j+1 << " pazimy:" << endl;
		cin >> temp.pazymiai[j];
	}
	do {
		cout << "iveskite egzamino rezultata(0<=egz<=10): " << endl;
		cin >> temp.egzaminas;
		if(temp.egzaminas > 10 or temp.egzaminas < 0) cout << "ivesta netinkama reiksme, prasome ivesti dar kart" << endl;
	} while (temp.egzaminas > 10 or temp.egzaminas < 0);
	
	if (answer == 'v')
	{
		int sum = 0;
		for (int j = 0; j < 10; j++)
		{
			sum += temp.pazymiai[j];
		}
		temp.answer = 0.4 * (sum*1.0/10) + 0.6 * temp.egzaminas;
	}
	else if (answer == 'm')
	{
		rikiavimas(temp.pazymiai, 10);
		temp.answer = temp.pazymiai[5];
	}

}

void generavimas(dat& temp, char answer)
{
	int index = (double)rand() / RAND_MAX * 16;
	temp.vardas = vardai[index];
	int index2 = (double)rand() / RAND_MAX * 16;
	temp.pavarde = pavardes[index2];
	int quantity;
	do {
		quantity = (double)rand() / RAND_MAX * 10;
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
	if (answer == 'v') temp.answer = sum * 1.0 / quantity*0.4+temp.egzaminas*1.0*0.4;
	else
	{
		int balai[11];
		for (int i = 0; i <= quantity; i++)
		{
			if (i == quantity) balai[i] = temp.egzaminas;
			else balai[i] = temp.pazymiai[i];
		}
		rikiavimas(balai , quantity+1);
		if (quantity % 2 == 1) temp.answer = balai[(quantity + 1) / 2];
		else temp.answer = (balai[quantity / 2] + balai[quantity / 2 - 1]) * 1.0/2;
	}
	
}

void isvedimas(dat temp)
{
	cout << left << setw(16) << temp.vardas << left << setw(16) << temp.pavarde << left << setw(7) << fixed<< setprecision(2)<< temp.answer << endl;
}

void rasymas(dat temp[], int n, char answer)
{
	cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde"<< "Galutinis";
	if (answer == 'v') cout << " (Vid.)" << endl;
	else cout << " (Med.)" << endl;
	cout << "--------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) isvedimas(temp[i]);
}
