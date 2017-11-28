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


	const Vecteur2D operator + (const Vecteur2D & u) const;
	const Vecteur2D operator * (const double & a) const;
	const Vecteur2D operator - () const;

	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);

	operator string() const;
	
};

ostream& operator<<(ostream &o, const Vecteur2D &v);