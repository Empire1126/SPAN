#pragma once
#include <string>


class KVertex
{
public:
	KVertex();
	~KVertex();
	std::string name;
	int currentIndex = 0;
	int id = 0;
};
typedef KVertex* KVertexPtr;

