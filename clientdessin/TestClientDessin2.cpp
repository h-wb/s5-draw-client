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
Vecteur2D u1(400, 100), u2(300,250), u3(55, 52), u4(25,70), w, v1(40, 40), v3;
Vecteur2D t1(100, 100), t2(80, 120), t3(80, 140), t4(100, 160), t5(140, 160), t6(160, 140), t7(160, 120), t8(140,100);
Rond r(5, u2, 250);
Segment s(2, u2, u3);
Triangle t(4, u1, u2, u3);
Polygone p(2);
FormeComposee f(4);

p = p + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;
f = f + r + s + t + p;

r.dessiner(new DessinerJava);
cout << &r;
s.dessiner(new DessinerJava);
cout << &s;
t.dessiner(new DessinerJava);
cout << &t;
p.dessiner(new DessinerJava);
cout << &p;
f.dessiner(new DessinerJava);
cout << &f;

}
catch(Erreur e)
{
cerr << e << endl;
}
char ch;
cin >> ch;

return 0;
}