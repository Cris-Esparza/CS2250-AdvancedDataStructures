#include "Graph.h"


// Constructs the graph in a safe state
Graph::Graph(void)
{
	numberOfNodes = 0;
	numberOfEdges = 0;

	this->numberOfNodes = numberOfNodes;
	this->numberOfEdges = numberOfEdges;
}

// Destroys any dynamic memory allocated within the graph class
Graph::~Graph(void)
{
	
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
	for (int i = 0; i < numberOfNodes; i++)
	{
		adjMatrix.push_back(vector<int>(numberOfNodes));
		for (int j = 0; j < numberOfNodes; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
}

// Sets the number of edges in the graph.
void Graph::SetNumberOfEdges(int numberOfEdges)
{
	this->numberOfEdges = numberOfEdges;
}

// Adds a single edge to the graph.
void Graph::AddEdge(int startNode, int endNode)
{
	adjMatrix[startNode][endNode] = 1;
}

// Uses Breadth-first search to find the shortest path between two nodes
// Optionally uses Djikstra's algorithm to find the shortest path on a
// weighted graph.  Graphs are assumed to be undirected unless specified.
vector<int> Graph::GetShortestPath(int startNode, int endNode, bool isDirected, bool isWeighted) const
{
	vector<int> path;
	vector<bool> isVisited;
	vector<int> backPointers;
	vector<int> queue;

	isVisited.resize(numberOfNodes, false);
	isVisited[startNode] = true;
	queue.push_back(startNode);
	backPointers.resize(numberOfNodes);
	isVisited.resize(numberOfEdges);
	
	while (!queue.empty())
	{
		int curr = queue[0];
		queue.erase(queue.begin());
		if (curr == endNode)
		{
			int node = curr;
			while (node != startNode)
			{
				path.push_back(node);
				node = backPointers[node];
			}
			path.push_back(startNode);
			reverse(path.begin(), path.end());
			break;
		}
		for (int i = 0; i < numberOfNodes; ++i)
		{
			if (isDirected && adjMatrix[curr][i] == 1 && !isVisited[i])
			{
				queue.push_back(i);
				backPointers[i] = curr;
				isVisited[i] = true;
			}
			if (!isDirected && !isVisited[i] && (adjMatrix[curr][i] != 0 || adjMatrix[i][curr] != 0))
			{
				queue.push_back(i);
				backPointers[i] = curr;
				isVisited[i] = true;
			}
		}
	}
	return path;
}

// Displays the graph to the provided stream
ostream& operator<<(ostream& sout, const Graph& graph)
{
	sout << "Graph: " << endl
		 << "  Number of Nodes: " << graph.GetNumberOfNodes() << endl
		 << "  Number of Edges: " << graph.GetNumberOfEdges() << endl
		 << "  Edges: " << endl;

	int count = graph.GetNumberOfEdges();
	for (int i = 0; i < graph.GetNumberOfEdges(); ++i)
	{
		for (int j = 0; j < graph.GetNumberOfNodes(); ++j)
		{
			if (count != 0 && graph.adjMatrix[i][j] != 0)
			{
				sout << "    Edge: " << i << " -> " << j << endl;
				--count;
			}
		}
	}
	return sout;
}