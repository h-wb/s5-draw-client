#include "VisiteurDessiner.h"
#include "Polygone.h"

Polygone::Polygone(const int couleur) : Forme(couleur)
{
	
}

Polygone::Polygone(const Polygone & p) : Forme(p)
{
	_nbCotes = p._nbCotes;
	_vecteurs = p._vecteurs;
	_cotes = p._cotes;
}

Polygone::~Polygone()
{
}

vector<Vecteur2D> Polygone::getVecteurs() const
{
	return _vecteurs;
}

void Polygone::setVecteurs(vector<Vecteur2D> v)
{
	_vecteurs = v;
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

Polygone Polygone::operator=(const Polygone & p)
{
	_vecteurs = p._vecteurs;
	_cotes = p._cotes;
	this->Construction();
	return *this;

}

Polygone & Polygone::operator+=(const Vecteur2D & v)
{
	_vecteurs.push_back(v);
	return *this;
}

Polygone Polygone::operator+(const Vecteur2D & v)
{
	Polygone p = Polygone(*this);

	p += v;
	return p;
}

Forme * Polygone::translation(const Vecteur2D & VectTrans ){


	for (int i = 0; i < _cotes.size(); i++) {
		_cotes[i].translation(VectTrans);
	}
	return this;

}

Forme * Polygone::homothetie(const Vecteur2D & point, const double & rapport) {
	
	for (int i = 0; i < _cotes.size(); i++) {
		_cotes[i].homothetie(point, rapport);
	}
	return this;
}

Forme * Polygone::rotation(const Vecteur2D & centre, const double & angle)  {


	for (int i = 0; i < _cotes.size(); i++) {
		_cotes[i].rotation(centre, angle);
	}
	return this;

}

Forme * Polygone::forme() const
{
	return new Polygone(*this);;
}

double Polygone::aire() const {
	return 0;
}

void Polygone::Construction() {

	for (int i = 1; i < _vecteurs.size(); i++) {
		_cotes.push_back(Segment(getCouleur(), _vecteurs[i - 1], _vecteurs[i]));
		_nbCotes++;
	}
	_cotes.push_back(Segment(getCouleur(), _vecteurs[_vecteurs.size() - 1], _vecteurs[0]));
	_nbCotes++;

}

const string Polygone::encoderForme() const
{
	ostringstream oss;
	for (Segment s : _cotes) {
		oss << s.encoderForme();
	}
	return oss.str();
}

const string Polygone::encoderFenetre() const
{
	ostringstream oss;
	oss << "Polygone, " << 0 << ", " << 0 << ", " << 500 << ", " << 500 << "\r\n";
	return oss.str();
}

void Polygone::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

void Polygone::sauvegarder(VisiteurSauvegarde * visiteurSauvegarde) const
{
}

ostream & operator << (ostream & os, const Polygone * p)
{
	return os << "Polygone : " << endl << p->encoderForme() << "\n";
}





