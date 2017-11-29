
#include <sstream>
#include "VisiteurDessiner.h"
#include "Segment.h"



Segment::Segment(int couleur, Vecteur2D x, Vecteur2D y):Forme(couleur), _x(x), _y(y)
{

}

Segment::Segment(Segment & s) : Forme(s), _x(s._x), _y(s._y)
{

}

/**
* @param x
* @param y
*/

Vecteur2D Segment::getX() const
{
	return _x;
}

Vecteur2D Segment::getY() const
{
	return _y;
}

void Segment::setX(Vecteur2D x)
{
	_x = x;
}

void Segment::setY(Vecteur2D y)
{
	_y = y;
}

void Segment::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}


Segment::operator string() const
{
	ostringstream oss;

	oss << "Segment : " << "x = " << _x << ", y = " << _y;

	return oss.str();
}

