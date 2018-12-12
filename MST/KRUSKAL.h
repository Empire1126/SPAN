#pragma once
#include "KVertex.h"
#include "KGraph.h"
#include "KHeap.h"
class KGraph;

class KRUSKAL
{
public:
	KRUSKAL(KGraph graph);
	KRUSKAL();
	~KRUSKAL();	
private:
	KGraph kruskalGraph;
	KHeap<0>* edgeHeap;
	KHeap<1>* MSTHeap;
	KVertex*** verticesSet;
	void MakeSet();
	
	//void FindSet();
	void Union(KVertexPtr inital,KVertexPtr destination);
	
	void printMSTHeap();
};

