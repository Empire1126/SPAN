#pragma once
#include <string>
//KVertex.h
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18

class KVertex
{
	//this class will hold the vertex of the kruskal algorithm 
public:
	KVertex();
	~KVertex();
	std::string name;
	int currentIndex = 0;//the current index is the current set that holds the vertex
	int id = 0;//the starting set of the vertex
};
typedef KVertex* KVertexPtr;

