#include "pch.h"
#include "KRUSKAL.h"
//KRUSKAL.cpp
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18


KRUSKAL::KRUSKAL()
{
	
}

KRUSKAL::KRUSKAL(KGraph* graph)
{
	//when we construct the kruskal algorithm we will always send it a graph of the data 
	kruskalGraph = graph;	
	edgeHeap = new KHeap<0>(graph->sizeOfEdges, graph->edges);//the graph will contain the array of edges collected from the input file and the size of that array
	//this is to allow the heaps to be created
	MSTHeap = new KHeap<1>(graph->sizeOfEdges);//a 1 will cause the heap to become a max heap
	MakeSet();//set up verticesSet
	KEdgePtr sortedMinHeap = edgeHeap->HeapSort();//sort the min heap of all edges in the graph
	for(int j = graph->sizeOfEdges-1;j>0;j--)//for every edge in the sorted array
	{
		KEdge nextMinEdge = sortedMinHeap[j];//get the next edge
		if(nextMinEdge.initial->currentIndex!= nextMinEdge.destination->currentIndex)			
		{	
			//if the edge's initial vertex and destination vertex are in different index's in the vertices set
			//made in the make set function above then union the vertex sets and insert the edge into the max heap that is the MST of the graph
			Union(nextMinEdge.initial, nextMinEdge.destination);
			MSTHeap->insert(nextMinEdge);
		}
	}
	printMSTHeap();
}


KRUSKAL::~KRUSKAL()
{
}

void KRUSKAL::MakeSet()
{
	//here we have to set references to all vertexes in the graph
	//each vertex starts out alone in an array of vertex references with room for all other vertices
	verticesSet = new KVertexPtr*[kruskalGraph->sizeOfVertices];//create new vertex pointer reference array
	for(int i=1;i<kruskalGraph->sizeOfVertices;i++)//go through the entire array
	{
		verticesSet[i] = new KVertexPtr[kruskalGraph->sizeOfVertices];//create a new array of references
		for(int j = 1;j<kruskalGraph->sizeOfVertices;j++)
		{
			verticesSet[i][j] = nullptr;//all initial values will be null
		}
	}
	for(int i = 1;i< kruskalGraph->sizeOfVertices;i++)
	{		
		kruskalGraph->vertices[i].id = i;//the vertex id is equal to its starting index in the vertices set
		kruskalGraph->vertices[i].currentIndex = i;//each vertex's current index is the starting index of the set
		for(int j =1;j<kruskalGraph->sizeOfVertices;j++)//for every index of the set
		{
			if(i==j)//if the column and row match
			{
				verticesSet[i][j] = &kruskalGraph->vertices[i];//add the vertex to this index of the vertices set
				//this is to make sure all vertices stay in their respective rows and all columns start with one vertex equal whose id is the column inserted into
			}
		}
	}
}


void KRUSKAL::Union(KVertexPtr initial, KVertexPtr destination)
{
	//one index of the vertices set can all of the vertices of the graph. This means we must not move all vertex's that are in a particular index of the array
	//over to the new index we are unionizing with. 
	for(int i =1;i< kruskalGraph->sizeOfVertices;i++)//go through the array of a set
	{
		if(verticesSet[destination->currentIndex][i]!=nullptr)
		{
			//if the destination set contains a vertex then move that vertex over the initial vertex's index in the set of sets			
			verticesSet[initial->currentIndex][i] = verticesSet[destination->currentIndex][i];
			//the old vertex reference in the destination's vertex array is now null
			verticesSet[destination->currentIndex][i] = nullptr;			
		}
	}
	//now we must adjust all of the current index values for the vertex references in the set of sets.
	for(int i =1 ;i<kruskalGraph->sizeOfVertices;i++)
	{
		if(verticesSet[initial->currentIndex][i]!= nullptr&&verticesSet[initial->currentIndex][i]->currentIndex!=initial->currentIndex)
		{
			//if the current index in initial's vertex array is not null and doesn't conform to the initial vertex's current index cant that vertex's current index to 
			//match the initial's of the edge
			verticesSet[initial->currentIndex][i]->currentIndex = initial->currentIndex;
		}
	}
}

void KRUSKAL::printMSTHeap()
{
	//call print ot display the MST to the user
	MSTHeap->printMaxHeap();
}


