#define _WINSOCK_DEPRECATED_NO_WARNINGS
/*
 * ClientDessin.cpp
 *
 *  Created on: 26 ao�t 2014
 *      Author: Dominique
 */

#include <winsock2.h>
#include <string.h>
#include <string>
#include <sstream>
#include "DessinerJava.h"



using namespace std;

/**
 * cr�e un client TCP/IP vers un serveur de dessin
 *
 * envoie 3 requ�tes possibles :
 *
 * ouvrir une fen�tre graphique
 * tracer un segment
 * tracer une ellipse pleine
 *
 * protocole : Chaque requ�te est cod�e sous forme d'une seule String se terminant par le caract�re fin de ligne.
 * Sur la ligne, 2 param�tres cons�cutifs sont s�par�s par ", ".
 *
 * */


DessinerJava::DessinerJava() 
{
}



void DessinerJava::visite(const Rond * forme) const
{	
	Connexion c(this->adresse, this->port);
	string requete = forme->encoderFenetre();
	c.envoyerRequete(requete);
	requete = forme->encoderForme();
	c.envoyerRequete(requete);
}

void DessinerJava::visite(const Segment * forme) const
{	
	Connexion c(this->adresse, this->port);
	string requete = forme->encoderFenetre();
	c.envoyerRequete(requete);
	requete = forme->encoderForme();
	c.envoyerRequete(requete);

}

void DessinerJava::visite(const Polygone * forme) const
{
	Connexion c(this->adresse, this->port);
	string requete = forme->encoderFenetre();
	c.envoyerRequete(requete);
	requete = forme->encoderForme();
	c.envoyerRequete(requete);
	
}

void DessinerJava::visite(const Triangle * forme) const
{
	Connexion c(this->adresse, this->port);
	string requete = forme->encoderFenetre();
	c.envoyerRequete(requete);
	requete = forme->encoderForme();
	c.envoyerRequete(requete);
}

void DessinerJava::visite(const FormeComposee * forme) const
{
	Connexion c(this->adresse, this->port);
	string requete = forme->encoderFenetre();
	c.envoyerRequete(requete);
	requete = forme->encoderForme();
	cout << forme->encoderForme();
	c.envoyerRequete(requete);

}
