#pragma once
#include <climits>
#include "KVertex.h"

class KEdge
{
	//class to hold the kruskal edge data
public:
	KEdge();
	~KEdge();
	double weight = INT_MAX;//start all edges at max weight
	//the edge connects two vertexs in the graph
	KVertexPtr initial = nullptr;
	KVertexPtr destination = nullptr;
};
typedef KEdge* KEdgePtr;

