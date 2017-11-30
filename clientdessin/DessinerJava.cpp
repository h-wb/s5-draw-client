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
#include "Erreur.h"
#include "Singleton.h"
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

DessinerJava::DessinerJava( const string & adresseServeurDessin, const int portServeurDessin)
{
	Singleton::getInstance();	// initialisation de la DLL : effectu�e une seule fois


//---------------------- cr�ation socket -------------------------------------------------

int r;

int familleAdresses = AF_INET;         // IPv4
int typeSocket = SOCK_STREAM;           // mode connect� TCP
int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
                                        // pour les valeurs des param�tres : cf. fct socket dans la doc sur winsock

sock =  socket( familleAdresses, typeSocket, protocole);

if (sock == INVALID_SOCKET)
  {
  ostringstream oss;
  oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
  //throw Erreur(oss.str().c_str());
  }

cout << "socket de dessin cr��" << endl;

//------------------------------ cr�ation du repr�sentant du serveur ----------------------------------------

sockaddr.sin_family = AF_INET;
sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());   // inet_addr() convertit de l'ASCII en entier
sockaddr.sin_port = htons((short)portServeurDessin);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

//-------------- connexion du client au serveur ---------------------------------------

r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
                                                                // Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

if (r == SOCKET_ERROR)
  //throw Erreur("La connexion au serveur de dessin a �chou�");

cout << "connexion au serveur de dessin r�ussie" << endl;
}

DessinerJava::~DessinerJava()
{
int r = shutdown(sock,SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
													// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

if (r == SOCKET_ERROR)
	//throw Erreur("la coupure de connexion a �chou�");


r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
//if (r) throw Erreur("La fermeture du socket a �chou�");

cout << "arr�t normal du client" << endl;
}

// il y a une GROSSE redondance de code (ou autrement dit un GROS copi�-coll� pourri) sur les 3 m�thodes suivantes : elle doit �tre �limin�e !!!!!!!
// cf. classe JAVA ClientDessin - m�thode encoder()

void DessinerJava::ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
ostringstream oss;

oss << titre << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("�chec de l'envoi de la requ�te d'ouverture de fen�tre graphique");

cout << "requ�te d'ouverture de fen�tre graphique envoy�e" << endl;
}

/**
    envoie sur une seule ligne les 5 param�tres au serveur.
 * Les 5 param�tres drawLine, ... , y2 sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
 *  * */
void DessinerJava::traceSegment(const int couleur, const int x1, const int y1, const int x2, const int y2)
{
ostringstream oss;

oss << "drawLine, " << couleur << ", " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("�chec de l'envoi de la requ�te de trac� de segment");

cout << "requ�te de trac� de segment envoy�e" << endl;
}

/**
envoie sur une seule ligne les 5 param�tres au serveur.
* Les 5 param�tres fillOval, ... , hauteur sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
*  * */
void DessinerJava::remplitEllipse(const int couleur, const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
ostringstream oss;

oss << "fillOval" << ", " << couleur << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("�chec de l'envoi de la requ�te de trac� de segment");

cout << "requ�te de trac� de segment envoy�e" << endl;
}

/*void DessinerJava::visite(const Croix * forme) const
{
	DessinerJava c("127.0.0.1", 8091);
	int marge, largeur, hauteur;

	largeur = (int)(forme->getDroit() - forme->getGauche());
	hauteur = (int)(forme->getBas() - forme->getHaut());
	marge = 50;
	c.ouvreFenetreGraphique("croix client C++", (int)forme->getGauche() - marge, (int)forme->getHaut() - marge, largeur + 2 * marge, hauteur + 2 * marge);

	c.traceSegment(marge, marge, marge + largeur, marge + hauteur);
	c.traceSegment(marge, marge + hauteur, marge + largeur, marge);
}*/

void DessinerJava::visite(const Rond * forme) const
{
	DessinerJava c("127.0.0.1", 8091);
	int marge = 50;
	int largeur, hauteur;
	largeur = hauteur = (int)(2 * forme->getRayon());
	int bordGauche, bordHaut;

	bordGauche = (forme->getCentre().getX() - forme->getRayon());
	bordHaut = (forme->getCentre().getY() - forme->getRayon());
	c.ouvreFenetreGraphique("rond client C++", bordGauche - marge, bordHaut - marge, largeur + 2 * marge, hauteur + 2 * marge);

	c.remplitEllipse(forme->getCouleur(), forme->getCentre().getX(), forme->getCentre().getY(), 2*forme->getRayon(), 2*forme->getRayon());
}

void DessinerJava::visite(const Segment * forme) const
{
	DessinerJava c("127.0.0.1", 8091);
	int marge, largeur, hauteur;
	
	largeur = (int)(forme->getDebut().getX() + forme->getDebut().getY());
	//hauteur = (int)(forme->getY().getY() + forme->getY().getX());
	largeur = (int)(forme->getFin().getX());
	hauteur = (int)(forme->getFin().getY());
	marge = 50;
	c.ouvreFenetreGraphique("segment client C++", (int)forme->getDebut().getX() - marge, (int)forme->getDebut().getY() -  marge, largeur +2 * marge, hauteur +2 * marge);
	//c.ouvreFenetreGraphique("segment client C++",200, 200, 200,200);
	c.traceSegment(forme->getCouleur(), forme->getDebut().getX(), forme->getDebut().getY(), forme->getFin().getX(), forme->getFin().getY());
	

}

void DessinerJava::visite(const Polygone * forme) const
{
	DessinerJava c("127.0.0.1", 8091);
	vector<Segment> s = forme->getCotes();
	cout << forme->getVecteur().size();
	c.ouvreFenetreGraphique("polygone client C++", 500, 500, 500, 500);
	for(int i=1; i<s.size(); i++){
		c.traceSegment(forme->getCouleur(), s[i-1].getDebut().getX(), s[i - 1].getDebut().getY(), s[i-1].getFin().getX(), s[i-1].getFin().getY());
	}
	c.traceSegment(forme->getCouleur(), s[s.size()-1].getDebut().getX(), s[s.size()-1].getDebut().getY(), s[s.size() - 1].getFin().getX(), s[s.size()-1].getFin().getY());
	//c.traceSegment(2, s[3].getX().getX(), s[3].getX().getY(), s[3].getY().getX(), s[3].getY().getY());
	//cout << s[2].getX().getX() << s[2].getX().getY() << s[2].getY().getX() << s[2].getY().getY();
}
