#pragma once

#include "Forme.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include "Vecteur2D.h"
#include <iostream>
#include <fstream>

class Expert {
private:
	Expert* _suivant;

public:

	Expert();
	Expert(Expert *);
	virtual ~Expert();

	Expert* getSuivant() const;
	void setSuivant(Expert* suivant);

	virtual Forme * handle(ifstream & fichier) const = 0;
};

template<typename Out>
inline void split(const string & s, char delim, Out result)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		
		*(result++) = item;
	}
}

inline vector<string> split(const std::string & s, const char delim)
{
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}