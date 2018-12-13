#pragma once
#include "PVertex.h"

class PGraph
{
public:
	PGraph();
	~PGraph();
	PVertex** vertices;
	int sizeOfVertices = 0;
};

