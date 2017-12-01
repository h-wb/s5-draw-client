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

	Vecteur2D oa, ob, oc, oap, obp, ocp;
	oa = point - _vecteurs[0];
	ob = point - _vecteurs[1];
	oc = point - _vecteurs[2];

	oap = oa * rapport;
	obp = ob * rapport;
	ocp = oc * rapport;

	return new Triangle(getCouleur(), oap + point, obp + point, ocp + point);

}

/*virtual*/ double Triangle::aire() const {
	double PuissanceAB, PuissanceAC, PuissanceBC;
	double LongAB, LongAC, LongBC;
	double S, aire;

	PuissanceAB = pow((_vecteurs[1].getX() - _vecteurs[0].getX()), 2) + pow((_vecteurs[1].getY() - _vecteurs[0].getY()),2);
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
