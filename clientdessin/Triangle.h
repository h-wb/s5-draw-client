#pragma once
#include "Polygone.h"

/**
* Représente un cercle de centre (xCentre, yCentre) et de rayon "rayon"
*
*
* */
class Triangle : public Polygone
{
public:
	Triangle(const int couleur, const Vecteur2D& v1, const Vecteur2D& v2, const Vecteur2D& v3);
	Triangle(const Triangle& t);
	virtual ~Triangle();

	virtual Forme * translation(const Vecteur2D & VectTrans) const;
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport) const;
	virtual Forme * rotation(const Vecteur2D & centre, const double & angle) const;
	virtual Forme * forme() const;
	virtual double aire() const;

	const string encoderForme() const;
	const string encoderFenetre() const;

	void dessiner(VisiteurDessiner * visiteurDessiner) const;
	void sauvegarder(VisiteurSauvegarde * visiteurSauvegarde) const;
	friend ostream & operator << (ostream & os, const Triangle * t);
};

