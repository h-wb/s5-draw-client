#include <sstream>
#include "VisiteurDessiner.h"
#include "Polygone.h"

/**
* @param xCentre
* @param yCentre
* @param rayon
*/



Polygone::Polygone(int couleur, int nbCotes) : Forme(couleur), _nbCotes(nbCotes)
{
	_nbCotes = nbCotes;
}

Polygone::Polygone(Polygone & p) : Forme(p), _nbCotes(p._nbCotes)
{
	_nbCotes = p._nbCotes;
}


void Polygone::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

Polygone::operator string() const
{
	ostringstream oss;

	//oss << "Polygone : " << "Centre = " << _centre << ", rayon = " << _rayon;
	oss << "Test";
	return oss.str();
}

int Polygone::getNbCotes() const
{
	return 0;
}

void Polygone::setNbCotes(int)
{
}


