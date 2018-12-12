#pragma once
#include "KEdge.h"

class KGraph
{
public:
	KGraph();
	~KGraph();
	KVertexPtr vertices;	
	KEdgePtr edges;
	int sizeOfEdges;
	int sizeOfVertices;
};

