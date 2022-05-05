#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"

using namespace std;

// Function prototypes
Graph* ReadGraph();
void DisplayGraph(const Graph& graph);
void DisplayPath(vector<int> path);
void FindShortestPath(const Graph& graph);
void FindAllShortestPaths(const Graph& graph);
int ReadInteger(const string& message, int min, int max);
bool ReadBoolean(const string& message, const string& trueChars, const string& falseChars);

// Reads a graph from a file provided by the user and then
// determines the shortest path between individual nodes
// in the graph.
int main()
{
	Graph* graph = NULL;
	string dummy;
	int menuChoice = 0;

	// Print instructions
	cout << "Welcome to the Graph Analyzer!" << endl
		 << "First, select a graph from a file by providing the file's name" << endl
		 << "and path.  Then, either compute all shortest paths between each" << endl
		 << "pair of nodes or select individual nodes.  Nodes are numbered" << endl
		 << "starting at zero to (numberOfNodes - 1)." << endl;

	// While the user chooses not to quit, display the menu
	do
	{
		// Display the menu to the user
		cout << "**************************************" << endl
			 << "Make a Selection from the following options:" << endl
			 << "1 - Read a graph from a file" << endl
			 << "2 - Display the graph" << endl
			 << "3 - Find the shortest path between two nodes" << endl
			 << "4 - Find ALL shortest paths" << endl
			 << "5 - Quit" << endl
			 << "**************************************" << endl;
		
		// Request the user's reponse to the menu
		menuChoice = ReadInteger("Please enter the number of your choice", 1, 5);

		// Determine which menu option the user selected
		switch (menuChoice)
		{
		case 1:
			// Open a new graph
			if (graph != NULL)
			{
				delete graph;
			}
			graph = ReadGraph();
			break;
		case 2:
			// Display the graph to the console.
			if (graph != NULL)
			{
				DisplayGraph(*graph);
			}
			else
			{
				cout << "Sorry, no graph selected, read a graph file first" << endl;
			}
			break;
		case 3:
			// Find the shortest path between two selected nodes
			if (graph != NULL)
			{
				FindShortestPath(*graph);
			}
			else
			{
				cout << "Sorry, no graph selected, read a graph file first" << endl;
			}
			break;
		case 4:
			// Find the shortest path between all nodes
			if (graph != NULL)
			{
				FindAllShortestPaths(*graph);
			}
			else
			{
				cout << "Sorry, no graph selected, read a graph file first" << endl;
			}
			break;
		case 5:
			// Quit the application
			cout << "Thank you, come again!" << endl;
			break;
		default:
			cout << "Please choose again..." << endl;
			break;
		}
	} while (menuChoice != 5);

	cout << "Press ENTER to exit" << endl;
	char c;
	cin.get(c);

	return 0;
}

// Ask the user for a filename that contains the graph
//   Returns a pointer to a graph.  If no graph is
//   constructed, the return value will be NULL.
Graph* ReadGraph()
{
	string filename = "";

	// Request the filename that the graph is stored in
	do
	{
		cout << "Please enter the filename and path for the graph file." << endl;
		getline(cin, filename);
	} while (filename.length() < 1);

	bool isWeighted = ReadBoolean("Is this graph weighted (y/Y/n/N)?", "yY", "nN");

	// Open the file for reading
    // Use fin just like cin
    ifstream fin(filename.c_str());

	// If the file was not opened, then exit this function
    if (!fin.is_open())
	{
		cout << "Error, file could not be found" << endl;
		return NULL;
	}

	int nbrOfNodes;
	int nbrOfEdges;
	int** edges;

	// Determine whether there is weight data on each edge or not
	int edgeSize = 2;
	if (isWeighted)
	{
		edgeSize = 3;
	}

	// Read the number of nodes from the file
	// If we are not at the end of the file...
	if (!fin.eof())
	{
		fin >> nbrOfNodes;
	}
	else
	{
		cout << "Improperly formatted graph file" << endl;
		return NULL;
	}

	// Read the number of nodes from the file
	// If we are not at the end of the file...
	if (!fin.eof())
	{
		fin >> nbrOfEdges;
	}
	else
	{
		cout << "Improperly formatted graph file" << endl;
		return NULL;
	}

	// Allocate memory for the collection of edges
	edges = new int*[nbrOfEdges];
	for (int i = 0; i < nbrOfEdges; ++i)
	{
		edges[i] = new int[edgeSize];
	}

	int edgeNbr = 0;

	// While we have not reached the end of the file
	// Or filled the array
    while (!fin.eof() && edgeNbr < nbrOfEdges)
    {
        // Read a value from the file
		if (!fin.eof())
		{
			fin >> edges[edgeNbr][0];
		}
		else
		{
			cout << "Improperly formatted graph file" << endl;
			return NULL;
		}

		if (!fin.eof())
		{
			fin >> edges[edgeNbr][1];
		}
		else
		{
			cout << "Improperly formatted graph file" << endl;
			return NULL;
		}

		if (isWeighted)
		{
			if (!fin.eof())
			{
				fin >> edges[edgeNbr][2];
			}
			else
			{
				cout << "Improperly formatted graph file" << endl;
				return NULL;
			}
		}

		edgeNbr++;
    }

	Graph* graph = new Graph();

	// Display the graph data to verify it was read correctly
	cout << "The following graph was found: " << endl
		 << "  Number of Nodes: " << nbrOfNodes << endl
		 << "  Number of Edges: " << nbrOfEdges << endl
		 << "  Edges: " << endl;

	graph->SetNumberOfNodes(nbrOfNodes);
	graph->SetNumberOfEdges(nbrOfEdges);
	for (int i = 0; i < nbrOfEdges; ++i)
	{
		cout << "    Edge: " << edges[i][0] << " -> " << edges[i][1] << endl;

		// Add each edge to the graph
		graph->AddEdge(edges[i][0], edges[i][1]);
	}

	// Delete the temporary memory used to story the graph
	for (int i = 0; i < nbrOfEdges; ++i)
	{
		delete[] edges[i];
	}
	delete[] edges;

	return graph;
}

// Display the graph to the console
void DisplayGraph(const Graph& graph)
{
	cout << "The current graph: " << endl;
	cout << graph << endl;
}

// Display the path to the console
void DisplayPath(int startNode, int endNode, vector<int> path)
{
	cout << "Path from " << startNode << " to " << endNode << ": ";

	// If the path has no nodes in it, then there is no path
	if (path.size() == 0)
	{
		cout << "IS DISCONNECTED" << endl;
		return;
	}

	cout << path[0];
	for (int i = 1; i < path.size(); ++i)
	{
		cout << " -> " << path[i];
	}

	cout << endl;
}

// Find the shortest path between two nodes
void FindShortestPath(const Graph& graph)
{
	int startNode = ReadInteger("Please select a starting node", 0, graph.GetNumberOfNodes() - 1);
	int endNode = ReadInteger("Please select an ending node", 0, graph.GetNumberOfNodes() - 1);
	bool isDirected = ReadBoolean("Is this graph directed (y/Y/n/N)?", "yY", "nN");
	bool isWeighted = ReadBoolean("Is this graph weighted (y/Y/n/N)?", "yY", "nN");

	DisplayPath(startNode, endNode, graph.GetShortestPath(startNode, endNode, isDirected, isWeighted));
}

// Find the shortest path between all pairs of nodes
void FindAllShortestPaths(const Graph& graph)
{
	bool isDirected = ReadBoolean("Is this graph directed (y/Y/n/N)?", "yY", "nN");
	bool isWeighted = ReadBoolean("Is this graph weighted (y/Y/n/N)?", "yY", "nN");

	for (int i = 0; i < graph.GetNumberOfNodes() - 1; ++i)
	{
		for (int j = i + 1; j < graph.GetNumberOfNodes(); ++j)
		{
			DisplayPath(i, j, graph.GetShortestPath(i, j, isDirected, isWeighted));
		}
	}

	// If the graph is directed, display BOTH directions for each pair of edges
	if (isDirected)
	{
		for (int i = 0; i < graph.GetNumberOfNodes() - 1; ++i)
		{
			for (int j = i + 1; j < graph.GetNumberOfNodes(); ++j)
			{
				DisplayPath(j, i, graph.GetShortestPath(j, i, isDirected, isWeighted));
			}
		}
	}
}

// Read an integer from the console within the range min to max (inclusive)
int ReadInteger(const string& message, int min, int max)
{
	int response;
	string dummy;

	// Ask for the integer, repeat if not within min to max range
	do
	{
		cout << message << endl;
		cin >> response;
		getline(cin, dummy);
	} while (response < min || response > max);

	return response;
}

// Read a boolean choice from the console that matches the true or false characters
bool ReadBoolean(const string& message, const string& trueChars, const string& falseChars)
{
	string response;

	// Ask for the character, repeat if not within acceptable character set
	do
	{
		cout << message << endl;
		getline(cin, response);
	} while (response.length() > 1 && trueChars.find(response) < 0 && falseChars.find(response) < 0);

	// If the character selected represents true
	if (trueChars.find(response) != string::npos)
		return true;
	else
		return false;
}
