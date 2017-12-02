#include <sstream>
#include "VisiteurDessiner.h"
#include "Rond.h"

/**
 * @param xCentre
 * @param yCentre
 * @param rayon
 */



Rond::Rond(int couleur, Vecteur2D centre, double rayon):Forme(couleur), _centre(centre)
{
	_rayon = rayon;
}

Rond::Rond(Rond & r):Forme(r), _centre(r._centre)
{
	_rayon = r._rayon;
}

void Rond::dessiner( VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

Rond::operator string() const
{
ostringstream oss;

oss << "Rond : "<<"Centre = " << _centre <<", rayon = " << _rayon;

return oss.str();
}

/*virtual*/ Forme * Rond::translation(const Vecteur2D & VectTrans) const {

	return new Rond(getCouleur(), VectTrans + _centre, getRayon());

}

/*virtual*/ Forme * Rond::homothetie(const Vecteur2D & point, const double & rapport) const {

	Vecteur2D oa, oap;
	oa = point - _centre;
	oap = oa * rapport;
	return new Rond(getCouleur(), oap, rapport * getRayon());

}

/*virtual*/ double Rond::aire() const {
	double aire;

	aire = pow(getRayon(), 2) * M_PI;

	return aire;
}

/*virtual*/ Forme * Rond::rotation(const Vecteur2D & centre, const double & angle) const {


	if ((angle > 0) && (angle < 360)) {
		double Centxprime, Centyprime;
		double result, result2;
		Vecteur2D CentRot;

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


		Centxprime = result * (_centre.getX() - centre.getX()) - result2 * (_centre.getY() - centre.getY()) + centre.getX();
		Centyprime = result2 * (_centre.getX() - centre.getX()) + result * (_centre.getY() - centre.getY()) + centre.getY();

		CentRot = Vecteur2D(Centxprime, Centyprime);

		return new Rond(getCouleur(), CentRot, getRayon());
	}
	else {
		throw invalid_argument("Veuillez entrer un angle entre 0 et 360");
	}

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