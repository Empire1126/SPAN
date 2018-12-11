#pragma once
#include <string>


class Vertex
{
public:
	Vertex();
	~Vertex();
	std::string name;
	int currentIndex = 0;
	int id = 0;
};
typedef Vertex* vertexPtr;

