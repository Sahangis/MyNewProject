#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <ostream>

using std::string;
using std::vector;
using std::ifstream;
using std::ostream;

double mediana(const vector<double> &pazymiai);
double average(const vector<double> &pazymiai);

class Zmogus {
public:
    virtual const string& vardas() const = 0;
    virtual const string& pavarde() const = 0;
};

class Studentas : public Zmogus {

private:
    string vardas_;
    string pavarde_;
    double egzaminas_;
    vector<double> nd_;

public:
    Studentas() : vardas_(), pavarde_(), egzaminas_(), nd_() { } 
    Studentas(const string &vardas, const string &pavarde, double egzaminas, const vector<double> &nd) : vardas_(vardas), pavarde_(pavarde), egzaminas_(egzaminas), nd_(nd) {}
    virtual const string &vardas() const override { return vardas_; }    
    virtual const string &pavarde() const override { return pavarde_; }  
	const vector<double>& pazymiai() const { return nd_; }
    //1st. rule - Copy constructor
    Studentas(const Studentas& source);
    //2nd. rule - Overloaded Assignment
    Studentas& operator=(const Studentas& source);
    //3rd. rule - Destructor
    ~Studentas();
    // Random for the future use
    Studentas& operator+(const Studentas& source);
    friend ostream& operator<<(ostream& os, const Studentas& source);
    //
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
