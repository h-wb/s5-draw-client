#include "ExpertChargementSegment.h"
#include "Segment.h"



ExpertChargementSegment::ExpertChargementSegment()
{
}

ExpertChargementSegment::ExpertChargementSegment(Expert * expert) : Expert(expert)
{

}


ExpertChargementSegment::~ExpertChargementSegment()
{
}

Forme * ExpertChargementSegment::handle(ifstream & fichier) const
{
	fichier.clear();
	fichier.seekg(0, fichier.beg);

	vector<string> arguments;
	string requete;
	getline(fichier, requete);
	cout << requete;
	arguments = split(requete, ',');

	if (arguments[0] == "Segment") {
		int couleur = stod(arguments[1]);
		Vecteur2D debut(stod(arguments[2]), stod(arguments[3]));
		Vecteur2D fin(stod(arguments[4]), stod(arguments[5]));

		return new Segment(couleur, debut, fin);
	}
	else {
		return getSuivant() != NULL ? getSuivant()->handle(fichier) : NULL;
	}
}
