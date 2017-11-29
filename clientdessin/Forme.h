#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"


#define RED 0;
#define BLUE 1;
#define GREEN 2;

using namespace std;

class VisiteurDessiner;
class Vecteur2D;

/**
 * Hiérarchie simplifiée de formes en 2D
 * 
 * */
class Forme
{
private:
	int _couleur;
public:
	Forme(int couleur);
	Forme(const Forme &f);

	void dessiner() const;

	virtual int getCouleur() const;
	virtual void setCouleur(int couleur);


	virtual  void dessiner( VisiteurDessiner * visiteurDessiner) const = 0;
	virtual operator string () const = 0;

};

ostream & operator << (ostream & os, const Forme * forme);