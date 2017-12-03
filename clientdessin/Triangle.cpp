#include <sstream>
#include "Triangle.h"
#include "VisiteurDessiner.h"

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

Forme * Triangle::translation(const Vecteur2D & VectTrans) const {

	return new Triangle(getCouleur(), VectTrans + _vecteurs[0], VectTrans + _vecteurs[1], VectTrans + _vecteurs[2]);

}

Forme * Triangle::homothetie(const Vecteur2D & point, const double & rapport) const {

	Vecteur2D oa, ob, oc, oap, obp, ocp;
	oa = point - _vecteurs[0];
	ob = point - _vecteurs[1];
	oc = point - _vecteurs[2];

	oap = oa * rapport;
	obp = ob * rapport;
	ocp = oc * rapport;

	return new Triangle(getCouleur(), oap + point, obp + point, ocp + point);

}

Forme * Triangle::rotation(const Vecteur2D & centre, const double & angle) const {
	if ((angle > 0) && (angle < 360)) {
		double Axprime, Ayprime, Bxprime, Byprime, Cxprime, Cyprime;
		double result, result2;
		Vecteur2D cote1, cote2, cote3;

		if ((angle != 90) || (angle != 270)) {
			result = cos(angle * M_PI / 180.0);
		}
		else {
			result = 0;
		}


		if ((angle != 180) || (angle != 360)) {
			result2 = sin(angle * M_PI / 180.0);
		}
		else {
			result2 = 0;
		}


		Axprime = result * (_vecteurs[0].getX() - centre.getX()) - result2 * (_vecteurs[0].getY() - centre.getY()) + centre.getX();
		Ayprime = result2 * (_vecteurs[0].getX() - centre.getX()) + result * (_vecteurs[0].getY() - centre.getY()) + centre.getY();

		Bxprime = result * (_vecteurs[1].getX() - centre.getX()) - result2 * (_vecteurs[1].getY() - centre.getY()) + centre.getX();
		Byprime = result2 * (_vecteurs[1].getX() - centre.getX()) + result * (_vecteurs[1].getY() - centre.getY()) + centre.getY();

		Cxprime = result * (_vecteurs[2].getX() - centre.getX()) - result2 * (_vecteurs[2].getY() - centre.getY()) + centre.getX();
		Cyprime = result2 * (_vecteurs[2].getX() - centre.getX()) + result * (_vecteurs[2].getY() - centre.getY()) + centre.getY();

		cote1 = Vecteur2D(round(Axprime), round(Ayprime));
		cote2 = Vecteur2D(round(Bxprime), round(Byprime));
		cote3 = Vecteur2D(round(Cxprime), round(Cyprime));

		return new Triangle(getCouleur(), cote1, cote2, cote3);
	}
	else {
		throw invalid_argument("Veuillez entrer un angle entre 0 et 360");
	}

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

void Triangle::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

ostream & operator << (ostream & os, const Triangle * t)
{
	return os << "Triangle : " << endl << t->encoderForme() << "\n";
}