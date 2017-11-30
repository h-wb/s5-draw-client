#pragma once
#include "Vecteur2D.h"
#include "Forme.h"

/**
cf. classe JAVA de même nom

*/
class Segment : public Forme
{
private:
	Vecteur2D _debut, _fin;
public:
	Segment(const int couleur, const Vecteur2D & debut, const Vecteur2D & fin) :Forme(couleur), _debut(debut), _fin(fin) {}

	Segment(const Segment &s);
	/**
	* @param debut
	* @param fin
	*/

	void dessiner(VisiteurDessiner * visiteurDessiner) const;
	virtual Forme * translation(const Vecteur2D & VectTrans) const;
	
	operator string() const;


	Vecteur2D getDebut() const;
	Vecteur2D getFin() const;
	void setDebut(Vecteur2D debut);
	void setFin(Vecteur2D fin);
	friend ostream & operator << (ostream & os, const Segment * s);
};

