#pragma once
#include "Forme.h"
/**
* Représente un cercle de centre (xCentre, yCentre) et de rayon "rayon"
*
*
* */
class Polygone : public Forme
{
private:
	vector<Vecteur2D> pts;
	vector<Segment> cotes;	
	int _nbCotes;
public:
	/**
	* @param couleur
	* @param centre
	* @param rayon
	*/
	Polygone(int couleur, int nbCotes);
	Polygone(Polygone &p);


	void dessiner(VisiteurDessiner * visiteurDessiner) const;

	operator string() const;



	int getNbCotes() const;
	void setNbCotes(int);
};
