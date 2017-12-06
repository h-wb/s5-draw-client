#pragma once
#include "Forme.h"


class FormeComposee : public Forme
{
private:
	vector<Forme*> _formes;

public:
	FormeComposee(const int couleur);
	FormeComposee(const FormeComposee &f);
	virtual ~FormeComposee();

	virtual vector<Forme*> getFormes() const;
	virtual void setFormes(vector<Forme*> v);

	FormeComposee operator= (const FormeComposee &f);
	FormeComposee& operator+= (Forme *f);
	FormeComposee operator+ (const Forme &f);

	virtual Forme * translation(const Vecteur2D & VectTrans);
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport);
	virtual Forme * rotation(const Vecteur2D & centre, const double & angle);
	virtual Forme * forme() const;
	virtual double aire() const;
	

	const string encoderForme() const;
	const string encoderFenetre() const;
	

	void dessiner(VisiteurDessiner * visiteurDessiner) const;

	friend ostream & operator << (ostream & os, const FormeComposee * fc);
};

