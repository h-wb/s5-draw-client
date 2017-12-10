#include "Expert.h"






Expert::Expert()
{
	_suivant = NULL;
}

Expert::Expert(Expert * expert)
{
	_suivant = expert;
}

Expert::~Expert()
{
}

Expert * Expert::getSuivant() const
{
	return _suivant;
}

void Expert::setSuivant(Expert * suivant)
{
	_suivant = suivant;
}


