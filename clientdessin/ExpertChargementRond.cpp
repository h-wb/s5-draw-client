#include "ExpertChargementRond.h"
#include "Rond.h"



ExpertChargementRond::ExpertChargementRond()
{
}

ExpertChargementRond::ExpertChargementRond(Expert * expert): Expert(expert)
{

}


ExpertChargementRond::~ExpertChargementRond()
{
}

Forme * ExpertChargementRond::handle(ifstream & fichier) const
{
	fichier.clear();
	fichier.seekg(0, fichier.beg);

	cout << "teseeset";
	vector<string> arguments ;
	string requete;
	getline(fichier, requete);
	arguments = split(requete, ',');
	if (arguments[0] == "Rond") {
		int couleur = stod(arguments[1]);
		Vecteur2D v(stod(arguments[2]), stod(arguments[3]));
		int rayon = stod(arguments[4]);
		return new Rond(couleur, v, rayon);
	}
	else {
		return getSuivant() != NULL ? getSuivant()->handle(fichier) : NULL;
	}
}
