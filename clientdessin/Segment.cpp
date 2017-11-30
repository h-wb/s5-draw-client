
#include <sstream>
#include "VisiteurDessiner.h"
#include "Segment.h"


Segment::Segment(const Segment & s) : Forme(s), _debut(s._debut), _fin(s._fin)
{
	

}


/**
* @param x
* @param y
*/

Vecteur2D Segment::getDebut() const
{
	return _debut;
}

Vecteur2D Segment::getFin() const
{
	return _fin;
}

void Segment::setDebut(Vecteur2D debut)
{
	_debut = debut;
}

void Segment::setFin(Vecteur2D fin)
{
	_fin = fin;
}

void Segment::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

/*virtual*/ Forme * Segment::translation(const Vecteur2D & VectTrans) const {

	return new Segment(getCouleur(), VectTrans + _debut, VectTrans + _fin);

}


Segment::operator string() const
{
	ostringstream oss;

	oss << "Segment : " << "x = " << _debut << ", y = " << _fin;

	return oss.str();
}


ostream & operator << (ostream & os, const Segment * s)
{
	return os;
}

