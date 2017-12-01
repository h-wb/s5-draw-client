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

	/**
	* @param couleur
	* @param centre
	* @param r
	*/
	Triangle(int couleur, const Vecteur2D& v1, const Vecteur2D& v2, const Vecteur2D& v3);
	Triangle(Triangle& t);



	void dessiner(VisiteurDessiner * visiteurDessiner) const;
	virtual Forme * translation(const Vecteur2D & VectTrans) const;
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport) const;
	virtual double aire() const;


	friend ostream & operator << (ostream & os, const Polygone * p);
};

