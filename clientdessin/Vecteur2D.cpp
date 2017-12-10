
#include <sstream>
#include "Vecteur2D.h"
#define M_PI 3.14159265358979323846


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

Vecteur2D Vecteur2D::operator+=(const Vecteur2D & u)
{
	_x += u._x;
	_y += u._y;
	return *this;

}

Vecteur2D & Vecteur2D::translation(const Vecteur2D & VectTrans)
{
	*this += VectTrans;
	return *this;

}

Vecteur2D & Vecteur2D::homothetie(const Vecteur2D & point, const double & rapport)
{
	_x = (_x - point._x) * rapport + point._x;
	_y = (_y - point._y) * rapport + point._y;
	return *this;
}

Vecteur2D & Vecteur2D::rotation(const Vecteur2D & centre, const double & angle)
{
	double result, result2;

	if ((angle != 90) || (angle != 270)) {
		result = cos(angle * M_PI / 180.0);
	}
	else {
		result = 0;
	}


	if ((angle != 180) || (angle != 360)) {
		result2 = sin(angle * M_PI / 180.0);
	}
	else {
		result2 = 0;
	}

	_x = (int)(result * (_x - centre._x) - result2 * (_y - centre._y)); 
	_y = (int)(result2 * (_x - centre._x) + result * (_y - centre._y));

		//_x = (int)(centre._x + _x * cos(angle) - centre._y *sin(angle));
		//_y = (int)(centre._x + _x * sin(angle) - centre._y *cos(angle));
		return *this;
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
	os << u._x << "," << u._y;
	return os;
}

