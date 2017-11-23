#pragma once

#include <iostream>
#include <string>

using namespace std;

class VisiteurDessiner;

/**
 * Hi�rarchie simplifi�e de formes en 2D
 * 
 * */
class Forme
{
public:

void dessiner() const;

virtual  void dessiner( VisiteurDessiner * visiteurDessiner) const = 0;


virtual operator string () const = 0;

};

ostream & operator << (ostream & os, const Forme * forme);