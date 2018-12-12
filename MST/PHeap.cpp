#include "pch.h"
#include "PHeap.h"



PHeap::PHeap(int size, PVertex* vertices)
{
	length = size;
	heapSize = size;
	vertexArray = vertices;
	for(int i =size/2;i>0;i-- )
	{
		minHeapify(i);
	}
}

bool PHeap::isEmpty()
{
	return heapSize;
}


PHeap::~PHeap()
{
}
PVertex PHeap::extractMin()
{
	if(heapSize<1)
	{
		std::cout << "heap underflow " << "\n";
		PVertex nothing;
		return nothing;
	}
	PVertex min = vertexArray[1];
	delete &vertexArray[1];
	vertexArray[1] = vertexArray[heapSize];
	heapSize--;
	minHeapify(1);
	return min;
}
int PHeap::getParent(int index)
{
	return (index / 2);
}
int PHeap::getLeftChild(int index)
{
	return (2 * index);
}
int PHeap::getRightChild(int index)
{
	return ((2 * index) + 1);
}
void PHeap::minHeapify(int index)
{
	int left = getLeftChild(index);
	int right = getRightChild(index);
	int smallest = index;
	if (left < heapSize&&vertexArray[left].traverseValue < vertexArray[smallest].traverseValue)
	{
		smallest = left;
	}
	if (right < heapSize&&vertexArray[right].traverseValue< vertexArray[smallest].traverseValue)
	{
		smallest = right;
	}
	if (smallest != index)
	{
		swap(index, smallest);
		minHeapify(smallest);
	}
}
void PHeap::swap(int index, int smallest)
{
	PVertex largerVertex = vertexArray[index];
	vertexArray[index] = vertexArray[smallest];
	vertexArray[smallest] = largerVertex;
}
