#pragma once
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
 * @param couleur
 * @param centre
 * @param rayon
 */
Rond(int couleur, Vecteur2D centre, double rayon);
Rond(Rond &r);

void dessiner(VisiteurDessiner * visiteurDessiner) const;

operator string() const;
virtual Forme * translation(const Vecteur2D & VectTrans) const;
virtual Forme * homothetie(const Vecteur2D & point, const double & rapport) const;
virtual double aire() const;


Vecteur2D getCentre() const;
void setCentre(Vecteur2D v);
double getRayon() const;
void setRayon(double);

};
