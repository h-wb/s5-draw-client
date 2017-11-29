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

