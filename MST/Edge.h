#pragma once
#include <climits>
#include "Vertex.h"

class edge
{
public:
	edge();
	~edge();
	double weight = INT_MAX;
	vertexPtr initial = nullptr;
	vertexPtr destination = nullptr;
};
typedef edge* edgePtr;

