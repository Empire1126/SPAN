#pragma once 
#include <type_traits>
#include "KEdge.h"
#include <iostream>
//KHeap.h
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18

constexpr bool isMaxHeap(bool isMax)
{
	//compile time function to help the templated heap determine whether to build a max heap or min heap
	return isMax;
}


template <bool isMax,typename = void> class KHeap
{
//templated heap class, this is the minheap as the default, this heap will hold our edges and sort them by least weighted edge for kruskals	antilogarithm
//MANY unused function to get the templated heap to compile. they are marked with "//NOT USED"
public:
	KHeap(int size)
	{
		//NOT USED
		//the most basic constructor that this heap can have is a with a size for the heap array
		minHeap = new KEdge[size];
		length = size;
		heapSize = 0;
	}
	KHeap(int size, KEdgePtr newHeap)
	{
		//we will use a heap constructor with the edge array already created
		//like with all heaps with arrays in the constructor we must build the heap from the array
		//the new heap from entry point will be the max size of the heap so length and heapsize are equal
		minHeap = newHeap;
		heapSize = size;
		length = size;
		for(int i = size/2;i>0;i--)
		{
			//we must build the heap from the array so minheapify to keep the least weighted edge on top of the heap
			minHeapify(i);
		}
	}
	~KHeap(){}

	void insert(KEdge key)
	{
		//NOT USED min heap insert
		if(heapSize==length)
		{
			std::cout << "heap overflow "<<"\n";
			return;
		}
		heapSize++;					
		decreaseKey(heapSize, key);
	}
	KEdgePtr minimum()
	{
		//NOT USED min heap min
		return &minHeap[1];
	}
	KEdge extractMin()
	{
		//NOT USED min heap extract
		if(heapSize<1)
		{
			std::cout << "heap underflow "<<"\n";
			KEdge nothing;
			return nothing;
		}
		KEdge min = minHeap[1];
		delete &minHeap[1];
		minHeap[1] = minHeap[heapSize];
		heapSize--;
		minHeapify(1);
		return min;
	}
	void decreaseKey(int index, KEdge key)
	{
		//NOT used min heap decrease key
		if(key.weight > minHeap[index].weight)
		{
			std::cout << "error new key value is greater than current value";
			return;
		}
		minHeap[index] = key;
		while (index > 0 && minHeap[getParent(index)].weight > minHeap[index].weight)
		{
			swap(index, getParent(index));
			index = getParent(index);
		}
	}
	KEdgePtr HeapSort()
	{
		//this min heap will be sorted into an array of the smallest weighted edges for us to consider
		for(int i = heapSize-1 ;i>1;i--)
		{
			//for the entirety of the heap
			swap(1, i);//swap the last and first element, the first element is guaranteed to be the smallest weighted edge
			heapSize--;//decrease the heap size
			minHeapify(1);//bring the smallest edge to the top of the heap
		}
		return minHeap;
	}
	void printMinHeap()
	{
		//NOT USED min heap print
		std::cout << "min heap print"<<"\n";
	}
private:
	//the length of the array and the heapsize of the heap
	int length = 0;
	int heapSize = 0;
	//pointer to hold the edge array
	KEdgePtr minHeap = nullptr;
	
	int getLeftChild(int index)
	{
		//heap left child calculation
		return (2*index);
	}
	int getRightChild(int index)
	{
		//heap right child calculation
		return ((2 * index) + 1);
	}
	int getParent(int index)
	{
		//heap parent child calculation
		return (index / 2);
	}	
	void minHeapify(int index)
	{
		//Min heapify, exists to preserve the min heap contract. recursive
		//the smallest item will always be pushed to the top of the heap this way.
		int left = getLeftChild(index);//get the left child of the current index
		int right = getRightChild(index);//get the right child of the current index
		int smallest = index;//the smallest item will be the index for now
		if(left<heapSize&&minHeap[left].weight<minHeap[smallest].weight)//if the left child is in the heap and has a smaller weight than the index
		{
			smallest = left;//the smallest is now the left child index
		}
		if(right<heapSize&&minHeap[right].weight<minHeap[smallest].weight)//if the right child is in the heap and has a weight smaller than the smallest index
		{
			smallest = right;//the smallest weighted index is now the right child
		}
		if(smallest!=index)//if the minheap property is broken
		{
			swap(index, smallest);//swap the offending items
			minHeapify(smallest);//recurse down to find more offenses
		}
	}
	void swap(int index,int smallestKeyIndex)
	{
		//simple swap function, stores a temp KEdge		
		KEdge largerKey = minHeap[index];
		//sets the old index to the new smaller key
		minHeap[index] = minHeap[smallestKeyIndex];
		//moves the old larger key down the heap
		minHeap[smallestKeyIndex] = largerKey;
	}

};



template<bool isMax> class KHeap<isMax, typename std::enable_if<isMaxHeap(isMax)>::type>
{
//templated heap class, this is the max heap that will hold the MST of the kruskal algorithm.
//by using a compile time function and a boolean in said function (isMaxHeap above) this causes our default type of typename = void
//in the min heap to compile with a type and using enable_if from std we can determine if this typename has a type and enable the compilation of the template,
//treating it bool for the template
//though is really is a type returned from the compile time function (as per my understanding) I thought it would be cool. It took a lot of time to research this.
public:
	KHeap(int size)
	{
		//we will make a new MST max heap to hold the finished graph
		maxHeap = new KEdge[size];//allocate a Kedge array 
		length = size;
		heapSize = 0;
	}
	KHeap(int size, KEdgePtr newHeap)
	{
		//NOT USED max heap constructor with predefined array
		maxHeap = newHeap;
		heapSize = size;
		length = size;
		for (int i = size / 2; i > 0; i--)
		{
			maxHeapify(i);
		}
	}
	~KHeap() {}

	void insert(KEdge key)
	{
		//we will use this to insert new edges into the array to build the MST
		if (heapSize == length)//if we are at max capacity
		{
			//overflow (should never happen)
			std::cout << "heap overflow " << "\n";
			return;
		}
		//increase heap size
		heapSize++;
		//increase the key at the new heap size location
		increaseMSTKey(heapSize, key);
	}
	KEdgePtr maximum()
	{
		//NOT USED max heap max function
		return &maxHeap[1];
	}
	KEdge extractMax()
	{
		//we will use this to retrieve the mst edges from the max heap to print them
		if (heapSize < 1)//if the heap is empty
		{
			//return blank edge
			KEdge nothing;
			nothing.destination = nullptr;
			nothing.initial = nullptr;
			return nothing;
		}
		//otherwise copy the top of the heap
		KEdge max = maxHeap[1];
		//move the end of the heap up to the top
		maxHeap[1] = maxHeap[heapSize];
		//remove the last item in the heap(now a copy of the first item in the heap) by decreasing the heapsize
		heapSize--;
		//max heapify to mantain the max heap contract
		maxHeapify(1);
		return max;//return the copied maximum
	}
	void increaseMSTKey(int index, KEdge key)	
	{
		//MST increase function, it will go to the specified index and set the key at that index to the new key provided
		if(index==1)//if we are at hte root
		{
			//set the root to the new key
			maxHeap[index] = key;
			//add the edge's weight to the MST total weight to traverse
			MSTWeight += key.weight;
			return;
		}
		//otherwise go to the index and set it equal to the provided key
		maxHeap[index] = key;
		//add the edge's weight to the mst traversal weight
		MSTWeight += key.weight;
		//we might have broken the max heap contract of alphabetical priority
		while (index > 1 && (maxHeap[getParent(index)].initial->name + maxHeap[getParent(index)].destination->name) > (maxHeap[index].initial->name + maxHeap[index].destination->name))
		{
			//if the name generated from the edge we inserted is alphabetically greater than its parent (the comparison is greater than for the parent (aka backwards from my explanation))
			//swap the parent key and the inserted key until we are either at the root or the parent is now less than ( greater technically) than the key we  inserted 
			swap(index, getParent(index));
			index = getParent(index);			
		}
	}
	KEdgePtr HeapSort()
	{
		//NOT USED heap sort to sort the max heap alphabetically
		for (int i = heapSize-1; i > 1; i--)
		{
			swap(1, i);
			heapSize--;
			maxHeapify(1);
		}
		return maxHeap;
	}
	void printMaxHeap()
	{
		//displays the MST inserted into the heap
		std::cout << MSTWeight << "\n";
		//get the next maximum alphabetically
		KEdge nextEdge = extractMax();
		//as long as the next minimum isn't null
		while(nextEdge.destination!=nullptr)
		{		
			//display it
			std::cout << nextEdge.initial->name + "-" + nextEdge.destination->name + ": " << nextEdge.weight <<"\n";
			//get the next minimum
			nextEdge = extractMax();			
		}
	}
private:
	//length, and heapsize for the size of the array and size of the heap respectively
	int length = 0;
	int heapSize = 0;	
	double MSTWeight = 0;//the total weight of the MST
	KEdgePtr maxHeap = nullptr;//pointer to hold the KEdge array 
	int getLeftChild(int index)
	{
		//heap left child calculation
		return (2 * index);
	}
	int getRightChild(int index)
	{
		//heap right child calc
		return ((2 * index) + 1);
	}
	int getParent(int index)
	{
		//heap parent calc
		return (index / 2);
	}
	
	void maxHeapify(int index)
	{
		//like min heap this max heap will preserve a contract where all edges will be sorted alphabetically with aaa being the highest priority
		//We will consider the initial vertex that an edge starts at and then add the destination vertex to the name of the edge. (ab > ac). recursive
		int left = getLeftChild(index);//get left child
		int right = getRightChild(index);//get right child
		int largest = index;	//the largest item so far is the index we are at
		if (left < heapSize && (maxHeap[left].initial->name + maxHeap[left].destination->name)< maxHeap[largest].initial->name + maxHeap[largest].destination->name)
		{
			//if we still are in the heap and the left child name (from initial to destination) is less than (alphabetically greater than) the index's name
			largest = left;//the largest item is the left child
		}
		if (right < heapSize && (maxHeap[right].initial->name + maxHeap[right].destination->name) < (maxHeap[largest].initial->name + maxHeap[largest].destination->name))
		{
			//if the right child's name is less than (aka alphabetically greater than) the largest item's name then the largest item is the right child
			largest = right;
		}
		if (largest != index)//if the max heap contract was violated
		{
			//swap the offending edges
			swap(index, largest);
			//recurse down to find more violations
			maxHeapify(largest);
		}
	}
	void swap(int index, int smallest)
	{
		//swaps two keys in the max heap
		KEdge temp = maxHeap[index];//store the alphabetically smaller key
		maxHeap[index] = maxHeap[smallest];//move the alphabetically larger key up the heap
		maxHeap[smallest] = temp;//move the stored key down the heap
	}
	
};
