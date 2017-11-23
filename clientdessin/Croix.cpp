
#include <sstream>
#include "VisiteurDessiner.h"
#include "Croix.h"

/**
 * @param gauche
 * @param haut
 * @param droit
 * @param bas
 */
Croix::Croix( const double gauche, const double haut, const double droit, const double bas) : _gauche(gauche), _haut(haut), _droit(droit), _bas(bas) {}

void Croix::dessiner( VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

Croix::operator string() const
{
ostringstream oss;

oss << "Croix : "<< "gauche = "<< _gauche << ", haut = "<< _haut << ", droit = " << _droit <<  ", bas = " << _bas;

return oss.str();
}

double Croix::getGauche() const
{
	return _gauche;
}

double Croix::getHaut() const
{
	return _haut;
}

double Croix::getDroit() const
{
	return _droit;
}

double Croix::getBas() const
{
	return _bas;
}

void Croix::setGauche(double gauche)
{
	_gauche = gauche;
}

void Croix::setHaut(double haut)
{
	_haut = haut;
}

void Croix::setDroit(double droit)
{
	_droit = droit;
}

void Croix::setBas(double bas)
{
	_bas = bas;
}