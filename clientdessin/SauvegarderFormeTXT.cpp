#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "SauvegarderFormeTXT.h"


SauvegarderFormeTXT::SauvegarderFormeTXT(){

}

void SauvegarderFormeTXT::sauvegarde(const Forme * forme) const
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	ostringstream oss;
	oss << "./sauvegarde/sauvegarde_" << aTime->tm_mday << "-" << aTime->tm_mon + 1 << "_" << aTime->tm_hour << "-" << aTime->tm_min << "-" << aTime->tm_sec << ".txt";
	string str = oss.str();
	const char* chr = str.c_str();

	ofstream fichier(chr, ios::out | ios::app);
	if (fichier) {
		fichier << forme->encoderForme() << "#";
		fichier.close();
	}
}



void SauvegarderFormeTXT::visite(const Rond * forme) const
{
	sauvegarde(forme);
}

void SauvegarderFormeTXT::visite(const Segment * forme) const
{
	sauvegarde(forme);
}

void SauvegarderFormeTXT::visite(const Polygone * forme) const
{
	sauvegarde(forme);
}

void SauvegarderFormeTXT::visite(const Triangle * forme) const
{
	sauvegarde(forme);
}

void SauvegarderFormeTXT::visite(const FormeComposee * forme) const
{
	sauvegarde(forme);
}
