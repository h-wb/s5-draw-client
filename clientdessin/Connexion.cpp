#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Connexion.h"



Connexion::Connexion()
{
	}

Connexion::Connexion(const string & adresseServeurDessin, const int portServeurDessin)
{
	Singleton::getInstance();	// initialisation de la DLL : effectu�e une seule fois

								//---------------------- cr�ation socket -------------------------------------------------

	int r;

	int familleAdresses = AF_INET;         // IPv4
	int typeSocket = SOCK_STREAM;           // mode connect� TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
											// pour les valeurs des param�tres : cf. fct socket dans la doc sur winsock

	sock = socket(familleAdresses, typeSocket, protocole);

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

	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.

	if (r == SOCKET_ERROR)
		throw Erreur("La connexion a echou�");

	cout << "Connexion r�ussie" << endl;



	//------------------ envoi de la requ�te au serveur -------------------------------



}

void Connexion::envoyerRequete(const string requete)
{
	int r = send(sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------

	if (r == SOCKET_ERROR)
		throw Erreur("�chec de l'envoi de la requ�te d'ouverture de fen�tre graphique");

	cout << "requ�te d'ouverture de fen�tre graphique envoy�e" << endl;

}

Connexion::~Connexion()
{
	int r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
																// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

	if (r == SOCKET_ERROR)
		//throw Erreur("la coupure de connexion a �chou�");


		r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
														//if (r) throw Erreur("La fermeture du socket a �chou�");

	cout << "arr�t normal du client" << endl;
}
