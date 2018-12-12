#pragma once 
#include <type_traits>
#include "KEdge.h"
#include <iostream>

constexpr bool isMaxHeap(bool isMax)
{
	return isMax;
}

template <bool isMax,typename = void> class KHeap
{	
public:
	KHeap(int size)
	{
		minHeap = new KEdge[size];
		length = size;
		heapSize = 0;
	}
	KHeap(int size, KEdgePtr newHeap)
	{
		minHeap = newHeap;
		heapSize = size;
		length = size;
		for(int i = size/2;i>0;i--)
		{
			minHeapify(i);
		}
	}
	~KHeap(){}

	void insert(KEdge key)
	{
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
		return &minHeap[1];
	}
	KEdge extractMin()
	{
		if(heapSize<1)
		{
			std::cout << "heap underflow "<<"\n";
			KEdge nothing;
			return nothing;
		}
		KEdge min = minHeap[1];
		delete &minHeap[1];
		minHeap[1] = minHeap[heapSize-1];
		heapSize--;
		minHeapify(1);
		return min;
	}
	void decreaseKey(int index, KEdge key)
	{
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
		for(int i = heapSize-1 ;i>1;i--)
		{
			swap(1, i);
			heapSize--;
			minHeapify(1);
		}
		return minHeap;
	}
	void printMinHeap()
	{
		std::cout << "min heap print"<<"\n";
	}
private:
	int length = 0;
	int heapSize = 0;
	KEdgePtr minHeap = nullptr;
	int getLeftChild(int index)
	{
		return (2*index);
	}
	int getRightChild(int index)
	{
		return ((2 * index) + 1);
	}
	int getParent(int index)
	{
		return (index / 2);
	}
	void buildMinHeap()
	{
		
	}
	void minHeapify(int index)
	{
		int left = getLeftChild(index);
		int right = getRightChild(index);
		int smallest = index;
		if(left<heapSize&&minHeap[left].weight<minHeap[smallest].weight)
		{
			smallest = left;
		}
		if(right<heapSize&&minHeap[right].weight<minHeap[smallest].weight)
		{
			smallest = right;
		}
		if(smallest!=index)
		{
			swap(index, smallest);
			minHeapify(smallest);
		}
	}
	void swap(int index,int smallestKeyIndex)
	{
		KEdge largerKey = minHeap[index];		
		minHeap[index] = minHeap[smallestKeyIndex];
		minHeap[smallestKeyIndex] = largerKey;
	}

};



template<bool isMax> class KHeap<isMax, typename std::enable_if<isMaxHeap(isMax)>::type>
{
public:
	KHeap(int size)
	{
		maxHeap = new KEdge[size];
		length = size;
		heapSize = 0;
	}
	KHeap(int size, KEdgePtr newHeap)
	{
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
		if (heapSize == length)
		{
			std::cout << "heap overflow " << "\n";
			return;
		}
		heapSize++;
		increaseMSTKey(heapSize, key);
	}
	KEdgePtr maximum()
	{
		return &maxHeap[1];
	}
	KEdge extractMax()
	{
		if (heapSize < 1)
		{
			std::cout << "heap underflow " << "\n";
			KEdge nothing;
			return nothing;
		}
		KEdge max = maxHeap[1];
		delete &maxHeap[1];
		maxHeap[1] = maxHeap[heapSize-1];
		heapSize--;
		maxHeapify(1);
		return max;
	}
	void increaseMSTKey(int index, KEdge key)	{
		
		if(index==1)
		{
			maxHeap[index] = key;
			MSTWeight += key.weight;
			return;
		}
		maxHeap[index] = key;
		MSTWeight += key.weight;		
		while (index > 1 && maxHeap[getParent(index)].initial->name + maxHeap[getParent(index)].destination->name > maxHeap[index].initial->name + maxHeap[index].destination->name)
		{
			swap(index, getParent(index));
			index = getParent(index);			
		}
	}
	KEdgePtr HeapSort()
	{
		for (int i = heapSize; i > 1; i--)
		{
			swap(1, i);
			heapSize--;
			maxHeapify(1);
		}
		return maxHeap;
	}
	void printMaxHeap()
	{
		std::cout << MSTWeight << "\n";
		HeapSort();
		for (int i = 1; i <= length; i++)
		{
			if(maxHeap[i].initial!=nullptr&&maxHeap[i].destination!=nullptr)
			{
				std::cout << maxHeap[i].initial->name + "-" + maxHeap[i].destination->name + ": " << maxHeap[i].weight;
			}
			
		}
	}
private:
	int length = 0;
	int heapSize = 0;
	int MSTWeight = 0;
	KEdgePtr maxHeap = nullptr;
	int getLeftChild(int index)
	{
		return (2 * index);
	}
	int getRightChild(int index)
	{
		return ((2 * index) + 1);
	}
	int getParent(int index)
	{
		return (index / 2);
	}
	void buildMaxHeap()
	{

	}
	void maxHeapify(int index)
	{
		int left = getLeftChild(index);
		int right = getRightChild(index);
		int largest = index;
		std::string leftName = maxHeap[left].initial->name + maxHeap[left].destination->name;
		std::string rightName = maxHeap[right].initial->name + maxHeap[right].destination->name;
		std::string indexName = maxHeap[index].initial->name + maxHeap[index].destination->name;
		if (left < heapSize && leftName > indexName)
		{
			largest = left;
		}
		if (right < heapSize && rightName > indexName)
		{
			largest = right;
		}
		if (largest != index)
		{
			swap(index, largest);
			maxHeapify(largest);
		}
	}
	void swap(int index, int smallest)
	{
		KEdge temp = maxHeap[index];
		maxHeap[index] = maxHeap[smallest];
		maxHeap[smallest] = temp;
	}
	
};
