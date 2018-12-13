#include "pch.h"
#include "PMSTHeap.h"





PMSTHeap::PMSTHeap(int size)
{
	//we will always call this heap with just the size of the vertex array from the graph
	heapSize = 0;
	length = size;
	vertexArray = new PVertex*[size];//create the new pointer array 
}


PVertex* PMSTHeap::extractMax()
{
	//used to extract the next vertex from the max heap
	if (heapSize < 1)
	{		
		//if the heap is empty return a nullptr
		PVertex* nothing=nullptr;
		return nothing;
	}
	//otherwise return the root of the max heap as it is teh alphabetically greater vertex
	PVertex* max = vertexArray[1];
	//move the end of teh heap up to the old root and remove that reference from the end of the heap by decreasing the heap size
	vertexArray[1] = nullptr;
	vertexArray[1] = vertexArray[heapSize];
	heapSize--;
	//fix any violation of the max heap contract
	maxHeapify(1);	
	return max;//return the maximum vertex
}


int PMSTHeap::getLeftChild(int index)
{
	//left child calc
	return (2 * index);
}

int PMSTHeap::getParent(int index)
{
	//parent calc
	return (index / 2);
}

int PMSTHeap::getRightChild(int index)
{
	//right child calc
	return ((2 * index) + 1);
}



void PMSTHeap::increaseKey(int index, PVertex* key)
{
	//used to set a key at a given index to a new value
	if (index == 1)//if we are adding the first vertex pointer to the max heap
	{
		//add the key to the root
		vertexArray[index] = key;
		//the vertex is now in the mst heap
		key->isInMST = true;
		//add the weight of the traversal value to the MST total weight
		MSTWeight += key->traverseValue;
		return;
	}
	//set the specified index to the new key
	vertexArray[index] = key;
	//the vertex is now in the MST heap
	key->isInMST = true;
	MSTWeight += key->traverseValue;//add the traversal value of the key to the MST weight
	while (index > 1 && vertexArray[getParent(index)]->parent->name + vertexArray[getParent(index)]->name> vertexArray[index]->parent->name +vertexArray[index]->name )
	{
		//if we violated the max heap contract we must correct it
		//the parent name is considered first then added to the current vertex name and compared against its parent. If the parent is alphabetically smaller than the key
		//we swap the current index and its parent
		swap(index, getParent(index));
		index = getParent(index);//set the new index we swapped to
	}
}

void PMSTHeap::insert(PVertex* key)
{
	//we will add a new vertex to the max heap MST
	if (heapSize == length)//if we are at capacity limit
	{
		//heap overflow and probably crash
		std::cout << "heap overflow " << "\n";
		return;
	}
	//increase heapsize 
	heapSize++;
	//set the key value at the new heapsize
	increaseKey(heapSize, key);
}

void PMSTHeap::maxHeapify(int index)
{
	//maintains the max heap contract of all key at an index will be greater than or equal alphabetically to their children
	int left = getLeftChild(index);
	int right = getRightChild(index);
	int largest = index;
	//get the left and right children of the current index
	if (left < heapSize&&vertexArray[left]->parent->name+vertexArray[left]->name < vertexArray[largest]->parent->name+ vertexArray[largest]->name )
	{//consider the parent name + the index(or left child's) name and see which one is alphabetically greater 
		largest = left;//if the left is greater it is the new largest vertex
	}
	if (right < heapSize&&vertexArray[right]->parent->name+vertexArray[right]->name   < vertexArray[largest]->parent->name+vertexArray[largest]->name)
	{
		//consider the right child as see if it is alphabetically greater than the largest index
		largest= right;//if so set the right child as the largest index
	}
	if (largest != index)
	{
		//if the contract was broken then swap the current index and the largest index
		swap(index, largest);
		maxHeapify(largest);//recurse down into the heap to fix for violations
	}
}

void PMSTHeap::swap(int index, int largest)
{
	//store the alphabetically smaller index
	PVertex* largerVertex = vertexArray[index];
	vertexArray[index] = vertexArray[largest];//move the larger index up
	vertexArray[largest] = largerVertex;//store the smaller index
}

PMSTHeap::~PMSTHeap()
{
}



double PMSTHeap::getMSTWeight()
{
	//returns the MST total weight
	return MSTWeight;
}