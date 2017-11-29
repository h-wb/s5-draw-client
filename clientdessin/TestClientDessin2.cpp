
/**
 * Essai du client qui envoie des formes à dessiner au serveur de dessin
 * 
 * 
 * */

#include <iostream>
#include "Forme.h"
#include "Rond.h"
#include "DessinerJava.h"
#include "Erreur.h"
#include "Vecteur2D.h"
#include "Singleton.h"

using namespace std;

int main()
{
try
{
cout << "test singletons \n";
//1er appel de Instance: on alloue le pointeur SoundManager::m_instance
Singleton& ptr1 = Singleton::getInstance();

//2eme appel:on se contente de renvoyer le pointeur déjà allouer.
Singleton& ptr2 = Singleton::getInstance();

//ptr1 et ptr2 pointe sur la même adresse mémoire.
//On voit donc qu'il ny a bien qu'un seul objet.
cout << &ptr1 << "|" << &ptr2 << endl;


cout << "test vecteurs 2D \n";

Vecteur2D u1(300, 300), u2(40, 20), u3(100,100), w, v1(35, -63), u4(3, -4), v3;

cout << " u1 = " << u1 << endl;

Forme * f1, * f2, *f3;
//f2 = new Rond(300, 300, 30);
f2 = new Rond(1, u1, 30);
f3 = new Segment(0, u2, u3);


//cout << "f1 = " << f1 << endl;
cout << "f2 = " << f2 << endl;
//cout << "f3 = " << f3 << endl;

//f1->dessiner(new DessinerJava); // requête vers le serveur de dessin
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