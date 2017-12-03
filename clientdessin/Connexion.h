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
	SOCKET sock;
	SOCKADDR_IN sockaddr;
public:
	Connexion();
	Connexion(const string & adresseServeurDessin, const int portServeurDessin);
	~Connexion();

	void envoyerRequete(const string);
};

