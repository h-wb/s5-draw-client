#include <fstream>
#include "SauvegardeFormeJSON.h"
#include "json.hpp"

using json = nlohmann::json;

SauvegarderFormeJSON::SauvegarderFormeJSON()
{
}

void SauvegarderFormeJSON::visite(const Forme * forme) const
{
	SauvegarderFormeJSON* test2 = new SauvegarderFormeJSON();
	test2->visite(forme);
}

void SauvegarderFormeJSON::visite(const Rond * forme) const
{
	json j2 = {
		{ "forme", "Rond" },
		{ "couleur", forme->getCouleur() },
		{"centre",{
			{"x", forme->getCentre().getX() },
			{"y", forme->getCentre().getY()}
		}},
		{ "hauteur", forme->getRayon() },
		{ "largeur", forme->getRayon() }
	};

	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	ostringstream oss;
	oss << "./sauvegarde/sauvegarde_" << aTime->tm_mday << "-" << aTime->tm_mon + 1 << "_" << aTime->tm_hour << "-" << aTime->tm_min << "-" << aTime->tm_sec << ".json";
	string str = oss.str();
	const char* chr = str.c_str();

	ofstream fichier(chr, ios::out | ios::app);
	if (fichier) {
		fichier << j2;
		fichier.close();
	}

	cout << "sauvegarde de rond réussie" << endl;
}

void SauvegarderFormeJSON::visite(const Segment * forme) const
{
	json j2 = {
		{ "forme", "Segment" },
		{ "couleur", forme->getCouleur() },
		{ "debut",{
			{ "x", forme->getDebut().getX() },
			{ "y", forme->getDebut().getY() }
		} },
		{ "fin",{
			{ "x", forme->getFin().getX() },
			{ "y", forme->getFin().getY() }
		} }
	};

	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	ostringstream oss;
	oss << "./sauvegarde/sauvegarde_" << aTime->tm_mday << "-" << aTime->tm_mon + 1 << "_" << aTime->tm_hour << "-" << aTime->tm_min << "-" << aTime->tm_sec << ".json";
	string str = oss.str();
	const char* chr = str.c_str();

	ofstream fichier(chr, ios::out | ios::app);
	if (fichier) {
		fichier << j2;
		fichier.close();
	}

	cout << "sauvegarde de Segment réussie" << endl;
}

void SauvegarderFormeJSON::visite(const Polygone * forme) const
{
	forme->sauvegardePolygone();
	cout << "sauvegarde du polygone réussie" << endl;
}

void SauvegarderFormeJSON::visite(const Triangle * forme) const
{
	forme->sauvegardeTriangle();
	cout << "sauvegarde de triangle réussie" << endl;
}

void SauvegarderFormeJSON::visite(const FormeComposee * forme) const
{
	forme->sauvegardeFormeComposee();
	cout << "sauvegarde de la forme composée réussie" << endl;
}
