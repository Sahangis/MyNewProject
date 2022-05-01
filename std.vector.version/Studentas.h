#pragma once
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

double mediana(const vector<double> &pazymiai);
double average(const vector<double> &pazymiai);

class Studentas {

private:
    string vardas_;
    string pavarde_;
    double egzaminas_;
    vector<double> nd_;

public:
    Studentas() : vardas_(), pavarde_(), egzaminas_(), nd_() { } 
    Studentas(const string &vardas, const string &pavarde, double egzaminas, const vector<double> &nd) : vardas_(vardas), pavarde_(pavarde), egzaminas_(egzaminas), nd_(nd) {}
    const string &vardas() const { return vardas_; }    
    const string &pavarde() const { return pavarde_; }  
	const vector<double>& pazymiai() const { return nd_; }
    double egzaminas() const { return egzaminas_; }  
    double galutinisBalas(double (*sudedamas) (const vector<double>&)) const;  
};

bool compare(const Studentas&a, const Studentas&b);
bool FileExists(const string& filename);
bool comparePagalPavarde(const Studentas&a, const Studentas&b);
bool comparePagalGalutiniBala(const Studentas&a, const Studentas&b);
Studentas skaitymas(int n, ifstream& fd);
Studentas input(int i);
Studentas generavimas(int quantity);
void isskyrimas(vector<Studentas>& poor, vector<Studentas>& cool, vector<Studentas>& all);
void isskyrimas2(vector<Studentas>& poor, vector<Studentas>& all);
void outputas(string& output, const Studentas& a, bool kurimas);
void rasymas(const vector<Studentas>& temp);
void rasymas_s(const vector<Studentas>& temp, const string& RF);
