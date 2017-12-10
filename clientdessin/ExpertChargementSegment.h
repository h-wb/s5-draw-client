#pragma once

#include "Expert.h"

class ExpertChargementSegment : public Expert
{
public:
	ExpertChargementSegment();
	ExpertChargementSegment(Expert*);
	~ExpertChargementSegment();

	Forme * handle(ifstream & fichier) const;
};

