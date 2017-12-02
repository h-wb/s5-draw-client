#include <sstream>
#include "FormeComposee.h"
#include "VisiteurDessiner.h"



FormeComposee::FormeComposee(int couleur) :Forme(couleur)
{

}

FormeComposee::FormeComposee(FormeComposee & f) : Forme(f)
{
	_formes = f._formes;
}

FormeComposee FormeComposee::operator=(const FormeComposee & f)
{
	_formes = f._formes;
	return *this;
}

FormeComposee & FormeComposee::operator+=(Forme * f)
{
	_formes.push_back(f);
	return *this;
}

FormeComposee FormeComposee::operator+(Forme * f)
{
	FormeComposee fc = FormeComposee(*this);
	fc += f;
	return fc;

}

/*virtual*/ Forme * FormeComposee::translation(const Vecteur2D & VectTrans) const {

	return new FormeComposee(getCouleur());

}

/*virtual*/ Forme * FormeComposee::homothetie(const Vecteur2D & point, const double & rapport) const {

	return new FormeComposee(getCouleur());

}

/*virtual*/ double FormeComposee::aire() const {
	return 0;
}

FormeComposee::operator string() const
{
	ostringstream oss;

	//oss << "Polygone : " << "Centre = " << _centre << ", rayon = " << _rayon;
	oss << "Test";
	return oss.str();
}


void FormeComposee::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);
}

vector<Forme*> FormeComposee::getFormes() const
{
	return _formes;
}

void FormeComposee::setFormes(vector<Forme*> v)
{
	_formes = v;
}

const string FormeComposee::encoderForme() const
{
	ostringstream oss;
	for (Forme * f : _formes) {
		oss << f->encoderForme();
	}
	return oss.str();
}

const string FormeComposee::encoderFenetre() const
{
	ostringstream oss;
	oss << "Forme Composée, " << 480 << ", " << 300 << ", " << 500 << ", " << 500 << "\r\n";
	return oss.str();
}