#include "pch.h"
#include "KRUSKAL.h"



KRUSKAL::KRUSKAL()
{
	
}

KRUSKAL::KRUSKAL(KGraph graph)
{
	kruskalGraph = graph;
	edgeHeap = new KHeap<0>(graph.sizeOfEdges, graph.edges);
	MSTHeap = new KHeap<1>(graph.sizeOfEdges);
	MakeSet();
	KEdgePtr sortedMinHeap = edgeHeap->HeapSort();
	for(int j = graph.sizeOfEdges-1;j>0;j--)
	{
		KEdge nextMinEdge = sortedMinHeap[j];
		if(nextMinEdge.initial->currentIndex!= nextMinEdge.destination->currentIndex)
		{	
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
	verticesSet = new KVertexPtr*[kruskalGraph.sizeOfVertices];
	for(int i=1;i<kruskalGraph.sizeOfVertices;i++)
	{
		verticesSet[i] = new KVertexPtr[kruskalGraph.sizeOfVertices];
		for(int j = 1;j<kruskalGraph.sizeOfVertices;j++)
		{
			verticesSet[i][j] = nullptr;
		}
	}
	for(int i = 1;i< kruskalGraph.sizeOfVertices;i++)
	{		
		kruskalGraph.vertices[i].id = i;
		kruskalGraph.vertices[i].currentIndex = i;
		for(int j =1;j<kruskalGraph.sizeOfVertices;j++)
		{
			if(i==j)
			{
				verticesSet[i][j] = &kruskalGraph.vertices[i];
			}
		}
	}
}


void KRUSKAL::Union(KVertexPtr initial, KVertexPtr destination)
{
	
	for(int i =1;i< kruskalGraph.sizeOfVertices;i++)
	{
		if(verticesSet[destination->currentIndex][i]!=nullptr)
		{
			verticesSet[initial->currentIndex][i] = verticesSet[destination->currentIndex][i];
			verticesSet[destination->currentIndex][i] = nullptr;			
		}
	}
	for(int i =1 ;i<kruskalGraph.sizeOfVertices;i++)
	{
		if(verticesSet[initial->currentIndex][i]!= nullptr&&verticesSet[initial->currentIndex][i]->currentIndex!=initial->currentIndex)
		{
			verticesSet[initial->currentIndex][i]->currentIndex = initial->currentIndex;
		}
	}
}

void KRUSKAL::printMSTHeap()
{
	MSTHeap->printMaxHeap();
}


