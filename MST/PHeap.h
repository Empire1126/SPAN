#pragma once
#include "PMSTHeap.h"

class PHeap
{
public:
	PHeap(int size, PVertex** vertices);
	~PHeap();
	int isNotEmpty();
	PVertex* extractMin();
	void increaseKeyValue(PVertex* key, double value);
private:
	int length = 0;
	int heapSize = 0;
	PVertex** vertexArray = nullptr;
	int getLeftChild(int index);
	int getRightChild(int index);
	int getParent(int index);
	void minHeapify(int index);
	void swap(int index, int smallest);
};

