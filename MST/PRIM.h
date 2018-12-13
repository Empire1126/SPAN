#pragma once
#include "PHeap.h"

class PRIM
{
	//class to hold the prim algorithm 
public:
	PRIM(PGraph* PrimGraph);	//we will always pass a graph to the prim algorithm containing the vertices and size of the vertices
	~PRIM();
	PGraph* PGraph = nullptr;//graph pointer
	PMSTHeap* maxHeap= nullptr;//MST max heap pointer
	PHeap* minHeap = nullptr;	//min heap of vertex traversal value
	void printMST();
};

