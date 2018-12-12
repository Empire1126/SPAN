#pragma once
#include "PVertex.h"

class PEdge
{
public:
	PEdge();
	~PEdge();
	PVertex* destinationVertex =nullptr;
	PEdge* nextEdge = nullptr;
	double weight = 0;
};

