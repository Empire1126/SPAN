#pragma once
#include "Edge.h"

class Graph
{
public:
	Graph();
	~Graph();
	vertexPtr vertices;	
	edgePtr edges;
	int sizeOfEdges;
	int sizeOfVertices;
};

