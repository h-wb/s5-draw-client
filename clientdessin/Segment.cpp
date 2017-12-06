
#include <sstream>
#include "VisiteurDessiner.h"
#include "Segment.h"


Segment::Segment(const int couleur, const Vecteur2D & debut, const Vecteur2D & fin) : Forme(couleur), _debut(debut), _fin(fin)
{
}

Segment::Segment(const Segment & s) : Forme(s), _debut(s._debut), _fin(s._fin)
{
}

Segment::~Segment()
{
}

Vecteur2D Segment::getDebut() const
{
	return _debut;
}

void Segment::setDebut(Vecteur2D debut)
{
	_debut = debut;
}

Vecteur2D Segment::getFin() const
{
	return _fin;
}

void Segment::setFin(Vecteur2D fin)
{
	_fin = fin;
}

Forme * Segment::translation(const Vecteur2D & VectTrans){

	//return new Segment(getCouleur(), VectTrans + _debut, VectTrans + _fin);
	_debut.translation(VectTrans);
	_fin.translation(VectTrans);
	return this;
}

Forme * Segment::homothetie(const Vecteur2D & point, const double & rapport){

/*	Vecteur2D oa, ob, oap, obp;
	oa = point - _debut;
	ob = point - _fin;

	oap = oa * rapport;
	obp = ob * rapport;

	return new Segment(getCouleur(), oap + point, obp + point);*/

	_debut.homothetie(point, rapport);
	_fin.homothetie(point, rapport);
	return this;
	
}

Forme * Segment::rotation(const Vecteur2D & centre, const double & angle) {

	/*if ((angle > 0) && (angle < 360)) {
		double Axprime, Ayprime, Bxprime, Byprime;
		double result, result2;
		Vecteur2D deb, fin;
		cout << "centre 0 = " << centre.getX() << " " << centre.getY() << endl;
		cout << "Point A = " << _debut.getX() << " " << _debut.getY() << endl;
		cout << "Point B = " << _fin.getX() << " " << _fin.getY() << endl;

		if ((angle != 90) || (angle != 270)) {
			result = cos(angle * M_PI / 180.0);
		}
		else {
			result = 0;
		}


		if ((angle != 180) || (angle != 360)) {
			result2 = sin(angle * M_PI / 180.0);
		}
		else {
			result2 = 0;
		}


		Axprime = result * (_debut.getX() - centre.getX()) - result2 * (_debut.getY() - centre.getY()) + centre.getX();
		Ayprime = result2 * (_debut.getX() - centre.getX()) + result * (_debut.getY() - centre.getY()) + centre.getY();

		Bxprime = result * (_fin.getX() - centre.getX()) - result2 * (_fin.getY() - centre.getY()) + centre.getX();
		Byprime = result2 * (_fin.getX() - centre.getX()) + result * (_fin.getY() - centre.getY()) + centre.getY();

		deb = Vecteur2D(round(Axprime), round(Ayprime));
		fin = Vecteur2D(Bxprime, Byprime);

		return new Segment(getCouleur(), deb, fin);
	}
	else {
		throw invalid_argument("Veuillez entrer un angle entre 0 et 360");
	}*/

	_debut.rotation(centre, angle);
	_fin.rotation(centre, angle);
	return this;
}

Forme * Segment::forme() const
{
	return new Segment(*this);
}

double Segment::aire() const {
	return 0;
}

const string Segment::encoderForme() const
{
	ostringstream oss;
	oss  << "Segment, " << getCouleur() << ", " << getDebut() << ", " << getFin() << "\r\n";
	return oss.str();
}

const string Segment::encoderFenetre() const
{
	ostringstream oss;
	oss << "Segment, " << 960 << ", " << 0 << ", " << 500 << ", " << 500 << "\r\n";
	return oss.str();
}

void Segment::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);
}

void Segment::sauvegarder(VisiteurSauvegarde * visiteurSauvegarde) const
{
}

ostream & operator << (ostream & os, const Segment * s)
{
	return os << s->encoderForme() << "\n";
}
