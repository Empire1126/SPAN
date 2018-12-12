#pragma once
#include <string>
#include <iostream>
#include "PEdge.h"

class PVertex
{
public:
	PVertex();
	~PVertex();
	std::string name;
	double traverseValue = INT_MAX;
	PVertex* parent = nullptr;
	PEdge* nextEdge = nullptr;	
};

