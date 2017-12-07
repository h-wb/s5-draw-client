#pragma once

#include <string>
#include "Forme.h"

class Expert {
private:
	Expert* _suivant;

public:
	Expert();
	Expert(Expert *);
	virtual ~Expert();

	Expert* getSuivant() const;
	void setSuivant(Expert* suivant);

	virtual Forme * handle(const string &requete) const = 0;
};