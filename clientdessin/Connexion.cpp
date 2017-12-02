#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Connexion.h"



Connexion::Connexion()
{
	}

Connexion::Connexion(const string & adresseServeurDessin, const int portServeurDessin)
{
	Singleton::getInstance();	// initialisation de la DLL : effectuée une seule fois

								//---------------------- création socket -------------------------------------------------

	int r;

	int familleAdresses = AF_INET;         // IPv4
	int typeSocket = SOCK_STREAM;           // mode connecté TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
											// pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

	sock = socket(familleAdresses, typeSocket, protocole);

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

	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.

	if (r == SOCKET_ERROR)
		throw Erreur("La connexion a echoué");

	cout << "Connexion réussie" << endl;



	//------------------ envoi de la requête au serveur -------------------------------



}

void Connexion::envoyerRequete(const string requete)
{
	int r = send(sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requête au serveur -------------------------------

	if (r == SOCKET_ERROR)
		throw Erreur("échec de l'envoi de la requête d'ouverture de fenêtre graphique");

	cout << "requête d'ouverture de fenêtre graphique envoyée" << endl;

}

Connexion::~Connexion()
{
	int r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
																// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

	if (r == SOCKET_ERROR)
		//throw Erreur("la coupure de connexion a échoué");


		r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
														//if (r) throw Erreur("La fermeture du socket a échoué");

	cout << "arrêt normal du client" << endl;
}
