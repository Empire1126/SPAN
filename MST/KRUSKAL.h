#pragma once
#include "Vertex.h"
#include "Graph.h"
#include "Heap.h"
class Graph;

class KRUSKAL
{
public:
	KRUSKAL(Graph graph);
	KRUSKAL();
	~KRUSKAL();	
private:
	Graph kruskalGraph;
	Heap<0>* edgeHeap;
	Heap<1>* MSTHeap;
	Vertex*** verticesSet;
	void MakeSet();
	
	//void FindSet();
	void Union(vertexPtr inital,vertexPtr destination);
	
	void printMSTHeap();
};

