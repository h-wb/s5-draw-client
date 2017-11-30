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
#include "Erreur.h"
#include "Singleton.h"
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

DessinerJava::DessinerJava( const string & adresseServeurDessin, const int portServeurDessin)
{
	Singleton::getInstance();	// initialisation de la DLL : effectuée une seule fois


//---------------------- création socket -------------------------------------------------

int r;

int familleAdresses = AF_INET;         // IPv4
int typeSocket = SOCK_STREAM;           // mode connecté TCP
int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
                                        // pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

sock =  socket( familleAdresses, typeSocket, protocole);

if (sock == INVALID_SOCKET)
  {
  ostringstream oss;
  oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
  //throw Erreur(oss.str().c_str());
  }

cout << "socket de dessin créé" << endl;

//------------------------------ création du représentant du serveur ----------------------------------------

sockaddr.sin_family = AF_INET;
sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());   // inet_addr() convertit de l'ASCII en entier
sockaddr.sin_port = htons((short)portServeurDessin);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

//-------------- connexion du client au serveur ---------------------------------------

r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
                                                                // Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

if (r == SOCKET_ERROR)
  //throw Erreur("La connexion au serveur de dessin a échoué");

cout << "connexion au serveur de dessin réussie" << endl;
}

DessinerJava::~DessinerJava()
{
int r = shutdown(sock,SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
													// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

if (r == SOCKET_ERROR)
	//throw Erreur("la coupure de connexion a échoué");


r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
//if (r) throw Erreur("La fermeture du socket a échoué");

cout << "arrêt normal du client" << endl;
}

// il y a une GROSSE redondance de code (ou autrement dit un GROS copié-collé pourri) sur les 3 méthodes suivantes : elle doit être éliminée !!!!!!!
// cf. classe JAVA ClientDessin - méthode encoder()

void DessinerJava::ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
ostringstream oss;

oss << titre << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requête au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("échec de l'envoi de la requête d'ouverture de fenêtre graphique");

cout << "requête d'ouverture de fenêtre graphique envoyée" << endl;
}

/**
    envoie sur une seule ligne les 5 paramètres au serveur.
 * Les 5 paramètres drawLine, ... , y2 sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", "
 *  * */
void DessinerJava::traceSegment(const int couleur, const int x1, const int y1, const int x2, const int y2)
{
ostringstream oss;

oss << "drawLine, " << couleur << ", " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requête au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("échec de l'envoi de la requête de tracé de segment");

cout << "requête de tracé de segment envoyée" << endl;
}

/**
envoie sur une seule ligne les 5 paramètres au serveur.
* Les 5 paramètres fillOval, ... , hauteur sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", "
*  * */
void DessinerJava::remplitEllipse(const int couleur, const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
ostringstream oss;

oss << "fillOval" << ", " << couleur << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requête au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("échec de l'envoi de la requête de tracé de segment");

cout << "requête de tracé de segment envoyée" << endl;
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
