#pragma once

#include "Expert.h"

class ExpertChargementRond : public Expert
{
public:
	ExpertChargementRond();
	ExpertChargementRond(Expert*);
	~ExpertChargementRond();

	Forme * handle(ifstream & fichier) const;
};

