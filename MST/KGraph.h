#pragma once
#include "KEdge.h"
//KGraph.h
//Luke Pinkney
//EECS 2510 Fall 2018
//12/10/18
class KGraph
{
	//class to hold the vertices and edges that make up a graph for kruskals algorithim
public:
	KGraph();
	~KGraph();
	//pointers to hold the edges and vertices arrays we collected 
	KVertexPtr vertices;	
	KEdgePtr edges;
	int sizeOfEdges;//we must define the heap sizes based off of the size of edges and vertices we collected.
	int sizeOfVertices;
};

