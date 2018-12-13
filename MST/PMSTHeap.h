#pragma once
#include "PGraph.h"
//PMSTHeap.h
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18

class PMSTHeap
{
	//max heap to hold all of the graph vertex's after the all shortest paths have been taken and parent pointer been set
	//this heap will maintain that the greatest alphabetical vertex (considering parent's first) will be at the top of the heap
public:
	PMSTHeap(int size);//the heap will always receive a size of the vertex's collected
	~PMSTHeap();
	//max heap insert and increase key,extract,ect
	//isNotEmpty will determine if the heap has no more vertex's
	void insert(PVertex* key);
	void increaseKey(int index, PVertex* key);	
	PVertex* extractMax();	
	//will return the MST weight added up
	double getMSTWeight();
private:
	//length of the array and heapsize of the heap
	int length = 0;
	int heapSize = 0;
	//the total weight added up will adding shortest paths from the algorithm 
	double MSTWeight = 0;
	//pointer pointer to gold pointer array
	PVertex** vertexArray = nullptr;
	int getLeftChild(int index);
	int getRightChild(int index);
	int getParent(int index);
	void maxHeapify(int index);
	void swap(int index, int largest);

};

