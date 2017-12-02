#pragma once
#include "Forme.h"


class FormeComposee : public Forme
{
private:
	vector<Forme*> _formes;
public:
	FormeComposee(int couleur);
	FormeComposee(FormeComposee &f);
	FormeComposee operator= (const FormeComposee &f);
	FormeComposee& operator+= (Forme *f);
	FormeComposee operator+ (Forme *f);
	operator string() const;

	virtual Forme * translation(const Vecteur2D & VectTrans) const;
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport) const;
	virtual double aire() const;
	virtual Forme * rotation(const Vecteur2D & centre, const double & angle) const;


	const string encoderForme() const;
	const string encoderFenetre() const;


	virtual vector<Forme*> getFormes() const;
	virtual void setFormes(vector<Forme*> v);

	void dessiner(VisiteurDessiner * visiteurDessiner) const;
};

