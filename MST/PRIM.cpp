#include "pch.h"
#include "PRIM.h"



PRIM::PRIM(::PGraph* PrimGraph)
{
	PrimGraph->vertices[1]->traverseValue= 0;
	PrimGraph->vertices[1]->parent = PrimGraph->vertices[1];
	//create mst max heap
	//MSTVertices = new PVertex[PrimGraph->sizeOfVertices];
	//create heap
	minHeap = new PHeap(PrimGraph->sizeOfVertices, PrimGraph->vertices);
	maxHeap = new PMSTHeap(PrimGraph->sizeOfVertices);

	while (minHeap->isNotEmpty())
	{
		PVertex* nextMin = minHeap->extractMin();
		//add to mst
		maxHeap->insert(nextMin);
		PEdge* nextEdge = nextMin->nextEdge;		
		
		while (nextEdge != nullptr)		
		{
			PVertex* destination = nextEdge->destinationVertex;			
			if(!(destination->isInMST)&&nextEdge->weight < destination->traverseValue)
			{
				destination->parent = nextMin;
				minHeap->increaseKeyValue(destination, nextEdge->weight);
			}
			nextEdge = nextEdge->nextEdge;
		}

	}
	printMST();
}




void PRIM::printMST()
{
	std::cout << maxHeap->getMSTWeight() << "\n";
	PVertex* next = nullptr;
	next = maxHeap->extractMax();
	while(next!=nullptr)
	{
		if(next->parent==next)
		{
			next = maxHeap->extractMax();
			continue;;
		}
		std::cout << next->parent->name +"-"+next->name<<": " <<next->traverseValue<< "\n";
		next = maxHeap->extractMax();
	}

}


PRIM::~PRIM()
{
}
