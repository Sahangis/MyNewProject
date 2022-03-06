#pragma once
#include <vector>
#include <string>
#include <fstream>

using std::ifstream;
using std::string;
using std::vector;

struct dat {
	string vardas, pavarde;
	int egzaminas;
	double answer[2];
};

dat generavimas();
dat input(int i);
dat skaitymas(int n, ifstream &fd);
void rasymas(vector<dat> temp);
