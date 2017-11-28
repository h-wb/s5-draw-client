#pragma once

#include <iostream>
#include <string>

#define red 0;

using namespace std;

class VisiteurDessiner;
class Vecteur2D;

/**
 * Hi�rarchie simplifi�e de formes en 2D
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