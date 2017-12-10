#include "VisiteurDessiner.h"
#include "SauvegarderFormeTXT.h"
#include "Rond.h"

Rond::Rond(const int couleur, const Vecteur2D centre, const double rayon):Forme(couleur), _centre(centre)
{
	_rayon = rayon;
}

Rond::Rond(const Rond & r):Forme(r), _centre(r._centre)
{
	_rayon = r._rayon;
}

Rond::~Rond()
{
}

Vecteur2D Rond::getCentre() const
{
	return _centre;
}

void Rond::setCentre(Vecteur2D v)
{
	_centre = v;
}

double Rond::getRayon() const
{
	return _rayon;
}

void Rond::setRayon(double rayon)
{
	_rayon = rayon;
}

Forme * Rond::translation(const Vecteur2D & VectTrans){

	_centre.translation(VectTrans);
	return this;

}

Forme * Rond::homothetie(const Vecteur2D & point, const double & rapport) {

	_centre.homothetie(point, rapport);
	_rayon *= rapport;
	return this;

}

Forme * Rond::rotation(const Vecteur2D & centre, const double & angle){

	_centre.rotation(centre, angle);
	return this;

}

Forme * Rond::forme() const
{
	return new Rond(*this);;
}

double Rond::aire() const {
	double aire;
	aire = pow(getRayon(), 2) * M_PI;
	return aire;
}

const string Rond::encoderForme() const
{
	ostringstream oss;
	oss << "Rond," << getCouleur() << "," << getCentre() << "," << getRayon() << "," << getRayon() << "\r\n";
	return oss.str();
}

const string Rond::encoderFenetre() const
{
	ostringstream oss;
	oss << "Rond," << 0 << "," << 300 << "," << 500 << "," << 500 << "\r\n";
	return oss.str();
}

void Rond::dessiner( VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

ostream & operator << (ostream & os, const Rond * r)
{
	return os << r->encoderForme() << "\n";
}










