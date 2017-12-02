
#include <sstream>
#include <math.h>
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

/*virtual*/ Forme * Segment::translation(const Vecteur2D & VectTrans) const {

	return new Segment(getCouleur(), VectTrans + _debut, VectTrans + _fin);

}

/*virtual*/ Forme * Segment::homothetie(const Vecteur2D & point, const double & rapport) const {

	Vecteur2D oa, ob, oap, obp;
	oa = point - _debut;
	ob = point - _fin;

	oap = oa * rapport;
	obp = ob * rapport;

	/*cout << "O = " << point.getX() << " " << point.getY() << endl;
	cout << "OA = " << oa.getX() << " " <<oa.getY() << endl;
	cout << "OB = " << ob.getX() << " " << ob.getY() << endl;
	cout << "OA = " << ob.getX() << " " << ob.getY() << endl;
	cout << "OA prime = " << oap.getX() << " " << oap.getY() << endl;
	cout << "OB prime = " << obp.getX() << " " << obp.getY() << endl;
	cout << "Point A = " << oap + point << endl;
	cout << "Point B = " << obp + point << endl;*/

	return new Segment(getCouleur(), oap + point, obp + point);
}

/*virtual*/ double Segment::aire() const {
	return 0;
}

/*virtual*/ Forme * Segment::rotation(const Vecteur2D & centre, const double & angle) const {
	
	if ((angle > 0) && (angle < 360)) {
		double Axprime, Ayprime, Bxprime, Byprime;
		double result, result2;
		Vecteur2D deb, fin;
		cout << "centre 0 = " << centre.getX() << " " << centre.getY() << endl;
		cout << "Point A = " << _debut.getX() << " " << _debut.getY() << endl;
		cout << "Point B = " << _fin.getX() << " " << _fin.getY() << endl;

		if ((angle != 90) || (angle != 270)) {
			result = cos(angle * PI / 180.0);
		}
		else {
			result = 0;
		}


		if ((angle != 180) || (angle != 360)) {
			result2 = sin(angle * PI / 180.0);
		}
		else {
			result2 = 0;
		}


		Axprime = result * (_debut.getX() - centre.getX()) - result2 * (_debut.getY() - centre.getY()) + centre.getX();
		Ayprime = result2 * (_debut.getX() - centre.getX()) + result * (_debut.getY() - centre.getY()) + centre.getY();

		Bxprime = result * (_fin.getX() - centre.getX()) - result2 * (_fin.getY() - centre.getY()) + centre.getX();
		Byprime = result2 * (_fin.getX() - centre.getX()) + result * (_fin.getY() - centre.getY()) + centre.getY();

		deb = Vecteur2D(Axprime, Ayprime);
		fin = Vecteur2D(Bxprime, Byprime);

		return new Segment(getCouleur(), deb, fin);
	}
	else {
		throw invalid_argument("Veuillez entrer un angle entre 0 et 360");
	}

}

Segment::operator string() const
{
	ostringstream oss;

	oss << "Segment : " << "x = " << _debut << ", y = " << _fin;

	return oss.str();
}


/*ostream & operator << (ostream & os, const Segment * s)
{
	return os;
}*/

