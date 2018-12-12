#pragma once
#include <climits>
#include "KVertex.h"

class KEdge
{
public:
	KEdge();
	~KEdge();
	double weight = INT_MAX;
	KVertexPtr initial = nullptr;
	KVertexPtr destination = nullptr;
};
typedef KEdge* KEdgePtr;

