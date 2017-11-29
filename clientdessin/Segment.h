#pragma once
#include "Forme.h"

/**
cf. classe JAVA de même nom

*/
class Segment : public Forme
{
private:
	Vecteur2D _x, _y;
public:
	Segment(int couleur, Vecteur2D x, Vecteur2D y);
	Segment(Segment &s);
	/**
	* @param x
	* @param y
	*/




	void dessiner(VisiteurDessiner * visiteurDessiner) const;
	operator string() const;


	Vecteur2D getX() const;
	Vecteur2D getY() const;
	void setX(Vecteur2D x);
	void setY(Vecteur2D y);
};

