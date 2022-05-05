#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
	Graph(void);
	~Graph(void);

	int GetNumberOfNodes() const;
	int GetNumberOfEdges() const;
	
	void SetNumberOfNodes(int numberOfNodes);
	void SetNumberOfEdges(int numberOfEdges);
	void AddEdge(int startNode, int endNode);

	vector<int> GetShortestPath(int startNode, int endNode, bool isDirected = false, bool isWeighted = false) const;

	friend ostream& operator<<(ostream& sout, const Graph& graph);

private:
	int numberOfNodes;		// Number of nodes in the graph
	int numberOfEdges;		// Number of edges in the graph
	vector<vector<int>> node;	// vector of nodes
};

#endif