#pragma once
#include <string>
#include <iostream>

class PEdge;
class PVertex
{
public:
	PVertex();
	PVertex(std::string initialName);
	~PVertex();
	std::string name;
	double traverseValue = INT_MAX;
	PVertex* parent = nullptr;
	PEdge* nextEdge = nullptr;
	bool isInMST = false;
};
class PEdge
{
public:
	PEdge();
	~PEdge();
	PVertex* destinationVertex = nullptr;
	PEdge* nextEdge = nullptr;
	double weight = 0;
};
