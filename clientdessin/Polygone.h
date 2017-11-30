#pragma once
#include "Forme.h"

class Segment;

/**
* Représente un cercle de centre (xCentre, yCentre) et de rayon "rayon"
*
*
* */
class Polygone : public Forme
{
private:
	vector<Vecteur2D> _vecteur;
	vector<Segment> _cotes;	
	int _nbCotes;
public:
	
	/**
	* @param couleur
	* @param centre
	* @param rayon
	*/
	Polygone(int couleur);
	Polygone(Polygone &p);
	void Construction();


	void dessiner(VisiteurDessiner * visiteurDessiner) const;

	operator string() const;

	//Polygone& operator=(const Polygone &p);
	Polygone& operator+=(const Vecteur2D &v);
	//Polygone& operator+(const Vecteur2D &v);


	virtual vector<Vecteur2D> getVecteur() const;
	virtual void setVecteur(vector<Vecteur2D> v);
	virtual vector<Segment> getCotes() const;
	virtual void setCotes(vector<Segment> s);

	int getNbCotes() const;
	void setNbCotes(int);
	friend ostream & operator << (ostream & os, const Polygone * p);
};

