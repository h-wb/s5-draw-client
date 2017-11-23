#pragma once
#include "Forme.h"
/**
 * Représente un cercle de centre (xCentre, yCentre) et de rayon "rayon"
 * 
 * 
 * */
class Rond : public Forme
{
double _xCentre, _yCentre, _rayon;
public:
/**
 * @param xCentre
 * @param yCentre
 * @param rayon
 */
Rond( const double xCentre,  const double yCentre,  const double rayon);

void dessiner(VisiteurDessiner * visiteurDessiner) const;

operator string() const;

double getxCentre() const;
double getyCentre() const;
double getRayon() const;
void setxCentre(double);
void setyCentre(double);
void setRayon(double);
};
