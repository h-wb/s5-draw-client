
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
#include "Polygone.h"
#include "Triangle.h"
#include "FormeComposee.h"

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


Vecteur2D u1(100, 200), u2(500,400), u3(100, -100), u4(25,70), w, v1(35, -63), v3;

Vecteur2D t1(100, 100), t2(80, 120), t3(80, 140), t4(100, 400), t5(300, 200), t6(160, 140), t7(160, 120), t8(140,100), centre(0,0) ;
cout << " u1 = " << u1 << endl;

Forme * f1, * f2, *f3, *tf1, *tf2;
Forme *t;
//f2 = new Rond(300, 300, 30);
//f1 = new Segment(3,t4,t5);
f3 = new Rond(2, u1, 120);
//f1 = new Polygone(5);
//t = new Triangle(4, u1, u2, u3);
//Triangle T(4, u1, u2, u3);
//f3->dessiner(new DessinerJava);
//f2->dessiner(new DessinerJava);
//test.visite(f3);
//oui->visite(f3);

//t->dessiner(new DessinerJava);
//f3->dessiner(oui);
//Polygone P(2);
//P = P + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;
//P = P +u1 + u2 + u3;
//P.dessiner(new DessinerJava);
//FormeComposee F(4);
//F = F+f3+f1;
//F.dessiner(new DessinerJava);
;
f3->dessiner(new DessinerJava);
tf2 = f3->rotation(centre, 90);
tf2->dessiner(new DessinerJava);
//tf1 = f3->homothetie(u3, 2);
//tf1->dessiner(new DessinerJava);
//cout << "Aire rond = " << f2->aire() << endl;
//Polygone P(2);
//P = P + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;

//f1->rotation(centre, 90);

//cout << "f1 = " << f1 << endl;
//cout << "f2 = " << f2 << endl;
//cout << "f3 = " << f3 << endl;

//f3->dessiner(new DessinerJava); // requête vers le serveur de dessin
//tf1 = f3->rotation(centre, 90);
//tf1->dessiner(new DessinerJava);
//f2->dessiner(new DessinerJava);      // requête vers le serveur de dessin
//f3->dessiner(new DessinerJava);

//T.dessiner(new DessinerJava);


//tf1 = f3->translation(u1);
//tf1->dessiner(new DessinerJava);
//tf2 = f2->translation(u1);
//tf2->dessiner(new DessinerJava);
//P.dessiner(new DessinerJava);
}
catch(Erreur e)
{
cerr << e << endl;
}
char ch;
cin >> ch;

return 0;
}