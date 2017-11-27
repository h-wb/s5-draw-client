#pragma once
#include "Forme.h"
#include "Croix.h"
#include "Rond.h"
#include "Segment.h"

class VisiteurDessiner
{
public:
	virtual void visite(const Croix * forme) const = 0;
	virtual void visite(const Rond * forme) const = 0;
	virtual void visite(const Segment * forme) const = 0;
};

