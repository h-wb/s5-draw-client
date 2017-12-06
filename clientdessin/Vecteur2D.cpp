
#include <sstream>
#include "Vecteur2D.h"

Vecteur2D::Vecteur2D(const double & x, const double & y) : _x(x), _y(y)
{

}

Vecteur2D::Vecteur2D(const char * s)
{

}

Vecteur2D::~Vecteur2D()
{
}

double Vecteur2D::getX() const
{
	return _x;
}

void Vecteur2D::setX(double x)
{
	_x = x;
}

double Vecteur2D::getY() const
{
	return _y;
}

void Vecteur2D::setY(double y)
{
	_y = y;
}

const Vecteur2D operator *(const double & a, const Vecteur2D & u)
{
	return u*a;
}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(_x + u._x, _y + u._y);
}

const Vecteur2D Vecteur2D::operator * (const double & a) const
{
	return Vecteur2D(_x*a, _y*a);
}

const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-_x, -_y);
}

const Vecteur2D Vecteur2D::operator - (const Vecteur2D & u) const {
	return Vecteur2D(u._x - _x, u._y - _y);
}

Vecteur2D & Vecteur2D::translation(const Vecteur2D & VectTrans)
{
	// TODO: insérer une instruction return ici
}

Vecteur2D & Vecteur2D::homothetie(const Vecteur2D & point, const double & rapport)
{
	// TODO: insérer une instruction return ici
}

Vecteur2D & Vecteur2D::rotation(const Vecteur2D & centre, const double & angle)
{
	// TODO: insérer une instruction return ici
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
	os << u._x << ", " << u._y;
	return os;
}

