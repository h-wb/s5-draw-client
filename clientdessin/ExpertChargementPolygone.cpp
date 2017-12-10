#include "ExpertChargementPolygone.h"
#include "Polygone.h"
#include "Segment.h"
#include "DessinerJava.h"




ExpertChargementPolygone::ExpertChargementPolygone()
{
}

ExpertChargementPolygone::ExpertChargementPolygone(Expert * expert) : Expert(expert)
{
}


ExpertChargementPolygone::~ExpertChargementPolygone()
{
}

Forme * ExpertChargementPolygone::handle(ifstream & fichier) const
{
	vector<vector<string>> lignes;
	string requete;
	int number_of_lines=0;
	

	while (getline(fichier, requete)) {
		lignes.push_back(split(requete, ','));
		++number_of_lines;
	}


	int couleur = stod(lignes[0][1]);
	Polygone * p = new Polygone(couleur);

		if (lignes[0][0] == "Segment" && number_of_lines >1) {
			for (int i = 0; i < number_of_lines; i++) {
				*p = *p + Vecteur2D(stod(lignes[i][2]), stod(lignes[i][3]));
			}
			return p;
			
			
		}
		else {
			return getSuivant() != NULL ? getSuivant()->handle(fichier) : NULL;			
		}
	
}
