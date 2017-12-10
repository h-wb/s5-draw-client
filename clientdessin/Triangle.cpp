#include <sstream>
#include <fstream>
#include "Triangle.h"
#include "VisiteurDessiner.h"
#include "VisiteurSauvegarde.h"
#include "SauvegardeFormeJSON.h"
#include "json.hpp"

using json = nlohmann::json;

Triangle::Triangle(const int couleur, const Vecteur2D & v1, const Vecteur2D & v2, const Vecteur2D & v3) :Polygone(couleur)
{
	_vecteurs.push_back(v1);
	_vecteurs.push_back(v2);
	_vecteurs.push_back(v3);
	_cotes.push_back(Segment(couleur, v1, v2));
	_cotes.push_back(Segment(couleur, v2, v3));
	_cotes.push_back(Segment(couleur, v3, v1));
}

Triangle::Triangle(const Triangle & t) : Polygone(t)
{
	setVecteurs(t._vecteurs);
	setCotes(t._cotes);
}

Triangle::~Triangle()
{
}

Forme * Triangle::forme() const
{
	return new Triangle(*this);;
}

double Triangle::aire() const {
	double PuissanceAB, PuissanceAC, PuissanceBC;
	double LongAB, LongAC, LongBC;
	double S, aire;

	PuissanceAB = pow((_vecteurs[1].getX() - _vecteurs[0].getX()), 2) + pow((_vecteurs[1].getY() - _vecteurs[0].getY()), 2);
	LongAB = sqrt(PuissanceAB);

	PuissanceAC = pow((_vecteurs[2].getX() - _vecteurs[0].getX()), 2) + pow((_vecteurs[2].getY() - _vecteurs[0].getY()), 2);
	LongAC = sqrt(PuissanceAC);

	PuissanceBC = pow((_vecteurs[2].getX() - _vecteurs[1].getX()), 2) + pow((_vecteurs[2].getY() - _vecteurs[1].getY()), 2);
	LongBC = sqrt(PuissanceBC);

	//Formule de héron qui permet de calculer la hauteur du triangle puis par la suite l'aire du triangle
	//S = (a+b+c)/2 puis formule : aire = sqrt(S(S-a)(S-b)(S-c))

	S = (LongAB + LongAC + LongBC) / 2;
	aire = sqrt(S * (S - LongAB) * (S - LongAC) * (S - LongBC));

	return aire;
}

const string Triangle::encoderForme() const
{
	ostringstream oss;
	for (Segment s : _cotes) {
		oss << s.encoderForme();
	}
	return oss.str();
}

const string Triangle::encoderFenetre() const
{
	ostringstream oss;
	oss << "Triangle, " << 480 << ", " << 0 << ", " << 500 << ", " <<500 << "\r\n";
	return oss.str();
}

void Triangle::sauvegardeJson() const
{
	SauvegarderFormeJSON* test2 = new SauvegarderFormeJSON();
	test2->visite(this);
}

const void Triangle::sauvegardeTriangle() const
{
	SauvegarderFormeJSON* test2 = new SauvegarderFormeJSON();
	
	for (Segment s : _cotes) {
		test2->visite(&s);
	}
}

void Triangle::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}


ostream & operator << (ostream & os, const Triangle * t)
{
	return os << "Triangle : " << endl << t->encoderForme() << "\n";
}