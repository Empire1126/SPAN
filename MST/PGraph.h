#pragma once
#include "PVertex.h"

class PGraph
{
	//Prim's graph to hold the vertex count and vertex array itself for Prims algorithm 
public:
	PGraph();
	~PGraph();
	PVertex** vertices;//an array of pointers to the vertex's of the graph
	int sizeOfVertices = 0;//number of vertex's in the graph
};

