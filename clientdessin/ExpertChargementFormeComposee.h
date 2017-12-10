#pragma once

#include "Expert.h"

class ExpertChargementFormeComposee : public Expert
{
public:
	ExpertChargementFormeComposee();
	ExpertChargementFormeComposee(Expert*);
	~ExpertChargementFormeComposee();

	Forme * handle(ifstream & fichier) const;
};

