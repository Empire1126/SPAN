#pragma once
#include "PHeap.h"
#include "PGraph.h"

class PRIM
{
public:
	PRIM(PGraph* PrimGraph);	
	~PRIM();
	PGraph* PGraph = nullptr;	
	int sizeOfMSTVertices = 0;
	void printMST(PVertex* MSTArray);
};

