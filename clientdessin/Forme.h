#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"
#include <algorithm>
#define _USE_MATH_DEFINES 
#include <math.h>


#define black 0;
#define blue 1;
#define red 2;
#define green 3;
#define yellow 4;
#define cyan 5;

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

	virtual int getCouleur() const;
	virtual void setCouleur(int couleur);

	virtual const string encoderForme() const = 0;
	virtual const string encoderFenetre() const = 0;
	virtual  void dessiner( VisiteurDessiner * visiteurDessiner) const = 0;
	virtual operator string () const = 0;

	virtual double aire() const = 0;

	virtual Forme * translation(const Vecteur2D & VectTrans) const = 0;
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport) const = 0;
};

ostream & operator << (ostream & os, const Forme * forme);