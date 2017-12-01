
/**
 * Essai du client qui envoie des formes � dessiner au serveur de dessin
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

using namespace std;

int main()
{
try
{
cout << "test singletons \n";
//1er appel de Instance: on alloue le pointeur SoundManager::m_instance
Singleton& ptr1 = Singleton::getInstance();

//2eme appel:on se contente de renvoyer le pointeur d�j� allouer.
Singleton& ptr2 = Singleton::getInstance();

//ptr1 et ptr2 pointe sur la m�me adresse m�moire.
//On voit donc qu'il ny a bien qu'un seul objet.
cout << &ptr1 << "|" << &ptr2 << endl;


cout << "test vecteurs 2D \n";

Vecteur2D u1(200, 300), u2(400, 600), u3(500, 300), u4(25,70), w, v1(35, -63), v3, u8(100,150), u7(200, 200), u9(500, 200), h1(100,100);
Vecteur2D t1(100, 100), t2(80, 120), t3(80, 140), t4(100, 160), t5(140, 160), t6(160, 140), t7(160, 120), t8(140,100) ;
cout << " u1 = " << u1 << endl;

Forme * f1, * f2, *f3, *f4, *hf1;
//f2 = new Rond(300, 300, 30);
f2= new Rond(5, u1, 20);
//f3 = new Segment(2, u7, u9);
//f1 = new Polygone(5);
//Triangle T(4, u1, u2, u3);
//f4 = new Triangle(4, u1, u2, u3);

//Polygone P(2);
//P = P + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;
//P = P +u1 + u2 + u3;



//cout << "f1 = " << f1 << endl;
//cout << "f2 = " << f2 << endl;
//cout << "f3 = " << f3 << endl;

//f1->dessiner(new DessinerJava); // requ�te vers le serveur de dessin
//f2->dessiner(new DessinerJava);      // requ�te vers le serveur de dessin
//f3->dessiner(new DessinerJava);
//P.dessiner(new DessinerJava);
//f4->dessiner(new DessinerJava);
//hf1 = f2->homothetie(h1, 1);
//hf1->dessiner(new DessinerJava);

cout << "Aire rond = " << f2->aire() << endl;
}
catch(Erreur e)
{
cerr << e << endl;
}
char ch;
cin >> ch;

return 0;
}