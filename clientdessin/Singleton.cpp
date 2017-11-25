#include <iostream>
#include "Singleton.h"
#include "Erreur.h"

using namespace std;

Singleton::Singleton() {
	int r;

	r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

													/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

	if (r) throw Erreur("L'initialisation a �chou�");

	cout << "initialisation winsock effectu�e" << endl;
}

Singleton::~Singleton()
{
	WSACleanup();
	cout << "lib�ration des ressources de la winsock effectu�e" << endl;
}
