#include "VisiteurDessiner.h"
#include "SauvegarderFormeTXT.h"
#include "Rond.h"

Rond::Rond(const int couleur, const Vecteur2D centre, const double rayon):Forme(couleur), _centre(centre)
{
	_rayon = rayon;
}

Rond::Rond(const Rond & r):Forme(r), _centre(r._centre)
{
	_rayon = r._rayon;
}

Rond::~Rond()
{
}

Vecteur2D Rond::getCentre() const
{
	return _centre;
}

void Rond::setCentre(Vecteur2D v)
{
	_centre = v;
}

double Rond::getRayon() const
{
	return _rayon;
}

void Rond::setRayon(double rayon)
{
	_rayon = rayon;
}

Forme * Rond::translation(const Vecteur2D & VectTrans){

	//return new Rond(getCouleur(), VectTrans + _centre, getRayon());
	_centre.translation(VectTrans);
	return this;

}

Forme * Rond::homothetie(const Vecteur2D & point, const double & rapport) {

	/*Vecteur2D oa, oap;
	oa = point - _centre;
	oap = oa * rapport;
	return new Rond(getCouleur(), oap, rapport * getRayon());*/
	_centre.homothetie(point, rapport);
	_rayon *= rapport;
	return this;

}

Forme * Rond::rotation(const Vecteur2D & centre, const double & angle){


	/*if ((angle > 0) && (angle < 360)) {
		double Centxprime, Centyprime;
		double result, result2;
		Vecteur2D CentRot;

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


		Centxprime = result * (_centre.getX() - centre.getX()) - result2 * (_centre.getY() - centre.getY()) + centre.getX();
		Centyprime = result2 * (_centre.getX() - centre.getX()) + result * (_centre.getY() - centre.getY()) + centre.getY();

		CentRot = Vecteur2D(round(Centxprime), round(Centyprime));

		return new Rond(getCouleur(), CentRot, getRayon());
	}
	else {
		throw invalid_argument("Veuillez entrer un angle entre 0 et 360");
	}*/

	_centre.rotation(centre, angle);
	return this;

}

Forme * Rond::forme() const
{
	return new Rond(*this);;
}

double Rond::aire() const {
	double aire;
	aire = pow(getRayon(), 2) * M_PI;
	return aire;
}

const string Rond::encoderForme() const
{
	ostringstream oss;
	oss << "Rond, " << getCouleur() << ", " << getCentre() << ", " << getRayon() << ", " << getRayon() << "\r\n";
	return oss.str();
}

const string Rond::encoderFenetre() const
{
	ostringstream oss;
	oss << "Rond, " << 0 << ", " << 300 << ", " << 500 << ", " << 500 << "\r\n";
	return oss.str();
}

void Rond::dessiner( VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

ostream & operator << (ostream & os, const Rond * r)
{
	return os << r->encoderForme() << "\n";
}










