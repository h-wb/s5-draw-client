#include "DessinerJava.h"

DessinerJava::DessinerJava() 
{
}

void DessinerJava::visite(const Rond * forme) const
{	
	Connexion c(this->adresse, this->port);
	c.envoyerRequete(forme->encoderFenetre());
	c.envoyerRequete(forme->encoderForme());
}

void DessinerJava::visite(const Segment * forme) const
{	
	Connexion c(this->adresse, this->port);
	c.envoyerRequete(forme->encoderFenetre());
	c.envoyerRequete(forme->encoderForme());
}

void DessinerJava::visite(const Polygone * forme) const
{
	Connexion c(this->adresse, this->port);
	c.envoyerRequete(forme->encoderFenetre());
	c.envoyerRequete(forme->encoderForme());
}

void DessinerJava::visite(const Triangle * forme) const
{
	Connexion c(this->adresse, this->port);
	c.envoyerRequete(forme->encoderFenetre());
	c.envoyerRequete(forme->encoderForme());
}

void DessinerJava::visite(const FormeComposee * forme) const
{
	Connexion c(this->adresse, this->port);
	c.envoyerRequete(forme->encoderFenetre());
	c.envoyerRequete(forme->encoderForme());
}
