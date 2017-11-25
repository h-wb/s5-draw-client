#include "Singleton.h"
#include <iostream>

using namespace std;

int main8(void) //Pour tester le main, le rename en main() et remplacer main() de TestClientDessin2 en main8() par exemple
{
	//1er appel de Instance: on alloue le pointeur SoundManager::m_instance
	Singleton& ptr1 = Singleton::getInstance();

	//2eme appel:on se contente de renvoyer le pointeur déjà allouer.
	Singleton& ptr2 = Singleton::getInstance();

	//ptr1 et ptr2 pointe sur la même adresse mémoire.
	//On voit donc qu'il ny a bien qu'un seul objet.
	cout << &ptr1 << "|" << &ptr2 << endl;

	return 0;
}

