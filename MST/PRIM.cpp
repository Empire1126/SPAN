#include "pch.h"
#include "PRIM.h"



PRIM::PRIM(::PGraph* PrimGraph)
{
	PrimGraph->vertices[1].traverseValue = 0;
	//MSTVertices = new PVertex[PrimGraph->sizeOfVertices];
	//create heap
	PHeap* minHeap = new PHeap(PrimGraph->sizeOfVertices, PrimGraph->vertices);
	while (!minHeap->isEmpty())
	{
		PVertex nextMin = minHeap->extractMin();
		//add to mst

		PEdge* nextEdge = nextMin.nextEdge;
		while (nextEdge != nullptr)
		{

		}

	}
}

PVertex PRIM::findVertexMST(PVertex vertex)
{
	for()
}


PRIM::~PRIM()
{
}
