#pragma once
#include <string>
#include <iostream>
//PVertex.h
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18


class PEdge;//declare Pedge class
class PVertex
{	
//class to contain the Prim vertex
public:
	PVertex();
	PVertex(std::string initialName);//construct vertex with name
	~PVertex();
	std::string name;
	double traverseValue = INT_MAX;//all vertex values start at infinity
	PVertex* parent = nullptr;//the vertex has reference to its parent in the MST
	PEdge* nextEdge = nullptr;//it also has a linked list of edges representing all edges to this vertex
	bool isInMST = false;//is the vertex included in the MST yet
};
class PEdge
{
	//class to contain an edge in the Prim graph
public:
	PEdge();
	~PEdge();
	PVertex* destinationVertex = nullptr;//edge connect vertex's together so the edge has a reference to the vertex it connects to
	PEdge* nextEdge = nullptr;//the next edge in the linked list of edges from a vertex
	double weight = 0;//the weight of the edge is zero to start
};
