#pragma once

#define _USE_MATH_DEFINES 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include "Vecteur2D.h"

#define black 0;
#define blue 1;
#define red 2;
#define green 3;
#define yellow 4;
#define cyan 5;

using namespace std;

class VisiteurDessiner;
class Vecteur2D;
class VisiteurSauvegarde;

class Forme
{
private:
	int _couleur;

public:
	Forme(int couleur);
	Forme(const Forme &f);
	virtual ~Forme();

	virtual int getCouleur() const;
	virtual void setCouleur(int couleur);

	virtual Forme * translation(const Vecteur2D & VectTrans) const = 0;
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport) const = 0;
	virtual Forme * rotation(const Vecteur2D & centre, const double & angle) const = 0;
	virtual Forme * forme() const = 0;

	virtual  void dessiner( VisiteurDessiner * visiteurDessiner) const = 0;
	virtual const string encoderForme() const = 0;
	virtual const string encoderFenetre() const = 0;
	virtual double aire() const = 0;
	virtual void sauvegarder(VisiteurSauvegarde * visiteurSauvegarde) const = 0;
	
	friend ostream & operator << (ostream & os, const Forme * f);
};
