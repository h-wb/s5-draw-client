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

	virtual Forme * forme() const;
	virtual double aire() const;

	const string encoderForme() const;
	const string encoderFenetre() const;
	void sauvegardeJson() const;

	const void sauvegardeTriangle() const;
	void dessiner(VisiteurDessiner * visiteurDessiner) const;
	friend ostream & operator << (ostream & os, const Triangle * t);
};

