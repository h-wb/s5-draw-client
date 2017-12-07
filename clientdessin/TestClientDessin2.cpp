#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>
#include "Forme.h"
#include "Rond.h"
#include "DessinerJava.h"
#include "Erreur.h"
#include "Vecteur2D.h"
#include "Singleton.h"
#include "Polygone.h"
#include "Triangle.h"
#include "FormeComposee.h"
#include "SauvegarderFormeTXT.h"

using namespace std;

int main()
{
try
{
/*******************DECLARATION FORMES**************************/
Vecteur2D u1(200, 200), u2(300,300), u3(55, 52), u4(25,70), w, v1(40, 40), v3(130,130);
Vecteur2D t1(100, 100), t2(80, 120), t3(80, 140), t4(100, 160), t5(140, 160), t6(160, 140), t7(160, 120), t8(140,100);
Rond r(5, u2, 50);
Segment s(2, u1, u2);
Triangle t(4, t1, t2, t3);
Polygone p(2);
FormeComposee f(4);

p = p + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;
f = f + r + s + t + p;

/*******************SAUVEGARDE**************************/


/*******************TEST SEGMENT*************************
s.dessiner(new DessinerJava);
cout << &s;
s.translation(v1);
s.dessiner(new DessinerJava);
cout << &s;

s.homothetie(v1,1.2);
s.dessiner(new DessinerJava);
cout << &s;

s.rotation(v3, 10);
s.dessiner(new DessinerJava);
cout << &s;*/

/*******************TEST ROND**************************/
r.dessiner(new DessinerJava);
cout << &r;

SauvegarderFormeTXT* test = new SauvegarderFormeTXT();
test->visite(&r);


/*r.translation(v1);
r.dessiner(new DessinerJava);
cout << &r;

r.homothetie(v1, 1.2);
r.dessiner(new DessinerJava);
cout << &r;

r.rotation(v3, 180);
r.dessiner(new DessinerJava);
cout << &r;/*


/*******************TEST POLYGONE************************
p.dessiner(new DessinerJava);
cout << &p;

p.translation(v1);
p.dessiner(new DessinerJava);
cout << &p;

p.homothetie(v1, 2);
p.dessiner(new DessinerJava);
cout << &p;

p.rotation(v3, 180);
p.dessiner(new DessinerJava);
cout << &p;**/

/*******************TEST TRIANGLE*************************
t.dessiner(new DessinerJava);
cout << &t;

t.translation(v1);
t.dessiner(new DessinerJava);
cout << &t;

t.homothetie(v1, 2);
t.dessiner(new DessinerJava);
cout << &t;

t.rotation(v3, 180);
t.dessiner(new DessinerJava);
cout << &t;*/

/*******************TEST FORME COMPOSEE*************************
f.dessiner(new DessinerJava);
cout << &f;

f.translation(v1);
f.dessiner(new DessinerJava);
cout << &f;

f.homothetie(v1);
f.dessiner(new DessinerJava);
cout << &f; 

f.rotation(v1);
f.dessiner(new DessinerJava);
cout << &f; */


}
catch(Erreur e)
{
cerr << e << endl;
}
char ch;
cin >> ch;

return 0;
}