#define _WINSOCK_DEPRECATED_NO_WARNINGS
/*
 * ClientDessin.cpp
 *
 *  Created on: 26 août 2014
 *      Author: Dominique
 */

#include <winsock2.h>
#include <string.h>
#include <string>
#include <sstream>
#include "DessinerJava.h"



using namespace std;

/**
 * crée un client TCP/IP vers un serveur de dessin
 *
 * envoie 3 requêtes possibles :
 *
 * ouvrir une fenêtre graphique
 * tracer un segment
 * tracer une ellipse pleine
 *
 * protocole : Chaque requête est codée sous forme d'une seule String se terminant par le caractère fin de ligne.
 * Sur la ligne, 2 paramètres consécutifs sont séparés par ", ".
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
