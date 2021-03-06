// SPAN.cpp
// Luke Pinkney
// EECS 2510 Fall 2018
// 12/10/18

#include "pch.h"
#include "KRUSKAL.h"
#include "PGraph.h"
#include "PRIM.h"
#include <fstream>






int main(int argc, char* argv[]){
	//entry point
	//takes in command line arguments
	if(argc < 2)
	{
		//if a file isn't provided then we can't build a graph
		std::cout << "must call program with a proper file location to input data from"<<"\n";
	}
	std::string fileLocation = argv[1];	//the graph data is the second argument
	//std::string fileLocation = "GraphData.txt"; // data used to test
	std::ifstream graphFile; // ifstream to get data from file
	graphFile.open(fileLocation);	//open the new data file
	if (graphFile)//if the stream is good
	{				
		int graphSize;//the next formatted input should be a numeric that determines the size of the graphs
		if (graphFile >> graphSize)//if the input is a numeric
		{
			//begin making the graphs,
			//we will make a new graph for Kruskal and Prims each
			KGraph* kgraph = new KGraph();
			KVertexPtr KVertices = new KVertex[graphSize + 1];//over-declare the arrays to work with the 1 indexed heaps
			PGraph* pgragh = new PGraph();
			PVertex** PVertices = new PVertex*[graphSize + 1];
			for (int i = 1; i < graphSize + 1; i++)
			{
				//loop through the next graphSize entries in the file
				//these are the vertex names for the graphs
				std::string vertexName;
				graphFile >> vertexName;
				KVertices[i].name = vertexName;
				PVertices[i] = new PVertex(vertexName);
			}
			//create the Kruskal Edge pointer array
			KEdgePtr* KEdges = new KEdge*[graphSize + 1];
			for(int i =0;i<graphSize+1;i++)
			{
				//initialize all pointers in the array
				KEdges[i] = nullptr;
			}
			double nextNum = 0;//holds teh data from file for edge weight values
			for (int i = 1; i < graphSize + 1; i++)
			{
				//for all rows
				KEdges[i] = new KEdge[graphSize + 1];//create a new array of pointers for Kruscal edge pointer array
				for (int j = 1; j < graphSize + 1; j++)
				{
					//and all columns
					graphFile >> nextNum;//get the next weight
					if (nextNum != 0)
					{
						//if it isn't infinity
						if (KEdges[j]==nullptr)//and the kruscal symmetric row isn't initialized yet
						{
							KEdges[i][j].weight = nextNum;//set the new weights value
							//tie the new edge to the vertices that makes up the kruscal graph
							KEdges[i][j].initial = &KVertices[i];
							KEdges[i][j].destination = &KVertices[j];
						}
						//for Prims we create a linked list of edges for each vertex to hold
						PEdge* trailer = nullptr;//we must record the parent vertex if there is one
						PEdge* tempEdge = PVertices[i]->nextEdge;//get the next edge from the vertex row
						while (tempEdge != nullptr)
						{
							//if the edge isn't null then we must keep getting the next edge until we are at the end of the edge linked list
							trailer = tempEdge;
							tempEdge = tempEdge->nextEdge;
						}
						//once at the end of the linked list of edges
						tempEdge = new PEdge();//make a new edge
						tempEdge->weight = nextNum;//set its value as the nextNum
						tempEdge->destinationVertex = PVertices[j];//tie the edges destination to the vertex array
						if (trailer != nullptr)
						{
							//if we had a parent edge
							trailer->nextEdge = tempEdge;//attach new edge to end of linked list
						}
						else
						{
							//otherwise the vertex gets the reference to the new edge
							PVertices[i]->nextEdge = tempEdge;
						}
					}
				}
			}
			//now that we have the full kruscal edges we must flatten them out for the heap to work with
			KEdgePtr flatenedEdges = new KEdge[(graphSize*graphSize) + 1];//new array that will actually be sent to kruscals
			int64_t flatIndex = 1;//start at 1 for heaps
			kgraph->sizeOfEdges = 1;//size is 1 for over-deceleration 
			for (int i = 1; i < graphSize+1; i++)
			{
				//for every row
				for (int j = 1; j < graphSize+1; j++)
				{
					//and every column
					if (KEdges[i][j].weight != INT_MAX)
					{
						//if the weight at the edge is not infinity 
						flatenedEdges[flatIndex] = KEdges[i][j];//add the edge to the flattened array
						flatIndex++;//increment the flattened current index
						kgraph->sizeOfEdges++;//increase the counter of the edges in the array 
					}
				}
			}
			//once we have a flattened array add the arrays and sizes to the graphs
			//Kruscal's will get vertices and edges and sizes
			//Prim's will get the vertices and size of vertex array
			kgraph->edges = flatenedEdges;
			kgraph->vertices = KVertices;
			kgraph->sizeOfVertices = graphSize + 1;
			pgragh->vertices = PVertices;
			pgragh->sizeOfVertices = graphSize + 1;
			//create the new algorithms and solve them
			//display results
			KRUSKAL* kruskalAlgo = new KRUSKAL(kgraph);
			PRIM* primAlgo = new PRIM(pgragh);
			std::cout << "test";
		}
		else
		{
			//if no numeric was given we cannot build the graph
			std::cout << "first line of a valid graph data file must be a numeric of n number of vertices"<<"\n";
			return 0;
		}
	}
	else
	{
		//if the file can't be found through and error
		std::cout << "file does not appear to exist"<<"\n";
		return 0;
	}	
}



