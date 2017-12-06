#include <sstream>
#include "FormeComposee.h"
#include "VisiteurDessiner.h"



FormeComposee::FormeComposee(const int couleur) :Forme(couleur)
{

}

FormeComposee::FormeComposee(const FormeComposee & f) : Forme(f)
{
	_formes = f._formes;
}

FormeComposee::~FormeComposee()
{
	/*for (Forme * f : _formes) {
		delete(f);
	}*/
}

vector<Forme*> FormeComposee::getFormes() const
{
	return _formes;
}

void FormeComposee::setFormes(vector<Forme*> v)
{
	_formes = v;
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

FormeComposee FormeComposee::operator+(const Forme & f)
{
	FormeComposee fc = FormeComposee(*this);
	fc += f.forme();
	return fc;

}

Forme * FormeComposee::translation(const Vecteur2D & VectTrans) {

	for (int i = 0; i < _formes.size(); i++) {
		_formes[i]->translation(VectTrans);
	}
	return this;

}

Forme * FormeComposee::homothetie(const Vecteur2D & point, const double & rapport){

	for (int i = 0; i < _formes.size(); i++) {
		_formes[i]->homothetie(point, rapport);
	}
	return this;


}

Forme * FormeComposee::rotation(const Vecteur2D & centre, const double & angle){


	/*if ((angle > 0) && (angle < 360)) {

		int i;
		Forme *f1, *tf1;
		FormeComposee fc(1);

		for (i = 0; i < _formes.size(); i++) {
			f1 = _formes[i];
			tf1 = f1->rotation(centre, angle);
			fc += tf1;
		}

		return new FormeComposee(fc);

	}
	else {
		throw invalid_argument("Veuillez entrer un angle entre 0 et 360");
	}*/
	for (int i = 0; i < _formes.size(); i++) {
		_formes[i]->rotation(centre, angle);
	}
	return this;

}

Forme * FormeComposee::forme() const
{
	return new FormeComposee(*this);;
}

double FormeComposee::aire() const {
	int i;
	double tmp, resultat = 0;
	Forme *f1;
	FormeComposee fc(1);

	for (i = 0; i < _formes.size(); i++) {
		f1 = _formes[i];
		tmp = f1->aire();
		resultat += tmp;
	}

	return resultat;
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

void FormeComposee::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);
}

void FormeComposee::sauvegarder(VisiteurSauvegarde * visiteurSauvegarde) const
{
}

ostream & operator << (ostream & os, const FormeComposee * f)
{
	return os << "Forme Composée : " << endl << f->encoderForme() << "\n";
}