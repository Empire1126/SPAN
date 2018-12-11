// MST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "KRUSKAL.h"

int main()
{
	
    std::cout << "Hello World!\n";
	Graph graph;
	Vertex vertices[10];
	
	edge edges[15];
	
	vertices[1].name = "a";
	vertices[2].name = "b";
	vertices[3].name = "c";
	vertices[4].name = "d";
	vertices[5].name = "e";
	vertices[6].name = "f";
	vertices[7].name = "g";
	vertices[8].name = "h";
	vertices[9].name = "i";

	graph.sizeOfVertices = 10;
	graph.sizeOfEdges = 15;
	edges[1].weight = 11;
	edges[1].initial = &vertices[2];
	edges[1].destination = &vertices[8];

	edges[2].weight = 14;
	edges[2].initial = &vertices[4];
	edges[2].destination = &vertices[6];

	edges[3].weight = 10;
	edges[3].initial = &vertices[5];
	edges[3].destination = &vertices[6];

	edges[4].weight = 9;
	edges[4].initial = &vertices[4];
	edges[4].destination = &vertices[5];

	edges[5].weight = 8;
	edges[5].initial = &vertices[2];
	edges[5].destination = &vertices[3];

	edges[6].weight = 8;
	edges[6].initial = &vertices[1];
	edges[6].destination = &vertices[8];

	edges[7].weight = 7;
	edges[7].initial = &vertices[3];
	edges[7].destination = &vertices[4];

	edges[8].weight = 7;
	edges[8].initial = &vertices[8];
	edges[8].destination = &vertices[9];

	edges[9].weight = 6;
	edges[9].initial = &vertices[7];
	edges[9].destination = &vertices[9];

	edges[10].weight = 4;
	edges[10].initial = &vertices[3];
	edges[10].destination = &vertices[6];

	edges[11].weight = 4;
	edges[11].initial = &vertices[1];
	edges[11].destination = &vertices[2];

	edges[12].weight = 2;
	edges[12].initial = &vertices[6];
	edges[12].destination = &vertices[7];

	edges[13].weight = 2;
	edges[13].initial = &vertices[3];
	edges[13].destination = &vertices[9];

	edges[14].weight = 1;
	edges[14].initial = &vertices[7];
	edges[14].destination = &vertices[8];
	
	graph.vertices = vertices;
	graph.edges = edges;
	
	KRUSKAL* kruskal = new KRUSKAL(graph);

	std::cout << "test";
}

