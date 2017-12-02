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

	int i;
	Forme *f1, *tf1;
	FormeComposee fc(1);

	for (i = 0; i < _formes.size(); i++) {
		f1 = _formes[i];
		tf1 = f1->translation(VectTrans);
		fc += tf1;
	}

	return new FormeComposee(fc);

}

/*virtual*/ Forme * FormeComposee::homothetie(const Vecteur2D & point, const double & rapport) const {

	int i;
	Forme *f1, *tf1;
	FormeComposee fc(1);

	for (i = 0; i < _formes.size(); i++) {
		f1 = _formes[i];
		tf1 = f1->homothetie(point, rapport);
		fc += tf1;
	}

	return new FormeComposee(fc);

}

/*virtual*/ double FormeComposee::aire() const {

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

/*virtual*/ Forme * FormeComposee::rotation(const Vecteur2D & centre, const double & angle) const {


	if ((angle > 0) && (angle < 360)) {
		
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
	}

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