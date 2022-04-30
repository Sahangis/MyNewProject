#pragma once
#include <list>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;
using std::cin;
using std::list;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::setprecision;
using std::fixed;
using std::sort;

struct dat {
	string vardas, pavarde;
	list<int> pazymiai;
	int egzaminas;
	double answer;
};

dat generavimas(int quantity);
dat input(int i);
dat skaitymas(int n, ifstream& fd);
void outputas(string& output, dat a, bool kurimas);
bool FileExists(string filename);
bool palyginimas(const dat &a, const dat &b);
bool palyginimas2(const dat& a, const dat& b);
void rasymas(list<dat> temp);
void rasymas_s(list<dat> temp, const string RF);
void isskyrimas(list<dat>& poor, list<dat>& cool, list<dat> all);
void isskyrimas2(list<dat>& poor, list<dat>& all);
