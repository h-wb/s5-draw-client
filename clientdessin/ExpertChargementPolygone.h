#pragma once

#include "Expert.h"

class ExpertChargementPolygone : public Expert
{
public:
	ExpertChargementPolygone();
	ExpertChargementPolygone(Expert*);
	~ExpertChargementPolygone();

	Forme * handle(ifstream & fichier) const;
};

