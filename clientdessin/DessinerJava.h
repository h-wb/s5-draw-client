#pragma once
/*
 * ClientDessin.h
 *
 *  Created on: 26 ao�t 2014
 *      Author: Dominique
 */


#include <WinSock2.h>
#include <string>
#include <string.h>
#include "VisiteurDessiner.h"

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
class DessinerJava : public VisiteurDessiner
{
SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole 
SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

public:
DessinerJava();
DessinerJava( const string & adresseServeurDessin, const int portServeurDessin);
~DessinerJava();

void ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur);

/**
    envoie sur une seule ligne les 5 param�tres au serveur.
 * Les 5 param�tres drawLine, ... , y2 sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
 *  * */
void traceSegment( const int x1, const int y1, const int x2, const int y2);

/**
envoie sur une seule ligne les 5 param�tres au serveur.
* Les 5 param�tres fillOval, ... , hauteur sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
*  * */
void remplitEllipse( const int bordGauche, const int bordHaut, const int largeur, const int hauteur);


void visite(const Rond * forme) const;

void visite(const Segment * forme) const;

};



