#pragma once
#include "PMSTHeap.h"
//Pheap.h
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18

class PHeap
{
	//a min heap to hold all of the vertex's and keep the minimum traverse valued vertex at the top of the heap
public:
	PHeap(int size, PVertex** vertices);//constructor will always be provided the array of pointers and the size of the array
	~PHeap();
	//mostly standard heap functions, isNotEmpty is to determine when the heap has no more vertex's
	int isNotEmpty();
	PVertex* extractMin();
	void decreaseKeyValue(PVertex* key, double value);
private:
	//length and heapsize of the heap
	int length = 0;
	int heapSize = 0;
	PVertex** vertexArray = nullptr;//pointer pointer to hold the pointer array
	int getLeftChild(int index);
	int getRightChild(int index);
	int getParent(int index);
	void minHeapify(int index);
	void swap(int index, int smallest);
};

