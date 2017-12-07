#pragma once

#include "Forme.h"


class Segment : public Forme
{
private:
	Vecteur2D _debut, _fin;
public:
	Segment(const int couleur, const Vecteur2D & debut, const Vecteur2D & fin);
	Segment(const Segment &s);
	virtual ~Segment();

	Vecteur2D getDebut() const;
	void setDebut(Vecteur2D debut);
	Vecteur2D getFin() const;
	void setFin(Vecteur2D fin);

	virtual Forme * translation(const Vecteur2D & VectTrans);
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport);
	virtual Forme * rotation(const Vecteur2D & centre, const double & angle);
	virtual Forme * forme() const;
	virtual double aire() const;
	
	const string encoderForme() const;
	const string encoderFenetre() const;
	void sauvegardeJson() const;
	

	void dessiner(VisiteurDessiner * visiteurDessiner) const;	
	void sauvegarder(VisiteurSauvegarde * visiteurSauvegarde) const;
	friend ostream & operator << (ostream & os, const Segment * s);
};

