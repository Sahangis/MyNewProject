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

/**
* Student class, used to store inputed, read or even generated data.
*/
/*!
* Student class, used to store inputed, read or even generated data.
*/
//!
//! Student class, used to store inputed, read or even generated data.
/// Student class, used to store inputed, read or even generated data.
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

/**
* Compares both Students by their first name.
*
* @param a Student a.
* @param b Student b.
*/
bool compare(const Studentas&a, const Studentas&b);

/**
* Checks if the file exists.
*/
bool FileExists(const string& filename);

/**
* Compare both Students by their last name.
*
* @param a Student a.
* @param b Student b.
*/
bool comparePagalPavarde(const Studentas&a, const Studentas&b);

/**
* Compares both Students by their final mark.
*
* @param a Student a.
* @param b Student b.
*/
bool comparePagalGalutiniBala(const Studentas&a, const Studentas&b);

/**
* Reads the file and returns values, which are then stored for further calculations.
*
* @param n Number of homework grades.
* @param fd Input stream.
* @return Student Returns the read student data.
*/
Studentas skaitymas(int n, ifstream& fd);

/**
* Gets the input from user, which act as the source of data.
*
* @param[in] i The index of the current student.
* @return Student Returns the inputed student data.
*/
Studentas input(int i);

/**
* Generates all of the students automatically.
*
* @param quantity Number of homework grades.
* @return Student Returns the generated student data.
*/
Studentas generavimas(int quantity);

/**
* Splits the students into two new seperate groups.
*
* @param[inout] poor The vector of the poor students.
* @param[inout] cool The vector of the cool students.
* @param[inout] all The vector of all the students.
*/
void isskyrimas(vector<Studentas>& poor, vector<Studentas>& cool, vector<Studentas>& all);

/**
* Splits the students into two seperate groups.
*
* @param[inout] poor The vector of the poor students.
* @param[inout] all The first vector with all students.
*/
void isskyrimas2(vector<Studentas>& poor, vector<Studentas>& all);

/**
* Outputs students into a file, by neatly aligning the data.
*
* @param[inout] output The string which is edited, to be outputed into the file.
* @param[in] a Given student data, to be edited and added to the output string.
* @param kurimas Boolian value determening if the output should be edited for the result file or the data file.
*/
void outputas(string& output, const Studentas& a, bool kurimas);

/**
* Prints out Student data into the console.
*
* @param temp Student data meant to be displayed.
*/
void rasymas(const vector<Studentas>& temp);

/**
* Prints out Student data into the file.
*
* @param temp Student data meant to be displayed.
* @param RF The name of the file which will be created.
*/
void rasymas_s(const vector<Studentas>& temp, const string& RF);
