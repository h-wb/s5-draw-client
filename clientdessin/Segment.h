#pragma once
#include "Forme.h"

/**
cf. classe JAVA de m�me nom

*/
class Segment : public Forme
{
	double _x, _y;
public:


	/**
	* @param x
	* @param y
	*/
	Segment(const double x, const double y);


	void dessiner(VisiteurDessiner * visiteurDessiner) const;
	operator string() const;
	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);
};

