#include "Graph.h"

Graph::Graph(std::string fileName)
{
	FileStream fs(fileName);
	
	if (fs.hasNext())
	{
		V = fs.readInt();
	}

	if (fs.hasNext())
	{
		E = fs.readInt();
	}

	data.resize(V);
	
	while (fs.hasNext())
	{
		int v = fs.readInt();
		int w = fs.readInt();

		addEdge(v, w);
	}

}

void Graph::addEdge(int v, int w)
{
	data[v].push_front(w);
	data[w].push_front(v);
}

std::forward_list<int>* Graph::getNeighbor(int v)
{
	return &data[v];
}

void Graph::showAll()
{
	for (int v = 0; v < data.size(); v++)
	{
		for (int w : data[v])
		{
			std::cout << v << " - " << w << std::endl;
		}
	}
}
