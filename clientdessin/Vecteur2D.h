#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}



class Vecteur2D
{
private:
	double _x, _y;
public:
	Vecteur2D(const double & x = 0, const double & y = 0);
	Vecteur2D(const char * s);
	virtual ~Vecteur2D();

	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);

	const Vecteur2D operator + (const Vecteur2D & u) const;
	const Vecteur2D operator * (const double & a) const;
	const Vecteur2D operator - () const;
	const Vecteur2D operator - (const Vecteur2D & u) const;

	Vecteur2D& translation(const Vecteur2D & VectTrans);
	Vecteur2D& homothetie(const Vecteur2D & point, const double & rapport);
	Vecteur2D& rotation(const Vecteur2D & centre, const double & angle);
	
	friend ostream& operator<<(ostream &o, const Vecteur2D &v);
};
