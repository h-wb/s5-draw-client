#pragma once
#include "Forme.h"

class Rond : public Forme
{
private :
	Vecteur2D _centre;
	double _rayon;
public:
	Rond(const int couleur, const Vecteur2D centre, const double rayon);
	Rond(const Rond &r);
	virtual ~Rond();

	Vecteur2D getCentre() const;
	void setCentre(Vecteur2D v);
	double getRayon() const;
	void setRayon(double);

	virtual Forme * translation(const Vecteur2D & VectTrans) const;
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport) const;
	virtual Forme * rotation(const Vecteur2D & centre, const double & angle) const;
	virtual Forme * forme() const;
	virtual double aire() const;

	const string encoderForme() const;
	const string encoderFenetre() const;

	void dessiner(VisiteurDessiner * visiteurDessiner) const;

	friend ostream & operator << (ostream & os, const Rond * r);
};
