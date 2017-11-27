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
public:
	double x, y;

	inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	* DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	*
	* */
	inline Vecteur2D(const char * s);
	inline const Vecteur2D operator + (const Vecteur2D & u) const;
	inline const Vecteur2D operator * (const double & a) const;
	/**
	* - unaire (c'est-à- dire opposé d'un vecteur)
	* */
	inline const Vecteur2D operator - () const;

	operator string() const;

}; // classe Vecteur2D

inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u*a; }
