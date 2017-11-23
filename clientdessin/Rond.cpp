#include <sstream>
#include "VisiteurDessiner.h"
#include "Rond.h"

/**
 * @param xCentre
 * @param yCentre
 * @param rayon
 */
Rond::Rond( const double xCentre, const double yCentre, const double rayon) : _xCentre (xCentre), _yCentre (yCentre), _rayon (rayon) {}


void Rond::dessiner( VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

Rond::operator string() const
{
ostringstream oss;

oss << "Rond : "<<"xCentre = " << _xCentre << ", yCentre = " << _yCentre <<", rayon = " << _rayon;

return oss.str();
}

double Rond::getxCentre() const
{
	return _xCentre;
}

double Rond::getyCentre() const
{
	return _yCentre;
}

double Rond::getRayon() const
{
	return _rayon;
}

void Rond::setxCentre(double xCentre)
{
	_xCentre = xCentre;
}

void Rond::setyCentre(double yCentre)
{
	_yCentre = yCentre;
}

void Rond::setRayon(double rayon)
{
	_rayon = rayon;
}
