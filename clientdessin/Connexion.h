#pragma once

#include <WinSock2.h>
#include <string>
#include <string.h>
#include <sstream>
#include "Erreur.h"
#include "Singleton.h"


class Connexion
{
private:
	SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole 
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
public:
	Connexion();
	~Connexion();
	Connexion(const string & adresseServeurDessin, const int portServeurDessin);
	void envoyerRequete(const string);
};

