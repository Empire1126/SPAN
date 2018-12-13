#include "pch.h"
#include "PMSTHeap.h"





PMSTHeap::PMSTHeap(int size)
{
	heapSize = 0;
	length = size;
	vertexArray = new PVertex*[size];
}


PVertex* PMSTHeap::extractMax()
{
	if (heapSize < 2)
	{		
		PVertex* nothing=nullptr;
		return nothing;
	}	
	PVertex* max = vertexArray[1];
	if(max->parent==max)
	{
		vertexArray[1] = nullptr;
		vertexArray[1] = vertexArray[heapSize];
		maxHeapify(1);
		return max;
	}
	vertexArray[1] = nullptr;
	heapSize--;
	vertexArray[1] = vertexArray[heapSize];
	maxHeapify(1);
	
	return max;
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



void PMSTHeap::increaseKey(int index, PVertex* key)
{
	if (index == 1)
	{
		vertexArray[index] = key;		
		key->isInMST = true;
		MSTWeight += key->traverseValue;
		return;
	}
	vertexArray[index] = key;
	key->isInMST = true;
	MSTWeight += key->traverseValue;
	while (index > 1 && vertexArray[getParent(index)]->parent->name + vertexArray[getParent(index)]->name> vertexArray[index]->parent->name +vertexArray[index]->name )
	{
		swap(index, getParent(index));
		index = getParent(index);
	}
}

void PMSTHeap::insert(PVertex* key)
{
	if (heapSize == length)
	{
		std::cout << "heap overflow " << "\n";
		return;
	}
	heapSize++;
	increaseKey(heapSize, key);
}

void PMSTHeap::maxHeapify(int index)
{
	int left = getLeftChild(index);
	int right = getRightChild(index);
	int largest = index;
	if (left < heapSize&&vertexArray[left]->parent->name+vertexArray[left]->name < vertexArray[largest]->parent->name+ vertexArray[largest]->name )
	{
		largest = left;
	}
	if (right < heapSize&&vertexArray[right]->parent->name+vertexArray[right]->name   < vertexArray[largest]->parent->name+vertexArray[largest]->name)
	{
		largest= right;
	}
	if (largest != index)
	{
		swap(index, largest);
		maxHeapify(largest);
	}
}

void PMSTHeap::swap(int index, int largest)
{
	PVertex* largerVertex = vertexArray[index];
	vertexArray[index] = vertexArray[largest];
	vertexArray[largest] = largerVertex;
}

PMSTHeap::~PMSTHeap()
{
}

bool PMSTHeap::isNotEmpty()
{
	return heapSize;
}

double PMSTHeap::getMSTWeight()
{
	return MSTWeight;
}