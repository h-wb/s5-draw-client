#include <sstream>
#include "VisiteurDessiner.h"
#include "Polygone.h"

/**
* @param xCentre
* @param yCentre
* @param rayon
*/



Polygone::Polygone(int couleur) : Forme(couleur)
{
	
}

Polygone::Polygone(Polygone & p) : Forme(p)
{
	_nbCotes = p._nbCotes;
	_vecteur = p._vecteur;
	_cotes = p._cotes;
}


void Polygone::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

void Polygone::Construction() {
	
		for (int i = 1; i < _vecteur.size(); i++) {
			_cotes.push_back(Segment(getCouleur(), _vecteur[i-1], _vecteur[i]));
			_nbCotes++;
		}
		_cotes.push_back(Segment(getCouleur(), _vecteur[_vecteur.size() - 1], _vecteur[0]));
		_nbCotes++;
	
}



Polygone::operator string() const
{
	ostringstream oss;

	//oss << "Polygone : " << "Centre = " << _centre << ", rayon = " << _rayon;
	oss << "Test";
	return oss.str();
}

/*Polygone Polygone::operator=(const Polygone & p)
{	
	_vecteur = p._vecteur;
	_cotes = p._cotes;
	_nbCotes = p._nbCotes;
	this->Construction();
	return *this;

}*/

Polygone & Polygone::operator+=(const Vecteur2D & v)
{
	_vecteur.push_back(v);
	return *this;
}

/*Polygone Polygone::operator+(const Vecteur2D & v)
{
	Polygone p = Polygone(*this);
	p += v;
	return p;
}*/

vector<Vecteur2D> Polygone::getVecteur() const
{
	return _vecteur;
}

void Polygone::setVecteur(vector<Vecteur2D> v)
{
	_vecteur = v;
}

vector<Segment> Polygone::getCotes() const
{
	return _cotes;
}

void Polygone::setCotes(vector<Segment> s)
{
	_cotes = s;
}

int Polygone::getNbCotes() const
{
	return _nbCotes;
}

void Polygone::setNbCotes(int nbCotes)
{
	_nbCotes = nbCotes;
}

ostream & operator << (ostream & os, const Polygone * p)
{
	return os;
}


