
/**
 * Essai du client qui envoie des formes à dessiner au serveur de dessin
 * 
 * 
 * */

#include <iostream>
#include "Forme.h"
#include "Croix.h"
#include "Rond.h"
#include "DessinerJava.h"
#include "Erreur.h"

using namespace std;

int main10()
{
try
{
Forme * f1, * f2, *f3;
f1 = new Croix(40, 40, 100, 100);
f2 = new Rond(300, 300, 30);
f3 = new Segment(40, 100);


cout << "f1 = " << f1 << endl;
cout << "f2 = " << f2 << endl;
cout << "f3 = " << f3 << endl;

f1->dessiner(new DessinerJava); // requête vers le serveur de dessin
f2->dessiner(new DessinerJava);      // requête vers le serveur de dessin
f3->dessiner(new DessinerJava);
}
catch(Erreur e)
{
cerr << e << endl;
}
char ch;
cin >> ch;

return 0;
}