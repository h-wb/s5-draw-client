#pragma once
#include "Forme.h"

/**
cf. classe JAVA de même nom

*/
class Croix: public Forme
{
double _gauche, _haut, _droit, _bas;
public:
							

/**
 * @param gauche
 * @param haut
 * @param droit
 * @param bas
 */
Croix( const double gauche, const double haut, const double droit, const double bas);


void dessiner(VisiteurDessiner * visiteurDessiner) const;
operator string() const;
double getGauche() const;
double getHaut() const;
double getDroit() const;
double getBas() const;
void setGauche(double);
void setHaut(double);
void setDroit(double);
void setBas(double);
};

