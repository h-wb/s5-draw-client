
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

