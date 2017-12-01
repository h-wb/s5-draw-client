#include <sstream>
#include "VisiteurDessiner.h"
#include "Rond.h"

#define PI 3.14159265358979323846

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
	
	aire = pow(getRayon(), 2) * PI;

	return aire;
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

