#pragma once

#include <WinSock2.h>
#include <string>
#include <string.h>
#include "Erreur.h"
#include "Singleton.h"
#include "VisiteurDessiner.h"
#include "Connexion.h"


using namespace std;

class DessinerJava : public VisiteurDessiner
{
private:
	string adresse = "127.0.0.1";
	int port = 8091;
public:
	DessinerJava();
	void visite(const Rond * forme) const;
	void visite(const Segment * forme) const;
	void visite(const Polygone * forme) const;
	void visite(const Triangle * forme) const;
	void visite(const FormeComposee * forme) const;
};



