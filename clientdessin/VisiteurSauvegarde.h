#pragma once
#include <time.h>
#include "Forme.h"
#include "Rond.h"
#include "Segment.h"
#include "Polygone.h"
#include "Triangle.h"
#include "FormeComposee.h"

class VisiteurSauvegarde
{
public:
	virtual void visite(const Rond * forme) const = 0;
	virtual void visite(const Segment * forme) const = 0;
	virtual void visite(const Polygone *forme) const = 0;
	virtual void visite(const Triangle *forme) const = 0;
	virtual void visite(const FormeComposee *forme) const = 0;

};