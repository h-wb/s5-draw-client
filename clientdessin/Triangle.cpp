#include "Triangle.h"
#include "VisiteurDessiner.h"

Triangle::Triangle(int couleur, const Vecteur2D & v1, const Vecteur2D & v2, const Vecteur2D & v3) :Polygone(couleur)
{
	_vecteurs.push_back(v1);
	_vecteurs.push_back(v2);
	_vecteurs.push_back(v3);
	_cotes.push_back(Segment(couleur, v1, v2));
	_cotes.push_back(Segment(couleur, v2, v3));
	_cotes.push_back(Segment(couleur, v3, v1));
}

Triangle::Triangle(Triangle & t) : Polygone(t)
{
	setVecteurs(t._vecteurs);
	setCotes(t._cotes);
}


void Triangle::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

/*virtual*/ Forme * Triangle::translation(const Vecteur2D & VectTrans) const {

	return new Triangle(getCouleur(), VectTrans + _vecteurs[0], VectTrans + _vecteurs[1], VectTrans + _vecteurs[2]);

}

/*virtual*/ Forme * Triangle::homothetie(const Vecteur2D & point, const double & rapport) const {

	return new Triangle(getCouleur(), point + _vecteurs[0], point + _vecteurs[1], point + _vecteurs[2]);

}
