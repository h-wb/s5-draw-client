
#include <iostream>
#include "Erreur.h"
#include "Forme.h"


using namespace std;
	
Forme::Forme(int couleur)
{
	_couleur = couleur;
}

Forme::Forme(const Forme & f)
{
	_couleur = f._couleur;
}

int Forme::getCouleur() const
{
	return _couleur;
}

void Forme::setCouleur(int couleur)
{
	_couleur = couleur;
}

ostream & operator << (ostream & os, const Forme * forme)
{
return os << (string)(*forme);
}