#pragma once

#include "VisiteurSauvegarde.h"

class SauvegarderFormeTXT : public VisiteurSauvegarde
{
public:
	SauvegarderFormeTXT();
	virtual void visite(const Rond * forme) const;
	virtual void visite(const Segment * forme) const;
	virtual void visite(const Polygone *forme) const;
	virtual void visite(const Triangle *forme) const;
	virtual void visite(const FormeComposee *forme) const;

};