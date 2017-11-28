#pragma once
#include "Vecteur2D.h"
#include "Forme.h"
/**
 * Représente un cercle de centre (xCentre, yCentre) et de rayon "rayon"
 * 
 * 
 * */
class Rond : public Forme
{
private :
	Vecteur2D _centre;
	double _rayon;
public:
/**
 * @param xCentre
 * @param yCentre
 * @param rayon
 */
Rond(int couleur, Vecteur2D centre, double rayon);
Rond(Rond &r);

void dessiner(VisiteurDessiner * visiteurDessiner) const;

operator string() const;


Vecteur2D getCentre() const;
void setCentre(Vecteur2D v);
double getRayon() const;
void setRayon(double);
};
