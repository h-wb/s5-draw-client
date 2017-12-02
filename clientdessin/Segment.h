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

	const string encoderForme() const;
	const string encoderFenetre() const;

	void dessiner(VisiteurDessiner * visiteurDessiner) const;
	virtual Forme * translation(const Vecteur2D & VectTrans) const;
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport) const;
	virtual double aire() const;
	virtual Forme * rotation(const Vecteur2D & centre, const double & angle) const;

	
	operator string() const;


	Vecteur2D getDebut() const;
	Vecteur2D getFin() const;
	void setDebut(Vecteur2D debut);
	void setFin(Vecteur2D fin);
	//friend ostream & operator << (ostream & os, const Segment * s);
};

