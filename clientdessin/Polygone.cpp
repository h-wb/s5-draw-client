#include "VisiteurDessiner.h"
#include "Polygone.h"
#include "SauvegardeFormeJSON.h"

Polygone::Polygone(const int couleur) : Forme(couleur)
{
	
}

Polygone::Polygone(const Polygone & p) : Forme(p)
{
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

Polygone Polygone::operator=(const Polygone & p)
{
	_vecteurs = p._vecteurs;
	_cotes = p._cotes;
	this->Construction();
	return *this;

}

Polygone& Polygone::operator+=(const Vecteur2D & v)
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
	}
	_cotes.push_back(Segment(getCouleur(), _vecteurs[_vecteurs.size() - 1], _vecteurs[0]));

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
	oss << "Polygone," << 0 << "," << 0 << "," << 500 << "," << 500 << "\r\n";
	return oss.str();
}

void Polygone::sauvegardeJson() const
{
	SauvegarderFormeJSON* test2 = new SauvegarderFormeJSON();
	test2->visite(this);
}

const void Polygone::sauvegardePolygone() const
{
	SauvegarderFormeJSON* test2 = new SauvegarderFormeJSON();

	for (Segment s : _cotes) {
		test2->visite(&s);
	}
}

void Polygone::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}


ostream & operator << (ostream & os, const Polygone * p)
{
	return os << "Polygone : " << endl << p->encoderForme() << "\n";
}





