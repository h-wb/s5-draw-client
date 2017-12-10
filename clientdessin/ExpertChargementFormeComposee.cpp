#include "ExpertChargementFormeComposee.h"
#include "FormeComposee.h"
#include "DessinerJava.h"




ExpertChargementFormeComposee::ExpertChargementFormeComposee()
{
}

ExpertChargementFormeComposee::ExpertChargementFormeComposee(Expert * expert) : Expert(expert)
{
}


ExpertChargementFormeComposee::~ExpertChargementFormeComposee()
{
}

Forme * ExpertChargementFormeComposee::handle(ifstream & fichier) const
{
	vector<vector<string>> lignes;
	string requete;
	bool b = false;
	int number_of_lines = 0;

	while (getline(fichier, requete)) {
		lignes.push_back(split(requete, ','));
		++number_of_lines;
	}

	for (int i = 0; i < number_of_lines; i++) {
		if ((lignes[i][0] == "Rond" || lignes[i][0] == "Segment") && number_of_lines > 1);
		b = true;
	}

	int couleur = stod(lignes[0][1]);
	FormeComposee * fc = new FormeComposee(couleur);
	if( b == true){
		for (int i = 0; i < number_of_lines; i++) {
			int couleur = stod(lignes[i][1]);
			Vecteur2D debut(stod(lignes[i][2]), stod(lignes[i][3]));
			Vecteur2D fin(stod(lignes[i][4]), stod(lignes[i][5]));
			if (lignes[i][0] == "Rond") {
				Rond r(couleur, debut, stod(lignes[i][4]));
				*fc = *fc + r;
			} else {
				Segment s(couleur, debut, fin);
				*fc = *fc + s;
				}
			
		}
		cout << fc;
		//fc->dessiner(new DessinerJava);
		return fc;


	}
	else {
		return getSuivant() != NULL ? getSuivant()->handle(fichier) : NULL;
	}

}
