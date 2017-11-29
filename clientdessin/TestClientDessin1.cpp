/*
* TestClientDessin1.cpp
*
*  Created on: 26 ao�t 2014
*      Author: Dominique
*
*
*  teste les fonctionnalit�s de la classe ClientDessin, � savoir :
*
*  1) envoyer une requ�te de cr�ation de fen�tre graphique nue titr�e
*  2) envoyer une requ�te de trac� de segment
*  3) envoyer une requ�te de dessin d'ellipse pleine
*
*/
#include <iostream>
#include <string>
#include "Erreur.h"
#include "DessinerJava.h"

#pragma comment(lib, "ws2_32.lib")

int main1()
{
	try
	{
/*
		string adresseServeur = "127.0.0.1";
		int portServeurDessin = 8091;

		DessinerJava dessinerJava(adresseServeur, portServeurDessin);


		string titre = "fen�tre ouverte par un client C++ distant";

		int bordGauche = 300;
		int bordHaut = 400;
		int largeur = 200;
		int hauteur = 300;

		dessinerJava.ouvreFenetreGraphique(titre, bordGauche, bordHaut, largeur, hauteur);

		int couleur = 2;
		int x1 = 180;
		int y1 = 40;
		int x2 = 40;
		int y2 = 180;

		dessinerJava.traceSegment(couleur, x1, y1, x2, y2);

		bordGauche = 40;
		bordHaut = 100;
		largeur = 70;
		hauteur = 70;

		//dessinerJava.remplitEllipse(bordGauche, bordHaut, largeur, hauteur);*/
	}
	catch (Erreur e)
	{
		cerr << e << endl;
	}

	char ch;
	cin >> ch;
	return 0;
}


