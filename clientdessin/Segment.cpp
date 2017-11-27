
#include <sstream>
#include "VisiteurDessiner.h"
#include "Segment.h"

/**
* @param x
* @param y
*/
Segment::Segment(const double x, const double y) : _x(x), _y(y) {}

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

double Segment::getX() const
{
	return _x;
}

double Segment::getY() const
{
	return _y;
}

void Segment::setX(double x)
{
	_x = x;
}

void Segment::setY(double y)
{
	_y = y;
}