#pragma once
#include "PHeap.h"

class PRIM
{
public:
	PRIM(PGraph* PrimGraph);	
	~PRIM();
	PGraph* PGraph = nullptr;
	PMSTHeap* maxHeap= nullptr;
	PHeap* minHeap = nullptr;	
	void printMST();
};

