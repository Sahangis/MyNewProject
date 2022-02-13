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
	double vidurkis;
	int quantity;
};

void generavimas(dat& temp);
void isvedimas(dat temp);
void rasymas(dat temp[], int n);

int main()
{
	srand(time(NULL));
	int n = (double)rand() / RAND_MAX * 10;
	do {
		n = (double)rand() / RAND_MAX * 10;
	} while (n == 0);
	dat* a=new dat[n];
	for (int i = 0; i < n; i++) generavimas(a[i]);
	rasymas(a, n);
	delete[] a;
}

void generavimas(dat& temp)
{
	int index = (double)rand() / RAND_MAX * 16;
	//index = (double)rand() / RAND_MAX * 16;
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
	temp.vidurkis = sum * 1.0 / quantity*0.4+temp.egzaminas*1.0*0.4;
}

void isvedimas(dat temp)
{
	cout << left << setw(16) << temp.vardas << left << setw(16) << temp.pavarde << left << setw(7) << fixed<< setprecision(2)<< temp.vidurkis << endl;
}

void rasymas(dat temp[], int n)
{
	cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << "Galutinis (Vid.)" << endl;
	cout << "--------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) isvedimas(temp[i]);
}
