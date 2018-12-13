#include "pch.h"
#include "PHeap.h"



PHeap::PHeap(int size, PVertex** vertices)
{//the min heap of vertex's will always be constructed with the vertices pointer array
	//provided as well as the size of that array
	length = size;//set the length and heapsize to the size of the provided array
	heapSize = size;
	vertexArray = vertices;
	for(int i =size/2;i>0;i-- )
	{
		//we must build the heap up so min heapify (though we will only call it once)
		minHeapify(i);
	}
}

int PHeap::isNotEmpty()
{
	//will determine in minheap is empty via heapsize
	return heapSize-1;
}

void PHeap::decreaseKeyValue(PVertex* key, double value)
{
	//used to set the new traverse key value for a vertex 	
	for(int i =1;i<heapSize;i++)
	{
		//traverse the entire heap
		if(vertexArray[i]==key)
		{
			//once the desired key to be updated is found
			vertexArray[i]->traverseValue = value;//set the new key traverse value
			int index = i;//record the index we are at
			while(index>1 && vertexArray[getParent(index)]->traverseValue > key->traverseValue)//if we aren't at the root and the minheap contract is broken by the change
			{
				swap(index, getParent(index));//move the key with the new index up the heap
				index = getParent(index);//get the next parent
			}
			break;//break we only need to change one key
		}
	}

}


PHeap::~PHeap()
{
}
PVertex* PHeap::extractMin()
{
	//used to extract the next least vertex from the heap.
	if(heapSize<1)//if the heap is empty
	{
		//return blank vertex
		std::cout << "heap underflow " << "\n";
		PVertex* nothing=nullptr;
		return nothing;
	}
	//otherwise we will return the root of the heap always as this is the least valued vertex in the heap
	PVertex* min = vertexArray[1];
	//set the old root to null and move the end of the heap up
	vertexArray[1] = nullptr;
	vertexArray[1] = vertexArray[heapSize-1];
	//decrease heap size to remove old end of heap
	heapSize--;
	//minheapify to correct and violation of the min heap contract
	minHeapify(1);
	return min;//return the minimum vertex
}
int PHeap::getParent(int index)
{
	//heap parent calc
	return (index / 2);
}
int PHeap::getLeftChild(int index)
{
	//heap left child calc
	return (2 * index);
}
int PHeap::getRightChild(int index)
{
	//heap right child calc
	return ((2 * index) + 1);
}
void PHeap::minHeapify(int index)
{
	//maintains the minheap contract for Prims algorithm, any parent in th heap shall ways be greater than or equal to its children
	//by traversal weight found in adjacent vertex's via Prims, all starting at infinity (int_max)
	int left = getLeftChild(index);
	int right = getRightChild(index);
	int smallest = index;
	//get the right and left children so far the current index is the smallest vertex
	if (left < heapSize&&vertexArray[left]->traverseValue< vertexArray[smallest]->traverseValue)
	{
		//if the left child is smaller in its value than the index
		smallest = left;//the smallest index is the left child
	}
	if (right < heapSize&&vertexArray[right]->traverseValue< vertexArray[smallest]->traverseValue)
	{
		//similarly if the right child is smaller than the smallest index by traverse value 
		smallest = right;//then the smallest index is the right child
	}
	if (smallest != index)
	{
		//if the min heap contract was violated , correct the violation with a swap
		//and recurse down the min heap to correct any more violations
		swap(index, smallest);
		minHeapify(smallest);
	}
}
void PHeap::swap(int index, int smallest)
{
	//swaps two vertex's 
	PVertex* largerVertex = vertexArray[index];//store the larger vertex by value
	vertexArray[index] = vertexArray[smallest];//move the smaller vertex up
	vertexArray[smallest] = largerVertex;//move the stored larger vertex back down the heap
}
