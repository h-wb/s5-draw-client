#include <iostream>
#include "Singleton.h"
#include "Erreur.h"

using namespace std;

Singleton::Singleton() {
	int r;

	r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

													/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

	if (r) throw Erreur("L'initialisation a échoué");

	cout << "initialisation winsock effectuée" << endl;
}

Singleton::~Singleton()
{
	WSACleanup();
	cout << "libération des ressources de la winsock effectuée" << endl;
}
