#include "pch.h"
#include "PRIM.h"
//Prim.cpp
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18


PRIM::PRIM(::PGraph* PrimGraph)
{
	//class to hold Prim algorithm 
	PrimGraph->vertices[1]->traverseValue= 0;//set the first vertex in the array to be considered first
	PrimGraph->vertices[1]->parent = PrimGraph->vertices[1];//the first vertex's traverse path is zero and its parent is itself
	//create mst max heap for holding traversed vertices in MST
	//create min heap to hold all untraveled vertices
	minHeap = new PHeap(PrimGraph->sizeOfVertices, PrimGraph->vertices);
	maxHeap = new PMSTHeap(PrimGraph->sizeOfVertices);
	while (minHeap->isNotEmpty())
	{
		//as long as the min heap isn't empty
		PVertex* nextMin = minHeap->extractMin();//get the next min vertex out of the heap		
		maxHeap->insert(nextMin);//add it to the MST heap
		PEdge* nextEdge = nextMin->nextEdge;//get the next edge on the new vertex in the MST		
		while (nextEdge != nullptr)		
		{
			//keep traversing the edge linked list until we fall off
			PVertex* destination = nextEdge->destinationVertex;	//get the destination vertex of that edge	
			if(!(destination->isInMST)&&nextEdge->weight < destination->traverseValue)
			{
				//if the destination isn't in the MST yet and its traverse value is greater than the weight of this edge
				destination->parent = nextMin;//set the parent of this destination vertex to be the last added vertex to the MST heap
				minHeap->decreaseKeyValue(destination, nextEdge->weight);//decrease the key's traversal value to that of the weights
			}
			nextEdge = nextEdge->nextEdge;//get the next edge in the linked list
		}

	}
	printMST();//display the MST
}




void PRIM::printMST()
{
	//display the MST total weight
	std::cout << maxHeap->getMSTWeight() << "\n";
	PVertex* next = nullptr;
	//get the next vertex from the MST max heap
	next = maxHeap->extractMax();
	while(next!=nullptr)//as long as we aren't out of vertices
	{
		if(next->parent==next)
		{
			//don't consider the first vertex we added whose parent is itself, it isn't an edge
			next = maxHeap->extractMax();//just get the next edge
			continue;
		}
		//display the edge to this vertex by displaying its parent then the vertex and the value to get there
		std::cout << next->parent->name +"-"+next->name<<": " <<next->traverseValue<< "\n";
		//get the next vertex in max heap
		next = maxHeap->extractMax();
	}

}


PRIM::~PRIM()
{
}
