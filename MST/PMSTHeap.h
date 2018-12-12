#pragma once
#include "PVertex.h"
class PMSTHeap
{
public:
	PMSTHeap(int size, PVertex* vertices);
	~PMSTHeap();	
	void insert(PVertex key);
	void increaseKey(int index, PVertex key);
	PVertex findVertexMST(PVertex vertex);
	PVertex* heapSort();
	PVertex extractMax();
private:
	int length = 0;
	int heapSize = 0;
	double MSTWeight = 0;
	PVertex* vertexArray = nullptr;
	int getLeftChild(int index);
	int getRightChild(int index);
	int getParent(int index);
	void maxHeapify(int index);
	void swap(int index, int smallest);
};

