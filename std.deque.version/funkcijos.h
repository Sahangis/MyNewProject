#pragma once
#include <deque>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::string;
using std::deque;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::setprecision;
using std::fixed;
using std::sort;

struct dat {
	string vardas, pavarde;
	deque<int> pazymiai;
	int egzaminas;
	double answer;
};

dat generavimas(int quantity);
dat input(int i);
dat skaitymas(int n, ifstream& fd);
void outputas(string& output, dat a, bool kurimas);
bool FileExists(string filename);
void rasymas(deque<dat> temp);
void rasymas_s(deque<dat> temp, const string RF);
void isskyrimas(deque<dat>& poor, deque<dat>& cool, deque<dat> all);
