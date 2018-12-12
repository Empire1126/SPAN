#include "pch.h"
#include "PMSTHeap.h"





PMSTHeap::PMSTHeap(int size, PVertex* vertices)
{
}


PVertex PMSTHeap::extractMax()
{
	if (heapSize < 1)
	{
		std::cout << "heap underflow " << "\n";
		PVertex nothing;
		return nothing;
	}
	PVertex max = vertexArray[1];
	delete &vertexArray[1];
	vertexArray[1] = vertexArray[heapSize - 1];
	heapSize--;
	maxHeapify(1);
	return max;
}

PVertex PMSTHeap::findVertexMST(PVertex vertex)
{
	
}

int PMSTHeap::getLeftChild(int index)
{
	return (2 * index);
}

int PMSTHeap::getParent(int index)
{
	return (index / 2);
}

int PMSTHeap::getRightChild(int index)
{
	return ((2 * index) + 1);
}

PVertex* PMSTHeap::heapSort()
{
	for (int i = heapSize; i > 1; i--)
	{
		swap(1, i);
		heapSize--;
		maxHeapify(1);
	}
	return maxHeap;
}

void PMSTHeap::increaseKey(int index, PVertex key)
{
	if (index == 1)
	{
		vertexArray[index] = key;
		MSTWeight += key.traverseValue;
		return;
	}
	vertexArray[index] = key;
	MSTWeight += key.traverseValue;
	while (index > 1 && vertexArray[getParent(index)].name+ vertexArray[getParent(index)].parent->name> vertexArray[index].name+ vertexArray[index].parent->name)
	{
		swap(index, getParent(index));
		index = getParent(index);
	}
}

void PMSTHeap::insert(PVertex key)
{
	for (int i = heapSize; i > 1; i--)
		{
			swap(1, i);
			heapSize--;
			maxHeapify(1);
		}
		return maxHeap;
}

void PMSTHeap::maxHeapify(int index)
{
	
}

void PMSTHeap::swap(int index, int smallest)
{
	
}

PMSTHeap::~PMSTHeap()
{
}
