// MST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "KRUSKAL.h"
#include "PGraph.h"
#include "PRIM.h"


void testPrim()
{
	PGraph* PrimGraph = new PGraph();

	PVertex** verrtices = new PVertex*[10];
	PVertex* a = new PVertex();
	a->name = "a";
	PVertex* b = new PVertex();
	b->name = "b";
	PVertex* c = new PVertex();
	c->name = "c";
	PVertex* d = new PVertex();
	d->name = "d";
	PVertex* e = new PVertex();
	e->name = "e";
	PVertex* f = new PVertex();
	f->name = "f";
	PVertex* g = new PVertex();
	g->name = "g";
	PVertex* h = new PVertex();
	h->name = "h";
	PVertex* i = new PVertex();
	i->name = "i";
	verrtices[1]= a;
	verrtices[2]= b;
	verrtices[3]= c;
	verrtices[4]= d;
	verrtices[5]= e;
	verrtices[6]= f;
	verrtices[7]= g;
	verrtices[8]= h;
	verrtices[9]= i;

	PEdge* a4 = new PEdge();
	a4->destinationVertex = verrtices[2];
	a4->weight = 4;

	PEdge* a8 = new PEdge();
	a8->weight = 8;
	a8->destinationVertex = verrtices[8];
	a4->nextEdge = a8;
	verrtices[1]->nextEdge= a4;
	PEdge* b11 = new PEdge();
	b11->destinationVertex = verrtices[8];
	b11->weight = 11;
	PEdge* b8 = new PEdge();
	b8->weight = 8;
	b8->destinationVertex = verrtices[3];
	PEdge* b4 = new PEdge();
	b4->weight = 4;
	b4->destinationVertex = verrtices[1];
	b8->nextEdge = b11;
	b4->nextEdge = b8;
	verrtices[2]->nextEdge = b4;
	PEdge* c8 = new PEdge();
	c8->weight = 8;
	c8->destinationVertex = verrtices[2];
	PEdge* c2 = new PEdge();
	c2->weight = 2;
	c2->destinationVertex = verrtices[9];
	PEdge* c4 = new PEdge();
	c4->weight = 4;
	c4->destinationVertex = verrtices[6];
	PEdge* c7 = new PEdge();
	c7->weight = 7;
	c7->destinationVertex = verrtices[4];
	c8->nextEdge = c2;
	c2->nextEdge = c4;
	c4->nextEdge = c7;
	verrtices[3]->nextEdge = c8;
	PEdge* d7 = new PEdge();
	d7->weight = 7;
	d7->destinationVertex = verrtices[3];
	PEdge* d9 = new PEdge();
	d9->weight = 9;
	d9->destinationVertex = verrtices[5];
	PEdge* d14 = new PEdge();
	d14->weight = 14;
	d14->destinationVertex = verrtices[6];
	d7->nextEdge = d9;
	d9->nextEdge = d14;
	verrtices[4]->nextEdge = d7;
	PEdge* e9 = new PEdge();
	e9->weight = 9;
	e9->destinationVertex = verrtices[4];
	PEdge* e10 = new PEdge();
	e10->weight = 10;
	e10->destinationVertex = verrtices[6];
	e9->nextEdge = e10;
	verrtices[5]->nextEdge = e9;
	PEdge* f10 = new PEdge();
	f10->weight = 10;
	f10->destinationVertex = verrtices[5];
	PEdge* f14 = new PEdge();
	f14->weight = 14;
	f14->destinationVertex = verrtices[4];
	PEdge* f4 = new PEdge();
	f4->weight = 4;
	f4->destinationVertex = verrtices[3];
	PEdge* f2 = new PEdge();
	f2->weight = 2;
	f2->destinationVertex = verrtices[7];
	f10->nextEdge = f2;
	f2->nextEdge = f14;
	f14->nextEdge = f4;
	verrtices[6]->nextEdge = f10;
	PEdge* g2 = new PEdge();
	g2->weight = 2;
	g2->destinationVertex = verrtices[6];
	PEdge* g6 = new PEdge();
	g6->weight = 6;
	g6->destinationVertex = verrtices[9];
	PEdge* g1 = new PEdge();
	g1->weight = 1;
	g1->destinationVertex = verrtices[8];
	g2->nextEdge = g1;
	g1->nextEdge = g6;
	verrtices[7]->nextEdge = g2;
	PEdge* h1 = new PEdge();
	h1->weight = 1;
	h1->destinationVertex = verrtices[7];
	PEdge* h7 = new PEdge();
	h7->weight = 7;
	h7->destinationVertex = verrtices[9];
	PEdge* h11 = new PEdge();
	h11->weight = 11;
	h11->destinationVertex = verrtices[2];
	PEdge* h8 = new PEdge();
	h8->weight = 8;
	h8->destinationVertex = verrtices[1];
	h1->nextEdge = h11;
	h11->nextEdge = h7;
	h7->nextEdge = h8;
	verrtices[8]->nextEdge = h1;
	PEdge* i7 = new PEdge();
	i7->weight = 7;
	i7->destinationVertex = verrtices[8];
	PEdge* i6 = new PEdge();
	i6->weight = 6;
	i6->destinationVertex = verrtices[7];
	PEdge* i2 = new PEdge();
	i2->weight = 2;
	i2->destinationVertex = verrtices[3];
	i7->nextEdge = i2;
	i2->nextEdge = i6;
	verrtices[9]->nextEdge = i7;
	PrimGraph->vertices = verrtices;
	PrimGraph->sizeOfVertices = 10;
	PRIM* primAlgo = new PRIM(PrimGraph);
}

int main(int argc, char* argv[])
{
	testPrim();
	
    
	KGraph graph;
	KVertex vertices[10];
	
	KEdge edges[15];
	
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



