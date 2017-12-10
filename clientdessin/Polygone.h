#pragma once
#include "Forme.h"

class Segment;

class Polygone : public Forme
{
protected:
	vector<Vecteur2D> _vecteurs;
	vector<Segment> _cotes;	
public:
	Polygone(const int couleur);
	Polygone(const Polygone &p);
	virtual ~Polygone();

	virtual vector<Vecteur2D> getVecteurs() const;
	virtual void setVecteurs(vector<Vecteur2D> v);
	virtual vector<Segment> getCotes() const;
	virtual void setCotes(vector<Segment> s);

	Polygone operator=(const Polygone &p);
	Polygone& operator+=(const Vecteur2D &v);
	Polygone operator+(const Vecteur2D &v);

	virtual Forme * translation(const Vecteur2D & VectTrans);
	virtual Forme * homothetie(const Vecteur2D & point, const double & rapport);
	virtual Forme * rotation(const Vecteur2D & centre, const double & angle);
	virtual Forme * forme() const;
	virtual double aire() const;
	void Construction();

	const string encoderForme() const;
	const string encoderFenetre() const;

	void dessiner(VisiteurDessiner * visiteurDessiner) const; 
	void sauvegarder(VisiteurSauvegarde * visiteurSauvegarde) const;
	friend ostream & operator << (ostream & os, const Polygone * p);
};

