#pragma once
#include "KVertex.h"
#include "KGraph.h"
#include "KHeap.h"
//KRUSKAL.h
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18

class KRUSKAL
{
	//this class will hold the logic to preform the kruskal algorithm
	//it will use two heaps a max heap and a min heap to hold KEdges
	//the max heap will contain the MST Edges
	//the min heap will contain all edges sorted by least weight
public:
	KRUSKAL(KGraph* graph);//we will send the graph to the algorithm 
	KRUSKAL();
	~KRUSKAL();	
private:
	//the graph and two heaps along with a set K vertex sets to determine what edges are cuts 
	KGraph* kruskalGraph;
	KHeap<0>* edgeHeap;
	KHeap<1>* MSTHeap;
	KVertex*** verticesSet;
	void MakeSet();//will set up the vertices set to allow us to begin determining what is a cut
	
	//void FindSet();
	void Union(KVertexPtr inital,KVertexPtr destination);//will add vertex sets together from the verticesSet variable to maintain what is a cut
	
	void printMSTHeap();
};

