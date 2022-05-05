#include "Graph.h"


// Constructs the graph in a safe state
Graph::Graph(void)
{
	numberOfNodes = 0;
	numberOfEdges = 0;

	// *******************************************************************
	// TODO: initialize the graph to a "safe" state
	// *******************************************************************
	this->numberOfNodes = numberOfNodes;
	this->numberOfEdges = numberOfEdges;
}

// Destroys any dynamic memory allocated within the graph class
Graph::~Graph(void)
{
	// *******************************************************************
	// TODO: delete any dynamic memory you created
	// *******************************************************************
	for (int i = 0; i < numberOfNodes; i++)
	{
		
	}
}

// Returns the number of nodes in the graph
int Graph::GetNumberOfNodes() const
{
	return numberOfNodes;
}

// Returns the number of edges in the graph
int Graph::GetNumberOfEdges() const
{
	return numberOfEdges;
}

// Sets the number of nodes in the graph.  Nodes are assumed to be
// numerical up to the number of nodes (0 to N-1, inclusive)
void Graph::SetNumberOfNodes(int numberOfNodes)
{
	this->numberOfNodes = numberOfNodes;

	// *******************************************************************
	// TODO: allocate any dynamic memory required to store the nodes
	// *******************************************************************
}

// Sets the number of edges in the graph.
void Graph::SetNumberOfEdges(int numberOfEdges)
{
	this->numberOfEdges = numberOfEdges;

	// *******************************************************************
	// TODO: allocate any dynamic memory required to store the edges
	// *******************************************************************
}

// Adds a single edge to the graph.
void Graph::AddEdge(int startNode, int endNode)
{
	// *******************************************************************
	// TODO: Add the edge to the graph
	// *******************************************************************
}

// Uses Breadth-first search to find the shortest path between two nodes
// Optionally uses Djikstra's algorithm to find the shortest path on a
// weighted graph.  Graphs are assumed to be undirected unless specified.
vector<int> Graph::GetShortestPath(int startNode, int endNode, bool isDirected, bool isWeighted) const
{
	vector<int> path;

	// *******************************************************************
	// TODO: find the shortest path between start and end nodes and
	// return the path as a vector of integers.  The first node in the
	// vector should be the start node and the last should be the end node
	// If there is no path from start to end nodes, return an empty vector
	// *******************************************************************


	// *******************************************************************
	// TODO: Push each node in the path onto the path vector
	// HINT: use a loop....
	// *******************************************************************
	//path.push_back(nodeNumber);

	return path;
}

// Displays the graph to the provided stream
ostream& operator<<(ostream& sout, const Graph& graph)
{
	sout << "Graph: " << endl
		 << "  Number of Nodes: " << graph.GetNumberOfNodes() << endl
		 << "  Number of Edges: " << graph.GetNumberOfEdges() << endl
		 << "  Edges: " << endl;

	for (int i = 0; i < graph.GetNumberOfEdges(); ++i)
	{
		// *******************************************************************
		// TODO: Display the nodes and edges of this graph.
		// Replace the "startNode" and "endNode" with the actual node, retain
		// all other formatting and spacing.
		// *******************************************************************

		sout << "    Edge: " << "startNode" << " -> " << "endNode" << endl;
	}
	return sout;
}